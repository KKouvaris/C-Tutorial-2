// N.B. This program contains a bug, on purpose.

#include <iostream>

int minColumn = 0;
int maxColumn = 80;
char particleSymbol = 'x';
double particlePosition = minColumn;
double particleSpeed = 6.3;

void draw(double position, char symbol){
	//draw start  
    for (int i = 0; i < position; i++) {
      std::cout << " ";
    }
    std::cout << symbol << std::endl;
	//draw end	
}

void move(){
  //move start
    particlePosition += particleSpeed;
    if (particlePosition >= maxColumn) {
      particlePosition = maxColumn;
      particleSpeed = -particleSpeed;
    } else if (particlePosition < minColumn) {
      particlePosition = minColumn;
      particleSpeed = -particleSpeed;
    }
	//move stop
}

int main() {
	
  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {

	draw(particlePosition,particleSymbol);
	move();

    timeStep++;
  }
}
