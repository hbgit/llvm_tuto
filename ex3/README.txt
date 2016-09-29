$ clang -c -emit-llvm ex3.c -o ex3.bc 
$ opt -mem2reg ex3.bc -o ex3.bc
$ llvm-dis ex3.bc
$ cat ex3.ll
$ lli ex3.bc # run llvm code
$ llc -march=x86 ex3.bc -o ex3.x86
