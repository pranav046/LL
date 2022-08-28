#
# Description:
#
# This makefile usecase is to automate the build of PROJECT examples
#
# Auther: Harshil Jain
# Email:  harshil.jain@securemeters.com  
# 
# Manage the abstraction layer compilation
# 
# @todo Harshil Jain
# Please explain targets once makefile requirements freezed
#
############################################################################################

include paths.mk

CC=gcc
CFLAGS= -Wall -ggdb
OBJECTS := $(filter-out $(EXCLUDE_FILES), $(OBJECTS))

# Targets
$(BUILD)/$(FILE).out: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) $(PDEF) $^ -o $@

start:
	./build/output/$(FILE).out

clean:
	-rm -r build/output/$(FILE).out

create_build_folder:
	-mkdir build
	-mkdir build/output