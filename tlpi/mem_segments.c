#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 未初始化数据段 */
int primes[] = { 2, 3, 5, 7 };  /* 初始化数据段 */
static int
square(int x)                   /* 栈 */
{
    int result;                 /* 栈 */

    result = x * x;
    return result;              /* 通过寄存器传递返回值 */
}
static void
doCalc(int val)                 /* 栈 */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 栈 */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}
int
main(int argc, char *argv[])    /* 栈 */
{
    static int key = 9973;      /* 初始化数据段 */
    static char mbuf[10240000]; /* 未初始化数据段 */
    char *p;                    /* 栈 */

    p = malloc(1024);           /* 指向堆中的内存 */

    doCalc(key);

    exit(EXIT_SUCCESS);
}