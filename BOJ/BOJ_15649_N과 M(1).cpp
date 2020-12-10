//BOJ_15649_N과 M(1)
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[8];
bool visited[8] = { false, };
vector<int> v;

void Permutation(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (visited[i] == true)
			continue;
		visited[i] = true;
		v.push_back(arr[i]);
		Permutation(cnt+1);
		visited[i] = false;
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
	// 중복없이 m개를 고른 수열 구하기 -> 순열
	Permutation(0);

	return 0;
}