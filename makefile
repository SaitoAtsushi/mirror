
test.exe : test.cpp mirror.h predicate.h descending.h
	$(CXX) test.cpp -o test.exe -std=c++17
	./test.exe
