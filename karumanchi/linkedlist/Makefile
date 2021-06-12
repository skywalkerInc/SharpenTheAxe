CC = g++
CFLAGS = -Wall

CPPFILES = main.cpp
CPPFILES += BaseLinkedList.cpp
CPPFILES += TestNodes.cpp


TARGET = linkedlist

$(TARGET): $(CPPFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(CPPFILES)

clean:
	rm -f $(TARGET)

run:
	./$(TARGET)
	