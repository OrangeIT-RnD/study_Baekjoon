// BOJ Problem no.2581
// author : thKwon(th.kwon29@gmail.com) - 2021/09/08

#include "stdio.h"

bool isPrimeNumber(int number)
{
    if(number == 1) return false; // 1은 소수가 아니며, 아래 체크로 걸러지지 않아 별도 처리
    for(int i = 2; i < number; i++)
        if(number % i == 0) return false;
    return true;
}

int main()
{
    int start, end;
    scanf("%d", &start);
    scanf("%d", &end);

    int sum = 0;
    int primeNumber = -1;
    for(int i = start; i <= end; i++)
    {
        if(isPrimeNumber(i) == true)
        {
            if(primeNumber == -1) primeNumber = i;
            sum += i;
            //printf("debug - prime found - %d\n", i);
        }
    }

    if(primeNumber == -1) printf("-1");
    else
    {
        printf("%d\n%d", sum, primeNumber);
    }

    return 0;
}

/*
attemps
    - 1차시도 : 틀림(소수 연산법이 틀린건가 애매한데, 일단 sum을 long으로 바꿔 봄..)
    - 2차시도 : 틀림
       - 소수체크해봤는데 대부분 맞음
       - 1이 소수에 포함되는 문제가 있어서 1만 예외처리 해봄
    - 3차시도 : 성공
note
    - 소수 연산방법 : %로 연산해 0이 되는지 확인하기? - 오래 걸릴듯함..
        - 이 방법 사용시 1은 예외처리해야 함.
*/
