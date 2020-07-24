CC = g++
CFLAGS = -O2 -Wall -std=gnu++17 -DONLINE_JUDGE -DBOJ
LDFLAGS = -lm -static 
SRC := $(shell ls -t *.cpp | awk 'NR == 1 { print $1}')
NOW := $(shell date)
NAME = new_
.PHONY: all new print

all: $(SRC)
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

new:
	if [ ! -e $(NAME).cpp ]; then sed "s/* Start Time:/* Start Time:$(NOW)/" tmpl.cpp > $(NAME).cpp; else echo "already exist $(NAME).cpp"; fi

print:
	echo "$(NOW)"
