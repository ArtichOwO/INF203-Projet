OUTPUT_DIR = dist
CC = gcc
LD = ld

# Modifiable via la ligne de commande (USE_PERL=...)
USE_PERL ?= 1

CCFLAGS = -I include
LDFLAGS = 

# Si compilation sous MacOS
ifeq ($(shell uname -s),Darwin)
	LDFLAGS += -L$(shell xcode-select -p)/SDKs/MacOSX.sdk/usr/lib -lSystem
else
	LD = gcc
endif

# Si compilation avec Perl
ifeq ($(USE_PERL), 1)
	LIBPERL_PATH = $(shell perl -MConfig -e 'print $$Config{archlib}')
	CCFLAGS += -D_GNU_SOURCE -DUSE_PERL -I$(LIBPERL_PATH)/CORE
	LDFLAGS += -L$(LIBPERL_PATH)/CORE -lperl
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
