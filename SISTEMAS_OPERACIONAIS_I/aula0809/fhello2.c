#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>
// #include <sys/stat.h>


int main() {
    mkdir("foo", 0777);
    long fd = open("foo/aula.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    write(fd, "Hello, World!\n", 14);
    close(fd);
    exit(0);

}