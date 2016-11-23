#include<iostream>

void hunting(int hunterPosition, int rabbitPosition, int best, int treeLevel = 0);
int abs(int A);

int main() {
	int hunterPosition = 6;
	int rabbitPosition = 10;
	int best = abs(hunterPosition - rabbitPosition);

	hunting(hunterPosition, rabbitPosition, best);

	std::cout << "Best Value: " << best << std::endl;

	return 0;
}

void hunting(int hunterPosition, int rabbitPosition,int best, int treeLevel) {

	std::cout << "Hunter: " << hunterPosition << std::endl;
	std::cout << "Rabbit: " << rabbitPosition << std::endl;
	std::cout << "Tree  : " << treeLevel << std::endl;
	std::cout << "Best  : " << best << std::endl;
	std::cout << std::endl;

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