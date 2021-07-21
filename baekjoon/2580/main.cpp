#include <iostream>
using namespace std;

int TABLE[81];
bool Y[9][9], X[9][9], square[9][9];

bool sudoku(int _n) {
	for (int i = _n; i < 81; ++i) {
		if (TABLE[i] == 0) {
			int x = i % 9, y = i / 9;
			for (int j = 0; j < 9; ++j) {
				if (X[x][j] && Y[y][j] && square[(y / 3) * 3 + x / 3][j]) {
					TABLE[i] = j + 1;
					X[x][j] = Y[y][j] = square[(y / 3) * 3 + x / 3][j] = false;
					if (sudoku(i + 1))
						return true;
					X[x][j] = Y[y][j] = square[(y / 3) * 3 + x / 3][j] = true;
				}
			}
			TABLE[i] = 0;
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			Y[i][j] = X[i][j] = square[i][j] = true;
	

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int inp;
			cin >> inp;
			TABLE[9 * i + j] = inp;
			if (inp != 0) {
				--inp;
				Y[i][inp] = false;
				X[j][inp] = false;
				square[(i / 3) * 3 + j / 3][inp] = false;
			}
		}
	}



	sudoku(0);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << TABLE[i * 9 + j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
