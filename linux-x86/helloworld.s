BITS 32

;ssize_t write(int fd, const void *buf, size_t count)
xor eax, eax
push eax ; to null terminate the string 
push 0x0a646c72 ; pushing "rld\n" of "Hello World\n" in the stack 
push 0x6f57206f ; pushing "o Wo" in the stack 
push 0x6c6c6548 ; pushing "Hell" in the stack
mov ecx, esp ; store the string address in ecx
push eax ; null terminating the stack
mov al, 4 ; syscall write no #4
push BYTE 1
pop ebx ; file descripter no of stdout #1
push BYTE 12
pop edx ; size of the string 
int 0x80 ; executing the syscall

;void exit(int status)
mov al, 1 ; syscall exit no #1
dec bl ; setting the argument of exit to 0
int 0x80 ; making an exit
