#include <iostream>
#include <queue>
using namespace std;

typedef struct _state {
	int x, y;
	bool bomb;
}state;

int N, M, table[1000][1000][2];
int dx[4] = { 1, -1, 0, 0 },
	dy[4] = { 0, 0, 1, -1 };

bool can_go(int _x, int _y) {
	return 0 <= _x && _x < N && 0 <= _y && _y < M;
}

int bfs() {

	table[0][0][1] = 1;
	queue<state> que;
	que.push({ 0, 0, true });

	while (!que.empty()) {
		state now = que.front();
		if (now.x == N - 1 && now.y == M - 1)
			return table[now.x][now.y][now.bomb];
		que.pop();
		int bomb = now.bomb;

		for (int i = 0; i < 4; ++i) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			
			if (can_go(nx, ny)) {
				if (table[nx][ny][bomb] == 0) {
					table[nx][ny][bomb] = table[now.x][now.y][bomb] + 1;
					que.push({ nx, ny, now.bomb });
				}
				else if (table[nx][ny][1] == -1 && now.bomb) {
					table[nx][ny][0] = table[now.x][now.y][1] + 1;
					que.push({ nx, ny, false });
				}
			}
		}

	}
	
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char ch;
			cin >> ch;
			int val;
			if (ch == '1')
				val = -1;
			else
				val = 0;
			table[i][j][0] = val;
			table[i][j][1] = val;
		}
	}
	cout << bfs();
	return 0;
}
