#include <iostream>
#include <deque>
#include <sstream>
using namespace std;
int T;

int main()
{
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string commands, list, buffer;
		int num;
		cin >> commands >> num >> list;
		list = list.substr(1, list.length() - 2);
		istringstream ss(list);
		deque<int> que;

		while (getline(ss, buffer, ','))
			que.push_back(stoi(buffer));

		bool turn = false, error = false;
		for (int j = 0; j < commands.length(); ++j) {
			if (commands[j] == 'R') {
				turn = !turn;
			}
			else {
				if (que.empty()) {
					error = true;
					cout << "error" << endl;
					break;
				}
				if (turn) {
					que.pop_back();
				}
				else {
					que.pop_front();
				}
			}
		}
		if (error)
			continue;
		cout << '[';
		while (true) {
			if (que.empty())
				break;
			if (turn) {
				cout << que.back();
				que.pop_back();
			}
			else {
				cout << que.front();
				que.pop_front();
			}
			if (!que.empty())
				cout << ',';
		}
		cout << ']' << endl;
	}
	
	return 0;
}
