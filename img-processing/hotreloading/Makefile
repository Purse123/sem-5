CXX = clang++

CXXFLAGS = -Wall -Wextra ${shell pkg-config --cflags raylib}
CXXLIBS = -ldl -lm ${shell pkg-config --libs raylib}

libhello_1.so: hello.cpp
	${CXX} $^ -fPIC -shared -o $@ ${CXXFLAGS}

main: main.cpp plugin.cpp libhello_0.so
	${CXX} $^ -o $@ ${CXXFLAGS} ${CXXLIBS}

new: hello.cpp
	${CXX} hello.cpp -fPIC -shared -o libhello.so ${CXXFLAGS}

clean:
	rm -f main libhello_*.so *~
