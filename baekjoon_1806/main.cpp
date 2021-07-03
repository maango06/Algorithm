#include <iostream>
using namespace std;

int N, S, TABLE[100000];

int min(int _a, int _b) {
	if (_a < _b)
		return _a;
	return _b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; ++i)
		cin >> TABLE[i];
	
	int fst = 0, end = 0, now = TABLE[0], ans = 100001;

	while (end != N) {
		if (now < S) {
			++end;
			now += TABLE[end];
		}
		else {
			ans = min(ans, end - fst + 1);
			now -= TABLE[fst];
			++fst;
		}
	}

	cout << (ans == 100001 ? 0 : ans);

	return 0;
}
