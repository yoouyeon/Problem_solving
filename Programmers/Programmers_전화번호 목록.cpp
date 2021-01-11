// Programmers_전화번호 목록
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true, findAnswer = true;
    int n;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++){
        for(n = 0; n < phone_book[i].length(); n++){
            if(phone_book[i][n] != phone_book[i + 1][n])
                break;
        }
        if(n == phone_book[i].length()){
            answer = false;
            return answer;
        }
    }
    return answer;
}