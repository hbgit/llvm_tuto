# Update Variable PASS

- RUN: $ make

This LLVM pass example aims to add an StoreInst in the code. In C code:

// From
int main(){
  
  int b;
  int a;

  a = a + b;

  return 0;
}

// Result
int main(){
  
  int b;
  int a;

  a = a + b;
  int tmp_1;
  tmp_1 = a;

  return 0;
}


- OUTPUT: $ sdiff example_code_test.ll example_code_test_new.ll 

...
%4 = load i32, i32* %3, align 4, !dbg !15			  %4 = load i32, i32* %3, align 4, !dbg !15
%5 = load i32, i32* %2, align 4, !dbg !16			  %5 = load i32, i32* %2, align 4, !dbg !16
%6 = add nsw i32 %4, %5, !dbg !17				      %6 = add nsw i32 %4, %5, !dbg !17
                                                      >	  %tmp_1 = alloca i32, align 4
store i32 %6, i32* %3, align 4, !dbg !18			  store i32 %6, i32* %3, align 4, !dbg !18
                                                      >	  store i32 %6, i32* %tmp_1
ret i32 0, !dbg !19						              ret i32 0, !dbg !19




