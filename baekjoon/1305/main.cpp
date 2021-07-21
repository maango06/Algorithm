#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define f(i, a, b) for(int i = int(a); i < int(b); ++i)

int SIZE, WORD_SIZE = 1;
char AD[1000001], words[1000001];

char moving(int _num) {
	return words[_num % WORD_SIZE];
}

int checking() {
	int i = WORD_SIZE;
	while (i < SIZE) {
		if (AD[i] != moving(i))
			break;
		i++;
	}
	return i;
}

int main() {
	cin >> SIZE;
	cin >> AD;

	words[0] = AD[0];
	int i = 1;
	while(true) {
		int temp = checking();
		if (temp == SIZE)
			break;
		else {
			temp -= temp % WORD_SIZE;
			f(j, i, temp + 1) {
				words[j] = AD[j];
				WORD_SIZE++;
				i++;
			}
		}
	}

	cout << WORD_SIZE;

	return 0;
}
