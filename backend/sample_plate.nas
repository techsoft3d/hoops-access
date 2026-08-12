ID       SAMPLE,PLATE
SOL      101
CEND
TITLE    = Simple test plate - 4 nodes, 2 CTRIA3 elements
SUBTITLE = For HOOPS Access smoke test
LOAD     = 1
SPC      = 1
DISP     = ALL
STRESS   = ALL
BEGIN BULK
$ Four corner nodes of a 1x1 unit square, lying flat in the XY plane
GRID           1              0.0     0.0     0.0
GRID           2              1.0     0.0     0.0
GRID           3              1.0     1.0     0.0
GRID           4              0.0     1.0     0.0
$ Two triangular shell elements forming the square (split along diagonal)
CTRIA3         1       1       1       2       3
CTRIA3         2       1       1       3       4
$ Shell property: references material 1, thickness 0.1
PSHELL         1       1      0.1
$ Material: isotropic, E=2.1e11 Pa (steel-like), nu=0.3, rho=7850 kg/m^3
MAT1           1  2.1+11             .3  7850.
$ Fix all 4 nodes fully (simple boundary condition so the deck is complete)
SPC1           1  123456       1       2       3       4
$ Apply a small downward force on node 3
FORCE          1       3       0    100.     0.0     0.0    -1.0
ENDDATA
