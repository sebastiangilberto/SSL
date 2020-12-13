TARGET = Calc.out
CC = gcc
CFLAGS = -std=c18 -g
FLEXL = Scanner.l
FLEXC = Scanner.c
BISONY = Parser.y
BISONC = Parser.c
BISONH = Token.h
BISON = Parser
TEST_INPUT = input.txt
TEST_OUTPUT = output.txt

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(BISONC) $(FLEXC) $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) -o $@

$(FLEXC): $(FLEXL)
	flex -o$(FLEXC) $(FLEXL)

$(BISONC): $(BISONY)
	bison -o$(BISONC) $(BISONY) --defines=$(BISONH)

test: $(TARGET)
	./$(TARGET) < $(TEST_INPUT) > $(TEST_OUTPUT)

clean:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f $(TEST_OUTPUT)