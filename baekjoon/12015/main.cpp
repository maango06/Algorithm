#include <iostream>
#include <algorithm>
using namespace std;

int N, TABLE[1000001], idx = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	TABLE[0] = 0;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;

		if (temp <= TABLE[idx])
			*lower_bound(TABLE, TABLE + idx, temp) = temp;
		else
			TABLE[++idx] = temp;
	}

	cout << idx;

	return 0;
}
