100 READING# = 0
600 WHILE 1=1
700 READING# = READING# + 1
800 PRINT "-----------------------------"
900 PORT = 70 : PDATA = 0 :  GOSUB 2200 : PRINT "Emulator version: "; RSTRING$
1000 PRINT "Reading: "; READING#
1100 PORT = 63 : PDATA = 0 :  GOSUB 2200 : PRINT "Temperature: "; RSTRING$
1200 PORT = 63 : PDATA = 1 :  GOSUB 2200 : PRINT "Pressure: "; RSTRING$
1300 PORT = 63 : PDATA = 2 :  GOSUB 2200 : PRINT "Light: "; RSTRING$
1700 PRINT "Sleep 1 seconds"
1800 OUT 30, 1 : WAIT 30, 1, 1
1900 WEND
2100 END
2200 REM SUBROUTINE READS STRING DATA FROM PORT UNTIL NULL CHARACTER
2300 OUT PORT, PDATA
2400 RSTRING$ = ""
2500 C=INP(200)
2600 WHILE C <> 0
2700 RSTRING$ = RSTRING$ + CHR$(C)
2800 C=INP(200)
2900 WEND
3000 RETURN