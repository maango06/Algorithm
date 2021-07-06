#include <iostream>
using namespace std;

int N, K, BEST = 0;
unsigned int MASK = -1, SELECT = 0;
unsigned int TABLE[50] = { 0, };

void DFS(int _num) {
	for (; _num < 26; ++_num) {
		if (SELECT & 1 << _num)
			break;
	}
	if (K == 0 || _num == 26) {
		int now = 0;
		for (int i = 0; i < N; ++i) {
			if (!(TABLE[i] & MASK)) {
				++now;
			}
		}
		BEST = BEST > now ? BEST : now;
		return;
	}
	--K;
	MASK &= ~(1 << _num);
	DFS(_num + 1);
	MASK |= 1 << _num;
	++K;
	DFS(_num + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		char inp[16];
		cin >> inp;
		int j = 0;
		while (inp[j]) {
			TABLE[i] |= 1 << inp[j] - 'a';
			++j;
		}
		SELECT |= TABLE[i];
	}

	if (K < 5) {
		cout << '0';
	}
	else {
		unsigned int temp = 532741;
		SELECT &= ~temp;
		MASK &= ~temp;
		K -= 5;
		DFS(0);
		cout << BEST;
	}
	return 0;
}
