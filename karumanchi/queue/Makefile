CC = g++
CFLAGS = -Wall

CPPFILES = main.cpp
CPPFILES += BaseQueue.cpp
CPPFILES += ../linkedlist/BaseLinkedList.cpp


TARGET = queue

$(TARGET): $(CPPFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(CPPFILES)

clean:
	rm -f $(TARGET)

run:
	./$(TARGET)
	