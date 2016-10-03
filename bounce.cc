// N.B. This program contains a bug, on purpose.

#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;

char screen[maxColumn];

void draw(const double, const char);
void move(double&, double&);
void clear_screen();
void print_screen();

int main() {

	const char particleSymbol = 'x';
	double particlePosition = minColumn;
	double particleSpeed = 6.3;

    const char particleSymbol2 = '+';
	double particlePosition2 = minColumn;
	double particleSpeed2 = 8.3;

	
  int timeStep = 0;
  const int stopTime = 60;

  while (timeStep < stopTime) {
	clear_screen();
	draw(particlePosition,particleSymbol);
	move(particlePosition,particleSpeed);
	draw(particlePosition2,particleSymbol2);
	move(particlePosition2,particleSpeed2);	
	print_screen();
    timeStep++;
  }
}

void draw(const double position, const char symbol){
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

void clear_screen(){
	for (int i =0; i<maxColumn; i++){
		screen[i] = ' ';
	}
}

void print_screen(){
	for (int i = 0; i<maxColumn; i++){
		std::cout << screen[i];
	}
	std::cout << std::endl;
}