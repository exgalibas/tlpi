#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

int
main(int argc, char *argv[])
{
    int fd;
    off_t seek;
    if (argc != 2 || strcmp(argv[1], "--help") == 0) {
        usageErr("%s file\n", argv[0]);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errExit("opening file %s", argv[1]);

    seek = lseek(fd, -1, SEEK_END);
    if (seek == -1)
        errExit("lseek file %s", argv[1]);

    printf("%lld\n", seek);
    exit(EXIT_SUCCESS);
}