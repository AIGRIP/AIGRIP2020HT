###########################################################################
## Makefile generated for component 'MorphologicalFilters'. 
## 
## Makefile     : MorphologicalFilters_rtw.mk
## Generated on : Wed Dec 02 13:31:53 2020
## Final product: ./MorphologicalFilters.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = MorphologicalFilters
MAKEFILE                  = MorphologicalFilters_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2020b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1
TGT_FCN_LIB               = ISO_C++
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
COMPILER_COMMAND_FILE     = MorphologicalFilters_rtw_comp.rsp
CMD_FILE                  = MorphologicalFilters_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = MorphologicalFilters.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 -std=c++11 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./MorphologicalFilters.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -D__USE_MINGW_ANSI_STDIO=1
DEFINES_CUSTOM = 
DEFINES_SKIPFORSIL = -D__linux__ -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=200000
DEFINES_STANDARD = -DMODEL=MorphologicalFilters

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MORPHO~1.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/RT_NON~1.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/rtGetNaN.cpp C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/rtGetInf.cpp C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MORPHO~2.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MORPHO~3.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MORPHO~4.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/imfill.cpp C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/minOrMax.cpp C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/REGION~1.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/BWCONN~1.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/bsxfun.cpp C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MO45FA~1.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/imerode.cpp C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/IMRECO~1.CPP C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/NEIGHB~1.CPP

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MorphologicalFilters_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj MorphologicalFilters_initialize.obj MorphologicalFilters_terminate.obj MorphologicalFilters.obj imfill.obj minOrMax.obj regionprops.obj bwconncomp.obj bsxfun.obj morphopAlgo.obj imerode.obj imreconstruct.obj NeighborhoodProcessor.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -fopenmp

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -fopenmp

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -fopenmp

LDFLAGS += $(LDFLAGS_)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -fopenmp

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MorphologicalFilters_data.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MorphologicalFilters_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MorphologicalFilters_initialize.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MorphologicalFilters_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MorphologicalFilters_terminate.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MorphologicalFilters_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MorphologicalFilters.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/MorphologicalFilters.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imfill.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/imfill.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


regionprops.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/regionprops.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bwconncomp.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/bwconncomp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bsxfun.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/bsxfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


morphopAlgo.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/morphopAlgo.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imerode.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/imerode.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imreconstruct.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/imreconstruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


NeighborhoodProcessor.obj : C:/Users/SWTEAM~1/DOCUME~1/GitHub/AIGRIP~1/JETSON~1/MATLAB/A43_AN~1.3/codegen/lib/MORPHO~1/NeighborhoodProcessor.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


