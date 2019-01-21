#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int
main(int argc, char *argv[])
{
    int fd;
    off_t seek;
    ssize_t numWrite;
    if (argc != 3 || strcmp(argv[1], "--help") == 0) {
        usageErr("%s file text\n", argv[0]);
    }

    fd = open(argv[1], O_RDWR | O_APPEND);
    if (fd == -1)
        errExit("opening file %s", argv[1]);

    seek = lseek(fd, 1000, SEEK_END);
    if (seek == -1)
        errExit("lseek file %s", argv[1]);

    numWrite = write(fd, argv[2], strlen(argv[2]));
    if (numWrite == -1)
        errExit("write file %s", argv[1]);

    if (close(fd) == -1)
        errExit("read");

    exit(EXIT_SUCCESS);
}