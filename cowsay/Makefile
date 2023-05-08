OUTPUT_DIR = dist
CC = gcc
LD = ld

USE_PERL ?= 0

CCFLAGS = -I include 
LDFLAGS = 

ifeq ($(shell uname -s),Darwin)
	LDFLAGS += -L$(shell xcode-select -p)/SDKs/MacOSX.sdk/usr/lib -lSystem
else
	LD = gcc
endif

ifeq ($(USE_PERL), 1)
	CCFLAGS += -DUSE_PERL -I$(shell perl -MConfig -e 'print $$Config{archlib}')/CORE
	LDFLAGS += -L$(shell perl -MConfig -e 'print $$Config{archlib}')/CORE -lperl
endif

newcow_objs = $(addprefix $(OUTPUT_DIR)/, \
	newcow.o \
	print_msg.o \
	show_cow.o \
)

wildcow_objs = $(addprefix $(OUTPUT_DIR)/, \
	wildcow.o \
	print_msg.o \
	show_cow.o \
)

reading_cow_objs = $(addprefix $(OUTPUT_DIR)/, \
	reading_cow.o \
	print_msg.o \
	show_cow.o \
)

all: newcow wildcow reading_cow

newcow: $(newcow_objs)
	@echo LD $@
	@$(LD) $^ -o $(OUTPUT_DIR)/$@ $(LDFLAGS)

wildcow: $(wildcow_objs)
	@echo LD $@
	@$(LD) $^ -o $(OUTPUT_DIR)/$@ $(LDFLAGS)

reading_cow: $(reading_cow_objs)
	@echo LD $@
	@$(LD) $^ -o $(OUTPUT_DIR)/$@ $(LDFLAGS)

.PHONY: clean run

clean:
	@echo CLEAN
	@rm -Rf dist

$(OUTPUT_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo CC $@
	@$(CC) -c $^ -o $@ $(CCFLAGS)
