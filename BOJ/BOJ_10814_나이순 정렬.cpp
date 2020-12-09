// BOJ_10814_나이순 정렬
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(const pair<int, string> &a, const pair<int, string> &b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, age;
	string name;
	vector<pair<int, string>> info;

	cin >> n;

	for (int i = 0; i < n; i++) {	
		cin >> age >> name;
		info.push_back(make_pair(age, name));
	}

	stable_sort(info.begin(), info.end(), compare);

	for (int i = 0; i < n; i++)
		cout << info[i].first << ' ' << info[i].second << '\n';

	return 0;
}