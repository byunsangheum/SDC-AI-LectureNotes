#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




int dice() {
	return rand() % 6 + 1;
}
int main() {
	srand(time(NULL));

	char player1 = "����";
	char player2 = "����";

	int player1dice = dice();
	printf("������ �ֻ����� %d\n", player1dice);

	int player2dice = dice();
	printf("�c�� �ֻ����� %d\n", player2dice);

	if (player1dice < player2dice) {
		printf("�c�� �¸�\n");
	}
	if (player1dice > player2dice) {
		printf("������ �¸�\n");

	}
	if (player1dice == player2dice) {
		printf("���º��Դϴ�.");

	}
}
