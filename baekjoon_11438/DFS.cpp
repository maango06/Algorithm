#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, DEP[100001], PARENT[100001][18];
bool visit[100001];
vector<vector<int>> LIST;

int LCA(int _a, int _b) {
	if (DEP[_a] < DEP[_b]) swap(_a, _b);

	int looper = 0;
	while (DEP[_a] != DEP[_b]) {
		++looper;
		if ((DEP[_a] - (1 << looper)) < DEP[_b]) {
			_a = PARENT[_a][looper - 1];
			looper = 0;
		}
	}
	while (_a != _b) {
		looper = 1;
		while (PARENT[_a][looper] != PARENT[_b][looper])
			++looper;
		_a = PARENT[_a][looper - 1];
		_b = PARENT[_b][looper - 1];
	}
	return _a;
}

void DFS(int _now) {
	int loop = LIST[_now].size();
	for (int i = 0; i < loop; ++i) {
		int next = LIST[_now][i];
		if (visit[next])
			continue;
		visit[next] = true;
		DEP[next] = DEP[_now] + 1;
		PARENT[next][0] = _now;
		for (int i = 1; i < 18; ++i) {
			PARENT[next][i] = PARENT[PARENT[next][i - 1]][i - 1];
		}
		DFS(LIST[_now][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	LIST.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		LIST[a].push_back(b);
		LIST[b].push_back(a);
	}

	DEP[1] = 1;
	visit[1] = true;
	DFS(1);

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}

	return 0;
}
