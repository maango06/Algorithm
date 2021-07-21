#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K, BAG[300000];
long long ANS = 0;
pair <int, int> GEM[300000];
priority_queue <int> que;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> GEM[i].first >> GEM[i].second;
	
	for (int i = 0; i < K; ++i)
		cin >> BAG[i];

	sort(GEM, GEM + N);
	sort(BAG, BAG + K);

	int idx = 0;

	for (int i = 0; i < K; ++i) {
		while (idx < N && GEM[idx].first <= BAG[i]) {
			que.push(GEM[idx].second);
			++idx;
		}
		if (!que.empty()) {
			ANS += que.top();
			que.pop();
		}
	}

	cout << ANS;

	return 0;
}
