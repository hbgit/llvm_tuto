CXX := clang++-6.0 `llvm-config-6.0 --cxxflags`
CC := clang-6.0

all:
	$(CXX) opCounter.cpp -c -o opCounter.cpp.o
	$(CXX) -shared -o LLVM_pass.so opCounter.cpp.o
	$(CC) -emit-llvm -c opcode.c # compile code to test the LLVM pass
	rm opCounter.cpp.o

clean:
	rm LLVM_pass.so klee_malloc.bc
