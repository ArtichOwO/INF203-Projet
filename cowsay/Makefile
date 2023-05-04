OUTPUT_DIR = dist
CC = gcc
LD = ld

CCFLAGS = -I include -I$(shell perl -MConfig -e 'print $$Config{archlib}')/CORE
LDFLAGS = -L$(shell perl -MConfig -e 'print $$Config{archlib}')/CORE -lperl

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LDFLAGS += -L$(shell xcode-select -p)/SDKs/MacOSX.sdk/usr/lib -lSystem
endif

objs = $(addprefix $(OUTPUT_DIR)/, \
	newcow.o \
)

newcow: $(objs)
	@echo LD $@
	@$(LD) $^ -o $(OUTPUT_DIR)/$@ $(LDFLAGS)

.PHONY: clean run

clean:
	@echo CLEAN
	@rm -Rf dist

run: newcow
	./$(OUTPUT_DIR)/newcow -d -e "**"

$(OUTPUT_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo CC $@
	@$(CC) -c $^ -o $@ $(CCFLAGS)
