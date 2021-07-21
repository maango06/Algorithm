#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, IN[1000000], idx = 0, TABLE[1000000], STACK[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	STACK[0] = -1000000001;
	for (int i = 0; i < N; ++i) {
		cin >> IN[i];
		if (IN[i] <= STACK[idx]) {
			int* bound = lower_bound(STACK, STACK + idx, IN[i]);
			*bound = IN[i];
			TABLE[i] = bound - STACK;
		}
		else {
			STACK[++idx] = IN[i];
			TABLE[i] = idx;
		}
	}

	cout << idx << "\n";

	int looper = N - 1;
	vector <int> stk;
	while (idx != 0) {
		if (TABLE[looper] == idx) {
			stk.push_back(IN[looper]);
			idx--;
		}
		looper--;
	}

	while (!stk.empty()) {
		cout << stk.back() << " ";
		stk.pop_back();
	}

	return 0;
}
