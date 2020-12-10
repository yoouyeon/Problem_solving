// BOJ_15651_N과 M(3)
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[8];
vector<int> v;
void Permutation_r(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
		Permutation_r(cnt + 1);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	// m개를 고른 수열 구하기 (같은 수를 여러번 골라도 된다) -> 중복순열
	Permutation_r(0);
	return 0;
}