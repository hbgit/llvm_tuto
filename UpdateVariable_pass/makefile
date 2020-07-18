CXX := clang++-8 `llvm-config-8 --cxxflags`
CC := clang-8

all:
	$(CXX) initVarPass.cpp -c -o initVarPass.cpp.o
	$(CXX) -shared -o LLVM_pass.so initVarPass.cpp.o
	$(CC) -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone example_code_test.c # compile code to test the LLVM pass
	rm initVarPass.cpp.o
	llvm-dis-8 example_code_test.bc

clean:
	rm LLVM_pass.so example_code_test.bc
