#include <iostream>
#include <string>
using namespace std;

int table[1000][1000];
string A, B;

int max(int _a, int _b) {
	return _a > _b ? _a : _b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;
	
	if (A[0] == B[0])
		table[0][0] = 1;
	else
		table[0][0] = 0;

	for (int i = 1; i < A.size(); ++i)
		table[0][i] = A[i] == B[0] ? 1 : table[0][i-1];
	for (int i = 1; i < B.size(); ++i)
		table[i][0] = A[0] == B[i] ? 1 : table[i-1][0];

	for (int i = 1; i < B.size(); ++i) {
		for (int j = 1; j < A.size(); ++j) {
			if (A[j] == B[i])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = max(table[i][j - 1], table[i - 1][j]);
		}
	}

	int max = 0;
	for (int i = 0; i < B.size(); ++i) {
		for (int j = 0; j < A.size(); ++j) {
			if (table[i][j] > max)
				max = table[i][j];
		}
	}
	cout << max;

	return 0;
}
