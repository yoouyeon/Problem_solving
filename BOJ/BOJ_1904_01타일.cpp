// BOJ_1904_01타일
#include<iostream>
using namespace std;

int n;
long long memo[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n;
	
	memo[1] = 1;
	memo[2] = 2;
	for (int i = 3; i <= n; i++) {
		memo[i] = (memo[i - 1] % 15746 + memo[i - 2] % 15746) % 15746;
	}
	cout << memo[n];
	
	return 0;
}