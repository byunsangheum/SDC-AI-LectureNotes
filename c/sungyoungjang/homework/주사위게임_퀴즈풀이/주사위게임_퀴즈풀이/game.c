#include "game.h" // game ����� �����Ͽ� game.c�� �Լ��� ȣ��.
#include "player.h" // player ����� �����Ͽ� player.c�� �Լ��� ȣ��.
#include "dice.h" // dice ����� �����Ͽ� dice.c�� �Լ��� ȣ��.

#include <stdio.h> // stdio.h ����� �Լ��� �ҷ��� ��뼱��.
#include <stdbool.h> // stdbool.h  ���� ������ ��Ÿ���� ������ ���� �� ���ִ�.

#define FIRST_DICE_INDEX	0 // ù��° �ֻ����� �ε����� ��Ÿ���� ����� '0'���� ����.
#define SECOND_DICE_INDEX	1 // �ι�° �ֻ����� �ε����� ��Ÿ���� ����� '1'���� ����.
#define BUFF_NUMBER		3 // ��ų�� �ߵ����� �� �����ϴ� ���� ���� �����, 3���� ����.
#define DEBUFF_NUMBER	4 // ��ų�� ������� �� �����ϴ� ���� ���� �����, 4�� ����.
#define PLAYER_DEATH -4444 // PLAYER_DEATH: �÷��̾ �׾��� �� �Ҵ�Ǵ� ���� ���� �����, -4444�� ����.

// ���� ���� define ��ũ�δ� ���α׷��� �������� ���̰� ���߿� ��� ���� �����ؾ� �� ��� �ڵ���
// ���� �κп��� �� ���� ������ �� �ֵ��� ������ �� �ִ�.

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];
/* player_each_dice_number ��� �迭�� �����ϰ�, �� �迭�� �ֻ����� ���� �÷��̾��� ������ ������ �� ���δ�
MAX_PLAYER_NUMBER = �÷��̾��� �ִ� ���� ��Ÿ���� ����̴�.
MAX_ROLL_NUMBER = �÷��̾�� �ֻ����� ���� Ƚ���� ����ϴ� ����̴�.*/


void play_game(void)
{	
	int loop; // loop ���� ����.
	int current_player_index; // current_player_index ���� ����.
	char* nickname[MAX_PLAYER_NUMBER] = // 2���� �÷��̾ �Է�.
	{
		"������",
		"�縶��"
	};

	printf("����� �г��� ����\n");

	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		init_player_nickname(nickname[loop]);
	}
	print_player_list();
	/* loop ������ 0���� �����Ͽ� MAX_PLAYER_NUMBER���� ���� �� ���� ���� 
	init_player_nickname �Լ��� ȣ���Ͽ� �Ű������� ����� �� �÷��̾��� �̸��� 
	player_nickname �迭�� �ʱ�ȭ.
	print_player_list �Լ��� ȣ���Ͽ� player_nickname �迭�� �����
	��� �÷��̾��� �г��� ����� ���. */
	random_seed_config(); // ���������� �߻��ϴ� random_seed_config() ȣ��.

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
	/*roll_dice() �Լ��� ���� �� �ֻ����� ������ �� ������� first_dice_number�� �����Ѵ�.
	�� �� ������� ¦�� ����Ȯ���� �Ǹ� apply_dice_skill�Լ��� ȣ�� �Ͽ� ��ų �� ������� �����Ѵ�.*/
	check_winner();
	// check_winner �Լ��� ȣ���Ͽ� ���� ����� ���� ���ڸ� Ȯ���Ѵ�.
}

void apply_dice_skill(int current_player_index)
{
	int second_dice_number = 
		player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += roll_dice();
	int target_player_index;

	printf("���� �� ��° �ֻ��� ���� =%d\n", second_dice_number);

	switch (second_dice_number)
	{
	
	case 2:
		buff_to_current_player(current_player_index);
		printf("�� ��° �ֻ��� ������ %d\n",
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;

	case 3:
		
		target_player_index = find_target_player(current_player_index);
		printf("��ų ���� �� ���� %d\n",
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX] -= BUFF_NUMBER);
		debuff_to_target_player(target_player_index);
		break;

	case 4:

		player_death(current_player_index);
		printf("���� : %d\n", player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;
	
	default:
		printf("��ų ����� �Ұ��մϴ�.\n");
		break;

	}
}
/*apply_dice_skill �Լ��� ù��° �ֻ��� ���� ¦�� �� ��� �۵��ϴ� �Լ��̸�,
�ι�° �ֻ����� ������ ��, roll_dice �Լ��� ���ϰ� �� ������� second_dice_number�� �����Ѵ�.
switch���� ����Ͽ�
�ֻ��� ���� 2�� ���� ��� buff_to_current_player �Լ��� ȣ���Ͽ� �ش�Ǵ� ������ ���ϰ�
�ֻ��� ���� 3�� ���� ��� find_target_player �Լ��� ȣ���Ͽ� ��� �÷��̾��� ������ ����ϴ�.
�ֻ��� ���� 4�� ���� ��� player_death �Լ��� ȣ���Ͽ� �ش� �÷��̾�� ���ӿ����� �˴ϴ�.
�� ���� �ֻ��� ���� ��� �Ұ�.*/

void buff_to_current_player(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += BUFF_NUMBER;
}
/*buff_to_current_player �Լ��� �ش� �÷��̾��� ������ BUFF_NUMBER�� �����ŭ ������ ���Ѵ�. */

int find_target_player(int current_player_index)
{
	// ���� ? ���ΰ�� : ������ ���
	// ���� ���·� �ۼ�.
	return current_player_index ? 0 : 1;
}

void debuff_to_target_player(int target_player_index)
{
	player_each_dice_number[target_player_index][SECOND_DICE_INDEX] -= DEBUFF_NUMBER;
}
/*debuff_to_target_player �Լ��� ��� �÷��̾��� ������ DEBUFF_NUMBER�� �����ŭ ������ ����. */

void player_death(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] = PLAYER_DEATH;
}
/*player_death �Լ��� �ش� �÷��̾��� ������ PLAYER_DEATH�� �����ŭ ����(���ӿ��� ��Ų��.)*/

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
/*each_player_dice_sum �迭�� �����ϰ�, �� �÷��̾��� �ֻ��� ���� �����ϰ�, loop�� ���� �� ��° �ֻ����� ���� 
PLAYER_DEATH ����� ��ġ�ϴ� �÷��̾ �ִ��� Ȯ�� ��, �̿� ���� death_count�� ���� ���� �й� �޽����� ����ϰ� �Ѵ�.
���� �Ѵ� death ī��Ʈ�� �ִٸ� ���ºη� ������ �׿ܿ��� ������ ���� ���и� �����Ѵ�.*/


	// 4�� ���� ����ó��

	for (i = 0; i < MAX_PLAYER_NUMBER; i++)
	{
		if (player_each_dice_number[i][SECOND_DICE_INDEX] == PLAYER_DEATH)
		{
			death_count++;
			printf("�÷��̾� %d ���� �й��ϼ̽��ϴ�.\n", i);
		}
	}

	if (death_count == 2) { does_everyone_lose = true; }

	if (does_everyone_lose) { return; }

	if (each_player_dice_sum[0] > each_player_dice_sum[1])
	{
		printf("0�� �÷��̾� �¸�!");
	}
	else if (each_player_dice_sum[0] < each_player_dice_sum[1])
	{
		printf("1�� �÷��̾� �¸�!");
	}
	else
	{
		printf("���º�!");
	}
}