CXX := clang++ `llvm-config --cxxflags`
CC := clang

all:
	$(CXX) BlkLoopPass.cpp -c -o BlkLoopPass.cpp.o
	$(CXX) -shared -o LLVM_bkl_pass.so BlkLoopPass.cpp.o
	$(CC) -emit-llvm -c loop.c # compile code to test the LLVM pass
	rm BlkLoopPass.cpp.o

clean:
	rm LLVM_bkl_pass.so loop.bc
