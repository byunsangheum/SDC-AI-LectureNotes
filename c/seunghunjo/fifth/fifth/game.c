#include "game.h"
#include "player.h"
#include "dice.h"
#include "random.h"
#include "common.h"

#include <stdio.h>
#include <stdbool.h>

#define FIRST_DICE_INDEX						0
#define SECOND_DICE_INDEX						1
#define BUFF_NUMBER								3
#define DEBUFF_NUMBER							4
#define PLAYER_DEATH							-4444

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];

void play_game(void)
{
	int loop;
	int current_player_index;
	char* nickname[MAX_PLAYER_NUMBER] = {
		"�Թ���������", "�ִ԰�����"
	};

	printf("����� �г��� ���� \n");
	// �Ʒ� ������ �־ ��������� �켱�� ������ �и��ϰڽ��ϴ�.
	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		init_player_nickname_info(nickname[loop]);
	}
	print_player_list();

	random_seed_config();
	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		int try_count = 0;
		int first_dice_number;

		first_dice_number = 
			player_each_dice_number[current_player_index][try_count] = roll_dice();

		printf("�ֻ��� ����: %d\n", first_dice_number);

		if (check_even(first_dice_number))
		{
			printf("�ֻ��� ��ų�� �ߵ��մϴ�!\n");
			apply_dice_skill(current_player_index);
		}

	}

	check_winner();
}

void apply_dice_skill(int current_player_index)
{
	int tartger_player_index;
	int second_dice_number =
		player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += roll_dice();

	printf("���� �� ��° �ֻ��� ���� = %d\n", second_dice_number);

	switch (second_dice_number)
	{
		case 2:
			buff_to_current_player(current_player_index);
			printf("�� ��° �ֻ��� ������ %d\n", player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
			break;

		case 3:
			tartger_player_index = find_targer_player(current_player_index);
			printf("��ų ���� �� ���� %d\n", player_each_dice_number[tartger_player_index][SECOND_DICE_INDEX]);
			debuff_to_target_player(tartger_player_index);
			printf("��ų ���� �� ���� %d\n", player_each_dice_number[tartger_player_index][SECOND_DICE_INDEX]);
			break;

		case 4:
			player_death(current_player_index);
			printf("�׾���: %d\n", player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
			break;

		default:
			printf("��ų ����� �Ұ��մϴ�\n");
			break;
	}
}

void buff_to_current_player(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += BUFF_NUMBER;
}

int find_targer_player(int current_player_index)
{
	// ���� ? ���ΰ�� : ������ ���
	// ���� ���·� �ۼ��մϴ�.
	return current_player_index ? 0 : 1;
}

void debuff_to_target_player(int target_player_index)
{
	player_each_dice_number[target_player_index][SECOND_DICE_INDEX] -= DEBUFF_NUMBER;
}

void player_death(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] = PLAYER_DEATH;
}

void check_winner(void)
{
	int each_player_dice_sum[MAX_PLAYER_NUMBER];
	int current_player_index;
	int i;

	int death_count = 0;

	bool does_everyone_lose = false;

	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		each_player_dice_sum[current_player_index] =
			player_each_dice_number[current_player_index][FIRST_DICE_INDEX] +
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX];
	}

	// 4�� ���� ����ó��
	for (i = 0; i < MAX_PLAYER_NUMBER; i++)
	{
		if (player_each_dice_number[i][SECOND_DICE_INDEX] == PLAYER_DEATH)
		{
			death_count++;
			printf("�÷��̾�%d ���� �й��Ͽ����ϴ�!\n", i);
		}
	}

	if (death_count == 2) { does_everyone_lose = true; }

	if (does_everyone_lose) { return; }

	if (each_player_dice_sum[0] > each_player_dice_sum[1])
	{
		printf("0�� �÷��̾� �¸�!");
	}
	else if((each_player_dice_sum[0] < each_player_dice_sum[1]))
	{
		printf("1�� �÷��̾� �¸�!");
	}
	else
	{
		printf("���º�");
	}
}