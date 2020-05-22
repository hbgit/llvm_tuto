make

opt-6.0 -load ./LLVM_pass.so -oplistFunctPass -disable-output -time-passes example_code_test.bc
