#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

const long INIT_NUMBER = 1983;
long getNextA(long a) {
    return (a * 214013 + 2531011) % long(pow(2, 32));
}

long getMatchCount(long k, long n) {
    long result = 0;
    long sum = INIT_NUMBER;
    long curA = INIT_NUMBER;
    long curPoint = 0;
    queue<long> q;
    q.push(INIT_NUMBER);
    do {
        if (sum <= k) {
            // 누적합이 k보다 작거나 같을 경우, 다음 원소를 추가합니다.
            // 만약 누적합이 k와 같을 경우에는 결과값을 1 증가시킵니다.
            if (sum == k)
                result += 1;
            long nextA = getNextA(curA);
            long nextNum = nextA % 10000 + 1;
            q.push(nextNum);
            sum += nextNum;
            curPoint += 1;
            curA = nextA;
        } else if (sum > k) {
            // 누적합이 k보다 클 경우, 맨 앞의 원소를 제거합니다.
            sum -= q.front();
            q.pop();
        }

    } while (curPoint < n);

    return result;
}

int main() {
    long n;
    cin >> n;
    while (n--) {
        long k, n;
        cin >> k >> n;
        cout << getMatchCount(k, n) << endl;
    }

    return 0;
}