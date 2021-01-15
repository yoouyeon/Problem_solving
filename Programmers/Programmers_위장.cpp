// Programmers_위장
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    answer = 1;
    unordered_map<string, int> clothes_map;
    for(int i = 0; i < clothes.size(); i++){
        clothes_map[clothes[i][1]]++;
    }
    for(auto i = clothes_map.begin(); i != clothes_map.end(); i++){
        answer *= i -> second + 1;
    }
    answer -= 1;
    return answer;
}