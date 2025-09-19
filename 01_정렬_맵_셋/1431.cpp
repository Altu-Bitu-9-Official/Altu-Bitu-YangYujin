#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//완료

using namespace std;

int sumOfNum(string s){
    int len = s.length();
    int sum=0;

    for(int i=0; i<len; i++){
        if(s[i]>='0'&&s[i]<='9'){
            sum+=s[i]-48;
        }
    }
    return sum;
}

bool compare(string a, string b){
    int aSum = sumOfNum(a);
    int bSum = sumOfNum(b);

    if(a.length()!=b.length()){
        if(a.length()<b.length()){
            return true;
        }
        return false;
    }
    else if(aSum!=bSum){
        if(aSum<bSum){
            return true;
        }
        return false;
    }
    else{
        if(a<b){
            return true;
        }
        return false;
    }
}

int main(){
    int n;
    vector<string> v;
    
    cin>>n;

    while(n--){
        string str;
        cin>>str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);
    
    for(auto i : v){
        cout<<i<<endl;
    }


    return 0;
}


/* 
1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
2. 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
3. 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
*/
