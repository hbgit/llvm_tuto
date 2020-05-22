CXX := clang++-6.0 `llvm-config-6.0 --cxxflags`
CC := clang-6.0

all:
	$(CXX) listFunctPass.cpp -c -o listFunctPass.cpp.o
	$(CXX) -shared -o LLVM_pass.so listFunctPass.cpp.o
	$(CC) -emit-llvm -c example_code_test.c # compile code to test the LLVM pass
	rm listFunctPass.cpp.o

clean:
	rm LLVM_pass.so example_code_test.bc
