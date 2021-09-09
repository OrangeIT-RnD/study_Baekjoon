// 3052 - 나머지
// author : thKwon(th.kwon29@gmail.com) - 2021/09/08

#include "stdio.h"

int main()
{
    bool isValueExist[43];

    int valueCount = 0;
    for(int i = 0; i < 10; i++)
    {
        int number = 0;
        scanf("%d", &number);
        number = number % 42;
        if(isValueExist[number] == false)
        {
            isValueExist[number] = true;
            valueCount++;
        }
    }

    // 결과 출력
    printf("%d", valueCount);
    return 0;
}