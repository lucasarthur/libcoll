rwildcard = $(foreach d, $(wildcard $(1:=/*)), $(call rwildcard, $d, $2) $(filter $(subst *, %, $2), $d))
RM = rm -rf
MKDIR = mkdir -p

SRC_DIR := src
INC_DIR := include
BIN_DIR := bin
OBJ_DIR := $(BIN_DIR)/obj
FINAL_NAME := main

CC := gcc
CPPFLAGS := $(patsubst %, -I%, $(shell find $(INC_DIR) -type d))
CFLAGS := -g -std=c11 -Wall -Wextra
LD := gcc
LFLAGS :=

SRCS := $(call rwildcard, $(SRC_DIR), *.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET := $(BIN_DIR)/$(FINAL_NAME)

.PHONY: all clean distclean run

all: dirs $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^ -o $@

dirs:
	@$(MKDIR) $(BIN_DIR)
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(SRC_DIR)
	@$(MKDIR) $(INC_DIR)

clean:
	$(RM) $(BIN_DIR)

distclean:
	$(RM) $(TARGET)

run: $(TARGET)
	@./$(TARGET)
