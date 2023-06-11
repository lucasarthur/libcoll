rwildcard = $(foreach d, $(wildcard $(1:=/*)), $(call rwildcard, $d, $2) $(filter $(subst *, %, $2), $d))
RM = rm -rf
MKDIR = mkdir -p

SRC_DIR := src
INC_DIR := include
BIN_DIR := bin
OBJ_DIR := $(BIN_DIR)/obj
FINAL_NAME := libcoll

CC := gcc
AR := ar
CPPFLAGS := $(patsubst %, -I%, $(shell find $(INC_DIR) -type d))
CFLAGS := -Wall -Wextra -Werror -std=c11 -pedantic

SRCS := $(call rwildcard, $(SRC_DIR), *.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET := $(BIN_DIR)/$(FINAL_NAME).a

.PHONY: all clean distclean

all: dirs $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^ -o $@

dirs:
	@$(MKDIR) $(OBJ_DIR)

clean:
	$(RM) $(BIN_DIR)

distclean:
	$(RM) $(TARGET)
