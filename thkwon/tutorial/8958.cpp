// 8958 - OX퀴즈

#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0;
    scanf("%d", &count);
    for(int i = 0; i < count; i++)
    {
        int score = 0;
        int point = 1; // 획득점수(연속된 O의 숫자)
        char str[80];
        scanf("%s", str);
        for(int j = 0; j < strlen(str); j++)
        {
            if(str[j] == 'O') score += point++;
            else point = 1;
        }
        printf("%d\n",score);
    }
    return 0;
}

// 1차시도 : 성공
// 첫 코딩에서 올바른 값이 나오지는 않음.(연속된 O의 개수만큼이 획득점수가 된다는 것을 확인 못함)

