; ModuleID = 'temp3.bc'
source_filename = "temp3.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [8 x i8] c"input_a\00", align 1
@.str.1 = private unnamed_addr constant [33 x i8] c"return_value_1 == return_value_2\00", align 1
@.str.2 = private unnamed_addr constant [8 x i8] c"temp3.c\00", align 1
@__PRETTY_FUNCTION__.main = private unnamed_addr constant [11 x i8] c"int main()\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define i32 @digitSum1(i32 %n) #0 {
entry:
  %retval = alloca i32, align 4
  %n.addr = alloca i32, align 4
  store i32 %n, i32* %n.addr, align 4
  %0 = load i32, i32* %n.addr, align 4
  %cmp = icmp eq i32 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %1 = load i32, i32* %n.addr, align 4
  %div = sdiv i32 %1, 10
  %call = call i32 (i32, ...) bitcast (i32 (...)* @digitSum to i32 (i32, ...)*)(i32 %div)
  %2 = load i32, i32* %n.addr, align 4
  %rem = srem i32 %2, 10
  %add = add nsw i32 %call, %rem
  store i32 %add, i32* %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %3 = load i32, i32* %retval, align 4
  ret i32 %3
}

declare i32 @digitSum(...) #1

; Function Attrs: noinline nounwind optnone uwtable
define i32 @digitSum2(i32 %n) #0 {
entry:
  %retval = alloca i32, align 4
  %n.addr = alloca i32, align 4
  %current_sum = alloca i32, align 4
  store i32 %n, i32* %n.addr, align 4
  %0 = load i32, i32* %n.addr, align 4
  %cmp = icmp sge i32 %0, 10
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  store i32 0, i32* %current_sum, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.then
  %1 = load i32, i32* %n.addr, align 4
  %cmp1 = icmp sgt i32 %1, 0
  br i1 %cmp1, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %2 = load i32, i32* %n.addr, align 4
  %rem = srem i32 %2, 10
  %3 = load i32, i32* %current_sum, align 4
  %add = add nsw i32 %3, %rem
  store i32 %add, i32* %current_sum, align 4
  %4 = load i32, i32* %n.addr, align 4
  %mul = mul nsw i32 %4, 10
  store i32 %mul, i32* %n.addr, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %5 = load i32, i32* %current_sum, align 4
  %call = call i32 (i32, ...) bitcast (i32 (...)* @digitSum to i32 (i32, ...)*)(i32 %5)
  store i32 %call, i32* %retval, align 4
  br label %return

if.else:                                          ; preds = %entry
  %6 = load i32, i32* %n.addr, align 4
  store i32 %6, i32* %retval, align 4
  br label %return

return:                                           ; preds = %if.else, %while.end
  %7 = load i32, i32* %retval, align 4
  ret i32 %7
}

; Function Attrs: noinline nounwind optnone uwtable
define i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %input_a = alloca i32, align 4
  %return_value_1 = alloca i32, align 4
  %return_value_2 = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  %call = call i32 (i32*, i64, i8*, ...) bitcast (i32 (...)* @klee_make_symbolic to i32 (i32*, i64, i8*, ...)*)(i32* %input_a, i64 4, i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str, i32 0, i32 0))
  %0 = load i32, i32* %input_a, align 4
  %cmp = icmp sgt i32 %0, 0
  %conv = zext i1 %cmp to i32
  %call1 = call i32 (i32, ...) bitcast (i32 (...)* @klee_assume to i32 (i32, ...)*)(i32 %conv)
  %1 = load i32, i32* %input_a, align 4
  %call2 = call i32 @digitSum1(i32 %1)
  store i32 %call2, i32* %return_value_1, align 4
  %2 = load i32, i32* %input_a, align 4
  %call3 = call i32 @digitSum2(i32 %2)
  store i32 %call3, i32* %return_value_2, align 4
  %3 = load i32, i32* %return_value_1, align 4
  %4 = load i32, i32* %return_value_2, align 4
  %cmp4 = icmp eq i32 %3, %4
  br i1 %cmp4, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.1, i32 0, i32 0), i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.2, i32 0, i32 0), i32 38, i8* getelementptr inbounds ([11 x i8], [11 x i8]* @__PRETTY_FUNCTION__.main, i32 0, i32 0)) #3
  unreachable

if.end:                                           ; preds = %if.then
  ret i32 0
}

declare i32 @klee_make_symbolic(...) #1

declare i32 @klee_assume(...) #1

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #2

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 6.0.1 "}
