#include <stdio.h>

void seperate(float n);

int main(void){
    float n ;

    printf("입력\n");
    scanf("%f", &n);

    seperate(n);
}       

void seperate(float n)
{
    printf("출력\n");
    printf("%d , %g\n",(int)n, n - (int)n);
}