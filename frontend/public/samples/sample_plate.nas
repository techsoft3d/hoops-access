ID       SAMPLE,BRACKET
SOL      101
CEND
TITLE    = Bracket - chassis plate + engine mount boss
SUBTITLE = For HOOPS Access demo
BEGIN BULK
$ Base plate corners
GRID,1,,0.0,-0.5,0.0
GRID,2,,2.0,-0.5,0.0
GRID,3,,2.0,0.5,0.0
GRID,4,,0.0,0.5,0.0
$ Mounting boss - bottom corners
GRID,5,,0.7,-0.3,0.0
GRID,6,,1.3,-0.3,0.0
GRID,7,,1.3,0.3,0.0
GRID,8,,0.7,0.3,0.0
$ Mounting boss - top corners
GRID,9,,0.7,-0.3,0.4
GRID,10,,1.3,-0.3,0.4
GRID,11,,1.3,0.3,0.4
GRID,12,,0.7,0.3,0.4
$ Chassis: base plate (part 1)
CQUAD4,1,1,1,2,3,4
$ Engine mount: boss top + 4 side walls (part 2)
CQUAD4,2,2,9,10,11,12
CQUAD4,3,2,5,6,10,9
CQUAD4,4,2,6,7,11,10
CQUAD4,5,2,7,8,12,11
CQUAD4,6,2,8,5,9,12
$ Shell properties (one per part)
PSHELL,1,1,0.1
PSHELL,2,1,0.1
$ Material
MAT1,1,2.1e+11,,.3,7850.
ENDDATA
