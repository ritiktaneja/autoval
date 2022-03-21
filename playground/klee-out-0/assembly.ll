; ModuleID = 'temp.bc'
source_filename = "temp.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [8 x i8] c"input_a\00", align 1
@.str.1 = private unnamed_addr constant [33 x i8] c"return_value_1 == return_value_2\00", align 1
@.str.2 = private unnamed_addr constant [7 x i8] c"temp.c\00", align 1
@__PRETTY_FUNCTION__.main = private unnamed_addr constant [11 x i8] c"int main()\00", align 1

; Function Attrs: noinline nounwind uwtable
define i32 @digitSum1(i32 %n) #0 !dbg !7 {
entry:
  %retval = alloca i32, align 4
  %n.addr = alloca i32, align 4
  %temp = alloca i32, align 4
  store i32 %n, i32* %n.addr, align 4
  call void @llvm.dbg.declare(metadata i32* %n.addr, metadata !11, metadata !DIExpression()), !dbg !12
  %0 = load i32, i32* %n.addr, align 4, !dbg !13
  %cmp = icmp slt i32 %0, 10, !dbg !15
  br i1 %cmp, label %if.then, label %if.end, !dbg !16

if.then:                                          ; preds = %entry
  %1 = load i32, i32* %n.addr, align 4, !dbg !17
  store i32 %1, i32* %retval, align 4, !dbg !19
  br label %return, !dbg !19

if.end:                                           ; preds = %entry
  call void @llvm.dbg.declare(metadata i32* %temp, metadata !20, metadata !DIExpression()), !dbg !21
  store i32 0, i32* %temp, align 4, !dbg !21
  br label %while.cond, !dbg !22

while.cond:                                       ; preds = %while.body, %if.end
  %2 = load i32, i32* %n.addr, align 4, !dbg !23
  %cmp1 = icmp sgt i32 %2, 0, !dbg !24
  br i1 %cmp1, label %while.body, label %while.end, !dbg !22

while.body:                                       ; preds = %while.cond
  %3 = load i32, i32* %n.addr, align 4, !dbg !25
  %rem = srem i32 %3, 10, !dbg !27
  %4 = load i32, i32* %temp, align 4, !dbg !28
  %add = add nsw i32 %4, %rem, !dbg !28
  store i32 %add, i32* %temp, align 4, !dbg !28
  %5 = load i32, i32* %n.addr, align 4, !dbg !29
  %div = sdiv i32 %5, 10, !dbg !29
  store i32 %div, i32* %n.addr, align 4, !dbg !29
  br label %while.cond, !dbg !22, !llvm.loop !30

while.end:                                        ; preds = %while.cond
  %6 = load i32, i32* %temp, align 4, !dbg !32
  %call = call i32 @digitSum1(i32 %6), !dbg !33
  store i32 %call, i32* %retval, align 4, !dbg !34
  br label %return, !dbg !34

return:                                           ; preds = %while.end, %if.then
  %7 = load i32, i32* %retval, align 4, !dbg !35
  ret i32 %7, !dbg !35
}

; Function Attrs: nounwind readnone speculatable
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind uwtable
define i32 @digitSum2(i32 %n) #0 !dbg !36 {
entry:
  %retval = alloca i32, align 4
  %n.addr = alloca i32, align 4
  %sum = alloca i32, align 4
  %x = alloca i32, align 4
  store i32 %n, i32* %n.addr, align 4
  call void @llvm.dbg.declare(metadata i32* %n.addr, metadata !37, metadata !DIExpression()), !dbg !38
  %0 = load i32, i32* %n.addr, align 4, !dbg !39
  %div = sdiv i32 %0, 10, !dbg !41
  %cmp = icmp eq i32 %div, 0, !dbg !42
  br i1 %cmp, label %if.then, label %if.else, !dbg !43

if.then:                                          ; preds = %entry
  %1 = load i32, i32* %n.addr, align 4, !dbg !44
  store i32 %1, i32* %retval, align 4, !dbg !45
  br label %if.end, !dbg !45

if.else:                                          ; preds = %entry
  call void @llvm.dbg.declare(metadata i32* %sum, metadata !46, metadata !DIExpression()), !dbg !48
  store i32 0, i32* %sum, align 4, !dbg !48
  call void @llvm.dbg.declare(metadata i32* %x, metadata !49, metadata !DIExpression()), !dbg !50
  %2 = load i32, i32* %n.addr, align 4, !dbg !51
  store i32 %2, i32* %x, align 4, !dbg !50
  br label %while.cond, !dbg !52

while.cond:                                       ; preds = %while.body, %if.else
  %3 = load i32, i32* %x, align 4, !dbg !53
  %cmp1 = icmp sgt i32 %3, 0, !dbg !54
  br i1 %cmp1, label %while.body, label %while.end, !dbg !52

