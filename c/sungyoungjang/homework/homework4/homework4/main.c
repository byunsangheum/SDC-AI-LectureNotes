#include <stdio.h>
#include <stdlib.h>
#include "skill.h"

#define MAX_PLAYER_NUMBER	2

int main(void) 
{
	set_player_info("����");
	set_player_info("����");

	print_player_info(0);
	print_player_info(1);

	random_config();

	// Ȧ�� ���̽��� ���� ���� ���� ����
	
	
	// roll_dice()�� �������� �����Ƿ� ���� ���� Ư���� �ʱⰪ�� 0�� ��µǰ� ����
	// roll_dice()�� ���� player1_dice ���� �����ؾ� �ϴµ� print_dice���� �۾��� �ϰ� ���� ???
	// �׸��� C��� ǥ�ص� ���������� ���� (���� ������ �ֻ����� �ؾ���)
	/*
	int player1 = print_dice_number(0);
	int player2 = print_dice_number(1);
	*/

	/* ���� ������ ���� ������ ������ �ذ� ������ ������ ������ ������*/
	// printf�� ���ϰ��� player_dice�� �ݿ��Ǵ� �������� ��Ÿ���� ����
	// �׷��Ƿ� �ùٸ� ������ ����� �ʿ���
	//int player1_dice = print_dice_number(0);
	//int player2_dice = print_dice_number(1);
	int player1_first_dice = roll_dice(0);
	int player2_first_dice = roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);
	
	// ���⼭ �ᱹ �迭���� 2�� ��� �ֱ� ������
	// -4�� �ص� -2�� �Ǿ���
	// int* player_scores[MAX_PLAYER_NUMBER] = {2};

	// int number1 = 3, number2 = 7;
	// int *arr[2] = { &number1, &number2 };
	// ���� �迭�� ����Ǵ� ������ �޸𸮰� �ƴ϶� ������
	// �׷��Ƿ� �迭�� �Ʒ��� ���� �ۼ��ϸ� �ȵ�
	// int* player_scores[MAX_PLAYER_NUMBER] = { 0 };
	int player_scores[MAX_PLAYER_NUMBER] = { 0 };

	skill(0, player1_first_dice, player_scores);
	skill(1, player2_first_dice, player_scores);

	// 0�� 1�� �뵵�� ������ ?
	printf("after skill\n");
	printf("�÷��̾� %d�� ���� ����: %d\n", 0, player_scores[0]);
	printf("�÷��̾� %d�� ���� ����: %d\n", 1, player_scores[1]);

	if (player_scores[0] > player_scores[1])
	{
		printf("�÷��̾� 0�� �¸��߽��ϴ�!\n");
	}
	else if (player_scores[0] < player_scores[1])
	{
		printf("�÷��̾� 1�� �¸��߽��ϴ�!\n");
	}
	else
	{
		printf("���º��Դϴ�!\n");
	}
	
	return 0;
}

