
// solving problem using recursion

////INCLUDES
#include <stdio.h>

// functions
void TowerOfHanoiProblem(int n, char source, char aux, char dest)
{

    // n is the number of discs in tower of hanoi

    // base case
    if (n == 1)
    {
        printf("Move \c to \c\n", source, dest);
        return;
    }

    // move top n-1 disc to dest using auxiliary
    TowerOfHanoiProblem(n - 1, source, dest, aux);

    //move remaining disks from source to destination
    printf("Move \c from ");

}

int main()
{
}