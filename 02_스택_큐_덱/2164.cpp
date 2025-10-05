#include <iostream>
#include <queue>
#include <string>

//완료

using namespace std;

void shuffle(int n, queue<int> q){
    while(n>1){
        q.pop(); //제일 위에 있는 카드를 버린다
        q.push(q.front()); //제일 위에 있는 카드를 밑으로 옮긴다
        q.pop();


        n--;
    }

    cout<<q.front()<<endl;
}

int main(){
    int n;
    queue<int> q;

    cin>>n;

    for(int i=1; i<n+1; i++){
        q.push(i);
    }

    shuffle(n,q);

    return 0;
}