#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>
// #include <sys/stat.h>


int main() {
    // syscall(SYS_mkdir, "foo", S_IRUSR | S_IWUSR);
    syscall(SYS_mkdir, "teste", 0777); // zero na frente é octal
    long fd = syscall(SYS_open, "text.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    syscall(SYS_write, fd, "Hello, World!\n", 14);
    syscall(SYS_close, fd);
    syscall(SYS_exit, 0);
}