// BOJ_9461_파도반 수열
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long pado[101];
	int t, n;
	pado[1] = 1;
	pado[2] = 1;
	pado[3] = 1;

	for (int i = 4; i <= 100; i++)
		pado[i] = pado[i - 2] + pado[i - 3];

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << pado[n] << '\n';
	}

	return 0;
}
