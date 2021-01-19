// Programmers_베스트앨범
include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first)
			return a.second > b.second;
		else
			return a.first < b.first;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	
	multimap<string, pair<int, int>> music_map; // first: 재생횟수, second: 고유번호
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> music_queue; // first: 재생횟수, second: 고유번호
	map<int, pair<int, int>, greater<int>> result_map;    // key: 재생횟수 총합, pair first: top1의 고유번호, second: top2의 고유번호
	pair<int, int> tempM; // first: 재생횟수, second: 고유번호
	pair<int, int> tempR; // first: top1의 고유번호, second: top2의 고유번호

	// step 1. 장르별로 음악 정보 정리하기
	for (int i = 0; i < genres.size(); i++) {
		tempM.first = plays[i];
		tempM.second = i;
		music_map.insert(pair<string, pair<int, int>>(genres[i], tempM));
	}

	// step 2. 장르별로 top2 골라내기
	multimap<string, pair<int, int>> ::iterator iter;
	iter = music_map.begin();
	int cnt, total;
	while (iter != music_map.end()) {
		cnt = music_map.count(iter->first);  // 해당 장르에 있는 음악의 개수
		for (int i = 0; i < cnt; i++) {
			music_queue.push(pair<int, int>(iter->second.first, iter->second.second));
			iter++;
		}
		// top2 골라내기
		total = 0;
		total += music_queue.top().first;
		tempR.first = music_queue.top().second; //top1의 고유번호
		music_queue.pop();
		// 장르에 속한 곡이 하나라면 하나만 선택한다. 
		if (music_queue.empty()) {
			tempR.second = -1;
			result_map.insert(pair<int, pair<int, int>>(total, tempR));
			continue;
		}
		total += music_queue.top().first;
		tempR.second = music_queue.top().second;    //top2의 고유번호
		music_queue.pop();
		while (!music_queue.empty()){
            total += music_queue.top().first;
            music_queue.pop();   
        }
		result_map.insert(pair<int, pair<int, int>>(total, tempR));
	}

	// step 3. answer 배열 완성하기
	map<int, pair<int, int>> ::iterator iter2;
	for (iter2 = result_map.begin(); iter2 != result_map.end(); iter2++) {
		answer.push_back(iter2->second.first);
        if(iter2->second.second == -1)
            continue;
		answer.push_back(iter2->second.second);
	}
	return answer;
}