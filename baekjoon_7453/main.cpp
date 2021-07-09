#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long NUM = 0;
int TABLE[4][4000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> TABLE[0][i] >> TABLE[1][i] >> TABLE[2][i] >> TABLE[3][i];
	}

	vector <int> v;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			v.push_back(TABLE[2][i] + TABLE[3][j]);

	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int now = TABLE[0][i] + TABLE[1][j];
			int low = lower_bound(v.begin(), v.end(), -now) - v.begin();
			int upp = upper_bound(v.begin(), v.end(), -now) - v.begin();
			if (v[low] == -now) {
				NUM += upp - low;
			}
		}
	}

	cout << NUM;

	return 0;
}
