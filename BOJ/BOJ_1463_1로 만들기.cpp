// BOJ_1463_1로 만들기
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int Dp[1000001];

void Solve() {
	cin >> n;
	memset(Dp, 0, sizeof(Dp));
	for (int i = 2; i <= n; i++) {
		Dp[i] = Dp[i - 1] + 1;
		if (i % 3 == 0)
			Dp[i] = min(Dp[i / 3] + 1, Dp[i]);
		if (i % 2 == 0)
			Dp[i] = min(Dp[i / 2] + 1, Dp[i]);
	}
	cout << Dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}
