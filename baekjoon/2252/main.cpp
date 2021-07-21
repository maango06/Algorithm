#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> TABLE;
bool visit[32001];

void DFS(int _num) {
	if (visit[_num])
		return;
	visit[_num] = true;
	int now_size = TABLE[_num].size();

	for (int i = 0; i < now_size; ++i) {
		DFS(TABLE[_num][i]);
	}
	cout << _num << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	TABLE.resize(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		TABLE[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i)
		DFS(i);

	return 0;
}
