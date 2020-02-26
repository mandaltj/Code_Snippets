1) For compilation - gcc -o simple simple.c
2) Compiler - https://godbolt.org/
.LC0:
        .string "%d\n"
main:
        pushq   %rbp					<- Push the old frame pointer onto stack(8B of frame pointer)
        movq    %rsp, %rbp				<- Move the current stackpointer to framepointer register
        subq    $16, %rsp				<- For 32B stack space allocation in x86
        movl    $10, -4(%rbp)			<- int x = 10 allocation on stack as argument
        movl    -4(%rbp), %eax			<- Not sure!! This is to bring 'x' from stack memory into %eax register
        movl    %eax, %esi				<- Move x from %eax to %esi 2nd argument(4B)
        movl    $.LC0, %edi				<- 1st argument(4B)
        movl    $0, %eax				<- https://stackoverflow.com/questions/6212665/why-is-eax-zeroed-before-a-call-to-printf
        call    printf
        movl    $0, %eax
        leave
        ret

Total space used on stack = 8B (old %rbp) + 4B (x) + 8B(Return Address when printf called) + 12B(unused)
The "subq $16, %rsp" has $16 because it knows that 8B (old %rbp) has already been used in this frame and further 8B wil be used for RA. So, it allocates a 16B decrement of Stack pointer
for storing arguments and in case arguments need to be passed to a called function. Of the 16B allocated, only 4B are used for 'x'. 
