// 2108 - 통계학
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// int compare(const void *a, const void *b){
//     if(*(int*)a > *(int*)b ){
//         return 1;
//     }
//     else if(*(int*)a > *(int*)b ){
//         return -1;
//     }
//     else{
//         return 0;
//     }
// }

int main()
{
    int number = 0; // 입력값 - 1<=n<=500000 (홀수)
    scanf("%d", &number);
    
    int sum = 0; // 산술평균용
    //int sortedArray[500001] = {0, };
    int rank[8002] = {0, }; // 최빈값용(정수이므로 +-4000 - 8000)
    int maxCount = 0; // 최빈값용
    int maxCountValue = 0; // 최빈값용
    int maxCountSecondValue = 9999; // 최빈값용
    bool isMaxCountDuplicate = false; // 최빈값용
    int maxNumber = -9999; // 범위 확인용(최대값)
    int minNumber = 9999; // 범위 확인용(최소값)

    // 첫 숫자용 처리(가운데에 넣음)
    int firstValue = 0;
    scanf("%d", &firstValue);
    sum += firstValue;
    rank[firstValue + 4000] = 1;
    maxCount = 1;
    maxCountValue = firstValue;
    maxNumber = minNumber = firstValue;
    //sortedArray[0] = firstValue;
    //printf("initial max : %d, min : %d\n", maxNumber, minNumber);

    for(int i = 1; i < number; i++)
    {
        // 내용 받기
        int member = 0;
        scanf("%d", &member);

        // 산술평균용 합
        sum += member;
        //printf("debug sum : %d\n", sum);

        //sortedArray[i] = member;

        // 최빈값
        rank[member + 4000] += 1;
        //printf("debug rank %d : %d\n", member, rank[member + 4000]);
        if(rank[member + 4000] > maxCount)
        {
            //printf("debug rank change %d -> %d : %d -> %d\n", maxCountValue, member, maxCount, rank[member + 4000]);
            maxCount = rank[member + 4000];
            maxCountValue = member;
            isMaxCountDuplicate = false;
            maxCountSecondValue = 9999;
        }
        else if(rank[member+4000] == maxCount)
        {
            // 동률일 경우
            if(maxCountValue > member) 
            {
                maxCountSecondValue = maxCountValue;
                maxCountValue = member;
            }                
            else if(maxCountSecondValue > member)
            {
                maxCountSecondValue = member;
            }
            isMaxCountDuplicate = true;
            //printf("debug max-min duplicate : change to %d \n", maxCountSecondValue);
        }
        
        // 범위
        if(member > maxNumber) maxNumber = member;
        if(member < minNumber) minNumber = member;
        //printf("debug max-min count after %d - max : %d, min : %d\n", member, maxNumber, minNumber);
    }

    // 중간값 확인
    // 정렬 없이 확인하기(최빈값 계산한 값을 이용)
    int medianCount = 0;
    int medianNumber = 0;
    for(medianNumber = 0; medianNumber < 8000; medianNumber++)
    {
        medianCount += rank[medianNumber];
        if(medianCount > number / 2) break;
    }
    medianNumber -= 4000;

    // 퀵소트 사용해 중간값 확인
    //qsort(sortedArray, number, sizeof(int), compare);

    // 결과 출력
    //printf("sum : %d, number : %d\n", sum, number);
    printf("%d\n", (int)round((double)sum / (double)number));
    printf("%d\n", medianNumber);
    //printf("%d\n", sortedArray[number / 2]); // 중간값(퀵소트 활용)
    printf("%d\n", isMaxCountDuplicate ? maxCountSecondValue : maxCountValue);
    printf("%d\n", maxNumber - minNumber);
    
    return 0;
}

// 중앙값 정하기 위해 큰 크기의 배열 및 정렬이 무조건 필요하게 됨
// 최빈값은 배열화하면 음수가 지정이 안되므로 +4000(정수 최대값)을 넣음
// 최빈값이 동률일때 두번째로 작은 값 정하라고 해서.. 두 값을 갖고 있어야 할 듯함.
// 결과 평균값 반올림이 음수일때 잘 안됨.. -> round를 걸고 형변환을 넣으니 어찌저찌 됨

// 1차시도 : 실패(시간초과) - sort에서 시간이 많이 걸린 듯함.(O(nlogn)?) sort를 입력받을때가 아니라 따로 수행해봄(퀵소트를 가져옴)
// 2차시도 : 실패(시간초과) - 퀵소트로도 안됨. 정렬 없이 계산할수 있나? -> rank값을 이용해 봄
// 3차시도 : 성공
// 기타 : 퀵소트를 c에서 제공하는 qsort()를 사용하면 시간제한 내에 해결이 됬음. 이쪽이 원래 의도한 정답일 가능성이 높음..
