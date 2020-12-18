// BOJ_2747_피보나치 수
#include <iostream>
using namespace std;

int result[46];
int temp;

int Fibonacci(int num) {
	if (result[num] != -1)
		return result[num];
	temp = Fibonacci(num - 1) + Fibonacci(num - 2);
	result[num] = temp;
	return result[num];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		if (i == 0)
			result[i] = 0;
		else if (i == 1)
			result[i] = 1;
		else
			result[i] = -1;
	}
	cout << Fibonacci(n);

	return 0;
}