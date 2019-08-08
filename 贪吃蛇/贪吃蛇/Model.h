#pragma once

typedef enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
}Direction;

typedef struct Position {
	int x;
	int y;
}Position;


typedef struct Node {
	Position pos;
	Node *next;
}Node;

typedef struct Snake {
	Node *head;
	Direction direction;
}Snake;

typedef struct Game {
	int speed;
	int score;
	int weight;
	int high;
}Game;

void SnakeInit(Snake *snake);   //�߳�ʼ��
void GameInit(Game *game,Snake *snake);  //��Ϸ��ʼ��
void GameStart(Game *game,Snake *snake);
