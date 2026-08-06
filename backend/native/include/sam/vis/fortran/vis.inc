      integer ANS_MAXELEMNODE
      parameter(ANS_MAXELEMNODE=32)
      integer ANSFWT_CONTROLCARDS
      parameter(ANSFWT_CONTROLCARDS=1)
      integer ANS_ALIAS_LINE300
      parameter(ANS_ALIAS_LINE300=1)
      integer ANS_ALIAS_TRI200
      parameter(ANS_ALIAS_TRI200=2)
      integer ANS_ALIAS_TRI300
      parameter(ANS_ALIAS_TRI300=3)
      integer ANS_ALIAS_TET200
      parameter(ANS_ALIAS_TET200=4)
      integer ANS_ALIAS_TET300
      parameter(ANS_ALIAS_TET300=5)
      integer ANS_ALIAS_PYR200
      parameter(ANS_ALIAS_PYR200=6)
      integer ANS_ALIAS_PYR300
      parameter(ANS_ALIAS_PYR300=7)
      integer ANS_ALIAS_WED200
      parameter(ANS_ALIAS_WED200=8)
      integer ANS_ALIAS_WED300
      parameter(ANS_ALIAS_WED300=9)
      integer ANS_ALIAS_QUAD320
      parameter(ANS_ALIAS_QUAD320=10)
      integer ANS_ALIAS_WED302
      parameter(ANS_ALIAS_WED302=11)
      integer ANS_ALIAS_HEX302
      parameter(ANS_ALIAS_HEX302=12)
      integer ANS_ALIAS_MAX
      parameter(ANS_ALIAS_MAX=12)
      integer ASURF_SEGMENT
      parameter(ASURF_SEGMENT=1)
      integer ASURF_SEGMENT_RULE
      parameter(ASURF_SEGMENT_RULE=2)
      integer ASURF_SEGMENT_REV
      parameter(ASURF_SEGMENT_REV=3)
      integer ASURF_PLANE
      parameter(ASURF_PLANE=4)
      integer ASURF_BOX
      parameter(ASURF_BOX=5)
      integer ASURF_SPHERE
      parameter(ASURF_SPHERE=6)
      integer ASURF_CYLINDER
      parameter(ASURF_CYLINDER=7)
      integer ASURF_CONE
      parameter(ASURF_CONE=8)
      integer ASURF_FACET
      parameter(ASURF_FACET=9)
      integer ASURF_NURBS
      parameter(ASURF_NURBS=10)
      integer ASURF_SEG_LINE
      parameter(ASURF_SEG_LINE=1)
      integer ASURF_SEG_ARC
      parameter(ASURF_SEG_ARC=2)
      integer ASURF_SEG_PARAB
      parameter(ASURF_SEG_PARAB=3)
      integer ASURF_FACET_TRI
      parameter(ASURF_FACET_TRI=1)
      integer ASURF_FACET_PARATRI
      parameter(ASURF_FACET_PARATRI=2)
      integer ASURF_FACET_QUAD
      parameter(ASURF_FACET_QUAD=3)
      integer ASURF_FACET_PARAQUAD
      parameter(ASURF_FACET_PARAQUAD=4)
      integer ASURF_NURBS_LINE
      parameter(ASURF_NURBS_LINE=1)
      integer ASURF_NURBS_SURF
      parameter(ASURF_NURBS_SURF=2)
      integer BEAMSECT_MAXPROPS
      parameter(BEAMSECT_MAXPROPS=16)
      integer BEAMSECT_MAXDIMES
      parameter(BEAMSECT_MAXDIMES=14)
      integer BEAMSECT_MAXFILLETS
      parameter(BEAMSECT_MAXFILLETS=10)
      integer BEAMSECT_PROPS
      parameter(BEAMSECT_PROPS=0)
      integer BEAMSECT_GEOMETRY
      parameter(BEAMSECT_GEOMETRY=1)
      integer BEAMSECT_BOX
      parameter(BEAMSECT_BOX=2)
      integer BEAMSECT_ANGLE
      parameter(BEAMSECT_ANGLE=3)
      integer BEAMSECT_IBEAM
      parameter(BEAMSECT_IBEAM=4)
      integer BEAMSECT_CIRCLE
      parameter(BEAMSECT_CIRCLE=5)
      integer BEAMSECT_TUBE
      parameter(BEAMSECT_TUBE=6)
      integer BEAMSECT_PANEL
      parameter(BEAMSECT_PANEL=7)
      integer BEAMSECT_RECTANGLE
      parameter(BEAMSECT_RECTANGLE=8)
      integer BEAMSECT_TRAPEZOID
      parameter(BEAMSECT_TRAPEZOID=9)
      integer BEAMSECT_HEXAGON
      parameter(BEAMSECT_HEXAGON=10)
      integer BEAMSECT_TEE
      parameter(BEAMSECT_TEE=11)
      integer BEAMSECT_ZEE
      parameter(BEAMSECT_ZEE=12)
      integer BEAMSECT_CHANNEL
      parameter(BEAMSECT_CHANNEL=13)
      integer BEAMSECT_SECTOR
      parameter(BEAMSECT_SECTOR=14)
      integer BEAMSECT_ELLIPSE
      parameter(BEAMSECT_ELLIPSE=15)
      integer BEAMSECT_HAT
      parameter(BEAMSECT_HAT=16)
      integer BEAMSECT_CROSS
      parameter(BEAMSECT_CROSS=17)
      integer BEAMSECT_DBOX
      parameter(BEAMSECT_DBOX=18)
      integer BEAMSECT_HAT1
      parameter(BEAMSECT_HAT1=19)
      integer BEAMSECT_QUAD
      parameter(BEAMSECT_QUAD=20)
      integer BEAMSECT_HATG
      parameter(BEAMSECT_HATG=21)
      integer BEAMSECT_SOLIDHEXA
      parameter(BEAMSECT_SOLIDHEXA=22)
      integer BEAMSECT_RECTTUBE
      parameter(BEAMSECT_RECTTUBE=23)
      integer BEAMSECT_HATT
      parameter(BEAMSECT_HATT=24)
      integer BEAMSECT_SEGMENTS
      parameter(BEAMSECT_SEGMENTS=25)
      integer BEAMSECT_MAXSECTIONS
      parameter(BEAMSECT_MAXSECTIONS=26)
      integer BEAMSECT_TORSION
      parameter(BEAMSECT_TORSION=0)
      integer BEAMSECT_FLEXURE1
      parameter(BEAMSECT_FLEXURE1=1)
      integer BEAMSECT_FLEXURE2
      parameter(BEAMSECT_FLEXURE2=2)
      integer BEAMSECT_QUALITYGRID
      parameter(BEAMSECT_QUALITYGRID=0)
      integer BEAMSECT_AXESBASIC
      parameter(BEAMSECT_AXESBASIC=1)
      integer BEAMSECT_AXESPRINCIPAL
      parameter(BEAMSECT_AXESPRINCIPAL=2)
      integer BEAMSECT_SHEARCENTER
      parameter(BEAMSECT_SHEARCENTER=3)
      integer BEAMSECT_CENTROID
      parameter(BEAMSECT_CENTROID=4)
      integer BEAMSECT_POLYLINE
      parameter(BEAMSECT_POLYLINE=5)
      integer BEAMSECT_EDGELENGTH
      parameter(BEAMSECT_EDGELENGTH=6)
      integer BEAMSECT_TRIMESHWRITE
      parameter(BEAMSECT_TRIMESHWRITE=8)
      integer BEAMSECT_MESHSMOOTH
      parameter(BEAMSECT_MESHSMOOTH=9)
      integer BEAMSECT_ERRORTOL
      parameter(BEAMSECT_ERRORTOL=10)
      integer BEAMSECT_MAXERRITER
      parameter(BEAMSECT_MAXERRITER=11)
      integer BEAMSECT_REFINE
      parameter(BEAMSECT_REFINE=12)
      integer BEAMSECT_NUMELEMENTS
      parameter(BEAMSECT_NUMELEMENTS=13)
      integer BEAMSECT_NASTRANWRITE
      parameter(BEAMSECT_NASTRANWRITE=14)
      integer BEAMSECT_VABS
      parameter(BEAMSECT_VABS=15)
      integer BEAMSECT_MAXELEMENTS
      parameter(BEAMSECT_MAXELEMENTS=16)
      integer BEAMSECT_TRIMESHFILETYPE
      parameter(BEAMSECT_TRIMESHFILETYPE=17)
      integer BEAMSECT_CENTROID_NONE
      parameter(BEAMSECT_CENTROID_NONE=0)
      integer BEAMSECT_CENTROID_CIRCLE
      parameter(BEAMSECT_CENTROID_CIRCLE=1)
      integer BEAMSECT_CENTROID_SPHERE
      parameter(BEAMSECT_CENTROID_SPHERE=2)
      integer BEAMSECT_ERROR
      parameter(BEAMSECT_ERROR=0)
      integer BEAMSECT_EDGELEN
      parameter(BEAMSECT_EDGELEN=1)
      integer BEAMSECT_NUMITER
      parameter(BEAMSECT_NUMITER=2)
      integer BEAMSECT_PROP_A
      parameter(BEAMSECT_PROP_A=0)
      integer BEAMSECT_PROP_IYY
      parameter(BEAMSECT_PROP_IYY=1)
      integer BEAMSECT_PROP_IZZ
      parameter(BEAMSECT_PROP_IZZ=2)
      integer BEAMSECT_PROP_IYZ
      parameter(BEAMSECT_PROP_IYZ=3)
      integer BEAMSECT_PROP_ANG
      parameter(BEAMSECT_PROP_ANG=4)
      integer BEAMSECT_PROP_J
      parameter(BEAMSECT_PROP_J=5)
      integer BEAMSECT_PROP_KSY
      parameter(BEAMSECT_PROP_KSY=6)
      integer BEAMSECT_PROP_KSZ
      parameter(BEAMSECT_PROP_KSZ=7)
      integer BEAMSECT_PROP_KSYZ
      parameter(BEAMSECT_PROP_KSYZ=8)
      integer BEAMSECT_PROP_EY
      parameter(BEAMSECT_PROP_EY=9)
      integer BEAMSECT_PROP_EZ
      parameter(BEAMSECT_PROP_EZ=10)
      integer BEAMSECT_PROP_DSY
      parameter(BEAMSECT_PROP_DSY=11)
      integer BEAMSECT_PROP_DSZ
      parameter(BEAMSECT_PROP_DSZ=12)
      integer BEAMSECT_PROP_CW
      parameter(BEAMSECT_PROP_CW=13)
      integer BEAMSECT_PROP_NEUTRALY
      parameter(BEAMSECT_PROP_NEUTRALY=14)
      integer BEAMSECT_PROP_NEUTRALZ
      parameter(BEAMSECT_PROP_NEUTRALZ=15)
      integer CONNECT_KERNELEXIST
      parameter(CONNECT_KERNELEXIST=1)
      integer CONNECT_STATIC
      parameter(CONNECT_STATIC=0)
      integer CONNECT_DYNAMIC
      parameter(CONNECT_DYNAMIC=1)
      integer CONNECT_UNIQUE
      parameter(CONNECT_UNIQUE=0)
      integer CONNECT_FREE
      parameter(CONNECT_FREE=1)
      integer CONNECT_ELEM
      parameter(CONNECT_ELEM=2)
      integer CONNECT_FEATURE
      parameter(CONNECT_FEATURE=3)
      integer CONNECT_ASSOC
      parameter(CONNECT_ASSOC=4)
      integer CONNECT_SHAPE
      parameter(CONNECT_SHAPE=5)
      integer CONNECT_DIMENSION
      parameter(CONNECT_DIMENSION=6)
      integer CONNECT_EXTENT
      parameter(CONNECT_EXTENT=7)
      integer CONNECT_CONTAINED
      parameter(CONNECT_CONTAINED=12)
      integer CONNECT_USE
      parameter(CONNECT_USE=13)
      integer CONNECT_CONNECTED
      parameter(CONNECT_CONNECTED=15)
      integer CONNECT_INCONSISTENT
      parameter(CONNECT_INCONSISTENT=17)
      integer CONNECT_CURVATURE
      parameter(CONNECT_CURVATURE=18)
      integer CONNECT_SEED
      parameter(CONNECT_SEED=23)
      integer CONNECT_NONMAN
      parameter(CONNECT_NONMAN=27)
      integer CONNECT_CORNER
      parameter(CONNECT_CORNER=28)
      integer CONNECT_ASSOCANY
      parameter(CONNECT_ASSOCANY=29)
      integer CONNECT_ASSOCDIFF
      parameter(CONNECT_ASSOCDIFF=30)
      integer CONNECT_INTERSECT
      parameter(CONNECT_INTERSECT=31)
      integer CONNECT_UNIQUEASSOCDIFF
      parameter(CONNECT_UNIQUEASSOCDIFF=32)
      integer CONNECT_FEATUREASSOCDIFF
      parameter(CONNECT_FEATUREASSOCDIFF=33)
      integer CONNECT_UNIQUEASSOC
      parameter(CONNECT_UNIQUEASSOC=34)
      integer CONNECT_FLOOD
      parameter(CONNECT_FLOOD=35)
      integer CONNECT_SILHOUETTE
      parameter(CONNECT_SILHOUETTE=8)
      integer CONNECT_INTERVAL
      parameter(CONNECT_INTERVAL=9)
      integer CONNECT_SAMPLE
      parameter(CONNECT_SAMPLE=20)
      integer CONNECT_FREEBODY
      parameter(CONNECT_FREEBODY=50)
      integer CONNECT_TOPOBODY
      parameter(CONNECT_TOPOBODY=51)
      integer CONNECT_MAP
      parameter(CONNECT_MAP=53)
      integer CONNECT_USERID
      parameter(CONNECT_USERID=54)
      integer CONNECT_TRIPOD
      parameter(CONNECT_TRIPOD=52)
      integer CONNECT_REDEFINETOPO
      parameter(CONNECT_REDEFINETOPO=22)
      integer CONNECT_EXACTADJACENCY
      parameter(CONNECT_EXACTADJACENCY=27)
      integer CONNECT_LAYERASSOC
      parameter(CONNECT_LAYERASSOC=34)
      integer CONNECT_ZEROUSERID
      parameter(CONNECT_ZEROUSERID=36)
      integer CONNECT_ASSOCID
      parameter(CONNECT_ASSOCID=2)
      integer CONNECT_FEATURESENSE
      parameter(CONNECT_FEATURESENSE=4)
      integer CONNECT_NUMBER
      parameter(CONNECT_NUMBER=14)
      integer CONNECT_SEEDNODE
      parameter(CONNECT_SEEDNODE=24)
      integer CONNECT_CURVATUREFLAT
      parameter(CONNECT_CURVATUREFLAT=26)
      integer CONNECT_SEEDELEM
      parameter(CONNECT_SEEDELEM=28)
      integer CONNECT_SEEDEDGE
      parameter(CONNECT_SEEDEDGE=29)
      integer CONNECT_SEEDFACE
      parameter(CONNECT_SEEDFACE=30)
      integer CONNECT_FEATURENONMAN
      parameter(CONNECT_FEATURENONMAN=33)
      integer CONNECT_ASSOCFREE
      parameter(CONNECT_ASSOCFREE=35)
      integer CONNECT_ASSOCTYPE
      parameter(CONNECT_ASSOCTYPE=1)
      integer CONNECT_INTERVALNUMBER
      parameter(CONNECT_INTERVALNUMBER=10)
      integer CONNECT_INTERVALVALUE
      parameter(CONNECT_INTERVALVALUE=11)
      integer CONNECT_DEMO_CUBE
      parameter(CONNECT_DEMO_CUBE=1)
      integer CONNECT_DEMO_CYLINDER
      parameter(CONNECT_DEMO_CYLINDER=2)
      integer CONNECT_DEMO_SPHERE
      parameter(CONNECT_DEMO_SPHERE=3)
      integer CONNECT_READ_ASCII
      parameter(CONNECT_READ_ASCII=3)
      integer CONNECT_READ_BINARY
      parameter(CONNECT_READ_BINARY=3)
      integer CONNECT_READ_STL
      parameter(CONNECT_READ_STL=3)
      integer CONNECT_READ_STL_BINARY
      parameter(CONNECT_READ_STL_BINARY=3)
      integer CONNECT_READ_OBJ
      parameter(CONNECT_READ_OBJ=3)
      integer CONNECT_WRITE_ASCII
      parameter(CONNECT_WRITE_ASCII=3)
      integer CONNECT_WRITE_BINARY
      parameter(CONNECT_WRITE_BINARY=3)
      integer CONNECT_WRITE_ABAQUS_INPUT
      parameter(CONNECT_WRITE_ABAQUS_INPUT=3)
      integer CONNECT_WRITE_ANSYS_INPUT
      parameter(CONNECT_WRITE_ANSYS_INPUT=3)
      integer CONNECT_WRITE_LS_DYNA_INPUT
      parameter(CONNECT_WRITE_LS_DYNA_INPUT=3)
      integer CONNECT_WRITE_NASTRAN_BULKDATA
      parameter(CONNECT_WRITE_NASTRAN_BULKDATA=3)
      integer CONNECT_WRITE_PATRAN_NEUTRAL
      parameter(CONNECT_WRITE_PATRAN_NEUTRAL=3)
      integer CONNECT_WRITE_SDRC_UNIVERSAL
      parameter(CONNECT_WRITE_SDRC_UNIVERSAL=3)
      integer CONNECT_GHS3D_DATA
      parameter(CONNECT_GHS3D_DATA=-10)
      integer CONNECT_GHS3D_NOBOITE
      parameter(CONNECT_GHS3D_NOBOITE=-11)
      integer CONNECT_TEXT_SUMMARY
      parameter(CONNECT_TEXT_SUMMARY=-16)
      integer CONNECT_TEXT_LISTING
      parameter(CONNECT_TEXT_LISTING=-17)
      integer CONNECT_SRF
      parameter(CONNECT_SRF=-19)
      integer CONNECT_TETGEN_NODEELEM
      parameter(CONNECT_TETGEN_NODEELEM=-20)
      integer CONNECT_TETGEN_POLY
      parameter(CONNECT_TETGEN_POLY=-21)
      integer CONNECT_CADENCE_MESH
      parameter(CONNECT_CADENCE_MESH=-22)
      integer CONNECT_GROUP_EXTENT
      parameter(CONNECT_GROUP_EXTENT=-22)
      integer CONNECT_MODELVIEWMATRIX
      parameter(CONNECT_MODELVIEWMATRIX=3)
      integer CONNECT_SEEDGROUP
      parameter(CONNECT_SEEDGROUP=25)
      integer CONNECT_NORMAL
      parameter(CONNECT_NORMAL=32)
      integer CONNECT_TOLERANCE
      parameter(CONNECT_TOLERANCE=16)
      integer CONNECT_SIZE
      parameter(CONNECT_SIZE=31)
      integer CONNECT_FEATUREANGLE
      parameter(CONNECT_FEATUREANGLE=0)
      integer CONNECT_GROUP_TOLERANCE
      parameter(CONNECT_GROUP_TOLERANCE=0)
      integer CONNECT_CURVATURECHANGE
      parameter(CONNECT_CURVATURECHANGE=19)
      integer CONNECT_SAMPLEDISTANCE
      parameter(CONNECT_SAMPLEDISTANCE=21)
      integer COORDSYS_XAXIS_XYPLANE
      parameter(COORDSYS_XAXIS_XYPLANE=0)
      integer COORDSYS_XAXIS_XZPLANE
      parameter(COORDSYS_XAXIS_XZPLANE=1)
      integer COORDSYS_ZAXIS_XZPLANE
      parameter(COORDSYS_ZAXIS_XZPLANE=2)
      integer CPAIR_CONTACT
      parameter(CPAIR_CONTACT=1)
      integer CPAIR_COSIM
      parameter(CPAIR_COSIM=2)
      integer CPAIR_CYCLIC
      parameter(CPAIR_CYCLIC=3)
      integer CPAIR_TIE_DEF
      parameter(CPAIR_TIE_DEF=4)
      integer CPAIR_MASTER
      parameter(CPAIR_MASTER=1)
      integer CPAIR_SLAVE
      parameter(CPAIR_SLAVE=2)
      integer CPAIR_UNDEFINED
      parameter(CPAIR_UNDEFINED=0)
      integer CPAIR_VALUE
      parameter(CPAIR_VALUE=1)
      integer CPAIR_CURVE
      parameter(CPAIR_CURVE=2)
      integer CPAIR_PID
      parameter(CPAIR_PID=0)
      integer CPAIR_SMALLSLIDING
      parameter(CPAIR_SMALLSLIDING=2)
      integer CPAIR_SYMMETRIC
      parameter(CPAIR_SYMMETRIC=7)
      integer CPAIR_SURFTOSURF
      parameter(CPAIR_SURFTOSURF=8)
      integer CPAIR_PROJECT
      parameter(CPAIR_PROJECT=10)
      integer CPAIR_NUMSECTOR
      parameter(CPAIR_NUMSECTOR=11)
      integer CPAIR_CID
      parameter(CPAIR_CID=12)
      integer CPAIR_MASTER_SET
      parameter(CPAIR_MASTER_SET=13)
      integer CPAIR_SLAVE_SET
      parameter(CPAIR_SLAVE_SET=14)
      integer CPAIR_CONTACT_BEHAVIOR
      parameter(CPAIR_CONTACT_BEHAVIOR=16)
      integer CPAIR_SEPARATIONTHRESHOLDTYPE
      parameter(CPAIR_SEPARATIONTHRESHOLDTYPE=18)
      integer CPAIR_ID
      parameter(CPAIR_ID=21)
      integer CPAIR_CYCLIC_MATCHING
      parameter(CPAIR_CYCLIC_MATCHING=22)
      integer CPAIR_MATLID
      parameter(CPAIR_MATLID=23)
      integer CPAIR_ADJUST
      parameter(CPAIR_ADJUST=1)
      integer CPAIR_SMOOTH
      parameter(CPAIR_SMOOTH=4)
      integer CPAIR_HCRIT
      parameter(CPAIR_HCRIT=5)
      integer CPAIR_EXTENSIONZONE
      parameter(CPAIR_EXTENSIONZONE=6)
      integer CPAIR_POSITIONTOL
      parameter(CPAIR_POSITIONTOL=9)
      integer CPAIR_CYCLICTOLERANCE
      parameter(CPAIR_CYCLICTOLERANCE=15)
      integer CPAIR_MINPOSITIONTOL
      parameter(CPAIR_MINPOSITIONTOL=17)
      integer CPAIR_SEPARATIONTHRESHOLD
      parameter(CPAIR_SEPARATIONTHRESHOLD=19)
      integer CPAIR_BIAS_POSITIONTOL
      parameter(CPAIR_BIAS_POSITIONTOL=20)
      integer CPAIR_UNUSED
      parameter(CPAIR_UNUSED=3)
      integer CPAIR_MAX
      parameter(CPAIR_MAX=24)
      integer CPAIR_CONTACT_BEHAVIOR_STANDARD
      parameter(CPAIR_CONTACT_BEHAVIOR_STANDARD=0)
      integer CPAIR_CONTACT_BEHAVIOR_ROUGH
      parameter(CPAIR_CONTACT_BEHAVIOR_ROUGH=1)
      integer CPAIR_CONTACT_BEHAVIOR_NO_SEPARATION
      parameter(CPAIR_CONTACT_BEHAVIOR_NO_SEPARATION=2)
      integer CPAIR_CONTACT_BEHAVIOR_BONDED
      parameter(CPAIR_CONTACT_BEHAVIOR_BONDED=3)
      integer CPAIR_SEPARATION_FORCE
      parameter(CPAIR_SEPARATION_FORCE=0)
      integer CPAIR_SEPARATION_STRESS
      parameter(CPAIR_SEPARATION_STRESS=1)
      integer CPAIR_SEPARATION_STRESS_EXTRAPOL
      parameter(CPAIR_SEPARATION_STRESS_EXTRAPOL=2)
      integer CPAIR_SEPARATION_STRESS_NODAL
      parameter(CPAIR_SEPARATION_STRESS_NODAL=3)
      integer CPAIR_SEPARATION_STRESS_RELATIVE
      parameter(CPAIR_SEPARATION_STRESS_RELATIVE=4)
      integer ELEMCHK_ALL
      parameter(ELEMCHK_ALL=-1)
      integer ELEMCHK_JACOBIAN_SUM
      parameter(ELEMCHK_JACOBIAN_SUM=0)
      integer ELEMCHK_JACOBIAN_RATIO
      parameter(ELEMCHK_JACOBIAN_RATIO=1)
      integer ELEMCHK_JACOBIAN_SMALL
      parameter(ELEMCHK_JACOBIAN_SMALL=2)
      integer ELEMCHK_ASPECT_RATIO
      parameter(ELEMCHK_ASPECT_RATIO=3)
      integer ELEMCHK_FACE_TAPER
      parameter(ELEMCHK_FACE_TAPER=4)
      integer ELEMCHK_SKEW
      parameter(ELEMCHK_SKEW=5)
      integer ELEMCHK_TWIST
      parameter(ELEMCHK_TWIST=6)
      integer ELEMCHK_SUBTENDED_ANGLE
      parameter(ELEMCHK_SUBTENDED_ANGLE=7)
      integer ELEMCHK_CIRCUM_RATIO
      parameter(ELEMCHK_CIRCUM_RATIO=8)
      integer ELEMCHK_MIN_ANGLE
      parameter(ELEMCHK_MIN_ANGLE=9)
      integer ELEMCHK_FACE_WARP
      parameter(ELEMCHK_FACE_WARP=10)
      integer ELEMCHK_CG_X
      parameter(ELEMCHK_CG_X=11)
      integer ELEMCHK_CG_Y
      parameter(ELEMCHK_CG_Y=12)
      integer ELEMCHK_CG_Z
      parameter(ELEMCHK_CG_Z=13)
      integer ELEMCHK_EDGEALT_RATIO
      parameter(ELEMCHK_EDGEALT_RATIO=14)
      integer ELEMCHK_JACOBIAN_NODAL
      parameter(ELEMCHK_JACOBIAN_NODAL=15)
      integer ELEMCHK_DIMENSION
      parameter(ELEMCHK_DIMENSION=16)
      integer ELEMCHK_PORDER
      parameter(ELEMCHK_PORDER=17)
      integer ELEMCHK_H
      parameter(ELEMCHK_H=18)
      integer ELEMCHK_MAX_ANGLE
      parameter(ELEMCHK_MAX_ANGLE=19)
      integer ELEMCHK_MIN_DIHEDANGLE
      parameter(ELEMCHK_MIN_DIHEDANGLE=20)
      integer ELEMCHK_MAX_DIHEDANGLE
      parameter(ELEMCHK_MAX_DIHEDANGLE=21)
      integer ELEMCHK_HANDEDNESS
      parameter(ELEMCHK_HANDEDNESS=22)
      integer ELEMCHK_MIN_EDGELENGTH
      parameter(ELEMCHK_MIN_EDGELENGTH=23)
      integer ELEMCHK_MAX_EDGELENGTH
      parameter(ELEMCHK_MAX_EDGELENGTH=24)
      integer ELEMCHK_CORN_WARP
      parameter(ELEMCHK_CORN_WARP=25)
      integer ELEMCHK_CORN_SKEW
      parameter(ELEMCHK_CORN_SKEW=26)
      integer ELEMCHK_MIDSIDE_OFF
      parameter(ELEMCHK_MIDSIDE_OFF=27)
      integer ELEMCHK_JACOBIAN_CORN
      parameter(ELEMCHK_JACOBIAN_CORN=28)
      integer ELEMCHK_EDGELENGTH
      parameter(ELEMCHK_EDGELENGTH=29)
      integer ELEMCHK_MAX
      parameter(ELEMCHK_MAX=30)
      integer ELEMCHK_CHEAP
      parameter(ELEMCHK_CHEAP=1)
      integer ELEMCHK_ADAPTTOL
      parameter(ELEMCHK_ADAPTTOL=1)
      integer ELEMCHK_MINREFINE
      parameter(ELEMCHK_MINREFINE=2)
      integer ELEMDAT_SETDATA
      parameter(ELEMDAT_SETDATA=1)
      integer ELEMDAT_LINNORMAL
      parameter(ELEMDAT_LINNORMAL=3)
      integer ELEMDAT_FEATUREBRANCH
      parameter(ELEMDAT_FEATUREBRANCH=2)
      integer ELEMDAT_FEATUREANGLE
      parameter(ELEMDAT_FEATUREANGLE=1)
      integer EPROP_UNDEFINED
      parameter(EPROP_UNDEFINED=0)
      integer EPROP_VALUE
      parameter(EPROP_VALUE=1)
      integer EPROP_IDENTIFIER
      parameter(EPROP_IDENTIFIER=2)
      integer EPROP_360
      parameter(EPROP_360=1)
      integer EPROP_MID
      parameter(EPROP_MID=0)
      integer EPROP_MID_BEND
      parameter(EPROP_MID_BEND=1)
      integer EPROP_MID_TRAN
      parameter(EPROP_MID_TRAN=2)
      integer EPROP_MID_COUP
      parameter(EPROP_MID_COUP=3)
      integer EPROP_MATLCID
      parameter(EPROP_MATLCID=5)
      integer EPROP_RULE
      parameter(EPROP_RULE=6)
      integer EPROP_NOSEPARATION
      parameter(EPROP_NOSEPARATION=45)
      integer EPROP_NOSLIP
      parameter(EPROP_NOSLIP=46)
      integer EPROP_DOF1
      parameter(EPROP_DOF1=49)
      integer EPROP_DOF2
      parameter(EPROP_DOF2=50)
      integer EPROP_HEATEXCH
      parameter(EPROP_HEATEXCH=62)
      integer EPROP_BEAMSECT
      parameter(EPROP_BEAMSECT=81)
      integer EPROP_DOFFLAG_NUM
      parameter(EPROP_DOFFLAG_NUM=83)
      integer EPROP_DOFFLAG_IND
      parameter(EPROP_DOFFLAG_IND=85)
      integer EPROP_DOFFLAG_DEP
      parameter(EPROP_DOFFLAG_DEP=86)
      integer EPROP_SHELLWALL
      parameter(EPROP_SHELLWALL=89)
      integer EPROP_LAYER_NUM
      parameter(EPROP_LAYER_NUM=96)
      integer EPROP_LAYER_MID
      parameter(EPROP_LAYER_MID=99)
      integer EPROP_LAYER_NIP
      parameter(EPROP_LAYER_NIP=100)
      integer EPROP_BEAMREFLECTY
      parameter(EPROP_BEAMREFLECTY=102)
      integer EPROP_BEAMREFLECTZ
      parameter(EPROP_BEAMREFLECTZ=103)
      integer EPROP_BEAMPNTS_NUM
      parameter(EPROP_BEAMPNTS_NUM=111)
      integer EPROP_BEAMLOOP_NUM
      parameter(EPROP_BEAMLOOP_NUM=113)
      integer EPROP_BEAMLOOP_PNTSNUM
      parameter(EPROP_BEAMLOOP_PNTSNUM=114)
      integer EPROP_BEAMLOOP_TYPE
      parameter(EPROP_BEAMLOOP_TYPE=115)
      integer EPROP_BEAMLOOP_MID
      parameter(EPROP_BEAMLOOP_MID=116)
      integer EPROP_BEAMLOOP_PNTS
      parameter(EPROP_BEAMLOOP_PNTS=117)
      integer EPROP_BEAMSEGS_NUM
      parameter(EPROP_BEAMSEGS_NUM=118)
      integer EPROP_LAYER_GID
      parameter(EPROP_LAYER_GID=130)
      integer EPROP_TIED
      parameter(EPROP_TIED=136)
      integer EPROP_NSM_ID
      parameter(EPROP_NSM_ID=141)
      integer EPROP_NSM_NUM
      parameter(EPROP_NSM_NUM=142)
      integer EPROP_NSM_VAL_SETIDS
      parameter(EPROP_NSM_VAL_SETIDS=144)
      integer EPROP_NSM_VAL_LUMP
      parameter(EPROP_NSM_VAL_LUMP=145)
      integer EPROP_BEND_FLEXFACTOR
      parameter(EPROP_BEND_FLEXFACTOR=150)
      integer EPROP_AMBIENT_TYPE
      parameter(EPROP_AMBIENT_TYPE=154)
      integer EPROP_GALERKIN_SPLINE_TYPE
      parameter(EPROP_GALERKIN_SPLINE_TYPE=158)
      integer EPROP_GALERKIN_DILATION_TYPE
      parameter(EPROP_GALERKIN_DILATION_TYPE=159)
      integer EPROP_GALERKIN_ESSENTIAL_BC_TYPE
      parameter(EPROP_GALERKIN_ESSENTIAL_BC_TYPE=160)
      integer EPROP_GALERKIN_DOMAIN_INTEGRATION_TYPE
      parameter(EPROP_GALERKIN_DOMAIN_INTEGRATION_TYPE=161)
      integer EPROP_GALERKIN_PRESSURE_SMOOTHING
      parameter(EPROP_GALERKIN_PRESSURE_SMOOTHING=163)
      integer EPROP_GALERKIN_KERNEL
      parameter(EPROP_GALERKIN_KERNEL=164)
      integer EPROP_GALERKIN_SMOOTHING_STEPS_INTERVAL
      parameter(EPROP_GALERKIN_SMOOTHING_STEPS_INTERVAL=165)
      integer EPROP_GALERKIN_SMOOTHING_SCHEME
      parameter(EPROP_GALERKIN_SMOOTHING_SCHEME=166)
      integer EPROP_GALERKIN_BOND_FAILURE_TYPE
      parameter(EPROP_GALERKIN_BOND_FAILURE_TYPE=167)
      integer EPROP_GALERKIN_STABILIZATION_TYPE
      parameter(EPROP_GALERKIN_STABILIZATION_TYPE=170)
      integer EPROP_GALERKIN_SELF_CONTACT
      parameter(EPROP_GALERKIN_SELF_CONTACT=172)
      integer EPROP_GALERKIN_BOX_ID
      parameter(EPROP_GALERKIN_BOX_ID=173)
      integer EPROP_TENSION_TABLES
      parameter(EPROP_TENSION_TABLES=179)
      integer EPROP_REINFSECT_NUM
      parameter(EPROP_REINFSECT_NUM=180)
      integer EPROP_REINFSECT
      parameter(EPROP_REINFSECT=181)
      integer EPROP_REINFSECT_MID
      parameter(EPROP_REINFSECT_MID=182)
      integer EPROP_REINFSECT_CID
      parameter(EPROP_REINFSECT_CID=185)
      integer EPROP_REINFSECT_LOCATION_TYPE
      parameter(EPROP_REINFSECT_LOCATION_TYPE=187)
      integer EPROP_COHESIVE_RESPONSE_TYPE
      parameter(EPROP_COHESIVE_RESPONSE_TYPE=188)
      integer EPROP_FRICTION_TYPE
      parameter(EPROP_FRICTION_TYPE=189)
      integer EPROP_THICKNESS
      parameter(EPROP_THICKNESS=7)
      integer EPROP_OFFSET
      parameter(EPROP_OFFSET=8)
      integer EPROP_KS
      parameter(EPROP_KS=9)
      integer EPROP_BENDSTF
      parameter(EPROP_BENDSTF=10)
      integer EPROP_NSM
      parameter(EPROP_NSM=11)
      integer EPROP_SRBOT
      parameter(EPROP_SRBOT=12)
      integer EPROP_SRTOP
      parameter(EPROP_SRTOP=13)
      integer EPROP_AREA
      parameter(EPROP_AREA=14)
      integer EPROP_IYY
      parameter(EPROP_IYY=15)
      integer EPROP_IZZ
      parameter(EPROP_IZZ=16)
      integer EPROP_IYZ
      parameter(EPROP_IYZ=17)
      integer EPROP_J
      parameter(EPROP_J=18)
      integer EPROP_KSY
      parameter(EPROP_KSY=19)
      integer EPROP_KSZ
      parameter(EPROP_KSZ=20)
      integer EPROP_DSY
      parameter(EPROP_DSY=21)
      integer EPROP_DSZ
      parameter(EPROP_DSZ=22)
      integer EPROP_OFFSETY
      parameter(EPROP_OFFSETY=23)
      integer EPROP_OFFSETZ
      parameter(EPROP_OFFSETZ=24)
      integer EPROP_CW
      parameter(EPROP_CW=25)
      integer EPROP_DIN
      parameter(EPROP_DIN=26)
      integer EPROP_DOUT
      parameter(EPROP_DOUT=27)
      integer EPROP_BENDRADIUS
      parameter(EPROP_BENDRADIUS=28)
      integer EPROP_STRSCOEFROT
      parameter(EPROP_STRSCOEFROT=29)
      integer EPROP_SRC
      parameter(EPROP_SRC=30)
      integer EPROP_SRD
      parameter(EPROP_SRD=31)
      integer EPROP_SRE
      parameter(EPROP_SRE=32)
      integer EPROP_SRF
      parameter(EPROP_SRF=33)
      integer EPROP_UZERO
      parameter(EPROP_UZERO=34)
      integer EPROP_FZERO
      parameter(EPROP_FZERO=35)
      integer EPROP_KCLOSE
      parameter(EPROP_KCLOSE=36)
      integer EPROP_KOPEN
      parameter(EPROP_KOPEN=37)
      integer EPROP_KTRANS
      parameter(EPROP_KTRANS=38)
      integer EPROP_MUSY
      parameter(EPROP_MUSY=39)
      integer EPROP_MUSZ
      parameter(EPROP_MUSZ=40)
      integer EPROP_MU_ISO
      parameter(EPROP_MU_ISO=39)
      integer EPROP_MU1_ORTHO
      parameter(EPROP_MU1_ORTHO=39)
      integer EPROP_MU2_ORTHO
      parameter(EPROP_MU2_ORTHO=40)
      integer EPROP_MUKY
      parameter(EPROP_MUKY=41)
      integer EPROP_MUKZ
      parameter(EPROP_MUKZ=42)
      integer EPROP_STIFF
      parameter(EPROP_STIFF=47)
      integer EPROP_DAMP
      parameter(EPROP_DAMP=48)
      integer EPROP_MASS
      parameter(EPROP_MASS=51)
      integer EPROP_OFFSETVEC
      parameter(EPROP_OFFSETVEC=52)
      integer EPROP_INERTIA
      parameter(EPROP_INERTIA=53)
      integer EPROP_MASSMATRIX
      parameter(EPROP_MASSMATRIX=54)
      integer EPROP_STIFFMATRIX
      parameter(EPROP_STIFFMATRIX=55)
      integer EPROP_PENALTY
      parameter(EPROP_PENALTY=56)
      integer EPROP_FILM
      parameter(EPROP_FILM=61)
      integer EPROP_CONVEXP
      parameter(EPROP_CONVEXP=63)
      integer EPROP_AREAFACT
      parameter(EPROP_AREAFACT=64)
      integer EPROP_STRSCOEF
      parameter(EPROP_STRSCOEF=65)
      integer EPROP_STIFFTRA
      parameter(EPROP_STIFFTRA=74)
      integer EPROP_STIFFROT
      parameter(EPROP_STIFFROT=75)
      integer EPROP_DAMPTRA
      parameter(EPROP_DAMPTRA=76)
      integer EPROP_DAMPROT
      parameter(EPROP_DAMPROT=77)
      integer EPROP_STRSCOEFTRA
      parameter(EPROP_STRSCOEFTRA=78)
      integer EPROP_STRNCOEFTRA
      parameter(EPROP_STRNCOEFTRA=79)
      integer EPROP_STRNCOEFROT
      parameter(EPROP_STRNCOEFROT=80)
      integer EPROP_BEAMDIME
      parameter(EPROP_BEAMDIME=82)
      integer EPROP_DOFFLAG_WGTS
      parameter(EPROP_DOFFLAG_WGTS=84)
      integer EPROP_SHELLMATRIX
      parameter(EPROP_SHELLMATRIX=90)
      integer EPROP_SHELLALPHA
      parameter(EPROP_SHELLALPHA=91)
      integer EPROP_QMATRIX
      parameter(EPROP_QMATRIX=92)
      integer EPROP_QALPHA
      parameter(EPROP_QALPHA=93)
      integer EPROP_BEAMMATRIX
      parameter(EPROP_BEAMMATRIX=94)
      integer EPROP_BEAMALPHA
      parameter(EPROP_BEAMALPHA=95)
      integer EPROP_LAYER_THK
      parameter(EPROP_LAYER_THK=97)
      integer EPROP_LAYER_PHI
      parameter(EPROP_LAYER_PHI=98)
      integer EPROP_ECC
      parameter(EPROP_ECC=101)
      integer EPROP_BEAMROTANGLE
      parameter(EPROP_BEAMROTANGLE=104)
      integer EPROP_RIGIDALPHA
      parameter(EPROP_RIGIDALPHA=108)
      integer EPROP_BEAMPNTS
      parameter(EPROP_BEAMPNTS=112)
      integer EPROP_BEAMSEGS_THICK
      parameter(EPROP_BEAMSEGS_THICK=119)
      integer EPROP_BEAMSEGS_PNTS
      parameter(EPROP_BEAMSEGS_PNTS=120)
      integer EPROP_EMIS
      parameter(EPROP_EMIS=135)
      integer EPROP_SDAMP
      parameter(EPROP_SDAMP=137)
      integer EPROP_SDAMPTRA
      parameter(EPROP_SDAMPTRA=138)
      integer EPROP_SDAMPROT
      parameter(EPROP_SDAMPROT=139)
      integer EPROP_NSM_VAL
      parameter(EPROP_NSM_VAL=143)
      integer EPROP_BEND_THETA
      parameter(EPROP_BEND_THETA=146)
      integer EPROP_BEND_INTERNALPRESSURE
      parameter(EPROP_BEND_INTERNALPRESSURE=147)
      integer EPROP_BEND_RCOFFSET
      parameter(EPROP_BEND_RCOFFSET=148)
      integer EPROP_BEND_ZCOFFSET
      parameter(EPROP_BEND_ZCOFFSET=149)
      integer EPROP_BEND_ROFFSET
      parameter(EPROP_BEND_ROFFSET=151)
      integer EPROP_BEND_RADIUSMEAN
      parameter(EPROP_BEND_RADIUSMEAN=152)
      integer EPROP_COHESIVE_LAYER
      parameter(EPROP_COHESIVE_LAYER=155)
      integer EPROP_GASKET_THICKNESS
      parameter(EPROP_GASKET_THICKNESS=156)
      integer EPROP_GALERKIN_DILATION_PARAMETERS
      parameter(EPROP_GALERKIN_DILATION_PARAMETERS=157)
      integer EPROP_GALERKIN_DEFORMATION_TOLERANCE
      parameter(EPROP_GALERKIN_DEFORMATION_TOLERANCE=162)
      integer EPROP_GALERKIN_CRITICAL_BOND_FAILURE
      parameter(EPROP_GALERKIN_CRITICAL_BOND_FAILURE=168)
      integer EPROP_GALERKIN_CRITICAL_STRETCH
      parameter(EPROP_GALERKIN_CRITICAL_STRETCH=169)
      integer EPROP_GALERKIN_SHEAR_LOCKING_FACTOR
      parameter(EPROP_GALERKIN_SHEAR_LOCKING_FACTOR=171)
      integer EPROP_GALERKIN_PARTICLE_DAMPING
      parameter(EPROP_GALERKIN_PARTICLE_DAMPING=174)
      integer EPROP_GALERKIN_SWITCH_TIME_LTE
      parameter(EPROP_GALERKIN_SWITCH_TIME_LTE=175)
      integer EPROP_GALERKIN_LENGTH_SCALE
      parameter(EPROP_GALERKIN_LENGTH_SCALE=176)
      integer EPROP_VISCOUS_DAMP_TC
      parameter(EPROP_VISCOUS_DAMP_TC=177)
      integer EPROP_VISCOUS_EXPNT_TC
      parameter(EPROP_VISCOUS_EXPNT_TC=178)
      integer EPROP_REINFSECT_AREA
      parameter(EPROP_REINFSECT_AREA=183)
      integer EPROP_REINFSECT_FIBER_DISTANCE
      parameter(EPROP_REINFSECT_FIBER_DISTANCE=184)
      integer EPROP_REINFSECT_THETA
      parameter(EPROP_REINFSECT_THETA=186)
      integer EPROP_CID
      parameter(EPROP_CID=4)
      integer EPROP_UDELTA
      parameter(EPROP_UDELTA=43)
      integer EPROP_KDELTA
      parameter(EPROP_KDELTA=44)
      integer EPROP_NUMDIST
      parameter(EPROP_NUMDIST=57)
      integer EPROP_WEIGHTS
      parameter(EPROP_WEIGHTS=58)
      integer EPROP_DOFFLAGDEP
      parameter(EPROP_DOFFLAGDEP=59)
      integer EPROP_DOFFLAGIND
      parameter(EPROP_DOFFLAGIND=60)
      integer EPROP_CONVEXCH
      parameter(EPROP_CONVEXCH=62)
      integer EPROP_ELEMPOINT
      parameter(EPROP_ELEMPOINT=66)
      integer EPROP_ELEMLINE
      parameter(EPROP_ELEMLINE=67)
      integer EPROP_ELEMTRI
      parameter(EPROP_ELEMTRI=68)
      integer EPROP_ELEMQUAD
      parameter(EPROP_ELEMQUAD=69)
      integer EPROP_ELEMTET
      parameter(EPROP_ELEMTET=70)
      integer EPROP_ELEMPYR
      parameter(EPROP_ELEMPYR=71)
      integer EPROP_ELEMWED
      parameter(EPROP_ELEMWED=72)
      integer EPROP_ELEMHEX
      parameter(EPROP_ELEMHEX=73)
      integer EPROP_SHEAR_F1
      parameter(EPROP_SHEAR_F1=87)
      integer EPROP_SHEAR_F2
      parameter(EPROP_SHEAR_F2=88)
      integer EPROP_SOLIDMIX
      parameter(EPROP_SOLIDMIX=105)
      integer EPROP_MIX_NUM
      parameter(EPROP_MIX_NUM=106)
      integer EPROP_MIX_MID
      parameter(EPROP_MIX_MID=107)
      integer EPROP_KSYZ
      parameter(EPROP_KSYZ=121)
      integer EPROP_SUPER_MASSTYPE
      parameter(EPROP_SUPER_MASSTYPE=122)
      integer EPROP_SUPER_STIFFTYPE
      parameter(EPROP_SUPER_STIFFTYPE=123)
      integer EPROP_SUPER_MASS
      parameter(EPROP_SUPER_MASS=124)
      integer EPROP_SUPER_STIFF
      parameter(EPROP_SUPER_STIFF=125)
      integer EPROP_SUPER_ID
      parameter(EPROP_SUPER_ID=126)
      integer EPROP_SUPER_TRANS
      parameter(EPROP_SUPER_TRANS=127)
      integer EPROP_SUPER_ORIGIN
      parameter(EPROP_SUPER_ORIGIN=128)
      integer EPROP_SUPER_DIRCOS
      parameter(EPROP_SUPER_DIRCOS=129)
      integer EPROP_ORIGIN
      parameter(EPROP_ORIGIN=131)
      integer EPROP_TRANS
      parameter(EPROP_TRANS=132)
      integer EPROP_ROTANG
      parameter(EPROP_ROTANG=133)
      integer EPROP_USER_NUM
      parameter(EPROP_USER_NUM=134)
      integer EPROP_COMP_PSDIR
      parameter(EPROP_COMP_PSDIR=140)
      integer EPROP_FORMULATION
      parameter(EPROP_FORMULATION=153)
      integer EPROP_MAX
      parameter(EPROP_MAX=190)
      integer EPROP_USERDIMENUM
      parameter(EPROP_USERDIMENUM=-1000000)
      integer EPROP_USERDIME
      parameter(EPROP_USERDIME=-2000000)
      integer EPROP_USERNAME
      parameter(EPROP_USERNAME=-3000000)
      integer EPROP_USERDATATYPE
      parameter(EPROP_USERDATATYPE=-4000000)
      integer EPROP_USERDATA
      parameter(EPROP_USERDATA=-5000000)
      integer EPROP_USERBASE
      parameter(EPROP_USERBASE=-5000000)
      integer EPROP_FRICTION_NOFRICTION
      parameter(EPROP_FRICTION_NOFRICTION=0)
      integer EPROP_FRICTION_BILINEAR_COULOMB
      parameter(EPROP_FRICTION_BILINEAR_COULOMB=1)
      integer EPROP_FRICTION_BILINEAR_SHEAR
      parameter(EPROP_FRICTION_BILINEAR_SHEAR=2)
      integer COHESIVE_RESP_NONE
      parameter(COHESIVE_RESP_NONE=0)
      integer COHESIVE_RESP_TRACTIONSEPARATION
      parameter(COHESIVE_RESP_TRACTIONSEPARATION=1)
      integer COHESIVE_RESP_CONTINUUM
      parameter(COHESIVE_RESP_CONTINUUM=2)
      integer COHESIVE_RESP_GASKET
      parameter(COHESIVE_RESP_GASKET=3)
      integer GEOMFUN_OPEN
      parameter(GEOMFUN_OPEN=1)
      integer GEOMFUN_CLOSE
      parameter(GEOMFUN_CLOSE=2)
      integer GEOMFUN_MODELLER
      parameter(GEOMFUN_MODELLER=4)
      integer GEOMFUN_NUMBODY
      parameter(GEOMFUN_NUMBODY=5)
      integer GEOMFUN_BODY
      parameter(GEOMFUN_BODY=6)
      integer GEOMFUN_FACE
      parameter(GEOMFUN_FACE=7)
      integer GEOMFUN_EDGE
      parameter(GEOMFUN_EDGE=8)
      integer GEOMFUN_NODE
      parameter(GEOMFUN_NODE=9)
      integer GEOMFUN_FACELOOP
      parameter(GEOMFUN_FACELOOP=10)
      integer GEOMFUN_EXTENT
      parameter(GEOMFUN_EXTENT=11)
      integer GEOMFUN_EDGEPOINT
      parameter(GEOMFUN_EDGEPOINT=12)
      integer GEOMFUN_EDGENEAREST
      parameter(GEOMFUN_EDGENEAREST=13)
      integer GEOMFUN_FACEPOINT
      parameter(GEOMFUN_FACEPOINT=14)
      integer GEOMFUN_FACENEAREST
      parameter(GEOMFUN_FACENEAREST=15)
      integer GEOMFUN_FACENORMAL
      parameter(GEOMFUN_FACENORMAL=16)
      integer GEOMFUN_ERROR
      parameter(GEOMFUN_ERROR=17)
      integer GEOMFUN_MAX
      parameter(GEOMFUN_MAX=18)
      integer GPROP_UNDEFINED
      parameter(GPROP_UNDEFINED=0)
      integer GPROP_VALUE
      parameter(GPROP_VALUE=1)
      integer GPROP_IDENTIFIER
      parameter(GPROP_IDENTIFIER=2)
      integer GPROP_TITLE
      parameter(GPROP_TITLE=3)
      integer GPROP_SUBTITLE
      parameter(GPROP_SUBTITLE=4)
      integer GPROP_ORIGCODE
      parameter(GPROP_ORIGCODE=5)
      integer GPROP_ORIGVERSION
      parameter(GPROP_ORIGVERSION=6)
      integer GPROP_ORIGTIME
      parameter(GPROP_ORIGTIME=7)
      integer GPROP_ORIGDATE
      parameter(GPROP_ORIGDATE=8)
      integer GPROP_2DPLANE
      parameter(GPROP_2DPLANE=0)
      integer GPROP_2DTYPE
      parameter(GPROP_2DTYPE=1)
      integer GPROP_LIBRARY
      parameter(GPROP_LIBRARY=2)
      integer GPROP_2DAXIS
      parameter(GPROP_2DAXIS=15)
      integer GPROP_AUTOSPC
      parameter(GPROP_AUTOSPC=22)
      integer GPROP_IMPORT_VENDOR
      parameter(GPROP_IMPORT_VENDOR=25)
      integer GPROP_EXPORT_VENDOR
      parameter(GPROP_EXPORT_VENDOR=26)
      integer GPROP_CYCLIC_NSEC
      parameter(GPROP_CYCLIC_NSEC=10)
      integer GPROP_SYMM_NUM
      parameter(GPROP_SYMM_NUM=16)
      integer GPROP_SYMM_ID
      parameter(GPROP_SYMM_ID=17)
      integer GPROP_SYMM_CID
      parameter(GPROP_SYMM_CID=18)
      integer GPROP_SYMM_NSEC
      parameter(GPROP_SYMM_NSEC=19)
      integer GPROP_SYMM_STAGEID
      parameter(GPROP_SYMM_STAGEID=27)
      integer GPROP_CYCLIC_CSYSID
      parameter(GPROP_CYCLIC_CSYSID=28)
      integer GPROP_PERMANENT_GLUE
      parameter(GPROP_PERMANENT_GLUE=29)
      integer GPROP_SYMM_ESET
      parameter(GPROP_SYMM_ESET=24)
      integer GPROP_CYCLIC_ORIG
      parameter(GPROP_CYCLIC_ORIG=11)
      integer GPROP_CYCLIC_AXIS
      parameter(GPROP_CYCLIC_AXIS=12)
      integer GPROP_STEFAN_BOLTZMANN
      parameter(GPROP_STEFAN_BOLTZMANN=13)
      integer GPROP_ABSOLUTE_ZERO
      parameter(GPROP_ABSOLUTE_ZERO=14)
      integer GPROP_SYMM_ORIG
      parameter(GPROP_SYMM_ORIG=20)
      integer GPROP_SYMM_AXIS
      parameter(GPROP_SYMM_AXIS=21)
      integer GPROP_STIFF_DAMP
      parameter(GPROP_STIFF_DAMP=23)
      integer GPROP_USER_NUM
      parameter(GPROP_USER_NUM=9)
      integer GPROP_MAX
      parameter(GPROP_MAX=30)
      integer GPROP_USERDIMENUM
      parameter(GPROP_USERDIMENUM=-1000000)
      integer GPROP_USERDIME
      parameter(GPROP_USERDIME=-2000000)
      integer GPROP_USERNAME
      parameter(GPROP_USERNAME=-3000000)
      integer GPROP_USERDATATYPE
      parameter(GPROP_USERDATATYPE=-4000000)
      integer GPROP_USERDATA
      parameter(GPROP_USERDATA=-5000000)
      integer GPROP_USERBASE
      parameter(GPROP_USERBASE=-5000000)
      integer GRIDFUN_NUMBER
      parameter(GRIDFUN_NUMBER=1)
      integer GRIDFUN_TOPOLOGY
      parameter(GRIDFUN_TOPOLOGY=2)
      integer GRIDFUN_ELEMNODE
      parameter(GRIDFUN_ELEMNODE=3)
      integer GRIDFUN_MAXELEMNODE
      parameter(GRIDFUN_MAXELEMNODE=4)
      integer GRIDFUN_COORDS
      parameter(GRIDFUN_COORDS=5)
      integer GRIDFUN_NODEASSOC
      parameter(GRIDFUN_NODEASSOC=6)
      integer GRIDFUN_ELEMASSOC
      parameter(GRIDFUN_ELEMASSOC=7)
      integer GRIDFUN_ELEMNUM
      parameter(GRIDFUN_ELEMNUM=8)
      integer GRIDFUN_ELEMCON
      parameter(GRIDFUN_ELEMCON=9)
      integer GRIDFUN_ELEMTOPO
      parameter(GRIDFUN_ELEMTOPO=10)
      integer GRIDFUN_ELEMADJ
      parameter(GRIDFUN_ELEMADJ=11)
      integer GRIDFUN_MAXNODEELEM
      parameter(GRIDFUN_MAXNODEELEM=12)
      integer GRIDFUN_NODEELEM
      parameter(GRIDFUN_NODEELEM=13)
      integer GRIDFUN_EXTENT
      parameter(GRIDFUN_EXTENT=14)
      integer GRIDFUN_ELEMCNN
      parameter(GRIDFUN_ELEMCNN=15)
      integer GRIDFUN_NODEADJ
      parameter(GRIDFUN_NODEADJ=16)
      integer GRIDFUN_COORDSDV
      parameter(GRIDFUN_COORDSDV=17)
      integer GRIDFUN_ERROR
      parameter(GRIDFUN_ERROR=19)
      integer GRIDFUN_NUMELEMNODE
      parameter(GRIDFUN_NUMELEMNODE=20)
      integer GRIDFUN_NUMNODEELEM
      parameter(GRIDFUN_NUMNODEELEM=21)
      integer GRIDFUN_ELEMCORN
      parameter(GRIDFUN_ELEMCORN=22)
      integer GRIDFUN_DIMENSION
      parameter(GRIDFUN_DIMENSION=24)
      integer GRIDFUN_EXTENTDV
      parameter(GRIDFUN_EXTENTDV=25)
      integer GRIDFUN_ELEMENTASSOC
      parameter(GRIDFUN_ELEMENTASSOC=26)
      integer GRIDFUN_NUMEIP
      parameter(GRIDFUN_NUMEIP=28)
      integer GRIDFUN_PARTNAME
      parameter(GRIDFUN_PARTNAME=31)
      integer GRIDFUN_NUMPARTNAME
      parameter(GRIDFUN_NUMPARTNAME=32)
      integer GRIDFUN_ITHPARTNAME
      parameter(GRIDFUN_ITHPARTNAME=33)
      integer GRIDFUN_LNGELEMNODE
      parameter(GRIDFUN_LNGELEMNODE=18)
      integer GRIDFUN_INDELEMNODE
      parameter(GRIDFUN_INDELEMNODE=23)
      integer GRIDFUN_NODENODE
      parameter(GRIDFUN_NODENODE=27)
      integer GRIDFUN_LNGEIP
      parameter(GRIDFUN_LNGEIP=29)
      integer GRIDFUN_INDEIP
      parameter(GRIDFUN_INDEIP=30)
      integer GRIDFUN_MAX
      parameter(GRIDFUN_MAX=34)
      integer GROUP_SET
      parameter(GROUP_SET=1)
      integer GROUP_INSERT
      parameter(GROUP_INSERT=2)
      integer GROUP_DELETE
      parameter(GROUP_DELETE=3)
      integer GROUP_MASK
      parameter(GROUP_MASK=4)
      integer HISTORY_ELEMNODE
      parameter(HISTORY_ELEMNODE=0)
      integer HISTORY_NODE
      parameter(HISTORY_NODE=1)
      integer HISTORY_ELEM
      parameter(HISTORY_ELEM=4)
      integer HISTORY_LISTWIDTH
      parameter(HISTORY_LISTWIDTH=1)
      integer HISTORY_LISTTRANSPOSE
      parameter(HISTORY_LISTTRANSPOSE=2)
      integer HISTORY_GLOBAL
      parameter(HISTORY_GLOBAL=0)
      integer HISTORY_LOCAL
      parameter(HISTORY_LOCAL=1)
      integer HISTORY_LOWPASS
      parameter(HISTORY_LOWPASS=0)
      integer HISTORY_TEXT_SUMMARY
      parameter(HISTORY_TEXT_SUMMARY=-5)
      integer HISTORY_TEXT_LISTING
      parameter(HISTORY_TEXT_LISTING=-6)
      integer ICASE_DOF
      parameter(ICASE_DOF=1)
      integer ICASE_DOFDOT
      parameter(ICASE_DOFDOT=2)
      integer ICASE_SPV_MAX
      parameter(ICASE_SPV_MAX=2)
      integer IDTRAN_MAXINDEX
      parameter(IDTRAN_MAXINDEX=0)
      integer IDTRAN_NUMINDICES
      parameter(IDTRAN_NUMINDICES=1)
      integer IDTRAN_NUMUNIQUE
      parameter(IDTRAN_NUMUNIQUE=2)
      integer IDTRAN_THRU
      parameter(IDTRAN_THRU=-1)
      integer IDTRAN_BY
      parameter(IDTRAN_BY=-2)
      integer LCASE_ADDFACTOR
      parameter(LCASE_ADDFACTOR=1)
      integer LCASE_FORCE
      parameter(LCASE_FORCE=1)
      integer LCASE_MOMENT
      parameter(LCASE_MOMENT=2)
      integer LCASE_HEAT
      parameter(LCASE_HEAT=3)
      integer LCASE_TEMP
      parameter(LCASE_TEMP=4)
      integer LCASE_CSCA
      parameter(LCASE_CSCA=5)
      integer LCASE_CVEC
      parameter(LCASE_CVEC=6)
      integer LCASE_CONC_FORCE
      parameter(LCASE_CONC_FORCE=1)
      integer LCASE_CONC_MOMENT
      parameter(LCASE_CONC_MOMENT=2)
      integer LCASE_CONC_HEAT
      parameter(LCASE_CONC_HEAT=3)
      integer LCASE_CONC_TEMP
      parameter(LCASE_CONC_TEMP=4)
      integer LCASE_CONC_SCA
      parameter(LCASE_CONC_SCA=5)
      integer LCASE_CONC_VEC
      parameter(LCASE_CONC_VEC=6)
      integer LCASE_CONC_MAX
      parameter(LCASE_CONC_MAX=6)
      integer LCASE_FORMOM
      parameter(LCASE_FORMOM=6)
      integer LCASE_TRAC
      parameter(LCASE_TRAC=1)
      integer LCASE_PRES
      parameter(LCASE_PRES=2)
      integer LCASE_TANGFORCE
      parameter(LCASE_TANGFORCE=3)
      integer LCASE_TANGMOMENT
      parameter(LCASE_TANGMOMENT=4)
      integer LCASE_HEATFLUX
      parameter(LCASE_HEATFLUX=5)
      integer LCASE_HEATCONV
      parameter(LCASE_HEATCONV=6)
      integer LCASE_DMOM
      parameter(LCASE_DMOM=7)
      integer LCASE_DSCA
      parameter(LCASE_DSCA=8)
      integer LCASE_DVEC
      parameter(LCASE_DVEC=9)
      integer LCASE_HEATRAD
      parameter(LCASE_HEATRAD=10)
      integer LCASE_HEATRAD_ABSORPTIVITY
      parameter(LCASE_HEATRAD_ABSORPTIVITY=11)
      integer LCASE_DIST_TRAC
      parameter(LCASE_DIST_TRAC=1)
      integer LCASE_DIST_PRES
      parameter(LCASE_DIST_PRES=2)
      integer LCASE_DIST_TANGFORCE
      parameter(LCASE_DIST_TANGFORCE=3)
      integer LCASE_DIST_TANGMOMENT
      parameter(LCASE_DIST_TANGMOMENT=4)
      integer LCASE_DIST_HEATFLUX
      parameter(LCASE_DIST_HEATFLUX=5)
      integer LCASE_DIST_HEATCONV
      parameter(LCASE_DIST_HEATCONV=6)
      integer LCASE_DIST_MOM
      parameter(LCASE_DIST_MOM=7)
      integer LCASE_DIST_SCA
      parameter(LCASE_DIST_SCA=8)
      integer LCASE_DIST_VEC
      parameter(LCASE_DIST_VEC=9)
      integer LCASE_DIST_HEATRAD
      parameter(LCASE_DIST_HEATRAD=10)
      integer LCASE_DIST_HEATRAD_ABSORPTIVITY
      parameter(LCASE_DIST_HEATRAD_ABSORPTIVITY=11)
      integer LCASE_DIST_MAX
      parameter(LCASE_DIST_MAX=11)
      integer LCASE_ACCLELEM
      parameter(LCASE_ACCLELEM=1)
      integer LCASE_HEATELEM
      parameter(LCASE_HEATELEM=2)
      integer LCASE_ELEM_ACCL
      parameter(LCASE_ELEM_ACCL=1)
      integer LCASE_ELEM_HEAT
      parameter(LCASE_ELEM_HEAT=2)
      integer LCASE_ELEM_MAX
      parameter(LCASE_ELEM_MAX=2)
      integer MCASE_MPC
      parameter(MCASE_MPC=1)
      integer MCASE_TIE
      parameter(MCASE_TIE=2)
      integer MCASE_PIN
      parameter(MCASE_PIN=3)
      integer MCASE_LINK
      parameter(MCASE_LINK=4)
      integer MCASE_BEAM
      parameter(MCASE_BEAM=5)
      integer MCASE_ELBOW
      parameter(MCASE_ELBOW=6)
      integer MCASE_MAX
      parameter(MCASE_MAX=7)
      integer MESHCON_GLOBALPROJECT
      parameter(MESHCON_GLOBALPROJECT=1)
      integer MESHCON_CONSISTENT
      parameter(MESHCON_CONSISTENT=100)
      integer MESHCON_PATCHPROJECT
      parameter(MESHCON_PATCHPROJECT=101)
      integer MESHCON_CHECKCLOSEDFRNT
      parameter(MESHCON_CHECKCLOSEDFRNT=102)
      integer MESHCON_EXTEND
      parameter(MESHCON_EXTEND=103)
      integer MESHCON_NORMAL
      parameter(MESHCON_NORMAL=104)
      integer MESHCON_CTRLSPACE
      parameter(MESHCON_CTRLSPACE=107)
      integer MESHCON_PATCHRESTRICT
      parameter(MESHCON_PATCHRESTRICT=108)
      integer MESHCON_VERBOSE
      parameter(MESHCON_VERBOSE=110)
      integer MESHCON_MAXNOED
      parameter(MESHCON_MAXNOED=12)
      integer MESHCON_STAT_ALL
      parameter(MESHCON_STAT_ALL=0)
      integer MESHCON_STAT_FREE
      parameter(MESHCON_STAT_FREE=-1)
      integer MESHCON_STAT_PRES
      parameter(MESHCON_STAT_PRES=-2)
      integer MESHCON_STAT_TEMP
      parameter(MESHCON_STAT_TEMP=-3)
      integer MESHCON_STAT_PREF
      parameter(MESHCON_STAT_PREF=-4)
      integer MESHCON_MINELEMANG
      parameter(MESHCON_MINELEMANG=1)
      integer MESHCON_MAXELEMLEN
      parameter(MESHCON_MAXELEMLEN=2)
      integer MESHCON_MINELEMLEN
      parameter(MESHCON_MINELEMLEN=3)
      integer MESHCON_MAXEDGELEN
      parameter(MESHCON_MAXEDGELEN=4)
      integer MESHCON_MINEDGELEN
      parameter(MESHCON_MINEDGELEN=5)
      integer MESHCON_MINFRNTLEN
      parameter(MESHCON_MINFRNTLEN=6)
      integer MESHCON_FRNTANG
      parameter(MESHCON_FRNTANG=7)
      integer MESHCON_CORNANG
      parameter(MESHCON_CORNANG=8)
      integer MESHCON_COLLREL
      parameter(MESHCON_COLLREL=9)
      integer MESHCON_COLLRELFLAG
      parameter(MESHCON_COLLRELFLAG=10)
      integer MESHCON_COLLMET
      parameter(MESHCON_COLLMET=11)
      integer MESHCON_COLLMETFLAG
      parameter(MESHCON_COLLMETFLAG=12)
      integer MESHCON_COLLANG
      parameter(MESHCON_COLLANG=13)
      integer MESHCON_COLLANGFLAG
      parameter(MESHCON_COLLANGFLAG=14)
      integer MESHCON_MAXMINELEMANG
      parameter(MESHCON_MAXMINELEMANG=15)
      integer MESHCON_COLLIMPFLAG
      parameter(MESHCON_COLLIMPFLAG=16)
      integer MESHCON_GROWTHRATE
      parameter(MESHCON_GROWTHRATE=17)
      integer MESHCON_TINYLEN
      parameter(MESHCON_TINYLEN=18)
      integer MESHCON_MAXELEMANG
      parameter(MESHCON_MAXELEMANG=19)
      integer MESHCON_ELEMHEAPSIZEFACT
      parameter(MESHCON_ELEMHEAPSIZEFACT=20)
      integer MESHCON_EDGEHEAPSIZEFACT
      parameter(MESHCON_EDGEHEAPSIZEFACT=21)
      integer MESHCON_EDGEHEAPPRESONLY
      parameter(MESHCON_EDGEHEAPPRESONLY=22)
      integer MESHCON_COLLTOPOFLAG
      parameter(MESHCON_COLLTOPOFLAG=23)
      integer MESHCON_COLLANGIMPFLAG
      parameter(MESHCON_COLLANGIMPFLAG=24)
      integer MESHCON_RECOVERCOS
      parameter(MESHCON_RECOVERCOS=25)
      integer MESHCON_COLLLENMAX
      parameter(MESHCON_COLLLENMAX=26)
      integer MESHCON_COLLLENMIN
      parameter(MESHCON_COLLLENMIN=27)
      integer MESHCON_COLLLENFLAG
      parameter(MESHCON_COLLLENFLAG=28)
      integer MESHCON_COLLNORMANG
      parameter(MESHCON_COLLNORMANG=29)
      integer MESHCON_COLLNORMANGFLAG
      parameter(MESHCON_COLLNORMANGFLAG=30)
      integer MESHCON_FUNSIZINGMIN
      parameter(MESHCON_FUNSIZINGMIN=31)
      integer MESHCON_WALKFACETOL
      parameter(MESHCON_WALKFACETOL=32)
      integer MESHCON_SWAPNORMANG
      parameter(MESHCON_SWAPNORMANG=33)
      integer MESHCON_SWAPNORMANGFLAG
      parameter(MESHCON_SWAPNORMANGFLAG=34)
      integer MESHCON_FUNSIZINGLEGACY
      parameter(MESHCON_FUNSIZINGLEGACY=35)
      integer MESHCON_MAXNMT
      parameter(MESHCON_MAXNMT=100)
      integer MESHCON_MAXNDG
      parameter(MESHCON_MAXNDG=10000)
      integer VIS_MESHMETRIC_COMPARISON_NONE
      parameter(VIS_MESHMETRIC_COMPARISON_NONE=0)
      integer VIS_MESHMETRIC_COMPARISON_LESSTHANOREQUAL
      parameter(VIS_MESHMETRIC_COMPARISON_LESSTHANOREQUAL=1)
      integer VIS_MESHMETRIC_COMPARISON_GREATERTHANOREQUAL
      parameter(VIS_MESHMETRIC_COMPARISON_GREATERTHANOREQUAL=2)
      integer VIS_MESHMETRIC_COMPARISON_EQUALWITHINTOLERANCE
      parameter(VIS_MESHMETRIC_COMPARISON_EQUALWITHINTOLERANCE=3)
      integer VIS_MESHMETRIC_COMPARISON_MAX
      parameter(VIS_MESHMETRIC_COMPARISON_MAX=4)
      integer MODEL_CHECKJACOBIAN
      parameter(MODEL_CHECKJACOBIAN=1)
      integer MODEL_NUMCHECKSTRING
      parameter(MODEL_NUMCHECKSTRING=-1)
      integer MODEL_CHECKSTRING
      parameter(MODEL_CHECKSTRING=0)
      integer MODEL_CHECKSTRING0
      parameter(MODEL_CHECKSTRING0=0)
      integer MODEL_CHECKSTRING1
      parameter(MODEL_CHECKSTRING1=1)
      integer MODEL_CHECKSTRING2
      parameter(MODEL_CHECKSTRING2=2)
      integer MODEL_CHECKSTRING3
      parameter(MODEL_CHECKSTRING3=3)
      integer MODEL_CHECKSTRING4
      parameter(MODEL_CHECKSTRING4=4)
      integer VIS_MODELCHK_ACTION_CHECK
      parameter(VIS_MODELCHK_ACTION_CHECK=1)
      integer VIS_MODELCHK_ACTION_PROCESS
      parameter(VIS_MODELCHK_ACTION_PROCESS=2)
      integer VIS_MODELCHK_CIRC_DEPENDENCY
      parameter(VIS_MODELCHK_CIRC_DEPENDENCY=1)
      integer MPROP_360
      parameter(MPROP_360=1)
      integer MPROP_UNDEFINED
      parameter(MPROP_UNDEFINED=0)
      integer MPROP_VALUE
      parameter(MPROP_VALUE=1)
      integer MPROP_IDENTIFIER
      parameter(MPROP_IDENTIFIER=2)
      integer MPROP_HYPER_N
      parameter(MPROP_HYPER_N=31)
      integer MPROP_PLASTICITY_HARDENING_TYPE
      parameter(MPROP_PLASTICITY_HARDENING_TYPE=40)
      integer MPROP_PLASTICITY_TABULAR_DATA
      parameter(MPROP_PLASTICITY_TABULAR_DATA=41)
      integer MPROP_DENSITY
      parameter(MPROP_DENSITY=0)
      integer MPROP_E
      parameter(MPROP_E=1)
      integer MPROP_NU
      parameter(MPROP_NU=2)
      integer MPROP_G
      parameter(MPROP_G=3)
      integer MPROP_A
      parameter(MPROP_A=4)
      integer MPROP_GE
      parameter(MPROP_GE=5)
      integer MPROP_TREF
      parameter(MPROP_TREF=6)
      integer MPROP_EORT
      parameter(MPROP_EORT=7)
      integer MPROP_NUORT
      parameter(MPROP_NUORT=8)
      integer MPROP_GORT
      parameter(MPROP_GORT=9)
      integer MPROP_AORT
      parameter(MPROP_AORT=10)
      integer MPROP_DMAT
      parameter(MPROP_DMAT=11)
      integer MPROP_AVEC
      parameter(MPROP_AVEC=12)
      integer MPROP_SXT
      parameter(MPROP_SXT=13)
      integer MPROP_SXC
      parameter(MPROP_SXC=14)
      integer MPROP_SYT
      parameter(MPROP_SYT=15)
      integer MPROP_SYC
      parameter(MPROP_SYC=16)
      integer MPROP_SHR
      parameter(MPROP_SHR=17)
      integer MPROP_K
      parameter(MPROP_K=19)
      integer MPROP_CP
      parameter(MPROP_CP=20)
      integer MPROP_FILM
      parameter(MPROP_FILM=21)
      integer MPROP_HGEN
      parameter(MPROP_HGEN=22)
      integer MPROP_EREF
      parameter(MPROP_EREF=23)
      integer MPROP_EMIS
      parameter(MPROP_EMIS=24)
      integer MPROP_KMAT
      parameter(MPROP_KMAT=26)
      integer MPROP_BULK
      parameter(MPROP_BULK=27)
      integer MPROP_SOUND
      parameter(MPROP_SOUND=28)
      integer MPROP_HYPER_CIJ
      parameter(MPROP_HYPER_CIJ=29)
      integer MPROP_HYPER_DI
      parameter(MPROP_HYPER_DI=30)
      integer MPROP_F12
      parameter(MPROP_F12=32)
      integer MPROP_VISCOSITY
      parameter(MPROP_VISCOSITY=33)
      integer MPROP_EXT
      parameter(MPROP_EXT=34)
      integer MPROP_EXC
      parameter(MPROP_EXC=35)
      integer MPROP_EYT
      parameter(MPROP_EYT=36)
      integer MPROP_EYC
      parameter(MPROP_EYC=37)
      integer MPROP_EHR
      parameter(MPROP_EHR=38)
      integer MPROP_USER
      parameter(MPROP_USER=39)
      integer MPROP_ALLOWTYPE
      parameter(MPROP_ALLOWTYPE=18)
      integer MPROP_MAX
      parameter(MPROP_MAX=42)
      integer NASFWT_RELATIVEPATH
      parameter(NASFWT_RELATIVEPATH=1)
      integer PNTLOC_CLOSEST
      parameter(PNTLOC_CLOSEST=1)
      integer PNTLOC_LOWEST
      parameter(PNTLOC_LOWEST=2)
      integer PNTLOC_ANY
      parameter(PNTLOC_ANY=3)
      integer RANGE_MAX_STATES
      parameter(RANGE_MAX_STATES=16)
      integer RBODY_TIE
      parameter(RBODY_TIE=1)
      integer RBODY_PIN
      parameter(RBODY_PIN=2)
      integer RBODY_UNDEFINED
      parameter(RBODY_UNDEFINED=0)
      integer RBODY_VALUE
      parameter(RBODY_VALUE=1)
      integer RBODY_CURVE
      parameter(RBODY_CURVE=2)
      integer RBODY_PID
      parameter(RBODY_PID=0)
      integer RBODY_ROTATION_AXIS
      parameter(RBODY_ROTATION_AXIS=1)
      integer RBODY_MAX
      parameter(RBODY_MAX=2)
      integer RCASE_FREE
      parameter(RCASE_FREE=0)
      integer RCASE_FIXED
      parameter(RCASE_FIXED=1)
      integer RCASE_APPLIED
      parameter(RCASE_APPLIED=2)
      integer RCASE_MASTER
      parameter(RCASE_MASTER=3)
      integer RCASE_DOF
      parameter(RCASE_DOF=1)
      integer RCASE_DOFDOT
      parameter(RCASE_DOFDOT=2)
      integer RCASE_DOFDOTDOT
      parameter(RCASE_DOFDOTDOT=3)
      integer RPROP_UNDEFINED
      parameter(RPROP_UNDEFINED=0)
      integer RPROP_VALUE
      parameter(RPROP_VALUE=1)
      integer RPROP_LOADFACTOR
      parameter(RPROP_LOADFACTOR=0)
      integer RPROP_FREQUENCY
      parameter(RPROP_FREQUENCY=1)
      integer RPROP_EIGENVALUE
      parameter(RPROP_EIGENVALUE=2)
      integer RPROP_TIME
      parameter(RPROP_TIME=3)
      integer RPROP_TIMESTEP
      parameter(RPROP_TIMESTEP=4)
      integer RPROP_AMPLITUDE
      parameter(RPROP_AMPLITUDE=5)
      integer RPROP_PHASE
      parameter(RPROP_PHASE=6)
      integer RPROP_GENERALIZEDMASS
      parameter(RPROP_GENERALIZEDMASS=7)
      integer RPROP_LOADCASE
      parameter(RPROP_LOADCASE=8)
      integer RPROP_CONTENTS
      parameter(RPROP_CONTENTS=9)
      integer RPROP_DATATYPE
      parameter(RPROP_DATATYPE=10)
      integer RPROP_COMPLEX
      parameter(RPROP_COMPLEX=11)
      integer RPROP_TITLE
      parameter(RPROP_TITLE=12)
      integer RPROP_SUBTITLE
      parameter(RPROP_SUBTITLE=13)
      integer RPROP_SUBTITLE1
      parameter(RPROP_SUBTITLE1=14)
      integer RPROP_SUBTITLE2
      parameter(RPROP_SUBTITLE2=15)
      integer RPROP_SUBTITLE3
      parameter(RPROP_SUBTITLE3=16)
      integer RPROP_SUBTITLE4
      parameter(RPROP_SUBTITLE4=17)
      integer RPROP_LABEL
      parameter(RPROP_LABEL=18)
      integer RPROP_SUBLABEL
      parameter(RPROP_SUBLABEL=19)
      integer RPROP_LINK_ROTANG
      parameter(RPROP_LINK_ROTANG=20)
      integer RPROP_LINK_CID
      parameter(RPROP_LINK_CID=21)
      integer RPROP_LINK_COMPLEX
      parameter(RPROP_LINK_COMPLEX=22)
      integer RPROP_LINK_SECTION
      parameter(RPROP_LINK_SECTION=23)
      integer RPROP_LINK_LAYERS
      parameter(RPROP_LINK_LAYERS=24)
      integer RPROP_STRAINTYPE
      parameter(RPROP_STRAINTYPE=25)
      integer RPROP_DATASOURCE
      parameter(RPROP_DATASOURCE=26)
      integer RPROP_CATEGORY
      parameter(RPROP_CATEGORY=27)
      integer RPROP_LINK_ENTDOF
      parameter(RPROP_LINK_ENTDOF=28)
      integer RPROP_LINK_INDEX
      parameter(RPROP_LINK_INDEX=29)
      integer RPROP_LABEL1
      parameter(RPROP_LABEL1=30)
      integer RPROP_ESSTEYR_NT11_EXCEPTION
      parameter(RPROP_ESSTEYR_NT11_EXCEPTION=31)
      integer RPROP_SCALAR1
      parameter(RPROP_SCALAR1=32)
      integer RPROP_SCALAR2
      parameter(RPROP_SCALAR2=33)
      integer RPROP_SCALAR3
      parameter(RPROP_SCALAR3=34)
      integer RPROP_CYCLICCSYSID
      parameter(RPROP_CYCLICCSYSID=35)
      integer RPROP_NONLINEAR
      parameter(RPROP_NONLINEAR=36)
      integer RPROP_MAX
      parameter(RPROP_MAX=37)
      integer SPACE_LINE_INFINITE
      parameter(SPACE_LINE_INFINITE=2)
      integer SPACE_PLANE_INFINITE
      parameter(SPACE_PLANE_INFINITE=6)
      integer SPACE_DEPTH
      parameter(SPACE_DEPTH=11)
      integer SPACE_RESOLUTION
      parameter(SPACE_RESOLUTION=12)
      integer SPACE_RESOLUTION_ADAPT
      parameter(SPACE_RESOLUTION_ADAPT=13)
      integer SPACE_DECOMP_BLOCK
      parameter(SPACE_DECOMP_BLOCK=31)
      integer SPACE_DECOMP_ADAPT_BLOCK
      parameter(SPACE_DECOMP_ADAPT_BLOCK=32)
      integer SPACE_TOLERANCE
      parameter(SPACE_TOLERANCE=50)
      integer SPACE_REFINE
      parameter(SPACE_REFINE=51)
      integer SPACE_NODE_SEARCH
      parameter(SPACE_NODE_SEARCH=60)
      integer SPACE_NODE_LOWEST
      parameter(SPACE_NODE_LOWEST=61)
      integer SPACE_NODE_CLOSEST
      parameter(SPACE_NODE_CLOSEST=62)
      integer SPACE_NODE_ANY
      parameter(SPACE_NODE_ANY=63)
      integer SPACE_TREE
      parameter(SPACE_TREE=70)
      integer SPACE_TREE_OCTREE
      parameter(SPACE_TREE_OCTREE=71)
      integer SPACE_TREE_ADTREE
      parameter(SPACE_TREE_ADTREE=72)
      integer SYS_SOL_NONE
      parameter(SYS_SOL_NONE=0)
      integer SYS_SOL_STATIC
      parameter(SYS_SOL_STATIC=1)
      integer SYS_SOL_VIBRATION
      parameter(SYS_SOL_VIBRATION=2)
      integer SYS_SOL_BUCKLING
      parameter(SYS_SOL_BUCKLING=3)
      integer SYS_SOL_TRANSIENT
      parameter(SYS_SOL_TRANSIENT=4)
      integer SYS_SOL_SUPERELEMENT
      parameter(SYS_SOL_SUPERELEMENT=5)
      integer SYS_SOL_FREQRESPONSE
      parameter(SYS_SOL_FREQRESPONSE=6)
      integer SYS_SOL_COMPLEXEIGEN
      parameter(SYS_SOL_COMPLEXEIGEN=7)
      integer SYS_SOL_QUASISTATIC
      parameter(SYS_SOL_QUASISTATIC=8)
      integer SYS_SOL_OUTPUT
      parameter(SYS_SOL_OUTPUT=9)
      integer SYS_SOL_SINGULAR
      parameter(SYS_SOL_SINGULAR=10)
      integer SYS_SOL_MAX
      parameter(SYS_SOL_MAX=10)
      integer SPROP_UNDEFINED
      parameter(SPROP_UNDEFINED=0)
      integer SPROP_VALUE
      parameter(SPROP_VALUE=1)
      integer SPROP_IDENTIFIER
      parameter(SPROP_IDENTIFIER=2)
      integer SPROP_ANALYSIS
      parameter(SPROP_ANALYSIS=0)
      integer SPROP_CASEID
      parameter(SPROP_CASEID=22)
      integer SPROP_EIGEN_NUM
      parameter(SPROP_EIGEN_NUM=1)
      integer SPROP_EIGEN_TYPE
      parameter(SPROP_EIGEN_TYPE=34)
      integer SPROP_EIGEN_SOLVER
      parameter(SPROP_EIGEN_SOLVER=38)
      integer SPROP_EIGEN_CASE
      parameter(SPROP_EIGEN_CASE=83)
      integer SPROP_LCASE_NUM
      parameter(SPROP_LCASE_NUM=2)
      integer SPROP_LCASE
      parameter(SPROP_LCASE=3)
      integer SPROP_LCASE_SENSORNODE
      parameter(SPROP_LCASE_SENSORNODE=62)
      integer SPROP_LCASE_SENSORDOF
      parameter(SPROP_LCASE_SENSORDOF=63)
      integer SPROP_EIGEN_NORM
      parameter(SPROP_EIGEN_NORM=39)
      integer SPROP_EIGEN_SIZE
      parameter(SPROP_EIGEN_SIZE=40)
      integer SPROP_EIGEN_STEPS
      parameter(SPROP_EIGEN_STEPS=41)
      integer SPROP_LCASE_TCURVE
      parameter(SPROP_LCASE_TCURVE=23)
      integer SPROP_LCASE_TREF
      parameter(SPROP_LCASE_TREF=25)
      integer SPROP_LCASE_MODE
      parameter(SPROP_LCASE_MODE=60)
      integer SPROP_LCASE_UNIT
      parameter(SPROP_LCASE_UNIT=76)
      integer SPROP_LCASE_TINIT
      parameter(SPROP_LCASE_TINIT=85)
      integer SPROP_TIME_STEPFIXED
      parameter(SPROP_TIME_STEPFIXED=56)
      integer SPROP_RCASE
      parameter(SPROP_RCASE=8)
      integer SPROP_MCASE
      parameter(SPROP_MCASE=18)
      integer SPROP_ICASE
      parameter(SPROP_ICASE=10)
      integer SPROP_THERMALSTRAIN
      parameter(SPROP_THERMALSTRAIN=14)
      integer SPROP_LARGESTRAIN
      parameter(SPROP_LARGESTRAIN=15)
      integer SPROP_NONLINEAR
      parameter(SPROP_NONLINEAR=16)
      integer SPROP_MASSDIAG
      parameter(SPROP_MASSDIAG=17)
      integer SPROP_INERTIARELIEF
      parameter(SPROP_INERTIARELIEF=24)
      integer SPROP_PRESTRESS
      parameter(SPROP_PRESTRESS=35)
      integer SPROP_PERTURBATION
      parameter(SPROP_PERTURBATION=36)
      integer SPROP_SAVE_FREQ
      parameter(SPROP_SAVE_FREQ=26)
      integer SPROP_RESFILE_FREQ
      parameter(SPROP_RESFILE_FREQ=26)
      integer SPROP_HISTFILE_FREQ
      parameter(SPROP_HISTFILE_FREQ=27)
      integer SPROP_COUPLED_NUM
      parameter(SPROP_COUPLED_NUM=28)
      integer SPROP_COUPLED
      parameter(SPROP_COUPLED=29)
      integer SPROP_RESFILE_NUM
      parameter(SPROP_RESFILE_NUM=30)
      integer SPROP_RESFILE
      parameter(SPROP_RESFILE=31)
      integer SPROP_RESFILE_QUA1
      parameter(SPROP_RESFILE_QUA1=50)
      integer SPROP_RESFILE_QUA2
      parameter(SPROP_RESFILE_QUA2=51)
      integer SPROP_RESFILE_NSET
      parameter(SPROP_RESFILE_NSET=77)
      integer SPROP_RESFILE_ESET
      parameter(SPROP_RESFILE_ESET=78)
      integer SPROP_RESPRINT_NUM
      parameter(SPROP_RESPRINT_NUM=32)
      integer SPROP_RESPRINT
      parameter(SPROP_RESPRINT=33)
      integer SPROP_RESPRINT_QUA1
      parameter(SPROP_RESPRINT_QUA1=53)
      integer SPROP_RESPRINT_QUA2
      parameter(SPROP_RESPRINT_QUA2=54)
      integer SPROP_LHSITER_FREQ
      parameter(SPROP_LHSITER_FREQ=46)
      integer SPROP_LHSSTEP_FREQ
      parameter(SPROP_LHSSTEP_FREQ=47)
      integer SPROP_LHSFORM
      parameter(SPROP_LHSFORM=81)
      integer SPROP_ITERMAX
      parameter(SPROP_ITERMAX=48)
      integer SPROP_ESET_DELETE
      parameter(SPROP_ESET_DELETE=61)
      integer SPROP_HISTFILE_NUM
      parameter(SPROP_HISTFILE_NUM=64)
      integer SPROP_HISTFILE
      parameter(SPROP_HISTFILE=65)
      integer SPROP_HISTFILE_SET
      parameter(SPROP_HISTFILE_SET=66)
      integer SPROP_MODALDAMP_TCURVE
      parameter(SPROP_MODALDAMP_TCURVE=67)
      integer SPROP_MODALDAMP_TYPE
      parameter(SPROP_MODALDAMP_TYPE=68)
      integer SPROP_FREQ_TYPE
      parameter(SPROP_FREQ_TYPE=69)
      integer SPROP_FREQ_NUM
      parameter(SPROP_FREQ_NUM=70)
      integer SPROP_FREQ_NPNTS
      parameter(SPROP_FREQ_NPNTS=73)
      integer SPROP_FREQRESPONSE_MODAL
      parameter(SPROP_FREQRESPONSE_MODAL=75)
      integer SPROP_FOURIER_NUM
      parameter(SPROP_FOURIER_NUM=79)
      integer SPROP_FOURIER
      parameter(SPROP_FOURIER=80)
      integer SPROP_NSM_ID
      parameter(SPROP_NSM_ID=84)
      integer SPROP_MAX_INCREMENT_STEP
      parameter(SPROP_MAX_INCREMENT_STEP=89)
      integer SPROP_CONTACT_NUM
      parameter(SPROP_CONTACT_NUM=90)
      integer SPROP_CONTACT_CASE
      parameter(SPROP_CONTACT_CASE=91)
      integer SPROP_RESEXPORT_NUM
      parameter(SPROP_RESEXPORT_NUM=92)
      integer SPROP_RESEXPORT
      parameter(SPROP_RESEXPORT=93)
      integer SPROP_RESIMPORT_NUM
      parameter(SPROP_RESIMPORT_NUM=95)
      integer SPROP_RESIMPORT
      parameter(SPROP_RESIMPORT=96)
      integer SPROP_USER_NUM
      parameter(SPROP_USER_NUM=59)
      integer SPROP_EIGEN_LOWER
      parameter(SPROP_EIGEN_LOWER=11)
      integer SPROP_EIGEN_UPPER
      parameter(SPROP_EIGEN_UPPER=12)
      integer SPROP_EIGEN_SHIFT
      parameter(SPROP_EIGEN_SHIFT=13)
      integer SPROP_LCASE_FACTOR
      parameter(SPROP_LCASE_FACTOR=4)
      integer SPROP_TIME_INIT
      parameter(SPROP_TIME_INIT=5)
      integer SPROP_TIME_STEP
      parameter(SPROP_TIME_STEP=6)
      integer SPROP_TIME_TERM
      parameter(SPROP_TIME_TERM=7)
      integer SPROP_TIME_STEPMIN
      parameter(SPROP_TIME_STEPMIN=42)
      integer SPROP_TIME_STEPMAX
      parameter(SPROP_TIME_STEPMAX=43)
      integer SPROP_RCASE_FACTOR
      parameter(SPROP_RCASE_FACTOR=9)
      integer SPROP_MASS_FACTOR
      parameter(SPROP_MASS_FACTOR=37)
      integer SPROP_DAMP_ALPHA
      parameter(SPROP_DAMP_ALPHA=57)
      integer SPROP_DAMP_BETA
      parameter(SPROP_DAMP_BETA=58)
      integer SPROP_FTOL
      parameter(SPROP_FTOL=44)
      integer SPROP_UTOL
      parameter(SPROP_UTOL=45)
      integer SPROP_ETOL
      parameter(SPROP_ETOL=87)
      integer SPROP_FREQ_LOWER
      parameter(SPROP_FREQ_LOWER=71)
      integer SPROP_FREQ_UPPER
      parameter(SPROP_FREQ_UPPER=72)
      integer SPROP_FREQ_BIAS
      parameter(SPROP_FREQ_BIAS=74)
      integer SPROP_TEMPMAXVARIATION
      parameter(SPROP_TEMPMAXVARIATION=86)
      integer SPROP_DRILLFACTOR
      parameter(SPROP_DRILLFACTOR=88)
      integer SPROP_TITLE
      parameter(SPROP_TITLE=19)
      integer SPROP_SUBTITLE
      parameter(SPROP_SUBTITLE=20)
      integer SPROP_LABEL
      parameter(SPROP_LABEL=21)
      integer SPROP_SUBLABEL
      parameter(SPROP_SUBLABEL=49)
      integer SPROP_RESFILE_CQUA
      parameter(SPROP_RESFILE_CQUA=52)
      integer SPROP_RESPRINT_CQUA
      parameter(SPROP_RESPRINT_CQUA=55)
      integer SPROP_DESTINATIONFILE
      parameter(SPROP_DESTINATIONFILE=82)
      integer SPROP_RESIMPORTFILE
      parameter(SPROP_RESIMPORTFILE=94)
      integer SPROP_MAX
      parameter(SPROP_MAX=97)
      integer SPROP_USERDIMENUM
      parameter(SPROP_USERDIMENUM=-1000000)
      integer SPROP_USERDIME
      parameter(SPROP_USERDIME=-2000000)
      integer SPROP_USERNAME
      parameter(SPROP_USERNAME=-3000000)
      integer SPROP_USERDATATYPE
      parameter(SPROP_USERDATATYPE=-4000000)
      integer SPROP_USERDATA
      parameter(SPROP_USERDATA=-5000000)
      integer SPROP_USERBASE
      parameter(SPROP_USERBASE=-5000000)
      integer SPROP_360
      parameter(SPROP_360=1)
      integer SPROP_FREQ_RANGE
      parameter(SPROP_FREQ_RANGE=2)
      integer SPROP_FREQ_EIGEN
      parameter(SPROP_FREQ_EIGEN=3)
      integer SPROP_FREQ_SPREAD
      parameter(SPROP_FREQ_SPREAD=4)
      integer SPROP_MODALDAMP_CRITFRAC
      parameter(SPROP_MODALDAMP_CRITFRAC=5)
      integer SPROP_MODALDAMP_RAYLEIGH
      parameter(SPROP_MODALDAMP_RAYLEIGH=6)
      integer SPROP_FREQ_RANDOM
      parameter(SPROP_FREQ_RANDOM=7)
      integer STATE_ELEMNODE
      parameter(STATE_ELEMNODE=0)
      integer STATE_NODE
      parameter(STATE_NODE=1)
      integer STATE_ELEM
      parameter(STATE_ELEM=4)
      integer STATE_SORTHIGHLOW
      parameter(STATE_SORTHIGHLOW=2)
      integer STATE_MAPNONZERO
      parameter(STATE_MAPNONZERO=3)
      integer STATE_SORTABSVALUE
      parameter(STATE_SORTABSVALUE=4)
      integer STATE_SORTELEMNODEAVE
      parameter(STATE_SORTELEMNODEAVE=5)
      integer STATE_MAPELEM
      parameter(STATE_MAPELEM=6)
      integer STATE_MAPNODE
      parameter(STATE_MAPNODE=7)
      integer STATE_EXTENTNONZERO
      parameter(STATE_EXTENTNONZERO=15)
      integer STATE_LISTWIDTH
      parameter(STATE_LISTWIDTH=16)
      integer STATE_MAPDEFINED
      parameter(STATE_MAPDEFINED=17)
      integer STATE_MIDSIDE
      parameter(STATE_MIDSIDE=18)
      integer STATE_MAPAVE
      parameter(STATE_MAPAVE=8)
      integer STATE_MAPMIN
      parameter(STATE_MAPMIN=9)
      integer STATE_MAPMAX
      parameter(STATE_MAPMAX=10)
      integer STATE_MAPABSMIN
      parameter(STATE_MAPABSMIN=11)
      integer STATE_MAPABSMAX
      parameter(STATE_MAPABSMAX=12)
      integer STATE_MAPCENT
      parameter(STATE_MAPCENT=13)
      integer STATE_MAPGEOM
      parameter(STATE_MAPGEOM=1)
      integer STATE_NODE_MAPAVE
      parameter(STATE_NODE_MAPAVE=1)
      integer STATE_NODE_MAPMIN
      parameter(STATE_NODE_MAPMIN=1)
      integer STATE_NODE_MAPMAX
      parameter(STATE_NODE_MAPMAX=1)
      integer STATE_NODE_MAPABSMIN
      parameter(STATE_NODE_MAPABSMIN=1)
      integer STATE_NODE_MAPABSMAX
      parameter(STATE_NODE_MAPABSMAX=1)
      integer STATE_MAPDIFF
      parameter(STATE_MAPDIFF=14)
      integer STATE_MIDSIDEAVE
      parameter(STATE_MIDSIDEAVE=19)
      integer STATE_MIDSIDECLAMP
      parameter(STATE_MIDSIDECLAMP=20)
      integer STATE_PATRAN_NEUTRAL
      parameter(STATE_PATRAN_NEUTRAL=-4)
      integer STATE_TEXT_SUMMARY
      parameter(STATE_TEXT_SUMMARY=-5)
      integer STATE_TEXT_LISTING
      parameter(STATE_TEXT_LISTING=-6)
      integer STATE_TEXT_SUMMMAX
      parameter(STATE_TEXT_SUMMMAX=-7)
      integer STATE_EXTENT
      parameter(STATE_EXTENT=7)
      integer STATE_DEFINED
      parameter(STATE_DEFINED=8)
      integer STATE_NONZERO
      parameter(STATE_NONZERO=9)
      integer STATE_OUTBOUND
      parameter(STATE_OUTBOUND=10)
      integer STATE_LOCALMIN
      parameter(STATE_LOCALMIN=11)
      integer STATE_LOCALMAX
      parameter(STATE_LOCALMAX=12)
      integer STATE_LOCALMINMAX
      parameter(STATE_LOCALMINMAX=13)
      integer STATE_EQUAL
      parameter(STATE_EQUAL=0)
      integer STATE_PLUSEQUAL
      parameter(STATE_PLUSEQUAL=1)
      integer STATE_MINUSEQUAL
      parameter(STATE_MINUSEQUAL=2)
      integer STATE_MULTIPLYEQUAL
      parameter(STATE_MULTIPLYEQUAL=3)
      integer STATE_DIVIDEEQUAL
      parameter(STATE_DIVIDEEQUAL=4)
      integer STATE_GRAD
      parameter(STATE_GRAD=0)
      integer STATE_GRADNORM
      parameter(STATE_GRADNORM=1)
      integer STATE_DIV
      parameter(STATE_DIV=2)
      integer STATE_CURL
      parameter(STATE_CURL=3)
      integer STATE_STRAIN
      parameter(STATE_STRAIN=4)
      integer STATE_VECTORGRAD
      parameter(STATE_VECTORGRAD=5)
      integer STATE_IDENTITY
      parameter(STATE_IDENTITY=0)
      integer STATE_SIN
      parameter(STATE_SIN=1)
      integer STATE_COS
      parameter(STATE_COS=2)
      integer STATE_TAN
      parameter(STATE_TAN=3)
      integer STATE_ASIN
      parameter(STATE_ASIN=4)
      integer STATE_ACOS
      parameter(STATE_ACOS=5)
      integer STATE_ATAN
      parameter(STATE_ATAN=6)
      integer STATE_SQRT
      parameter(STATE_SQRT=7)
      integer STATE_LOG
      parameter(STATE_LOG=8)
      integer STATE_EXP
      parameter(STATE_EXP=9)
      integer STATE_ABS
      parameter(STATE_ABS=10)
      integer STATE_RECIPROCAL
      parameter(STATE_RECIPROCAL=11)
      integer STATE_UNITY
      parameter(STATE_UNITY=12)
      integer STATE_MIN
      parameter(STATE_MIN=1)
      integer STATE_MAX
      parameter(STATE_MAX=2)
      integer STATE_AVERAGE
      parameter(STATE_AVERAGE=3)
      integer STATE_CROSS
      parameter(STATE_CROSS=4)
      integer STATE_DOT
      parameter(STATE_DOT=5)
      integer STATE_SUM
      parameter(STATE_SUM=6)
      integer STATE_DEMO_BEAM
      parameter(STATE_DEMO_BEAM=1)
      integer STATE_DEMO_PLATE
      parameter(STATE_DEMO_PLATE=2)
      integer STATE_DEMO_COORDS
      parameter(STATE_DEMO_COORDS=3)
      integer STATE_DEMO_X
      parameter(STATE_DEMO_X=4)
      integer STATE_DEMO_Y
      parameter(STATE_DEMO_Y=5)
      integer STATE_DEMO_Z
      parameter(STATE_DEMO_Z=6)
      integer STATE_GLOBAL
      parameter(STATE_GLOBAL=0)
      integer STATE_LOCAL
      parameter(STATE_LOCAL=1)
      integer STATE_ROTANG
      parameter(STATE_ROTANG=2)
      integer STATE_MATERIAL
      parameter(STATE_MATERIAL=3)
      integer STATE_ISINTEGERDATA
      parameter(STATE_ISINTEGERDATA=0)
      integer STATE_CYCLICSYSTEMID
      parameter(STATE_CYCLICSYSTEMID=1)
      integer STATE_MISSINGLINKCSYS
      parameter(STATE_MISSINGLINKCSYS=2)
      integer STATE_SYSTEMDEFAULTTOROTANG
      parameter(STATE_SYSTEMDEFAULTTOROTANG=3)
      integer STATE_AVOIDTRANSFORMATION
      parameter(STATE_AVOIDTRANSFORMATION=4)
      integer STATE_SCALEDDIRCOS
      parameter(STATE_SCALEDDIRCOS=5)
      integer SYSMAT_VECTOR
      parameter(SYSMAT_VECTOR=0)
      integer SYSMAT_MATRIX
      parameter(SYSMAT_MATRIX=1)
      integer SYSMAT_MATRIX_DIAG
      parameter(SYSMAT_MATRIX_DIAG=2)
      integer SYSMAT_MATRIX_SPARSE
      parameter(SYSMAT_MATRIX_SPARSE=3)
      integer SYSMAT_TECH
      parameter(SYSMAT_TECH=0)
      integer SYSMAT_MAXITER
      parameter(SYSMAT_MAXITER=1)
      integer SYSMAT_TOL
      parameter(SYSMAT_TOL=0)
      integer SYSMAT_TECH_DIRECT
      parameter(SYSMAT_TECH_DIRECT=0)
      integer SYSMAT_TECH_CONJGRAD
      parameter(SYSMAT_TECH_CONJGRAD=1)
      integer SYSMAT_NUMITER
      parameter(SYSMAT_NUMITER=0)
      integer SYSMAT_CONV
      parameter(SYSMAT_CONV=0)
      integer SYSMAT_FUN_PROD
      parameter(SYSMAT_FUN_PROD=0)
      integer TCURVE_PWLINEAR
      parameter(TCURVE_PWLINEAR=0)
      integer TCURVE_EQUATION
      parameter(TCURVE_EQUATION=1)
      integer TCURVE_EXPRESSION
      parameter(TCURVE_EXPRESSION=2)
      integer TCURVE_SCALE
      parameter(TCURVE_SCALE=1)
      integer TCURVE_SHIFT
      parameter(TCURVE_SHIFT=2)
      integer TCURVE_DIVISOR
      parameter(TCURVE_DIVISOR=3)
      integer TCURVE_OFFSET
      parameter(TCURVE_OFFSET=4)
      integer TCURVE_TOLERANCE
      parameter(TCURVE_TOLERANCE=1)
      integer TCURVE_EXTRAPOLATE
      parameter(TCURVE_EXTRAPOLATE=2)
      integer TCURVE_HINT
      parameter(TCURVE_HINT=3)
      integer TCURVE_TABLEM1
      parameter(TCURVE_TABLEM1=1)
      integer TCURVE_TABLEM2
      parameter(TCURVE_TABLEM2=2)
      integer TCURVE_TABLEM3
      parameter(TCURVE_TABLEM3=3)
      integer TCURVE_TABLES1
      parameter(TCURVE_TABLES1=4)
      integer TCURVE_TABLED2
      parameter(TCURVE_TABLED2=6)
      integer TCURVE_TABLED3
      parameter(TCURVE_TABLED3=7)
      integer TRIMESH_NUMNONMAN
      parameter(TRIMESH_NUMNONMAN=1)
      integer TRIMESH_NONMAN
      parameter(TRIMESH_NONMAN=2)
      integer TRIMESH_NUMINCONS
      parameter(TRIMESH_NUMINCONS=3)
      integer TRIMESH_INCONS
      parameter(TRIMESH_INCONS=4)
      integer TRIMESH_NUMNEGJAC
      parameter(TRIMESH_NUMNEGJAC=5)
      integer TRIMESH_NUMFREEEND
      parameter(TRIMESH_NUMFREEEND=6)
      integer TRIMESH_FREEEND
      parameter(TRIMESH_FREEEND=7)
      integer TRIMESH_NUMNONQUAL
      parameter(TRIMESH_NUMNONQUAL=8)
      integer TRIMESH_NUMUNCONN
      parameter(TRIMESH_NUMUNCONN=9)
      integer TRIMESH_UNCONN
      parameter(TRIMESH_UNCONN=10)
      integer TRIMESH_NUMEXNODE
      parameter(TRIMESH_NUMEXNODE=11)
      integer TRIMESH_EXNODE
      parameter(TRIMESH_EXNODE=12)
      integer TRIMESH_NUMINTERSECT
      parameter(TRIMESH_NUMINTERSECT=13)
      integer TRIMESH_INTERSECT
      parameter(TRIMESH_INTERSECT=14)
      integer TRIMESH_NUMREPEATEDNODE
      parameter(TRIMESH_NUMREPEATEDNODE=15)
      integer TRIMESH_REPEATEDNODE
      parameter(TRIMESH_REPEATEDNODE=16)
      integer TRIMESH_NUMDUPLICATELINE
      parameter(TRIMESH_NUMDUPLICATELINE=17)
      integer TRIMESH_DUPLICATELINE
      parameter(TRIMESH_DUPLICATELINE=18)
      integer TRIMESH_UNCONNECT
      parameter(TRIMESH_UNCONNECT=-2)
      integer TRIMESH_LINEFLAG
      parameter(TRIMESH_LINEFLAG=-3)
      integer TRIMESH_UNCONNECT_ERROR
      parameter(TRIMESH_UNCONNECT_ERROR=0)
      integer TRIMESH_UNCONNECT_INCLUDE
      parameter(TRIMESH_UNCONNECT_INCLUDE=1)
      integer TRIMESH_UNCONNECT_IGNORE
      parameter(TRIMESH_UNCONNECT_IGNORE=2)
      integer TRIMESH_ADVFRONT
      parameter(TRIMESH_ADVFRONT=-5)
      integer TRIMESH_SMOOTH
      parameter(TRIMESH_SMOOTH=-6)
      integer TRIMESH_BOUNDCUT
      parameter(TRIMESH_BOUNDCUT=-7)
      integer TRIMESH_CUTFLAG
      parameter(TRIMESH_CUTFLAG=-8)
      integer TRIMESH_CUTANGLE
      parameter(TRIMESH_CUTANGLE=-9)
      integer TRIMESH_CUTMINEDGELENGTH
      parameter(TRIMESH_CUTMINEDGELENGTH=-10)
      integer TRIMESH_NONOBTUSEMETHOD
      parameter(TRIMESH_NONOBTUSEMETHOD=-11)
      integer TRIMESH_FUN_DEBUG
      parameter(TRIMESH_FUN_DEBUG=1)
      integer TRIMESH_FUN_MONITOR
      parameter(TRIMESH_FUN_MONITOR=2)
      integer TRIMESH_FUN_SIZING
      parameter(TRIMESH_FUN_SIZING=3)
      integer TRIMESH_FUN_ASIZING
      parameter(TRIMESH_FUN_ASIZING=4)
      integer UNITS_LENGTH
      parameter(UNITS_LENGTH=1)
      integer UNITS_MASS
      parameter(UNITS_MASS=2)
      integer UNITS_TIME
      parameter(UNITS_TIME=3)
      integer UNITS_TEMP
      parameter(UNITS_TEMP=4)
      integer UNITS_TEMP_OFFSET
      parameter(UNITS_TEMP_OFFSET=5)
      integer UNITS_ANGLE
      parameter(UNITS_ANGLE=6)
      integer UNITS_CHARGE
      parameter(UNITS_CHARGE=7)
      integer UNITS_LENGTH_METER
      parameter(UNITS_LENGTH_METER=1)
      integer UNITS_LENGTH_CENTIMETER
      parameter(UNITS_LENGTH_CENTIMETER=2)
      integer UNITS_LENGTH_MILLIMETER
      parameter(UNITS_LENGTH_MILLIMETER=3)
      integer UNITS_LENGTH_MICRON
      parameter(UNITS_LENGTH_MICRON=4)
      integer UNITS_LENGTH_NANOMETER
      parameter(UNITS_LENGTH_NANOMETER=5)
      integer UNITS_LENGTH_ANGSTROM
      parameter(UNITS_LENGTH_ANGSTROM=6)
      integer UNITS_LENGTH_KILOMETER
      parameter(UNITS_LENGTH_KILOMETER=7)
      integer UNITS_LENGTH_INCH
      parameter(UNITS_LENGTH_INCH=8)
      integer UNITS_LENGTH_FOOT
      parameter(UNITS_LENGTH_FOOT=9)
      integer UNITS_LENGTH_MILE
      parameter(UNITS_LENGTH_MILE=10)
      integer UNITS_LENGTH_USER
      parameter(UNITS_LENGTH_USER=11)
      integer UNITS_MASS_KILOGRAM
      parameter(UNITS_MASS_KILOGRAM=101)
      integer UNITS_MASS_GRAM
      parameter(UNITS_MASS_GRAM=102)
      integer UNITS_MASS_POUND
      parameter(UNITS_MASS_POUND=103)
      integer UNITS_MASS_SLUG
      parameter(UNITS_MASS_SLUG=104)
      integer UNITS_MASS_METRICTON
      parameter(UNITS_MASS_METRICTON=105)
      integer UNITS_MASS_BLOB
      parameter(UNITS_MASS_BLOB=106)
      integer UNITS_MASS_KILOGRAMFM
      parameter(UNITS_MASS_KILOGRAMFM=107)
      integer UNITS_MASS_KILOGRAMFMM
      parameter(UNITS_MASS_KILOGRAMFMM=108)
      integer UNITS_MASS_USER
      parameter(UNITS_MASS_USER=109)
      integer UNITS_MASS_NEWTONHOURSQUAREPERMM
      parameter(UNITS_MASS_NEWTONHOURSQUAREPERMM=110)
      integer UNITS_MASS_MILLIGRAM
      parameter(UNITS_MASS_MILLIGRAM=111)
      integer UNITS_TIME_SECOND
      parameter(UNITS_TIME_SECOND=201)
      integer UNITS_TIME_MINUTE
      parameter(UNITS_TIME_MINUTE=202)
      integer UNITS_TIME_HOUR
      parameter(UNITS_TIME_HOUR=203)
      integer UNITS_TIME_USER
      parameter(UNITS_TIME_USER=204)
      integer UNITS_TIME_MICROSECOND
      parameter(UNITS_TIME_MICROSECOND=205)
      integer UNITS_TIME_MILLISECOND
      parameter(UNITS_TIME_MILLISECOND=206)
      integer UNITS_TEMP_KELVIN
      parameter(UNITS_TEMP_KELVIN=301)
      integer UNITS_TEMP_CELSIUS
      parameter(UNITS_TEMP_CELSIUS=302)
      integer UNITS_TEMP_RANKINE
      parameter(UNITS_TEMP_RANKINE=303)
      integer UNITS_TEMP_FAHRENHEIT
      parameter(UNITS_TEMP_FAHRENHEIT=304)
      integer UNITS_TEMP_USER
      parameter(UNITS_TEMP_USER=305)
      integer UNITS_ANGLE_RADIAN
      parameter(UNITS_ANGLE_RADIAN=401)
      integer UNITS_ANGLE_DEGREE
      parameter(UNITS_ANGLE_DEGREE=402)
      integer UNITS_ANGLE_CYCLE
      parameter(UNITS_ANGLE_CYCLE=403)
      integer UNITS_ANGLE_USER
      parameter(UNITS_ANGLE_USER=404)
      integer UNITS_CHARGE_COULOMB
      parameter(UNITS_CHARGE_COULOMB=501)
      integer UNITS_CHARGE_USER
      parameter(UNITS_CHARGE_USER=502)
      integer UNITS_DESCRIPTION_MAXCHAR
      parameter(UNITS_DESCRIPTION_MAXCHAR=12)
      integer UPROP_UNDEFINED
      parameter(UPROP_UNDEFINED=0)
      integer UPROP_VALUE
      parameter(UPROP_VALUE=1)
      integer UPROP_USERDIMENUM
      parameter(UPROP_USERDIMENUM=-1000000)
      integer UPROP_USERDIME
      parameter(UPROP_USERDIME=-2000000)
      integer UPROP_USERNAME
      parameter(UPROP_USERNAME=-3000000)
      integer UPROP_USERDATATYPE
      parameter(UPROP_USERDATATYPE=-4000000)
      integer UPROP_USERDATA
      parameter(UPROP_USERDATA=-5000000)
      integer UPROP_USERBASE
      parameter(UPROP_USERBASE=-5000000)
      integer ANS_NUMELEMTYPES
      parameter(ANS_NUMELEMTYPES=300)
      integer D3D_NUMELEMTYPES
      parameter(D3D_NUMELEMTYPES=13)
      integer D3D_NUMELEMSETTYPES
      parameter(D3D_NUMELEMSETTYPES=6)
      integer VIS_MAXISOCLIP
      parameter(VIS_MAXISOCLIP=6)
      integer VIS_MAXPRIMLENGTH
      parameter(VIS_MAXPRIMLENGTH=864)
      integer VIS_MAXDATAROWS
      parameter(VIS_MAXDATAROWS=16)
      integer VIS_MAXELEMIJK
      parameter(VIS_MAXELEMIJK=13)
      integer VIS_MAXEDGENODE
      parameter(VIS_MAXEDGENODE=13)
      integer VIS_MAXFACENODE
      parameter(VIS_MAXFACENODE=1024)
      integer VIS_MAXCELLNODE
      parameter(VIS_MAXCELLNODE=2197)
      integer VIS_MAXELEMNODE
      parameter(VIS_MAXELEMNODE=4095)
      integer VIS_MAXIJK
      parameter(VIS_MAXIJK=4096)
      integer VIS_MAX_MAXI
      parameter(VIS_MAX_MAXI=32767)
      integer VIS_MAX_MAXJ
      parameter(VIS_MAX_MAXJ=32767)
      integer VIS_MAX_MAXK
      parameter(VIS_MAX_MAXK=32767)
      integer VIS_MAXNODEELEM
      parameter(VIS_MAXNODEELEM=1000)
      integer VIS_MAXSECTION
      parameter(VIS_MAXSECTION=4096)
      integer VIS_OFF
      parameter(VIS_OFF=0)
      integer VIS_ON
      parameter(VIS_ON=1)
      integer VIS_ERROR_NONE
      parameter(VIS_ERROR_NONE=0)
      integer VIS_ERROR_VALUE
      parameter(VIS_ERROR_VALUE=1)
      integer VIS_ERROR_ENUM
      parameter(VIS_ERROR_ENUM=2)
      integer VIS_ERROR_OBJECTTYPE
      parameter(VIS_ERROR_OBJECTTYPE=3)
      integer VIS_ERROR_MEMORY
      parameter(VIS_ERROR_MEMORY=4)
      integer VIS_ERROR_NULLOBJECT
      parameter(VIS_ERROR_NULLOBJECT=5)
      integer VIS_ERROR_FILE
      parameter(VIS_ERROR_FILE=6)
      integer VIS_ERROR_COMPUTE
      parameter(VIS_ERROR_COMPUTE=7)
      integer VIS_ERROR_OPERATION
      parameter(VIS_ERROR_OPERATION=8)
      integer VIS_SHAPEUNDEFINED
      parameter(VIS_SHAPEUNDEFINED=-1)
      integer VIS_SHAPEPOINT
      parameter(VIS_SHAPEPOINT=0)
      integer VIS_SHAPELINE
      parameter(VIS_SHAPELINE=1)
      integer VIS_SHAPETRI
      parameter(VIS_SHAPETRI=2)
      integer VIS_SHAPEQUAD
      parameter(VIS_SHAPEQUAD=3)
      integer VIS_SHAPETET
      parameter(VIS_SHAPETET=4)
      integer VIS_SHAPEPYR
      parameter(VIS_SHAPEPYR=5)
      integer VIS_SHAPEWED
      parameter(VIS_SHAPEWED=6)
      integer VIS_SHAPEHEX
      parameter(VIS_SHAPEHEX=7)
      integer VIS_SHAPEPOLYGON
      parameter(VIS_SHAPEPOLYGON=8)
      integer VIS_SHAPEPOLYHED
      parameter(VIS_SHAPEPOLYHED=9)
      integer VIS_SPCFLAGS
      parameter(VIS_SPCFLAGS=7)
      integer VIS_CREFID
      parameter(VIS_CREFID=9)
      integer VIS_FEATYPE
      parameter(VIS_FEATYPE=0)
      integer VIS_MATLID
      parameter(VIS_MATLID=1)
      integer VIS_PROPID
      parameter(VIS_PROPID=2)
      integer VIS_PARTID
      parameter(VIS_PARTID=3)
      integer VIS_CSYSID
      parameter(VIS_CSYSID=4)
      integer VIS_IBLANK
      parameter(VIS_IBLANK=6)
      integer VIS_EXTTYPE
      parameter(VIS_EXTTYPE=8)
      integer VIS_USERID
      parameter(VIS_USERID=10)
      integer VIS_FEATECH
      parameter(VIS_FEATECH=11)
      integer VIS_FEASPEC
      parameter(VIS_FEASPEC=12)
      integer VIS_CMATID
      parameter(VIS_CMATID=13)
      integer VIS_CMATFLAG
      parameter(VIS_CMATFLAG=14)
      integer VIS_MISCID0
      parameter(VIS_MISCID0=15)
      integer VIS_MISCID1
      parameter(VIS_MISCID1=16)
      integer VIS_MISCID2
      parameter(VIS_MISCID2=17)
      integer VIS_MISCID3
      parameter(VIS_MISCID3=18)
      integer VIS_MISCID4
      parameter(VIS_MISCID4=19)
      integer VIS_MISCID5
      parameter(VIS_MISCID5=20)
      integer VIS_MISCID6
      parameter(VIS_MISCID6=21)
      integer VIS_MISCID7
      parameter(VIS_MISCID7=22)
      integer VIS_MISCID8
      parameter(VIS_MISCID8=23)
      integer VIS_FEATWOD
      parameter(VIS_FEATWOD=25)
      integer VIS_ENDATOPO
      parameter(VIS_ENDATOPO=26)
      integer VIS_ENDBTOPO
      parameter(VIS_ENDBTOPO=27)
      integer VIS_ENDACON
      parameter(VIS_ENDACON=28)
      integer VIS_ENDBCON
      parameter(VIS_ENDBCON=29)
      integer VIS_ORIENTINDEX
      parameter(VIS_ORIENTINDEX=30)
      integer VIS_GEOVERT
      parameter(VIS_GEOVERT=33)
      integer VIS_GEOEDGE
      parameter(VIS_GEOEDGE=34)
      integer VIS_GEOFACE
      parameter(VIS_GEOFACE=35)
      integer VIS_GEOBODY
      parameter(VIS_GEOBODY=36)
      integer VIS_PINFLAGS
      parameter(VIS_PINFLAGS=41)
      integer VIS_DOMAIN
      parameter(VIS_DOMAIN=42)
      integer VIS_SEID
      parameter(VIS_SEID=43)
      integer VIS_SYMMID
      parameter(VIS_SYMMID=44)
      integer VIS_POLYUNIQUEFACE
      parameter(VIS_POLYUNIQUEFACE=46)
      integer VIS_NODE_FEATYPE
      parameter(VIS_NODE_FEATYPE=46)
      integer VIS_NODE_PARTID
      parameter(VIS_NODE_PARTID=46)
      integer VIS_NODE_CSYSID
      parameter(VIS_NODE_CSYSID=46)
      integer VIS_NODE_IBLANK
      parameter(VIS_NODE_IBLANK=46)
      integer VIS_NODE_SPCFLAGS
      parameter(VIS_NODE_SPCFLAGS=46)
      integer VIS_NODE_CREFID
      parameter(VIS_NODE_CREFID=46)
      integer VIS_NODE_USERID
      parameter(VIS_NODE_USERID=46)
      integer VIS_NODE_MISCID0
      parameter(VIS_NODE_MISCID0=46)
      integer VIS_NODE_MISCID1
      parameter(VIS_NODE_MISCID1=46)
      integer VIS_NODE_MISCID2
      parameter(VIS_NODE_MISCID2=46)
      integer VIS_NODE_MISCID3
      parameter(VIS_NODE_MISCID3=46)
      integer VIS_NODE_MISCID4
      parameter(VIS_NODE_MISCID4=46)
      integer VIS_NODE_MISCID5
      parameter(VIS_NODE_MISCID5=46)
      integer VIS_NODE_MISCID6
      parameter(VIS_NODE_MISCID6=46)
      integer VIS_NODE_MISCID7
      parameter(VIS_NODE_MISCID7=46)
      integer VIS_NODE_MISCID8
      parameter(VIS_NODE_MISCID8=46)
      integer VIS_MAXNODEASSOC
      parameter(VIS_MAXNODEASSOC=24)
      integer VIS_COLORID
      parameter(VIS_COLORID=5)
      integer VIS_MISCID
      parameter(VIS_MISCID=15)
      integer VIS_EXTNAMEA
      parameter(VIS_EXTNAMEA=31)
      integer VIS_EXTNAMEB
      parameter(VIS_EXTNAMEB=32)
      integer VIS_INTERN
      parameter(VIS_INTERN=37)
      integer VIS_INTERN0
      parameter(VIS_INTERN0=37)
      integer VIS_INTERN1
      parameter(VIS_INTERN1=38)
      integer VIS_INTERN2
      parameter(VIS_INTERN2=39)
      integer VIS_INTERN3
      parameter(VIS_INTERN3=40)
      integer VIS_FEATECHMODIFIED
      parameter(VIS_FEATECHMODIFIED=45)
      integer VIS_QUALFLAG
      parameter(VIS_QUALFLAG=24)
      integer VIS_MAXASSOC
      parameter(VIS_MAXASSOC=47)
      integer VIS_MAXASSOC_PER_ENTITY
      parameter(VIS_MAXASSOC_PER_ENTITY=10000)
      integer VIS_NODE_UNDEFINED
      parameter(VIS_NODE_UNDEFINED=0)
      integer VIS_NODE_GRID
      parameter(VIS_NODE_GRID=1)
      integer VIS_NODE_SCALAR
      parameter(VIS_NODE_SCALAR=2)
      integer VIS_ELEM_UNDEFINED
      parameter(VIS_ELEM_UNDEFINED=2)
      integer VIS_ELEM_SOLID
      parameter(VIS_ELEM_SOLID=2)
      integer VIS_ELEM_SHELL
      parameter(VIS_ELEM_SHELL=2)
      integer VIS_ELEM_MEMBRANE
      parameter(VIS_ELEM_MEMBRANE=2)
      integer VIS_ELEM_BEAM
      parameter(VIS_ELEM_BEAM=2)
      integer VIS_ELEM_TRUSS
      parameter(VIS_ELEM_TRUSS=2)
      integer VIS_ELEM_INFINITE
      parameter(VIS_ELEM_INFINITE=2)
      integer VIS_ELEM_GAP
      parameter(VIS_ELEM_GAP=2)
      integer VIS_ELEM_JOINT
      parameter(VIS_ELEM_JOINT=2)
      integer VIS_ELEM_SPRINGDASHPOT
      parameter(VIS_ELEM_SPRINGDASHPOT=2)
      integer VIS_ELEM_RIGID
      parameter(VIS_ELEM_RIGID=2)
      integer VIS_ELEM_CONSTRAINT
      parameter(VIS_ELEM_CONSTRAINT=2)
      integer VIS_ELEM_PLOT
      parameter(VIS_ELEM_PLOT=2)
      integer VIS_ELEM_MASS
      parameter(VIS_ELEM_MASS=2)
      integer VIS_ELEM_INTER
      parameter(VIS_ELEM_INTER=2)
      integer VIS_ELEM_SUPER
      parameter(VIS_ELEM_SUPER=2)
      integer VIS_ELEM_REINFORCEMENT
      parameter(VIS_ELEM_REINFORCEMENT=2)
      integer VIS_ELEM_MAX
      parameter(VIS_ELEM_MAX=2)
      integer VIS_SCALAR
      parameter(VIS_SCALAR=0)
      integer VIS_VECTOR
      parameter(VIS_VECTOR=1)
      integer VIS_TENSOR
      parameter(VIS_TENSOR=2)
      integer VIS_GENERALTENSOR
      parameter(VIS_GENERALTENSOR=3)
      integer VIS_ELEMRES
      parameter(VIS_ELEMRES=5)
      integer VIS_SIXDOF
      parameter(VIS_SIXDOF=9)
      integer VIS_SCALARS
      parameter(VIS_SCALARS=10)
      integer VIS_SCALARS1
      parameter(VIS_SCALARS1=11)
      integer VIS_SCALARS2
      parameter(VIS_SCALARS2=12)
      integer VIS_SCALARS3
      parameter(VIS_SCALARS3=13)
      integer VIS_SCALARS4
      parameter(VIS_SCALARS4=14)
      integer VIS_SCALARS5
      parameter(VIS_SCALARS5=15)
      integer VIS_SCALARS6
      parameter(VIS_SCALARS6=16)
      integer VIS_SCALARS7
      parameter(VIS_SCALARS7=17)
      integer VIS_SCALARS8
      parameter(VIS_SCALARS8=18)
      integer VIS_SCALARS9
      parameter(VIS_SCALARS9=19)
      integer VIS_SCALARS10
      parameter(VIS_SCALARS10=20)
      integer VIS_SCALARS11
      parameter(VIS_SCALARS11=21)
      integer VIS_SCALARS12
      parameter(VIS_SCALARS12=22)
      integer VIS_SCALARS13
      parameter(VIS_SCALARS13=23)
      integer VIS_SCALARS14
      parameter(VIS_SCALARS14=24)
      integer VIS_SCALARS15
      parameter(VIS_SCALARS15=25)
      integer VIS_SCALARS16
      parameter(VIS_SCALARS16=26)
      integer VIS_SCALARS17
      parameter(VIS_SCALARS17=27)
      integer VIS_SCALARS18
      parameter(VIS_SCALARS18=28)
      integer VIS_SCALARS19
      parameter(VIS_SCALARS19=29)
      integer VIS_SCALARS20
      parameter(VIS_SCALARS20=30)
      integer VIS_SCALARS21
      parameter(VIS_SCALARS21=31)
      integer VIS_SCALARS22
      parameter(VIS_SCALARS22=32)
      integer VIS_SCALARS23
      parameter(VIS_SCALARS23=33)
      integer VIS_SCALARS24
      parameter(VIS_SCALARS24=34)
      integer VIS_SCALARS25
      parameter(VIS_SCALARS25=35)
      integer VIS_SCALARS26
      parameter(VIS_SCALARS26=36)
      integer VIS_SCALARS27
      parameter(VIS_SCALARS27=37)
      integer VIS_SCALARS28
      parameter(VIS_SCALARS28=38)
      integer VIS_SCALARS29
      parameter(VIS_SCALARS29=39)
      integer VIS_SCALARS30
      parameter(VIS_SCALARS30=40)
      integer VIS_SCALARS31
      parameter(VIS_SCALARS31=41)
      integer VIS_SCALARS32
      parameter(VIS_SCALARS32=42)
      integer VIS_SCALARS33
      parameter(VIS_SCALARS33=43)
      integer VIS_SCALARS34
      parameter(VIS_SCALARS34=44)
      integer VIS_SCALARS35
      parameter(VIS_SCALARS35=45)
      integer VIS_SCALARS36
      parameter(VIS_SCALARS36=46)
      integer VIS_SCALARS37
      parameter(VIS_SCALARS37=47)
      integer VIS_SCALARS38
      parameter(VIS_SCALARS38=48)
      integer VIS_SCALARS39
      parameter(VIS_SCALARS39=49)
      integer VIS_SCALARS40
      parameter(VIS_SCALARS40=50)
      integer VIS_SCALARS41
      parameter(VIS_SCALARS41=51)
      integer VIS_SCALARS42
      parameter(VIS_SCALARS42=52)
      integer VIS_SCALARS43
      parameter(VIS_SCALARS43=53)
      integer VIS_SCALARS44
      parameter(VIS_SCALARS44=54)
      integer VIS_SCALARS45
      parameter(VIS_SCALARS45=55)
      integer VIS_SCALARS46
      parameter(VIS_SCALARS46=56)
      integer VIS_SCALARS47
      parameter(VIS_SCALARS47=57)
      integer VIS_SCALARS48
      parameter(VIS_SCALARS48=58)
      integer VIS_SCALARS49
      parameter(VIS_SCALARS49=59)
      integer VIS_SCALARS50
      parameter(VIS_SCALARS50=60)
      integer VIS_SCALARS51
      parameter(VIS_SCALARS51=61)
      integer VIS_SCALARS52
      parameter(VIS_SCALARS52=62)
      integer VIS_SCALARS53
      parameter(VIS_SCALARS53=63)
      integer VIS_SCALARS54
      parameter(VIS_SCALARS54=64)
      integer VIS_SCALARS55
      parameter(VIS_SCALARS55=65)
      integer VIS_SCALARS56
      parameter(VIS_SCALARS56=66)
      integer VIS_SCALARS57
      parameter(VIS_SCALARS57=67)
      integer VIS_SCALARS58
      parameter(VIS_SCALARS58=68)
      integer VIS_SCALARS59
      parameter(VIS_SCALARS59=69)
      integer VIS_SCALARS60
      parameter(VIS_SCALARS60=70)
      integer VIS_SCALARS61
      parameter(VIS_SCALARS61=71)
      integer VIS_SCALARS62
      parameter(VIS_SCALARS62=72)
      integer VIS_SCALARS63
      parameter(VIS_SCALARS63=73)
      integer VIS_SCALARS64
      parameter(VIS_SCALARS64=74)
      integer VIS_SCALARS65
      parameter(VIS_SCALARS65=75)
      integer VIS_SCALARS66
      parameter(VIS_SCALARS66=76)
      integer VIS_SCALARS67
      parameter(VIS_SCALARS67=77)
      integer VIS_SCALARS68
      parameter(VIS_SCALARS68=78)
      integer VIS_SCALARS69
      parameter(VIS_SCALARS69=79)
      integer VIS_SCALARS70
      parameter(VIS_SCALARS70=80)
      integer VIS_SCALARS71
      parameter(VIS_SCALARS71=81)
      integer VIS_SCALARS72
      parameter(VIS_SCALARS72=82)
      integer VIS_SCALARS73
      parameter(VIS_SCALARS73=83)
      integer VIS_SCALARS74
      parameter(VIS_SCALARS74=84)
      integer VIS_SCALARS75
      parameter(VIS_SCALARS75=85)
      integer VIS_SCALARS76
      parameter(VIS_SCALARS76=86)
      integer VIS_SCALARS77
      parameter(VIS_SCALARS77=87)
      integer VIS_SCALARS78
      parameter(VIS_SCALARS78=88)
      integer VIS_SCALARS79
      parameter(VIS_SCALARS79=89)
      integer VIS_SCALARS80
      parameter(VIS_SCALARS80=90)
      integer VIS_SCALARS81
      parameter(VIS_SCALARS81=91)
      integer VIS_SCALARS82
      parameter(VIS_SCALARS82=92)
      integer VIS_SCALARS83
      parameter(VIS_SCALARS83=93)
      integer VIS_SCALARS84
      parameter(VIS_SCALARS84=94)
      integer VIS_SCALARS85
      parameter(VIS_SCALARS85=95)
      integer VIS_SCALARS86
      parameter(VIS_SCALARS86=96)
      integer VIS_SCALARS87
      parameter(VIS_SCALARS87=97)
      integer VIS_SCALARS88
      parameter(VIS_SCALARS88=98)
      integer VIS_SCALARS89
      parameter(VIS_SCALARS89=99)
      integer VIS_SCALARS90
      parameter(VIS_SCALARS90=100)
      integer VIS_SCALARS91
      parameter(VIS_SCALARS91=101)
      integer VIS_SCALARS92
      parameter(VIS_SCALARS92=102)
      integer VIS_SCALARS93
      parameter(VIS_SCALARS93=103)
      integer VIS_SCALARS94
      parameter(VIS_SCALARS94=104)
      integer VIS_SCALARS95
      parameter(VIS_SCALARS95=105)
      integer VIS_SCALARS96
      parameter(VIS_SCALARS96=106)
      integer VIS_SCALARS97
      parameter(VIS_SCALARS97=107)
      integer VIS_SCALARS98
      parameter(VIS_SCALARS98=108)
      integer VIS_SCALARS99
      parameter(VIS_SCALARS99=109)
      integer VIS_SCALARS100
      parameter(VIS_SCALARS100=110)
      integer VIS_SCALARS101
      parameter(VIS_SCALARS101=111)
      integer VIS_SCALARS102
      parameter(VIS_SCALARS102=112)
      integer VIS_SCALARS103
      parameter(VIS_SCALARS103=113)
      integer VIS_SCALARS104
      parameter(VIS_SCALARS104=114)
      integer VIS_SCALARS105
      parameter(VIS_SCALARS105=115)
      integer VIS_SCALARS106
      parameter(VIS_SCALARS106=116)
      integer VIS_SCALARS107
      parameter(VIS_SCALARS107=117)
      integer VIS_SCALARS108
      parameter(VIS_SCALARS108=118)
      integer VIS_SCALARS109
      parameter(VIS_SCALARS109=119)
      integer VIS_SCALARS110
      parameter(VIS_SCALARS110=120)
      integer VIS_SCALARS111
      parameter(VIS_SCALARS111=121)
      integer VIS_SCALARS112
      parameter(VIS_SCALARS112=122)
      integer VIS_SCALARS113
      parameter(VIS_SCALARS113=123)
      integer VIS_SCALARS114
      parameter(VIS_SCALARS114=124)
      integer VIS_SCALARS115
      parameter(VIS_SCALARS115=125)
      integer VIS_SCALARS116
      parameter(VIS_SCALARS116=126)
      integer VIS_SCALARS117
      parameter(VIS_SCALARS117=127)
      integer VIS_SCALARS118
      parameter(VIS_SCALARS118=128)
      integer VIS_SCALARS119
      parameter(VIS_SCALARS119=129)
      integer VIS_SCALARS120
      parameter(VIS_SCALARS120=130)
      integer VIS_SCALARS121
      parameter(VIS_SCALARS121=131)
      integer VIS_SCALARS122
      parameter(VIS_SCALARS122=132)
      integer VIS_SCALARS123
      parameter(VIS_SCALARS123=133)
      integer VIS_SCALARS124
      parameter(VIS_SCALARS124=134)
      integer VIS_SCALARS125
      parameter(VIS_SCALARS125=135)
      integer VIS_SCALARS126
      parameter(VIS_SCALARS126=136)
      integer VIS_SCALARS127
      parameter(VIS_SCALARS127=137)
      integer VIS_SCALARS128
      parameter(VIS_SCALARS128=138)
      integer VIS_SCALARS129
      parameter(VIS_SCALARS129=139)
      integer VIS_SCALARS130
      parameter(VIS_SCALARS130=140)
      integer VIS_SCALARS131
      parameter(VIS_SCALARS131=141)
      integer VIS_SCALARS132
      parameter(VIS_SCALARS132=142)
      integer VIS_SCALARS133
      parameter(VIS_SCALARS133=143)
      integer VIS_SCALARS134
      parameter(VIS_SCALARS134=144)
      integer VIS_SCALARS135
      parameter(VIS_SCALARS135=145)
      integer VIS_SCALARS136
      parameter(VIS_SCALARS136=146)
      integer VIS_SCALARS137
      parameter(VIS_SCALARS137=147)
      integer VIS_SCALARS138
      parameter(VIS_SCALARS138=148)
      integer VIS_SCALARS139
      parameter(VIS_SCALARS139=149)
      integer VIS_SCALARS140
      parameter(VIS_SCALARS140=150)
      integer VIS_SCALARS141
      parameter(VIS_SCALARS141=151)
      integer VIS_SCALARS142
      parameter(VIS_SCALARS142=152)
      integer VIS_SCALARS143
      parameter(VIS_SCALARS143=153)
      integer VIS_SCALARS144
      parameter(VIS_SCALARS144=154)
      integer VIS_SCALARS145
      parameter(VIS_SCALARS145=155)
      integer VIS_SCALARS146
      parameter(VIS_SCALARS146=156)
      integer VIS_SCALARS147
      parameter(VIS_SCALARS147=157)
      integer VIS_SCALARS148
      parameter(VIS_SCALARS148=158)
      integer VIS_SCALARS149
      parameter(VIS_SCALARS149=159)
      integer VIS_SCALARS150
      parameter(VIS_SCALARS150=160)
      integer VIS_SCALARS151
      parameter(VIS_SCALARS151=161)
      integer VIS_SCALARS152
      parameter(VIS_SCALARS152=162)
      integer VIS_SCALARS153
      parameter(VIS_SCALARS153=163)
      integer VIS_SCALARS154
      parameter(VIS_SCALARS154=164)
      integer VIS_SCALARS155
      parameter(VIS_SCALARS155=165)
      integer VIS_SCALARS156
      parameter(VIS_SCALARS156=166)
      integer VIS_SCALARS157
      parameter(VIS_SCALARS157=167)
      integer VIS_SCALARS158
      parameter(VIS_SCALARS158=168)
      integer VIS_SCALARS159
      parameter(VIS_SCALARS159=169)
      integer VIS_SCALARS160
      parameter(VIS_SCALARS160=170)
      integer VIS_SCALARS161
      parameter(VIS_SCALARS161=171)
      integer VIS_SCALARS162
      parameter(VIS_SCALARS162=172)
      integer VIS_SCALARS163
      parameter(VIS_SCALARS163=173)
      integer VIS_SCALARS164
      parameter(VIS_SCALARS164=174)
      integer VIS_SCALARS165
      parameter(VIS_SCALARS165=175)
      integer VIS_SCALARS166
      parameter(VIS_SCALARS166=176)
      integer VIS_SCALARS167
      parameter(VIS_SCALARS167=177)
      integer VIS_SCALARS168
      parameter(VIS_SCALARS168=178)
      integer VIS_SCALARS169
      parameter(VIS_SCALARS169=179)
      integer VIS_SCALARS170
      parameter(VIS_SCALARS170=180)
      integer VIS_SCALARS171
      parameter(VIS_SCALARS171=181)
      integer VIS_SCALARS172
      parameter(VIS_SCALARS172=182)
      integer VIS_SCALARS173
      parameter(VIS_SCALARS173=183)
      integer VIS_SCALARS174
      parameter(VIS_SCALARS174=184)
      integer VIS_SCALARS175
      parameter(VIS_SCALARS175=185)
      integer VIS_SCALARS176
      parameter(VIS_SCALARS176=186)
      integer VIS_SCALARS177
      parameter(VIS_SCALARS177=187)
      integer VIS_SCALARS178
      parameter(VIS_SCALARS178=188)
      integer VIS_SCALARS179
      parameter(VIS_SCALARS179=189)
      integer VIS_SCALARS180
      parameter(VIS_SCALARS180=190)
      integer VIS_SCALARS181
      parameter(VIS_SCALARS181=191)
      integer VIS_SCALARS182
      parameter(VIS_SCALARS182=192)
      integer VIS_SCALARS183
      parameter(VIS_SCALARS183=193)
      integer VIS_SCALARS184
      parameter(VIS_SCALARS184=194)
      integer VIS_SCALARS185
      parameter(VIS_SCALARS185=195)
      integer VIS_SCALARS186
      parameter(VIS_SCALARS186=196)
      integer VIS_SCALARS187
      parameter(VIS_SCALARS187=197)
      integer VIS_SCALARS188
      parameter(VIS_SCALARS188=198)
      integer VIS_SCALARS189
      parameter(VIS_SCALARS189=199)
      integer VIS_SCALARS190
      parameter(VIS_SCALARS190=200)
      integer VIS_SCALARS191
      parameter(VIS_SCALARS191=201)
      integer VIS_SCALARS192
      parameter(VIS_SCALARS192=202)
      integer VIS_SCALARS193
      parameter(VIS_SCALARS193=203)
      integer VIS_SCALARS194
      parameter(VIS_SCALARS194=204)
      integer VIS_SCALARS195
      parameter(VIS_SCALARS195=205)
      integer VIS_SCALARS196
      parameter(VIS_SCALARS196=206)
      integer VIS_SCALARS197
      parameter(VIS_SCALARS197=207)
      integer VIS_SCALARS198
      parameter(VIS_SCALARS198=208)
      integer VIS_SCALARS199
      parameter(VIS_SCALARS199=209)
      integer VIS_SCALARS200
      parameter(VIS_SCALARS200=210)
      integer VIS_SCALARS201
      parameter(VIS_SCALARS201=211)
      integer VIS_SCALARS202
      parameter(VIS_SCALARS202=212)
      integer VIS_SCALARS203
      parameter(VIS_SCALARS203=213)
      integer VIS_SCALARS204
      parameter(VIS_SCALARS204=214)
      integer VIS_SCALARS205
      parameter(VIS_SCALARS205=215)
      integer VIS_SCALARS206
      parameter(VIS_SCALARS206=216)
      integer VIS_SCALARS207
      parameter(VIS_SCALARS207=217)
      integer VIS_SCALARS208
      parameter(VIS_SCALARS208=218)
      integer VIS_SCALARS209
      parameter(VIS_SCALARS209=219)
      integer VIS_SCALARS210
      parameter(VIS_SCALARS210=220)
      integer VIS_SCALARS211
      parameter(VIS_SCALARS211=221)
      integer VIS_SCALARS212
      parameter(VIS_SCALARS212=222)
      integer VIS_SCALARS213
      parameter(VIS_SCALARS213=223)
      integer VIS_SCALARS214
      parameter(VIS_SCALARS214=224)
      integer VIS_SCALARS215
      parameter(VIS_SCALARS215=225)
      integer VIS_SCALARS216
      parameter(VIS_SCALARS216=226)
      integer VIS_SCALARS217
      parameter(VIS_SCALARS217=227)
      integer VIS_SCALARS218
      parameter(VIS_SCALARS218=228)
      integer VIS_SCALARS219
      parameter(VIS_SCALARS219=229)
      integer VIS_SCALARS220
      parameter(VIS_SCALARS220=230)
      integer VIS_SCALARS221
      parameter(VIS_SCALARS221=231)
      integer VIS_SCALARS222
      parameter(VIS_SCALARS222=232)
      integer VIS_SCALARS223
      parameter(VIS_SCALARS223=233)
      integer VIS_SCALARS224
      parameter(VIS_SCALARS224=234)
      integer VIS_SCALARS225
      parameter(VIS_SCALARS225=235)
      integer VIS_SCALARS226
      parameter(VIS_SCALARS226=236)
      integer VIS_SCALARS227
      parameter(VIS_SCALARS227=237)
      integer VIS_SCALARS228
      parameter(VIS_SCALARS228=238)
      integer VIS_SCALARS229
      parameter(VIS_SCALARS229=239)
      integer VIS_SCALARS230
      parameter(VIS_SCALARS230=240)
      integer VIS_SCALARS231
      parameter(VIS_SCALARS231=241)
      integer VIS_SCALARS232
      parameter(VIS_SCALARS232=242)
      integer VIS_SCALARS233
      parameter(VIS_SCALARS233=243)
      integer VIS_SCALARS234
      parameter(VIS_SCALARS234=244)
      integer VIS_SCALARS235
      parameter(VIS_SCALARS235=245)
      integer VIS_SCALARS236
      parameter(VIS_SCALARS236=246)
      integer VIS_SCALARS237
      parameter(VIS_SCALARS237=247)
      integer VIS_SCALARS238
      parameter(VIS_SCALARS238=248)
      integer VIS_SCALARS239
      parameter(VIS_SCALARS239=249)
      integer VIS_SCALARS240
      parameter(VIS_SCALARS240=250)
      integer VIS_SCALARS241
      parameter(VIS_SCALARS241=251)
      integer VIS_SCALARS242
      parameter(VIS_SCALARS242=252)
      integer VIS_SCALARS243
      parameter(VIS_SCALARS243=253)
      integer VIS_SCALARS244
      parameter(VIS_SCALARS244=254)
      integer VIS_SCALARS245
      parameter(VIS_SCALARS245=255)
      integer VIS_SCALARS246
      parameter(VIS_SCALARS246=256)
      integer VIS_SCALARS247
      parameter(VIS_SCALARS247=257)
      integer VIS_SCALARS248
      parameter(VIS_SCALARS248=258)
      integer VIS_SCALARS249
      parameter(VIS_SCALARS249=259)
      integer VIS_SCALARS250
      parameter(VIS_SCALARS250=260)
      integer VIS_SCALARS251
      parameter(VIS_SCALARS251=261)
      integer VIS_SCALARS252
      parameter(VIS_SCALARS252=262)
      integer VIS_SCALARS253
      parameter(VIS_SCALARS253=263)
      integer VIS_SCALARS254
      parameter(VIS_SCALARS254=264)
      integer VIS_SCALARS255
      parameter(VIS_SCALARS255=265)
      integer VIS_SCALARS256
      parameter(VIS_SCALARS256=266)
      integer VIS_MAXDATATYPEROWS
      parameter(VIS_MAXDATATYPEROWS=256)
      integer VIS_VECTOR_X
      parameter(VIS_VECTOR_X=326)
      integer VIS_VECTOR_Y
      parameter(VIS_VECTOR_Y=327)
      integer VIS_VECTOR_Z
      parameter(VIS_VECTOR_Z=328)
      integer VIS_VECTOR_MAG
      parameter(VIS_VECTOR_MAG=329)
      integer VIS_VECTOR_VECTOR
      parameter(VIS_VECTOR_VECTOR=329)
      integer VIS_TENSOR_XX
      parameter(VIS_TENSOR_XX=331)
      integer VIS_TENSOR_YY
      parameter(VIS_TENSOR_YY=332)
      integer VIS_TENSOR_ZZ
      parameter(VIS_TENSOR_ZZ=333)
      integer VIS_TENSOR_XY
      parameter(VIS_TENSOR_XY=334)
      integer VIS_TENSOR_YZ
      parameter(VIS_TENSOR_YZ=335)
      integer VIS_TENSOR_ZX
      parameter(VIS_TENSOR_ZX=336)
      integer VIS_TENSOR_MEAN
      parameter(VIS_TENSOR_MEAN=337)
      integer VIS_TENSOR_VONMISES
      parameter(VIS_TENSOR_VONMISES=338)
      integer VIS_TENSOR_OCTAHEDRAL
      parameter(VIS_TENSOR_OCTAHEDRAL=339)
      integer VIS_TENSOR_DETERMINANT
      parameter(VIS_TENSOR_DETERMINANT=340)
      integer VIS_TENSOR_MAXSHEAR
      parameter(VIS_TENSOR_MAXSHEAR=341)
      integer VIS_TENSOR_ANGSHEAR
      parameter(VIS_TENSOR_ANGSHEAR=342)
      integer VIS_TENSOR_MINPRINC
      parameter(VIS_TENSOR_MINPRINC=343)
      integer VIS_TENSOR_MIDPRINC
      parameter(VIS_TENSOR_MIDPRINC=344)
      integer VIS_TENSOR_MAXPRINC
      parameter(VIS_TENSOR_MAXPRINC=345)
      integer VIS_TENSOR_MINPRINCDEV
      parameter(VIS_TENSOR_MINPRINCDEV=346)
      integer VIS_TENSOR_MIDPRINCDEV
      parameter(VIS_TENSOR_MIDPRINCDEV=347)
      integer VIS_TENSOR_MAXPRINCDEV
      parameter(VIS_TENSOR_MAXPRINCDEV=348)
      integer VIS_TENSOR_INTENSITY
      parameter(VIS_TENSOR_INTENSITY=349)
      integer VIS_TENSOR_EQUDIRECT
      parameter(VIS_TENSOR_EQUDIRECT=350)
      integer VIS_TENSOR_VONMISES_E
      parameter(VIS_TENSOR_VONMISES_E=351)
      integer VIS_TENSOR_PRINC
      parameter(VIS_TENSOR_PRINC=352)
      integer VIS_TENSOR_PRINCDIRCOS
      parameter(VIS_TENSOR_PRINCDIRCOS=353)
      integer VIS_TENSOR_TENSOR
      parameter(VIS_TENSOR_TENSOR=353)
      integer VIS_GENERALTENSOR_GENERALTENSOR
      parameter(VIS_GENERALTENSOR_GENERALTENSOR=353)
      integer VIS_GENERALTENSOR_XX
      parameter(VIS_GENERALTENSOR_XX=361)
      integer VIS_GENERALTENSOR_XY
      parameter(VIS_GENERALTENSOR_XY=362)
      integer VIS_GENERALTENSOR_XZ
      parameter(VIS_GENERALTENSOR_XZ=363)
      integer VIS_GENERALTENSOR_YX
      parameter(VIS_GENERALTENSOR_YX=364)
      integer VIS_GENERALTENSOR_YY
      parameter(VIS_GENERALTENSOR_YY=365)
      integer VIS_GENERALTENSOR_YZ
      parameter(VIS_GENERALTENSOR_YZ=366)
      integer VIS_GENERALTENSOR_ZX
      parameter(VIS_GENERALTENSOR_ZX=367)
      integer VIS_GENERALTENSOR_ZY
      parameter(VIS_GENERALTENSOR_ZY=368)
      integer VIS_GENERALTENSOR_ZZ
      parameter(VIS_GENERALTENSOR_ZZ=369)
      integer VIS_GENERALTENSOR_SYM
      parameter(VIS_GENERALTENSOR_SYM=370)
      integer VIS_GENERALTENSOR_XVEC
      parameter(VIS_GENERALTENSOR_XVEC=371)
      integer VIS_GENERALTENSOR_YVEC
      parameter(VIS_GENERALTENSOR_YVEC=372)
      integer VIS_GENERALTENSOR_ZVEC
      parameter(VIS_GENERALTENSOR_ZVEC=373)
      integer VIS_ELEMRES_SHELL_NXX
      parameter(VIS_ELEMRES_SHELL_NXX=381)
      integer VIS_ELEMRES_SHELL_NYY
      parameter(VIS_ELEMRES_SHELL_NYY=382)
      integer VIS_ELEMRES_SHELL_NXY
      parameter(VIS_ELEMRES_SHELL_NXY=383)
      integer VIS_ELEMRES_SHELL_MXX
      parameter(VIS_ELEMRES_SHELL_MXX=384)
      integer VIS_ELEMRES_SHELL_MYY
      parameter(VIS_ELEMRES_SHELL_MYY=385)
      integer VIS_ELEMRES_SHELL_MXY
      parameter(VIS_ELEMRES_SHELL_MXY=386)
      integer VIS_ELEMRES_SHELL_QXZ
      parameter(VIS_ELEMRES_SHELL_QXZ=387)
      integer VIS_ELEMRES_SHELL_QYZ
      parameter(VIS_ELEMRES_SHELL_QYZ=388)
      integer VIS_ELEMRES_BEAM_NXX
      parameter(VIS_ELEMRES_BEAM_NXX=391)
      integer VIS_ELEMRES_BEAM_MYY
      parameter(VIS_ELEMRES_BEAM_MYY=392)
      integer VIS_ELEMRES_BEAM_MZZ
      parameter(VIS_ELEMRES_BEAM_MZZ=393)
      integer VIS_ELEMRES_BEAM_T
      parameter(VIS_ELEMRES_BEAM_T=394)
      integer VIS_ELEMRES_BEAM_QXY
      parameter(VIS_ELEMRES_BEAM_QXY=395)
      integer VIS_ELEMRES_BEAM_QZX
      parameter(VIS_ELEMRES_BEAM_QZX=396)
      integer VIS_ELEMRES_BEAM_TB
      parameter(VIS_ELEMRES_BEAM_TB=397)
      integer VIS_ELEMRES_SPRINGDASHPOT_F
      parameter(VIS_ELEMRES_SPRINGDASHPOT_F=400)
      integer VIS_ELEMRES_SPRINGDASHPOT_FX
      parameter(VIS_ELEMRES_SPRINGDASHPOT_FX=400)
      integer VIS_ELEMRES_SPRINGDASHPOT_FY
      parameter(VIS_ELEMRES_SPRINGDASHPOT_FY=401)
      integer VIS_ELEMRES_SPRINGDASHPOT_FZ
      parameter(VIS_ELEMRES_SPRINGDASHPOT_FZ=402)
      integer VIS_ELEMRES_SPRINGDASHPOT_MX
      parameter(VIS_ELEMRES_SPRINGDASHPOT_MX=403)
      integer VIS_ELEMRES_SPRINGDASHPOT_MY
      parameter(VIS_ELEMRES_SPRINGDASHPOT_MY=404)
      integer VIS_ELEMRES_SPRINGDASHPOT_MZ
      parameter(VIS_ELEMRES_SPRINGDASHPOT_MZ=405)
      integer VIS_SIXDOF_SIXDOF
      parameter(VIS_SIXDOF_SIXDOF=405)
      integer VIS_SIXDOF_TX
      parameter(VIS_SIXDOF_TX=411)
      integer VIS_SIXDOF_TY
      parameter(VIS_SIXDOF_TY=412)
      integer VIS_SIXDOF_TZ
      parameter(VIS_SIXDOF_TZ=413)
      integer VIS_SIXDOF_RX
      parameter(VIS_SIXDOF_RX=414)
      integer VIS_SIXDOF_RY
      parameter(VIS_SIXDOF_RY=415)
      integer VIS_SIXDOF_RZ
      parameter(VIS_SIXDOF_RZ=416)
      integer VIS_SIXDOF_TMAG
      parameter(VIS_SIXDOF_TMAG=417)
      integer VIS_SIXDOF_RMAG
      parameter(VIS_SIXDOF_RMAG=418)
      integer VIS_SIXDOF_TVEC
      parameter(VIS_SIXDOF_TVEC=419)
      integer VIS_SIXDOF_RVEC
      parameter(VIS_SIXDOF_RVEC=420)
      integer VIS_SCALARS_SCALAR
      parameter(VIS_SCALARS_SCALAR=420)
      integer VIS_SCALARS_0
      parameter(VIS_SCALARS_0=421)
      integer VIS_SCALARS_1
      parameter(VIS_SCALARS_1=422)
      integer VIS_SCALARS_2
      parameter(VIS_SCALARS_2=423)
      integer VIS_SCALARS_3
      parameter(VIS_SCALARS_3=424)
      integer VIS_SCALARS_4
      parameter(VIS_SCALARS_4=425)
      integer VIS_SCALARS_5
      parameter(VIS_SCALARS_5=426)
      integer VIS_SCALARS_6
      parameter(VIS_SCALARS_6=427)
      integer VIS_SCALARS_7
      parameter(VIS_SCALARS_7=428)
      integer VIS_SCALARS_8
      parameter(VIS_SCALARS_8=429)
      integer VIS_SCALARS_9
      parameter(VIS_SCALARS_9=430)
      integer VIS_SCALARS_10
      parameter(VIS_SCALARS_10=431)
      integer VIS_SCALARS_11
      parameter(VIS_SCALARS_11=432)
      integer VIS_SCALARS_12
      parameter(VIS_SCALARS_12=433)
      integer VIS_DERIVE_MAX
      parameter(VIS_DERIVE_MAX=433)
      integer VIS_ISOCLIP_NONE
      parameter(VIS_ISOCLIP_NONE=0)
      integer VIS_ISOCLIP_FULL
      parameter(VIS_ISOCLIP_FULL=1)
      integer VIS_ISOCLIP_PART
      parameter(VIS_ISOCLIP_PART=2)
      integer VIS_EFORMAT
      parameter(VIS_EFORMAT=0)
      integer VIS_FFORMAT
      parameter(VIS_FFORMAT=1)
      integer VIS_IFORMAT
      parameter(VIS_IFORMAT=2)
      integer VIS_GFORMAT
      parameter(VIS_GFORMAT=3)
      integer VIS_XFORMAT
      parameter(VIS_XFORMAT=4)
      integer VIS_E2FORMAT
      parameter(VIS_E2FORMAT=5)
      integer VIS_E3FORMAT
      parameter(VIS_E3FORMAT=6)
      integer VIS_GXFORMAT
      parameter(VIS_GXFORMAT=7)
      integer VIS_FMFORMAT
      parameter(VIS_FMFORMAT=8)
      integer VIS_LISTING
      parameter(VIS_LISTING=1)
      integer VIS_SUMMARY
      parameter(VIS_SUMMARY=2)
      integer VIS_VALUEBRACKET
      parameter(VIS_VALUEBRACKET=1024)
      integer VIS_VALUEBACK
      parameter(VIS_VALUEBACK=2048)
      integer VIS_DOFBACK
      parameter(VIS_DOFBACK=4096)
      integer VIS_ELEMREP_LINE
      parameter(VIS_ELEMREP_LINE=0)
      integer VIS_ELEMREP_SEMI
      parameter(VIS_ELEMREP_SEMI=1)
      integer VIS_ELEMREP_SOLID
      parameter(VIS_ELEMREP_SOLID=2)
      integer VIS_ELEMREP_BITMAP
      parameter(VIS_ELEMREP_BITMAP=3)
      integer VIS_ELEMREP_PIXMAP
      parameter(VIS_ELEMREP_PIXMAP=4)
      integer VIS_ELEMREP_VALUE
      parameter(VIS_ELEMREP_VALUE=5)
      integer VIS_ELEMAXES_NONE
      parameter(VIS_ELEMAXES_NONE=0)
      integer VIS_ELEMAXES_XYZ
      parameter(VIS_ELEMAXES_XYZ=7)
      integer VIS_ELEMAXES_X
      parameter(VIS_ELEMAXES_X=1)
      integer VIS_ELEMAXES_Y
      parameter(VIS_ELEMAXES_Y=2)
      integer VIS_ELEMAXES_Z
      parameter(VIS_ELEMAXES_Z=4)
      integer VIS_TRIANGLE
      parameter(VIS_TRIANGLE=0)
      integer VIS_SQUARE
      parameter(VIS_SQUARE=1)
      integer VIS_DIAMOND
      parameter(VIS_DIAMOND=2)
      integer VIS_HOURGLASS
      parameter(VIS_HOURGLASS=3)
      integer VIS_PLUSSIGN
      parameter(VIS_PLUSSIGN=4)
      integer VIS_CIRCLE
      parameter(VIS_CIRCLE=5)
      integer VIS_DOT
      parameter(VIS_DOT=6)
      integer VIS_POINT
      parameter(VIS_POINT=7)
      integer VIS_DASH
      parameter(VIS_DASH=8)
      integer VIS_SPHERE
      parameter(VIS_SPHERE=9)
      integer VIS_BOX
      parameter(VIS_BOX=10)
      integer VIS_TETRAHEDRON
      parameter(VIS_TETRAHEDRON=11)
      integer VIS_OCTAHEDRON
      parameter(VIS_OCTAHEDRON=12)
      integer VIS_POINT2
      parameter(VIS_POINT2=13)
      integer VIS_POINT4
      parameter(VIS_POINT4=14)
      integer VIS_CIRCLE3
      parameter(VIS_CIRCLE3=15)
      integer VIS_CIRCLE5
      parameter(VIS_CIRCLE5=16)
      integer VIS_CIRCLE7
      parameter(VIS_CIRCLE7=17)
      integer VIS_CIRCLE9
      parameter(VIS_CIRCLE9=18)
      integer VIS_METER
      parameter(VIS_METER=19)
      integer VIS_MARKERMAX
      parameter(VIS_MARKERMAX=19)
      integer VIS_SOLID
      parameter(VIS_SOLID=0)
      integer VIS_DASHDASH
      parameter(VIS_DASHDASH=1)
      integer VIS_DOTDOT
      parameter(VIS_DOTDOT=2)
      integer VIS_DOTDASH
      parameter(VIS_DOTDASH=3)
      integer VIS_CYLINDER
      parameter(VIS_CYLINDER=4)
      integer VIS_VECTORDOUBLEHEAD
      parameter(VIS_VECTORDOUBLEHEAD=2)
      integer VIS_VECTORNOHEAD
      parameter(VIS_VECTORNOHEAD=8)
      integer VIS_VECTORTAIL
      parameter(VIS_VECTORTAIL=16)
      integer VIS_VECTORTAILREGISTER
      parameter(VIS_VECTORTAILREGISTER=32)
      integer VIS_VECTORPUSHHEAD
      parameter(VIS_VECTORPUSHHEAD=128)
      integer VIS_VECTORNOCAP
      parameter(VIS_VECTORNOCAP=256)
      integer VIS_VECTORROUND
      parameter(VIS_VECTORROUND=512)
      integer VIS_VECTORDOUBLEHEADPEN
      parameter(VIS_VECTORDOUBLEHEADPEN=32768)
      integer VIS_VECTORDOUBLEHEADADD
      parameter(VIS_VECTORDOUBLEHEADADD=65536)
      integer VIS_VECTORLINE
      parameter(VIS_VECTORLINE=0)
      integer VIS_VECTORCYLINDER
      parameter(VIS_VECTORCYLINDER=1)
      integer VIS_VECTORUMBRELLA
      parameter(VIS_VECTORUMBRELLA=2)
      integer VIS_TENSORBOX
      parameter(VIS_TENSORBOX=1)
      integer VIS_TENSORDIRECT
      parameter(VIS_TENSORDIRECT=4)
      integer VIS_TENSORSHEAR
      parameter(VIS_TENSORSHEAR=64)
      integer VIS_TENSORCUBE
      parameter(VIS_TENSORCUBE=0)
      integer VIS_TENSORELLIPSOID
      parameter(VIS_TENSORELLIPSOID=1)
      integer VIS_TENSORCROWSFEET
      parameter(VIS_TENSORCROWSFEET=2)
      integer VIS_SHRINKNONE
      parameter(VIS_SHRINKNONE=0)
      integer VIS_SHRINKENTITY
      parameter(VIS_SHRINKENTITY=1)
      integer VIS_SHRINKELEMENT
      parameter(VIS_SHRINKELEMENT=2)
      integer VIS_MAPCOLOR_NONE
      parameter(VIS_MAPCOLOR_NONE=0)
      integer VIS_MAPCOLOR_CONSTANT
      parameter(VIS_MAPCOLOR_CONSTANT=1)
      integer VIS_MAPCOLOR_SMOOTH
      parameter(VIS_MAPCOLOR_SMOOTH=2)
      integer VIS_COMPONENT_PRINCIPAL
      parameter(VIS_COMPONENT_PRINCIPAL=0)
      integer VIS_COMPONENT_BASIC
      parameter(VIS_COMPONENT_BASIC=1)
      integer VIS_COMPONENT_MAXSHEAR
      parameter(VIS_COMPONENT_MAXSHEAR=2)
      integer VIS_BACKPLANEFLIP
      parameter(VIS_BACKPLANEFLIP=8192)
      integer VIS_CREATEPOLYHEDRON
      parameter(VIS_CREATEPOLYHEDRON=16384)
      integer VIS_CYLINDERCAP
      parameter(VIS_CYLINDERCAP=131072)
      integer VIS_ISOVALPOINT
      parameter(VIS_ISOVALPOINT=0)
      integer VIS_ISOVALLINE
      parameter(VIS_ISOVALLINE=1)
      integer VIS_ISOVALSURFACE
      parameter(VIS_ISOVALSURFACE=2)
      integer VIS_ISOVALVOLUME
      parameter(VIS_ISOVALVOLUME=3)
      integer VIS_ISOVALFRINGE
      parameter(VIS_ISOVALFRINGE=4)
      integer VIS_ISOVALTONE
      parameter(VIS_ISOVALTONE=5)
      integer VIS_ISOVALGOURAUD
      parameter(VIS_ISOVALGOURAUD=6)
      integer VIS_ISOVALTEXTURE
      parameter(VIS_ISOVALTEXTURE=7)
      integer VIS_INTERP_SHAPE
      parameter(VIS_INTERP_SHAPE=0)
      integer VIS_INTERP_CLAMP
      parameter(VIS_INTERP_CLAMP=1)
      integer VIS_PRIM_POLY
      parameter(VIS_PRIM_POLY=0)
      integer VIS_PRIM_MULT
      parameter(VIS_PRIM_MULT=1)
      integer VIS_PRIM_ARRAY
      parameter(VIS_PRIM_ARRAY=1)
      integer VIS_PRIM_STRIP
      parameter(VIS_PRIM_STRIP=2)
      integer VIS_ISOVALACCENT
      parameter(VIS_ISOVALACCENT=1)
      integer VIS_TOPOCRITICALPOINT
      parameter(VIS_TOPOCRITICALPOINT=0)
      integer VIS_TOPOVORTEXCORE
      parameter(VIS_TOPOVORTEXCORE=1)
      integer VIS_TOPODIVIDE
      parameter(VIS_TOPODIVIDE=2)
      integer VIS_STREAMLINE
      parameter(VIS_STREAMLINE=0)
      integer VIS_STREAMPOINT
      parameter(VIS_STREAMPOINT=1)
      integer VIS_STREAMRIBBON
      parameter(VIS_STREAMRIBBON=2)
      integer VIS_STREAMTUBE
      parameter(VIS_STREAMTUBE=3)
      integer VIS_STREAMTWIST
      parameter(VIS_STREAMTWIST=4)
      integer VIS_STREAMBOX
      parameter(VIS_STREAMBOX=5)
      integer VIS_STREAMELLIPSE
      parameter(VIS_STREAMELLIPSE=6)
      integer VIS_STREAMZERO
      parameter(VIS_STREAMZERO=0)
      integer VIS_STREAMEXIT
      parameter(VIS_STREAMEXIT=1)
      integer VIS_STREAMBRANCH
      parameter(VIS_STREAMBRANCH=2)
      integer VIS_STREAMMAXSTEPS
      parameter(VIS_STREAMMAXSTEPS=3)
      integer VIS_STREAMMAXEXCEEDED
      parameter(VIS_STREAMMAXEXCEEDED=3)
      integer VIS_STREAMCOMPUTE
      parameter(VIS_STREAMCOMPUTE=4)
      integer VIS_TIMEREVERSE
      parameter(VIS_TIMEREVERSE=1048576)
      integer VIS_NOSHADE
      parameter(VIS_NOSHADE=0)
      integer VIS_FLATSHADE
      parameter(VIS_FLATSHADE=1)
      integer VIS_VERTEXSHADE
      parameter(VIS_VERTEXSHADE=2)
      integer VIS_SIZEWORLD
      parameter(VIS_SIZEWORLD=0)
      integer VIS_SIZEDEVICE
      parameter(VIS_SIZEDEVICE=1)
      integer VIS_RIGHT
      parameter(VIS_RIGHT=0)
      integer VIS_LEFT
      parameter(VIS_LEFT=1)
      integer VIS_BOTTOM
      parameter(VIS_BOTTOM=2)
      integer VIS_TOP
      parameter(VIS_TOP=3)
      integer VIS_CENTER
      parameter(VIS_CENTER=4)
      integer VIS_BOTTOMRIGHT
      parameter(VIS_BOTTOMRIGHT=5)
      integer VIS_TOPRIGHT
      parameter(VIS_TOPRIGHT=6)
      integer VIS_BOTTOMLEFT
      parameter(VIS_BOTTOMLEFT=7)
      integer VIS_TOPLEFT
      parameter(VIS_TOPLEFT=8)
      integer VIS_DRAG_INIT
      parameter(VIS_DRAG_INIT=1)
      integer VIS_DRAG_MOVE
      parameter(VIS_DRAG_MOVE=2)
      integer VIS_DRAG_TERM
      parameter(VIS_DRAG_TERM=3)
      integer VIS_ACTION_NONE
      parameter(VIS_ACTION_NONE=0)
      integer VIS_ACTION_TRANSLATE
      parameter(VIS_ACTION_TRANSLATE=1)
      integer VIS_ACTION_SCALE
      parameter(VIS_ACTION_SCALE=2)
      integer VIS_ACTION_ROTATE
      parameter(VIS_ACTION_ROTATE=3)
      integer VIS_NODATA
      parameter(VIS_NODATA=0)
      integer VIS_CELLDATA
      parameter(VIS_CELLDATA=1)
      integer VIS_VERTEXDATA
      parameter(VIS_VERTEXDATA=2)
      integer VIS_MAT_ISOTROPIC
      parameter(VIS_MAT_ISOTROPIC=0)
      integer VIS_MAT_LAMINA
      parameter(VIS_MAT_LAMINA=1)
      integer VIS_MAT_ORTHOTROPIC
      parameter(VIS_MAT_ORTHOTROPIC=2)
      integer VIS_MAT_ANISOTROPIC
      parameter(VIS_MAT_ANISOTROPIC=3)
      integer VIS_ELEMLOC_CENTROID
      parameter(VIS_ELEMLOC_CENTROID=0)
      integer VIS_ELEMLOC_CORNERS
      parameter(VIS_ELEMLOC_CORNERS=1)
      integer VIS_ELEMLOC_NODES
      parameter(VIS_ELEMLOC_NODES=2)
      integer VIS_ELEMLOC_NATIVE
      parameter(VIS_ELEMLOC_NATIVE=3)
      integer VIS_MESH_MAXI
      parameter(VIS_MESH_MAXI=1)
      integer VIS_MESH_SHAPE
      parameter(VIS_MESH_SHAPE=2)
      integer VIS_MESH_NUMELEMENTS
      parameter(VIS_MESH_NUMELEMENTS=3)
      integer VIS_MESH_INWARD
      parameter(VIS_MESH_INWARD=4)
      integer VIS_MESH_EDGELENGTH
      parameter(VIS_MESH_EDGELENGTH=5)
      integer VIS_MESH_MINEDGELENGTH
      parameter(VIS_MESH_MINEDGELENGTH=6)
      integer VIS_MESH_SPANANGLE
      parameter(VIS_MESH_SPANANGLE=7)
      integer VIS_MESH_BOUNDREFINE
      parameter(VIS_MESH_BOUNDREFINE=8)
      integer VIS_MESH_MINANGLE
      parameter(VIS_MESH_MINANGLE=9)
      integer VIS_MESH_LAGRANGE
      parameter(VIS_MESH_LAGRANGE=10)
      integer VIS_MESH_GROWTHRATE
      parameter(VIS_MESH_GROWTHRATE=11)
      integer VIS_MESH_CHECK
      parameter(VIS_MESH_CHECK=12)
      integer VIS_MESH_MINFEATLENGTH
      parameter(VIS_MESH_MINFEATLENGTH=13)
      integer VIS_MESH_COARSEN
      parameter(VIS_MESH_COARSEN=14)
      integer VIS_MESH_JACOBIANRATIO
      parameter(VIS_MESH_JACOBIANRATIO=15)
      integer VIS_MESH_MIDSIDEPROJ
      parameter(VIS_MESH_MIDSIDEPROJ=16)
      integer VIS_MESH_MIDSIDEQUAL
      parameter(VIS_MESH_MIDSIDEQUAL=17)
      integer VIS_MESH_MINFEATANGLE
      parameter(VIS_MESH_MINFEATANGLE=18)
      integer VIS_MESH_REPAIRINCONS
      parameter(VIS_MESH_REPAIRINCONS=19)
      integer VIS_MESH_QUALTARGET
      parameter(VIS_MESH_QUALTARGET=20)
      integer VIS_MESH_QUALTYPE
      parameter(VIS_MESH_QUALTYPE=21)
      integer VIS_MESH_INTERREFINE
      parameter(VIS_MESH_INTERREFINE=22)
      integer VIS_MESH_CHORDHEIGHT
      parameter(VIS_MESH_CHORDHEIGHT=23)
      integer VIS_MESH_MINHEALLENGTH
      parameter(VIS_MESH_MINHEALLENGTH=24)
      integer VIS_MESH_MINHEALANGLE
      parameter(VIS_MESH_MINHEALANGLE=25)
      integer VIS_MESH_COMPUTENORMAL
      parameter(VIS_MESH_COMPUTENORMAL=26)
      integer VIS_MESH_NUMLAYERS
      parameter(VIS_MESH_NUMLAYERS=27)
      integer VIS_MESH_LAYERINITLENGTH
      parameter(VIS_MESH_LAYERINITLENGTH=28)
      integer VIS_MESH_LAYERGROWTHRATE
      parameter(VIS_MESH_LAYERGROWTHRATE=29)
      integer VIS_MESH_REFINESMOOTH
      parameter(VIS_MESH_REFINESMOOTH=30)
      integer VIS_MESH_MAXEDGELENGTH
      parameter(VIS_MESH_MAXEDGELENGTH=31)
      integer VIS_MESH_MAPDETECT
      parameter(VIS_MESH_MAPDETECT=32)
      integer VIS_MESH_MAPANGLE
      parameter(VIS_MESH_MAPANGLE=33)
      integer VIS_MESH_MAPRECTONLY
      parameter(VIS_MESH_MAPRECTONLY=34)
      integer VIS_MESH_MAXRECTANGLE
      parameter(VIS_MESH_MAXRECTANGLE=35)
      integer VIS_MESH_MAXQUADANGLE
      parameter(VIS_MESH_MAXQUADANGLE=35)
      integer VIS_MESH_UNCONNECT
      parameter(VIS_MESH_UNCONNECT=36)
      integer VIS_MESH_UNCONNECTLENGTH
      parameter(VIS_MESH_UNCONNECTLENGTH=37)
      integer VIS_MESH_UNCONNECTPROJECT
      parameter(VIS_MESH_UNCONNECTPROJECT=38)
      integer VIS_MESH_PROGRESS
      parameter(VIS_MESH_PROGRESS=39)
      integer VIS_MESH_MAXPROXRATIO
      parameter(VIS_MESH_MAXPROXRATIO=40)
      integer VIS_MESH_DELAUNAY
      parameter(VIS_MESH_DELAUNAY=42)
      integer VIS_MESH_QUALMINANG
      parameter(VIS_MESH_QUALMINANG=43)
      integer VIS_MESH_QUALEDGEALT
      parameter(VIS_MESH_QUALEDGEALT=44)
      integer VIS_MESH_REFINETEMPLATE
      parameter(VIS_MESH_REFINETEMPLATE=45)
      integer VIS_MESH_MAXANGLE
      parameter(VIS_MESH_MAXANGLE=46)
      integer VIS_MESH_NONOBTUSE
      parameter(VIS_MESH_NONOBTUSE=47)
      integer VIS_MESH_VERBOSE
      parameter(VIS_MESH_VERBOSE=48)
      integer VIS_MESH_MAXEDGEALT
      parameter(VIS_MESH_MAXEDGEALT=49)
      integer VIS_MESH_GEOMBOX
      parameter(VIS_MESH_GEOMBOX=50)
      integer VIS_MESH_GEOMSPHERE
      parameter(VIS_MESH_GEOMSPHERE=52)
      integer VIS_MESH_GEOMCYLINDER
      parameter(VIS_MESH_GEOMCYLINDER=53)
      integer VIS_MESH_GEOMHEMISPHERE
      parameter(VIS_MESH_GEOMHEMISPHERE=54)
      integer VIS_MESH_REFINEFACTOR
      parameter(VIS_MESH_REFINEFACTOR=55)
      integer VIS_MESH_MAXWARPANGLE
      parameter(VIS_MESH_MAXWARPANGLE=56)
      integer VIS_MESH_MAXSKEWANGLE
      parameter(VIS_MESH_MAXSKEWANGLE=57)
      integer VIS_MESH_POINTSET
      parameter(VIS_MESH_POINTSET=58)
      integer VIS_MESH_HARDMINEDGELENGTH
      parameter(VIS_MESH_HARDMINEDGELENGTH=59)
      integer VIS_MESH_FUNSIZINGMIN
      parameter(VIS_MESH_FUNSIZINGMIN=60)
      integer VIS_MESH_FUNSIZINGLEGACY
      parameter(VIS_MESH_FUNSIZINGLEGACY=61)
      integer VIS_MESH_BIT_GENSPLIT
      parameter(VIS_MESH_BIT_GENSPLIT=1)
      integer VIS_MESH_BIT_GENSWAP
      parameter(VIS_MESH_BIT_GENSWAP=2)
      integer VIS_MESH_BIT_REFSPLIT
      parameter(VIS_MESH_BIT_REFSPLIT=4)
      integer VIS_MESH_BIT_REFSWAP
      parameter(VIS_MESH_BIT_REFSWAP=8)
      integer VIS_STREAM_FLAG
      parameter(VIS_STREAM_FLAG=0)
      integer VIS_STREAM_INTEGER
      parameter(VIS_STREAM_INTEGER=1)
      integer VIS_STREAM_REAL
      parameter(VIS_STREAM_REAL=2)
      integer VIS_STREAM_HOLLERITH
      parameter(VIS_STREAM_HOLLERITH=3)
      integer VIS_STREAM_IDENTIFIER
      parameter(VIS_STREAM_IDENTIFIER=4)
      integer VIS_LEVELS
      parameter(VIS_LEVELS=2010)
      integer VIS_TRANSMAP
      parameter(VIS_TRANSMAP=2020)
      integer VIS_COLORMAP
      parameter(VIS_COLORMAP=2030)
      integer VIS_VISCONTEXT
      parameter(VIS_VISCONTEXT=2040)
      integer VIS_VISCONTEXT_SCALAR
      parameter(VIS_VISCONTEXT_SCALAR=2041)
      integer VIS_VISCONTEXT_VECTOR
      parameter(VIS_VISCONTEXT_VECTOR=2042)
      integer VIS_VISCONTEXT_TENSOR
      parameter(VIS_VISCONTEXT_TENSOR=2043)
      integer VIS_VISCONTEXT_FONT
      parameter(VIS_VISCONTEXT_FONT=2047)
      integer VIS_VISCONTEXT_AXIS
      parameter(VIS_VISCONTEXT_AXIS=2048)
      integer VIS_ISOCLIP
      parameter(VIS_ISOCLIP=2050)
      integer VIS_DATAINT
      parameter(VIS_DATAINT=2060)
      integer VIS_GRIDFUN
      parameter(VIS_GRIDFUN=2070)
      integer VIS_CONNECT
      parameter(VIS_CONNECT=2080)
      integer VIS_STATE
      parameter(VIS_STATE=2090)
      integer VIS_STATE_ROTANG
      parameter(VIS_STATE_ROTANG=2091)
      integer VIS_COORDSYS
      parameter(VIS_COORDSYS=2100)
      integer VIS_IDTRAN
      parameter(VIS_IDTRAN=2110)
      integer VIS_IDTRAN_COLOR
      parameter(VIS_IDTRAN_COLOR=2111)
      integer VIS_IDTRAN_TRANS
      parameter(VIS_IDTRAN_TRANS=2112)
      integer VIS_IDTRAN_NODE
      parameter(VIS_IDTRAN_NODE=2113)
      integer VIS_IDTRAN_ELEM
      parameter(VIS_IDTRAN_ELEM=2114)
      integer VIS_IDTRAN_DATAINDEX
      parameter(VIS_IDTRAN_DATAINDEX=2115)
      integer VIS_IDTRAN_ELEMENT
      parameter(VIS_IDTRAN_ELEMENT=2116)
      integer VIS_IDTRAN_NODESURF
      parameter(VIS_IDTRAN_NODESURF=2117)
      integer VIS_GROUP
      parameter(VIS_GROUP=2120)
      integer VIS_SPACE
      parameter(VIS_SPACE=2140)
      integer VIS_BEAM
      parameter(VIS_BEAM=2150)
      integer VIS_BEAMSECT
      parameter(VIS_BEAMSECT=2160)
      integer VIS_SHELL
      parameter(VIS_SHELL=2170)
      integer VIS_SHELLWALL
      parameter(VIS_SHELLWALL=2180)
      integer VIS_TRIAD
      parameter(VIS_TRIAD=2190)
      integer VIS_LEGEND
      parameter(VIS_LEGEND=2200)
      integer VIS_EDGE
      parameter(VIS_EDGE=2210)
      integer VIS_FACE
      parameter(VIS_FACE=2220)
      integer VIS_SEGMENT
      parameter(VIS_SEGMENT=2230)
      integer VIS_CONTOUR
      parameter(VIS_CONTOUR=2240)
      integer VIS_THRESHOLD
      parameter(VIS_THRESHOLD=2250)
      integer VIS_MARK
      parameter(VIS_MARK=2260)
      integer VIS_VALUE
      parameter(VIS_VALUE=2270)
      integer VIS_SPROP
      parameter(VIS_SPROP=2280)
      integer VIS_EPROP
      parameter(VIS_EPROP=2300)
      integer VIS_MPROP
      parameter(VIS_MPROP=2310)
      integer VIS_LCASE
      parameter(VIS_LCASE=2320)
      integer VIS_RCASE
      parameter(VIS_RCASE=2330)
      integer VIS_ICASE
      parameter(VIS_ICASE=2340)
      integer VIS_MODEL
      parameter(VIS_MODEL=2350)
      integer VIS_TOPOCELL
      parameter(VIS_TOPOCELL=2360)
      integer VIS_GAPELEM
      parameter(VIS_GAPELEM=2370)
      integer VIS_DISCELEM
      parameter(VIS_DISCELEM=2380)
      integer VIS_MASSELEM
      parameter(VIS_MASSELEM=2390)
      integer VIS_BILLBOARD
      parameter(VIS_BILLBOARD=2400)
      integer VIS_RIGIDELEM
      parameter(VIS_RIGIDELEM=2410)
      integer VIS_INFELEM
      parameter(VIS_INFELEM=2420)
      integer VIS_DIMENSION
      parameter(VIS_DIMENSION=2430)
      integer VIS_WORKPLANE
      parameter(VIS_WORKPLANE=2440)
      integer VIS_MAPMESH
      parameter(VIS_MAPMESH=2450)
      integer VIS_TRIMESH
      parameter(VIS_TRIMESH=2460)
      integer VIS_TETMESH
      parameter(VIS_TETMESH=2470)
      integer VIS_VOLMESH
      parameter(VIS_VOLMESH=2471)
      integer VIS_GEOMFUN
      parameter(VIS_GEOMFUN=2480)
      integer VIS_ELEMCHK
      parameter(VIS_ELEMCHK=2490)
      integer VIS_SURFMESH
      parameter(VIS_SURFMESH=2500)
      integer VIS_EXTMESH
      parameter(VIS_EXTMESH=2510)
      integer VIS_MASSPRP
      parameter(VIS_MASSPRP=2520)
      integer VIS_CURVMESH
      parameter(VIS_CURVMESH=2530)
      integer VIS_ELEMDAT
      parameter(VIS_ELEMDAT=2540)
      integer VIS_MCASE
      parameter(VIS_MCASE=2550)
      integer VIS_TCURVE
      parameter(VIS_TCURVE=2560)
      integer VIS_MESHQUAL
      parameter(VIS_MESHQUAL=2570)
      integer VIS_RPROP
      parameter(VIS_RPROP=2580)
      integer VIS_MESHQUAD
      parameter(VIS_MESHQUAD=2590)
      integer VIS_CPAIR
      parameter(VIS_CPAIR=2600)
      integer VIS_HISTORY
      parameter(VIS_HISTORY=2610)
      integer VIS_PRMCLP
      parameter(VIS_PRMCLP=2620)
      integer VIS_UNITS
      parameter(VIS_UNITS=2640)
      integer VIS_TESS
      parameter(VIS_TESS=2650)
      integer VIS_ASURF
      parameter(VIS_ASURF=2660)
      integer VIS_REDMAT
      parameter(VIS_REDMAT=2670)
      integer VIS_HANDLEBOX
      parameter(VIS_HANDLEBOX=2671)
      integer VIS_POLYBOX
      parameter(VIS_POLYBOX=2672)
      integer VIS_ZSTATE
      parameter(VIS_ZSTATE=2673)
      integer VIS_GPROP
      parameter(VIS_GPROP=2674)
      integer VIS_ISOLABEL
      parameter(VIS_ISOLABEL=2675)
      integer VIS_RBODY
      parameter(VIS_RBODY=2676)
      integer VIS_WRITER
      parameter(VIS_WRITER=2677)
      integer NAS_NUMELEMTYPES
      parameter(NAS_NUMELEMTYPES=152)
      integer PAM_NUMELEMTYPES
      parameter(PAM_NUMELEMTYPES=13)
      integer ZSTATE_ELEMNODE
      parameter(ZSTATE_ELEMNODE=0)
      integer ZSTATE_NODE
      parameter(ZSTATE_NODE=1)
      integer ZSTATE_ELEM
      parameter(ZSTATE_ELEM=4)
      integer ZSTATE_TOL
      parameter(ZSTATE_TOL=1)
      integer ZSTATE_NUMLEVELS
      parameter(ZSTATE_NUMLEVELS=2)
      integer ZSTATE_NUMCOARSE
      parameter(ZSTATE_NUMCOARSE=3)
      integer ZSTATE_NUMFINE
      parameter(ZSTATE_NUMFINE=4)
      integer ZSTATE_WRITEMESH
      parameter(ZSTATE_WRITEMESH=5)
      integer ZSTATE_PRINTLEVEL
      parameter(ZSTATE_PRINTLEVEL=6)
      integer ZSTATE_ZEROTOL
      parameter(ZSTATE_ZEROTOL=7)
      integer ZSTATE_NUMZERO
      parameter(ZSTATE_NUMZERO=8)
      integer ZSTATE_SPATIALCONTINUITY
      parameter(ZSTATE_SPATIALCONTINUITY=1)
      integer ZSTATE_BUFSIZE
      parameter(ZSTATE_BUFSIZE=2048)
