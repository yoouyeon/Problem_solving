// BOJ_2580_스도쿠
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int map[9][9];
vector<pair<int, int>> zero;
bool found_answer = false;

bool check_row(int y, int x, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[y][i] == num)
			return false;
	}
	return true;
}

bool check_col(int y, int x, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == num)
			return false;
	}
	return true;
}

bool check_square(int y, int x, int num) {
	int optionY = y % 3, optionX = x % 3;
	if (optionY == 0) {
		if (optionX == 0) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (map[y + i][x + j] == num)
						return false;
				}
			}
			return true;
		}
		else if (optionX == 1) {
			for (int i = 0; i < 3; i++) {
				for (int j = -1; j < 2; j++) {
					if (map[y + i][x + j] == num)
						return false;
				}
			}
			return true;
		}
		else if (optionX == 2) {
			for (int i = 0; i < 3; i++) {
				for (int j = -2; j < 1; j++) {
					if (map[y + i][x + j] == num)
						return false;
				}
			}
			return true;
		}
	}
	else if (optionY == 1) {
		if (optionX == 0) {
			for (int i = -1; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
					if (map[y + i][x + j] == num)
						return false;
				}
			}
			return true;
		}
		else if (optionX == 1) {
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					if (map[y + i][x + j] == num)
						return false;
				}
			}
			return true;
		}
		else if(optionX == 2) {
			for (int i = -1; i < 2; i++) {
				for (int j = -2; j < 1; j++) {
					if (map[y + i][x + j] == num)
						return false;
				}
			}
			return true;
		}
	}
	else if (optionY == 2) {
		if (optionX == 0) {
			for (int i = -2; i < 1; i++) {
				for (int j = 0; j < 3; j++)
					if (map[y + i][x + j] == num)
						return false;
			}
			return true;
		}
		else if (optionX == 1) {
			for (int i = -2; i < 1; i++) {
				for (int j = -1; j < 2; j++)
					if (map[y + i][x + j] == num)
						return false;
			}
			return true;
		}
		else if (optionX == 2) {
			for (int i = -2; i < 1; i++) {
				for (int j = -2; j < 1; j++)
					if (map[y + i][x + j] == num)
						return false;
			}
			return true;
		}
	}
}

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << map[i][j] << ' ';
		cout << '\n';
	}
}

void check(int n) {
	if (n == zero.size()) {
		print();
		exit(0);
	}
	int y = zero[n].first, x = zero[n].second;
	for (int i = 1; i <= 9; i++) {
		if (check_col(y, x, i) != true || check_row(y, x, i) != true || check_square(y, x, i) != true)
			continue;
		map[y][x] = i;
		check(n + 1);
		map[y][x] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				zero.push_back(make_pair(i, j));
		}
	}

	check(0);
	
	return 0;
}