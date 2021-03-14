#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define f(i, a, b) for(int i = int(a); i < int(b); ++i)

vector <char> ad, words;

char moving(vector <char> _words, int _num) {
	return _words[_num % _words.size()];
}

int checking(vector <char> _ad, vector <char> _words) {
	int i = _words.size();
	while (i != _ad.size()) {
		cout << _ad[i] << " : " << moving(_words, i) << endl;
		if (_ad[i] != moving(_words, i))
			break;
		i++;
	}
	cout << "return i : " << i << endl;
	return i;
}

int main() {

	int size;
	cin >> size;
	cout << "size : " << size << endl;
	ad.reserve(size);
	cin.get();
	f(i, 0, size) {
		ad.push_back(cin.get());
		cout << "testing " << i << endl;
	}

	f(i, 0, ad.size()) {
		cout << ad[i] << endl;
	}

	cout << "size : " << size << " : " << ad.size() << endl;

	words.push_back(ad[0]);
	f(i, 1, size) {
		cout << "현재 i : " << i << endl;
		cout << "checking 시작" << endl;
		cout << "words : ";
		f(j, 0, words.size())
			cout << words[j];
		cout << endl;

		int temp = checking(ad, words);
		if (temp == ad.size())
			break;
		else {
			f(j, i, temp + 1) {
				words.push_back(ad[j]);
			}
		}
		cout << "-------------------" << endl;
	}

	cout << words.size();

	return 0;
}
