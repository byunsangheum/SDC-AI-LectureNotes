#include <stdio.h>

#include "dice.h"
#include "player.h"
#include "random_gen.h"

int player_each_dice_number[MAX_PLAYER_NUMBER];
int player_index_count;

const int min = 1;
const int max = 6;


void roll_dice(const int index)
{
	player_each_dice_number[index] = generate_random(min, max);
}

void print_dice_number(const int index)
{
	// printf�� ���ϰ��� ����
	// ���ڸ� �� ����Ʈ ��� �ߴ����� ������
	// ��������� �Լ��� ���ϰ��� ���� ������ ? ax ��������
	printf("%d �� �÷��̾��� �ֻ��� ������ %d\n", index, player_each_dice_number[index]);
}
