# Update Variable PASS

- RUN: $ make

This LLVM pass example aims to add an AllocaInst in the code. 

- OUTPUT: $ sdiff example_code_test.ll example_code_test_new.ll 


; Function Attrs: noinline nounwind uwtable			; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !7 {			define dso_local i32 @main() #0 !dbg !7 {
                                             ...
  %4 = load i32, i32* %3, align 4, !dbg !15			  %4 = load i32, i32* %3, align 4, !dbg !15
  %5 = load i32, i32* %2, align 4, !dbg !16			  %5 = load i32, i32* %2, align 4, !dbg !16
							                        >	  %tmp_1 = alloca i32, align 4
  %6 = add nsw i32 %4, %5, !dbg !17				      %6 = add nsw i32 %4, %5, !dbg !17
  store i32 %6, i32* %3, align 4, !dbg !18			  store i32 %6, i32* %3, align 4, !dbg !18
  ret i32 0, !dbg !19						          ret i32 0, !dbg !19
}								}


