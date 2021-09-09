#include <stdio.h>

int main()
{
    int number = 0;
    int newnumber = 0;
    int count = 0;
    int numberA = 0;
    int numberB = 0;
    scanf("%d", &number);

    newnumber = number;

    do
    {            
        numberA = newnumber % 10;
        numberB = (newnumber - numberA) / 10;
        newnumber = numberA * 10 + ((numberA + numberB) % 10);
        //printf("%d + %d = %d -> %d\n", numberA, numberB, numberA + numberB, newnumber);
        count++;
    } while(number != newnumber);

    printf("%d", count);

    return 0;
}

/*
    1차시도 : 시간초과 발생
       - if(newnumber < 10) newnumber *= 10; 은 필요없어 보여 뺌
       - numberA, numberB를 외부 변수로 사용해 변수선언하는 시간을 줄임
    2차시도 : 통과
       - 복잡도를 줄이는 방법이 있으면 더 좋아 보임. -> 없는 듯..
*/