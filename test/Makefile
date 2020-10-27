CPP=g++SYSROOT		:="/opt/crosstools/arm-cortex_a9-eabi-4.7-eglibc-2.18/arm-cortex_a9-linux-gnueabi/sysroot
CROSSNAME       := arm-cortex_a9-linux-gnueabi-


CC      =   $(CROSSNAME)gcc
CPP     =   $(CROSSNAME)g++
CXX             =       $(CROSSNAME)g++
AR      =   $(CROSSNAME)ar cqs
AS              =       $(CROSSNAME)as
LD      =   $(CROSSNAME)ld
NM              =       $(CROSSNAME)nm
RANLIB  =       $(CROSSNAME)ranlib
OBJCOPY =       $(CROSSNAME)objcopy
STRIP   =   $(CROSSNAME)strip

CPPFLAGS=-I. -std=c++11 -ldl -pthread
DEPS = Test.h MediaService.h
OBJ = Test.o

#%.o: %.cpp $(DEPS)
#	$(CPP) -c -o $@ $< $(CPPFLAGS)

TARGET = encodertest

all: $(TARGET)

clean: 
	rm -f $(OBJ) $(TARGET)


$(TARGET): $(OBJ)
	$(CPP) -o $@ $^ $(CPPFLAGS)

###############################################################################
ifdef V
        ifeq ("$(origin V)", "command line")
                BUILD_VERBOSE = $(V)
                Q =
        endif
endif

ifndef BUILD_VERBOSE
        BUILD_VERBOSE = 0
        Q = @
endif

export BUILD_VERBOSE Q
#########################################################################
#       Generic Rules
#########################################################################
%.o: %.c
	@echo "root Compiling.....      [$<]"
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<

%.o: %.cpp
	@echo "root cpp Compiling.....  [$<]" 
	$(Q)$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

%.o: %.s
	@echo "root Compiling.....      [$<]"
	@$(AS) $(CPPFLAGS) $(AFLAGS) $(INCLUDE) -c -o $@ $<
