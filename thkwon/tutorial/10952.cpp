#include <stdio.h>

int main() 
{
    while(1)
    {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        if(a == 0 && b == 0) break;

        printf("%d\n", a + b);
    }

    return 0;
}