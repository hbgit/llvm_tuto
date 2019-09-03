Install:

$ sudo dnf install llvm-devel llvm-static llvm-libs

Run:

$ clang -emit-llvm -c -o ex1.bc ex1.c
$ opt --view-cfg ex1.bc
$ opt -mem2reg ex1.bc > ex1.reg.bc
$ opt -constprop ex1.reg.bc > ex1.cp.bc

