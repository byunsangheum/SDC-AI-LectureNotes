#include <stdio.h>

#include "led/entity/led.h"
#include "account/entity/account_manager.h"

int main(void)
{
    int i;
    led *led_array;
    // ��� led�� �ɰ����� ���ϴ� ����
    const int led_array_count = 7;
    char name[32] = "hi";
    printf("First C Programming on Linux!\n");
    
    // led_array�� 7���� led������ ������ �ʱ�ȭ�� �������ִ� ��
    led_array = init_led_objeckt(led_array_count);

    // led_array�� �� 7���� statuse�� on(true)�� �������ִ� for��
    for(i = 0; i < led_array_count; i ++)
    {
        set_led_statuse(led_array,i,true);
    }

    // led_array�� print �Ѵ�.
    print_led_array_status(led_array);

    printf("account, account_manager test!\n");

    // account������ ������ 32�� ����
    init_account_manager_object();
    // account_manager.account_array[1].name�� char*������ name�� ���� +1��ŭ �����
    // name�� account_manager.account_array[1].name�� �����ؼ� �ִ´�.
    register_new_account(name);
    // account_manager.account_array[2].name�� char*������ "test"�� ���� +1��ŭ �����
    // "test"�� account_manager.account_array[2].name�� �����ؼ� �ִ´�.
    register_new_account("test");
    register_new_account("go");
    // �� 3���� account_manager.account_array�� �����Ǿ����Ƿ� 
    // 3���� account_array�� name�� print�Ѵ�.
    print_account_manager();

    return 0;
}