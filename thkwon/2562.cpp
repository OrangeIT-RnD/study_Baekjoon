// 2562 - 최댓값

#include <stdio.h>

int main()
{
    int maxNumber = 0;
    int maxNumberPosition = 0;
    for(int i = 0; i < 9; i++)
    {
        int number = 0;
        scanf("%d", &number);
        if(number > maxNumber) 
        {
            maxNumber = number;
            maxNumberPosition = i + 1;
        }
    }

    printf("%d\n%d", maxNumber, maxNumberPosition);
    
    return 0;
}

// 1차시도 : 성공. 그런데 배열을 사용하는게 의도같아 보이는데 사용 안함..
// 배열 사용하도록 고치는건 어렵지 않아보이니 패스