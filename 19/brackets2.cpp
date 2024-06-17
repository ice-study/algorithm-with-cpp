#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

bool check(char* str) {
    // 여는 괄호 문자들을  순ㅓ대로 담는 스택
    stack<char> stack;

    // 문자 하나씩 검사
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            // 여는 괄호라면 무조건 스택에 넣는다.
            stack.push(str[i]);
        } else {
            // 스택이 비어있는 경우 실패
            if (stack.size() == 0) return false;

            // 스택의 TOP에 있는 여는 괄호의 종류와 현재 검사중인 닫는 괄호의 종류가 같은지 검사
            char poped = stack.top();
            stack.pop();
            // 같다면 다음 문자 검사
            if (str[i] == ')' && poped == '(') continue;
            if (str[i] == '}' && poped == '{') continue;
            if (str[i] == ']' && poped == '[') continue;

            // 다르다면 실패
            return false;
        }
    }

    // 스택에 문자가 남아있는 경우
    // = 여는 괄호가 남아있는 경우 실패
    if (stack.size() > 0) return false;

    return true;
}

int main(int argc, char const* argv[]) {
    int n;
    cin >> n;
    while (n--) {
        char str[10001];
        cin >> str;
        if (check(str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
