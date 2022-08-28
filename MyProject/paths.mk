# Constants
# Abstraction layer header paths
PRJ_COMMON=MyProject\Common
PRJ_INC=MyProject\include
PRJ_STUB=MyProject\Stubs
APPLICATION=Applications
#CJSON=3pp\cJson\lib

BUILD	:= build/output
FILE=PK

TARGET=D:\vs_code_projects\MyProject

# Header includes
INCLUDE := -I$(PRJ_COMMON)
INCLUDE += -I$(PRJ_INC)
INCLUDE += -I$(PRJ_STUB)
INCLUDE += -I$(TARGET)

# Lib includes
OBJECTS := $(wildcard $(TARGET)/*.c)
OBJECTS += $(wildcard $(PRJ_COMMON)/*.c)
OBJECTS += $(wildcard $(PRJ_STUB)/*.c)
OBJECTS += $(wildcard $(CJSON)/*.c)
OBJECTS += $(wildcard $(APPLICATION)/*.c)

# Exclude files from build
#EXCLUDE_FILES := $(APPLICATION)/Server_blocking.c
#EXCLUDE_FILES += $(APPLICATION)/Client_blocking.c
#EXCLUDE_FILES += $(ABS_WIN)/TWindowsUartByteStream_Asynch1.c

# Private defines to enable lib settings
# -DSWITCH_CONSTANT_NAME
PDEF:=