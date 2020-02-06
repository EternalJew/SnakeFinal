#include <iostream>
#include <conio.h>

using namespace std;
char getMapValue(int value);
const int width = 20;
const int height = 40;
int map[width * height];
int headx;
int heady;
int direction;
int food = 3;
bool running;
class Snake {
public:
	void run()
	{

		initMap();
		running = true;
		while (running) {

			if (kbhit()) {

				changeDirection(getch());
			}

			update();


			clearScreen();


			printMap();


			_sleep(100);
		}


		cout << "\t\tGame over" << endl << "\t\tscore: " << food;


		cin.ignore();
	}


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


	void generateFood() {
		int x = 0;
		int y = 0;
		do {

			x = rand() % (width - 2) + 1;
			y = rand() % (height - 2) + 1;


		} while (map[x + y * width] != 0);


		map[x + y * width] = -2;
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


	void initMap()
	{

		headx = width / 2;
		heady = height / 2;
		map[headx + heady * width] = 1;


		for (int x = 0; x < width; ++x) {
			map[x] = -1;
			map[x + (height - 1) * width] = -1;
		}


		for (int y = 0; y < height; y++) {
			map[0 + y * width] = -1;
			map[(width - 1) + y * width] = -1;
		}


		generateFood();
	}


	void printMap()
	{
		for (int x = 0; x < width; ++x) {
			for (int y = 0; y < height; ++y) {

				cout << getMapValue(map[x + y * width]);
			}

			cout << endl;
		}

	}


	char getMapValue(int value)
	{

		if (value > 0) return 'o';

		switch (value) {

		case -1: return '#';

		case -2: return '$';
		}

		return ' ';
	}
};


int main() {
	Snake manager;
	manager.run();
	manager.changeDirection();
	manager.move();
	manager.clearScreen();
	manager.generateFood();
	manager.update();
	manager.initMap();
	manager.printMap();
	manager.getMapValue();

	return 0;

}
