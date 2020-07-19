; ModuleID = 'example_code_test.bc'
source_filename = "example_code_test.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @foo() #0 !dbg !7 {
  ret i32 0, !dbg !11
}

; Function Attrs: noinline nounwind uwtable
define dso_local void @bar() #0 !dbg !12 {
  ret void, !dbg !15
}

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !16 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  call void @llvm.dbg.declare(metadata i32* %2, metadata !17, metadata !DIExpression()), !dbg !18
  %4 = call i32 @foo(), !dbg !19
  store i32 %4, i32* %2, align 4, !dbg !18
  call void @bar(), !dbg !20
  call void @llvm.dbg.declare(metadata i32* %3, metadata !21, metadata !DIExpression()), !dbg !22
  %5 = load i32, i32* %3, align 4, !dbg !23
  %6 = load i32, i32* %2, align 4, !dbg !24
  %7 = add nsw i32 %5, %6, !dbg !25
  store i32 %7, i32* %3, align 4, !dbg !26
  ret i32 0, !dbg !27
}

; Function Attrs: nounwind readnone speculatable
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

attributes #0 = { noinline nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5}
!llvm.ident = !{!6}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 8.0.1-9 (tags/RELEASE_801/final)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, nameTableKind: None)
!1 = !DIFile(filename: "example_code_test.c", directory: "/home/hrocha/Documents/Projects/llvm_tuto/AddFunction_pass")
!2 = !{}
!3 = !{i32 2, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{!"clang version 8.0.1-9 (tags/RELEASE_801/final)"}
!7 = distinct !DISubprogram(name: "foo", scope: !1, file: !1, line: 1, type: !8, scopeLine: 1, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!8 = !DISubroutineType(types: !9)
!9 = !{!10}
!10 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!11 = !DILocation(line: 2, column: 3, scope: !7)
!12 = distinct !DISubprogram(name: "bar", scope: !1, file: !1, line: 5, type: !13, scopeLine: 5, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!13 = !DISubroutineType(types: !14)
!14 = !{null}
!15 = !DILocation(line: 7, column: 1, scope: !12)
!16 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 9, type: !8, scopeLine: 9, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!17 = !DILocalVariable(name: "b", scope: !16, file: !1, line: 11, type: !10)
!18 = !DILocation(line: 11, column: 7, scope: !16)
!19 = !DILocation(line: 11, column: 11, scope: !16)
!20 = !DILocation(line: 13, column: 3, scope: !16)
!21 = !DILocalVariable(name: "a", scope: !16, file: !1, line: 15, type: !10)
!22 = !DILocation(line: 15, column: 7, scope: !16)
!23 = !DILocation(line: 17, column: 7, scope: !16)
!24 = !DILocation(line: 17, column: 11, scope: !16)
!25 = !DILocation(line: 17, column: 9, scope: !16)
!26 = !DILocation(line: 17, column: 5, scope: !16)
!27 = !DILocation(line: 19, column: 3, scope: !16)
