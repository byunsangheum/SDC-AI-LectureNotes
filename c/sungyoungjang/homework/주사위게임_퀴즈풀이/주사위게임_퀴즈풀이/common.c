#include "common.h" // common ����� �����Ͽ� common.c�� �Լ��� ȣ��.

bool check_even(int first_dice_number) // bool�̶� �ڷ��� �������͸� ��������� �����ϰ�, int first_dice_number �� �Ű������� ������\
check_even���� �����Ѵ�.
{
	//C���� 0�� false�̸�, 0�� �ƴϸ� true�̴�
	return (first_dice_number % 2) ? false : true; //first_dice_number�� ¦���� ��� false�� ����ǰ�, �ƴҰ�� true�� ����ȴ�.
}