// N.B. This program contains a bug, on purpose.

#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;

void draw(const double position, const char symbol){
	//draw start  
    for (int i = 0; i < position; i++) {
      std::cout << " ";
    }
    std::cout << symbol << std::endl;
	//draw end	
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

int main() {

	const char particleSymbol = 'x';
	double particlePosition = minColumn;
	double particleSpeed = 6.3;

	
  int timeStep = 0;
  const int stopTime = 60;

  while (timeStep < stopTime) {

	draw(particlePosition,particleSymbol);
	move(particlePosition,particleSpeed);

    timeStep++;
  }
}
