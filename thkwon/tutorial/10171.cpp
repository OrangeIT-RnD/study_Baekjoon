// 10171 - 고양이
// \    /\
//  )  ( ')
// (  /  )
//  \(__)|
// escape 문자를 잘 출력하도록 활용할 필요 있음

#include "stdio.h"

int main()
{
    printf("\\    /\\\n");
    printf(" )  ( ')\n");
    printf("(  /  )\n");
    printf(" \\(__)|\n");
    return 0;
}

// 1차시도 : 실패(너무 많이 escape를 사용)
// 2차시도 : 실패(결과값을 착각하고 \하나를 더 넣음)
// 3차시도 : 성공