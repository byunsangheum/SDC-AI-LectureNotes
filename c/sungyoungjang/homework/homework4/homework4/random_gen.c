#include <time.h>
#include <stdlib.h>

#include "random_gen.h"

void random_config(void)
{
	// NULL�� stdio.h �� ���� �Ǿ� ����
	srand(time(NULL));
}


int generate_random()
{
	return rand() % 6 + 1;
}
