#include<stdio.h>
int fact(int num)
{
    if(num==0)
    {
        return 1;
    }
    return num*fact(num-1);
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);

    int factorial=fact(num);

    printf("%d",factorial);

    return 0;
}