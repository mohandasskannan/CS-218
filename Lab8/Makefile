XX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = Lab8

OBJECTS = Lab8.o card.o deck.o rank.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

Lab8.o: Lab8.cpp deck.h card.h rank.h
	$(CXX) $(CXXFLAGS) -c Lab8.cpp -o Lab8.o

card.o: card.cpp card.h
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o

deck.o: deck.cpp deck.h card.h
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o

rank.o: rank.cpp rank.h card.h
	$(CXX) $(CXXFLAGS) -c rank.cpp -o rank.o

clean:
	rm -f $(TARGET) $(OBJECTS)
