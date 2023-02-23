CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

hw3/llrec-test: hw3/llrec-test.cpp hw3/llrec.cpp
	$(CXX) $(CXXFLAGS) $(VALGRIND) llrec-test.cpp -o llrec-test

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 