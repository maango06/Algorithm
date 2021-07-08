#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> left_que;
priority_queue <int, vector<int>, greater<int>> right_que;

int min(int _a, int _b) { return _a < _b ? _a : _b; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, temp;
	cin >> N;
	cin >> temp;
	cout << temp << "\n";
	right_que.push(temp);

	for (int i = 1; i < N; ++i) {
		cin >> temp;

		if (left_que.size() == right_que.size()) {
			if (temp >= right_que.top()) {
				right_que.push(temp);
			}
			else {
				left_que.push(temp);
				right_que.push(left_que.top());
				left_que.pop();
			}
			cout << right_que.top() << "\n";
		}
		else {
			if (temp >= right_que.top()) {
				right_que.push(temp);
				left_que.push(right_que.top());
				right_que.pop();
			}
			else {
				left_que.push(temp);
			}
			cout << min(left_que.top(), right_que.top()) << "\n";
		}
		
	}

	return 0;
}
