; ModuleID = 'example_code_test.bc'
source_filename = "example_code_test.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @bar() #0 !dbg !7 {
  %1 = alloca i32, align 4
  call void @llvm.dbg.declare(metadata i32* %1, metadata !11, metadata !DIExpression()), !dbg !12
  %2 = call i32 @__VERIFIER_nondet_int(), !dbg !13
  store i32 %2, i32* %1, align 4, !dbg !12
  %3 = load i32, i32* %1, align 4, !dbg !14
  ret i32 %3, !dbg !15
}

; Function Attrs: nounwind readnone speculatable
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare dso_local i32 @__VERIFIER_nondet_int() #2

; Function Attrs: noinline nounwind uwtable
define dso_local void @foo() #0 !dbg !16 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca double, align 8
  call void @llvm.dbg.declare(metadata i32* %1, metadata !19, metadata !DIExpression()), !dbg !20
  %4 = call i32 @bar(), !dbg !21
  store i32 %4, i32* %1, align 4, !dbg !20
  call void @llvm.dbg.declare(metadata i32* %2, metadata !22, metadata !DIExpression()), !dbg !23
  store i32 0, i32* %2, align 4, !dbg !23
  store i32 0, i32* %2, align 4, !dbg !24
  br label %5, !dbg !26

; <label>:5:                                      ; preds = %16, %0
  %6 = load i32, i32* %2, align 4, !dbg !27
  %7 = load i32, i32* %1, align 4, !dbg !29
  %8 = icmp sle i32 %6, %7, !dbg !30
  br i1 %8, label %9, label %19, !dbg !31

; <label>:9:                                      ; preds = %5
  %10 = load i32, i32* %2, align 4, !dbg !32
  %11 = icmp sgt i32 %10, 1, !dbg !35
  br i1 %11, label %12, label %15, !dbg !36

; <label>:12:                                     ; preds = %9
  call void @llvm.dbg.declare(metadata double* %3, metadata !37, metadata !DIExpression()), !dbg !40
  %13 = call i32 @__VERIFIER_nondet_double(), !dbg !41
  %14 = sitofp i32 %13 to double, !dbg !41
  store double %14, double* %3, align 8, !dbg !40
  br label %15, !dbg !42

; <label>:15:                                     ; preds = %12, %9
  br label %16, !dbg !43

; <label>:16:                                     ; preds = %15
  %17 = load i32, i32* %2, align 4, !dbg !44
  %18 = add nsw i32 %17, 1, !dbg !44
  store i32 %18, i32* %2, align 4, !dbg !44
  br label %5, !dbg !45, !llvm.loop !46

; <label>:19:                                     ; preds = %5
  ret void, !dbg !48
}

declare dso_local i32 @__VERIFIER_nondet_double() #2

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !49 {
  %1 = alloca i32, align 4
  %2 = alloca i32*, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca double, align 8
  store i32 0, i32* %1, align 4
  call void @foo(), !dbg !50
  call void @llvm.dbg.declare(metadata i32** %2, metadata !51, metadata !DIExpression()), !dbg !53
  store i32* null, i32** %2, align 8, !dbg !53
  call void @llvm.dbg.declare(metadata i32* %3, metadata !54, metadata !DIExpression()), !dbg !55
  call void @llvm.dbg.declare(metadata i32* %4, metadata !56, metadata !DIExpression()), !dbg !58
  call void @llvm.dbg.declare(metadata double* %5, metadata !59, metadata !DIExpression()), !dbg !60
  %6 = load i32, i32* %4, align 4, !dbg !61
  store i32 %6, i32* %3, align 4, !dbg !62
  ret i32 0, !dbg !63
}

