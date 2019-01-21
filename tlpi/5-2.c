#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

int
main(int argc, char *argv[])
{
    if (argc != 3)
        usageErr("asshole\n");

    int fd;
    off_t seek;
    ssize_t nWrite;
    //char buffer[] = "asshole";
    fd = open(argv[1], O_APPEND|O_RDWR);
    if (fd == -1)
        errExit("open");

    printf("%d\n", fd);

    seek = lseek(fd, 0, SEEK_SET);
    if (seek == -1)
        errExit("lseek");

    nWrite = write(fd, argv[2], strlen(argv[2]));
    if (nWrite == -1)
        errExit("write");

    if (close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}