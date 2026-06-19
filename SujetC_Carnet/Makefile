CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = carnet

all: $(TARGET)

$(TARGET): carnet.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) carnet.cpp

clean:
	rm -f $(TARGET) contacts.csv
