// hansu
#include <stdio.h>

bool is_hansu(int number)
{
    int number1 = number % 10;
    number -= number % 10;
    if(number == 0) return true; // 한자리 숫자
    number /= 10;

    int number2 = number % 10; // 두번째 자릿수   
    int diff = number2 - number1;
    number1 = number2;
    while(number > 9) // 세자리 이상일 경우
    {
        number -= number % 10;
        number /= 10;
        number2 = number % 10;    
        if(number2 - number1 != diff)
            return false;
        number1 = number2;
    }
    return true;
}

int main()
{
    int input = 0;
    int count = 0;

    scanf("%d", &input);

    for(int i = 1; i <= input; i++)
        if(is_hansu(i) == true) count++;

    printf("%d", count);

    return 0;
}