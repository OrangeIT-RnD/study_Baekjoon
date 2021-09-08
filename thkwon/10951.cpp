#include <stdio.h>

int main()
{
    while(1)
    {
        int a, b;
        if(scanf("%d", &a) == EOF) break;
        if(scanf("%d", &b) == EOF) break;

        printf("%d\n", a + b);
    }
}