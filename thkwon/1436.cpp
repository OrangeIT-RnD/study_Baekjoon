// 1436 - 영화감독 숌

#include <stdio.h>

bool is666(int n)
{
    bool isFound = false;
    int findCount = 0;
    while(n > 0)
    {
        if(n % 10 == 6)
        {
            if(isFound == true) findCount++;
            else isFound = true;

            if(findCount == 2) return true;
        }
        else 
        {
            isFound = false;
            findCount = 0;
        }
        n /= 10;
    }
    
    return false;
}

int main()
{
    int number = 0;
    scanf("%d", &number);

    // printf("%d", findIndex(number));

    // brute force 사용하기
    int count = 0;
    int findNumber = 665;
    while(count < 10000)
    {
        if(is666(findNumber)) 
        {   
            count++;
            //printf("%d - %d\n", count, findNumber); // 디버그용
            if(count == number) break;
        }
        findNumber++;
    }

    printf("%d", findNumber);
    return 0;
}

// 1차시도 : 통과
// 369 게임과 유사하게 숫자를 세나간다고 보면 됨. 369 대신 666이 되었다는 정도의 차이.
// brute force를 사용한다고 해서 이렇게 만들어보긴 했지만, 공식화도 가능할듯해 보임.
// 아래는 공식화하려다 말은 정리내용(함수도 미완성)

// 세자리 : 0666 
// 네자리 : 1666 - 2666 - 3666 - 4666 - 5666 - 6660 - 6661 - 6662 - ... - 6669 - 7666 - 8666 - 9666 
//          -> 1 * 9개 + 10 
//          -> 19개 -> 6 - 10 - 3
// 다섯자리 : 10666(19개) - 11666(19개) - ... - 20666 - 30666 - ... - 60666 - ... - 65666 - 66600 - ... - 66699 - 67666 - 99666
//          -> 19개 * 99 + 100 
//          -> 1981개 -> 66*19 - 100 - 33*19
// 여섯자리(예상) : 1980019개 -> 1981 * 999 + 1000 -> 666 * 1981 - 1000 - 333 * 1981
// n번째 영화 : 

int findIndex(int n)
{
    if(n <= 19)
    {
        // 세자리
        if(n < 7 || n > 16) return n * 1000 + 666;
        else return 6660 + n - 7;
    }
    else if(n <= 1981)
    {
        // 네자리
        if(n < 19*66)
        {
            int subindex = n % 19;
            return findIndex(subindex) + ( (n - subindex) / 19 + 9 ) * 1000;
        }
        else if(n > 19*99 + 100)
        {
            int mainindex = (n - (67 * 19) - 100);
            int subindex = mainindex % 19;
            return findIndex(subindex) + ( (mainindex - subindex) / 19 + 9 ) * 1000;
        }
    }
}
