#include <stdio.h>
#include "dice_game.h"
#include "random_generator.h"

#define MAX		6
#define MIN		1

int dice_number = 0;



int roll_dice(void)    //이게 주사위 굴린?
{
	dice_number = generate_random(MIN, MAX);
}









void print_dice_number(void) 
{
	printf("굴려서 나온 주사위 숫자 = %d\n", dice_number);
}