#include <iostream>
#include <conio.h>
using namespace std;
int food = 3;
class Food{
public:
void generateFood() {
		int x = 0;
		int y = 0;
		do {

			x = rand() % (width - 2) + 1;
			y = rand() % (height - 2) + 1;


		} while (map[x + y * width] != 0);


		map[x + y * width] = -2;
	}
  };
