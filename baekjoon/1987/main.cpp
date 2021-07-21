#include <iostream>
using namespace std;

char table[20][20];

int R, C, MAX = 1, NOW = 1;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool can_go[26];

void DFS(int _x, int _y) {

	if (NOW > MAX)
		MAX = NOW;
	for (int i = 0; i < 4; ++i) {
		int nx = dx[i] + _x;
		int ny = dy[i] + _y;
		if (0 <= nx && nx < C && 0 <= ny && ny < R) {
			int alp = table[ny][nx] - 'A';
			if (can_go[alp]) {
				can_go[alp] = false;
				++NOW;
				DFS(nx, ny);
				--NOW;
				can_go[alp] = true;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char in[21];
	fill_n(can_go, 26, true);

	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cin >> in;
		for (int j = 0; j < C; ++j) {
			table[i][j] = in[j];
		}
	}
	can_go[table[0][0] - 'A'] = false;
	DFS(0, 0);
	cout << MAX;
	return 0;
}
