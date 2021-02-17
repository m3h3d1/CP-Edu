#include<stdio.h>
#include<math.h>
int N = 50000, status[25010];

int main() {
    int i, j, sqrtN;
    for( i = 2; i <= N >> 1; i++ ) status[i] = 0;
    sqrtN = int( sqrt((double)N) ); // have to check primes up to (sqrt(N))
    for( i = 3; i <= sqrtN; i += 2 ) {
        if( status[i>>1] == 0 ) {
            // so, i is a prime, so, discard all the multiples
            // j = i * i, because it’s the first number to be colored
            for( j = i * i; j <= N; j += i + i )
                status[j>>1] = 1; // status of the multiple is 1
        }
    }
    // print the primes
    printf("2 ");
    for( i = 3; i <= N; i += 2 ) {
        if( status[i>>1] == 0 )
            printf("%d ", i);
    }
    return 0;
}

/*
We are not considering even numbers, but we have declared memory for even numbers.
For example we do have status[2], status[4], status[506] etc, which are completely wasted.
So, we can easily observe that half of the allocated memories are actually of no use.
Just think that between 1 and 100 there are 50 odd numbers and 50 even numbers.

Now we know that any odd number can be represent as 2 * i + 1 form where i is an integer.
Like 3 can be represented as 2 * 1 + 1, 11 can be represented as 2 * 5 + 1.

So, we can update our idea with the property that if status of i equals 0 then we will think that 
2 * i + 1 is a prime, and then we will discard all multiples of 2 * i + 1. 
When discarding the multiples, we will find the multiple in 2 * x + 1 form, and we will update the status of x.
So, If we check the status of x, we are actually checking that 2 * x + 1 is a prime or not.
So, for any integer p, we will check the status of p/2. Division is a bit costlier,
so we can right shift p once instead of dividing it by 2 as we will have same results.
So, the new code will be
*/