CC = g++
CFLAGS = -Wall

CPPFILES = main.cpp
CPPFILES += BaseStack.cpp
CPPFILES += ../linkedlist/BaseLinkedList.cpp


TARGET = stack

$(TARGET): $(CPPFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(CPPFILES)

clean:
	rm -f $(TARGET)

run:
	./$(TARGET)
	