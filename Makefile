DEBUG		?= 0


ELF			:= jpeg_test.elf

CC 			:= clang
IINC		:= -I src
WARNINGS	:= -Wall -Wextra -Wshadow -Wno-unused-variable -Werror=implicit-function-declaration
CFLAGS		:= -funsigned-char
ifeq ($(DEBUG),0)
  OPTFLAGS	:= -O2
else
  OPTFLAGS	:= -O0 -g3
endif

SRC_DIRS 	:= $(shell find src -type d)
C_FILES		:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
O_FILES		:= $(foreach f,$(C_FILES:.c=.o),build/$f)

all: $(ELF)

clean:
	$(RM) -r $(O_FILES)

.PHONY: all clean

# create build directories
$(shell mkdir -p $(foreach dir,$(SRC_DIRS),build/$(dir)))

$(ELF): $(O_FILES)
	$(CC) $(IINC) $(WARNINGS) $(CFLAGS) $(OPTFLAGS) -o $@ $^

build/src/%.o: src/%.c
	$(CC) -c $(IINC) $(WARNINGS) $(CFLAGS) $(OPTFLAGS) -o $@ $<