#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

vector<pair<string, long long>> commands;
stack<long long> num_stack;

long long labs(long long num){
    if (num < 0)
        return (num * (-1));
    return (num);
}

int input_op(){
    string operation;
    long long x;
    cin >> operation;
    while (operation != "END"){
        x = 0;
        if (operation == "QUIT")
            return (0);
        if (operation == "NUM")
            cin >> x;
        commands.push_back(make_pair(operation, x));
        cin >> operation;
    }
    return (1);
}

bool num(long long x){
    num_stack.push(x);
    return (true);
}

bool pop(){
    if (num_stack.empty())
        return (false);
    num_stack.pop();
    return (true);
}

bool inv(){
    long long temp;
    if (num_stack.empty())
        return (false);
    temp = num_stack.top();
    num_stack.pop();
    temp *= -1;
    num_stack.push(temp);
    return (true);
}

bool dup(){
    long long temp;
    if (num_stack.empty())
        return (false);
    temp = num_stack.top();
    num_stack.push(temp);
    return (true);
}

bool swp(){
    long long temp1, temp2;
    if (num_stack.size() < 2)
        return (false);
    temp1 = num_stack.top();
    num_stack.pop();
    temp2 = num_stack.top();
    num_stack.pop();
    num_stack.push(temp1);
    num_stack.push(temp2);
    return (true);
}

bool add(){
    long long temp1, temp2, result;
    if (num_stack.size() < 2)
        return (false);
    temp1 = num_stack.top();
    num_stack.pop();
    temp2 = num_stack.top();
    num_stack.pop();
    result = temp1 + temp2;
    if (labs(result) > 1000000000)
        return(false);
    num_stack.push(result);
    return (true);
}

bool sub(){
    long long temp1, temp2, result;
    if (num_stack.size() < 2)
        return (false);
    temp1 = num_stack.top();
    num_stack.pop();
    temp2 = num_stack.top();
    num_stack.pop();
    result = temp2 - temp1;
    if (labs(result) > 1000000000)
        return(false);
    num_stack.push(result);
    return (true);
}

bool mul(){
    long long temp1, temp2, result;
    if (num_stack.size() < 2)
        return (false);
    temp1 = num_stack.top();
    num_stack.pop();
    temp2 = num_stack.top();
    num_stack.pop();
    result = temp2 * temp1;
    if (labs(result) > 1000000000)
        return(false);
    num_stack.push(result);
    return (true);
}

bool div(){
    long long temp1, temp2, result;
    if (num_stack.size() < 2)
        return (false);
    temp1 = num_stack.top();
    num_stack.pop();
    if (temp1 == 0)
        return (false);
    temp2 = num_stack.top();
    num_stack.pop();
    result = temp2 / temp1;
    if (labs(result) > 1000000000)
        return (false);
    num_stack.push(result);
    return (true);
}

bool mod(){
    long long temp1, temp2, result;
    if (num_stack.size() < 2)
        return (false);
    temp1 = num_stack.top();
    num_stack.pop();
    if (temp1 == 0)
        return (false);
    temp2 = num_stack.top();
    num_stack.pop();
    result = temp2 % temp1;
    if (labs(result) > 1000000000)
        return (false);
    num_stack.push(result);
    return (true);
}

void error(){
    while (!num_stack.empty())
        num_stack.pop();
    cout << "ERROR" << '\n';
}

void print_result(){
    if (num_stack.size() != 1)
        error();
    else{
        cout << num_stack.top() << '\n';
        num_stack.pop();
    }
}

void prog(){
    for(int i = 0; i < commands.size(); i++){
        if (commands[i].first == "NUM"){
            if (num(commands[i].second) == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "POP"){
            if (pop() == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "INV"){
            if (inv() == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "DUP"){
            if (dup() == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "SWP"){
            if (swp() == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "ADD"){
            if (add() == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "SUB"){
            if (sub() == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "MUL"){
            if (mul() == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "DIV"){
            if (div() == false){
                error();
                return;
            }
        }
        else if (commands[i].first == "MOD"){
            if (mod() == false){
                error();
                return;
            }
        }
    }
    print_result();
}

int main(){
    int temp, n;
    long long templ;
    while (1){
        temp = input_op();
        if (temp == 0)
            break;;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> templ;
            num_stack.push(templ);
            prog();
        }
        commands.clear();
        cout << '\n';
    }
    return (0);
}