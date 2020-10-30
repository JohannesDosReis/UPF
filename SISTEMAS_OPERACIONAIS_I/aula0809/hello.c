#include <unistd.h>
#include <sys/syscall.h>

int main() {
    // syscall(1, 1, "Hello, World\n", 14);
    // syscall(60, 0);

    // with sys/syscall
    syscall(SYS_write, 1, "Hello, World\n", 14); 
    syscall(SYS_exit, 0);
}