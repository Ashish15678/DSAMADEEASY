#include <stdio.h>

/////       Globals
char Array[5] = "abcde";
int A[5][5] = {{1, 1, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 0, 1, 1}};

////////functions

// 1. Generate all strings of n-bits
void binary(int n)
{
    if (n < 1)
    {
        printf("%s\t", Array);
    }

    else
    {
        Array[n - 1] = 0;
        binary(n - 1);
        Array[n - 1] = 1;
        binary(n - 1);
    }
}

// 2. Finding the largest Area of 1s region in a given matrix
/** Sample input
 * 11000
 * 01100
 * 00101
 * 10001
 * 01011
 *
 * Output : 5
 */

/* int geMaxOnes(int (*A)[5] s, int rmax, int colmax)
{

    int maxSize = 0;
    int size = 0;
    bool **cntarr = create2darr(rmax, colmax);
}
 */
int main(int argc, char const *argv[])
{
    // generate strings of n bits from globally declared array Array
    binary(3);
}
