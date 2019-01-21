#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

int
main(int argc, char *argv[])
{
    if (argc < 2)
        usageErr("asshole\n");

    int fd, fd1, fd2;

    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    fd1 = dup(fd);
    fd2 = open(argv[1], O_RDWR);

    write(fd, "Hello,", 6);
    write(fd1, "world", 5);
    lseek(fd1, 0, SEEK_SET);
    write(fd, "HELLO,", 6);
    write(fd2, "Gidday", 6);

    close(fd);
    close(fd1);
    close(fd2);
}