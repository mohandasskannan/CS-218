# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Object files for the classes
OBJS = card.o deck.o rank.o pokerhand.o

# Default target: build the main game "Project2"
all: Project2

Project2: $(OBJS) PA2.o
	$(CXX) $(CXXFLAGS) -o Project2 $(OBJS) PA2.o

PA2.o: PA2.cpp card.h deck.h rank.h pokerhand.h
	$(CXX) $(CXXFLAGS) -c PA2.cpp

# Target to build "testPA2" as required by the PDF
testPA2: $(OBJS) testPA2.o
	$(CXX) $(CXXFLAGS) -o testPA2 $(OBJS) testPA2.o

testPA2.o: testPA2.cpp card.h deck.h rank.h pokerhand.h
	$(CXX) $(CXXFLAGS) -c testPA2.cpp

# Rules for compiling class implementation files
pokerhand.o: pokerhand.cpp pokerhand.h card.h rank.h
	$(CXX) $(CXXFLAGS) -c pokerhand.cpp

deck.o: deck.cpp deck.h card.h
	$(CXX) $(CXXFLAGS) -c deck.cpp

rank.o: rank.cpp rank.h
	$(CXX) $(CXXFLAGS) -c rank.cpp

card.o: card.cpp card.h
	$(CXX) $(CXXFLAGS) -c card.cpp

# Clean target
clean:
	rm -f *.o Project2 testPA2
