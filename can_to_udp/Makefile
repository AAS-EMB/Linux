CC=gcc
CFLAGS=-pthread
TARGET=can_to_udp
SOURCES_PATH=$(shell pwd)
SOURCES_EXTENSION=c
SOURCES=$(shell find $(PWD) -name '*.$(SOURCES_EXTENSION)')

.PHONY: all clean

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -rf $(TARGET)

