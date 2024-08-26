CC = gcc

CFLAGS = -Wall -Iinclude

TARGET = main

SRC_DIR = commands
INC_DIR = include

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/utility.c $(SRC_DIR)/log.c $(SRC_DIR)/shutdown.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

clean_objs:
	rm -f $(OBJS)

clean_exe:
	rm -f $(TARGET)

.PHONY: all clean clean_objs clean_exe