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
	
	int left = 0, right = 0, now = TABLE[0], ans = 100001;

	while (right != N) {
		if (now < S) {
			++right;
			now += TABLE[right];
		}
		else {
			ans = min(ans, right - left + 1);
			now -= TABLE[left];
			++left;
		}
	}

	cout << (ans == 100001 ? 0 : ans);

	return 0;
}
