#include <stdio.h>
#include "win.h"
#include "dice_game.h"
#include "player.h"

void check_winner(const int index1, const int index2)
{
	if (player_each_dice_number[index1] > player_each_dice_number[index2])
	{
		printf("player ��ȣ %d = %s ���� �¸��ϼ̽��ϴ�.\n", index1, player_name[index1]);
	}
	else if(player_each_dice_number[index1] < player_each_dice_number[index2])
	{
		printf("player ��ȣ %d = %s ���� �¸��ϼ̽��ϴ�.\n", index2, player_name[index2]);
	}
	else
	{
		printf("���º� �Դϴ�.\n");
	}
}