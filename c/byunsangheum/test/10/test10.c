#include <stdio.h>
 
int main()
{
    int num1 =10;
    int num2 =12;
    int and_data, or_data, xor_data , not_data, num1_not_data, num2_not_data;

    and_data = (num1==10 & num2==12);
    or_data = (num1<12 | num2>12);
    xor_data = (num1 ^ num2);
    num1_not_data = (~num1);
    num2_not_data = (~num2);

    printf("and_data : %d \n",and_data);
    printf("or_data : %d \n",or_data);
    printf("xor_data : %d \n",xor_data);
    printf("num1의 not_data : %d \n",num1_not_data);
    printf("num2의 not_data : %d \n",num2_not_data);

    return 0;
}