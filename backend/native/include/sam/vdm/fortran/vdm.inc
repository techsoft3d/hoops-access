      integer ABAFIL_NUMRESTYPES
      parameter(ABAFIL_NUMRESTYPES=32)
      integer ABAFIL_NUMUNREC
      parameter(ABAFIL_NUMUNREC=-1)
      integer ABAFIL_LINENUM
      parameter(ABAFIL_LINENUM=-2)
      integer ABAFIL_UNRECTYPE
      parameter(ABAFIL_UNRECTYPE=-3)
      integer ABAFIL_UNRECCARD
      parameter(ABAFIL_UNRECCARD=-4)
      integer ABAFIL_UNRECKEYWORD
      parameter(ABAFIL_UNRECKEYWORD=-5)
      integer ABAFIL_UNRECPARAM
      parameter(ABAFIL_UNRECPARAM=-6)
      integer ABAFIL_UNRECPARAMVAL
      parameter(ABAFIL_UNRECPARAMVAL=-7)
      integer ABAFIL_UNRECDATALINE
      parameter(ABAFIL_UNRECDATALINE=-8)
      integer ABAFIL_UNRECFILE
      parameter(ABAFIL_UNRECFILE=-9)
      integer ABAFIL_KEYWORD
      parameter(ABAFIL_KEYWORD=1)
      integer ABAFIL_DATALINE
      parameter(ABAFIL_DATALINE=2)
      integer ABAFIL_UNKNOWN
      parameter(ABAFIL_UNKNOWN=3)
      integer ABAFIL_EOF
      parameter(ABAFIL_EOF=4)
      integer ABAFIL_CONTINUE
      parameter(ABAFIL_CONTINUE=5)
      integer ABAFIL_BLANKLINE
      parameter(ABAFIL_BLANKLINE=6)
      integer ABAFIL_MODE_NONE
      parameter(ABAFIL_MODE_NONE=0)
      integer ABAFIL_MODE_DEFAULT
      parameter(ABAFIL_MODE_DEFAULT=1)
      integer ABAFIL_MODE_COMMA
      parameter(ABAFIL_MODE_COMMA=2)
      integer ABAFIL_MODE_LITERAL
      parameter(ABAFIL_MODE_LITERAL=3)
      integer ABAFIL_MODE_PYTHON
      parameter(ABAFIL_MODE_PYTHON=4)
      integer ABAFIL_LINENUMBER
      parameter(ABAFIL_LINENUMBER=1)
      integer ABALIB_UPGRADEODB
      parameter(ABALIB_UPGRADEODB=1)
      integer ABALIB_UPGRADEODBAUTO
      parameter(ABALIB_UPGRADEODBAUTO=2)
      integer ABA_OUTELEM_WHOLE
      parameter(ABA_OUTELEM_WHOLE=-2)
      integer ABA_OUTELEMNODE_WHOLE
      parameter(ABA_OUTELEMNODE_WHOLE=-3)
      integer ABA_ROTANGELEM
      parameter(ABA_ROTANGELEM=-4)
      integer ABA_ROTANGELEMNODE
      parameter(ABA_ROTANGELEMNODE=-5)
      integer ABA_ROTANGELEMEIP
      parameter(ABA_ROTANGELEMEIP=-6)
      integer ABA_OUTELEM_FACE
      parameter(ABA_OUTELEM_FACE=-7)
      integer ABA_OUTELEM_EDGE
      parameter(ABA_OUTELEM_EDGE=-8)
      integer ABA_SML
      parameter(ABA_SML=1)
      integer ABALIBIO_LENGTH
      parameter(ABALIBIO_LENGTH=1)
      integer ABALIBIO_BYTESWAP
      parameter(ABALIBIO_BYTESWAP=2)
      integer ABALIBIO_WORDSINREC
      parameter(ABALIBIO_WORDSINREC=3)
      integer ABALIBIO_ORIGIN
      parameter(ABALIBIO_ORIGIN=1)
      integer ADAMSLIBIO_PARAMETER
      parameter(ADAMSLIBIO_PARAMETER=1000)
      integer ANSFIL_NUMRESTYPES
      parameter(ANSFIL_NUMRESTYPES=12)
      integer ANSFIL_CONTROLCARDS
      parameter(ANSFIL_CONTROLCARDS=1)
      integer ANSFIL_NUMUNREC
      parameter(ANSFIL_NUMUNREC=-1)
      integer ANSFIL_LINENUM
      parameter(ANSFIL_LINENUM=-2)
      integer ANSFIL_UNRECTYPE
      parameter(ANSFIL_UNRECTYPE=-3)
      integer ANSFIL_UNRECCARD
      parameter(ANSFIL_UNRECCARD=-4)
      integer ANSFIL_UNRECKEYWORD
      parameter(ANSFIL_UNRECKEYWORD=-5)
      integer ANSFIL_UNRECFORMAT
      parameter(ANSFIL_UNRECFORMAT=-6)
      integer ANSFIL_UNRECDATALINE
      parameter(ANSFIL_UNRECDATALINE=-7)
      integer ANSFIL_UNRECPARAM
      parameter(ANSFIL_UNRECPARAM=-8)
      integer ANSFIL_UNRECREFER
      parameter(ANSFIL_UNRECREFER=-9)
      integer ANSFIL_MAXSIZE
      parameter(ANSFIL_MAXSIZE=257)
      integer ANSFIL_MAXELEMENTNODE
      parameter(ANSFIL_MAXELEMENTNODE=81)
      integer ANSFIL_COMMAND
      parameter(ANSFIL_COMMAND=1)
      integer ANSFIL_DATA
      parameter(ANSFIL_DATA=2)
      integer ANSFIL_FORMAT
      parameter(ANSFIL_FORMAT=3)
      integer ANSFIL_EOF
      parameter(ANSFIL_EOF=4)
      integer ANSFIL_UNKNOWN
      parameter(ANSFIL_UNKNOWN=5)
      integer ANSFIL_MAXCHAR
      parameter(ANSFIL_MAXCHAR=641)
      integer ANSFIL_MAXITEMS
      parameter(ANSFIL_MAXITEMS=128)
      integer ANSFIL_FORMAT_SIZE
      parameter(ANSFIL_FORMAT_SIZE=50)
      integer ANSFIL_LINENUMBER
      parameter(ANSFIL_LINENUMBER=1)
      integer ANSLIB_SEARCH_OFF
      parameter(ANSLIB_SEARCH_OFF=0)
      integer ANSLIB_SEARCH_CDB
      parameter(ANSLIB_SEARCH_CDB=1)
      integer ANSLIBIO_RECSIZ
      parameter(ANSLIBIO_RECSIZ=1)
      integer ANSLIBIO_CHARSWAP
      parameter(ANSLIBIO_CHARSWAP=2)
      integer ANSLIBIO_BASEFLAG
      parameter(ANSLIBIO_BASEFLAG=3)
      integer ANSLIBIO_HOSTSWAP
      parameter(ANSLIBIO_HOSTSWAP=4)
      integer ATTRIBUTE_MAXNAME
      parameter(ATTRIBUTE_MAXNAME=0)
      integer ATTRIBUTE_MAXVALUE
      parameter(ATTRIBUTE_MAXVALUE=0)
      integer AUTODYNLIB_LIBVERSION
      parameter(AUTODYNLIB_LIBVERSION=1)
      integer PATH_MAX
      parameter(PATH_MAX=4096)
      integer MAX_ALLOWED_NEIGHBORS
      parameter(MAX_ALLOWED_NEIGHBORS=16)
      integer ELEMENTDATA_RESIZEFACTOR
      parameter(ELEMENTDATA_RESIZEFACTOR=1)
      integer FACEDATA_RESIZFACTOR
      parameter(FACEDATA_RESIZFACTOR=1)
      integer PARALLELCONV_FACESHARINGTHREADS_RSZLEN
      parameter(PARALLELCONV_FACESHARINGTHREADS_RSZLEN=8000)
      integer CONVERTER_MAX_THREAD_COUNT
      parameter(CONVERTER_MAX_THREAD_COUNT=64)
      integer CGNSVLIB_SEARCH_OFF
      parameter(CGNSVLIB_SEARCH_OFF=0)
      integer CGNSVLIB_SEARCH_DIRNUM
      parameter(CGNSVLIB_SEARCH_DIRNUM=1)
      integer CGNSVLIB_SEARCH_DIRNUMFILENUM
      parameter(CGNSVLIB_SEARCH_DIRNUMFILENUM=2)
      integer CGNSVLIB_SEARCH_FILENUM
      parameter(CGNSVLIB_SEARCH_FILENUM=3)
      integer CGNSVLIB_HDF5
      parameter(CGNSVLIB_HDF5=1)
      integer CGNSVLIB_ADF
      parameter(CGNSVLIB_ADF=2)
      integer MAXELEMOFFSETSIZE
      parameter(MAXELEMOFFSETSIZE=10000000)
      integer COMSOLLIBIO_BUFSIZE
      parameter(COMSOLLIBIO_BUFSIZE=256)
      integer COMSOLLIBIO_MAXITEMS
      parameter(COMSOLLIBIO_MAXITEMS=256)
      integer D3DFIL_NUMRESTYPES
      parameter(D3DFIL_NUMRESTYPES=32)
      integer D3DFIL_PARTHEADER_LENGTH
      parameter(D3DFIL_PARTHEADER_LENGTH=133)
      integer D3DFIL_NUMUNREC
      parameter(D3DFIL_NUMUNREC=-1)
      integer D3DFIL_LINENUM
      parameter(D3DFIL_LINENUM=-2)
      integer D3DFIL_UNRECKEYWORD
      parameter(D3DFIL_UNRECKEYWORD=-3)
      integer D3DFIL_UNRECDATALINE
      parameter(D3DFIL_UNRECDATALINE=-4)
      integer D3DFIL_UNRECFILE
      parameter(D3DFIL_UNRECFILE=-5)
      integer D3DFIL_KEYWORD
      parameter(D3DFIL_KEYWORD=1)
      integer D3DFIL_DATALINE
      parameter(D3DFIL_DATALINE=2)
      integer D3DFIL_UNKNOWN
      parameter(D3DFIL_UNKNOWN=3)
      integer D3DFIL_EOF
      parameter(D3DFIL_EOF=4)
      integer D3DFIL_LINENUMBER
      parameter(D3DFIL_LINENUMBER=1)
      integer D3DFIL_MODE_DATA
      parameter(D3DFIL_MODE_DATA=1)
      integer D3DFIL_MODE_LITERAL
      parameter(D3DFIL_MODE_LITERAL=2)
      integer D3DFIL_PARAMETER_DOUBLE
      parameter(D3DFIL_PARAMETER_DOUBLE=2)
      integer D3DFIL_PARAMETER_INT
      parameter(D3DFIL_PARAMETER_INT=2)
      integer D3DFIL_PARAMETER_CHAR
      parameter(D3DFIL_PARAMETER_CHAR=2)
      integer D3DLIB_SEARCH_SWFORC
      parameter(D3DLIB_SEARCH_SWFORC=1)
      integer D3DLIB_SEARCH_SWFORC_OFF
      parameter(D3DLIB_SEARCH_SWFORC_OFF=2)
      integer D3DLIB_SEARCH_NCFORC
      parameter(D3DLIB_SEARCH_NCFORC=3)
      integer D3DLIB_SEARCH_NCFORC_OFF
      parameter(D3DLIB_SEARCH_NCFORC_OFF=4)
      integer D3D_ELEMENT_SOLID
      parameter(D3D_ELEMENT_SOLID=0)
      integer D3D_ELEMENT_BEAM
      parameter(D3D_ELEMENT_BEAM=1)
      integer D3D_ELEMENT_SHELL
      parameter(D3D_ELEMENT_SHELL=2)
      integer D3D_ELEMENT_THICK_SHELL
      parameter(D3D_ELEMENT_THICK_SHELL=3)
      integer D3D_ELEMENT_HEX8
      parameter(D3D_ELEMENT_HEX8=4)
      integer D3D_ELEMENT_HEX20
      parameter(D3D_ELEMENT_HEX20=5)
      integer D3D_ELEMENT_HEX27
      parameter(D3D_ELEMENT_HEX27=6)
      integer D3D_ELEMENT_TET4
      parameter(D3D_ELEMENT_TET4=7)
      integer D3D_ELEMENT_TET10
      parameter(D3D_ELEMENT_TET10=8)
      integer DATAFUN_SETMODE
      parameter(DATAFUN_SETMODE=1)
      integer DATAFUN_SETCONVENTION
      parameter(DATAFUN_SETCONVENTION=2)
      integer DATAFUN_OPEN
      parameter(DATAFUN_OPEN=3)
      integer DATAFUN_CLOSE
      parameter(DATAFUN_CLOSE=4)
      integer DATAFUN_DEFDATASET
      parameter(DATAFUN_DEFDATASET=5)
      integer DATAFUN_GETNUMENTITIES
      parameter(DATAFUN_GETNUMENTITIES=6)
      integer DATAFUN_GETLIBRARY
      parameter(DATAFUN_GETLIBRARY=7)
      integer DATAFUN_WRITEDATASET
      parameter(DATAFUN_WRITEDATASET=8)
      integer DATAFUN_READDATASET
      parameter(DATAFUN_READDATASET=9)
      integer DATAFUN_UPDATE
      parameter(DATAFUN_UPDATE=10)
      integer DATAFUN_SETSTATUS
      parameter(DATAFUN_SETSTATUS=11)
      integer DATAFUN_INCDATASET
      parameter(DATAFUN_INCDATASET=12)
      integer DATAFUN_APPEND
      parameter(DATAFUN_APPEND=13)
      integer DATAFUN_ERROR
      parameter(DATAFUN_ERROR=14)
      integer DATAFUN_WRITEMODEL
      parameter(DATAFUN_WRITEMODEL=15)
      integer DATAFUN_WRITESTATE
      parameter(DATAFUN_WRITESTATE=16)
      integer DATAFUN_SETIDS
      parameter(DATAFUN_SETIDS=17)
      integer DATAFUN_SETCONNECT
      parameter(DATAFUN_SETCONNECT=18)
      integer DATAFUN_GETCONNECT
      parameter(DATAFUN_GETCONNECT=19)
      integer DATAFUN_LIBDATASET
      parameter(DATAFUN_LIBDATASET=20)
      integer DATAFUN_DEFATTRIBUTE
      parameter(DATAFUN_DEFATTRIBUTE=21)
      integer DATAFUN_SETATTVAL
      parameter(DATAFUN_SETATTVAL=22)
      integer DATAFUN_GETATTVAL
      parameter(DATAFUN_GETATTVAL=23)
      integer DATAFUN_NUMDATASETS
      parameter(DATAFUN_NUMDATASETS=24)
      integer DATAFUN_NUMATTRIBUTES
      parameter(DATAFUN_NUMATTRIBUTES=25)
      integer DATAFUN_INQDATASET
      parameter(DATAFUN_INQDATASET=26)
      integer DATAFUN_INQATTRIBUTE
      parameter(DATAFUN_INQATTRIBUTE=27)
      integer DATAFUN_GETINTEGER
      parameter(DATAFUN_GETINTEGER=28)
      integer DATAFUN_GETSTRING
      parameter(DATAFUN_GETSTRING=29)
      integer DATAFUN_NUMDOMAINS
      parameter(DATAFUN_NUMDOMAINS=30)
      integer DATAFUN_PUSHCONTAINER
      parameter(DATAFUN_PUSHCONTAINER=31)
      integer DATAFUN_POPCONTAINER
      parameter(DATAFUN_POPCONTAINER=32)
      integer DATAFUN_READDATASETCOLS
      parameter(DATAFUN_READDATASETCOLS=33)
      integer DATAFUN_SETTHREADSCOUNT
      parameter(DATAFUN_SETTHREADSCOUNT=34)
      integer DATAFUN_SETSTRING
      parameter(DATAFUN_SETSTRING=35)
      integer DATAFUN_GETUNRECOGNIZEDDATA
      parameter(DATAFUN_GETUNRECOGNIZEDDATA=36)
      integer DATAFUN_MAX
      parameter(DATAFUN_MAX=38)
      integer DATAIPC_CLIENT
      parameter(DATAIPC_CLIENT=1)
      integer DATAIPC_SERVER
      parameter(DATAIPC_SERVER=2)
      integer DATAIPC_NET
      parameter(DATAIPC_NET=1)
      integer DATAIPC_LOCAL
      parameter(DATAIPC_LOCAL=2)
      integer DATAIPC_USER
      parameter(DATAIPC_USER=3)
      integer DATAIPC_FUN_MONITOR
      parameter(DATAIPC_FUN_MONITOR=1)
      integer DATAIPC_FUN_WRITE
      parameter(DATAIPC_FUN_WRITE=2)
      integer DATAIPC_FUN_READ
      parameter(DATAIPC_FUN_READ=3)
      integer DATAIPC_FUN_USER
      parameter(DATAIPC_FUN_USER=4)
      integer DATAIPC_BEFORE
      parameter(DATAIPC_BEFORE=0)
      integer DATAIPC_AFTER
      parameter(DATAIPC_AFTER=1)
      integer DATAIPC_DATAFUN
      parameter(DATAIPC_DATAFUN=-1)
      integer DATAIPC_STATE
      parameter(DATAIPC_STATE=-2)
      integer DATAIPC_FILETYPE
      parameter(DATAIPC_FILETYPE=-3)
      integer DATAIPC_FILENAME
      parameter(DATAIPC_FILENAME=-4)
      integer DATASET_MAXNAME
      parameter(DATASET_MAXNAME=0)
      integer DISK_UNKNOWN
      parameter(DISK_UNKNOWN=0)
      integer DISK_OLD
      parameter(DISK_OLD=1)
      integer DISK_NEW
      parameter(DISK_NEW=2)
      integer DISK_ADD
      parameter(DISK_ADD=3)
      integer DISK_MAGIC
      parameter(DISK_MAGIC=101491)
      integer DISK_MAGIC1
      parameter(DISK_MAGIC1=31601)
      integer DISK_MAGIC2
      parameter(DISK_MAGIC2=82610)
      integer DISK_MAGIC3
      parameter(DISK_MAGIC3=32411)
      integer DISK_MAGIC4
      parameter(DISK_MAGIC4=200924)
      integer DISK_OFFMULT
      parameter(DISK_OFFMULT=1)
      integer DISK_OFFMULT1
      parameter(DISK_OFFMULT1=256)
      integer ENSIGHT_FORMAT_UNKNOWN
      parameter(ENSIGHT_FORMAT_UNKNOWN=0)
      integer ENSIGHT_FORMAT_CBIN
      parameter(ENSIGHT_FORMAT_CBIN=1)
      integer ENSIGHT_FORMAT_FBIN
      parameter(ENSIGHT_FORMAT_FBIN=2)
      integer ENSIGHT_FORMAT_ASCII
      parameter(ENSIGHT_FORMAT_ASCII=3)
      integer FEMAPLIBIO_MAXITEMS
      parameter(FEMAPLIBIO_MAXITEMS=20)
      integer FEMAPLIBIO_BUFSIZE
      parameter(FEMAPLIBIO_BUFSIZE=256)
      integer FLUENTLIB_SWAP
      parameter(FLUENTLIB_SWAP=1)
      integer FLUENTLIB_FLOAT
      parameter(FLUENTLIB_FLOAT=2)
      integer FLUENTLIB_OK
      parameter(FLUENTLIB_OK=1)
      integer FLUENTLIB_EOF
      parameter(FLUENTLIB_EOF=2)
      integer FLUENTLIB_UNREC
      parameter(FLUENTLIB_UNREC=3)
      integer FLUENTLIB_BOS
      parameter(FLUENTLIB_BOS=4)
      integer FLUENTLIB_EOS
      parameter(FLUENTLIB_EOS=5)
      integer FLUENTLIB_TRUNC
      parameter(FLUENTLIB_TRUNC=6)
      integer FLUENTLIB_FM_DEF
      parameter(FLUENTLIB_FM_DEF=1)
      integer FLUENTLIB_FM_HEX
      parameter(FLUENTLIB_FM_HEX=2)
      integer FLUENTLIB_FM_BIN4
      parameter(FLUENTLIB_FM_BIN4=3)
      integer FLUENTLIB_FM_BIN8
      parameter(FLUENTLIB_FM_BIN8=4)
      integer GMV_INTERIOR
      parameter(GMV_INTERIOR=-1)
      integer GMV_TRACER
      parameter(GMV_TRACER=-2)
      integer GMV_SURF
      parameter(GMV_SURF=-3)
      integer GMV_BOTH
      parameter(GMV_BOTH=-4)
      integer GMVLIB_SEARCH_OFF
      parameter(GMVLIB_SEARCH_OFF=0)
      integer GMVLIB_SEARCH_FILENUM
      parameter(GMVLIB_SEARCH_FILENUM=1)
      integer GMV_FORMAT_ASCII
      parameter(GMV_FORMAT_ASCII=1)
      integer GMV_FORMAT_BIN
      parameter(GMV_FORMAT_BIN=2)
      integer HMAFIL_NUMUNREC
      parameter(HMAFIL_NUMUNREC=-1)
      integer HMAFIL_LINENUM
      parameter(HMAFIL_LINENUM=-2)
      integer HMAFIL_UNRECCARD
      parameter(HMAFIL_UNRECCARD=-3)
      integer HMAFIL_UNRECKEYWORD
      parameter(HMAFIL_UNRECKEYWORD=-4)
      integer HMAFIL_UNRECTYPE
      parameter(HMAFIL_UNRECTYPE=-5)
      integer HMAFIL_KEYWORD
      parameter(HMAFIL_KEYWORD=1)
      integer HMAFIL_UNKNOWN
      parameter(HMAFIL_UNKNOWN=2)
      integer HMAFIL_EOF
      parameter(HMAFIL_EOF=3)
      integer HMAFIL_LINENUMBER
      parameter(HMAFIL_LINENUMBER=1)
      integer LIB_NATIVE
      parameter(LIB_NATIVE=1)
      integer LIB_GENERIC
      parameter(LIB_GENERIC=5)
      integer LIB_PDA
      parameter(LIB_PDA=6)
      integer LIB_D3DLSTC
      parameter(LIB_D3DLSTC=7)
      integer LIB_ABAODB
      parameter(LIB_ABAODB=8)
      integer LIB_ABAFILBIN
      parameter(LIB_ABAFILBIN=9)
      integer LIB_NASOUTPUT2
      parameter(LIB_NASOUTPUT2=10)
      integer LIB_ABAINPUT
      parameter(LIB_ABAINPUT=13)
      integer LIB_SDRC
      parameter(LIB_SDRC=14)
      integer LIB_PAMDAISY
      parameter(LIB_PAMDAISY=15)
      integer LIB_ANSYSRESULT
      parameter(LIB_ANSYSRESULT=16)
      integer LIB_MECHANICASTUDY
      parameter(LIB_MECHANICASTUDY=17)
      integer LIB_NASBULKDATA
      parameter(LIB_NASBULKDATA=18)
      integer LIB_PATNEUTRAL
      parameter(LIB_PATNEUTRAL=20)
      integer LIB_FLUENT
      parameter(LIB_FLUENT=21)
      integer LIB_ANSYSINPUT
      parameter(LIB_ANSYSINPUT=22)
      integer LIB_MOLDFLOW
      parameter(LIB_MOLDFLOW=23)
      integer LIB_MAXLIBTYPE
      parameter(LIB_MAXLIBTYPE=28)
      integer LMAN_NONZERO
      parameter(LMAN_NONZERO=0)
      integer LMAN_INDEXSTART
      parameter(LMAN_INDEXSTART=1)
      integer LMAN_INDEXSTOP
      parameter(LMAN_INDEXSTOP=2)
      integer LMAN_VERBOSE
      parameter(LMAN_VERBOSE=3)
      integer LMAN_SAVEMODEL_PRE
      parameter(LMAN_SAVEMODEL_PRE=5)
      integer LMAN_FOCUSCONN
      parameter(LMAN_FOCUSCONN=6)
      integer LMAN_NODATAVAL
      parameter(LMAN_NODATAVAL=7)
      integer LMAN_RETAINCONNECT
      parameter(LMAN_RETAINCONNECT=8)
      integer LMAN_LOADRESULT_PRE
      parameter(LMAN_LOADRESULT_PRE=9)
      integer LMAN_LOADMODEL_LOAD
      parameter(LMAN_LOADMODEL_LOAD=11)
      integer LMAN_LOADMODEL_REST
      parameter(LMAN_LOADMODEL_REST=12)
      integer LMAN_LOADMODEL_ELEMGEOM
      parameter(LMAN_LOADMODEL_ELEMGEOM=13)
      integer LMAN_LOADMODEL_SET
      parameter(LMAN_LOADMODEL_SET=14)
      integer LMAN_SAVEMODEL_CASE
      parameter(LMAN_SAVEMODEL_CASE=15)
      integer LMAN_SAVERESULT_CASE
      parameter(LMAN_SAVERESULT_CASE=16)
      integer LMAN_SAVERESULT_PRE
      parameter(LMAN_SAVERESULT_PRE=17)
      integer LMAN_LOADMODEL_PRE
      parameter(LMAN_LOADMODEL_PRE=18)
      integer LMAN_CHECK
      parameter(LMAN_CHECK=19)
      integer LMAN_LOADMODEL_STORE
      parameter(LMAN_LOADMODEL_STORE=20)
      integer LMAN_MESH_LIB_PUSH
      parameter(LMAN_MESH_LIB_PUSH=1)
      integer LMAN_MESH_LIB_POP
      parameter(LMAN_MESH_LIB_POP=2)
      integer LMAN_MESH_LIB_TOP
      parameter(LMAN_MESH_LIB_TOP=3)
      integer MARCFILIO_BUFSIZE
      parameter(MARCFILIO_BUFSIZE=256)
      integer MARCLIB_OK
      parameter(MARCLIB_OK=0)
      integer MARCLIB_ERROR
      parameter(MARCLIB_ERROR=1)
      integer MARCLIB_EOF
      parameter(MARCLIB_EOF=2)
      integer MARCLIBIO_BSIZE
      parameter(MARCLIBIO_BSIZE=1024)
      integer MEMLIB_VERSION
      parameter(MEMLIB_VERSION=-1)
      integer MEMLIB_CREATEDATE
      parameter(MEMLIB_CREATEDATE=-2)
      integer MEMLIB_CREATETIME
      parameter(MEMLIB_CREATETIME=-3)
      integer MEMLIB_UPDATEDATE
      parameter(MEMLIB_UPDATEDATE=-4)
      integer MEMLIB_UPDATETIME
      parameter(MEMLIB_UPDATETIME=-5)
      integer VDM_H5_MAXSEC
      parameter(VDM_H5_MAXSEC=4)
      integer VDM_H5_MAXCORN
      parameter(VDM_H5_MAXCORN=8)
      integer VDM_H5_MAXCOMP
      parameter(VDM_H5_MAXCOMP=8)
      integer VDM_XDB_MAXSEC
      parameter(VDM_XDB_MAXSEC=4)
      integer VDM_XDB_MAXCORN
      parameter(VDM_XDB_MAXCORN=8)
      integer VDM_XDB_MAXCOMP
      parameter(VDM_XDB_MAXCOMP=8)
      integer NAS_NUMRESTYPES
      parameter(NAS_NUMRESTYPES=17)
      integer NASFIL_NUMUNREC
      parameter(NASFIL_NUMUNREC=-1)
      integer NASFIL_LINENUM
      parameter(NASFIL_LINENUM=-2)
      integer NASFIL_UNRECTYPE
      parameter(NASFIL_UNRECTYPE=-3)
      integer NASFIL_UNRECCARD
      parameter(NASFIL_UNRECCARD=-4)
      integer NASFIL_UNRECCOMMAND
      parameter(NASFIL_UNRECCOMMAND=-5)
      integer NASFIL_UNRECFIELD
      parameter(NASFIL_UNRECFIELD=-6)
      integer NASFIL_UNRECFIELDVAL
      parameter(NASFIL_UNRECFIELDVAL=-7)
      integer NASFIL_RELATIVEPATH
      parameter(NASFIL_RELATIVEPATH=1)
      integer NASFIL_RIGIDPBUSHVALUE
      parameter(NASFIL_RIGIDPBUSHVALUE=1)
      integer NASFIL_NO_COORDINATE_SYSTEM
      parameter(NASFIL_NO_COORDINATE_SYSTEM=0)
      integer NASFIL_BASIC_COORDINATE_SYSTEM
      parameter(NASFIL_BASIC_COORDINATE_SYSTEM=1)
      integer NASFIL_GLOBAL_COORDINATE_SYSTEM
      parameter(NASFIL_GLOBAL_COORDINATE_SYSTEM=2)
      integer NASFIL_OFFSET_COORDINATE_SYSTEM
      parameter(NASFIL_OFFSET_COORDINATE_SYSTEM=3)
      integer NASFIL_MAX_RECORDSIZE
      parameter(NASFIL_MAX_RECORDSIZE=256)
      integer NASFIL_FIELDS_PER_CARD
      parameter(NASFIL_FIELDS_PER_CARD=10)
      integer NASFIL_FIELDSIZE
      parameter(NASFIL_FIELDSIZE=8)
      integer NASFIL_CONT_FIELD_START_COLUMN
      parameter(NASFIL_CONT_FIELD_START_COLUMN=73)
      integer NASFIL_INT
      parameter(NASFIL_INT=0)
      integer NASFIL_FLOAT
      parameter(NASFIL_FLOAT=1)
      integer NASFIL_NORMAL
      parameter(NASFIL_NORMAL=0)
      integer NASFIL_COPY_PREVIOUS
      parameter(NASFIL_COPY_PREVIOUS=1)
      integer NASFIL_INCREMENT_INT_PREVIOUS
      parameter(NASFIL_INCREMENT_INT_PREVIOUS=2)
      integer NASFIL_INCREMENT_FLOAT_PREVIOUS
      parameter(NASFIL_INCREMENT_FLOAT_PREVIOUS=3)
      integer NASFIL_COPY_REST_PREVIOUS
      parameter(NASFIL_COPY_REST_PREVIOUS=4)
      integer NASFIL_REPEAT_PREVIOUS
      parameter(NASFIL_REPEAT_PREVIOUS=5)
      integer NASFIL_COMMON_STRING_SIZE
      parameter(NASFIL_COMMON_STRING_SIZE=17)
      integer NASFIL_ILINENUM
      parameter(NASFIL_ILINENUM=1)
      integer NASFIL_ISAVEDLINENUM
      parameter(NASFIL_ISAVEDLINENUM=2)
      integer NASFIL_CURRENTFIELD
      parameter(NASFIL_CURRENTFIELD=3)
      integer NASLIBIO_ILP64
      parameter(NASLIBIO_ILP64=1)
      integer NASLIBIO_BYTESWAP
      parameter(NASLIBIO_BYTESWAP=2)
      integer NASLIBIO_VENDOR
      parameter(NASLIBIO_VENDOR=3)
      integer NASLIBIO_NOIDARRAY
      parameter(NASLIBIO_NOIDARRAY=1)
      integer MAXNATDATASET
      parameter(MAXNATDATASET=4096)
      integer NATLIB_BASE
      parameter(NATLIB_BASE=0)
      integer NATLIB_SWAP
      parameter(NATLIB_SWAP=1)
      integer NATLIB_VERSION
      parameter(NATLIB_VERSION=-1)
      integer NATLIB_CREATEDATE
      parameter(NATLIB_CREATEDATE=-2)
      integer NATLIB_CREATETIME
      parameter(NATLIB_CREATETIME=-3)
      integer NATLIB_UPDATEDATE
      parameter(NATLIB_UPDATEDATE=-4)
      integer NATLIB_UPDATETIME
      parameter(NATLIB_UPDATETIME=-5)
      integer OPENFOAMLIB_SEARCH_DEFAULT
      parameter(OPENFOAMLIB_SEARCH_DEFAULT=0)
      integer OPENFOAMLIB_SEARCH_RECONSTRUCT
      parameter(OPENFOAMLIB_SEARCH_RECONSTRUCT=1)
      integer OPENFOAM_BUFFSIZE
      parameter(OPENFOAM_BUFFSIZE=4096)
      integer OPENFOAM_FORMAT_ASCII
      parameter(OPENFOAM_FORMAT_ASCII=1)
      integer OPENFOAM_FORMAT_BIN
      parameter(OPENFOAM_FORMAT_BIN=2)
      integer OPENFOAM_TYPE_NONE
      parameter(OPENFOAM_TYPE_NONE=0)
      integer OPENFOAM_TYPE_DATA
      parameter(OPENFOAM_TYPE_DATA=1)
      integer OPENFOAM_TYPE_BEGINARRAY
      parameter(OPENFOAM_TYPE_BEGINARRAY=2)
      integer OPENFOAM_TYPE_ENDARRAY
      parameter(OPENFOAM_TYPE_ENDARRAY=3)
      integer OPENFOAM_TYPE_BEGINDICT
      parameter(OPENFOAM_TYPE_BEGINDICT=4)
      integer OPENFOAM_TYPE_ENDDICT
      parameter(OPENFOAM_TYPE_ENDDICT=5)
      integer OPENFOAM_TYPE_ENDKEY
      parameter(OPENFOAM_TYPE_ENDKEY=6)
      integer OPENFOAM_TYPE_BEGINDIM
      parameter(OPENFOAM_TYPE_BEGINDIM=7)
      integer OPENFOAM_TYPE_ENDDIM
      parameter(OPENFOAM_TYPE_ENDDIM=8)
      integer OPENFOAM_TYPE_BEGINLIST
      parameter(OPENFOAM_TYPE_BEGINLIST=9)
      integer OPENFOAM_TYPE_ENDLIST
      parameter(OPENFOAM_TYPE_ENDLIST=10)
      integer OPENFOAM_TYPE_EOF
      parameter(OPENFOAM_TYPE_EOF=11)
      integer OPENFOAM_TYPE_ERROR
      parameter(OPENFOAM_TYPE_ERROR=12)
      integer OPENFOAMLIBIO_INC
      parameter(OPENFOAMLIBIO_INC=1)
      integer OPENFOAMLIBIO_GO
      parameter(OPENFOAMLIBIO_GO=2)
      integer OPENFOAMLIBIO_INCEXT
      parameter(OPENFOAMLIBIO_INCEXT=3)
      integer OPENFOAMLIBIO_INC_ETC
      parameter(OPENFOAMLIBIO_INC_ETC=4)
      integer OPENFOAM_MAXWORD
      parameter(OPENFOAM_MAXWORD=256)
      integer PAMFIL_NUMRESTYPES
      parameter(PAMFIL_NUMRESTYPES=32)
      integer PAMFIL_NUMUNREC
      parameter(PAMFIL_NUMUNREC=-1)
      integer PAMFIL_LINENUM
      parameter(PAMFIL_LINENUM=-2)
      integer PAMFIL_UNRECKEYWORD
      parameter(PAMFIL_UNRECKEYWORD=-3)
      integer PAMFIL_UNRECDATALINE
      parameter(PAMFIL_UNRECDATALINE=-4)
      integer PAMFIL_UNRECFILE
      parameter(PAMFIL_UNRECFILE=-5)
      integer PAMFIL_KEYWORD
      parameter(PAMFIL_KEYWORD=1)
      integer PAMFIL_COMMENT
      parameter(PAMFIL_COMMENT=2)
      integer PAMFIL_CONTROL
      parameter(PAMFIL_CONTROL=3)
      integer PAMFIL_NONE
      parameter(PAMFIL_NONE=4)
      integer PAMFIL_EOF
      parameter(PAMFIL_EOF=5)
      integer PAMFIL_LINENUMBER
      parameter(PAMFIL_LINENUMBER=1)
      integer PATLIB_NODAL
      parameter(PATLIB_NODAL=1)
      integer PATLIB_DISPLACEMENT
      parameter(PATLIB_DISPLACEMENT=2)
      integer PATLIB_ELEMENTAL
      parameter(PATLIB_ELEMENTAL=3)
      integer PATLIB_TITLE_MAXNAME
      parameter(PATLIB_TITLE_MAXNAME=83)
      integer PERMASDAT_SECTION
      parameter(PERMASDAT_SECTION=1)
      integer PERMASDAT_CID
      parameter(PERMASDAT_CID=2)
      integer PLEX_CLOSEAPPEND
      parameter(PLEX_CLOSEAPPEND=1)
      integer PLOT3DLIB_AUTO
      parameter(PLOT3DLIB_AUTO=0)
      integer PLOT3DLIB_SINGLE
      parameter(PLOT3DLIB_SINGLE=1)
      integer PLOT3DLIB_MULTIPLE
      parameter(PLOT3DLIB_MULTIPLE=2)
      integer PLOT3DLIB_1D
      parameter(PLOT3DLIB_1D=1)
      integer PLOT3DLIB_2D
      parameter(PLOT3DLIB_2D=2)
      integer PLOT3DLIB_3DWHOLE
      parameter(PLOT3DLIB_3DWHOLE=3)
      integer PLOT3DLIB_3DPLANES
      parameter(PLOT3DLIB_3DPLANES=4)
      integer PLOT3DLIB_UNSTRUCTURED
      parameter(PLOT3DLIB_UNSTRUCTURED=5)
      integer PLOT3DLIB_Q
      parameter(PLOT3DLIB_Q=1)
      integer PLOT3DLIB_FUNCTION
      parameter(PLOT3DLIB_FUNCTION=2)
      integer TECPLOTLIB_MERGESHAPE
      parameter(TECPLOTLIB_MERGESHAPE=1)
      integer TECPLOTLIB_OK
      parameter(TECPLOTLIB_OK=0)
      integer TECPLOTLIB_EOF
      parameter(TECPLOTLIB_EOF=1)
      integer TECPLOTLIB_ZONE
      parameter(TECPLOTLIB_ZONE=2)
      integer TECPLOTLIB_DATA
      parameter(TECPLOTLIB_DATA=3)
      integer TECPLOTLIB_SKIP_ZONE
      parameter(TECPLOTLIB_SKIP_ZONE=1)
      integer TECPLOTLIB_SKIP_DATA
      parameter(TECPLOTLIB_SKIP_DATA=2)
      integer TECPLOTLIB_SKIP_ZONEDATA
      parameter(TECPLOTLIB_SKIP_ZONEDATA=3)
      integer TECPLOTLIBIO_FORMAT
      parameter(TECPLOTLIBIO_FORMAT=1)
      integer TECPLOTLIBIO_BYTESWAP
      parameter(TECPLOTLIBIO_BYTESWAP=2)
      integer TECPLOTLIBIO_VERSION
      parameter(TECPLOTLIBIO_VERSION=3)
      integer TECPLOTLIBIO_KEYWORD
      parameter(TECPLOTLIBIO_KEYWORD=0)
      integer TECPLOTLIBIO_EOF
      parameter(TECPLOTLIBIO_EOF=1)
      integer ABA_NUMELEMTYPES
      parameter(ABA_NUMELEMTYPES=226)
      integer VDM_ADAPTER_UNDEFINED
      parameter(VDM_ADAPTER_UNDEFINED=0)
      integer VDM_ADAPTER_ANSYS_DPF
      parameter(VDM_ADAPTER_ANSYS_DPF=1)
      integer VDM_ADAPTER_PLUGIN
      parameter(VDM_ADAPTER_PLUGIN=2)
      integer VDM_ADAPTER_MAX
      parameter(VDM_ADAPTER_MAX=3)
      integer VDM_NATIVE
      parameter(VDM_NATIVE=0)
      integer VDM_PLOT3D_GRID
      parameter(VDM_PLOT3D_GRID=0)
      integer VDM_PLOT3D_SOLUTION
      parameter(VDM_PLOT3D_SOLUTION=0)
      integer VDM_PATRAN_RESULT
      parameter(VDM_PATRAN_RESULT=0)
      integer VDM_GENERIC
      parameter(VDM_GENERIC=0)
      integer VDM_PDA
      parameter(VDM_PDA=0)
      integer VDM_LSTC_STATE
      parameter(VDM_LSTC_STATE=0)
      integer VDM_ABAQUS_ODB
      parameter(VDM_ABAQUS_ODB=0)
      integer VDM_ABAQUS_FILBIN
      parameter(VDM_ABAQUS_FILBIN=0)
      integer VDM_ABAQUS_FIL
      parameter(VDM_ABAQUS_FIL=0)
      integer VDM_NASTRAN_OUTPUT2
      parameter(VDM_NASTRAN_OUTPUT2=0)
      integer VDM_STL
      parameter(VDM_STL=0)
      integer VDM_STLBIN
      parameter(VDM_STLBIN=0)
      integer VDM_ABAQUS_INPUT
      parameter(VDM_ABAQUS_INPUT=0)
      integer VDM_SDRC_UNIVERSAL
      parameter(VDM_SDRC_UNIVERSAL=0)
      integer VDM_PAM_DAISY
      parameter(VDM_PAM_DAISY=0)
      integer VDM_ANSYS_RESULT
      parameter(VDM_ANSYS_RESULT=0)
      integer VDM_MECHANICA_STUDY
      parameter(VDM_MECHANICA_STUDY=0)
      integer VDM_NASTRAN_BULKDATA
      parameter(VDM_NASTRAN_BULKDATA=0)
      integer VDM_FDI_NEUTRAL
      parameter(VDM_FDI_NEUTRAL=0)
      integer VDM_PAT_NEUTRAL
      parameter(VDM_PAT_NEUTRAL=0)
      integer VDM_PATRAN_NEUTRAL
      parameter(VDM_PATRAN_NEUTRAL=0)
      integer VDM_FLUENT_MESH
      parameter(VDM_FLUENT_MESH=0)
      integer VDM_ANSYS_INPUT
      parameter(VDM_ANSYS_INPUT=0)
      integer VDM_TECPLOT
      parameter(VDM_TECPLOT=0)
      integer VDM_HYPERMESH_ASCII
      parameter(VDM_HYPERMESH_ASCII=0)
      integer VDM_LSTC_INPUT
      parameter(VDM_LSTC_INPUT=0)
      integer VDM_CGNS
      parameter(VDM_CGNS=0)
      integer VDM_MARC_POST
      parameter(VDM_MARC_POST=0)
      integer VDM_ENSIGHT
      parameter(VDM_ENSIGHT=0)
      integer VDM_STARCCM
      parameter(VDM_STARCCM=0)
      integer VDM_MECHANICA_FNF
      parameter(VDM_MECHANICA_FNF=0)
      integer VDM_LSTC_HISTORY
      parameter(VDM_LSTC_HISTORY=0)
      integer VDM_NASTRAN_XDB
      parameter(VDM_NASTRAN_XDB=0)
      integer VDM_NASTRAN_H5
      parameter(VDM_NASTRAN_H5=0)
      integer VDM_POLYFLOW
      parameter(VDM_POLYFLOW=0)
      integer VDM_FEMAP_NEUTRAL
      parameter(VDM_FEMAP_NEUTRAL=0)
      integer VDM_AUTODYN_RES
      parameter(VDM_AUTODYN_RES=0)
      integer VDM_PAM_ERF
      parameter(VDM_PAM_ERF=0)
      integer VDM_OPENFOAM
      parameter(VDM_OPENFOAM=0)
      integer VDM_OBJ
      parameter(VDM_OBJ=0)
      integer VDM_COMSOL_SECTION
      parameter(VDM_COMSOL_SECTION=0)
      integer VDM_H3D
      parameter(VDM_H3D=0)
      integer VDM_LSTC_STATEFEMZIP
      parameter(VDM_LSTC_STATEFEMZIP=0)
      integer VDM_PAM_INPUT
      parameter(VDM_PAM_INPUT=0)
      integer VDM_CFX_RESULT
      parameter(VDM_CFX_RESULT=0)
      integer VDM_GMV
      parameter(VDM_GMV=0)
      integer VDM_PERMAS_POST
      parameter(VDM_PERMAS_POST=0)
      integer VDM_VTK_LEGACY
      parameter(VDM_VTK_LEGACY=0)
      integer VDM_SAMCEF
      parameter(VDM_SAMCEF=0)
      integer VDM_AFLR
      parameter(VDM_AFLR=0)
      integer VDM_ADAMS
      parameter(VDM_ADAMS=0)
      integer VDM_NATIVE_HDF5
      parameter(VDM_NATIVE_HDF5=0)
      integer VDM_MEMORY
      parameter(VDM_MEMORY=0)
      integer VDM_COMSOL_MPH
      parameter(VDM_COMSOL_MPH=0)
      integer VDM_COMSOL_MPHBIN
      parameter(VDM_COMSOL_MPHBIN=0)
      integer VDM_MARC_INPUT
      parameter(VDM_MARC_INPUT=0)
      integer VDM_ANSYS_DPF
      parameter(VDM_ANSYS_DPF=0)
      integer VDM_PLUGIN
      parameter(VDM_PLUGIN=0)
      integer VDM_VTK_VTU
      parameter(VDM_VTK_VTU=0)
      integer VDM_MAXTYPE
      parameter(VDM_MAXTYPE=0)
      integer VDM_STATUS_OLD
      parameter(VDM_STATUS_OLD=1)
      integer VDM_STATUS_NEW
      parameter(VDM_STATUS_NEW=2)
      integer VDM_STATUS_ADD
      parameter(VDM_STATUS_ADD=3)
      integer VDM_ONFILE
      parameter(VDM_ONFILE=1000)
      integer VDM_VIRTUAL
      parameter(VDM_VIRTUAL=1001)
      integer VDM_ELEMNODEPNTR
      parameter(VDM_ELEMNODEPNTR=1002)
      integer VDM_ELEMNODESIZE
      parameter(VDM_ELEMNODESIZE=1003)
      integer VDM_ELEMNODE
      parameter(VDM_ELEMNODE=1004)
      integer VDM_ELEMTYPE
      parameter(VDM_ELEMTYPE=1005)
      integer VDM_ELEMTYPEINT
      parameter(VDM_ELEMTYPEINT=1007)
      integer VDM_ELEMTYPEHOL
      parameter(VDM_ELEMTYPEHOL=1008)
      integer VDM_EID
      parameter(VDM_EID=1009)
      integer VDM_MID
      parameter(VDM_MID=1010)
      integer VDM_PID
      parameter(VDM_PID=1011)
      integer VDM_PARAMINT
      parameter(VDM_PARAMINT=1012)
      integer VDM_PARAMHOL
      parameter(VDM_PARAMHOL=1013)
      integer VDM_ERSCID
      parameter(VDM_ERSCID=1014)
      integer VDM_COLORELEM
      parameter(VDM_COLORELEM=1015)
      integer VDM_PARTIDELEM
      parameter(VDM_PARTIDELEM=1016)
      integer VDM_ORIENTELEM
      parameter(VDM_ORIENTELEM=1017)
      integer VDM_ERSVEC
      parameter(VDM_ERSVEC=1018)
      integer VDM_SETELEM
      parameter(VDM_SETELEM=1019)
      integer VDM_X
      parameter(VDM_X=1020)
      integer VDM_SETNODE
      parameter(VDM_SETNODE=1021)
      integer VDM_NID
      parameter(VDM_NID=1022)
      integer VDM_NODETYPE
      parameter(VDM_NODETYPE=1023)
      integer VDM_SETELEMENT
      parameter(VDM_SETELEMENT=1024)
      integer VDM_DOFCID
      parameter(VDM_DOFCID=1025)
      integer VDM_DOF
      parameter(VDM_DOF=1026)
      integer VDM_COLORNODE
      parameter(VDM_COLORNODE=1027)
      integer VDM_PARTIDNODE
      parameter(VDM_PARTIDNODE=1028)
      integer VDM_COLORMAP
      parameter(VDM_COLORMAP=1029)
      integer VDM_ELEMTOPO
      parameter(VDM_ELEMTOPO=1030)
      integer VDM_ELEMSPEC
      parameter(VDM_ELEMSPEC=1031)
      integer VDM_ELEMTWOD
      parameter(VDM_ELEMTWOD=1032)
      integer VDM_PARAMIJK
      parameter(VDM_PARAMIJK=1033)
      integer VDM_IBLANKNODE
      parameter(VDM_IBLANKNODE=1034)
      integer VDM_ELEMTYPEEXT
      parameter(VDM_ELEMTYPEEXT=1035)
      integer VDM_ELEMSIZE
      parameter(VDM_ELEMSIZE=1036)
      integer VDM_ELEMSHAP
      parameter(VDM_ELEMSHAP=1037)
      integer VDM_ELEMMIJK
      parameter(VDM_ELEMMIJK=1038)
      integer VDM_ELEMTECH
      parameter(VDM_ELEMTECH=1039)
      integer VDM_DIRCOS
      parameter(VDM_DIRCOS=1040)
      integer VDM_ELEMEIPS
      parameter(VDM_ELEMEIPS=1041)
      integer VDM_CREFID
      parameter(VDM_CREFID=1042)
      integer VDM_ELEMSEID
      parameter(VDM_ELEMSEID=1043)
      integer VDM_ELEMSYMMID
      parameter(VDM_ELEMSYMMID=1044)
      integer VDM_THICKNESS
      parameter(VDM_THICKNESS=1050)
      integer VDM_NORMAL
      parameter(VDM_NORMAL=1051)
      integer VDM_OFFSETVEC
      parameter(VDM_OFFSETVEC=1052)
      integer VDM_FIBERBOT
      parameter(VDM_FIBERBOT=1053)
      integer VDM_FIBERTOP
      parameter(VDM_FIBERTOP=1054)
      integer VDM_OFFSET
      parameter(VDM_OFFSET=1055)
      integer VDM_DOMAINNODE
      parameter(VDM_DOMAINNODE=1058)
      integer VDM_DOMAINELEM
      parameter(VDM_DOMAINELEM=1059)
      integer VDM_EMTCID
      parameter(VDM_EMTCID=1060)
      integer VDM_EMTVEC
      parameter(VDM_EMTVEC=1061)
      integer VDM_EMTFLAG
      parameter(VDM_EMTFLAG=1062)
      integer VDM_ENDATOPO
      parameter(VDM_ENDATOPO=1063)
      integer VDM_ENDBTOPO
      parameter(VDM_ENDBTOPO=1064)
      integer VDM_ENDACON
      parameter(VDM_ENDACON=1065)
      integer VDM_ENDBCON
      parameter(VDM_ENDBCON=1066)
      integer VDM_ENDAVEC
      parameter(VDM_ENDAVEC=1067)
      integer VDM_ENDBVEC
      parameter(VDM_ENDBVEC=1068)
      integer VDM_NODEGEOVERT
      parameter(VDM_NODEGEOVERT=1069)
      integer VDM_NODEGEOEDGE
      parameter(VDM_NODEGEOEDGE=1070)
      integer VDM_NODEGEOFACE
      parameter(VDM_NODEGEOFACE=1071)
      integer VDM_NODEGEOBODY
      parameter(VDM_NODEGEOBODY=1072)
      integer VDM_ELEMGEOEDGE
      parameter(VDM_ELEMGEOEDGE=1073)
      integer VDM_ELEMGEOFACE
      parameter(VDM_ELEMGEOFACE=1074)
      integer VDM_ELEMGEOBODY
      parameter(VDM_ELEMGEOBODY=1075)
      integer VDM_ELEMEDGEGEOEDGE
      parameter(VDM_ELEMEDGEGEOEDGE=1076)
      integer VDM_ELEMFACEGEOFACE
      parameter(VDM_ELEMFACEGEOFACE=1077)
      integer VDM_PINFLAGSELEM
      parameter(VDM_PINFLAGSELEM=1078)
      integer VDM_MISCID
      parameter(VDM_MISCID=101079)
      integer VDM_MISCID0
      parameter(VDM_MISCID0=101079)
      integer VDM_MISCID1
      parameter(VDM_MISCID1=101080)
      integer VDM_MISCID2
      parameter(VDM_MISCID2=101081)
      integer VDM_MISCID3
      parameter(VDM_MISCID3=101082)
      integer VDM_MISCID4
      parameter(VDM_MISCID4=101083)
      integer VDM_MISCID5
      parameter(VDM_MISCID5=101084)
      integer VDM_MISCID6
      parameter(VDM_MISCID6=101085)
      integer VDM_MISCID7
      parameter(VDM_MISCID7=101086)
      integer VDM_MISCID8
      parameter(VDM_MISCID8=101087)
      integer VDM_MISCIDELEMFACE
      parameter(VDM_MISCIDELEMFACE=101088)
      integer VDM_MISCID0ELEMFACE
      parameter(VDM_MISCID0ELEMFACE=101088)
      integer VDM_MISCID1ELEMFACE
      parameter(VDM_MISCID1ELEMFACE=101089)
      integer VDM_MISCID2ELEMFACE
      parameter(VDM_MISCID2ELEMFACE=101090)
      integer VDM_MISCID3ELEMFACE
      parameter(VDM_MISCID3ELEMFACE=101091)
      integer VDM_MISCID4ELEMFACE
      parameter(VDM_MISCID4ELEMFACE=101092)
      integer VDM_MISCID5ELEMFACE
      parameter(VDM_MISCID5ELEMFACE=101093)
      integer VDM_MISCID6ELEMFACE
      parameter(VDM_MISCID6ELEMFACE=101094)
      integer VDM_MISCID7ELEMFACE
      parameter(VDM_MISCID7ELEMFACE=101095)
      integer VDM_MISCID8ELEMFACE
      parameter(VDM_MISCID8ELEMFACE=101096)
      integer VDM_MISCIDELEMEDGE
      parameter(VDM_MISCIDELEMEDGE=101097)
      integer VDM_MISCID0ELEMEDGE
      parameter(VDM_MISCID0ELEMEDGE=101097)
      integer VDM_MISCID1ELEMEDGE
      parameter(VDM_MISCID1ELEMEDGE=101098)
      integer VDM_MISCID2ELEMEDGE
      parameter(VDM_MISCID2ELEMEDGE=101099)
      integer VDM_MISCID3ELEMEDGE
      parameter(VDM_MISCID3ELEMEDGE=101100)
      integer VDM_MISCID4ELEMEDGE
      parameter(VDM_MISCID4ELEMEDGE=101101)
      integer VDM_MISCID5ELEMEDGE
      parameter(VDM_MISCID5ELEMEDGE=101092)
      integer VDM_MISCID6ELEMEDGE
      parameter(VDM_MISCID6ELEMEDGE=101103)
      integer VDM_MISCID7ELEMEDGE
      parameter(VDM_MISCID7ELEMEDGE=101104)
      integer VDM_MISCID8ELEMEDGE
      parameter(VDM_MISCID8ELEMEDGE=101105)
      integer VDM_PARTNAMEID
      parameter(VDM_PARTNAMEID=1080)
      integer VDM_PARTNAME
      parameter(VDM_PARTNAME=1081)
      integer VDM_ELEMTANGEDGE
      parameter(VDM_ELEMTANGEDGE=1082)
      integer VDM_ELEMTANGEDGEINDX
      parameter(VDM_ELEMTANGEDGEINDX=1083)
      integer VDM_ELEMNORMFACE
      parameter(VDM_ELEMNORMFACE=1085)
      integer VDM_ELEMNORMFACEINDX
      parameter(VDM_ELEMNORMFACEINDX=1086)
      integer VDM_PARTIJKID
      parameter(VDM_PARTIJKID=1088)
      integer VDM_PARTIJK
      parameter(VDM_PARTIJK=1089)
      integer VDM_IDE
      parameter(VDM_IDE=1090)
      integer VDM_IDN
      parameter(VDM_IDN=1091)
      integer VDM_CSYS
      parameter(VDM_CSYS=1100)
      integer VDM_CSYSID
      parameter(VDM_CSYSID=1101)
      integer VDM_CSYSTYPE
      parameter(VDM_CSYSTYPE=1102)
      integer VDM_UNITSTYPE
      parameter(VDM_UNITSTYPE=1103)
      integer VDM_UNITS
      parameter(VDM_UNITS=1104)
      integer VDM_REST
      parameter(VDM_REST=1110)
      integer VDM_RESTDISP
      parameter(VDM_RESTDISP=1111)
      integer VDM_RESTINDX
      parameter(VDM_RESTINDX=1112)
      integer VDM_RESTTAG
      parameter(VDM_RESTTAG=1113)
      integer VDM_RESTMAST
      parameter(VDM_RESTMAST=1114)
      integer VDM_RESTNAME
      parameter(VDM_RESTNAME=1115)
      integer VDM_RESTELEM
      parameter(VDM_RESTELEM=1116)
      integer VDM_RESTELEMDISP
      parameter(VDM_RESTELEMDISP=1117)
      integer VDM_RESTELEMINDX
      parameter(VDM_RESTELEMINDX=1118)
      integer VDM_RESTELEMTAG
      parameter(VDM_RESTELEMTAG=1119)
      integer VDM_RESTTID
      parameter(VDM_RESTTID=1120)
      integer VDM_RESTDOT
      parameter(VDM_RESTDOT=1121)
      integer VDM_LOADACCL
      parameter(VDM_LOADACCL=1123)
      integer VDM_LOADNAME
      parameter(VDM_LOADNAME=1124)
      integer VDM_LOADTEMPNODETID
      parameter(VDM_LOADTEMPNODETID=1125)
      integer VDM_LOADHEATNODETID
      parameter(VDM_LOADHEATNODETID=1126)
      integer VDM_LOADCSCANODETID
      parameter(VDM_LOADCSCANODETID=1127)
      integer VDM_LOADCVECNODETID
      parameter(VDM_LOADCVECNODETID=1128)
      integer VDM_LOADTID
      parameter(VDM_LOADTID=1129)
      integer VDM_MATL
      parameter(VDM_MATL=1130)
      integer VDM_MATLID
      parameter(VDM_MATLID=1131)
      integer VDM_MATLTYPE
      parameter(VDM_MATLTYPE=1132)
      integer VDM_MATLINT
      parameter(VDM_MATLINT=1133)
      integer VDM_MATLFLAG
      parameter(VDM_MATLFLAG=1135)
      integer VDM_MATLNAME
      parameter(VDM_MATLNAME=1136)
      integer VDM_LOADTEMPNODE
      parameter(VDM_LOADTEMPNODE=1140)
      integer VDM_LOADHEATNODE
      parameter(VDM_LOADHEATNODE=1141)
      integer VDM_LOADCSCANODE
      parameter(VDM_LOADCSCANODE=1142)
      integer VDM_LOADCVECNODE
      parameter(VDM_LOADCVECNODE=1143)
      integer VDM_LOAD
      parameter(VDM_LOAD=1144)
      integer VDM_LOADTEMPNODEINDX
      parameter(VDM_LOADTEMPNODEINDX=1145)
      integer VDM_LOADHEATNODEINDX
      parameter(VDM_LOADHEATNODEINDX=1146)
      integer VDM_LOADCSCANODEINDX
      parameter(VDM_LOADCSCANODEINDX=1147)
      integer VDM_LOADCVECNODEINDX
      parameter(VDM_LOADCVECNODEINDX=1148)
      integer VDM_LOADINDX
      parameter(VDM_LOADINDX=1149)
      integer VDM_PROP
      parameter(VDM_PROP=1150)
      integer VDM_PROPID
      parameter(VDM_PROPID=1151)
      integer VDM_PROPTYPE
      parameter(VDM_PROPTYPE=1152)
      integer VDM_PROPINT
      parameter(VDM_PROPINT=1153)
      integer VDM_PROPHOL
      parameter(VDM_PROPHOL=1154)
      integer VDM_PROPFLAG
      parameter(VDM_PROPFLAG=1155)
      integer VDM_PROPNAME
      parameter(VDM_PROPNAME=1156)
      integer VDM_SOLN
      parameter(VDM_SOLN=1160)
      integer VDM_SOLNID
      parameter(VDM_SOLNID=1161)
      integer VDM_SOLNTYPE
      parameter(VDM_SOLNTYPE=1162)
      integer VDM_SOLNINT
      parameter(VDM_SOLNINT=1163)
      integer VDM_SOLNHOL
      parameter(VDM_SOLNHOL=1164)
      integer VDM_SOLNFLAG
      parameter(VDM_SOLNFLAG=1165)
      integer VDM_MPCNODE
      parameter(VDM_MPCNODE=1170)
      integer VDM_MPCCOMP
      parameter(VDM_MPCCOMP=1171)
      integer VDM_MPCCOEF
      parameter(VDM_MPCCOEF=1172)
      integer VDM_MPCSIZE
      parameter(VDM_MPCSIZE=1173)
      integer VDM_MPCRHS
      parameter(VDM_MPCRHS=1174)
      integer VDM_MPCELEM
      parameter(VDM_MPCELEM=1175)
      integer VDM_MPCTYPE
      parameter(VDM_MPCTYPE=1176)
      integer VDM_FUNC
      parameter(VDM_FUNC=1180)
      integer VDM_FUNCID
      parameter(VDM_FUNCID=1181)
      integer VDM_FUNCTYPE
      parameter(VDM_FUNCTYPE=1182)
      integer VDM_FUNCINT
      parameter(VDM_FUNCINT=1183)
      integer VDM_INITDOF
      parameter(VDM_INITDOF=1190)
      integer VDM_INITDOFINDX
      parameter(VDM_INITDOFINDX=1191)
      integer VDM_INITDOFTAG
      parameter(VDM_INITDOFTAG=1192)
      integer VDM_INITDOFDOT
      parameter(VDM_INITDOFDOT=1193)
      integer VDM_INITDOFDOTINDX
      parameter(VDM_INITDOFDOTINDX=1194)
      integer VDM_INITDOFDOTTAG
      parameter(VDM_INITDOFDOTTAG=1195)
      integer VDM_LOADPRESEDGE
      parameter(VDM_LOADPRESEDGE=1200)
      integer VDM_LOADPRESEDGEINDX
      parameter(VDM_LOADPRESEDGEINDX=1201)
      integer VDM_LOADPRESEDGETID
      parameter(VDM_LOADPRESEDGETID=1202)
      integer VDM_LOADPRESFACE
      parameter(VDM_LOADPRESFACE=1205)
      integer VDM_LOADPRESFACEINDX
      parameter(VDM_LOADPRESFACEINDX=1206)
      integer VDM_LOADPRESFACETID
      parameter(VDM_LOADPRESFACETID=1207)
      integer VDM_LOADFLUXEDGE
      parameter(VDM_LOADFLUXEDGE=1210)
      integer VDM_LOADFLUXEDGEINDX
      parameter(VDM_LOADFLUXEDGEINDX=1211)
      integer VDM_LOADFLUXEDGETID
      parameter(VDM_LOADFLUXEDGETID=1212)
      integer VDM_LOADFLUXFACE
      parameter(VDM_LOADFLUXFACE=1215)
      integer VDM_LOADFLUXFACEINDX
      parameter(VDM_LOADFLUXFACEINDX=1216)
      integer VDM_LOADFLUXFACETID
      parameter(VDM_LOADFLUXFACETID=1217)
      integer VDM_LOADTRACEDGE
      parameter(VDM_LOADTRACEDGE=1220)
      integer VDM_LOADTRACEDGEINDX
      parameter(VDM_LOADTRACEDGEINDX=1221)
      integer VDM_LOADTRACEDGETID
      parameter(VDM_LOADTRACEDGETID=1222)
      integer VDM_LOADTRACFACE
      parameter(VDM_LOADTRACFACE=1225)
      integer VDM_LOADTRACFACEINDX
      parameter(VDM_LOADTRACFACEINDX=1226)
      integer VDM_LOADTRACFACETID
      parameter(VDM_LOADTRACFACETID=1227)
      integer VDM_LOADHEATELEM
      parameter(VDM_LOADHEATELEM=1230)
      integer VDM_LOADHEATELEMINDX
      parameter(VDM_LOADHEATELEMINDX=1231)
      integer VDM_LOADHEATELEMTID
      parameter(VDM_LOADHEATELEMTID=1232)
      integer VDM_LOADACCLELEM
      parameter(VDM_LOADACCLELEM=1234)
      integer VDM_LOADACCLELEMINDX
      parameter(VDM_LOADACCLELEMINDX=1235)
      integer VDM_LOADACCLELEMTID
      parameter(VDM_LOADACCLELEMTID=1236)
      integer VDM_LOADCONVEDGE
      parameter(VDM_LOADCONVEDGE=1240)
      integer VDM_LOADCONVEDGEINDX
      parameter(VDM_LOADCONVEDGEINDX=1241)
      integer VDM_LOADCONVEDGETID
      parameter(VDM_LOADCONVEDGETID=1242)
      integer VDM_LOADCONVFACE
      parameter(VDM_LOADCONVFACE=1245)
      integer VDM_LOADCONVFACEINDX
      parameter(VDM_LOADCONVFACEINDX=1246)
      integer VDM_LOADCONVFACETID
      parameter(VDM_LOADCONVFACETID=1247)
      integer VDM_LOADDMOMEDGE
      parameter(VDM_LOADDMOMEDGE=1250)
      integer VDM_LOADDMOMEDGEINDX
      parameter(VDM_LOADDMOMEDGEINDX=1251)
      integer VDM_LOADDMOMEDGETID
      parameter(VDM_LOADDMOMEDGETID=1252)
      integer VDM_LOADDMOMFACE
      parameter(VDM_LOADDMOMFACE=1255)
      integer VDM_LOADDMOMFACEINDX
      parameter(VDM_LOADDMOMFACEINDX=1256)
      integer VDM_LOADDMOMFACETID
      parameter(VDM_LOADDMOMFACETID=1257)
      integer VDM_LOADDSCAEDGE
      parameter(VDM_LOADDSCAEDGE=1260)
      integer VDM_LOADDSCAEDGEINDX
      parameter(VDM_LOADDSCAEDGEINDX=1261)
      integer VDM_LOADDSCAEDGETID
      parameter(VDM_LOADDSCAEDGETID=1262)
      integer VDM_LOADDSCAFACE
      parameter(VDM_LOADDSCAFACE=1265)
      integer VDM_LOADDSCAFACEINDX
      parameter(VDM_LOADDSCAFACEINDX=1266)
      integer VDM_LOADDSCAFACETID
      parameter(VDM_LOADDSCAFACETID=1267)
      integer VDM_LOADDVECEDGE
      parameter(VDM_LOADDVECEDGE=1270)
      integer VDM_LOADDVECEDGEINDX
      parameter(VDM_LOADDVECEDGEINDX=1271)
      integer VDM_LOADDVECEDGETID
      parameter(VDM_LOADDVECEDGETID=1272)
      integer VDM_LOADDVECFACE
      parameter(VDM_LOADDVECFACE=1275)
      integer VDM_LOADDVECFACEINDX
      parameter(VDM_LOADDVECFACEINDX=1276)
      integer VDM_LOADDVECFACETID
      parameter(VDM_LOADDVECFACETID=1277)
      integer VDM_LOADHRADEDGE
      parameter(VDM_LOADHRADEDGE=1290)
      integer VDM_LOADHRADEDGEINDX
      parameter(VDM_LOADHRADEDGEINDX=1291)
      integer VDM_LOADHRADEDGETID
      parameter(VDM_LOADHRADEDGETID=1292)
      integer VDM_LOADHRADFACE
      parameter(VDM_LOADHRADFACE=1295)
      integer VDM_LOADHRADFACEINDX
      parameter(VDM_LOADHRADFACEINDX=1296)
      integer VDM_LOADHRADFACETID
      parameter(VDM_LOADHRADFACETID=1297)
      integer VDM_GLOB
      parameter(VDM_GLOB=1280)
      integer VDM_GLOBINT
      parameter(VDM_GLOBINT=1283)
      integer VDM_GLOBHOL
      parameter(VDM_GLOBHOL=1284)
      integer VDM_GLOBFLAG
      parameter(VDM_GLOBFLAG=1285)
      integer VDM_CONT
      parameter(VDM_CONT=1300)
      integer VDM_CONTFLAG
      parameter(VDM_CONTFLAG=1301)
      integer VDM_CONTINT
      parameter(VDM_CONTINT=1302)
      integer VDM_CONTTYPE
      parameter(VDM_CONTTYPE=1310)
      integer VDM_CONTMASTASURF
      parameter(VDM_CONTMASTASURF=1323)
      integer VDM_CONTMASTELEMFACE
      parameter(VDM_CONTMASTELEMFACE=1324)
      integer VDM_CONTMASTELEMEDGE
      parameter(VDM_CONTMASTELEMEDGE=1325)
      integer VDM_CONTSLAVAREA
      parameter(VDM_CONTSLAVAREA=1333)
      integer VDM_CONTSLAVNODE
      parameter(VDM_CONTSLAVNODE=1334)
      integer VDM_CONTSLAVELEMFACE
      parameter(VDM_CONTSLAVELEMFACE=1335)
      integer VDM_CONTSLAVELEMEDGE
      parameter(VDM_CONTSLAVELEMEDGE=1336)
      integer VDM_CONVERSIONTIME
      parameter(VDM_CONVERSIONTIME=1337)
      integer VDM_CONVERSIONSTATUS
      parameter(VDM_CONVERSIONSTATUS=1338)
      integer VDM_EFFECTIVEMASSSUMMARY
      parameter(VDM_EFFECTIVEMASSSUMMARY=1339)
      integer VDM_EFFECTIVEMASS
      parameter(VDM_EFFECTIVEMASS=1340)
      integer VDM_PARTICIPATIONFACTOR
      parameter(VDM_PARTICIPATIONFACTOR=1341)
      integer VDM_MASSFRACTION
      parameter(VDM_MASSFRACTION=1342)
      integer VDM_POLYUNIQUEFACE
      parameter(VDM_POLYUNIQUEFACE=1343)
      integer VDM_LOADHRADABSORPEDGE
      parameter(VDM_LOADHRADABSORPEDGE=1350)
      integer VDM_LOADHRADABSORPEDGEINDX
      parameter(VDM_LOADHRADABSORPEDGEINDX=1351)
      integer VDM_LOADHRADABSORPEDGETID
      parameter(VDM_LOADHRADABSORPEDGETID=1352)
      integer VDM_LOADHRADABSORPFACE
      parameter(VDM_LOADHRADABSORPFACE=1355)
      integer VDM_LOADHRADABSORPFACEINDX
      parameter(VDM_LOADHRADABSORPFACEINDX=1356)
      integer VDM_LOADHRADABSORPFACETID
      parameter(VDM_LOADHRADABSORPFACETID=1357)
      integer VDM_OUTELEM
      parameter(VDM_OUTELEM=2000)
      integer VDM_OUTELEMNODEAVGD
      parameter(VDM_OUTELEMNODEAVGD=2001)
      integer VDM_OUTELEMNODEFREE
      parameter(VDM_OUTELEMNODEFREE=2002)
      integer VDM_OUTHISTELEM
      parameter(VDM_OUTHISTELEM=2100)
      integer VDM_OUTELEMINDEX
      parameter(VDM_OUTELEMINDEX=2101)
      integer VDM_OUTNODE
      parameter(VDM_OUTNODE=3000)
      integer VDM_OUTHISTNODE
      parameter(VDM_OUTHISTNODE=3100)
      integer VDM_OUTNODEINDEX
      parameter(VDM_OUTNODEINDEX=3101)
      integer VDM_OUTELEMNODE
      parameter(VDM_OUTELEMNODE=4000)
      integer VDM_OUTHISTELEMNODE
      parameter(VDM_OUTHISTELEMNODE=4003)
      integer VDM_OUTHISTMODEL
      parameter(VDM_OUTHISTMODEL=5100)
      integer VDM_OUTHISTTIME
      parameter(VDM_OUTHISTTIME=5101)
      integer VDM_OUTHISTSTEP
      parameter(VDM_OUTHISTSTEP=5102)
      integer VDM_OUTNODECOMP
      parameter(VDM_OUTNODECOMP=5103)
      integer VDM_OUTELEMCOMP
      parameter(VDM_OUTELEMCOMP=5104)
      integer VDM_OUTELEMSECT
      parameter(VDM_OUTELEMSECT=5105)
      integer VDM_OUTELEMLAYS
      parameter(VDM_OUTELEMLAYS=5106)
      integer VDM_OUTENTDOF
      parameter(VDM_OUTENTDOF=5107)
      integer VDM_OUTMODE
      parameter(VDM_OUTMODE=5108)
      integer VDM_OUTMODEINDEX
      parameter(VDM_OUTMODEINDEX=5109)
      integer VDM_OUTHISTMODE
      parameter(VDM_OUTHISTMODE=5110)
      integer VDM_OUTPANEL
      parameter(VDM_OUTPANEL=5111)
      integer VDM_OUTPANELINDEX
      parameter(VDM_OUTPANELINDEX=5112)
      integer VDM_OUTHISTPANEL
      parameter(VDM_OUTHISTPANEL=5113)
      integer VDM_OUTEDGEINDEX
      parameter(VDM_OUTEDGEINDEX=5114)
      integer VDM_OUTFACEINDEX
      parameter(VDM_OUTFACEINDEX=5115)
      integer VDM_OUTELEMEIP
      parameter(VDM_OUTELEMEIP=5116)
      integer VDM_OUTMATSIZE
      parameter(VDM_OUTMATSIZE=5117)
      integer VDM_OUTMATEQUN
      parameter(VDM_OUTMATEQUN=5118)
      integer VDM_ASURFTYPE
      parameter(VDM_ASURFTYPE=6000)
      integer VDM_ASURFSEGS
      parameter(VDM_ASURFSEGS=6001)
      integer VDM_ASURFSEGTYPE
      parameter(VDM_ASURFSEGTYPE=6002)
      integer VDM_ASURFPNTS
      parameter(VDM_ASURFPNTS=6003)
      integer VDM_ASURFDBL
      parameter(VDM_ASURFDBL=6004)
      integer VDM_ASURFNAME
      parameter(VDM_ASURFNAME=6005)
      integer VDM_ASURFFACET
      parameter(VDM_ASURFFACET=6006)
      integer VDM_ASURFFACETTYPE
      parameter(VDM_ASURFFACETTYPE=6007)
      integer VDM_ASURFTRIM
      parameter(VDM_ASURFTRIM=6008)
      integer VDM_ASURFTRIMNUM
      parameter(VDM_ASURFTRIMNUM=6009)
      integer VDM_ASURFNURBS
      parameter(VDM_ASURFNURBS=6010)
      integer VDM_ASURFNURBSNUM
      parameter(VDM_ASURFNURBSNUM=6011)
      integer VDM_ASURFNURBSTRIM
      parameter(VDM_ASURFNURBSTRIM=6012)
      integer VDM_RBODY
      parameter(VDM_RBODY=6100)
      integer VDM_RBODYFLAG
      parameter(VDM_RBODYFLAG=6101)
      integer VDM_RBODYINT
      parameter(VDM_RBODYINT=6102)
      integer VDM_RBODYTYPE
      parameter(VDM_RBODYTYPE=6103)
      integer VDM_RBODYASURF
      parameter(VDM_RBODYASURF=6104)
      integer VDM_RBODYELEMFACE
      parameter(VDM_RBODYELEMFACE=6105)
      integer VDM_RBODYELEMEDGE
      parameter(VDM_RBODYELEMEDGE=6106)
      integer VDM_RBODYELEM
      parameter(VDM_RBODYELEM=6107)
      integer VDM_RBODYNODE
      parameter(VDM_RBODYNODE=6108)
      integer VDM_RBODYNODETYPE
      parameter(VDM_RBODYNODETYPE=6109)
      integer VDM_DATASETCOLS_UNDEF
      parameter(VDM_DATASETCOLS_UNDEF=-1)
      integer VDM_DATASETCOLS_UNSUP
      parameter(VDM_DATASETCOLS_UNSUP=-2)
      integer VDM_NODATAVALMODE
      parameter(VDM_NODATAVALMODE=1)
      integer VDM_RETAINCONNECTMODE
      parameter(VDM_RETAINCONNECTMODE=2)
      integer VDM_ABAODBNOCLOSEMODE
      parameter(VDM_ABAODBNOCLOSEMODE=3)
      integer VDM_INCLUDEERRORMODE
      parameter(VDM_INCLUDEERRORMODE=4)
      integer VDM_ZLIBCOMPRESSMODE
      parameter(VDM_ZLIBCOMPRESSMODE=5)
      integer VDM_ANSYS_PARTIDNUMBERINGMODE
      parameter(VDM_ANSYS_PARTIDNUMBERINGMODE=6)
      integer VDM_CGNS_FAMILYSPECIFIED
      parameter(VDM_CGNS_FAMILYSPECIFIED=7)
      integer VDM_CGNS_MULTIZONESEXPORT
      parameter(VDM_CGNS_MULTIZONESEXPORT=8)
      integer VDM_CGNS_ZONEFACECENTER
      parameter(VDM_CGNS_ZONEFACECENTER=9)
      integer VDM_DPFLIB_ROTATETOGLOBALFRAME
      parameter(VDM_DPFLIB_ROTATETOGLOBALFRAME=10)
      integer VDM_DPFLIB_CHECKVERSION
      parameter(VDM_DPFLIB_CHECKVERSION=11)
      integer VDM_WRITEFORMAT
      parameter(VDM_WRITEFORMAT=12)
      integer VDM_HEADERPRECISION
      parameter(VDM_HEADERPRECISION=13)
      integer VDM_DPFLIB_ASSUMELICENSING
      parameter(VDM_DPFLIB_ASSUMELICENSING=14)
      integer VDM_DEFERREDREADMODE
      parameter(VDM_DEFERREDREADMODE=15)
      integer VDM_CGNS_POLYASELEMENTASSOC
      parameter(VDM_CGNS_POLYASELEMENTASSOC=16)
      integer VDM_ABAODBAUTOUPDATE
      parameter(VDM_ABAODBAUTOUPDATE=17)
      integer VDM_NODATAVAL
      parameter(VDM_NODATAVAL=17)
      integer EXPORT_ASCII
      parameter(EXPORT_ASCII=0)
      integer EXPORT_BINARY
      parameter(EXPORT_BINARY=1)
      integer HEADERUINT32
      parameter(HEADERUINT32=0)
      integer HEADERUINT64
      parameter(HEADERUINT64=1)
      integer VDM_PHASE
      parameter(VDM_PHASE=1)
      integer VDM_SOURCE
      parameter(VDM_SOURCE=2)
      integer VDM_SOURCE_SIZE
      parameter(VDM_SOURCE_SIZE=256)
      integer VDM_PHASE_UNDEFINED
      parameter(VDM_PHASE_UNDEFINED=0)
      integer VDM_PHASE_OPENMODEL
      parameter(VDM_PHASE_OPENMODEL=1)
      integer VDM_PHASE_OPENMODELCOMPLETE
      parameter(VDM_PHASE_OPENMODELCOMPLETE=2)
      integer VDM_PHASE_OPENRESULT
      parameter(VDM_PHASE_OPENRESULT=3)
      integer VDM_OPENPLEX
      parameter(VDM_OPENPLEX=-1)
      integer VDM_IDS_OFFSET
      parameter(VDM_IDS_OFFSET=0)
      integer VDM_IDS_BASE
      parameter(VDM_IDS_BASE=1)
      integer VDM_IDS_ABSOLUTE
      parameter(VDM_IDS_ABSOLUTE=2)
      integer VDM_LIBDATASET_PUSH
      parameter(VDM_LIBDATASET_PUSH=1)
      integer VDM_LIBDATASET_POP
      parameter(VDM_LIBDATASET_POP=2)
      integer VDM_LIBDATASET_TOP
      parameter(VDM_LIBDATASET_TOP=3)
      integer VDM_ATTRIBUTE
      parameter(VDM_ATTRIBUTE=6000)
      integer VDM_DATASET
      parameter(VDM_DATASET=6001)
      integer VDM_LIBRARY
      parameter(VDM_LIBRARY=6002)
      integer VDM_DATAFUN
      parameter(VDM_DATAFUN=6003)
      integer VDM_LMAN
      parameter(VDM_LMAN=6004)
      integer VDM_DATAIPC
      parameter(VDM_DATAIPC=6005)
      integer VDM_ELEMSECT
      parameter(VDM_ELEMSECT=6006)
      integer VDM_UNRECOGNIZEDDATA
      parameter(VDM_UNRECOGNIZEDDATA=6007)
      integer VDM_OPENFOAM_ETC_PATH
      parameter(VDM_OPENFOAM_ETC_PATH=1)
      integer VDM_LIBRARY_PATH
      parameter(VDM_LIBRARY_PATH=2)
      integer VDM_ABALIB_UPGRADEODBNAME
      parameter(VDM_ABALIB_UPGRADEODBNAME=3)
      integer ANSLIB_PARTIDUSINGLEGACYMETHOD
      parameter(ANSLIB_PARTIDUSINGLEGACYMETHOD=0)
      integer ANSLIB_PARTIDUSINGSECNUM
      parameter(ANSLIB_PARTIDUSINGSECNUM=1)
      integer ANSLIB_PARTIDUSINGREALCONSTREF_NUMBER
      parameter(ANSLIB_PARTIDUSINGREALCONSTREF_NUMBER=2)
      integer ANSLIB_PARTIDUSINGELEM_TYPE
      parameter(ANSLIB_PARTIDUSINGELEM_TYPE=3)
      integer PAM_LAYERPOSITION_BEAM1
      parameter(PAM_LAYERPOSITION_BEAM1=9)
      integer PAM_LAYERPOSITION_BEAM2
      parameter(PAM_LAYERPOSITION_BEAM2=10)
      integer PAM_LAYERPOSITION_BEAM3
      parameter(PAM_LAYERPOSITION_BEAM3=11)
      integer PAM_LAYERPOSITION_BEAM4
      parameter(PAM_LAYERPOSITION_BEAM4=12)
      integer PAM_LAYERPOSITION_BEAM12
      parameter(PAM_LAYERPOSITION_BEAM12=13)
      integer PAM_LAYERPOSITION_BEAM13
      parameter(PAM_LAYERPOSITION_BEAM13=14)
      integer PAM_LAYERPOSITION_BEAM14
      parameter(PAM_LAYERPOSITION_BEAM14=15)
      integer PAM_LAYERPOSITION_BEAM23
      parameter(PAM_LAYERPOSITION_BEAM23=16)
      integer PAM_LAYERPOSITION_BEAM24
      parameter(PAM_LAYERPOSITION_BEAM24=17)
      integer PAM_LAYERPOSITION_BEAM34
      parameter(PAM_LAYERPOSITION_BEAM34=18)
      integer PAM_LAYERPOSITION_BEAM123
      parameter(PAM_LAYERPOSITION_BEAM123=19)
      integer PAM_LAYERPOSITION_BEAM124
      parameter(PAM_LAYERPOSITION_BEAM124=20)
      integer PAM_LAYERPOSITION_BEAM234
      parameter(PAM_LAYERPOSITION_BEAM234=21)
      integer PAM_LAYERPOSITION_BEAM134
      parameter(PAM_LAYERPOSITION_BEAM134=22)
      integer PAM_LAYERPOSITION_BEAM1234
      parameter(PAM_LAYERPOSITION_BEAM1234=23)
      integer MARCLIB_IPT_NONE
      parameter(MARCLIB_IPT_NONE=0)
      integer MARCLIB_IPT_LINE_LINE2_1PT
      parameter(MARCLIB_IPT_LINE_LINE2_1PT=1)
      integer MARCLIB_IPT_LINE_LINE2_2PT
      parameter(MARCLIB_IPT_LINE_LINE2_2PT=2)
      integer MARCLIB_IPT_LINE_LINE3_2PT
      parameter(MARCLIB_IPT_LINE_LINE3_2PT=3)
      integer MARCLIB_IPT_LINE_LINE2_3PT
      parameter(MARCLIB_IPT_LINE_LINE2_3PT=4)
      integer MARCLIB_IPT_LINE_LINE3_3PT
      parameter(MARCLIB_IPT_LINE_LINE3_3PT=5)
      integer MARCLIB_IPT_LINE_2NODE
      parameter(MARCLIB_IPT_LINE_2NODE=6)
      integer MARCLIB_IPT_LINE_QUAD4_2PT
      parameter(MARCLIB_IPT_LINE_QUAD4_2PT=7)
      integer MARCLIB_IPT_LINE_QUAD8_6PT
      parameter(MARCLIB_IPT_LINE_QUAD8_6PT=8)
      integer MARCLIB_IPT_LINE_AVG_2PT
      parameter(MARCLIB_IPT_LINE_AVG_2PT=9)
      integer MARCLIB_IPT_TRI3_1PT
      parameter(MARCLIB_IPT_TRI3_1PT=10)
      integer MARCLIB_IPT_TRI6_1PT
      parameter(MARCLIB_IPT_TRI6_1PT=11)
      integer MARCLIB_IPT_TRI3_3PT
      parameter(MARCLIB_IPT_TRI3_3PT=12)
      integer MARCLIB_IPT_TRI6_3PT
      parameter(MARCLIB_IPT_TRI6_3PT=13)
      integer MARCLIB_IPT_TRI_7PT
      parameter(MARCLIB_IPT_TRI_7PT=14)
      integer MARCLIB_IPT_QUAD_1PT
      parameter(MARCLIB_IPT_QUAD_1PT=15)
      integer MARCLIB_IPT_QUAD4_4PT
      parameter(MARCLIB_IPT_QUAD4_4PT=16)
      integer MARCLIB_IPT_QUAD8_4PT
      parameter(MARCLIB_IPT_QUAD8_4PT=17)
      integer MARCLIB_IPT_QUAD_AVG_4PT
      parameter(MARCLIB_IPT_QUAD_AVG_4PT=18)
      integer MARCLIB_IPT_QUAD_9PT
      parameter(MARCLIB_IPT_QUAD_9PT=19)
      integer MARCLIB_IPT_QUAD_AVG_9PT
      parameter(MARCLIB_IPT_QUAD_AVG_9PT=20)
      integer MARCLIB_IPT_QUAD_INF_9PT
      parameter(MARCLIB_IPT_QUAD_INF_9PT=21)
      integer MARCLIB_IPT_QUAD_4NODE
      parameter(MARCLIB_IPT_QUAD_4NODE=22)
      integer MARCLIB_IPT_QUAD_6PT
      parameter(MARCLIB_IPT_QUAD_6PT=23)
      integer MARCLIB_IPT_QUAD_28PT
      parameter(MARCLIB_IPT_QUAD_28PT=24)
      integer MARCLIB_IPT_QUAD_HEX8_4PT
      parameter(MARCLIB_IPT_QUAD_HEX8_4PT=25)
      integer MARCLIB_IPT_QUAD_HEX20_4PT
      parameter(MARCLIB_IPT_QUAD_HEX20_4PT=26)
      integer MARCLIB_IPT_TET_1PT
      parameter(MARCLIB_IPT_TET_1PT=27)
      integer MARCLIB_IPT_TET_4PT
      parameter(MARCLIB_IPT_TET_4PT=28)
      integer MARCLIB_IPT_HEX_1PT
      parameter(MARCLIB_IPT_HEX_1PT=29)
      integer MARCLIB_IPT_HEX8_8PT
      parameter(MARCLIB_IPT_HEX8_8PT=30)
      integer MARCLIB_IPT_HEX20_8PT
      parameter(MARCLIB_IPT_HEX20_8PT=31)
      integer MARCLIB_IPT_HEX_27PT
      parameter(MARCLIB_IPT_HEX_27PT=32)
      integer MARCLIB_IPT_HEX_INF_27PT
      parameter(MARCLIB_IPT_HEX_INF_27PT=33)
      integer MARCLIB_IPT_HEX_12PT
      parameter(MARCLIB_IPT_HEX_12PT=34)
      integer MARCLIB_IPT_WED_21PT
      parameter(MARCLIB_IPT_WED_21PT=35)
      integer MARCLIB_IPT_WED_6PT
      parameter(MARCLIB_IPT_WED_6PT=36)
      integer MARCLIB_IPT_PYR_5PT
      parameter(MARCLIB_IPT_PYR_5PT=37)
      integer MARCLIB_IPT_PYR_14PT
      parameter(MARCLIB_IPT_PYR_14PT=38)
      integer MARCLIB_RULE_GAUSS
      parameter(MARCLIB_RULE_GAUSS=38)
      integer MARCLIB_RULE_LOBATTO
      parameter(MARCLIB_RULE_LOBATTO=38)
      integer MARCLIB_RULE_AVERAGE
      parameter(MARCLIB_RULE_AVERAGE=-3)
      integer MARCLIB_RULE_QUADINF
      parameter(MARCLIB_RULE_QUADINF=-4)
      integer MARCLIB_RULE_HEXINF
      parameter(MARCLIB_RULE_HEXINF=-5)
      integer MARCLIB_RULE_4TRI7
      parameter(MARCLIB_RULE_4TRI7=-6)
      integer MARCLIB_RULE_4_8
      parameter(MARCLIB_RULE_4_8=-7)
      integer MARCLIB_RULE_4_20
      parameter(MARCLIB_RULE_4_20=-8)
      integer MARC_NUMELEMTYPES
      parameter(MARC_NUMELEMTYPES=243)
      integer PERMASLIB_NONE
      parameter(PERMASLIB_NONE=0)
      integer PERMASLIB_CORNER
      parameter(PERMASLIB_CORNER=1)
      integer PERMASLIB_SECTION
      parameter(PERMASLIB_SECTION=2)
      integer SDRC_NUMELEMTYPES
      parameter(SDRC_NUMELEMTYPES=196)
      integer VTK_DS_NONE
      parameter(VTK_DS_NONE=0)
      integer VTK_DS_STRUCTURED_POINTS
      parameter(VTK_DS_STRUCTURED_POINTS=1)
      integer VTK_DS_STRUCTURED_GRID
      parameter(VTK_DS_STRUCTURED_GRID=2)
      integer VTK_DS_UNSTRUCTURED_GRID
      parameter(VTK_DS_UNSTRUCTURED_GRID=3)
      integer VTK_DS_POLYDATA
      parameter(VTK_DS_POLYDATA=4)
      integer VTK_DS_RECTILINEAR_GRID
      parameter(VTK_DS_RECTILINEAR_GRID=5)
      integer VTKLIB_SHAPETRISTRIP
      parameter(VTKLIB_SHAPETRISTRIP=-1)
      integer VTK_EMPTY_CELL
      parameter(VTK_EMPTY_CELL=0)
      integer VTK_VERTEX
      parameter(VTK_VERTEX=1)
      integer VTK_POLY_VERTEX
      parameter(VTK_POLY_VERTEX=2)
      integer VTK_LINE
      parameter(VTK_LINE=3)
      integer VTK_POLY_LINE
      parameter(VTK_POLY_LINE=4)
      integer VTK_TRIANGLE
      parameter(VTK_TRIANGLE=5)
      integer VTK_TRIANGLE_STRIP
      parameter(VTK_TRIANGLE_STRIP=6)
      integer VTK_POLYGON
      parameter(VTK_POLYGON=7)
      integer VTK_PIXEL
      parameter(VTK_PIXEL=8)
      integer VTK_QUAD
      parameter(VTK_QUAD=9)
      integer VTK_TETRA
      parameter(VTK_TETRA=10)
      integer VTK_VOXEL
      parameter(VTK_VOXEL=11)
      integer VTK_HEXAHEDRON
      parameter(VTK_HEXAHEDRON=12)
      integer VTK_WEDGE
      parameter(VTK_WEDGE=13)
      integer VTK_PYRAMID
      parameter(VTK_PYRAMID=14)
      integer VTK_PENTAGONAL_PRISM
      parameter(VTK_PENTAGONAL_PRISM=15)
      integer VTK_HEXAGONAL_PRISM
      parameter(VTK_HEXAGONAL_PRISM=16)
      integer VTK_QUADRATIC_EDGE
      parameter(VTK_QUADRATIC_EDGE=21)
      integer VTK_QUADRATIC_TRIANGLE
      parameter(VTK_QUADRATIC_TRIANGLE=22)
      integer VTK_QUADRATIC_QUAD
      parameter(VTK_QUADRATIC_QUAD=23)
      integer VTK_QUADRATIC_TETRA
      parameter(VTK_QUADRATIC_TETRA=24)
      integer VTK_QUADRATIC_HEXAHEDRON
      parameter(VTK_QUADRATIC_HEXAHEDRON=25)
      integer VTK_QUADRATIC_WEDGE
      parameter(VTK_QUADRATIC_WEDGE=26)
      integer VTK_QUADRATIC_PYRAMID
      parameter(VTK_QUADRATIC_PYRAMID=27)
      integer VTK_BIQUADRATIC_QUAD
      parameter(VTK_BIQUADRATIC_QUAD=28)
      integer VTK_TRIQUADRATIC_HEXAHEDRON
      parameter(VTK_TRIQUADRATIC_HEXAHEDRON=29)
      integer VTK_QUADRATIC_LINEAR_QUAD
      parameter(VTK_QUADRATIC_LINEAR_QUAD=30)
      integer VTK_QUADRATIC_LINEAR_WEDGE
      parameter(VTK_QUADRATIC_LINEAR_WEDGE=31)
      integer VTK_BIQUADRATIC_QUADRATIC_WEDGE
      parameter(VTK_BIQUADRATIC_QUADRATIC_WEDGE=32)
      integer VTK_BIQUADRATIC_QUADRATIC_HEXAHEDRON
      parameter(VTK_BIQUADRATIC_QUADRATIC_HEXAHEDRON=33)
      integer VTK_BIQUADRATIC_TRIANGLE
      parameter(VTK_BIQUADRATIC_TRIANGLE=34)
      integer VTK_CUBIC_LINE
      parameter(VTK_CUBIC_LINE=35)
      integer VTK_CONVEX_POINT_SET
      parameter(VTK_CONVEX_POINT_SET=41)
      integer VTK_POLYHEDRON
      parameter(VTK_POLYHEDRON=42)
      integer VTK_PARAMETRIC_CURVE
      parameter(VTK_PARAMETRIC_CURVE=51)
      integer VTK_PARAMETRIC_SURFACE
      parameter(VTK_PARAMETRIC_SURFACE=52)
      integer VTK_PARAMETRIC_TRI_SURFACE
      parameter(VTK_PARAMETRIC_TRI_SURFACE=53)
      integer VTK_PARAMETRIC_QUAD_SURFACE
      parameter(VTK_PARAMETRIC_QUAD_SURFACE=54)
      integer VTK_PARAMETRIC_TETRA_REGION
      parameter(VTK_PARAMETRIC_TETRA_REGION=55)
      integer VTK_PARAMETRIC_HEX_REGION
      parameter(VTK_PARAMETRIC_HEX_REGION=56)
      integer VTK_HIGHER_ORDER_EDGE
      parameter(VTK_HIGHER_ORDER_EDGE=60)
      integer VTK_HIGHER_ORDER_TRIANGLE
      parameter(VTK_HIGHER_ORDER_TRIANGLE=61)
      integer VTK_HIGHER_ORDER_QUAD
      parameter(VTK_HIGHER_ORDER_QUAD=62)
      integer VTK_HIGHER_ORDER_POLYGON
      parameter(VTK_HIGHER_ORDER_POLYGON=63)
      integer VTK_HIGHER_ORDER_TETRAHEDRON
      parameter(VTK_HIGHER_ORDER_TETRAHEDRON=64)
      integer VTK_HIGHER_ORDER_WEDGE
      parameter(VTK_HIGHER_ORDER_WEDGE=65)
      integer VTK_HIGHER_ORDER_PYRAMID
      parameter(VTK_HIGHER_ORDER_PYRAMID=66)
      integer VTK_HIGHER_ORDER_HEXAHEDRON
      parameter(VTK_HIGHER_ORDER_HEXAHEDRON=67)
      integer VTKLIB_SEARCH_OFF
      parameter(VTKLIB_SEARCH_OFF=0)
      integer VTKLIB_SEARCH_OPENFOAM
      parameter(VTKLIB_SEARCH_OPENFOAM=1)
      integer VTKLIB_SEARCH_MULTIDIR
      parameter(VTKLIB_SEARCH_MULTIDIR=2)
      integer WRITER_RESTYPE
      parameter(WRITER_RESTYPE=1)
      integer WRITER_RESFILE
      parameter(WRITER_RESFILE=2)
      integer ZFILE_READ
      parameter(ZFILE_READ=1)
      integer ZFILE_WRITE
      parameter(ZFILE_WRITE=2)
