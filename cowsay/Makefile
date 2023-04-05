OUTPUT_DIR = dist
CC = gcc
LD = ld

CFLAGS =
LDFLAGS = -L$(shell xcode-select -p)/SDKs/MacOSX.sdk/usr/lib -lSystem

objs = $(addprefix $(OUTPUT_DIR)/, \
	main.o \
)

cowsay: $(objs)
	@echo LD $@
	@$(LD) $^ -o $(OUTPUT_DIR)/$@ $(LDFLAGS)

.PHONY: clean

clean:
	@echo CLEAN
	@rm -Rf dist

$(OUTPUT_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo CC $@
	@$(CC) -c $^ -o $@ $(CFLAGS)
