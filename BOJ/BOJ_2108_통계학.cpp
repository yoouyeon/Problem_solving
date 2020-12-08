#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

vector<int> input;

double average(int sum) {
	return round(sum / (double)input.size());
}

int median() {
	return input[input.size() / 2];
}

int mode() {
	int count[8001];
	int max = 0, ans = 0;
	bool isSecond = false; // 현재의 최빈값은 두번째로 작은 값임.
	memset(count, 0, sizeof(count));
	for (int i = 0; i < input.size(); i++)
		count[input[i] + 4000]++;
	for (int i = 0; i < 8001; i++) {
		if (count[i] > max) {
			ans = i - 4000;
			max = count[i];
			isSecond = false;
		}
		else if (max != 0 && count[i] == max && isSecond == false) {
			ans = i - 4000;
			isSecond = true;
		}
	}
	return ans;
}

int range() {
	return *(input.end() - 1) - *(input.begin());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sum += temp;
		input.push_back(temp);
	}
	sort(input.begin(), input.end());
	cout << average(sum) << '\n';
	cout << median() << '\n';
	cout << mode() << '\n';
	cout << range() << '\n';

	return 0;
}