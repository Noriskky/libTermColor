#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#

# define the Cpp compiler to use
CXX = g++

# define any compile-time flags
CXXFLAGS := -std=c++17 -Wall -Wextra -g

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS =

# define output directory
OUTPUT := output

# define source directory
SRC := example

# define include directory
INCLUDE := include

# define lib directory
LIB := lib

ifeq ($(OS),Windows_NT)
	MAIN := main.exe
	SOURCEDIRS := $(SRC)
	INCLUDEDIRS := $(INCLUDE)
	LIBDIRS := $(LIB)
	FIXPATH = $(subst /,\,$1)
	RM := del /q /f
	MD := mkdir
else
	MAIN := main
	SOURCEDIRS := $(shell find $(SRC) -type d)
	INCLUDEDIRS := $(shell find $(INCLUDE) -type d)
	LIBDIRS := $(shell find $(LIB) -type d)
	FIXPATH = $1
	RM = rm -f
	MD := mkdir -p
endif

# define any directories containing header files other than /usr/include
INCLUDEDIRS := $(shell find $(INCLUDE) -type d)
INCLUDES := $(patsubst %,-I%, $(INCLUDEDIRS:%/=%)) -I$(LIB)

# define the C libs
LIBS := $(patsubst %,-L%, $(LIBDIRS:%/=%))

# define the C source files
SOURCES := $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))

# define the C object files
OBJECTS := $(SOURCES:.cpp=.o)

# define the dependency output files
DEPS := $(OBJECTS:.o=.d)

# define the output main file
OUTPUTMAIN := $(call FIXPATH,$(OUTPUT)/$(MAIN))

# build all rule
all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

# create output directory
$(OUTPUT):
	$(MD) $(OUTPUT)

# build main executable
$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

# include all .d files
-include $(DEPS)

# build rule for .cpp to .o
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -MMD $<  -o $@
	
# clean rule
.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))
	@echo Cleanup complete!

# run rule
run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!

rust_build:
	# Rust
	cargo build
