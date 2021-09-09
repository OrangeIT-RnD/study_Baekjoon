// BOJ Problem no.11729 - 하노이 탑
// author : thKwon(th.kwon29@gmail.com) - 2021/09/08

#include "stdio.h"

int calcHanoi(int size)
{
    if(size == 1) return size;
    return calcHanoi(size - 1) * 2 + 1;
}

void printHanoi(int size, int start, int end, int sub)
{
    if(size == 1) printf("%d %d\n", start, end);
    else
    {
        printHanoi(size-1, start, sub, end);
        printf("%d %d\n", start, end);
        printHanoi(size-1, sub, end, start);
    }
}

int main()
{
    int number;
    scanf("%d", &number);
    printf("%d\n", calcHanoi(number));
    printHanoi(number, 1, 3, 2);
    return 0;
}

/*
attemps
    - 1차시도 : 성공
note
    - 하노이 탑의 이동 방식
        - 1층 : 1-3(1) - 1회 
        - 2층 : 1-2(1) 1-3(2) 2-3(1) - 3회 
            -> 1층 + 2번원반 + 1층
        - 3층 : 1-3(1) 1-2(2) 3-2(1) 1-3(3) 2-1(1) 2-3(2) 1-3(1) - 7회
            -> 2층 + 3번원반 + 2층 -> 1층 + 2번원반 + 1층 + 3번원반 + 1층 + 2번원반 + 1층
        - 4층 : 3층 + 4번 + 3층 -> 15회
        ... -> 2^n - 1 이 됨.(재귀호출로 해도 됨)
    - 수행과정 출력 이전에 횟수를 출력해야 하는게 번거로워 보임..
*/