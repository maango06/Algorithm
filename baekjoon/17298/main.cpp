#include <iostream>
#include <stack>
using namespace std;

stack <int> STACK;
int N;
int NUM[1000000], TABLE[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> NUM[i];

	for (int i = N - 1; i >= 0; --i) {
		int now = NUM[i];
		while (!STACK.empty()) {
			if (STACK.top() <= now)
				STACK.pop();
			else
				break;
		}
		if (STACK.empty())
			TABLE[i] = -1;
		else
			TABLE[i] = STACK.top();
		STACK.push(now);
	}
	
	for (int i = 0; i < N; ++i) {
		cout << TABLE[i] << " ";
	}

	return 0;
}
