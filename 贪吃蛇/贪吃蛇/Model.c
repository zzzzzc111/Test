#include"Model.h"
#include<stdlib.h>

void SnakeInit(Snake *snake)
{
	snake->direction = RIGHT;
	snake->direction = NULL;
	for (int i = 0; i < 3; i++)
	{
		Node *node = (Node*)malloc(sizeof(Node));
		node->pos.x = 3 + i;
		node->pos.y = 3;
		node->next = snake->direction;
		snake->direction = node;
	}
}

void GameInit(Game *game,Snake *snake)
{
	SnakeInit(&snake);
	game->weight = 30;
	game->high = 30;
	game->speed = 300;
	game->score = 0;
}


void GameStart(Game *game, Snake *snake)
{
	while () {
		swich(snake->direction)
		{
			case RIGHT:
				GotoRight();
			case LEFT:
				GotoLeft();
			case UP:
				GotoUp();
			case DOWN:
				GotoDown();
		}
		
	}
}