###########################################################################
## Makefile generated for MATLAB file/project 'GetSignature'. 
## 
## Makefile     : GetSignature_rtw.mk
## Generated on : Tue Dec 01 17:42:26 2020
## MATLAB Coder version: 5.0 (R2020a)
## 
## Build Info:
## 
## Final product: .GetSignature.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = GetSignature
MAKEFILE                  = GetSignature_rtw.mk
MATLAB_ROOT               = C:\PROGRA~1\MATLAB\R2020a
MATLAB_BIN                = C:\PROGRA~1\MATLAB\R2020a\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)glnxa64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:\Users\AutoBike01\Documents\GitHub\AIGRIP2020HT\JetsonNano\MATLAB\A4.3_and_A8.3\codegen\lib\GetSignature
TGT_FCN_LIB               = ISO_C++
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = GetSignature.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Cadence Incisive (64-bit Linux)
# Supported Version(s):    1.0
# ToolchainInfo Version:   2020a
# Specification Revision:  1.0
# 
TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: C Compiler
CC = gcc

# Linker: Linker
LD = gcc

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE = echo "### Successfully generated all binary outputs."


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              =
C_OUTPUT_FLAG       =
LDDEBUG             =
OUTPUT_FLAG         =
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                =
MV                  =
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              =
CFLAGS               =
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           =  $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = .GetSignature.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -ccflags$(START_DIR) -ccflagsC:\Users\AUTOBI~1\DOCUME~1\GitHub\AIGRIP~1\JETSON~1\MATLAB\A43_AN~1.3 -ccflagsC:\ProgramData\MATLAB\SupportPackages\R2020a\toolbox\target\supportpackages\nvidia\include -ccflags$(MATLAB_ROOT)\extern\include

INCLUDES = 

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = __MW_TARGET_USE_HARDWARE_RESOURCES_H__ ARM_PROJECT _USE_TARGET_UDP_ _RUNONTARGETHARDWARE_BUILD_ STACK_SIZE=200000 MODEL=GetSignature
DEFINES_CUSTOM = 
DEFINES_SKIPFORSIL = ARM_PROJECT _USE_TARGET_UDP_ _RUNONTARGETHARDWARE_BUILD_ STACK_SIZE=200000
DEFINES_STANDARD = MODEL=GetSignature

DEFINES =    

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)rt_nonfinite.cpp $(START_DIR)rtGetNaN.cpp $(START_DIR)rtGetInf.cpp $(START_DIR)GetSignature_data.cpp $(START_DIR)GetSignature_initialize.cpp $(START_DIR)GetSignature_terminate.cpp $(START_DIR)GetSignature.cpp $(START_DIR)YXtoAngle.cpp $(START_DIR)GetARsing.cpp

ALL_SRCS = 

###########################################################################
## OBJECTS
###########################################################################

OBJS = rt_nonfinite.o rtGetNaN.o rtGetInf.o GetSignature_data.o GetSignature_initialize.o GetSignature_terminate.o GetSignature.o YXtoAngle.o GetARsing.o

ALL_OBJS = 

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

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += 

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += 

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	 "### Successfully generated all binary outputs."


build : prebuild 


prebuild : 


download : 


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

 :  
	 "### Creating static library "" ..."
	    $(subst ,/,$(subst ,/,))
	 "### Created: "


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	   "$@" $(subst ,/,"$<")


%.o : %.cpp
	  -o "$@" $(subst ,/,"$<")


%.o : $(START_DIR)%.c
	   "$@" $(subst ,/,"$<")


%.o : $(START_DIR)%.cpp
	  -o "$@" $(subst ,/,"$<")


%.o : C:UsersAutoBike01DocumentsGitHubAIGRIP2020HTJetsonNanoMATLABA4.3_and_A8.3%.c
	   "$@" $(subst ,/,"$<")


%.o : C:UsersAutoBike01DocumentsGitHubAIGRIP2020HTJetsonNanoMATLABA4.3_and_A8.3%.cpp
	  -o "$@" $(subst ,/,"$<")


rt_nonfinite.o : $(START_DIR)rt_nonfinite.cpp
	  -o "$@" $(subst ,/,"$<")


rtGetNaN.o : $(START_DIR)rtGetNaN.cpp
	  -o "$@" $(subst ,/,"$<")


rtGetInf.o : $(START_DIR)rtGetInf.cpp
	  -o "$@" $(subst ,/,"$<")


GetSignature_data.o : $(START_DIR)GetSignature_data.cpp
	  -o "$@" $(subst ,/,"$<")


GetSignature_initialize.o : $(START_DIR)GetSignature_initialize.cpp
	  -o "$@" $(subst ,/,"$<")


GetSignature_terminate.o : $(START_DIR)GetSignature_terminate.cpp
	  -o "$@" $(subst ,/,"$<")


GetSignature.o : $(START_DIR)GetSignature.cpp
	  -o "$@" $(subst ,/,"$<")


YXtoAngle.o : $(START_DIR)YXtoAngle.cpp
	  -o "$@" $(subst ,/,"$<")


GetARsing.o : $(START_DIR)GetARsing.cpp
	  -o "$@" $(subst ,/,"$<")


###########################################################################
## DEPENDENCIES
###########################################################################

 : rtw_proj.tmw 


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	 "### PRODUCT = "
	 "### PRODUCT_TYPE = "
	 "### BUILD_TYPE = "
	 "### INCLUDES = "
	 "### DEFINES = "
	 "### ALL_SRCS = "
	 "### ALL_OBJS = "
	 "### LIBS = "
	 "### MODELREF_LIBS = "
	 "### SYSTEM_LIBS = "
	 "### TOOLCHAIN_LIBS = "
	 "### CFLAGS = "
	 "### LDFLAGS = "
	 "### SHAREDLIB_LDFLAGS = "
	 "### CPPFLAGS = "
	 "### CPP_LDFLAGS = "
	 "### CPP_SHAREDLIB_LDFLAGS = "
	 "### ARFLAGS = "
	 "### MEX_CFLAGS = "
	 "### MEX_CPPFLAGS = "
	 "### MEX_LDFLAGS = "
	 "### MEX_CPPLDFLAGS = "
	 "### DOWNLOAD_FLAGS = "
	 "### EXECUTE_FLAGS = "
	 "### MAKE_FLAGS = "


clean : 
	 "### Deleting all derived files..."
	 $(subst /,\,)
	 $(subst /,\,)
	 "### Deleted all derived files."


