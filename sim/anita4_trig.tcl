set FAST_CLK_PERIOD 4.0
set M_CLK_PERIOD 33.0303
set NEVENTS 500

###pick one test mode:
#set TEST "MIDTOP"
#set TEST "BOTTOP"
set TEST "MIDBOT"

append ofilename $TEST "_4.txt"
set oFileId [open $ofilename "w"]

#have to wait 100 ns since xilinx sim models have a built-in reset
set INIT 100.0

###uncomment to plot waveforms in ISim:
#wave add /  

for { set i 0 } { $i < $NEVENTS } { incr i } { 
	#(re)set simulation time to 0
	restart 

	#(re)define clocks
	isim force add clk_i 0 -value 1 -time [expr $FAST_CLK_PERIOD/2] ns -repeat $FAST_CLK_PERIOD ns -radix bin
	isim force add mclk_i 0 -value 1 -time [expr $M_CLK_PERIOD/2] ns -repeat $M_CLK_PERIOD ns -radix bin
 
	if { $TEST eq "MIDTOP" } { 
		set t_top [expr { $INIT  + floor(rand() * 21.0) }]
		set t_mid [expr { $INIT + floor(rand() * 21.0) }]
		set t_bot 0
		
		set t_diff [expr $t_mid - $t_top]
	} elseif { $TEST eq "BOTTOP" } { 
		set t_top [expr { $INIT + floor(rand() * 25.0) }]
		set t_mid 0
		set t_bot [expr { $INIT + floor(rand() * 25.0) }]
		
		set t_diff [expr $t_bot - $t_top]
	} elseif { $TEST eq "MIDBOT" } { 
		set t_top 0
		set t_mid [expr { $INIT + floor(rand() * 13.0) }]
		set t_bot [expr { $INIT + floor(rand() * 13.0) }]
		
		set t_diff [expr $t_mid - $t_bot]
	}	else {
		puts "Incorrect run mode"
		return
	}
	
	isim force add TOP_LCP 11 -value 10 -time $t_top ns -value 11 -time [expr $t_top+2] ns -radix bin
	isim force add TOP_RCP 11 -value 10 -time $t_top ns -value 11 -time [expr $t_top+2] ns -radix bin

	isim force add MID_LCP 11 -value 10 -time $t_mid ns -value 11 -time [expr $t_mid+2] ns -radix bin
	isim force add MID_RCP 11 -value 10 -time $t_mid ns -value 11 -time [expr $t_mid+2] ns -radix bin

	isim force add BOT_LCP 11 -value 10 -time $t_bot ns -value 11 -time [expr $t_bot+2] ns -radix bin
	isim force add BOT_RCP 11 -value 10 -time $t_bot ns -value 11 -time [expr $t_bot+2] ns -radix bin

	run $INIT ns
	set trig_flag 0

	#check for a trigger in the next 60 ns
	for { set k 0 } { $k < 15 } { incr k } {
	
		if { [test trig_o 0001] } {
			set trig_flag 1
			break
		}	
		run $FAST_CLK_PERIOD ns
	}
	
	append datToSave $t_diff "\t" $trig_flag "\n"
}

puts $oFileId $datToSave
close $oFileId
puts "done"
quit
