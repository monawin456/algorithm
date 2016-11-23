#include<iostream>

void hunting(int hunterPosition, int rabbitPosition, int &best, int treeLevel = 0);
int abs(int A); //return absolute value

int main() {
	int hunterPosition = 6; //position of hunter
	int rabbitPosition = 10; //position of rabbit
	int best = abs(hunterPosition - rabbitPosition); //bound

	hunting(hunterPosition, rabbitPosition, best);

	std::cout << "Best Value: " << best << std::endl; //print result

	return 0;
}

void hunting(int hunterPosition, int rabbitPosition, int &best, int treeLevel) {
	if (treeLevel < best) {
		if (hunterPosition == rabbitPosition) {
			best = treeLevel;
		}
		else {
			hunting(hunterPosition-1, rabbitPosition, best, treeLevel + 1);
			hunting(hunterPosition+1, rabbitPosition, best, treeLevel + 1);
			hunting(hunterPosition*2, rabbitPosition, best, treeLevel + 1);
		}
	}
}

int abs(int A) {
	if (A < 0) {
		return -A;
	}
	else {
		return A;
	}
}
