CXX := clang++ `llvm-config --cxxflags`
CC := clang

all:
	$(CXX) FPredLoopPass.cpp -c -o FPredLoopPass.cpp.o
	$(CXX) -shared -o LLVM_pass.so FPredLoopPass.cpp.o
#	$(CXX) BreakInfiniteLoops.cpp -c -o BreakInfiniteLoops.cpp.o
#	$(CXX) -shared -o LLVM_SYM_pass.so BreakInfiniteLoops.cpp.o
	$(CC) -emit-llvm -c loop.c # compile code to test the LLVM pass
	rm FPredLoopPass.cpp.o

clean:
	rm LLVM_pass.so loop.bc
