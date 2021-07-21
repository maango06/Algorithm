#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int what_type(string str, bool _is) {
	
	int left = 0, right = str.size() - 1, type = 0;

	while (left <= right) {
		if (str[left] == str[right]) {
			left++, right--;
		}
		else {
			if (_is) {
				type = 1;
				break;
			}
			if (0 == what_type(str.substr(left + 1, right - left), 1))
				type = 1;
			else if (0 == what_type(str.substr(left, right - left), 1))
				type = 1;
			else
				type = 2;
			break;
		}
	}

	return type;

}

int main() {
	string buffer;
	int num;
	cin >> num;

	for(int i = 0; i < num; ++i) {
		cin >> buffer;
		cout << what_type(buffer, 0) << endl;
	}

	return 0;
}
