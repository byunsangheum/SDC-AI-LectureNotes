#include <stdio.h>

void main() {
    int num1;
    printf("정수를 입력하세요");
    scanf("%d", &num1);

    int num2;
    printf("정수를 입력하세요");
    scanf("%d", &num2);

    printf("%d\n", num1 << num2);
}