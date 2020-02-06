#include <iostream>
#include <conio.h>

using namespace std;
int headx;
int heady;
class Snake(){
public:
void changeDirection(char key) {

		switch (key) {
		case 'w':
			if (direction != 2) direction = 0;
			break;
		case 'd':
			if (direction != 3) direction = 1;
			break;
		case 's':
			if (direction != 4) direction = 2;
			break;
		case 'a':
			if (direction != 5) direction = 3;
			break;
		case 'k':
			running = false;
			break;
		}
	}


	void move(int dx, int dy) {


		int newx = headx + dx;
		int newy = heady + dy;


		if (map[newx + newy * width] == -2) {

			food++;


			generateFood();
		}


		else if (map[newx + newy * width] != 0) {
			running = false;
		}


		headx = newx;
		heady = newy;
		map[headx + heady * width] = food + 1;

	}


	void clearScreen() {

		system("cls");
	}
  void update() {

		switch (direction) {
		case 0: move(-1, 0);
			break;
		case 1: move(0, 1);
			break;
		case 2: move(1, 0);
			break;
		case 3: move(0, -1);
			break;
		}


		for (int i = 0; i < width * height; i++) {
			if (map[i] > 0) map[i]--;
		}
	}
  };
  
  
  int main(){
  Snake snake;
  snake.changeDirection();
  snake.void move();
  snake.void clearScreen();
  snake.update();
  return 0;
  }
