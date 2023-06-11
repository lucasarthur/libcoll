rwildcard = $(foreach d, $(wildcard $(1:=/*)), $(call rwildcard, $d, $2) $(filter $(subst *, %, $2), $d))
RM = rm -rf
MKDIR = mkdir -p
CP = cp

SRC_DIR := src
INC_DIR := include
BIN_DIR := bin
OBJ_DIR := $(BIN_DIR)/obj
INSTALL_LIB_DIR := /usr/local/lib
INSTALL_INCLUDE_DIR := /usr/local/include
FINAL_NAME := libcoll

CC := gcc
CPPFLAGS := $(patsubst %, -I%, $(shell find $(INC_DIR) -type d))
CFLAGS := -Wall -Wextra -Werror -std=c11 -pedantic -fPIC

SRCS := $(call rwildcard, $(SRC_DIR), *.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET := $(BIN_DIR)/$(FINAL_NAME).so

.PHONY: all clean distclean

all: prepare $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -shared -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^ -o $@

prepare:
	@$(MKDIR) $(OBJ_DIR)

clean:
	$(RM) $(BIN_DIR)

distclean:
	$(RM) $(TARGET)

install:
	@if [ $(shell id -u) -ne 0 ]; then echo "Please run as root using sudo make install"; exit 1; fi
	$(CP) $(TARGET) $(INSTALL_LIB_DIR)
	$(CP) -r $(INC_DIR)/* $(INSTALL_INCLUDE_DIR)
	ldconfig
