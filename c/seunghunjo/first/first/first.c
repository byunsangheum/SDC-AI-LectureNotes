#include <stdio.h>
// �Ʒ��� second_function() �� ����ϱ� ���� ��� ������ include �Ͽ����ϴ�.
#include "second.h"
#include "third.h"
#include "fourth.h"

int main(void)
{
	int return_value;
	// printf�� �� �״�� �Ұ�ȣ ���ο� �ִ� ���ڿ��� ����մϴ�.
	// ���ڿ��� "" (�ֵ���ǥ) ���̿� ������ ����ִ� �������� �����˴ϴ�.
	// '\n' �� ���๮�� (����) �� ������ �����մϴ�.
	printf("Hello First C Programming!\n");

	// second_function �� ��° �۾��̴ٶ�� �ǹ̷� �ۼ��Ͽ���
	// �ܺο� �ִ� �Լ��� ����� ���� *.c ���ϰ� *.h ������ ���� �ۼ��ؾ� �մϴ�.
	// ����� ���� �Լ��� �̸��� �ۼ��ϰ� �Ұ�ȣ�� ���� �ݾƾ� �մϴ�.
	second_function();
	return_value = third_function();
	printf("return_value = %d\n", return_value);
	// Quiz, fourth_function���� ���� 7�� ����ϵ��� ����� ���ô�.
	fourth_function();

	return 0;
}

//#ifdef 0
//void �ӵ�����()
//{
//	// �ӵ� ��� �������� �Ѵ� ����
//	float voltage = acquire_voltage_from_adc_sensor();
//	// ���� ���� ���� pid���� ���� (���� �� ����, ����, �̺�)
//	pid_t* pid_struct = adjust_pid_control_structure();
//	// �������� �ӵ� ����
//	control_velocity(pid_struct);
//}
//#endif
