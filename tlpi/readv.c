#include <fcntl.h>
#include <sys/uio.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

int
main(int argc, char *argv[])
{
    int fd;
    struct iovec iov[1];
#define STR_SIZE 20
    char str[STR_SIZE];//, str2[STR_SIZE], str3[STR_SIZE];
    ssize_t numRead;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errExit("open");

    iov[1].iov_base = str;
    iov[1].iov_len = STR_SIZE;

    /*iov[2].iov_base = str2;
    iov[2].iov_len = STR_SIZE;

    iov[3].iov_base = str3;
    iov[3].iov_len = STR_SIZE;*/

    numRead = readv(fd, iov, 1);

    if (numRead == -1) {
        errExit("readv");
    }

    //printf("%s\n%s\n%s\n", str1, str2, str3);
    printf("%s\n", str);
    exit(EXIT_SUCCESS);
}