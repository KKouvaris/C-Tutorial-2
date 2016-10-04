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

struct Particle{
	char symbol;
	double position;
	double speed;
};

int main() {

	int timeStep = 0;
	const int stopTime = 60;

	char* screen = new char[screenSize];
	
	const int particleNumber = 4;	
	Particle particles[particleNumber] = {	{'*',1,1},
											{'+',2,2},
											{'x',3,3},	
											{'o',4,4}};
											
	while (timeStep < stopTime) {
		clear_screen(screen);
		for (int i=0; i<particleNumber; i++){
			draw(particles[i].position,particles[i].symbol,screen);
			move(particles[i].position,particles[i].speed);
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