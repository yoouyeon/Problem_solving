// Programmers_더 맵게

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int low_scov_0 = 0, low_scov_1 = 0;
    int mixed_scov = 0;
    
    priority_queue<int, vector<int>, greater<int>> scov_queue;   // 오름차순 우선순위 큐
    
    for(int i = 0; i < scoville.size(); i++){
        scov_queue.push(scoville[i]);
    }
    
    do{
        // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
        if(scov_queue.size() == 1 && scov_queue.top() < K){
            answer = -1;
            return answer;
        }
        
        low_scov_0 = scov_queue.top();
        scov_queue.pop();
        low_scov_1 = scov_queue.top();
        scov_queue.pop();
        mixed_scov = low_scov_0 + (low_scov_1 * 2);
        scov_queue.push(mixed_scov);
        
        answer++;
        
    }while(scov_queue.top() < K);
    
    return answer;
}