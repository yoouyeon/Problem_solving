// BOJ_14889_스타트와 링크
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int statMap[21][21];
int n, ans = 987654321;
bool visited[21];
vector<int> sTeam, lTeam;

void getMinGap() {
	sTeam.clear();
	lTeam.clear();
	for (int i = 1; i <= n; i++) {
		if (visited[i] == true)
			sTeam.push_back(i);
		else
			lTeam.push_back(i);
	}
	int sStat = 0, lStat = 0;
	for (int i = 0; i < sTeam.size(); i++) {
		for (int j = i + 1; j < sTeam.size(); j++) {
			if (i == j)
				continue;
			int sx = sTeam[i], sy = sTeam[j], lx = lTeam[i], ly = lTeam[j];
			sStat += statMap[sx][sy] + statMap[sy][sx];
			lStat += statMap[lx][ly] + statMap[ly][lx];
		}
	}
	ans = min(ans, abs(sStat - lStat));
}

void dfs(int idx, int cnt) {
	if (cnt == n / 2) {
		getMinGap();
		return;
	}
	for (int i = idx; i <= n; i++) {
		if (visited[i] == true)
			continue;
		else {
			visited[i] = true;
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> statMap[i][j];
	}
	
	dfs(1, 0);
	cout << ans;
	return 0;
}