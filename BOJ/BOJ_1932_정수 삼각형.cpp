// BOJ_1932_정수 삼각형
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int triangle[500][500];
	int n, temp, ans = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				temp = triangle[i][j] + triangle[i - 1][j];
				triangle[i][j] = temp;
			}
			else if (j == i) {
				temp = triangle[j][j] + triangle[i - 1][j - 1];
				triangle[i][j] = temp;
			}
			else {
				temp = triangle[i][j] + max(triangle[i - 1][j], triangle[i - 1][j - 1]);
				triangle[i][j] = temp;
			}
		}
	}

	for (int j = 0; j < n; j++) {
		if (ans < triangle[n - 1][j])
			ans = triangle[n - 1][j];
	}

	cout << ans;

	return 0;
}
