#include "dice.h"
#include "random.h"

		//		-�ֻ��� ������ �ּ�,�ִ�

#define MIN			1
#define MAX			6


		//		-random.c�� ������ get_random_from_min_to_max => ����������
int roll_dice(void)
{
	return get_random_from_min_to_max(MIN, MAX);
}