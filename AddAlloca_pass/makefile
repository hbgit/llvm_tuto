CXX := clang++-8 `llvm-config-8 --cxxflags`
CC := clang-8

all:
	$(CXX) addAlloca.cpp -c -o addAlloca.cpp.o
	$(CXX) -shared -o LLVM_pass.so addAlloca.cpp.o
	$(CC) -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone example_code_test.c # compile code to test the LLVM pass
	rm addAlloca.cpp.o
	llvm-dis-8 example_code_test.bc
	opt-8 -load ./LLVM_pass.so -opAddAllocaPass example_code_test.bc > example_code_test_new.bc
	llvm-dis-8 example_code_test_new.bc
	

clean:
	rm LLVM_pass.so example_code_test.bc
