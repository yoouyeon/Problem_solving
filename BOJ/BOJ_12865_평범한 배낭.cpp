// BOJ_12865_평범한 배낭
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, k;
int weight[101], value[101], cache[1000001][101];
int pack(int capacity, int itemNo) {
	if (itemNo == n)
		return 0;
	if (cache[capacity][itemNo] != 0)
		return cache[capacity][itemNo];
	// 이 물건을 배낭에 넣지 않을 경우
	cache[capacity][itemNo] = pack(capacity, itemNo + 1);
	// 이 물건을 배낭에 넣을 수 있는 경우 -> 넣지 않을 경우와 비교해서 큰 값을 구한다. 
	if(capacity >= weight[itemNo])
		cache[capacity][itemNo] = max(cache[capacity][itemNo], pack(capacity - weight[itemNo], itemNo + 1) + value[itemNo]);
	return cache[capacity][itemNo];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> weight[i] >> value[i];
	ans = pack(k, 0);
	cout << ans;
	return 0;
}