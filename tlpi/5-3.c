#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

int
main(int argc, char *argv[])
{
    int mode = O_CREAT|O_RDWR|O_APPEND;
    char byte = 'a';
    int num = 100000;
    ssize_t numWrite;
    int fd;

    if (argc < 2)
        usageErr("asshole\n");
    else if (argc == 3 && strcmp(argv[2], "x") == 0)
        mode &= ~O_APPEND;

    fd = open(argv[1], mode, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open");

    while (num-- > 0) {
        lseek(fd, 0, SEEK_END);
        numWrite = write(fd, &byte, 1);
        if (numWrite == -1)
            errExit("write");
    }

    if (close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}