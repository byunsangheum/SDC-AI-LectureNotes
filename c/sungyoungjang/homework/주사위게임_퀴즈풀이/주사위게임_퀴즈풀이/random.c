#include "random.h"

#include <time.h>
#include <stdlib.h>

void random_seed_config(void)
{
	srand(time(NULL));
}
/*random_seed_config �Լ��� ������ ���� ������ ���� �Լ�.*/

int get_random_from_min_to_max(const int min, const max)
{
	return rand() % (max - min + 1) + min;
}
/*get_random_from_min_to_max �Լ��� min�� max ���� ������ ���� ���� ����.*/