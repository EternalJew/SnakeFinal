#include <iostream>
#include <conio.h>

using namespace std;

char getMapValue(int value);
const int width = 20;
const int height = 40;
int map[width * height];

class Map{
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
  int main(){
  Map map;
  map.run();
  map.initMap();
  map.printMap();
  map.getMapValue();
  return 0;
  }
