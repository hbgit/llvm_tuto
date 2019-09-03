# llvm_tuto
This repo has samples with LLVM/Clang.

# It was adopted LLVM 6.0 and the follow packages:
- git
- build-essential
- llvm-6.0-dev
- clang-6.0
- graphviz
- nano

# FirstExample
- ex1
    - Install LLVM/Clang
    - Building with Clang
    - Using **opt**

- ex2
    - Using Common Subexpression Elimination (CSE) from **opt**

- ex3
    - Using llvm tools: llvm-dis; lli; and llc

# FirstPass
- pass_ex
    - Building llvm pass as shared library
    - Running llvm pass with **opt**
    - Pass to count opcodes per functions using **runOnFunction(Function &F)**

# LoopPass
- pass_countblkloop
    - Building llvm pass as shared library
    - Running llvm pass with **opt**
    - Pass to count the number of Basic Blocks (BBs) inside each loop using **getAnalysis<LoopInfoWrapperPass>().getLoopInfo()**

# Parse
- bin_pass
    - Building llvm pass as a binary tool using function **main**
    - Parse the input LLVM IR file into a module
    - Create a pass manager and fill it with the passes we want to run

# utils
- Other llvm passes not classified


