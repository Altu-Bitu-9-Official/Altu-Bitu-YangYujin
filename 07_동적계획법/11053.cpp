// 가장 긴 증가하는 부분 수열 https://www.acmicpc.net/problem/11053

#include <iostream>
#include <vector>
#include <algorithm>

//완료

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}