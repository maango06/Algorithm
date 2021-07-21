#include <iostream>
using namespace std;

int N, K, now_weight = 0, now_value = 0;
int table[100][100001];
pair<int, int> list[100];

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> list[i].first >> list[i].second;
	}
	
	for (int i = 0; i <= K; ++i) {
		if (i < list[0].first)
			table[0][i] = 0;
		else
			table[0][i] = list[0].second;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= K; ++j) {
			if (j < list[i].first) table[i][j] = table[i - 1][j];
			else
				table[i][j] = table[i - 1][j] > (table[i - 1][j - list[i].first] + list[i].second) ?
					table[i - 1][j] : table[i - 1][j - list[i].first] + list[i].second;
		}
	}

	
	cout << table[N - 1][K];

	
	return 0;
}
