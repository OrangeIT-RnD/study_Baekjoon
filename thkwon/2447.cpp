// 별 찍기
#include <stdio.h>
#include <math.h>

void setStar(int size, int startX, int startY, bool matrix[][2200])
{
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {            
            // 가운데 구멍
            if(x == 1 && y == 1) continue;

            if(size == 1)
                matrix[startX + x][startY + y] = true;
            else
                setStar(size / 3, startX + x * size, startY + y * size, matrix);
        }
    }
}

int main()
{
    bool isPrintStar[2200][2200];
    int input = 0;
    scanf("%d", &input);
    
    setStar(input / 3, 0, 0, isPrintStar);

    for(int x = 0; x < input; x++)
    {
        for(int y = 0; y < input; y++)
            printf("%s", isPrintStar[x][y] ? "*" : " ");
        printf("\n");
    }

    return 0;
}

// 메모리 설정시 1<=k<8 의 등호 여부를 잘못봐서 하나 크게 했더니 메모리 소비량이 매우 커졌음. 줄였더니 어느정도 정상화됨
// 그래도 exe파일이 터미널로 실행되지는 않음.. 배열을 너무 크게 잡아서인가?
// input을 k로 받는게 아니라 n을 받아서 pow를 쓰게 만들었다가 빼고, 나누기로 변경한 부분이 조금 있음.