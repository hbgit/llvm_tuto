$ clang -c -emit-llvm cse.c -o cse.bc
$ opt -mem2reg cse.bc -o cse.reg.bc 
$ opt -view-cfg cse.reg.bc
$ opt -early-cse cse.reg.bc > cse.o.bc
$ opt -view-cfg cse.o.bc
$ 