while.body:                                       ; preds = %while.cond
  %4 = load i32, i32* %x, align 4, !dbg !55
  %rem = srem i32 %4, 10, !dbg !57
  %5 = load i32, i32* %sum, align 4, !dbg !58
  %add = add nsw i32 %5, %rem, !dbg !58
  store i32 %add, i32* %sum, align 4, !dbg !58
  %6 = load i32, i32* %x, align 4, !dbg !59
  %div2 = sdiv i32 %6, 10, !dbg !59
  store i32 %div2, i32* %x, align 4, !dbg !59
  br label %while.cond, !dbg !52, !llvm.loop !60

while.end:                                        ; preds = %while.cond
  %7 = load i32, i32* %sum, align 4, !dbg !62
  %call = call i32 @digitSum2(i32 %7), !dbg !63
  br label %if.end

if.end:                                           ; preds = %if.then, %while.end
  %8 = load i32, i32* %retval, align 4, !dbg !64
  ret i32 %8, !dbg !64
}

; Function Attrs: noinline nounwind uwtable
define i32 @main() #0 !dbg !65 {
entry:
  %retval = alloca i32, align 4
  %input_a = alloca i32, align 4
  %return_value_1 = alloca i32, align 4
  %return_value_2 = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata i32* %input_a, metadata !68, metadata !DIExpression()), !dbg !69
  %call = call i32 (i32*, i64, i8*, ...) bitcast (i32 (...)* @klee_make_symbolic to i32 (i32*, i64, i8*, ...)*)(i32* %input_a, i64 4, i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str, i32 0, i32 0)), !dbg !70
  %0 = load i32, i32* %input_a, align 4, !dbg !71
  %cmp = icmp sgt i32 %0, 0, !dbg !72
  %conv = zext i1 %cmp to i32, !dbg !72
  %call1 = call i32 (i32, ...) bitcast (i32 (...)* @klee_assume to i32 (i32, ...)*)(i32 %conv), !dbg !73
  call void @llvm.dbg.declare(metadata i32* %return_value_1, metadata !74, metadata !DIExpression()), !dbg !75
  %1 = load i32, i32* %input_a, align 4, !dbg !76
  %call2 = call i32 @digitSum1(i32 %1), !dbg !77
  store i32 %call2, i32* %return_value_1, align 4, !dbg !75
  call void @llvm.dbg.declare(metadata i32* %return_value_2, metadata !78, metadata !DIExpression()), !dbg !79
  %2 = load i32, i32* %input_a, align 4, !dbg !80
  %call3 = call i32 @digitSum2(i32 %2), !dbg !81
  store i32 %call3, i32* %return_value_2, align 4, !dbg !79
  %3 = load i32, i32* %return_value_1, align 4, !dbg !82
  %4 = load i32, i32* %return_value_2, align 4, !dbg !82
  %cmp4 = icmp eq i32 %3, %4, !dbg !82
  br i1 %cmp4, label %if.end, label %if.else, !dbg !85

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.1, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), i32 45, i8* getelementptr inbounds ([11 x i8], [11 x i8]* @__PRETTY_FUNCTION__.main, i32 0, i32 0)) #4, !dbg !82
  unreachable, !dbg !82

if.end:                                           ; preds = %entry
  ret i32 0, !dbg !86
}

declare i32 @klee_make_symbolic(...) #2

declare i32 @klee_assume(...) #2

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #3

