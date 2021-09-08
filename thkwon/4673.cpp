// Self number
#include <stdio.h>

int d(int number)
{
    int sum = 0;
    int n = 0;
    n = number;
    sum += n;

    while(n != 0)
    {
        sum += n % 10;
        n = (n - (n % 10)) / 10;
        //printf("n : %d\n", n);
    }

    //printf("number : %d, sum : %d\n", number, sum);
    return sum;
}

int main()
{
    bool isNotSelfNumber[10100] = {false, };

    for(int i = 1; i < 10000; i++)
    {
        int num = d(i);
        isNotSelfNumber[num] = true;
        //printf("%d : isNotSelfNumber %d = true\n", i, num);
    }

    for(int i = 1; i < 10000; i++)
    {
        if(isNotSelfNumber[i] == false)
            printf("%d\n", i);
    }

    return 0;
}