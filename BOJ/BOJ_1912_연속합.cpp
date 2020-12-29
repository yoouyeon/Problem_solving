// BOJ_1912_연속합
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp1, temp2, ans = 0;
	int arr[100000];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	ans = arr[0];
	for (int i = 1; i < n; i++) {
		temp1 = arr[i - 1] + arr[i];
		temp2 = arr[i];
		arr[i] = max(temp1, temp2);
		ans = max(ans, arr[i]);
	}

	cout << ans;
	
	return 0;
}