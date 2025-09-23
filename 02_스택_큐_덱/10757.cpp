#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//완료

using namespace std;

vector<int> stov(string str){
    vector<int> v;
    for(int i=0; i<str.length(); i++){
        v.push_back(str[i]-'0');
    }

    return v;
}

vector<int> calculate(vector<int> v1, vector<int> v2){
    int carry = 0;
    int sum = 0;
    vector<int> result;

    if(v1.size()<v2.size()){
        v1.swap(v2); //v1의 크기를 v2보다 항상 크게
    }

   while(!v2.empty()){
        sum = v1.back() + v2.back() + carry;
        carry = sum/10;
        result.push_back(sum%10);
        v1.pop_back();
        v2.pop_back();
    }

    while(!v1.empty()){
        sum = v1.back() + carry;
        carry = sum/10;
        result.push_back(sum%10);
        v1.pop_back();
    }

    if (carry > 0) {
        result.push_back(carry);
    }

    return result;

}


int main(){
    string str1;
    string str2;
    vector<int> v1;
    vector<int> v2;
    vector<int> result;

    cin>>str1;
    cin>>str2;

    v1 = stov(str1);
    v2 = stov(str2);
    
    result = calculate(v1, v2);
    reverse(result.begin(), result.end());

    for(int i:result) cout<<i;
    
    return 0;
}