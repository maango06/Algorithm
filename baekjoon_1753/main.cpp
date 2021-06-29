#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V, E, START;

vector<pair<int, int>> LIST[20001];
int DIS[20001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> START;
	int start, end, weight;
	for (int i = 0; i < E; ++i) {
		cin >> start >> end >> weight;
		LIST[start].push_back({ end, weight });
	}
	for (int i = 1; i <= V; ++i) {
		DIS[i] = 2147483647;
	}

	DIS[START] = 0;
	priority_queue<pair<int, int>> que;
	que.push({ 0, START });
	while (!que.empty()) {
		int now_cost = -que.top().first;
		int now = que.top().second;
		que.pop();
		for (int i = 0; i < LIST[now].size(); ++i) {
			int target = LIST[now][i].first;
			int cost = LIST[now][i].second;
			if (DIS[target] > now_cost + cost) {
				DIS[target] = now_cost + cost;
				que.push({ -DIS[target], target });
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (DIS[i] == 2147483647) {
			cout << "INF" << endl;
		}
		else
			cout << DIS[i] << endl;
	}
	
	return 0;
}