attributes #0 = { noinline nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5}
!llvm.ident = !{!6}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 6.0.1 ", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2)
!1 = !DIFile(filename: "temp.c", directory: "/home/klee/data/playground")
!2 = !{}
!3 = !{i32 2, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{!"clang version 6.0.1 "}
!7 = distinct !DISubprogram(name: "digitSum1", scope: !1, file: !1, line: 7, type: !8, isLocal: false, isDefinition: true, scopeLine: 8, flags: DIFlagPrototyped, isOptimized: false, unit: !0, variables: !2)
!8 = !DISubroutineType(types: !9)
!9 = !{!10, !10}
!10 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!11 = !DILocalVariable(name: "n", arg: 1, scope: !7, file: !1, line: 7, type: !10)
!12 = !DILocation(line: 7, column: 19, scope: !7)
!13 = !DILocation(line: 9, column: 5, scope: !14)
!14 = distinct !DILexicalBlock(scope: !7, file: !1, line: 9, column: 5)
!15 = !DILocation(line: 9, column: 6, scope: !14)
!16 = !DILocation(line: 9, column: 5, scope: !7)
!17 = !DILocation(line: 10, column: 10, scope: !18)
!18 = distinct !DILexicalBlock(scope: !14, file: !1, line: 9, column: 10)
!19 = !DILocation(line: 10, column: 3, scope: !18)
!20 = !DILocalVariable(name: "temp", scope: !7, file: !1, line: 12, type: !10)
!21 = !DILocation(line: 12, column: 6, scope: !7)
!22 = !DILocation(line: 13, column: 2, scope: !7)
!23 = !DILocation(line: 13, column: 8, scope: !7)
!24 = !DILocation(line: 13, column: 9, scope: !7)
!25 = !DILocation(line: 14, column: 10, scope: !26)
!26 = distinct !DILexicalBlock(scope: !7, file: !1, line: 13, column: 12)
!27 = !DILocation(line: 14, column: 11, scope: !26)
!28 = !DILocation(line: 14, column: 7, scope: !26)
!29 = !DILocation(line: 15, column: 4, scope: !26)
!30 = distinct !{!30, !22, !31}
!31 = !DILocation(line: 16, column: 2, scope: !7)
!32 = !DILocation(line: 17, column: 19, scope: !7)
!33 = !DILocation(line: 17, column: 9, scope: !7)
!34 = !DILocation(line: 17, column: 2, scope: !7)
!35 = !DILocation(line: 18, column: 1, scope: !7)
!36 = distinct !DISubprogram(name: "digitSum2", scope: !1, file: !1, line: 21, type: !8, isLocal: false, isDefinition: true, scopeLine: 22, flags: DIFlagPrototyped, isOptimized: false, unit: !0, variables: !2)
!37 = !DILocalVariable(name: "n", arg: 1, scope: !36, file: !1, line: 21, type: !10)
!38 = !DILocation(line: 21, column: 19, scope: !36)
!39 = !DILocation(line: 23, column: 5, scope: !40)
!40 = distinct !DILexicalBlock(scope: !36, file: !1, line: 23, column: 5)
!41 = !DILocation(line: 23, column: 6, scope: !40)
!42 = !DILocation(line: 23, column: 9, scope: !40)
!43 = !DILocation(line: 23, column: 5, scope: !36)
!44 = !DILocation(line: 23, column: 21, scope: !40)
!45 = !DILocation(line: 23, column: 14, scope: !40)
!46 = !DILocalVariable(name: "sum", scope: !47, file: !1, line: 25, type: !10)
!47 = distinct !DILexicalBlock(scope: !40, file: !1, line: 24, column: 6)
!48 = !DILocation(line: 25, column: 7, scope: !47)
!49 = !DILocalVariable(name: "x", scope: !47, file: !1, line: 26, type: !10)
!50 = !DILocation(line: 26, column: 7, scope: !47)
!51 = !DILocation(line: 26, column: 11, scope: !47)
!52 = !DILocation(line: 27, column: 3, scope: !47)
!53 = !DILocation(line: 27, column: 10, scope: !47)
!54 = !DILocation(line: 27, column: 11, scope: !47)
!55 = !DILocation(line: 29, column: 9, scope: !56)
!56 = distinct !DILexicalBlock(scope: !47, file: !1, line: 28, column: 3)
!57 = !DILocation(line: 29, column: 10, scope: !56)
!58 = !DILocation(line: 29, column: 7, scope: !56)
!59 = !DILocation(line: 30, column: 5, scope: !56)
!60 = distinct !{!60, !52, !61}
!61 = !DILocation(line: 31, column: 3, scope: !47)
!62 = !DILocation(line: 32, column: 13, scope: !47)
!63 = !DILocation(line: 32, column: 3, scope: !47)
!64 = !DILocation(line: 34, column: 1, scope: !36)
!65 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 37, type: !66, isLocal: false, isDefinition: true, scopeLine: 38, isOptimized: false, unit: !0, variables: !2)
!66 = !DISubroutineType(types: !67)
!67 = !{!10}
!68 = !DILocalVariable(name: "input_a", scope: !65, file: !1, line: 39, type: !10)
!69 = !DILocation(line: 39, column: 6, scope: !65)
!70 = !DILocation(line: 40, column: 2, scope: !65)
!71 = !DILocation(line: 41, column: 14, scope: !65)
!72 = !DILocation(line: 41, column: 22, scope: !65)
!73 = !DILocation(line: 41, column: 2, scope: !65)
!74 = !DILocalVariable(name: "return_value_1", scope: !65, file: !1, line: 42, type: !10)
!75 = !DILocation(line: 42, column: 6, scope: !65)
!76 = !DILocation(line: 42, column: 33, scope: !65)
!77 = !DILocation(line: 42, column: 23, scope: !65)
!78 = !DILocalVariable(name: "return_value_2", scope: !65, file: !1, line: 43, type: !10)
!79 = !DILocation(line: 43, column: 6, scope: !65)
!80 = !DILocation(line: 43, column: 33, scope: !65)
!81 = !DILocation(line: 43, column: 23, scope: !65)
!82 = !DILocation(line: 45, column: 2, scope: !83)
!83 = distinct !DILexicalBlock(scope: !84, file: !1, line: 45, column: 2)
!84 = distinct !DILexicalBlock(scope: !65, file: !1, line: 45, column: 2)
!85 = !DILocation(line: 45, column: 2, scope: !84)
!86 = !DILocation(line: 47, column: 2, scope: !65)
