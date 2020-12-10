// BOJ_15650_N과 M(2)
#include <iostream>
using namespace std;
int n, m;
int arr[8];
bool visited[8] = { false, };
void Combination(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < n; i++) {
			if (visited[i] == true)
				cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = idx; i < n; i++) {
		if (visited[i] == true)
			continue;
		visited[i] = true;
		Combination(i, cnt+1);
		visited[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	// 중복없이 m개를 고른 수열 구하기 (오름차순) -> 조합
	Combination(0, 0);
	return 0;
}