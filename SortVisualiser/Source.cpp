#include <iostream>
#include <Windows.h>
#include <random>

std::string name = "";  //name of sorting for show

void bubbleSort(int[]);
void sortVisualiser(int[]);
void arrRandFill(int[]);

int main() {
	
	int algoNum;
	int mass[10] = {};
	

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

	for (int i = 0; i < 10; i++) {
		int val = uniform_dist(el);
		arr[i] = val;
	}
}




void bubbleSort(int arr[]) {
	int temp;
	for (int i = 0; i < 9; i++) {
		for (int n = 0; n < 9; n++) {
			std::cout << name << std::endl;
			sortVisualiser(arr);
			Sleep(100);
			system("CLS");
			if (arr[n] < arr[n + 1]) {
				temp = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = temp;
			}
		}
	}
}

void sortVisualiser(int arr[]) {

	char arrVis[10][10] = {};

	for (int i = 0; i < 10; i++) {
		for (int c = 0; c < 10; c++) {
			arrVis[i][c] = ' ';
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int c = 9; c > abs(arr[i] - 9); c--) {
			arrVis[c][i] = 'O';
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int c = 0; c < 10; c++) {
			std::cout << arrVis[i][c] << "  ";
		}
		std::cout << std::endl;
	}

	std::cout << "____________________________" << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << "  ";
	}

}