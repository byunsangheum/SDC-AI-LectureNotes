#include "winner.h"
#include "dice.h"
#include "skill.h"


void winner(const int index1, const int index2)
{
	if (player_each_dice_number[index1] > player_each_dice_number[index2])
	{
		printf("player ��ȣ %d = %s ���� �¸��ϼ̽��ϴ�!", index1, player[index1]);
	}
	else if (player_each_dice_number[index1] < player_each_dice_number[index2])
	{
		printf("player ��ȣ %d = %s ���� �¸��ϼ̽��ϴ�!", index2, player[index2]);
	}
	else
	{
		printf("���º��Դϴ�.");
	}
}