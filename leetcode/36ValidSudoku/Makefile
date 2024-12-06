CXXFLAGS = -Wall -pedantic -O2 -std=c++17

target = sudoku

objects = $(target).o

all: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $(target)

$(target).o: $(target).cpp
	$(CXX) $(CXXFLAGS) -c $(target).cpp -o $(target).o

clean:
	rm -f *.o $(target)

