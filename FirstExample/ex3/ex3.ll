; ModuleID = 'ex3.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-redhat-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @callee(i32* %X) #0 {
  %1 = load i32* %X, align 4
  %2 = add nsw i32 %1, 1
  ret i32 %2
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %T = alloca i32, align 4
  store i32 4, i32* %T, align 4
  %1 = call i32 @callee(i32* %T)
  ret i32 %1
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.5.0 (tags/RELEASE_350/final)"}
