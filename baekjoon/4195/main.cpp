#include <iostream>
#include <map>
using namespace std;

typedef struct {
	string name;
	int num;
} parent;

map<string, parent> TABLE;
int T, F;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		cin >> F;
		TABLE.clear();
		for (int i = 0; i < F; ++i) {
			string left, right;
			cin >> left >> right;

			if (TABLE.find(left) == TABLE.end()) {
				TABLE.insert({ left, { left, 1 } });
			}
			if (TABLE.find(right) == TABLE.end()) {
				TABLE.insert({ right, { right, 1 } });
			}

			while (left != TABLE[left].name)
				left = TABLE[left].name;

			while (right != TABLE[right].name) {
				string name = TABLE[right].name;
				TABLE[right].name = left;
				right = name;
			}
			if (left != right) {
				TABLE[right].name = left;
				TABLE[left].num += TABLE[right].num;
			}
			cout << TABLE[left].num << "\n";
		}
	}

	return 0;
}
