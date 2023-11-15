#include "dice.h"
#include "random.h"

#define MIN		1
#define MAX		6

int roll_dice(void)
{
	return get_random_from_min_to_max(MIN, MAX);
}

/*roll_dice �Լ��� �����ϸ�, �ش� �Լ��� get_random_from_min_to_max�� ȣ���Ͽ�, �ּҰ�(MIN)�� �ִ밪(MAX)�� ���̿�
�ش�Ǵ� ������ ������ �����մϴ�.
*/