attributes #0 = { noinline nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5}
!llvm.ident = !{!6}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 8.0.1-9 (tags/RELEASE_801/final)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, nameTableKind: None)
!1 = !DIFile(filename: "example_code_test.c", directory: "/home/hrocha/Documents/Projects/llvm_tuto/UpdateVariable_pass")
!2 = !{}
!3 = !{i32 2, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{!"clang version 8.0.1-9 (tags/RELEASE_801/final)"}
!7 = distinct !DISubprogram(name: "bar", scope: !1, file: !1, line: 6, type: !8, scopeLine: 6, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!8 = !DISubroutineType(types: !9)
!9 = !{!10}
!10 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!11 = !DILocalVariable(name: "a", scope: !7, file: !1, line: 7, type: !10)
!12 = !DILocation(line: 7, column: 7, scope: !7)
!13 = !DILocation(line: 7, column: 11, scope: !7)
!14 = !DILocation(line: 8, column: 10, scope: !7)
!15 = !DILocation(line: 8, column: 3, scope: !7)
!16 = distinct !DISubprogram(name: "foo", scope: !1, file: !1, line: 11, type: !17, scopeLine: 11, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!17 = !DISubroutineType(types: !18)
!18 = !{null}
!19 = !DILocalVariable(name: "N", scope: !16, file: !1, line: 12, type: !10)
!20 = !DILocation(line: 12, column: 7, scope: !16)
!21 = !DILocation(line: 12, column: 11, scope: !16)
!22 = !DILocalVariable(name: "i", scope: !16, file: !1, line: 13, type: !10)
!23 = !DILocation(line: 13, column: 7, scope: !16)
!24 = !DILocation(line: 14, column: 9, scope: !25)
!25 = distinct !DILexicalBlock(scope: !16, file: !1, line: 14, column: 3)
!26 = !DILocation(line: 14, column: 7, scope: !25)
!27 = !DILocation(line: 14, column: 14, scope: !28)
!28 = distinct !DILexicalBlock(scope: !25, file: !1, line: 14, column: 3)
!29 = !DILocation(line: 14, column: 18, scope: !28)
!30 = !DILocation(line: 14, column: 15, scope: !28)
!31 = !DILocation(line: 14, column: 3, scope: !25)
!32 = !DILocation(line: 15, column: 8, scope: !33)
!33 = distinct !DILexicalBlock(scope: !34, file: !1, line: 15, column: 8)
!34 = distinct !DILexicalBlock(scope: !28, file: !1, line: 14, column: 25)
!35 = !DILocation(line: 15, column: 10, scope: !33)
!36 = !DILocation(line: 15, column: 8, scope: !34)
!37 = !DILocalVariable(name: "k", scope: !38, file: !1, line: 16, type: !39)
!38 = distinct !DILexicalBlock(scope: !33, file: !1, line: 15, column: 14)
!39 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!40 = !DILocation(line: 16, column: 14, scope: !38)
!41 = !DILocation(line: 16, column: 18, scope: !38)
!42 = !DILocation(line: 17, column: 5, scope: !38)
!43 = !DILocation(line: 19, column: 3, scope: !34)
!44 = !DILocation(line: 14, column: 22, scope: !28)
!45 = !DILocation(line: 14, column: 3, scope: !28)
!46 = distinct !{!46, !31, !47}
!47 = !DILocation(line: 19, column: 3, scope: !25)
!48 = !DILocation(line: 20, column: 1, scope: !16)
!49 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 22, type: !8, scopeLine: 22, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!50 = !DILocation(line: 23, column: 3, scope: !49)
!51 = !DILocalVariable(name: "p", scope: !49, file: !1, line: 25, type: !52)
!52 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !10, size: 64)
!53 = !DILocation(line: 25, column: 8, scope: !49)
!54 = !DILocalVariable(name: "b", scope: !49, file: !1, line: 27, type: !10)
!55 = !DILocation(line: 27, column: 7, scope: !49)
!56 = !DILocalVariable(name: "a", scope: !49, file: !1, line: 29, type: !57)
!57 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!58 = !DILocation(line: 29, column: 16, scope: !49)
!59 = !DILocalVariable(name: "d", scope: !49, file: !1, line: 31, type: !39)
!60 = !DILocation(line: 31, column: 10, scope: !49)
!61 = !DILocation(line: 33, column: 7, scope: !49)
!62 = !DILocation(line: 33, column: 5, scope: !49)
!63 = !DILocation(line: 35, column: 3, scope: !49)
