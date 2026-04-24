CXX = g++
CXXLIBS = $(shell pkg-config --cflags --libs opencv4)

q1: 1-clr2grayScale.cpp
	$(CXX) $^ -o $@ $(CXXLIBS) -g -O0
q9: 9-fft.cpp
	$(CXX) $^ -o $@ $(CXXLIBS) -g -O0
clean:
	rm *~ q1 q2 q3 q4 q5 q6 q7 q8 q9
