// N번째 큰 수 https://www.acmicpc.net/problem/2075
#include <iostream>
#include <queue>
#include <string>

//완료

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin>>n;

    priority_queue<int, vector<int>, greater<int>> pq;
    int num;

    for(int j=0; j<n*n; j++){
        
        cin>>num;
        pq.push(num);

        if(pq.size()>n){
            pq.pop();
        }
    
    }
    
    

    cout<<pq.top();

    return 0;
}