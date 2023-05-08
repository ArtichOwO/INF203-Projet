OUTPUT_DIR = dist
CC = gcc
LD = ld

DEBUG ?= 0
USE_PERL ?= 0

CCFLAGS = -I include 
LDFLAGS = 

ifeq ($(shell uname -s),Darwin)
	LDFLAGS += -L$(shell xcode-select -p)/SDKs/MacOSX.sdk/usr/lib -lSystem
else
	LD = gcc
endif

ifeq ($(DEBUG), 1)
	CCFLAGS += -DDEBUG
endif

ifeq ($(USE_PERL), 1)
	CCFLAGS += -DUSE_PERL -I$(shell perl -MConfig -e 'print $$Config{archlib}')/CORE
	LDFLAGS += -L$(shell perl -MConfig -e 'print $$Config{archlib}')/CORE -lperl
endif

objs = $(addprefix $(OUTPUT_DIR)/, \
	print_msg.o \
	show_cow.o \
	usage.o \
)

.PHONY: all clean

all: newcow.exe wildcow.exe reading_cow.exe tamagotchi_cow.exe

clean:
	@rm -rf cowsay/dist
	@echo CLEAN

$(OUTPUT_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo CC $@
	@$(CC) -c $^ -o $@ $(CCFLAGS)

%.exe: $(OUTPUT_DIR)/%.o $(objs)
	@echo LD $@
	@$(LD) $^ -o $(OUTPUT_DIR)/$@ $(LDFLAGS)
