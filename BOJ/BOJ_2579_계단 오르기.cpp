// BOJ_2579_계단 오르기
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[300], value[300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}
	// Base Case 설정
	dp[1] = value[1];    //첫번째 계단을 밟는 경우
	dp[2] = value[1] + value[2];    //두번째 계단을 밟는 경우
	dp[3] = max(value[1], value[2]) + value[3];        //세번째 계단을 밟는 경우
	for (int i = 4; i <= n; i++)
		dp[i] = max(dp[i - 3] + value[i - 1], dp[i - 2]) + value[i];
	cout << dp[n];

	return 0;
}