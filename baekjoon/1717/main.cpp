#include <iostream>
using namespace std;

int N, M, TABLE[1000001];

int find_top(int _num) {
	if (TABLE[_num] == _num)
		return _num;
	return TABLE[_num] = find_top(TABLE[_num]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i <= N; ++i)
		TABLE[i] = i;
	
	for (int i = 0; i < M; ++i) {
		int temp, a, b;
		cin >> temp >> a >> b;
		if (temp) {
			if (find_top(a) == find_top(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else
			TABLE[find_top(b)] = find_top(a);
		
	}


	return 0;
}
