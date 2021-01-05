// BOJ_10844_쉬운 계단 수
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long dp[101][10];	//	dp[k][m]: k자리 수 중에서 끝자리가 m인 계단 수의 개수
	long long ans = 0;
	int n;

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)	// 끝자리가 0인 경우는 인접한 왼쪽의 숫자가 1인 경우 1개 뿐이다.
				dp[i][j] = dp[i - 1][1] % 1000000000;

			else if (j == 9)	// 끝자리가 9인 경우는 인접한 왼쪽의 숫자가 8인 경우 1개 뿐이다.
				dp[i][j] = dp[i - 1][8] % 1000000000;

			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	for (int i = 0; i <= 9; i++)
		ans += dp[n][i];

	cout << ans % 1000000000;

	return 0;
}