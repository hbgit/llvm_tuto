# Update Variable PASS

This LLVM pass example aims to set a call function for not initialized variables
in the main function.


make

opt-8 -load ./LLVM_pass.so -opInitVarPass -disable-output example_code_test.bc
