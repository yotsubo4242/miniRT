CC := gcc
OBJS := main.o fizzbuzz.o
CFLAGS := -W -Wall

main: $(OBJS)

$(OBJS): fizzbuzz.h 

.PHONY: clean
clean:
	-rm *.o 
	-rm main

.DEFAULT_GOAL=main

