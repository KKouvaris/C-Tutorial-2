// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; using std::endl;

const int minColumn = 0;
const int maxColumn = 80;
const int screenSize = maxColumn - minColumn + 1;

void draw(const double, const char, char []);
void move(double&, double&);
void clear_screen(char []);
void print_screen(char []);

int main() {

	int timeStep = 0;
	const int stopTime = 60;

	char* screen = new char[screenSize];
	
	const int particleNumber = 4;	
	const char particleSymbol[particleNumber]={'*','+','x','o'};
	double particlePosition[particleNumber]={1,2,3,4};
	double particleSpeed[particleNumber]={1,2,3,4};

	while (timeStep < stopTime) {
		clear_screen(screen);
		for (int i=0; i<particleNumber; i++){
			draw(particlePosition[i],particleSymbol[i],screen);
			move(particlePosition[i],particleSpeed[i]);
		}
		print_screen(screen);
		timeStep++;
	}
	delete [] screen;
}

void draw(const double position, const char symbol, char *screen){
	screen[static_cast<int>(position)]= symbol; 
}

void move(double& pos, double& speed){
  //move start
    pos += speed;
    if (pos >= maxColumn) {
      pos = maxColumn;
      speed = -speed;
    } else if (pos < minColumn) {
      pos = minColumn;
      speed = -speed;
    }
	//move stop
}

void clear_screen(char *screen){
	for (int i =0; i<screenSize; i++){
		i[screen] = ' ';
	}
}

void print_screen(char *screen){
	for (int i = 0; i<screenSize; i++){
		cout << *(screen + i);
	}
	cout << endl;
}