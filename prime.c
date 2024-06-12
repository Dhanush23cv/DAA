#include <stdio.h>
#include <math.h>

// Recursive function to check if a number is prime
int isPrime(int num, int divisor)
{
    // Base case 1: if num is less than 2, it is not a prime number
    if (num < 2)
    {
        return 0;
    }

    // Base case 2: if divisor is greater than sqrt(num), then num is prime
    if (divisor > sqrt(num))
    {
        return 1;
    }

    // If num is divisible by divisor, it is not a prime number
    if (num % divisor == 0)
    {
        return 0;
    }

    // Recursive case: check the next divisor
    return isPrime(num, divisor + 1);
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if (isPrime(num, 2))
    {
        printf("%d is a prime number.\n", num);
    }
    else
    {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
