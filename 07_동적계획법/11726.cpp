// 2xn 타일링

#include <iostream>
#include <vector>
#include <algorithm>

//완료

using namespace std;

int squares(int n){
    vector<int> dp(1001,0);
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=n; i++){
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }

    return dp[n];

}


int main() {
    int n;
    cin>>n;

    

    cout<<squares(n);
    
}