#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct edge {
	int len, a, b;
};

bool operator < (edge& _a, edge& _b) {
	return _a.len < _b.len;
}

struct xyz {
	int x, y, z, idx;
};

bool comp_x(xyz _a, xyz _b) {
	return _a.x < _b.x;
}

bool comp_y(xyz _a, xyz _b) {
	return _a.y < _b.y;
}

bool comp_z(xyz _a, xyz _b) {
	return _a.z < _b.z;
}

int N, DIST = 0, parent[100000], set_size[100000];
xyz TABLE[100000];

int abs(int _a) {
	if (_a < 0)
		return -_a;
	return _a;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> TABLE[i].x >> TABLE[i].y >> TABLE[i].z;
		TABLE[i].idx = i;
		parent[i] = i;
		set_size[i] = 1;
	}

	vector<edge> list;
	list.reserve(N * 3);

	sort(TABLE, TABLE + N, comp_x);
	for (int i = 1; i < N; ++i)
		list.push_back({ abs(TABLE[i].x - TABLE[i-1].x), TABLE[i].idx, TABLE[i - 1].idx });
	
	sort(TABLE, TABLE + N, comp_y);
	for (int i = 1; i < N; ++i)
		list.push_back({ abs(TABLE[i].y - TABLE[i - 1].y), TABLE[i].idx, TABLE[i - 1].idx });

	sort(TABLE, TABLE + N, comp_z);
	for (int i = 1; i < N; ++i)
		list.push_back({ abs(TABLE[i].z - TABLE[i - 1].z), TABLE[i].idx, TABLE[i - 1].idx });
	
	sort(list.begin(), list.end());

	for (int i = 0; i < list.size(); ++i) {
		int left_p = list[i].a, right_p = list[i].b;

		while (left_p != parent[left_p])
			left_p = parent[left_p];

		while (right_p != parent[right_p])
			right_p = parent[right_p];

		if (left_p == right_p)
			continue;

		if (set_size[left_p] > set_size[right_p])
			swap(left_p, right_p);
		parent[left_p] = right_p;
		DIST += list[i].len;
		set_size[right_p] += set_size[left_p];
		if (set_size[right_p] == N)
			break;
	}

	cout << DIST;

	return 0;
}
