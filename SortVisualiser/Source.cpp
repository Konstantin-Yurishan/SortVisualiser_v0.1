#include <iostream>
#include <Windows.h>
#include <random>

std::string name = "";  //name of sorting for show
int counter = 0;
int step = 0;

void bubbleSort(int[]);
void sortVisualiser(int[]);
void arrRandFill(int[]);

int main() {
	
	int algoNum;
	int mass[20] = {};
	
	std::cout << "Enter the alrorithm: " << std::endl;
	std::cin >> algoNum;

	arrRandFill(mass);

	switch (algoNum) {
	case 1:
		name = "Bubble Sort";
		bubbleSort(mass);

		for (auto t : mass) {
			std::cout << t << " ";
		}
		std::cout << std::endl;
		std::cout << "Number of steps:" << counter;
		break;
	default:
		break;
	}

	return 0;
}



void arrRandFill(int arr[]) {

	std::random_device r;
	std::default_random_engine el(r());
	std::uniform_int_distribution<int> uniform_dist(0, 9);

	for (int i = 0; i < 20; i++) {
		int val = uniform_dist(el);
		arr[i] = val;
	}
}

void bubbleSort(int arr[]) {
	int temp;
	bool hook = false;
	for (int i = 0; i < 19; i++) {
		hook = false;
		for (int n = 0; n < 19; n++) {
			std::cout << name << std::endl;
			std::cout << "Step #: " << counter << std::endl;
			sortVisualiser(arr);
			if (arr[n] < arr[n + 1]) {
				temp = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = temp;
				hook = true;
			}
			counter++;
			step++;
		}
		step = 0;
		if (!hook) {
			break;
		}
	}
}

void sortVisualiser(int arr[]) {

	char arrVis[20][20] = {};

	for (int i = 0; i < 20; i++) {
		for (int c = 0; c < 20; c++) {
			arrVis[i][c] = ' ';
		}
	}

	for (int i = 0; i < 20; i++) {
		for (int c = 9; c > abs(arr[i] - 9); c--) {
			arrVis[c][i] = '#';
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int c = 0; c < 20; c++) {
			std::cout << arrVis[i][c] << "  ";
		}
		std::cout << std::endl;
	}

	for (int g = 0; g <= step * 2; g += 2) {
		if (g == step * 2) {
			std::cout << "^  ^";
		}
		std::cout << "   ";
	}
	std::cout << std::endl;

	std::cout << "____________________________________________________________" << std::endl;

	for (int i = 0; i < 20; i++) {
		std::cout << arr[i] << "  ";
	}
	
	Beep(arr[step + 1] * 100, arr[step + 1] * 20);
	Sleep(50);
	system("CLS");
}