#include <iostream>
using namespace std;

int N, M, TABLE[50][50], VALUE[50][50];
bool MEMORY[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int DFS(int _x, int _y) {
	if (TABLE[_y][_x] == 0) {
		return 0;
	}
	if (VALUE[_y][_x] != 0)
		return VALUE[_y][_x];
	if (MEMORY[_y][_x])
		return -1;
	MEMORY[_y][_x] = true;
	int best = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = _x + dx[i] * TABLE[_y][_x];
		int ny = _y + dy[i] * TABLE[_y][_x];
		if (0 <= nx && nx < M && 0 <= ny && ny < N) {
			int value = DFS(nx, ny);
			if (value == -1)
				return -1;
			best = best > value ? best : value;

		}
	}

	MEMORY[_y][_x] = false;
	VALUE[_y][_x] = best + 1;
	return best + 1;
}

int main()
{
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char ch = getchar();
			TABLE[i][j] = ch == 'H' ? 0 : ch - '0';
		}
		getchar();
	}
	
	printf("%d", DFS(0, 0));

	return 0;
}
