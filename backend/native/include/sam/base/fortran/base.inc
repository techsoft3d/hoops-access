      integer ADTREE_POINT
      parameter(ADTREE_POINT=1)
      integer ADTREE_EXTENT
      parameter(ADTREE_EXTENT=2)
      integer ADTREE_TOLERANCE
      parameter(ADTREE_TOLERANCE=1)
      integer ADTREE_NUMHITS
      parameter(ADTREE_NUMHITS=1)
      integer ADTREE_NUMVISITS
      parameter(ADTREE_NUMVISITS=2)
      integer ADTREE_MAXLEVEL
      parameter(ADTREE_MAXLEVEL=3)
      integer VKI_OS_UNIX
      parameter(VKI_OS_UNIX=1)
      integer VKI_OS_WIN32
      parameter(VKI_OS_WIN32=1)
      integer VKI_OS_LINUX
      parameter(VKI_OS_LINUX=1)
      integer wchar_t
      parameter(wchar_t=1)
      integer CEE_SAM_PRId64
      parameter(CEE_SAM_PRId64=1)
      integer CEE_SAM_PRId64
      parameter(CEE_SAM_PRId64=1)
      integer CEE_SAM_PRId64
      parameter(CEE_SAM_PRId64=1)
      integer CEE_SAM_PRId64
      parameter(CEE_SAM_PRId64=1)
      integer CEE_SAM_PRId64
      parameter(CEE_SAM_PRId64=1)
      integer CEE_SAM_PRId64
      parameter(CEE_SAM_PRId64=1)
      integer SYS_NONE
      parameter(SYS_NONE=0)
      integer SYS_NODE
      parameter(SYS_NODE=1)
      integer SYS_EDGE
      parameter(SYS_EDGE=2)
      integer SYS_FACE
      parameter(SYS_FACE=3)
      integer SYS_ELEM
      parameter(SYS_ELEM=4)
      integer SYS_DOF
      parameter(SYS_DOF=10)
      integer SYS_INTPNT
      parameter(SYS_INTPNT=12)
      integer SYS_PARTICLE
      parameter(SYS_PARTICLE=13)
      integer SYS_MODE
      parameter(SYS_MODE=14)
      integer SYS_ASURF
      parameter(SYS_ASURF=2660)
      integer SYS_COORDSYS
      parameter(SYS_COORDSYS=2100)
      integer SYS_EQN
      parameter(SYS_EQN=11)
      integer SYS_PANEL
      parameter(SYS_PANEL=15)
      integer SYS_CPAIR
      parameter(SYS_CPAIR=2600)
      integer SYS_LIBRARY
      parameter(SYS_LIBRARY=6002)
      integer SYS_NODATATYPE
      parameter(SYS_NODATATYPE=0)
      integer SYS_INTEGER
      parameter(SYS_INTEGER=1)
      integer SYS_REAL
      parameter(SYS_REAL=2)
      integer SYS_FLOAT
      parameter(SYS_FLOAT=2)
      integer SYS_HOLLERITH
      parameter(SYS_HOLLERITH=3)
      integer SYS_CHAR
      parameter(SYS_CHAR=3)
      integer SYS_DOUBLE
      parameter(SYS_DOUBLE=4)
      integer SYS_STRING
      parameter(SYS_STRING=5)
      integer SYS_COMPLEX
      parameter(SYS_COMPLEX=6)
      integer SYS_DOUBLECOMPLEX
      parameter(SYS_DOUBLECOMPLEX=7)
      integer SYS_OBJECT
      parameter(SYS_OBJECT=8)
      integer SYS_SHORT
      parameter(SYS_SHORT=9)
      integer SYS_LONG
      parameter(SYS_LONG=10)
      integer SYS_HALF
      parameter(SYS_HALF=11)
      integer SYS_QUARTER
      parameter(SYS_QUARTER=12)
      integer SYS_WCHAR
      parameter(SYS_WCHAR=13)
      integer SYS_24BIT
      parameter(SYS_24BIT=14)
      integer SYS_DATATYPE_NONE
      parameter(SYS_DATATYPE_NONE=-1)
      integer SYS_SCALAR
      parameter(SYS_SCALAR=0)
      integer SYS_VECTOR
      parameter(SYS_VECTOR=1)
      integer SYS_TENSOR
      parameter(SYS_TENSOR=2)
      integer SYS_GENERALTENSOR
      parameter(SYS_GENERALTENSOR=3)
      integer SYS_SIXDOF
      parameter(SYS_SIXDOF=9)
      integer SYS_MATRIX_DIAG
      parameter(SYS_MATRIX_DIAG=6)
      integer SYS_MATRIX_SYMM
      parameter(SYS_MATRIX_SYMM=7)
      integer SYS_MATRIX_USYMM
      parameter(SYS_MATRIX_USYMM=8)
      integer SYS_ELEMRES
      parameter(SYS_ELEMRES=5)
      integer SYS_SCALARS
      parameter(SYS_SCALARS=10)
      integer SYS_SCALARS1
      parameter(SYS_SCALARS1=11)
      integer SYS_SCALARS2
      parameter(SYS_SCALARS2=12)
      integer SYS_SCALARS3
      parameter(SYS_SCALARS3=13)
      integer SYS_SCALARS4
      parameter(SYS_SCALARS4=14)
      integer SYS_SCALARS5
      parameter(SYS_SCALARS5=15)
      integer SYS_SCALARS6
      parameter(SYS_SCALARS6=16)
      integer SYS_SCALARS7
      parameter(SYS_SCALARS7=17)
      integer SYS_SCALARS8
      parameter(SYS_SCALARS8=18)
      integer SYS_SCALARS9
      parameter(SYS_SCALARS9=19)
      integer SYS_SCALARS10
      parameter(SYS_SCALARS10=20)
      integer SYS_SCALARS11
      parameter(SYS_SCALARS11=21)
      integer SYS_SCALARS12
      parameter(SYS_SCALARS12=22)
      integer SYS_SCALARS13
      parameter(SYS_SCALARS13=23)
      integer SYS_SCALARS14
      parameter(SYS_SCALARS14=24)
      integer SYS_SCALARS15
      parameter(SYS_SCALARS15=25)
      integer SYS_SCALARS16
      parameter(SYS_SCALARS16=26)
      integer SYS_SCALARS17
      parameter(SYS_SCALARS17=27)
      integer SYS_SCALARS18
      parameter(SYS_SCALARS18=28)
      integer SYS_SCALARS19
      parameter(SYS_SCALARS19=29)
      integer SYS_SCALARS20
      parameter(SYS_SCALARS20=30)
      integer SYS_SCALARS21
      parameter(SYS_SCALARS21=31)
      integer SYS_SCALARS22
      parameter(SYS_SCALARS22=32)
      integer SYS_SCALARS23
      parameter(SYS_SCALARS23=33)
      integer SYS_SCALARS24
      parameter(SYS_SCALARS24=34)
      integer SYS_SCALARS25
      parameter(SYS_SCALARS25=35)
      integer SYS_SCALARS26
      parameter(SYS_SCALARS26=36)
      integer SYS_SCALARS27
      parameter(SYS_SCALARS27=37)
      integer SYS_SCALARS28
      parameter(SYS_SCALARS28=38)
      integer SYS_SCALARS29
      parameter(SYS_SCALARS29=39)
      integer SYS_SCALARS30
      parameter(SYS_SCALARS30=40)
      integer SYS_SCALARS31
      parameter(SYS_SCALARS31=41)
      integer SYS_SCALARS32
      parameter(SYS_SCALARS32=42)
      integer SYS_SCALARS33
      parameter(SYS_SCALARS33=43)
      integer SYS_SCALARS34
      parameter(SYS_SCALARS34=44)
      integer SYS_SCALARS35
      parameter(SYS_SCALARS35=45)
      integer SYS_SCALARS36
      parameter(SYS_SCALARS36=46)
      integer SYS_SCALARS37
      parameter(SYS_SCALARS37=47)
      integer SYS_SCALARS38
      parameter(SYS_SCALARS38=48)
      integer SYS_SCALARS39
      parameter(SYS_SCALARS39=49)
      integer SYS_SCALARS40
      parameter(SYS_SCALARS40=50)
      integer SYS_SCALARS41
      parameter(SYS_SCALARS41=51)
      integer SYS_SCALARS42
      parameter(SYS_SCALARS42=52)
      integer SYS_SCALARS43
      parameter(SYS_SCALARS43=53)
      integer SYS_SCALARS44
      parameter(SYS_SCALARS44=54)
      integer SYS_SCALARS45
      parameter(SYS_SCALARS45=55)
      integer SYS_SCALARS46
      parameter(SYS_SCALARS46=56)
      integer SYS_SCALARS47
      parameter(SYS_SCALARS47=57)
      integer SYS_SCALARS48
      parameter(SYS_SCALARS48=58)
      integer SYS_SCALARS49
      parameter(SYS_SCALARS49=59)
      integer SYS_SCALARS50
      parameter(SYS_SCALARS50=60)
      integer SYS_SCALARS51
      parameter(SYS_SCALARS51=61)
      integer SYS_SCALARS52
      parameter(SYS_SCALARS52=62)
      integer SYS_SCALARS53
      parameter(SYS_SCALARS53=63)
      integer SYS_SCALARS54
      parameter(SYS_SCALARS54=64)
      integer SYS_SCALARS55
      parameter(SYS_SCALARS55=65)
      integer SYS_SCALARS56
      parameter(SYS_SCALARS56=66)
      integer SYS_SCALARS57
      parameter(SYS_SCALARS57=67)
      integer SYS_SCALARS58
      parameter(SYS_SCALARS58=68)
      integer SYS_SCALARS59
      parameter(SYS_SCALARS59=69)
      integer SYS_SCALARS60
      parameter(SYS_SCALARS60=70)
      integer SYS_SCALARS61
      parameter(SYS_SCALARS61=71)
      integer SYS_SCALARS62
      parameter(SYS_SCALARS62=72)
      integer SYS_SCALARS63
      parameter(SYS_SCALARS63=73)
      integer SYS_SCALARS64
      parameter(SYS_SCALARS64=74)
      integer SYS_SCALARS65
      parameter(SYS_SCALARS65=75)
      integer SYS_SCALARS66
      parameter(SYS_SCALARS66=76)
      integer SYS_SCALARS67
      parameter(SYS_SCALARS67=77)
      integer SYS_SCALARS68
      parameter(SYS_SCALARS68=78)
      integer SYS_SCALARS69
      parameter(SYS_SCALARS69=79)
      integer SYS_SCALARS70
      parameter(SYS_SCALARS70=80)
      integer SYS_SCALARS71
      parameter(SYS_SCALARS71=81)
      integer SYS_SCALARS72
      parameter(SYS_SCALARS72=82)
      integer SYS_SCALARS73
      parameter(SYS_SCALARS73=83)
      integer SYS_SCALARS74
      parameter(SYS_SCALARS74=84)
      integer SYS_SCALARS75
      parameter(SYS_SCALARS75=85)
      integer SYS_SCALARS76
      parameter(SYS_SCALARS76=86)
      integer SYS_SCALARS77
      parameter(SYS_SCALARS77=87)
      integer SYS_SCALARS78
      parameter(SYS_SCALARS78=88)
      integer SYS_SCALARS79
      parameter(SYS_SCALARS79=89)
      integer SYS_SCALARS80
      parameter(SYS_SCALARS80=90)
      integer SYS_SCALARS81
      parameter(SYS_SCALARS81=91)
      integer SYS_SCALARS82
      parameter(SYS_SCALARS82=92)
      integer SYS_SCALARS83
      parameter(SYS_SCALARS83=93)
      integer SYS_SCALARS84
      parameter(SYS_SCALARS84=94)
      integer SYS_SCALARS85
      parameter(SYS_SCALARS85=95)
      integer SYS_SCALARS86
      parameter(SYS_SCALARS86=96)
      integer SYS_SCALARS87
      parameter(SYS_SCALARS87=97)
      integer SYS_SCALARS88
      parameter(SYS_SCALARS88=98)
      integer SYS_SCALARS89
      parameter(SYS_SCALARS89=99)
      integer SYS_SCALARS90
      parameter(SYS_SCALARS90=100)
      integer SYS_SCALARS91
      parameter(SYS_SCALARS91=101)
      integer SYS_SCALARS92
      parameter(SYS_SCALARS92=102)
      integer SYS_SCALARS93
      parameter(SYS_SCALARS93=103)
      integer SYS_SCALARS94
      parameter(SYS_SCALARS94=104)
      integer SYS_SCALARS95
      parameter(SYS_SCALARS95=105)
      integer SYS_SCALARS96
      parameter(SYS_SCALARS96=106)
      integer SYS_SCALARS97
      parameter(SYS_SCALARS97=107)
      integer SYS_SCALARS98
      parameter(SYS_SCALARS98=108)
      integer SYS_SCALARS99
      parameter(SYS_SCALARS99=109)
      integer SYS_SCALARS100
      parameter(SYS_SCALARS100=110)
      integer SYS_SCALARS101
      parameter(SYS_SCALARS101=111)
      integer SYS_SCALARS102
      parameter(SYS_SCALARS102=112)
      integer SYS_SCALARS103
      parameter(SYS_SCALARS103=113)
      integer SYS_SCALARS104
      parameter(SYS_SCALARS104=114)
      integer SYS_SCALARS105
      parameter(SYS_SCALARS105=115)
      integer SYS_SCALARS106
      parameter(SYS_SCALARS106=116)
      integer SYS_SCALARS107
      parameter(SYS_SCALARS107=117)
      integer SYS_SCALARS108
      parameter(SYS_SCALARS108=118)
      integer SYS_SCALARS109
      parameter(SYS_SCALARS109=119)
      integer SYS_SCALARS110
      parameter(SYS_SCALARS110=120)
      integer SYS_SCALARS111
      parameter(SYS_SCALARS111=121)
      integer SYS_SCALARS112
      parameter(SYS_SCALARS112=122)
      integer SYS_SCALARS113
      parameter(SYS_SCALARS113=123)
      integer SYS_SCALARS114
      parameter(SYS_SCALARS114=124)
      integer SYS_SCALARS115
      parameter(SYS_SCALARS115=125)
      integer SYS_SCALARS116
      parameter(SYS_SCALARS116=126)
      integer SYS_SCALARS117
      parameter(SYS_SCALARS117=127)
      integer SYS_SCALARS118
      parameter(SYS_SCALARS118=128)
      integer SYS_SCALARS119
      parameter(SYS_SCALARS119=129)
      integer SYS_SCALARS120
      parameter(SYS_SCALARS120=130)
      integer SYS_SCALARS121
      parameter(SYS_SCALARS121=131)
      integer SYS_SCALARS122
      parameter(SYS_SCALARS122=132)
      integer SYS_SCALARS123
      parameter(SYS_SCALARS123=133)
      integer SYS_SCALARS124
      parameter(SYS_SCALARS124=134)
      integer SYS_SCALARS125
      parameter(SYS_SCALARS125=135)
      integer SYS_SCALARS126
      parameter(SYS_SCALARS126=136)
      integer SYS_SCALARS127
      parameter(SYS_SCALARS127=137)
      integer SYS_SCALARS128
      parameter(SYS_SCALARS128=138)
      integer SYS_SCALARS129
      parameter(SYS_SCALARS129=139)
      integer SYS_SCALARS130
      parameter(SYS_SCALARS130=140)
      integer SYS_SCALARS131
      parameter(SYS_SCALARS131=141)
      integer SYS_SCALARS132
      parameter(SYS_SCALARS132=142)
      integer SYS_SCALARS133
      parameter(SYS_SCALARS133=143)
      integer SYS_SCALARS134
      parameter(SYS_SCALARS134=144)
      integer SYS_SCALARS135
      parameter(SYS_SCALARS135=145)
      integer SYS_SCALARS136
      parameter(SYS_SCALARS136=146)
      integer SYS_SCALARS137
      parameter(SYS_SCALARS137=147)
      integer SYS_SCALARS138
      parameter(SYS_SCALARS138=148)
      integer SYS_SCALARS139
      parameter(SYS_SCALARS139=149)
      integer SYS_SCALARS140
      parameter(SYS_SCALARS140=150)
      integer SYS_SCALARS141
      parameter(SYS_SCALARS141=151)
      integer SYS_SCALARS142
      parameter(SYS_SCALARS142=152)
      integer SYS_SCALARS143
      parameter(SYS_SCALARS143=153)
      integer SYS_SCALARS144
      parameter(SYS_SCALARS144=154)
      integer SYS_SCALARS145
      parameter(SYS_SCALARS145=155)
      integer SYS_SCALARS146
      parameter(SYS_SCALARS146=156)
      integer SYS_SCALARS147
      parameter(SYS_SCALARS147=157)
      integer SYS_SCALARS148
      parameter(SYS_SCALARS148=158)
      integer SYS_SCALARS149
      parameter(SYS_SCALARS149=159)
      integer SYS_SCALARS150
      parameter(SYS_SCALARS150=160)
      integer SYS_SCALARS151
      parameter(SYS_SCALARS151=161)
      integer SYS_SCALARS152
      parameter(SYS_SCALARS152=162)
      integer SYS_SCALARS153
      parameter(SYS_SCALARS153=163)
      integer SYS_SCALARS154
      parameter(SYS_SCALARS154=164)
      integer SYS_SCALARS155
      parameter(SYS_SCALARS155=165)
      integer SYS_SCALARS156
      parameter(SYS_SCALARS156=166)
      integer SYS_SCALARS157
      parameter(SYS_SCALARS157=167)
      integer SYS_SCALARS158
      parameter(SYS_SCALARS158=168)
      integer SYS_SCALARS159
      parameter(SYS_SCALARS159=169)
      integer SYS_SCALARS160
      parameter(SYS_SCALARS160=170)
      integer SYS_SCALARS161
      parameter(SYS_SCALARS161=171)
      integer SYS_SCALARS162
      parameter(SYS_SCALARS162=172)
      integer SYS_SCALARS163
      parameter(SYS_SCALARS163=173)
      integer SYS_SCALARS164
      parameter(SYS_SCALARS164=174)
      integer SYS_SCALARS165
      parameter(SYS_SCALARS165=175)
      integer SYS_SCALARS166
      parameter(SYS_SCALARS166=176)
      integer SYS_SCALARS167
      parameter(SYS_SCALARS167=177)
      integer SYS_SCALARS168
      parameter(SYS_SCALARS168=178)
      integer SYS_SCALARS169
      parameter(SYS_SCALARS169=179)
      integer SYS_SCALARS170
      parameter(SYS_SCALARS170=180)
      integer SYS_SCALARS171
      parameter(SYS_SCALARS171=181)
      integer SYS_SCALARS172
      parameter(SYS_SCALARS172=182)
      integer SYS_SCALARS173
      parameter(SYS_SCALARS173=183)
      integer SYS_SCALARS174
      parameter(SYS_SCALARS174=184)
      integer SYS_SCALARS175
      parameter(SYS_SCALARS175=185)
      integer SYS_SCALARS176
      parameter(SYS_SCALARS176=186)
      integer SYS_SCALARS177
      parameter(SYS_SCALARS177=187)
      integer SYS_SCALARS178
      parameter(SYS_SCALARS178=188)
      integer SYS_SCALARS179
      parameter(SYS_SCALARS179=189)
      integer SYS_SCALARS180
      parameter(SYS_SCALARS180=190)
      integer SYS_SCALARS181
      parameter(SYS_SCALARS181=191)
      integer SYS_SCALARS182
      parameter(SYS_SCALARS182=192)
      integer SYS_SCALARS183
      parameter(SYS_SCALARS183=193)
      integer SYS_SCALARS184
      parameter(SYS_SCALARS184=194)
      integer SYS_SCALARS185
      parameter(SYS_SCALARS185=195)
      integer SYS_SCALARS186
      parameter(SYS_SCALARS186=196)
      integer SYS_SCALARS187
      parameter(SYS_SCALARS187=197)
      integer SYS_SCALARS188
      parameter(SYS_SCALARS188=198)
      integer SYS_SCALARS189
      parameter(SYS_SCALARS189=199)
      integer SYS_SCALARS190
      parameter(SYS_SCALARS190=200)
      integer SYS_SCALARS191
      parameter(SYS_SCALARS191=201)
      integer SYS_SCALARS192
      parameter(SYS_SCALARS192=202)
      integer SYS_SCALARS193
      parameter(SYS_SCALARS193=203)
      integer SYS_SCALARS194
      parameter(SYS_SCALARS194=204)
      integer SYS_SCALARS195
      parameter(SYS_SCALARS195=205)
      integer SYS_SCALARS196
      parameter(SYS_SCALARS196=206)
      integer SYS_SCALARS197
      parameter(SYS_SCALARS197=207)
      integer SYS_SCALARS198
      parameter(SYS_SCALARS198=208)
      integer SYS_SCALARS199
      parameter(SYS_SCALARS199=209)
      integer SYS_SCALARS200
      parameter(SYS_SCALARS200=210)
      integer SYS_SCALARS201
      parameter(SYS_SCALARS201=211)
      integer SYS_SCALARS202
      parameter(SYS_SCALARS202=212)
      integer SYS_SCALARS203
      parameter(SYS_SCALARS203=213)
      integer SYS_SCALARS204
      parameter(SYS_SCALARS204=214)
      integer SYS_SCALARS205
      parameter(SYS_SCALARS205=215)
      integer SYS_SCALARS206
      parameter(SYS_SCALARS206=216)
      integer SYS_SCALARS207
      parameter(SYS_SCALARS207=217)
      integer SYS_SCALARS208
      parameter(SYS_SCALARS208=218)
      integer SYS_SCALARS209
      parameter(SYS_SCALARS209=219)
      integer SYS_SCALARS210
      parameter(SYS_SCALARS210=220)
      integer SYS_SCALARS211
      parameter(SYS_SCALARS211=221)
      integer SYS_SCALARS212
      parameter(SYS_SCALARS212=222)
      integer SYS_SCALARS213
      parameter(SYS_SCALARS213=223)
      integer SYS_SCALARS214
      parameter(SYS_SCALARS214=224)
      integer SYS_SCALARS215
      parameter(SYS_SCALARS215=225)
      integer SYS_SCALARS216
      parameter(SYS_SCALARS216=226)
      integer SYS_SCALARS217
      parameter(SYS_SCALARS217=227)
      integer SYS_SCALARS218
      parameter(SYS_SCALARS218=228)
      integer SYS_SCALARS219
      parameter(SYS_SCALARS219=229)
      integer SYS_SCALARS220
      parameter(SYS_SCALARS220=230)
      integer SYS_SCALARS221
      parameter(SYS_SCALARS221=231)
      integer SYS_SCALARS222
      parameter(SYS_SCALARS222=232)
      integer SYS_SCALARS223
      parameter(SYS_SCALARS223=233)
      integer SYS_SCALARS224
      parameter(SYS_SCALARS224=234)
      integer SYS_SCALARS225
      parameter(SYS_SCALARS225=235)
      integer SYS_SCALARS226
      parameter(SYS_SCALARS226=236)
      integer SYS_SCALARS227
      parameter(SYS_SCALARS227=237)
      integer SYS_SCALARS228
      parameter(SYS_SCALARS228=238)
      integer SYS_SCALARS229
      parameter(SYS_SCALARS229=239)
      integer SYS_SCALARS230
      parameter(SYS_SCALARS230=240)
      integer SYS_SCALARS231
      parameter(SYS_SCALARS231=241)
      integer SYS_SCALARS232
      parameter(SYS_SCALARS232=242)
      integer SYS_SCALARS233
      parameter(SYS_SCALARS233=243)
      integer SYS_SCALARS234
      parameter(SYS_SCALARS234=244)
      integer SYS_SCALARS235
      parameter(SYS_SCALARS235=245)
      integer SYS_SCALARS236
      parameter(SYS_SCALARS236=246)
      integer SYS_SCALARS237
      parameter(SYS_SCALARS237=247)
      integer SYS_SCALARS238
      parameter(SYS_SCALARS238=248)
      integer SYS_SCALARS239
      parameter(SYS_SCALARS239=249)
      integer SYS_SCALARS240
      parameter(SYS_SCALARS240=250)
      integer SYS_SCALARS241
      parameter(SYS_SCALARS241=251)
      integer SYS_SCALARS242
      parameter(SYS_SCALARS242=252)
      integer SYS_SCALARS243
      parameter(SYS_SCALARS243=253)
      integer SYS_SCALARS244
      parameter(SYS_SCALARS244=254)
      integer SYS_SCALARS245
      parameter(SYS_SCALARS245=255)
      integer SYS_SCALARS246
      parameter(SYS_SCALARS246=256)
      integer SYS_SCALARS247
      parameter(SYS_SCALARS247=257)
      integer SYS_SCALARS248
      parameter(SYS_SCALARS248=258)
      integer SYS_SCALARS249
      parameter(SYS_SCALARS249=259)
      integer SYS_SCALARS250
      parameter(SYS_SCALARS250=260)
      integer SYS_SCALARS251
      parameter(SYS_SCALARS251=261)
      integer SYS_SCALARS252
      parameter(SYS_SCALARS252=262)
      integer SYS_SCALARS253
      parameter(SYS_SCALARS253=263)
      integer SYS_SCALARS254
      parameter(SYS_SCALARS254=264)
      integer SYS_SCALARS255
      parameter(SYS_SCALARS255=265)
      integer SYS_SCALARS256
      parameter(SYS_SCALARS256=266)
      integer SYS_DATATYPE_MAX
      parameter(SYS_DATATYPE_MAX=266)
      integer SYS_COMPLEX_NONE
      parameter(SYS_COMPLEX_NONE=0)
      integer SYS_COMPLEX_REAL
      parameter(SYS_COMPLEX_REAL=1)
      integer SYS_COMPLEX_MAGNITUDE
      parameter(SYS_COMPLEX_MAGNITUDE=2)
      integer SYS_COMPLEX_IMAGINARY
      parameter(SYS_COMPLEX_IMAGINARY=3)
      integer SYS_COMPLEX_PHASE
      parameter(SYS_COMPLEX_PHASE=4)
      integer SYS_COMPLEX_REALIMAGINARY
      parameter(SYS_COMPLEX_REALIMAGINARY=5)
      integer SYS_COMPLEX_MAGNITUDEPHASE
      parameter(SYS_COMPLEX_MAGNITUDEPHASE=6)
      integer SYS_NODATAVAL
      parameter(SYS_NODATAVAL=0)
      integer SYS_GRAD_NODATAVAL
      parameter(SYS_GRAD_NODATAVAL=0)
      integer SYS_CARTESIAN
      parameter(SYS_CARTESIAN=1)
      integer SYS_CYLINDRICAL
      parameter(SYS_CYLINDRICAL=2)
      integer SYS_SPHERICAL
      parameter(SYS_SPHERICAL=3)
      integer SYS_SPHERICAL_ALT
      parameter(SYS_SPHERICAL_ALT=4)
      integer SYS_TOROIDAL
      parameter(SYS_TOROIDAL=5)
      integer SYS_CYLINDRICAL_ALT
      parameter(SYS_CYLINDRICAL_ALT=6)
      integer SYS_XAXIS
      parameter(SYS_XAXIS=1)
      integer SYS_YAXIS
      parameter(SYS_YAXIS=2)
      integer SYS_ZAXIS
      parameter(SYS_ZAXIS=3)
      integer SYS_XYPLANE
      parameter(SYS_XYPLANE=12)
      integer SYS_XZPLANE
      parameter(SYS_XZPLANE=13)
      integer SYS_YZPLANE
      parameter(SYS_YZPLANE=23)
      integer SYS_OFF
      parameter(SYS_OFF=0)
      integer SYS_ON
      parameter(SYS_ON=1)
      integer SYS_NEW
      parameter(SYS_NEW=2)
      integer SYS_CHARBITS
      parameter(SYS_CHARBITS=8)
      integer SYS_INVALIDINT
      parameter(SYS_INVALIDINT=900000000)
      integer SYS_THREADS_MAX
      parameter(SYS_THREADS_MAX=64)
      integer SYS_KEEP
      parameter(SYS_KEEP=0)
      integer SYS_DELETE
      parameter(SYS_DELETE=1)
      integer SYS_UNKNOWN
      parameter(SYS_UNKNOWN=0)
      integer SYS_OLD
      parameter(SYS_OLD=1)
      integer SYS_SHAPEUNDEFINED
      parameter(SYS_SHAPEUNDEFINED=-1)
      integer SYS_SHAPEPOINT
      parameter(SYS_SHAPEPOINT=0)
      integer SYS_SHAPELINE
      parameter(SYS_SHAPELINE=1)
      integer SYS_SHAPETRI
      parameter(SYS_SHAPETRI=2)
      integer SYS_SHAPEQUAD
      parameter(SYS_SHAPEQUAD=3)
      integer SYS_SHAPETET
      parameter(SYS_SHAPETET=4)
      integer SYS_SHAPEPYR
      parameter(SYS_SHAPEPYR=5)
      integer SYS_SHAPEWED
      parameter(SYS_SHAPEWED=6)
      integer SYS_SHAPEHEX
      parameter(SYS_SHAPEHEX=7)
      integer SYS_SHAPEPOLYGON
      parameter(SYS_SHAPEPOLYGON=8)
      integer SYS_SHAPEPOLYHED
      parameter(SYS_SHAPEPOLYHED=9)
      integer SYS_SHAPE_MAX
      parameter(SYS_SHAPE_MAX=10)
      integer SYS_NODE_UNDEFINED
      parameter(SYS_NODE_UNDEFINED=0)
      integer SYS_NODE_GRID
      parameter(SYS_NODE_GRID=1)
      integer SYS_NODE_SCALAR
      parameter(SYS_NODE_SCALAR=2)
      integer SYS_ELEM_UNDEFINED
      parameter(SYS_ELEM_UNDEFINED=0)
      integer SYS_ELEM_SOLID
      parameter(SYS_ELEM_SOLID=1)
      integer SYS_ELEM_SHELL
      parameter(SYS_ELEM_SHELL=2)
      integer SYS_ELEM_MEMBRANE
      parameter(SYS_ELEM_MEMBRANE=3)
      integer SYS_ELEM_BEAM
      parameter(SYS_ELEM_BEAM=4)
      integer SYS_ELEM_TRUSS
      parameter(SYS_ELEM_TRUSS=5)
      integer SYS_ELEM_INFINITE
      parameter(SYS_ELEM_INFINITE=6)
      integer SYS_ELEM_GAP
      parameter(SYS_ELEM_GAP=7)
      integer SYS_ELEM_JOINT
      parameter(SYS_ELEM_JOINT=8)
      integer SYS_ELEM_SPRINGDASHPOT
      parameter(SYS_ELEM_SPRINGDASHPOT=9)
      integer SYS_ELEM_RIGID
      parameter(SYS_ELEM_RIGID=10)
      integer SYS_ELEM_CONSTRAINT
      parameter(SYS_ELEM_CONSTRAINT=11)
      integer SYS_ELEM_PLOT
      parameter(SYS_ELEM_PLOT=12)
      integer SYS_ELEM_MASS
      parameter(SYS_ELEM_MASS=13)
      integer SYS_ELEM_INTER
      parameter(SYS_ELEM_INTER=14)
      integer SYS_ELEM_SUPER
      parameter(SYS_ELEM_SUPER=15)
      integer SYS_ELEM_REINFORCEMENT
      parameter(SYS_ELEM_REINFORCEMENT=16)
      integer SYS_ELEM_MAX
      parameter(SYS_ELEM_MAX=17)
      integer SYS_SOLID_SOLID
      parameter(SYS_SOLID_SOLID=0)
      integer SYS_SOLID_FLUID
      parameter(SYS_SOLID_FLUID=1)
      integer SYS_SOLID_SHELL
      parameter(SYS_SOLID_SHELL=2)
      integer SYS_MEMBRANE_STAN
      parameter(SYS_MEMBRANE_STAN=0)
      integer SYS_MEMBRANE_SHEAR
      parameter(SYS_MEMBRANE_SHEAR=1)
      integer SYS_MEMBRANE_FACE
      parameter(SYS_MEMBRANE_FACE=2)
      integer SYS_BEAM_STAN
      parameter(SYS_BEAM_STAN=0)
      integer SYS_BEAM_ROD
      parameter(SYS_BEAM_ROD=1)
      integer SYS_BEAM_WELD
      parameter(SYS_BEAM_WELD=2)
      integer SYS_BEAM_CBEND
      parameter(SYS_BEAM_CBEND=3)
      integer SYS_TRUSS_STAN
      parameter(SYS_TRUSS_STAN=0)
      integer SYS_TRUSS_EDGE
      parameter(SYS_TRUSS_EDGE=1)
      integer SYS_SPRINGDASHPOT_SCALAR
      parameter(SYS_SPRINGDASHPOT_SCALAR=0)
      integer SYS_SPRINGDASHPOT_LINK
      parameter(SYS_SPRINGDASHPOT_LINK=1)
      integer SYS_SPRINGDASHPOT_WELD
      parameter(SYS_SPRINGDASHPOT_WELD=2)
      integer SYS_SPRINGDASHPOT_BUSH
      parameter(SYS_SPRINGDASHPOT_BUSH=3)
      integer SYS_SPRINGDASHPOT_SCALARDAMP
      parameter(SYS_SPRINGDASHPOT_SCALARDAMP=4)
      integer SYS_SPRINGDASHPOT_LINKDAMP
      parameter(SYS_SPRINGDASHPOT_LINKDAMP=5)
      integer SYS_SPRINGDASHPOT_VECTOR
      parameter(SYS_SPRINGDASHPOT_VECTOR=6)
      integer SYS_SPRINGDASHPOT_SEATBELT
      parameter(SYS_SPRINGDASHPOT_SEATBELT=7)
      integer SYS_SPRINGDASHPOT_TORSION
      parameter(SYS_SPRINGDASHPOT_TORSION=8)
      integer SYS_MASS_SCALAR
      parameter(SYS_MASS_SCALAR=0)
      integer SYS_MASS_LUMP
      parameter(SYS_MASS_LUMP=1)
      integer SYS_MASS_MATRIX
      parameter(SYS_MASS_MATRIX=2)
      integer SYS_MASS_VECTOR
      parameter(SYS_MASS_VECTOR=3)
      integer SYS_MASS_VERTEX
      parameter(SYS_MASS_VERTEX=4)
      integer SYS_RIGID_KINE
      parameter(SYS_RIGID_KINE=0)
      integer SYS_RIGID_DIST
      parameter(SYS_RIGID_DIST=1)
      integer SYS_RIGID_LINK
      parameter(SYS_RIGID_LINK=2)
      integer SYS_RIGID_MPC
      parameter(SYS_RIGID_MPC=3)
      integer SYS_RIGID_RBE3
      parameter(SYS_RIGID_RBE3=4)
      integer SYS_RIGID_SPLINE
      parameter(SYS_RIGID_SPLINE=5)
      integer SYS_RIGID_JOINT
      parameter(SYS_RIGID_JOINT=6)
      integer SYS_CONSTRAINT_NONE
      parameter(SYS_CONSTRAINT_NONE=0)
      integer SYS_CONSTRAINT_MEAN
      parameter(SYS_CONSTRAINT_MEAN=1)
      integer SYS_PLOT_LOD0
      parameter(SYS_PLOT_LOD0=0)
      integer SYS_PLOT_LOD1
      parameter(SYS_PLOT_LOD1=1)
      integer SYS_PLOT_LOD2
      parameter(SYS_PLOT_LOD2=2)
      integer SYS_PLOT_LOD3
      parameter(SYS_PLOT_LOD3=3)
      integer SYS_PLOT_AERO
      parameter(SYS_PLOT_AERO=4)
      integer SYS_INTER_NONE
      parameter(SYS_INTER_NONE=0)
      integer SYS_INTER_CONTACT
      parameter(SYS_INTER_CONTACT=1)
      integer SYS_INTER_INTERIOR
      parameter(SYS_INTER_INTERIOR=2)
      integer SYS_INTER_WALL
      parameter(SYS_INTER_WALL=3)
      integer SYS_INTER_INLET_PRESSURE
      parameter(SYS_INTER_INLET_PRESSURE=4)
      integer SYS_INTER_OUTLET_PRESSURE
      parameter(SYS_INTER_OUTLET_PRESSURE=5)
      integer SYS_INTER_SURF
      parameter(SYS_INTER_SURF=6)
      integer SYS_INTER_SYMMETRY
      parameter(SYS_INTER_SYMMETRY=7)
      integer SYS_INTER_PERIODIC_SHADOW
      parameter(SYS_INTER_PERIODIC_SHADOW=8)
      integer SYS_INTER_PRESSURE_FARFIELD
      parameter(SYS_INTER_PRESSURE_FARFIELD=9)
      integer SYS_INTER_INLET_VELOCITY
      parameter(SYS_INTER_INLET_VELOCITY=10)
      integer SYS_INTER_PERIODIC
      parameter(SYS_INTER_PERIODIC=11)
      integer SYS_INTER_FAN
      parameter(SYS_INTER_FAN=12)
      integer SYS_INTER_INLET_MASSFLOW
      parameter(SYS_INTER_INLET_MASSFLOW=13)
      integer SYS_INTER_INTERFACE
      parameter(SYS_INTER_INTERFACE=14)
      integer SYS_INTER_PARENT
      parameter(SYS_INTER_PARENT=15)
      integer SYS_INTER_OUTFLOW
      parameter(SYS_INTER_OUTFLOW=16)
      integer SYS_INTER_AXIS
      parameter(SYS_INTER_AXIS=17)
      integer SYS_INTER_USER_DEFINED
      parameter(SYS_INTER_USER_DEFINED=18)
      integer SYS_INTER_DEGENERATE_LINE
      parameter(SYS_INTER_DEGENERATE_LINE=19)
      integer SYS_INTER_DIRICHLET
      parameter(SYS_INTER_DIRICHLET=20)
      integer SYS_INTER_FARFIELD
      parameter(SYS_INTER_FARFIELD=21)
      integer SYS_INTER_NEUMANN
      parameter(SYS_INTER_NEUMANN=22)
      integer SYS_INTER_GENERAL
      parameter(SYS_INTER_GENERAL=23)
      integer SYS_INTER_INFLOW_SUBSONIC
      parameter(SYS_INTER_INFLOW_SUBSONIC=24)
      integer SYS_INTER_OUTFLOW_SUBSONIC
      parameter(SYS_INTER_OUTFLOW_SUBSONIC=25)
      integer SYS_INTER_INFLOW_SUPERSONIC
      parameter(SYS_INTER_INFLOW_SUPERSONIC=26)
      integer SYS_INTER_OUTFLOW_SUPERSONIC
      parameter(SYS_INTER_OUTFLOW_SUPERSONIC=27)
      integer SYS_INTER_TUNNEL_INFLOW
      parameter(SYS_INTER_TUNNEL_INFLOW=28)
      integer SYS_INTER_SYMMETRY_POLAR
      parameter(SYS_INTER_SYMMETRY_POLAR=29)
      integer SYS_INTER_TUNNEL_OUTFLOW
      parameter(SYS_INTER_TUNNEL_OUTFLOW=30)
      integer SYS_INTER_WALL_VISCOUS
      parameter(SYS_INTER_WALL_VISCOUS=31)
      integer SYS_INTER_WALL_VISCOUS_HEAT_FLUX
      parameter(SYS_INTER_WALL_VISCOUS_HEAT_FLUX=32)
      integer SYS_INTER_WALL_VISCOUS_ISOTHERMAL
      parameter(SYS_INTER_WALL_VISCOUS_ISOTHERMAL=33)
      integer SYS_INTER_WALL_INVISCID
      parameter(SYS_INTER_WALL_INVISCID=34)
      integer SYS_INTER_DEGENERATE_POINT
      parameter(SYS_INTER_DEGENERATE_POINT=35)
      integer SYS_INTER_EXTRAPOLATE
      parameter(SYS_INTER_EXTRAPOLATE=36)
      integer SYS_INTER_SURF_ENVIRONMENT
      parameter(SYS_INTER_SURF_ENVIRONMENT=37)
      integer SYS_INTER_STAGNATION
      parameter(SYS_INTER_STAGNATION=38)
      integer SYS_INTER_PRESSURE
      parameter(SYS_INTER_PRESSURE=39)
      integer SYS_INTER_BAFFLE
      parameter(SYS_INTER_BAFFLE=40)
      integer SYS_INTER_FREESTREAM
      parameter(SYS_INTER_FREESTREAM=41)
      integer SYS_INTER_GASKET
      parameter(SYS_INTER_GASKET=42)
      integer SYS_INTER_COHESIVE
      parameter(SYS_INTER_COHESIVE=43)
      integer SYS_INTER_PATCH
      parameter(SYS_INTER_PATCH=44)
      integer SYS_INTER_OPENING
      parameter(SYS_INTER_OPENING=45)
      integer SYS_INTER_INLET
      parameter(SYS_INTER_INLET=46)
      integer SYS_INTER_OUTLET
      parameter(SYS_INTER_OUTLET=47)
      integer SYS_SOLID_STAN
      parameter(SYS_SOLID_STAN=0)
      integer SYS_SPRINGDASHPOT_INTRINSIC
      parameter(SYS_SPRINGDASHPOT_INTRINSIC=9)
      integer SYS_INTER_MAX
      parameter(SYS_INTER_MAX=47)
      integer SYS_ELEMSYS_GLOBAL
      parameter(SYS_ELEMSYS_GLOBAL=0)
      integer SYS_ELEMSYS_STANDARD
      parameter(SYS_ELEMSYS_STANDARD=-1)
      integer SYS_ELEMSYS_POSITION
      parameter(SYS_ELEMSYS_POSITION=-2)
      integer SYS_ELEMSYS_GLOBALPROJECT
      parameter(SYS_ELEMSYS_GLOBALPROJECT=-3)
      integer SYS_ELEMSYS_VECTOR
      parameter(SYS_ELEMSYS_VECTOR=-4)
      integer SYS_ELEMSYS_BISECTOR
      parameter(SYS_ELEMSYS_BISECTOR=-5)
      integer SYS_ELEMSYS_NASTRANSHELL
      parameter(SYS_ELEMSYS_NASTRANSHELL=-6)
      integer SYS_ELEMSYS_VECTORELEMNODE
      parameter(SYS_ELEMSYS_VECTORELEMNODE=-8)
      integer SYS_ELEMSYS_FIRSTEDGE
      parameter(SYS_ELEMSYS_FIRSTEDGE=-9)
      integer SYS_ELEMSYS_FIRSTEDGEANGLE
      parameter(SYS_ELEMSYS_FIRSTEDGEANGLE=-11)
      integer SYS_ELEMSYS_SPHERICAL_ALT
      parameter(SYS_ELEMSYS_SPHERICAL_ALT=-13)
      integer SYS_ELEMSYS_GLOBALCLOSEST
      parameter(SYS_ELEMSYS_GLOBALCLOSEST=-14)
      integer SYS_ELEMSYS_CYLINDRICAL
      parameter(SYS_ELEMSYS_CYLINDRICAL=-15)
      integer SYS_ELEMSYS_SPHERICAL
      parameter(SYS_ELEMSYS_SPHERICAL=-16)
      integer SYS_ELEMSYS_CENTROID
      parameter(SYS_ELEMSYS_CENTROID=-17)
      integer SYS_ELEMSYS_ROTANG
      parameter(SYS_ELEMSYS_ROTANG=-18)
      integer SYS_ELEMSYS_ROTANGELEMNODE
      parameter(SYS_ELEMSYS_ROTANGELEMNODE=-19)
      integer SYS_ELEMSYS_UNKNOWN
      parameter(SYS_ELEMSYS_UNKNOWN=-20)
      integer SYS_ELEMSYS_MIDEDGE
      parameter(SYS_ELEMSYS_MIDEDGE=-25)
      integer SYS_ELEMSYS_BIDIAGONAL
      parameter(SYS_ELEMSYS_BIDIAGONAL=-27)
      integer SYS_ELEMSYS_MIDPOINT
      parameter(SYS_ELEMSYS_MIDPOINT=-28)
      integer SYS_ELEMSYS_CYLINDRICAL_ALT
      parameter(SYS_ELEMSYS_CYLINDRICAL_ALT=-29)
      integer SYS_ELEMSYS_NASTRANSOLID
      parameter(SYS_ELEMSYS_NASTRANSOLID=-10)
      integer SYS_ELEMSYS_GLOBALPROJECTR
      parameter(SYS_ELEMSYS_GLOBALPROJECTR=-21)
      integer SYS_ELEMSYS_GLOBALPROJECTS
      parameter(SYS_ELEMSYS_GLOBALPROJECTS=-22)
      integer SYS_ELEMSYS_GLOBALPROJECTT
      parameter(SYS_ELEMSYS_GLOBALPROJECTT=-23)
      integer SYS_ELEMSYS_MARCSHELL
      parameter(SYS_ELEMSYS_MARCSHELL=-24)
      integer SYS_ELEMSYS_MAX
      parameter(SYS_ELEMSYS_MAX=30)
      integer SYS_ELEMEND_NONE
      parameter(SYS_ELEMEND_NONE=0)
      integer SYS_ELEMEND_POSITION
      parameter(SYS_ELEMEND_POSITION=-1)
      integer SYS_ELEMEND_OFFSET
      parameter(SYS_ELEMEND_OFFSET=-2)
      integer SYS_ELEMSEC_NONE
      parameter(SYS_ELEMSEC_NONE=0)
      integer SYS_ELEMSEC_BOT
      parameter(SYS_ELEMSEC_BOT=-1)
      integer SYS_ELEMSEC_TOP
      parameter(SYS_ELEMSEC_TOP=-2)
      integer SYS_ELEMSEC_MID
      parameter(SYS_ELEMSEC_MID=-3)
      integer SYS_ELEMSEC_ALL
      parameter(SYS_ELEMSEC_ALL=-4)
      integer SYS_LAYERPOSITION_NONE
      parameter(SYS_LAYERPOSITION_NONE=0)
      integer SYS_LAYERPOSITION_MID
      parameter(SYS_LAYERPOSITION_MID=1)
      integer SYS_LAYERPOSITION_BOTTOP
      parameter(SYS_LAYERPOSITION_BOTTOP=2)
      integer SYS_LAYERPOSITION_BOTMIDTOP
      parameter(SYS_LAYERPOSITION_BOTMIDTOP=3)
      integer SYS_LAYERPOSITION_INTPNT
      parameter(SYS_LAYERPOSITION_INTPNT=4)
      integer SYS_LAYERPOSITION_BOTMID
      parameter(SYS_LAYERPOSITION_BOTMID=5)
      integer SYS_LAYERPOSITION_MIDTOP
      parameter(SYS_LAYERPOSITION_MIDTOP=6)
      integer SYS_LAYERPOSITION_BOT
      parameter(SYS_LAYERPOSITION_BOT=7)
      integer SYS_LAYERPOSITION_TOP
      parameter(SYS_LAYERPOSITION_TOP=8)
      integer SYS_LAYERPOSITION_B1M
      parameter(SYS_LAYERPOSITION_B1M=9)
      integer SYS_LAYERPOSITION_M1T
      parameter(SYS_LAYERPOSITION_M1T=10)
      integer SYS_LAYERPOSITION_B5T
      parameter(SYS_LAYERPOSITION_B5T=11)
      integer SYS_STRAINTYPE_TENSOR
      parameter(SYS_STRAINTYPE_TENSOR=0)
      integer SYS_STRAINTYPE_ENGINEERING
      parameter(SYS_STRAINTYPE_ENGINEERING=1)
      integer SYS_BEAMSECT_PROPS
      parameter(SYS_BEAMSECT_PROPS=0)
      integer SYS_BEAMSECT_GEOMETRY
      parameter(SYS_BEAMSECT_GEOMETRY=1)
      integer SYS_BEAMSECT_BOX
      parameter(SYS_BEAMSECT_BOX=2)
      integer SYS_BEAMSECT_ANGLE
      parameter(SYS_BEAMSECT_ANGLE=3)
      integer SYS_BEAMSECT_IBEAM
      parameter(SYS_BEAMSECT_IBEAM=4)
      integer SYS_BEAMSECT_CIRCLE
      parameter(SYS_BEAMSECT_CIRCLE=5)
      integer SYS_BEAMSECT_TUBE
      parameter(SYS_BEAMSECT_TUBE=6)
      integer SYS_BEAMSECT_PANEL
      parameter(SYS_BEAMSECT_PANEL=7)
      integer SYS_BEAMSECT_RECTANGLE
      parameter(SYS_BEAMSECT_RECTANGLE=8)
      integer SYS_BEAMSECT_TRAPEZOID
      parameter(SYS_BEAMSECT_TRAPEZOID=9)
      integer SYS_BEAMSECT_HEXAGON
      parameter(SYS_BEAMSECT_HEXAGON=10)
      integer SYS_BEAMSECT_TEE
      parameter(SYS_BEAMSECT_TEE=11)
      integer SYS_BEAMSECT_ZEE
      parameter(SYS_BEAMSECT_ZEE=12)
      integer SYS_BEAMSECT_CHANNEL
      parameter(SYS_BEAMSECT_CHANNEL=13)
      integer SYS_BEAMSECT_SECTOR
      parameter(SYS_BEAMSECT_SECTOR=14)
      integer SYS_BEAMSECT_ELLIPSE
      parameter(SYS_BEAMSECT_ELLIPSE=15)
      integer SYS_BEAMSECT_HAT
      parameter(SYS_BEAMSECT_HAT=16)
      integer SYS_BEAMSECT_CROSS
      parameter(SYS_BEAMSECT_CROSS=17)
      integer SYS_BEAMSECT_DBOX
      parameter(SYS_BEAMSECT_DBOX=18)
      integer SYS_BEAMSECT_HAT1
      parameter(SYS_BEAMSECT_HAT1=19)
      integer SYS_BEAMSECT_QUAD
      parameter(SYS_BEAMSECT_QUAD=20)
      integer SYS_BEAMSECT_HATG
      parameter(SYS_BEAMSECT_HATG=21)
      integer SYS_BEAMSECT_SOLIDHEXA
      parameter(SYS_BEAMSECT_SOLIDHEXA=22)
      integer SYS_BEAMSECT_SEGMENTS
      parameter(SYS_BEAMSECT_SEGMENTS=23)
      integer SYS_BEAMSECT_MAXSECTIONS
      parameter(SYS_BEAMSECT_MAXSECTIONS=24)
      integer SYS_SHELLWALL_MONOCOQUE
      parameter(SYS_SHELLWALL_MONOCOQUE=0)
      integer SYS_SHELLWALL_PROPS
      parameter(SYS_SHELLWALL_PROPS=1)
      integer SYS_SHELLWALL_LAMINATE
      parameter(SYS_SHELLWALL_LAMINATE=2)
      integer SYS_SHELLWALL_CORRUGATED
      parameter(SYS_SHELLWALL_CORRUGATED=3)
      integer SYS_SHELLWALL_PSHELL
      parameter(SYS_SHELLWALL_PSHELL=4)
      integer SYS_SHELLWALL_MATRIX
      parameter(SYS_SHELLWALL_MATRIX=5)
      integer SYS_SHELLWALL_GEOMETRY
      parameter(SYS_SHELLWALL_GEOMETRY=6)
      integer SYS_SOLIDMIX_SINGLE
      parameter(SYS_SOLIDMIX_SINGLE=0)
      integer SYS_SOLIDMIX_MULTI
      parameter(SYS_SOLIDMIX_MULTI=1)
      integer SYS_TECH_UNDEFINNED
      parameter(SYS_TECH_UNDEFINNED=0)
      integer SYS_TECH_ISOP
      parameter(SYS_TECH_ISOP=1)
      integer SYS_TECH_URED
      parameter(SYS_TECH_URED=2)
      integer SYS_TECH_KIRCHHOFF
      parameter(SYS_TECH_KIRCHHOFF=3)
      integer SYS_TECH_MIXED
      parameter(SYS_TECH_MIXED=4)
      integer SYS_TECH_ENHANCED
      parameter(SYS_TECH_ENHANCED=5)
      integer SYS_TECH_ANS
      parameter(SYS_TECH_ANS=6)
      integer SYS_PROP_THICKNESS
      parameter(SYS_PROP_THICKNESS=2)
      integer SYS_PROP_OFFSET
      parameter(SYS_PROP_OFFSET=4)
      integer SYS_PROP_NORMAL
      parameter(SYS_PROP_NORMAL=5)
      integer SYS_PROP_FIBERBOT
      parameter(SYS_PROP_FIBERBOT=6)
      integer SYS_PROP_FIBERTOP
      parameter(SYS_PROP_FIBERTOP=7)
      integer SYS_PROP_ELEMVEC
      parameter(SYS_PROP_ELEMVEC=28)
      integer SYS_PROP_MATLVEC
      parameter(SYS_PROP_MATLVEC=29)
      integer SYS_PROP_ENDAX
      parameter(SYS_PROP_ENDAX=35)
      integer SYS_PROP_ENDBX
      parameter(SYS_PROP_ENDBX=36)
      integer SYS_PROP_OFFSETVEC
      parameter(SYS_PROP_OFFSETVEC=37)
      integer SYS_PROP_VOLFACT
      parameter(SYS_PROP_VOLFACT=3)
      integer SYS_PROP_AREA
      parameter(SYS_PROP_AREA=10)
      integer SYS_PROP_VOLFACT_MASS
      parameter(SYS_PROP_VOLFACT_MASS=40)
      integer SYS_PROP_VOLFACT_STIFF
      parameter(SYS_PROP_VOLFACT_STIFF=41)
      integer SYS_PROP_VOLFACT_LOAD
      parameter(SYS_PROP_VOLFACT_LOAD=42)
      integer SYS_REINFSECT_SMEAR
      parameter(SYS_REINFSECT_SMEAR=0)
      integer SYS_REINFSECT_LOCATION_NOTYPE
      parameter(SYS_REINFSECT_LOCATION_NOTYPE=0)
      integer SYS_REINFSECT_LOCATION_TYPE_MESH
      parameter(SYS_REINFSECT_LOCATION_TYPE_MESH=1)
      integer SYS_BASIS_SERENDIPITY
      parameter(SYS_BASIS_SERENDIPITY=0)
      integer SYS_BASIS_LAGRANGE
      parameter(SYS_BASIS_LAGRANGE=1)
      integer SYS_BASIS_BEZIER
      parameter(SYS_BASIS_BEZIER=2)
      integer SYS_BASIS_SPLINE
      parameter(SYS_BASIS_SPLINE=3)
      integer SYS_BASIS_NURBS
      parameter(SYS_BASIS_NURBS=4)
      integer SYS_BASIS_HERMITE
      parameter(SYS_BASIS_HERMITE=5)
      integer SYS_RULE_UNKKNOWN
      parameter(SYS_RULE_UNKKNOWN=0)
      integer SYS_RULE_GAUSS
      parameter(SYS_RULE_GAUSS=1)
      integer SYS_RULE_LOBATTO
      parameter(SYS_RULE_LOBATTO=2)
      integer SYS_RULE_SIMPSON
      parameter(SYS_RULE_SIMPSON=3)
      integer SYS_ERROR_NONE
      parameter(SYS_ERROR_NONE=0)
      integer SYS_ERROR_VALUE
      parameter(SYS_ERROR_VALUE=1)
      integer SYS_ERROR_ENUM
      parameter(SYS_ERROR_ENUM=2)
      integer SYS_ERROR_OBJECTTYPE
      parameter(SYS_ERROR_OBJECTTYPE=3)
      integer SYS_ERROR_MEMORY
      parameter(SYS_ERROR_MEMORY=4)
      integer SYS_ERROR_NULLOBJECT
      parameter(SYS_ERROR_NULLOBJECT=5)
      integer SYS_ERROR_FILE
      parameter(SYS_ERROR_FILE=6)
      integer SYS_ERROR_COMPUTE
      parameter(SYS_ERROR_COMPUTE=7)
      integer SYS_ERROR_OPERATION
      parameter(SYS_ERROR_OPERATION=8)
      integer SYS_ERROR_OVERFLOW
      parameter(SYS_ERROR_OVERFLOW=9)
      integer SYS_ERROR_UNDERFLOW
      parameter(SYS_ERROR_UNDERFLOW=10)
      integer SYS_ERROR_UNKNOWN
      parameter(SYS_ERROR_UNKNOWN=11)
      integer SYS_ERROR_FORMAT
      parameter(SYS_ERROR_FORMAT=12)
      integer SYS_ERROR_LOAD
      parameter(SYS_ERROR_LOAD=13)
      integer SYS_ERROR_SEVERE
      parameter(SYS_ERROR_SEVERE=14)
      integer SYS_ERROR_LICENSE
      parameter(SYS_ERROR_LICENSE=15)
      integer SYS_ERROR_MAX
      parameter(SYS_ERROR_MAX=15)
      integer SYS_MAXPATHCHAR
      parameter(SYS_MAXPATHCHAR=1024)
      integer SYS_MAXNAMECHAR
      parameter(SYS_MAXNAMECHAR=81)
      integer SYS_MAXNAME
      parameter(SYS_MAXNAME=256)
      integer SYS_MAXDATENAME
      parameter(SYS_MAXDATENAME=11)
      integer SYS_MAXTIMENAME
      parameter(SYS_MAXTIMENAME=9)
      integer SYS_FUNCTION_DEBUG
      parameter(SYS_FUNCTION_DEBUG=1)
      integer SYS_FUNCTION_MONITOR
      parameter(SYS_FUNCTION_MONITOR=2)
      integer SYS_FUNCTION_SIZING
      parameter(SYS_FUNCTION_SIZING=3)
      integer SYS_FUNCTION_ASIZING
      parameter(SYS_FUNCTION_ASIZING=4)
      integer SYS_FUNCTION_GEOPROJ
      parameter(SYS_FUNCTION_GEOPROJ=5)
      integer SYS_ORDER_AUTO
      parameter(SYS_ORDER_AUTO=0)
      integer SYS_ORDER_MMD1
      parameter(SYS_ORDER_MMD1=1)
      integer SYS_ORDER_MMD2
      parameter(SYS_ORDER_MMD2=2)
      integer SYS_ORDER_MDF1
      parameter(SYS_ORDER_MDF1=3)
      integer SYS_ORDER_ORIG
      parameter(SYS_ORDER_ORIG=4)
      integer SYS_ORDER_METIS
      parameter(SYS_ORDER_METIS=5)
      integer SYS_ORDER_BCS_MMD
      parameter(SYS_ORDER_BCS_MMD=7)
      integer SYS_ORDER_RANDOM
      parameter(SYS_ORDER_RANDOM=14)
      integer SYS_ORDER_SWEEP
      parameter(SYS_ORDER_SWEEP=15)
      integer SYS_ORDER_BAND
      parameter(SYS_ORDER_BAND=16)
      integer SYS_ORDER_EXTMETIS
      parameter(SYS_ORDER_EXTMETIS=17)
      integer SYS_TEXT_UNORDERED
      parameter(SYS_TEXT_UNORDERED=0)
      integer SYS_TEXT_ORDERED
      parameter(SYS_TEXT_ORDERED=1)
      integer SYS_TEXT_MENU
      parameter(SYS_TEXT_MENU=2)
      integer SYS_TEXT_PREFORMATTED
      parameter(SYS_TEXT_PREFORMATTED=0)
      integer SYS_TEXT_BOLD
      parameter(SYS_TEXT_BOLD=1)
      integer SYS_TEXT_ITALICS
      parameter(SYS_TEXT_ITALICS=2)
      integer SYS_TEXT_TYPEWRITER
      parameter(SYS_TEXT_TYPEWRITER=3)
      integer SYS_TEXT_CENTER
      parameter(SYS_TEXT_CENTER=4)
      integer SYS_TEXT_HANDLEERR
      parameter(SYS_TEXT_HANDLEERR=5)
      integer SYS_TEXT_BORDEREQUALS
      parameter(SYS_TEXT_BORDEREQUALS=6)
      integer SYS_TEXT_TABLETITLES
      parameter(SYS_TEXT_TABLETITLES=7)
      integer SYS_TEXT_HEADING
      parameter(SYS_TEXT_HEADING=1)
      integer SYS_TEXT_ANCHOR
      parameter(SYS_TEXT_ANCHOR=2)
      integer SYS_TEXT_TITLE
      parameter(SYS_TEXT_TITLE=3)
      integer SYS_TEXT_LIST
      parameter(SYS_TEXT_LIST=4)
      integer SYS_TEXT_ITEM
      parameter(SYS_TEXT_ITEM=5)
      integer SYS_TEXT_PARAGRAPH
      parameter(SYS_TEXT_PARAGRAPH=6)
      integer SYS_TEXT_LINEBREAK
      parameter(SYS_TEXT_LINEBREAK=7)
      integer SYS_TEXT_TABLE
      parameter(SYS_TEXT_TABLE=8)
      integer SYS_TEXT_ROW
      parameter(SYS_TEXT_ROW=9)
      integer SYS_TEXT_COLUMN
      parameter(SYS_TEXT_COLUMN=10)
      integer SYS_TEXT_INTERRUPT
      parameter(SYS_TEXT_INTERRUPT=11)
      integer SYS_TEXT_LEFT
      parameter(SYS_TEXT_LEFT=1)
      integer SYS_TEXT_MIDDLE
      parameter(SYS_TEXT_MIDDLE=2)
      integer SYS_TEXT_RIGHT
      parameter(SYS_TEXT_RIGHT=3)
      integer SYS_ANALYSIS_NONE
      parameter(SYS_ANALYSIS_NONE=0)
      integer SYS_ANALYSIS_STRUCTURAL
      parameter(SYS_ANALYSIS_STRUCTURAL=1)
      integer SYS_ANALYSIS_THERMAL
      parameter(SYS_ANALYSIS_THERMAL=2)
      integer SYS_ANALYSIS_ELECTRIC
      parameter(SYS_ANALYSIS_ELECTRIC=3)
      integer SYS_ANALYSIS_MAGNETIC
      parameter(SYS_ANALYSIS_MAGNETIC=4)
      integer SYS_ANALYSIS_FLUID
      parameter(SYS_ANALYSIS_FLUID=5)
      integer SYS_ANALYSIS_ACOUSTIC
      parameter(SYS_ANALYSIS_ACOUSTIC=6)
      integer SYS_ANALYSIS_DIFFUSION
      parameter(SYS_ANALYSIS_DIFFUSION=7)
      integer SYS_ANALYSIS_ELECTROCHEMICAL
      parameter(SYS_ANALYSIS_ELECTROCHEMICAL=8)
      integer SYS_PLANESTRAIN
      parameter(SYS_PLANESTRAIN=1)
      integer SYS_PLANESTRESS
      parameter(SYS_PLANESTRESS=2)
      integer SYS_AXISYMMETRIC
      parameter(SYS_AXISYMMETRIC=3)
      integer SYS_AXISYMFOURIER
      parameter(SYS_AXISYMFOURIER=4)
      integer SYS_EIGEN_NONE
      parameter(SYS_EIGEN_NONE=0)
      integer SYS_EIGEN_ALL
      parameter(SYS_EIGEN_ALL=1)
      integer SYS_EIGEN_LOWEST
      parameter(SYS_EIGEN_LOWEST=2)
      integer SYS_EIGEN_NEAREST
      parameter(SYS_EIGEN_NEAREST=3)
      integer SYS_EIGEN_SUBSPACE
      parameter(SYS_EIGEN_SUBSPACE=5)
      integer SYS_EIGEN_LANCZOS
      parameter(SYS_EIGEN_LANCZOS=6)
      integer SYS_EIGEN_AMLS
      parameter(SYS_EIGEN_AMLS=9)
      integer SYS_EIGEN_NORMMASS
      parameter(SYS_EIGEN_NORMMASS=7)
      integer SYS_EIGEN_NORMMAX
      parameter(SYS_EIGEN_NORMMAX=8)
      integer SYS_SOLVERTYPE_PARDISO
      parameter(SYS_SOLVERTYPE_PARDISO=1)
      integer SYS_SOLVERTYPE_MUMPS
      parameter(SYS_SOLVERTYPE_MUMPS=2)
      integer SYS_SOLVERTYPE_MUMPSPIVOT
      parameter(SYS_SOLVERTYPE_MUMPSPIVOT=3)
      integer SYS_SOLVERTYPE_LL
      parameter(SYS_SOLVERTYPE_LL=4)
      integer SYS_SOLVERTYPE_MF
      parameter(SYS_SOLVERTYPE_MF=5)
      integer SYS_SOLVERTYPE_MFP
      parameter(SYS_SOLVERTYPE_MFP=6)
      integer SYS_DOF_NONE
      parameter(SYS_DOF_NONE=0)
      integer SYS_DOF_TX
      parameter(SYS_DOF_TX=1)
      integer SYS_DOF_TY
      parameter(SYS_DOF_TY=2)
      integer SYS_DOF_TZ
      parameter(SYS_DOF_TZ=3)
      integer SYS_DOF_RX
      parameter(SYS_DOF_RX=4)
      integer SYS_DOF_RY
      parameter(SYS_DOF_RY=5)
      integer SYS_DOF_RZ
      parameter(SYS_DOF_RZ=6)
      integer SYS_DOF_TEMP
      parameter(SYS_DOF_TEMP=7)
      integer SYS_DOF_VOLT
      parameter(SYS_DOF_VOLT=8)
      integer SYS_DOF_WARP
      parameter(SYS_DOF_WARP=9)
      integer SYS_DOF_PRES
      parameter(SYS_DOF_PRES=10)
      integer SYS_DOF_VX
      parameter(SYS_DOF_VX=11)
      integer SYS_DOF_VY
      parameter(SYS_DOF_VY=12)
      integer SYS_DOF_VZ
      parameter(SYS_DOF_VZ=13)
      integer SYS_DOF_ELEM
      parameter(SYS_DOF_ELEM=14)
      integer SYS_DOF_LAGM
      parameter(SYS_DOF_LAGM=15)
      integer SYS_DOF_S0
      parameter(SYS_DOF_S0=16)
      integer SYS_DOF_S1
      parameter(SYS_DOF_S1=17)
      integer SYS_DOF_S2
      parameter(SYS_DOF_S2=18)
      integer SYS_DOF_S3
      parameter(SYS_DOF_S3=19)
      integer SYS_DOF_S4
      parameter(SYS_DOF_S4=20)
      integer SYS_DOF_S5
      parameter(SYS_DOF_S5=21)
      integer SYS_DOF_S6
      parameter(SYS_DOF_S6=22)
      integer SYS_DOF_S7
      parameter(SYS_DOF_S7=23)
      integer SYS_DOF_S8
      parameter(SYS_DOF_S8=24)
      integer SYS_DOF_S9
      parameter(SYS_DOF_S9=25)
      integer SYS_DOF_S10
      parameter(SYS_DOF_S10=26)
      integer SYS_DOF_S11
      parameter(SYS_DOF_S11=27)
      integer SYS_DOF_S12
      parameter(SYS_DOF_S12=28)
      integer SYS_DOF_S13
      parameter(SYS_DOF_S13=29)
      integer SYS_DOF_S14
      parameter(SYS_DOF_S14=30)
      integer SYS_DOF_S15
      parameter(SYS_DOF_S15=31)
      integer SYS_DOF_S
      parameter(SYS_DOF_S=16)
      integer SYS_DOF_MAX
      parameter(SYS_DOF_MAX=31)
      integer SYS_MAT_ISOTROPIC
      parameter(SYS_MAT_ISOTROPIC=0)
      integer SYS_MAT_LAMINA
      parameter(SYS_MAT_LAMINA=1)
      integer SYS_MAT_ORTHOTROPIC
      parameter(SYS_MAT_ORTHOTROPIC=2)
      integer SYS_MAT_ANISOTROPIC
      parameter(SYS_MAT_ANISOTROPIC=3)
      integer SYS_MAT_HYPERELASTIC
      parameter(SYS_MAT_HYPERELASTIC=4)
      integer SYS_MAT_GENERIC
      parameter(SYS_MAT_GENERIC=5)
      integer SYS_MAT_MAX
      parameter(SYS_MAT_MAX=6)
      integer SYS_MAT_HARDENING_ISOTROPIC
      parameter(SYS_MAT_HARDENING_ISOTROPIC=-1)
      integer SYS_MAT_HARDENING_KINEMATIC
      parameter(SYS_MAT_HARDENING_KINEMATIC=-2)
      integer SYS_HEATEXCH_LINEAR
      parameter(SYS_HEATEXCH_LINEAR=1)
      integer SYS_HEATEXCH_EXP
      parameter(SYS_HEATEXCH_EXP=2)
      integer SYS_HEATEXCH_POW
      parameter(SYS_HEATEXCH_POW=3)
      integer SYS_HEATEXCH_RAD
      parameter(SYS_HEATEXCH_RAD=4)
      integer SYS_ASCII
      parameter(SYS_ASCII=-1)
      integer SYS_BINARY
      parameter(SYS_BINARY=-2)
      integer SYS_FILE_STL
      parameter(SYS_FILE_STL=-4)
      integer SYS_FILE_STLBIN
      parameter(SYS_FILE_STLBIN=-5)
      integer SYS_FILE_OBJ
      parameter(SYS_FILE_OBJ=-6)
      integer SYS_MAGIC
      parameter(SYS_MAGIC=7946)
      integer SYS_NATIVE
      parameter(SYS_NATIVE=1)
      integer SYS_PLOT3D_GRID
      parameter(SYS_PLOT3D_GRID=2)
      integer SYS_PLOT3D_SOLUTION
      parameter(SYS_PLOT3D_SOLUTION=3)
      integer SYS_PATRAN_RESULT
      parameter(SYS_PATRAN_RESULT=4)
      integer SYS_GENERIC
      parameter(SYS_GENERIC=5)
      integer SYS_PDA
      parameter(SYS_PDA=6)
      integer SYS_LSTC_STATE
      parameter(SYS_LSTC_STATE=7)
      integer SYS_ABAQUS_ODB
      parameter(SYS_ABAQUS_ODB=8)
      integer SYS_ABAQUS_FIL
      parameter(SYS_ABAQUS_FIL=9)
      integer SYS_NASTRAN_OUTPUT2
      parameter(SYS_NASTRAN_OUTPUT2=10)
      integer SYS_STL
      parameter(SYS_STL=11)
      integer SYS_STLBIN
      parameter(SYS_STLBIN=12)
      integer SYS_ABAQUS_INPUT
      parameter(SYS_ABAQUS_INPUT=13)
      integer SYS_SDRC_UNIVERSAL
      parameter(SYS_SDRC_UNIVERSAL=14)
      integer SYS_PAM_DAISY
      parameter(SYS_PAM_DAISY=15)
      integer SYS_ANSYS_RESULT
      parameter(SYS_ANSYS_RESULT=16)
      integer SYS_MECHANICA_STUDY
      parameter(SYS_MECHANICA_STUDY=17)
      integer SYS_NASTRAN_BULKDATA
      parameter(SYS_NASTRAN_BULKDATA=18)
      integer SYS_FDI_NEUTRAL
      parameter(SYS_FDI_NEUTRAL=19)
      integer SYS_PATRAN_NEUTRAL
      parameter(SYS_PATRAN_NEUTRAL=20)
      integer SYS_FLUENT_MESH
      parameter(SYS_FLUENT_MESH=21)
      integer SYS_ANSYS_INPUT
      parameter(SYS_ANSYS_INPUT=22)
      integer SYS_TECPLOT
      parameter(SYS_TECPLOT=23)
      integer SYS_HYPERMESH_ASCII
      parameter(SYS_HYPERMESH_ASCII=24)
      integer SYS_LSTC_INPUT
      parameter(SYS_LSTC_INPUT=25)
      integer SYS_CGNS
      parameter(SYS_CGNS=26)
      integer SYS_MARC_POST
      parameter(SYS_MARC_POST=27)
      integer SYS_ENSIGHT
      parameter(SYS_ENSIGHT=28)
      integer SYS_STARCCM
      parameter(SYS_STARCCM=29)
      integer SYS_MECHANICA_FNF
      parameter(SYS_MECHANICA_FNF=30)
      integer SYS_LSTC_HISTORY
      parameter(SYS_LSTC_HISTORY=32)
      integer SYS_NASTRAN_XDB
      parameter(SYS_NASTRAN_XDB=33)
      integer SYS_NASTRAN_H5
      parameter(SYS_NASTRAN_H5=34)
      integer SYS_POLYFLOW
      parameter(SYS_POLYFLOW=36)
      integer SYS_FEMAP_NEUTRAL
      parameter(SYS_FEMAP_NEUTRAL=37)
      integer SYS_AUTODYN_RES
      parameter(SYS_AUTODYN_RES=38)
      integer SYS_PAM_ERF
      parameter(SYS_PAM_ERF=39)
      integer SYS_OPENFOAM
      parameter(SYS_OPENFOAM=40)
      integer SYS_OBJ
      parameter(SYS_OBJ=41)
      integer SYS_COMSOL_SECTION
      parameter(SYS_COMSOL_SECTION=43)
      integer SYS_H3D
      parameter(SYS_H3D=44)
      integer SYS_LSTC_STATEFEMZIP
      parameter(SYS_LSTC_STATEFEMZIP=45)
      integer SYS_PAM_INPUT
      parameter(SYS_PAM_INPUT=46)
      integer SYS_CFX_RESULT
      parameter(SYS_CFX_RESULT=47)
      integer SYS_GMV
      parameter(SYS_GMV=48)
      integer SYS_PERMAS_POST
      parameter(SYS_PERMAS_POST=49)
      integer SYS_VTK_LEGACY
      parameter(SYS_VTK_LEGACY=50)
      integer SYS_SAMCEF
      parameter(SYS_SAMCEF=51)
      integer SYS_AFLR
      parameter(SYS_AFLR=52)
      integer SYS_ADAMS
      parameter(SYS_ADAMS=53)
      integer SYS_NATIVE_HDF5
      parameter(SYS_NATIVE_HDF5=54)
      integer SYS_MEMORY
      parameter(SYS_MEMORY=55)
      integer SYS_COMSOL_MPH
      parameter(SYS_COMSOL_MPH=56)
      integer SYS_COMSOL_MPHBIN
      parameter(SYS_COMSOL_MPHBIN=57)
      integer SYS_MARC_INPUT
      parameter(SYS_MARC_INPUT=58)
      integer SYS_ANSYS_DPF
      parameter(SYS_ANSYS_DPF=59)
      integer SYS_PLUGIN
      parameter(SYS_PLUGIN=60)
      integer SYS_VTK_VTU
      parameter(SYS_VTK_VTU=61)
      integer SYS_MAXTYPE
      parameter(SYS_MAXTYPE=62)
      integer SYS_CATEGORY_NONE
      parameter(SYS_CATEGORY_NONE=0)
      integer SYS_CATEGORY_BUCK
      parameter(SYS_CATEGORY_BUCK=1)
      integer SYS_CATEGORY_VIBE
      parameter(SYS_CATEGORY_VIBE=2)
      integer SYS_CATEGORY_STAT
      parameter(SYS_CATEGORY_STAT=3)
      integer SYS_CATEGORY_TRAN
      parameter(SYS_CATEGORY_TRAN=4)
      integer SYS_CATEGORY_CONS
      parameter(SYS_CATEGORY_CONS=5)
      integer SYS_CATEGORY_CONC
      parameter(SYS_CATEGORY_CONC=6)
      integer SYS_CATEGORY_DIST
      parameter(SYS_CATEGORY_DIST=7)
      integer SYS_CATEGORY_INERTIA
      parameter(SYS_CATEGORY_INERTIA=8)
      integer SYS_CATEGORY_EFFINERTIA
      parameter(SYS_CATEGORY_EFFINERTIA=9)
      integer SYS_CATEGORY_RIGID
      parameter(SYS_CATEGORY_RIGID=10)
      integer SYS_CATEGORY_LOAD
      parameter(SYS_CATEGORY_LOAD=11)
      integer SYS_CATEGORY_FREQUENCYRESPONSE
      parameter(SYS_CATEGORY_FREQUENCYRESPONSE=12)
      integer SYS_CATEGORY_MAX
      parameter(SYS_CATEGORY_MAX=13)
      integer SYS_VENDOR_UNKNOWN
      parameter(SYS_VENDOR_UNKNOWN=0)
      integer SYS_VENDOR_VKI
      parameter(SYS_VENDOR_VKI=1)
      integer SYS_VENDOR_MSC_NASTRAN
      parameter(SYS_VENDOR_MSC_NASTRAN=2)
      integer SYS_VENDOR_ANSYS
      parameter(SYS_VENDOR_ANSYS=3)
      integer SYS_VENDOR_ABAQUS
      parameter(SYS_VENDOR_ABAQUS=4)
      integer SYS_VENDOR_LS_DYNA3D
      parameter(SYS_VENDOR_LS_DYNA3D=5)
      integer SYS_VENDOR_ALTAIR_OPTISTRUCT
      parameter(SYS_VENDOR_ALTAIR_OPTISTRUCT=6)
      integer SYS_VENDOR_NX_NASTRAN
      parameter(SYS_VENDOR_NX_NASTRAN=7)
      integer SYS_VENDOR_ADINA_NASTRAN
      parameter(SYS_VENDOR_ADINA_NASTRAN=7)
      integer SYS_VENDOR_MAX
      parameter(SYS_VENDOR_MAX=8)
      integer SYS_RES_NONE
      parameter(SYS_RES_NONE=-1)
      integer SYS_RES_X
      parameter(SYS_RES_X=0)
      integer SYS_RES_D
      parameter(SYS_RES_D=1)
      integer SYS_RES_XF
      parameter(SYS_RES_XF=2)
      integer SYS_RES_R
      parameter(SYS_RES_R=3)
      integer SYS_RES_V
      parameter(SYS_RES_V=4)
      integer SYS_RES_A
      parameter(SYS_RES_A=5)
      integer SYS_RES_HEAT_FLUX
      parameter(SYS_RES_HEAT_FLUX=6)
      integer SYS_RES_VOLT
      parameter(SYS_RES_VOLT=7)
      integer SYS_RES_DENS
      parameter(SYS_RES_DENS=8)
      integer SYS_RES_VISC
      parameter(SYS_RES_VISC=9)
      integer SYS_RES_COND
      parameter(SYS_RES_COND=10)
      integer SYS_RES_MACH
      parameter(SYS_RES_MACH=11)
      integer SYS_RES_STREAM
      parameter(SYS_RES_STREAM=12)
      integer SYS_RES_ENTROPY
      parameter(SYS_RES_ENTROPY=13)
      integer SYS_RES_MASS_FLUX
      parameter(SYS_RES_MASS_FLUX=14)
      integer SYS_RES_TEMP
      parameter(SYS_RES_TEMP=15)
      integer SYS_RES_FILM_COEF
      parameter(SYS_RES_FILM_COEF=16)
      integer SYS_RES_J
      parameter(SYS_RES_J=17)
      integer SYS_RES_TF
      parameter(SYS_RES_TF=18)
      integer SYS_RES_PRES
      parameter(SYS_RES_PRES=19)
      integer SYS_RES_D_MAT
      parameter(SYS_RES_D_MAT=20)
      integer SYS_RES_ELEC_POT
      parameter(SYS_RES_ELEC_POT=21)
      integer SYS_RES_Q
      parameter(SYS_RES_Q=22)
      integer SYS_RES_MAG_POT
      parameter(SYS_RES_MAG_POT=23)
      integer SYS_RES_R_J
      parameter(SYS_RES_R_J=24)
      integer SYS_RES_MASS_FLOW
      parameter(SYS_RES_MASS_FLOW=25)
      integer SYS_RES_VOLUME
      parameter(SYS_RES_VOLUME=26)
      integer SYS_RES_VOLUME_FLUX
      parameter(SYS_RES_VOLUME_FLUX=27)
      integer SYS_RES_UNKNOWN
      parameter(SYS_RES_UNKNOWN=28)
      integer SYS_RES_V_DIV
      parameter(SYS_RES_V_DIV=29)
      integer SYS_RES_E
      parameter(SYS_RES_E=30)
      integer SYS_RES_INERTIA
      parameter(SYS_RES_INERTIA=31)
      integer SYS_RES_DENS_GRAD
      parameter(SYS_RES_DENS_GRAD=32)
      integer SYS_RES_P
      parameter(SYS_RES_P=33)
      integer SYS_RES_TIME
      parameter(SYS_RES_TIME=34)
      integer SYS_RES_S
      parameter(SYS_RES_S=35)
      integer SYS_RES_ID
      parameter(SYS_RES_ID=36)
      integer SYS_RES_V_GRAD
      parameter(SYS_RES_V_GRAD=37)
      integer SYS_RES_USER
      parameter(SYS_RES_USER=38)
      integer SYS_RES_THICKNESS
      parameter(SYS_RES_THICKNESS=39)
      integer SYS_RES_STIFF
      parameter(SYS_RES_STIFF=40)
      integer SYS_RES_R_Q
      parameter(SYS_RES_R_Q=41)
      integer SYS_RES_SCALARS
      parameter(SYS_RES_SCALARS=42)
      integer SYS_RES_HEAT_GRAD
      parameter(SYS_RES_HEAT_GRAD=43)
      integer SYS_RES_TE_ERROR
      parameter(SYS_RES_TE_ERROR=44)
      integer SYS_RES_XF_Q
      parameter(SYS_RES_XF_Q=45)
      integer SYS_RES_ENERGY_DENSITY
      parameter(SYS_RES_ENERGY_DENSITY=46)
      integer SYS_RES_SDV
      parameter(SYS_RES_SDV=47)
      integer SYS_RES_VIEW_FACT
      parameter(SYS_RES_VIEW_FACT=48)
      integer SYS_RES_DAMP
      parameter(SYS_RES_DAMP=49)
      integer SYS_RES_FREQ
      parameter(SYS_RES_FREQ=50)
      integer SYS_RES_SE_DENSITY
      parameter(SYS_RES_SE_DENSITY=51)
      integer SYS_RES_K_MAT
      parameter(SYS_RES_K_MAT=52)
      integer SYS_RES_M_MAT
      parameter(SYS_RES_M_MAT=53)
      integer SYS_RES_L_VEC
      parameter(SYS_RES_L_VEC=54)
      integer SYS_RES_ORDER
      parameter(SYS_RES_ORDER=55)
      integer SYS_RES_AREA
      parameter(SYS_RES_AREA=56)
      integer SYS_RES_LENGTH
      parameter(SYS_RES_LENGTH=57)
      integer SYS_RES_RADIUS
      parameter(SYS_RES_RADIUS=58)
      integer SYS_RES_NUMBER
      parameter(SYS_RES_NUMBER=59)
      integer SYS_RES_KE_DENSITY
      parameter(SYS_RES_KE_DENSITY=60)
      integer SYS_RES_DAMAGE
      parameter(SYS_RES_DAMAGE=61)
      integer SYS_RES_DIST
      parameter(SYS_RES_DIST=62)
      integer SYS_RES_TEMP_DOT
      parameter(SYS_RES_TEMP_DOT=63)
      integer SYS_RES_TE
      parameter(SYS_RES_TE=64)
      integer SYS_RES_COND_MAT
      parameter(SYS_RES_COND_MAT=65)
      integer SYS_RES_CAP_MAT
      parameter(SYS_RES_CAP_MAT=66)
      integer SYS_RES_FAIL_INDEX
      parameter(SYS_RES_FAIL_INDEX=67)
      integer SYS_RES_VOID_RATIO
      parameter(SYS_RES_VOID_RATIO=69)
      integer SYS_RES_TEMP_GRAD
      parameter(SYS_RES_TEMP_GRAD=70)
      integer SYS_RES_PRES_COEF
      parameter(SYS_RES_PRES_COEF=71)
      integer SYS_RES_LOAD_FACT
      parameter(SYS_RES_LOAD_FACT=72)
      integer SYS_RES_PRES_GRAD
      parameter(SYS_RES_PRES_GRAD=73)
      integer SYS_RES_PRES_DOT
      parameter(SYS_RES_PRES_DOT=74)
      integer SYS_RES_PRES_DOTDOT
      parameter(SYS_RES_PRES_DOTDOT=75)
      integer SYS_RES_MASS
      parameter(SYS_RES_MASS=76)
      integer SYS_RES_HEAT
      parameter(SYS_RES_HEAT=77)
      integer SYS_RES_CRACK_DENSITY
      parameter(SYS_RES_CRACK_DENSITY=78)
      integer SYS_RES_ELEC_FIELD
      parameter(SYS_RES_ELEC_FIELD=79)
      integer SYS_RES_ELEC_FLUX
      parameter(SYS_RES_ELEC_FLUX=80)
      integer SYS_RES_R_HEAT_FLOW
      parameter(SYS_RES_R_HEAT_FLOW=81)
      integer SYS_RES_MAG_FLUX
      parameter(SYS_RES_MAG_FLUX=82)
      integer SYS_RES_MAG_FIELD
      parameter(SYS_RES_MAG_FIELD=83)
      integer SYS_RES_J_DENSITY
      parameter(SYS_RES_J_DENSITY=84)
      integer SYS_RES_TURB_KE
      parameter(SYS_RES_TURB_KE=85)
      integer SYS_RES_TURB_ED
      parameter(SYS_RES_TURB_ED=86)
      integer SYS_RES_CONC
      parameter(SYS_RES_CONC=87)
      integer SYS_RES_H
      parameter(SYS_RES_H=88)
      integer SYS_RES_CP
      parameter(SYS_RES_CP=89)
      integer SYS_RES_POROSITY
      parameter(SYS_RES_POROSITY=90)
      integer SYS_RES_H_DOT
      parameter(SYS_RES_H_DOT=91)
      integer SYS_RES_FACTOR
      parameter(SYS_RES_FACTOR=92)
      integer SYS_RES_HEAT_FLOW
      parameter(SYS_RES_HEAT_FLOW=93)
      integer SYS_RES_SFM
      parameter(SYS_RES_SFM=94)
      integer SYS_RES_SEK
      parameter(SYS_RES_SEK=95)
      integer SYS_RES_WEIGHT
      parameter(SYS_RES_WEIGHT=96)
      integer SYS_RES_KE
      parameter(SYS_RES_KE=97)
      integer SYS_RES_SE
      parameter(SYS_RES_SE=98)
      integer SYS_RES_DIR
      parameter(SYS_RES_DIR=99)
      integer SYS_RES_ENERGY
      parameter(SYS_RES_ENERGY=100)
      integer SYS_RES_SEP
      parameter(SYS_RES_SEP=102)
      integer SYS_RES_CLOSURE
      parameter(SYS_RES_CLOSURE=105)
      integer SYS_RES_STATE
      parameter(SYS_RES_STATE=107)
      integer SYS_RES_STAT
      parameter(SYS_RES_STAT=108)
      integer SYS_RES_R_MASS_FLOW
      parameter(SYS_RES_R_MASS_FLOW=109)
      integer SYS_RES_XF_MASS_FLOW
      parameter(SYS_RES_XF_MASS_FLOW=110)
      integer SYS_RES_E_RATE
      parameter(SYS_RES_E_RATE=113)
      integer SYS_RES_SE_ERROR
      parameter(SYS_RES_SE_ERROR=117)
      integer SYS_RES_XF_HEAT_FLOW
      parameter(SYS_RES_XF_HEAT_FLOW=119)
      integer SYS_RES_DIR_COS
      parameter(SYS_RES_DIR_COS=120)
      integer SYS_RES_SF
      parameter(SYS_RES_SF=121)
      integer SYS_RES_SD
      parameter(SYS_RES_SD=122)
      integer SYS_RES_YPLUS
      parameter(SYS_RES_YPLUS=123)
      integer SYS_RES_UTAU
      parameter(SYS_RES_UTAU=124)
      integer SYS_RES_SE_PERCENT
      parameter(SYS_RES_SE_PERCENT=125)
      integer SYS_RES_KE_PERCENT
      parameter(SYS_RES_KE_PERCENT=126)
      integer SYS_RES_DOM_FLUID_PHASE
      parameter(SYS_RES_DOM_FLUID_PHASE=127)
      integer SYS_RES_SOUND_MODEL
      parameter(SYS_RES_SOUND_MODEL=128)
      integer SYS_RES_PENE_CONTACT
      parameter(SYS_RES_PENE_CONTACT=129)
      integer SYS_RES_SAFE_FACT
      parameter(SYS_RES_SAFE_FACT=139)
      integer SYS_RES_FAT_DAMAGE
      parameter(SYS_RES_FAT_DAMAGE=140)
      integer SYS_RES_FAT_DAMAGE_DIR
      parameter(SYS_RES_FAT_DAMAGE_DIR=141)
      integer SYS_RES_FAT_LIFE
      parameter(SYS_RES_FAT_LIFE=142)
      integer SYS_RES_GAP
      parameter(SYS_RES_GAP=144)
      integer SYS_RES_EN_FORC
      parameter(SYS_RES_EN_FORC=145)
      integer SYS_RES_EN_FLUX
      parameter(SYS_RES_EN_FLUX=146)
      integer SYS_RES_STRENGTH_SAFE_FACT
      parameter(SYS_RES_STRENGTH_SAFE_FACT=147)
      integer SYS_RES_FAT_SAFE_FACT
      parameter(SYS_RES_FAT_SAFE_FACT=148)
      integer SYS_RES_PHASE_DIAMETER
      parameter(SYS_RES_PHASE_DIAMETER=149)
      integer SYS_RES_MU_LAMB
      parameter(SYS_RES_MU_LAMB=150)
      integer SYS_RES_MU_TURB
      parameter(SYS_RES_MU_TURB=151)
      integer SYS_RES_BODY_FORCE
      parameter(SYS_RES_BODY_FORCE=152)
      integer SYS_RES_WALL_SHEAR
      parameter(SYS_RES_WALL_SHEAR=153)
      integer SYS_RES_VORTICITY
      parameter(SYS_RES_VORTICITY=154)
      integer SYS_RES_REACTION_PROGRESS
      parameter(SYS_RES_REACTION_PROGRESS=155)
      integer SYS_RES_SOUND_LEVEL
      parameter(SYS_RES_SOUND_LEVEL=156)
      integer SYS_RES_ROT_ANG
      parameter(SYS_RES_ROT_ANG=157)
      integer SYS_RES_VOF
      parameter(SYS_RES_VOF=158)
      integer SYS_RES_VISC_EDDY
      parameter(SYS_RES_VISC_EDDY=159)
      integer SYS_RES_ROUGHNESS
      parameter(SYS_RES_ROUGHNESS=160)
      integer SYS_RES_FRACTION
      parameter(SYS_RES_FRACTION=161)
      integer SYS_RES_CONV_COEF
      parameter(SYS_RES_CONV_COEF=162)
      integer SYS_RES_POWER
      parameter(SYS_RES_POWER=163)
      integer SYS_RES_INTENSITY
      parameter(SYS_RES_INTENSITY=164)
      integer SYS_RES_TRAC
      parameter(SYS_RES_TRAC=165)
      integer SYS_RES_XF_J
      parameter(SYS_RES_XF_J=166)
      integer SYS_RES_PRANDTL
      parameter(SYS_RES_PRANDTL=167)
      integer SYS_RES_TURB_DIST
      parameter(SYS_RES_TURB_DIST=168)
      integer SYS_RES_REYNOLDS
      parameter(SYS_RES_REYNOLDS=169)
      integer SYS_RES_RADIANCE
      parameter(SYS_RES_RADIANCE=170)
      integer SYS_RES_FLUENCE
      parameter(SYS_RES_FLUENCE=171)
      integer SYS_RES_RC_PROD
      parameter(SYS_RES_RC_PROD=172)
      integer SYS_RES_POWER_DENSITY
      parameter(SYS_RES_POWER_DENSITY=173)
      integer SYS_RES_WATER_ACCUM
      parameter(SYS_RES_WATER_ACCUM=174)
      integer SYS_RES_TURB_SD
      parameter(SYS_RES_TURB_SD=175)
      integer SYS_RES_TE_DENSITY
      parameter(SYS_RES_TE_DENSITY=176)
      integer SYS_RES_STRENGTH_RATIO
      parameter(SYS_RES_STRENGTH_RATIO=177)
      integer SYS_RES_DELETED
      parameter(SYS_RES_DELETED=178)
      integer SYS_RES_MARG_SAFE
      parameter(SYS_RES_MARG_SAFE=179)
      integer SYS_RES_MOMENT
      parameter(SYS_RES_MOMENT=180)
      integer SYS_RES_ROTATION
      parameter(SYS_RES_ROTATION=181)
      integer SYS_RES_TRANSLATION
      parameter(SYS_RES_TRANSLATION=182)
      integer SYS_RES_FORCE
      parameter(SYS_RES_FORCE=183)
      integer SYS_RES_DECIBEL
      parameter(SYS_RES_DECIBEL=184)
      integer SYS_RES_PROBABILITY
      parameter(SYS_RES_PROBABILITY=185)
      integer SYS_RES_FORCE_MOMENT
      parameter(SYS_RES_FORCE_MOMENT=186)
      integer SYS_RES_YOUNGS_MODULUS
      parameter(SYS_RES_YOUNGS_MODULUS=187)
      integer SYS_RES_POISSONS_RATIO
      parameter(SYS_RES_POISSONS_RATIO=188)
      integer SYS_RES_SHEAR_MODULUS
      parameter(SYS_RES_SHEAR_MODULUS=189)
      integer SYS_RES_TEXP_COEF
      parameter(SYS_RES_TEXP_COEF=190)
      integer SYS_RES_CHEM_SHRINKAGE
      parameter(SYS_RES_CHEM_SHRINKAGE=191)
      integer SYS_RES_CONVERSIONTIME
      parameter(SYS_RES_CONVERSIONTIME=192)
      integer SYS_RES_CONVERSIONSTATUS
      parameter(SYS_RES_CONVERSIONSTATUS=193)
      integer SYS_RES_EFFECTIVEMASSSUMMARY
      parameter(SYS_RES_EFFECTIVEMASSSUMMARY=194)
      integer SYS_RES_EFFECTIVEMASS
      parameter(SYS_RES_EFFECTIVEMASS=195)
      integer SYS_RES_PARTICIPATIONFACTOR
      parameter(SYS_RES_PARTICIPATIONFACTOR=196)
      integer SYS_RES_MASSFRACTION
      parameter(SYS_RES_MASSFRACTION=197)
      integer SYS_RES_TM
      parameter(SYS_RES_TM=198)
      integer SYS_RES_HOURGLASS_ENERGY
      parameter(SYS_RES_HOURGLASS_ENERGY=199)
      integer SYS_RES_MAX
      parameter(SYS_RES_MAX=200)
      integer SYS_QUA_NONE
      parameter(SYS_QUA_NONE=-1)
      integer SYS_QUA_X
      parameter(SYS_QUA_X=0)
      integer SYS_QUA_Y
      parameter(SYS_QUA_Y=1)
      integer SYS_QUA_Z
      parameter(SYS_QUA_Z=2)
      integer SYS_QUA_MAG
      parameter(SYS_QUA_MAG=3)
      integer SYS_QUA_XX
      parameter(SYS_QUA_XX=4)
      integer SYS_QUA_YY
      parameter(SYS_QUA_YY=5)
      integer SYS_QUA_ZZ
      parameter(SYS_QUA_ZZ=6)
      integer SYS_QUA_XY
      parameter(SYS_QUA_XY=7)
      integer SYS_QUA_YZ
      parameter(SYS_QUA_YZ=8)
      integer SYS_QUA_ZX
      parameter(SYS_QUA_ZX=9)
      integer SYS_QUA_VONMISES
      parameter(SYS_QUA_VONMISES=10)
      integer SYS_QUA_NXX
      parameter(SYS_QUA_NXX=11)
      integer SYS_QUA_NYY
      parameter(SYS_QUA_NYY=12)
      integer SYS_QUA_NXY
      parameter(SYS_QUA_NXY=13)
      integer SYS_QUA_MXX
      parameter(SYS_QUA_MXX=14)
      integer SYS_QUA_MYY
      parameter(SYS_QUA_MYY=15)
      integer SYS_QUA_MXY
      parameter(SYS_QUA_MXY=16)
      integer SYS_QUA_QXY
      parameter(SYS_QUA_QXY=17)
      integer SYS_QUA_QZX
      parameter(SYS_QUA_QZX=18)
      integer SYS_QUA_TX
      parameter(SYS_QUA_TX=19)
      integer SYS_QUA_TY
      parameter(SYS_QUA_TY=20)
      integer SYS_QUA_TZ
      parameter(SYS_QUA_TZ=21)
      integer SYS_QUA_RX
      parameter(SYS_QUA_RX=22)
      integer SYS_QUA_RY
      parameter(SYS_QUA_RY=23)
      integer SYS_QUA_RZ
      parameter(SYS_QUA_RZ=24)
      integer SYS_QUA_MINIMUM
      parameter(SYS_QUA_MINIMUM=25)
      integer SYS_QUA_MAXIMUM
      parameter(SYS_QUA_MAXIMUM=26)
      integer SYS_QUA_INTERMEDIATE
      parameter(SYS_QUA_INTERMEDIATE=27)
      integer SYS_QUA_EFF
      parameter(SYS_QUA_EFF=28)
      integer SYS_QUA_TOT
      parameter(SYS_QUA_TOT=29)
      integer SYS_QUA_INC
      parameter(SYS_QUA_INC=30)
      integer SYS_QUA_REL
      parameter(SYS_QUA_REL=31)
      integer SYS_QUA_ABS
      parameter(SYS_QUA_ABS=32)
      integer SYS_QUA_EQUIV
      parameter(SYS_QUA_EQUIV=33)
      integer SYS_QUA_PLAST
      parameter(SYS_QUA_PLAST=34)
      integer SYS_QUA_CREEP
      parameter(SYS_QUA_CREEP=35)
      integer SYS_QUA_THERMAL
      parameter(SYS_QUA_THERMAL=36)
      integer SYS_QUA_ELAST
      parameter(SYS_QUA_ELAST=37)
      integer SYS_QUA_INELAST
      parameter(SYS_QUA_INELAST=38)
      integer SYS_QUA_REYNOLDS
      parameter(SYS_QUA_REYNOLDS=39)
      integer SYS_QUA_STAG
      parameter(SYS_QUA_STAG=40)
      integer SYS_QUA_CAUCHY
      parameter(SYS_QUA_CAUCHY=41)
      integer SYS_QUA_PK
      parameter(SYS_QUA_PK=42)
      integer SYS_QUA_LOG
      parameter(SYS_QUA_LOG=43)
      integer SYS_QUA_TRESCA
      parameter(SYS_QUA_TRESCA=44)
      integer SYS_QUA_YIELD
      parameter(SYS_QUA_YIELD=45)
      integer SYS_QUA_MEAN
      parameter(SYS_QUA_MEAN=46)
      integer SYS_QUA_NONLIN
      parameter(SYS_QUA_NONLIN=47)
      integer SYS_QUA_TORSION
      parameter(SYS_QUA_TORSION=48)
      integer SYS_QUA_SWELLING
      parameter(SYS_QUA_SWELLING=49)
      integer SYS_QUA_CRACKING
      parameter(SYS_QUA_CRACKING=50)
      integer SYS_QUA_NORMAL
      parameter(SYS_QUA_NORMAL=51)
      integer SYS_QUA_SHEAR
      parameter(SYS_QUA_SHEAR=52)
      integer SYS_QUA_PSD
      parameter(SYS_QUA_PSD=53)
      integer SYS_QUA_RMS
      parameter(SYS_QUA_RMS=54)
      integer SYS_QUA_NOM
      parameter(SYS_QUA_NOM=55)
      integer SYS_QUA_COMPONENT
      parameter(SYS_QUA_COMPONENT=56)
      integer SYS_QUA_INTERLAMINAR
      parameter(SYS_QUA_INTERLAMINAR=57)
      integer SYS_QUA_PLY
      parameter(SYS_QUA_PLY=58)
      integer SYS_QUA_BOND
      parameter(SYS_QUA_BOND=59)
      integer SYS_QUA_CONSTRAINT
      parameter(SYS_QUA_CONSTRAINT=60)
      integer SYS_QUA_PORE
      parameter(SYS_QUA_PORE=61)
      integer SYS_QUA_GASKET
      parameter(SYS_QUA_GASKET=62)
      integer SYS_QUA_CONTACT
      parameter(SYS_QUA_CONTACT=63)
      integer SYS_QUA_INITIAL
      parameter(SYS_QUA_INITIAL=64)
      integer SYS_QUA_FINAL
      parameter(SYS_QUA_FINAL=65)
      integer SYS_QUA_TENS
      parameter(SYS_QUA_TENS=66)
      integer SYS_QUA_COMP
      parameter(SYS_QUA_COMP=67)
      integer SYS_QUA_INFRARED
      parameter(SYS_QUA_INFRARED=68)
      integer SYS_QUA_DIFFUSE
      parameter(SYS_QUA_DIFFUSE=69)
      integer SYS_QUA_COLLIMATED
      parameter(SYS_QUA_COLLIMATED=70)
      integer SYS_QUA_SOLAR
      parameter(SYS_QUA_SOLAR=71)
      integer SYS_QUA_SOUND
      parameter(SYS_QUA_SOUND=72)
      integer SYS_QUA_RADIATIVE
      parameter(SYS_QUA_RADIATIVE=73)
      integer SYS_QUA_CONDUCTIVE
      parameter(SYS_QUA_CONDUCTIVE=74)
      integer SYS_QUA_CONVECTIVE
      parameter(SYS_QUA_CONVECTIVE=75)
      integer SYS_QUA_RESIDUAL
      parameter(SYS_QUA_RESIDUAL=76)
      integer SYS_QUA_ADJUSTED
      parameter(SYS_QUA_ADJUSTED=77)
      integer SYS_QUA_PSIDE
      parameter(SYS_QUA_PSIDE=78)
      integer SYS_QUA_MSIDE
      parameter(SYS_QUA_MSIDE=79)
      integer SYS_QUA_LOCAL
      parameter(SYS_QUA_LOCAL=80)
      integer SYS_QUA_INTERNAL
      parameter(SYS_QUA_INTERNAL=81)
      integer SYS_QUA_BULK
      parameter(SYS_QUA_BULK=82)
      integer SYS_QUA_STATIC
      parameter(SYS_QUA_STATIC=83)
      integer SYS_QUA_DYNAMIC
      parameter(SYS_QUA_DYNAMIC=84)
      integer SYS_QUA_SLIP
      parameter(SYS_QUA_SLIP=85)
      integer SYS_QUA_FREE
      parameter(SYS_QUA_FREE=86)
      integer SYS_QUA_FORCED
      parameter(SYS_QUA_FORCED=87)
      integer SYS_QUA_FLUID
      parameter(SYS_QUA_FLUID=88)
      integer SYS_QUA_HARMONIC
      parameter(SYS_QUA_HARMONIC=89)
      integer SYS_QUA_LORENTZ
      parameter(SYS_QUA_LORENTZ=90)
      integer SYS_QUA_BEARING
      parameter(SYS_QUA_BEARING=91)
      integer SYS_QUA_RADIAL
      parameter(SYS_QUA_RADIAL=92)
      integer SYS_QUA_TANG
      parameter(SYS_QUA_TANG=93)
      integer SYS_QUA_AXIAL
      parameter(SYS_QUA_AXIAL=94)
      integer SYS_QUA_GREEN
      parameter(SYS_QUA_GREEN=95)
      integer SYS_QUA_MEANPRES
      parameter(SYS_QUA_MEANPRES=96)
      integer SYS_QUA_DEFORM
      parameter(SYS_QUA_DEFORM=97)
      integer SYS_QUA_GPF
      parameter(SYS_QUA_GPF=98)
      integer SYS_QUA_VISC
      parameter(SYS_QUA_VISC=99)
      integer SYS_QUA_GLUE
      parameter(SYS_QUA_GLUE=100)
      integer SYS_QUA_FRICTION
      parameter(SYS_QUA_FRICTION=101)
      integer SYS_QUA_SCALAR
      parameter(SYS_QUA_SCALAR=102)
      integer SYS_QUA_PRINCIPAL
      parameter(SYS_QUA_PRINCIPAL=103)
      integer SYS_QUA_NOZ
      parameter(SYS_QUA_NOZ=104)
      integer SYS_QUA_ATO
      parameter(SYS_QUA_ATO=105)
      integer SYS_QUA_CRM
      parameter(SYS_QUA_CRM=106)
      integer SYS_QUA_SOURCE
      parameter(SYS_QUA_SOURCE=107)
      integer SYS_QUA_SUM
      parameter(SYS_QUA_SUM=108)
      integer SYS_QUA_NET
      parameter(SYS_QUA_NET=109)
      integer SYS_QUA_ACOUSTIC
      parameter(SYS_QUA_ACOUSTIC=110)
      integer SYS_QUA_RADIOSITY
      parameter(SYS_QUA_RADIOSITY=111)
      integer SYS_QUA_IRRADIANCE
      parameter(SYS_QUA_IRRADIANCE=112)
      integer SYS_QUA_TRANSMITTED
      parameter(SYS_QUA_TRANSMITTED=113)
      integer SYS_QUA_REFLECTED
      parameter(SYS_QUA_REFLECTED=114)
      integer SYS_QUA_INCIDENT
      parameter(SYS_QUA_INCIDENT=115)
      integer SYS_QUA_ABSORBED
      parameter(SYS_QUA_ABSORBED=116)
      integer SYS_QUA_SOLID
      parameter(SYS_QUA_SOLID=117)
      integer SYS_QUA_DISSIPATED
      parameter(SYS_QUA_DISSIPATED=118)
      integer SYS_QUA_OPT
      parameter(SYS_QUA_OPT=119)
      integer SYS_QUA_CONC
      parameter(SYS_QUA_CONC=120)
      integer SYS_QUA_DIST
      parameter(SYS_QUA_DIST=121)
      integer SYS_QUA_ATTACHMENT
      parameter(SYS_QUA_ATTACHMENT=122)
      integer SYS_QUA_INERTIA
      parameter(SYS_QUA_INERTIA=123)
      integer SYS_QUA_REDUCED
      parameter(SYS_QUA_REDUCED=124)
      integer SYS_QUA_MODAL
      parameter(SYS_QUA_MODAL=125)
      integer SYS_QUA_PARTICLE
      parameter(SYS_QUA_PARTICLE=126)
      integer SYS_QUA_NEIGHBORS
      parameter(SYS_QUA_NEIGHBORS=127)
      integer SYS_QUA_SHELL
      parameter(SYS_QUA_SHELL=128)
      integer SYS_QUA_ERROR
      parameter(SYS_QUA_ERROR=129)
      integer SYS_QUA_NORM
      parameter(SYS_QUA_NORM=130)
      integer SYS_QUA_EIP
      parameter(SYS_QUA_EIP=131)
      integer SYS_QUA_PANEL
      parameter(SYS_QUA_PANEL=132)
      integer SYS_QUA_LCR
      parameter(SYS_QUA_LCR=133)
      integer SYS_QUA_PEAK
      parameter(SYS_QUA_PEAK=134)
      integer SYS_QUA_DIFFERENCE
      parameter(SYS_QUA_DIFFERENCE=135)
      integer SYS_QUA_CYCLIC
      parameter(SYS_QUA_CYCLIC=136)
      integer SYS_QUA_SIN
      parameter(SYS_QUA_SIN=137)
      integer SYS_QUA_COS
      parameter(SYS_QUA_COS=138)
      integer SYS_QUA_MPC
      parameter(SYS_QUA_MPC=139)
      integer SYS_QUA_TURB
      parameter(SYS_QUA_TURB=140)
      integer SYS_QUA_SYM
      parameter(SYS_QUA_SYM=141)
      integer SYS_QUA_ASYM
      parameter(SYS_QUA_ASYM=142)
      integer SYS_QUA_DAMAGE
      parameter(SYS_QUA_DAMAGE=143)
      integer SYS_QUA_COHESIVE
      parameter(SYS_QUA_COHESIVE=144)
      integer SYS_QUA_BOLT
      parameter(SYS_QUA_BOLT=145)
      integer SYS_QUA_CHOCKING
      parameter(SYS_QUA_CHOCKING=146)
      integer SYS_QUA_MECH
      parameter(SYS_QUA_MECH=147)
      integer SYS_QUA_ENTHALPY
      parameter(SYS_QUA_ENTHALPY=148)
      integer SYS_QUA_FLAME
      parameter(SYS_QUA_FLAME=149)
      integer SYS_QUA_GLASSTRANS
      parameter(SYS_QUA_GLASSTRANS=150)
      integer SYS_QUA_EMITTED
      parameter(SYS_QUA_EMITTED=151)
      integer SYS_QUA_COUPLED
      parameter(SYS_QUA_COUPLED=152)
      integer SYS_QUA_UNCOUPLED
      parameter(SYS_QUA_UNCOUPLED=153)
      integer SYS_QUA_STRUCT
      parameter(SYS_QUA_STRUCT=154)
      integer SYS_QUA_TRANSPORT
      parameter(SYS_QUA_TRANSPORT=155)
      integer SYS_QUA_WELD
      parameter(SYS_QUA_WELD=156)
      integer SYS_QUA_KIRCH
      parameter(SYS_QUA_KIRCH=157)
      integer SYS_QUA_NORMALIZED
      parameter(SYS_QUA_NORMALIZED=158)
      integer SYS_QUA_APPLIED
      parameter(SYS_QUA_APPLIED=159)
      integer SYS_QUA_GYROSCOPIC
      parameter(SYS_QUA_GYROSCOPIC=160)
      integer SYS_QUA_DAMPING
      parameter(SYS_QUA_DAMPING=161)
      integer SYS_QUA_CIRCULATORY_FORCES
      parameter(SYS_QUA_CIRCULATORY_FORCES=162)
      integer SYS_QUA_TSAI_HILL
      parameter(SYS_QUA_TSAI_HILL=163)
      integer SYS_QUA_TSAI_WU
      parameter(SYS_QUA_TSAI_WU=164)
      integer SYS_QUA_HASHIN
      parameter(SYS_QUA_HASHIN=165)
      integer SYS_QUA_STRESS
      parameter(SYS_QUA_STRESS=166)
      integer SYS_QUA_STRAIN
      parameter(SYS_QUA_STRAIN=167)
      integer SYS_QUA_RICE_TRACEY
      parameter(SYS_QUA_RICE_TRACEY=168)
      integer SYS_QUA_HOFFMAN
      parameter(SYS_QUA_HOFFMAN=169)
      integer SYS_QUA_PUCK
      parameter(SYS_QUA_PUCK=170)
      integer SYS_QUA_LARC04
      parameter(SYS_QUA_LARC04=171)
      integer SYS_QUA_TRACTION
      parameter(SYS_QUA_TRACTION=172)
      integer SYS_QUA_PLANE_STRESS
      parameter(SYS_QUA_PLANE_STRESS=173)
      integer SYS_QUA_FIBER
      parameter(SYS_QUA_FIBER=174)
      integer SYS_QUA_MATRIX
      parameter(SYS_QUA_MATRIX=175)
      integer SYS_QUA_RATIO
      parameter(SYS_QUA_RATIO=176)
      integer SYS_QUA_VARIANT
      parameter(SYS_QUA_VARIANT=177)
      integer SYS_QUA_CRITICAL
      parameter(SYS_QUA_CRITICAL=178)
      integer SYS_QUA_FULL
      parameter(SYS_QUA_FULL=179)
      integer SYS_QUA_MATERIAL
      parameter(SYS_QUA_MATERIAL=180)
      integer SYS_QUA_AWEIGHT
      parameter(SYS_QUA_AWEIGHT=181)
      integer SYS_QUA_INACTIVE
      parameter(SYS_QUA_INACTIVE=182)
      integer SYS_QUA_OVERHEATING
      parameter(SYS_QUA_OVERHEATING=183)
      integer SYS_QUA_UNCONVERGED
      parameter(SYS_QUA_UNCONVERGED=184)
      integer SYS_QUA_VOLUME
      parameter(SYS_QUA_VOLUME=185)
      integer SYS_QUA_VIBE
      parameter(SYS_QUA_VIBE=186)
      integer SYS_QUA_PENETRATION
      parameter(SYS_QUA_PENETRATION=187)
      integer SYS_QUA_BIOT
      parameter(SYS_QUA_BIOT=188)
      integer SYS_QUA_ENG
      parameter(SYS_QUA_ENG=189)
      integer SYS_QUA_CG
      parameter(SYS_QUA_CG=190)
      integer SYS_QUA_PARTICIPATION
      parameter(SYS_QUA_PARTICIPATION=191)
      integer SYS_QUA_AERO
      parameter(SYS_QUA_AERO=192)
      integer SYS_QUA_MASS
      parameter(SYS_QUA_MASS=193)
      integer SYS_QUA_RIGID
      parameter(SYS_QUA_RIGID=194)
      integer SYS_QUA_UNIT
      parameter(SYS_QUA_UNIT=195)
      integer SYS_QUA_RESTRAINED
      parameter(SYS_QUA_RESTRAINED=196)
      integer SYS_QUA_UNRESTRAINED
      parameter(SYS_QUA_UNRESTRAINED=197)
      integer SYS_QUA_HOMOGENIZED
      parameter(SYS_QUA_HOMOGENIZED=198)
      integer SYS_QUA_SHEARPANEL
      parameter(SYS_QUA_SHEARPANEL=199)
      integer SYS_QUA_BENDING
      parameter(SYS_QUA_BENDING=200)
      integer SYS_QUA_BODY
      parameter(SYS_QUA_BODY=201)
      integer SYS_QUA_SPC
      parameter(SYS_QUA_SPC=202)
      integer SYS_QUA_ROTATIONAL
      parameter(SYS_QUA_ROTATIONAL=203)
      integer SYS_QUA_MAX
      parameter(SYS_QUA_MAX=204)
      integer SYS_QUAVAL_NONE
      parameter(SYS_QUAVAL_NONE=-1)
      integer SYS_QUAVAL_PHASE
      parameter(SYS_QUAVAL_PHASE=0)
      integer SYS_QUAVAL_HARMONIC
      parameter(SYS_QUAVAL_HARMONIC=1)
      integer SYS_QUAVAL_ROTORSPEED
      parameter(SYS_QUAVAL_ROTORSPEED=2)
      integer SYS_QUAVAL_NODE
      parameter(SYS_QUAVAL_NODE=3)
      integer SYS_QUAVAL_MATERIAL
      parameter(SYS_QUAVAL_MATERIAL=4)
      integer SYS_QUAVAL_SET
      parameter(SYS_QUAVAL_SET=5)
      integer SYS_QUAVAL_DESIGNCYCLE
      parameter(SYS_QUAVAL_DESIGNCYCLE=6)
      integer SYS_QUAVAL_SECTION
      parameter(SYS_QUAVAL_SECTION=7)
      integer SYS_QUAVAL_INTPNT
      parameter(SYS_QUAVAL_INTPNT=8)
      integer SYS_QUAVAL_CONTACTPAIR
      parameter(SYS_QUAVAL_CONTACTPAIR=9)
      integer SYS_QUAVAL_SPECIES
      parameter(SYS_QUAVAL_SPECIES=10)
      integer SYS_QUAVAL_BOLTSEQUENCE
      parameter(SYS_QUAVAL_BOLTSEQUENCE=11)
      integer SYS_QUAVAL_STEP
      parameter(SYS_QUAVAL_STEP=12)
      integer SYS_QUAVAL_COUNT
      parameter(SYS_QUAVAL_COUNT=13)
      integer SYS_QUAVAL_MAX
      parameter(SYS_QUAVAL_MAX=14)
      integer SYS_NQUA_MAX
      parameter(SYS_NQUA_MAX=4)
      integer SYS_APPROX_NONE
      parameter(SYS_APPROX_NONE=0)
      integer SYS_APPROX_LINEAR
      parameter(SYS_APPROX_LINEAR=1)
      integer SYS_APPROX_QUADRATIC
      parameter(SYS_APPROX_QUADRATIC=2)
      integer SYS_APPROX_CUBIC
      parameter(SYS_APPROX_CUBIC=3)
      integer SYS_PHASE_MASS
      parameter(SYS_PHASE_MASS=1)
      integer SYS_PHASE_SYMFACTOR
      parameter(SYS_PHASE_SYMFACTOR=2)
      integer SYS_PHASE_INITCOND
      parameter(SYS_PHASE_INITCOND=3)
      integer SYS_PHASE_PREDICTOR
      parameter(SYS_PHASE_PREDICTOR=4)
      integer SYS_PHASE_STIFF
      parameter(SYS_PHASE_STIFF=5)
      integer SYS_PHASE_FACTOR
      parameter(SYS_PHASE_FACTOR=6)
      integer SYS_PHASE_UPDATE
      parameter(SYS_PHASE_UPDATE=7)
      integer SYS_PHASE_REACT
      parameter(SYS_PHASE_REACT=8)
      integer SYS_PHASE_REACTSTIFF
      parameter(SYS_PHASE_REACTSTIFF=9)
      integer SYS_PHASE_SOLVE
      parameter(SYS_PHASE_SOLVE=10)
      integer SYS_PHASE_GEOMSTIFF
      parameter(SYS_PHASE_GEOMSTIFF=11)
      integer SYS_PHASE_BUCKLING
      parameter(SYS_PHASE_BUCKLING=12)
      integer SYS_PHASE_VIBRATION
      parameter(SYS_PHASE_VIBRATION=13)
      integer SYS_PHASE_OUTPUT
      parameter(SYS_PHASE_OUTPUT=14)
      integer SYS_PHASE_STATICMODES
      parameter(SYS_PHASE_STATICMODES=15)
      integer SYS_PHASE_DOFTAB
      parameter(SYS_PHASE_DOFTAB=16)
      integer SYS_PHASE_INITIALIZATION
      parameter(SYS_PHASE_INITIALIZATION=17)
      integer SYS_PHASE_BEGINCASE
      parameter(SYS_PHASE_BEGINCASE=18)
      integer SYS_PHASE_ENDCASE
      parameter(SYS_PHASE_ENDCASE=19)
      integer VSY_DICTIONARY
      parameter(VSY_DICTIONARY=1010)
      integer VSY_HASHTABLE
      parameter(VSY_HASHTABLE=1020)
      integer VSY_LIST
      parameter(VSY_LIST=1030)
      integer VSY_STACK
      parameter(VSY_STACK=1040)
      integer VSY_BITVEC
      parameter(VSY_BITVEC=1050)
      integer VSY_PROPSET
      parameter(VSY_PROPSET=1060)
      integer VSY_RANDOM
      parameter(VSY_RANDOM=1070)
      integer VSY_TEXTFUN
      parameter(VSY_TEXTFUN=1080)
      integer VSY_TEXTFUN_0
      parameter(VSY_TEXTFUN_0=1080)
      integer VSY_TEXTFUN_1
      parameter(VSY_TEXTFUN_1=1081)
      integer VSY_TEXTFUN_2
      parameter(VSY_TEXTFUN_2=1082)
      integer VSY_TEXTFUN_3
      parameter(VSY_TEXTFUN_3=1083)
      integer VSY_TEXTFUN_4
      parameter(VSY_TEXTFUN_4=1084)
      integer VSY_TEXTFUN_5
      parameter(VSY_TEXTFUN_5=1085)
      integer VSY_TEXTFUN_6
      parameter(VSY_TEXTFUN_6=1086)
      integer VSY_TEXTFUN_7
      parameter(VSY_TEXTFUN_7=1087)
      integer VSY_TEXTFUN_TEE
      parameter(VSY_TEXTFUN_TEE=1087)
      integer VSY_HTMLTEXT
      parameter(VSY_HTMLTEXT=1100)
      integer VSY_PLAINTEXT
      parameter(VSY_PLAINTEXT=1110)
      integer VSY_CONCAT
      parameter(VSY_CONCAT=1120)
      integer VSY_DATATABLE
      parameter(VSY_DATATABLE=1130)
      integer VSY_PQUEUE
      parameter(VSY_PQUEUE=1140)
      integer VSY_TRICON
      parameter(VSY_TRICON=1150)
      integer VSY_VERTLOC
      parameter(VSY_VERTLOC=1160)
      integer VSY_LINECON
      parameter(VSY_LINECON=1170)
      integer VSY_INTVEC
      parameter(VSY_INTVEC=1180)
      integer VSY_TIMER
      parameter(VSY_TIMER=1190)
      integer VSY_PTASK
      parameter(VSY_PTASK=1200)
      integer VSY_TEXTTEE
      parameter(VSY_TEXTTEE=1210)
      integer VSY_LATEXTEXT
      parameter(VSY_LATEXTEXT=1220)
      integer VSY_FILETEXT
      parameter(VSY_FILETEXT=1230)
      integer VSY_LINKLIST
      parameter(VSY_LINKLIST=1240)
      integer VSY_ADTREE
      parameter(VSY_ADTREE=1250)
      integer VSY_DBLVEC
      parameter(VSY_DBLVEC=1260)
      integer VSY_INTHASH
      parameter(VSY_INTHASH=1270)
      integer VSY_INTDICT
      parameter(VSY_INTDICT=1280)
      integer VSY_CALC
      parameter(VSY_CALC=1290)
      integer VSY_PROGRESS
      parameter(VSY_PROGRESS=1300)
      integer VSY_INTSTACK
      parameter(VSY_INTSTACK=1310)
      integer VSY_REGEXP
      parameter(VSY_REGEXP=1320)
      integer VSY_ECHO
      parameter(VSY_ECHO=1330)
      integer VSY_FLTVEC
      parameter(VSY_FLTVEC=1340)
      integer VSY_INTQUE
      parameter(VSY_INTQUE=1350)
      integer VSY_HEAP
      parameter(VSY_HEAP=1360)
      integer VSY_HEAPIND
      parameter(VSY_HEAPIND=1370)
      integer VSY_REDPRE
      parameter(VSY_REDPRE=1380)
      integer VSY_INTVHASH
      parameter(VSY_INTVHASH=1390)
      integer VSY_TREE
      parameter(VSY_TREE=1400)
      integer VSY_PRED
      parameter(VSY_PRED=1410)
      integer VSY_MPC
      parameter(VSY_MPC=1411)
      integer VSY_ZMEM
      parameter(VSY_ZMEM=1430)
      integer VSY_VHASHTABLE
      parameter(VSY_VHASHTABLE=1440)
      integer VSY_CVECT
      parameter(VSY_CVECT=1490)
      integer VSY_INCLUDEZERO
      parameter(VSY_INCLUDEZERO=1)
      integer SYS_CHAR_UNDEFINED
      parameter(SYS_CHAR_UNDEFINED=1)
      integer SYS_SCHAR_UNDEFINED
      parameter(SYS_SCHAR_UNDEFINED=1)
      integer SYS_UCHAR_UNDEFINED
      parameter(SYS_UCHAR_UNDEFINED=1)
      integer SYS_SHORT_UNDEFINED
      parameter(SYS_SHORT_UNDEFINED=1)
      integer SYS_USHORT_UNDEFINED
      parameter(SYS_USHORT_UNDEFINED=1)
      integer SYS_INT_UNDEFINED
      parameter(SYS_INT_UNDEFINED=1)
      integer SYS_LONG_UNDEFINED
      parameter(SYS_LONG_UNDEFINED=1)
      integer SYS_ULONG_UNDEFINED
      parameter(SYS_ULONG_UNDEFINED=1)
      integer SYS_WORD_UNDEFINED
      parameter(SYS_WORD_UNDEFINED=1)
      integer SYS_FLOAT_UNDEFINED
      parameter(SYS_FLOAT_UNDEFINED=1)
      integer SYS_DOUBLE_UNDEFINED
      parameter(SYS_DOUBLE_UNDEFINED=1)
      integer SYS_UINT_UNDEFINED
      parameter(SYS_UINT_UNDEFINED=1)
      integer SYS_TCHAR_UNDEFINED
      parameter(SYS_TCHAR_UNDEFINED=1)
      integer SYS_WCHAR_T_UNDEFINED
      parameter(SYS_WCHAR_T_UNDEFINED=1)
      integer SYS_MAX_DEGREES_OF_FREEDOM
      parameter(SYS_MAX_DEGREES_OF_FREEDOM=6)
      integer BITVEC_SET
      parameter(BITVEC_SET=1)
      integer BITVEC_AND
      parameter(BITVEC_AND=2)
      integer BITVEC_OR
      parameter(BITVEC_OR=3)
      integer BITVEC_XOR
      parameter(BITVEC_XOR=4)
      integer SYS_BUILD_OPTION_BLASMKL_SEQUENTIAL
      parameter(SYS_BUILD_OPTION_BLASMKL_SEQUENTIAL=1)
      integer SYS_BUILD_OPTION_BLASMKL_THREAD
      parameter(SYS_BUILD_OPTION_BLASMKL_THREAD=2)
      integer SYS_BUILD_OPTION_BLASMKL
      parameter(SYS_BUILD_OPTION_BLASMKL=3)
      integer SYS_BUILD_OPTION_ADDRESS_SANITIZER
      parameter(SYS_BUILD_OPTION_ADDRESS_SANITIZER=4)
      integer SYS_BUILD_OPTION_THREAD_SANITIZER
      parameter(SYS_BUILD_OPTION_THREAD_SANITIZER=5)
      integer SYS_BUILD_OPTION_FREETYPE
      parameter(SYS_BUILD_OPTION_FREETYPE=6)
      integer SYS_BUILD_OPTION_METIS
      parameter(SYS_BUILD_OPTION_METIS=7)
      integer SYS_BUILD_OPTION_BLOSC
      parameter(SYS_BUILD_OPTION_BLOSC=8)
      integer SYS_BUILD_OPTION_FFMPEG
      parameter(SYS_BUILD_OPTION_FFMPEG=9)
      integer SYS_BUILD_OPTION_64BITS
      parameter(SYS_BUILD_OPTION_64BITS=10)
      integer SYS_BUILD_OPTION_MUMPS
      parameter(SYS_BUILD_OPTION_MUMPS=11)
      integer SYS_BUILD_OPTION_HOOPS_EXCHANGE
      parameter(SYS_BUILD_OPTION_HOOPS_EXCHANGE=12)
      integer SYS_BUILD_OPTION_MAX
      parameter(SYS_BUILD_OPTION_MAX=13)
      integer CALC_INFIX
      parameter(CALC_INFIX=1)
      integer CALC_POSTFIX
      parameter(CALC_POSTFIX=2)
      integer CALC_LPAREN
      parameter(CALC_LPAREN=1)
      integer CALC_RPAREN
      parameter(CALC_RPAREN=2)
      integer CALC_PLUS
      parameter(CALC_PLUS=3)
      integer CALC_MINUS
      parameter(CALC_MINUS=4)
      integer CALC_ADD
      parameter(CALC_ADD=5)
      integer CALC_SUB
      parameter(CALC_SUB=6)
      integer CALC_DIV
      parameter(CALC_DIV=7)
      integer CALC_MUL
      parameter(CALC_MUL=8)
      integer CALC_POWER
      parameter(CALC_POWER=9)
      integer CALC_INTEGER
      parameter(CALC_INTEGER=10)
      integer CALC_REAL
      parameter(CALC_REAL=11)
      integer CALC_STRING
      parameter(CALC_STRING=12)
      integer CALC_ABS
      parameter(CALC_ABS=13)
      integer CALC_ACOS
      parameter(CALC_ACOS=14)
      integer CALC_ASIN
      parameter(CALC_ASIN=15)
      integer CALC_ATAN
      parameter(CALC_ATAN=16)
      integer CALC_COS
      parameter(CALC_COS=17)
      integer CALC_LOG
      parameter(CALC_LOG=18)
      integer CALC_LOG10
      parameter(CALC_LOG10=19)
      integer CALC_POW
      parameter(CALC_POW=20)
      integer CALC_SIN
      parameter(CALC_SIN=21)
      integer CALC_SQRT
      parameter(CALC_SQRT=22)
      integer CALC_TAN
      parameter(CALC_TAN=23)
      integer CALC_INT
      parameter(CALC_INT=24)
      integer CALC_FLOAT
      parameter(CALC_FLOAT=25)
      integer CALC_STR
      parameter(CALC_STR=26)
      integer CALC_MAX_TYPE
      parameter(CALC_MAX_TYPE=27)
      integer CALC_PARSEERROR
      parameter(CALC_PARSEERROR=1)
      integer CALC_UNMATCHEDPAREN
      parameter(CALC_UNMATCHEDPAREN=1)
      integer CALC_INSUFFICIENTOPERANDS
      parameter(CALC_INSUFFICIENTOPERANDS=2)
      integer CALC_ILLEGALOPERAND
      parameter(CALC_ILLEGALOPERAND=3)
      integer CALC_MAX_TOKENS
      parameter(CALC_MAX_TOKENS=100)
      integer CONCAT_ITER
      parameter(CONCAT_ITER=1)
      integer CVECT_NUM
      parameter(CVECT_NUM=4)
      integer DATATABLE_INTERPOLATE
      parameter(DATATABLE_INTERPOLATE=1)
      integer DATATABLE_EXTRAPOLATE
      parameter(DATATABLE_EXTRAPOLATE=2)
      integer DATATABLE_CLAMP
      parameter(DATATABLE_CLAMP=1)
      integer DATATABLE_LINEAR
      parameter(DATATABLE_LINEAR=2)
      integer DATATABLE_PARABOLIC_SLOPE
      parameter(DATATABLE_PARABOLIC_SLOPE=3)
      integer DOUBLE_DICTIONARY_MIN_STORAGE
      parameter(DOUBLE_DICTIONARY_MIN_STORAGE=128)
      integer DICTIONARY_IGNORECASE
      parameter(DICTIONARY_IGNORECASE=2)
      integer DICTIONARY_MIN_STORAGE
      parameter(DICTIONARY_MIN_STORAGE=128)
      integer ECHO_WRITE
      parameter(ECHO_WRITE=1)
      integer ECHO_READ
      parameter(ECHO_READ=2)
      integer ECHO_MAX_ARGS
      parameter(ECHO_MAX_ARGS=5)
      integer HEAP_MIN
      parameter(HEAP_MIN=0)
      integer HEAP_MAX
      parameter(HEAP_MAX=1)
      integer INTEGER_DICTIONARY_MIN_STORAGE
      parameter(INTEGER_DICTIONARY_MIN_STORAGE=128)
      integer INTHASH_UNDEFINED
      parameter(INTHASH_UNDEFINED=1)
      integer INTVHASH_EMPTY_SLOT
      parameter(INTVHASH_EMPTY_SLOT=0)
      integer INTVHASH_TRASH_SLOT
      parameter(INTVHASH_TRASH_SLOT=0)
      integer INTVHASH_MIN_TABLE_SIZE
      parameter(INTVHASH_MIN_TABLE_SIZE=5)
      integer INTVHASH_HASH_FUNCTION_LEGACY
      parameter(INTVHASH_HASH_FUNCTION_LEGACY=0)
      integer INTVHASH_HASH_FUNCTION_FNV1A
      parameter(INTVHASH_HASH_FUNCTION_FNV1A=1)
      integer LINECON_MAXLENGTH
      parameter(LINECON_MAXLENGTH=1)
      integer NAME_COLOR
      parameter(NAME_COLOR=0)
      integer NAME_POSITION
      parameter(NAME_POSITION=1)
      integer NAME_ONOFF
      parameter(NAME_ONOFF=2)
      integer NAME_AXIS
      parameter(NAME_AXIS=3)
      integer NAME_LINESTYLE
      parameter(NAME_LINESTYLE=4)
      integer NAME_OBJECT
      parameter(NAME_OBJECT=5)
      integer NAME_MARKER
      parameter(NAME_MARKER=6)
      integer NAME_FORMAT
      parameter(NAME_FORMAT=7)
      integer NAME_SCALE
      parameter(NAME_SCALE=8)
      integer NAME_DIRECTION
      parameter(NAME_DIRECTION=9)
      integer NAME_CURSOR
      parameter(NAME_CURSOR=10)
      integer NAME_ELEM
      parameter(NAME_ELEM=11)
      integer NAME_TRANSPARENCY
      parameter(NAME_TRANSPARENCY=12)
      integer NAME_ELEMSHAPE
      parameter(NAME_ELEMSHAPE=13)
      integer NAME_LINEWIDTH
      parameter(NAME_LINEWIDTH=14)
      integer NAME_POINTSIZE
      parameter(NAME_POINTSIZE=15)
      integer NAME_ON
      parameter(NAME_ON=16)
      integer NAME_OFF
      parameter(NAME_OFF=17)
      integer NAME_ELEMTYPE
      parameter(NAME_ELEMTYPE=18)
      integer NAME_DOF
      parameter(NAME_DOF=19)
      integer NAME_VERSION
      parameter(NAME_VERSION=20)
      integer NAME_YESNO
      parameter(NAME_YESNO=21)
      integer NAME_ELEM_SOLID
      parameter(NAME_ELEM_SOLID=22)
      integer NAME_ELEM_INTER
      parameter(NAME_ELEM_INTER=23)
      integer NAME_ASSOC
      parameter(NAME_ASSOC=24)
      integer NAME_OBJECT4
      parameter(NAME_OBJECT4=25)
      integer PLAINTEXT_BORDEREQUALS
      parameter(PLAINTEXT_BORDEREQUALS=1)
      integer PROGRESS_RATE
      parameter(PROGRESS_RATE=1)
      integer PROGRESS_RATE_NORMAL
      parameter(PROGRESS_RATE_NORMAL=1)
      integer PROGRESS_RATE_ACCELERATED
      parameter(PROGRESS_RATE_ACCELERATED=2)
      integer PROGRESS_RATE_STALLED
      parameter(PROGRESS_RATE_STALLED=3)
      integer PTASK_SERIALMODE
      parameter(PTASK_SERIALMODE=1)
      integer PTASK_EXEC
      parameter(PTASK_EXEC=1)
      integer PTASK_START
      parameter(PTASK_START=2)
      integer PREC_MANTISSA
      parameter(PREC_MANTISSA=1)
      integer REGEXP_MAXDFA
      parameter(REGEXP_MAXDFA=1024)
      integer REGEXP_MAXTAG
      parameter(REGEXP_MAXTAG=10)
      integer REGEXP_MAXCHR
      parameter(REGEXP_MAXCHR=128)
      integer REGEXP_CHRBIT
      parameter(REGEXP_CHRBIT=8)
      integer REGEXP_SQUAREBRACKET
      parameter(REGEXP_SQUAREBRACKET=1)
      integer REGEXP_POSIX
      parameter(REGEXP_POSIX=3)
      integer TEXTFUN_UNDEFINED
      parameter(TEXTFUN_UNDEFINED=-1)
      integer TEXTFUN_OPENFILE
      parameter(TEXTFUN_OPENFILE=1)
      integer TEXTFUN_CLOSEFILE
      parameter(TEXTFUN_CLOSEFILE=2)
      integer TEXTFUN_LISTTYPE
      parameter(TEXTFUN_LISTTYPE=3)
      integer TEXTFUN_HEADINGLEVEL
      parameter(TEXTFUN_HEADINGLEVEL=4)
      integer TEXTFUN_RULEWIDTH
      parameter(TEXTFUN_RULEWIDTH=5)
      integer TEXTFUN_SETMODE
      parameter(TEXTFUN_SETMODE=6)
      integer TEXTFUN_FORMINIT
      parameter(TEXTFUN_FORMINIT=7)
      integer TEXTFUN_FORMTERM
      parameter(TEXTFUN_FORMTERM=8)
      integer TEXTFUN_FORMACTION
      parameter(TEXTFUN_FORMACTION=9)
      integer TEXTFUN_HORIZONTALRULE
      parameter(TEXTFUN_HORIZONTALRULE=10)
      integer TEXTFUN_IMAGEFILE
      parameter(TEXTFUN_IMAGEFILE=11)
      integer TEXTFUN_STRING
      parameter(TEXTFUN_STRING=12)
      integer TEXTFUN_CONNECTFILE
      parameter(TEXTFUN_CONNECTFILE=13)
      integer TEXTFUN_DISCONNECTFILE
      parameter(TEXTFUN_DISCONNECTFILE=14)
      integer TEXTFUN_QUERYFILE
      parameter(TEXTFUN_QUERYFILE=15)
      integer TEXTFUN_COLUMNALIGN
      parameter(TEXTFUN_COLUMNALIGN=16)
      integer TEXTFUN_SPACE
      parameter(TEXTFUN_SPACE=17)
      integer TEXTFUN_TEXTCOLOR
      parameter(TEXTFUN_TEXTCOLOR=18)
      integer TEXTFUN_TABLECOLOR
      parameter(TEXTFUN_TABLECOLOR=19)
      integer TEXTFUN_BACKCOLOR
      parameter(TEXTFUN_BACKCOLOR=20)
      integer TEXTFUN_BORDERWIDTH
      parameter(TEXTFUN_BORDERWIDTH=21)
      integer TEXTFUN_TABLEWIDTH
      parameter(TEXTFUN_TABLEWIDTH=22)
      integer TEXTFUN_ERROR
      parameter(TEXTFUN_ERROR=23)
      integer TEXTFUN_MAX
      parameter(TEXTFUN_MAX=24)
      integer TEXTFUN_APIPRINT
      parameter(TEXTFUN_APIPRINT=0)
      integer TEXTFUN_APIRETURN
      parameter(TEXTFUN_APIRETURN=1)
      integer VSY_TEXTTEE_MAX
      parameter(VSY_TEXTTEE_MAX=8)
      integer TIMER_ECHO
      parameter(TIMER_ECHO=1)
      integer TREE_FUNCTION_PRINT
      parameter(TREE_FUNCTION_PRINT=1)
      integer TRICON_MAXLENGTH
      parameter(TRICON_MAXLENGTH=1)
      integer TRICON_SWAP
      parameter(TRICON_SWAP=2)
      integer VKI_VERSION_MAJOR
      parameter(VKI_VERSION_MAJOR=3)
      integer VKI_VERSION_MINOR
      parameter(VKI_VERSION_MINOR=1)
      integer VKI_VERSION_PATCH
      parameter(VKI_VERSION_PATCH=0)
      integer VKI_VERSION_PRE_RELEASE
      parameter(VKI_VERSION_PRE_RELEASE=0)
      integer VERTLOC_TOL
      parameter(VERTLOC_TOL=1)
      integer VERTLOC_NTOL
      parameter(VERTLOC_NTOL=2)
      integer VERTLOC_NORMALATT
      parameter(VERTLOC_NORMALATT=3)
      integer VERTLOC_COLORTRANSATT
      parameter(VERTLOC_COLORTRANSATT=4)
      integer VHASHTABLE_HASH_FUNCTION_LEGACY
      parameter(VHASHTABLE_HASH_FUNCTION_LEGACY=0)
      integer VHASHTABLE_HASH_FUNCTION_FNV1A
      parameter(VHASHTABLE_HASH_FUNCTION_FNV1A=1)
      integer IDXTYPEWIDTH
      parameter(IDXTYPEWIDTH=64)
      integer REALTYPEWIDTH
      parameter(REALTYPEWIDTH=32)
      integer IDX_MAX
      parameter(IDX_MAX=32)
      integer IDX_MIN
      parameter(IDX_MIN=32)
      integer SCIDX
      parameter(SCIDX=32)
      integer PRIDX
      parameter(PRIDX=32)
      integer strtoidx
      parameter(strtoidx=32)
      integer IDX_MAX
      parameter(IDX_MAX=32)
      integer IDX_MIN
      parameter(IDX_MIN=32)
      integer SCIDX
      parameter(SCIDX=32)
      integer PRIDX
      parameter(PRIDX=32)
      integer strtoidx
      parameter(strtoidx=32)
      integer strtoidx
      parameter(strtoidx=32)
      integer SCREAL
      parameter(SCREAL=32)
      integer PRREAL
      parameter(PRREAL=32)
      integer REAL_MAX
      parameter(REAL_MAX=32)
      integer REAL_MIN
      parameter(REAL_MIN=32)
      integer REAL_EPSILON
      parameter(REAL_EPSILON=32)
      integer rabs
      parameter(rabs=32)
      integer strtoreal
      parameter(strtoreal=32)
      integer SCREAL
      parameter(SCREAL=32)
      integer PRREAL
      parameter(PRREAL=32)
      integer REAL_MAX
      parameter(REAL_MAX=32)
      integer REAL_MIN
      parameter(REAL_MIN=32)
      integer REAL_EPSILON
      parameter(REAL_EPSILON=32)
      integer rabs
      parameter(rabs=32)
      integer strtoreal
      parameter(strtoreal=32)
      integer THREAD_METIS_VER_MAJOR
      parameter(THREAD_METIS_VER_MAJOR=5)
      integer THREAD_METIS_VER_MINOR
      parameter(THREAD_METIS_VER_MINOR=1)
      integer THREAD_METIS_VER_SUBMINOR
      parameter(THREAD_METIS_VER_SUBMINOR=0)
      integer THREAD_METIS_NOPTIONS
      parameter(THREAD_METIS_NOPTIONS=40)
      integer VSOCKET_NONE
      parameter(VSOCKET_NONE=0)
      integer VSOCKET_CLIENT
      parameter(VSOCKET_CLIENT=1)
      integer VSOCKET_SERVER
      parameter(VSOCKET_SERVER=2)
      integer VSOCKET_WAITTIME
      parameter(VSOCKET_WAITTIME=1)
      integer VSOCKET_DEBUG
      parameter(VSOCKET_DEBUG=2)
      integer VSOCKET_SCOPE
      parameter(VSOCKET_SCOPE=3)
      integer VSOCKET_MAXCONNECTIONS
      parameter(VSOCKET_MAXCONNECTIONS=4)
      integer VSOCKET_LOCAL
      parameter(VSOCKET_LOCAL=1)
      integer VSOCKET_NET
      parameter(VSOCKET_NET=2)
      integer ZMEM_BUFFER
      parameter(ZMEM_BUFFER=1)
      integer ZMEM_FINISH
      parameter(ZMEM_FINISH=2)
