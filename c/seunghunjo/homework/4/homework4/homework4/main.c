#include <stdio.h>

#include "player.h"
#include "dice.h"
#include "skill.h"
#include "random_generator.h"
#include "win.h"

// player���ϱ�(? ��)2��
// player �̸��� ���� malloc���� player[]�� ������ ���� �̸��� ������
// ���� : player, malloc
// 
// �����Ҵ����� �ϱ�(malloc)
//
//
// �ֻ����� ������.���� ¦����� �ѹ��� ������.�÷��̾��� ���ڸ� ���
// ���� ���ڰ� 2, 3, 4�� ������ ��ų ���� �ϰ� ���ڸ� ��ģ��.�ƴ϶�� ���ڸ� �׳� ��ģ��.
// ���� : game - dice(�����°�, ��ų��������, ���� ��ġ��), game - skill
//
//
// �Ŀ� �÷��̾���� ���ڸ� ���Ͽ� ū���� �̱��.
// ���� : win
//
// �������
// main(����)->player�̸� �ް� �����Ҵ�(malloc���� ��������� �̸� �ֱ�)->player�Ѹ� �ֻ����� ������->dice_roll
// ->player[�̸�]�� ���ڸ� ������ ��Ŵ->¦��Ȯ�� �ϰ� ¦���� �ٽõ�����->���ڰ� 2, 3, 4�� �´��� Ȯ��
// -> 2, 3, 4�� ��ų�����(->�ƴ϶�� ���� ���ڿ� �����ֱ�)->��ų�� ����()���� ���->�Ŀ� ���� ���ڰ� ��ū�� �Ǻ�
// ->print�ϸ� ��

int main(void)
{
	set_player_info("ö��");
	set_player_info("����");

	print_player_info(0);
	print_player_info(1);

	random_config();
	roll_dice(0);
	roll_dice(1);

	printf("\n");

	print_dice_number(0);
	print_dice_number(1);

	printf("\n");

	check_winner(0, 1);

	return 0;
}