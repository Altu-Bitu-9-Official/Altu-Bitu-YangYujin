// 집합(구현) https://www.acmicpc.net/problem/11723

#include <iostream>
#include <map>
#include <string>

//완료

using namespace std;

int add(int bits, int x){
    bits |= (1<<x);
    return bits;

}

int remove(int bits, int x){
    bits &= ~(1<<x);
    return bits;
}

void check(int bits, int x){
    if(bits&(1<<x)){
        cout<<1<<"\n";
    }
    else{
        cout<<0<<"\n";
    }
}

int toggle(int bits, int x){
    bits^=(1<<x);
    return bits;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 


    int m;
    string str;
    int x;

    int bits=0;

    cin>>m;

    while(m--){
        cin>>str;
        
        if(str== "add"){
            cin>>x;
            bits=add(bits,x);
            }
        else if(str== "remove"){
            cin>>x;
            bits=remove(bits,x);
            }
        else if(str== "check"){
            cin>>x;
            check(bits,x);
            }
        else if(str== "toggle"){
            cin>>x;
            bits=toggle(bits,x);
            }
        else if(str== "all"){
            bits=(1<<21)-1;
            bits &= ~(1 << 0);
            }
        else if(str== "empty"){
            bits=0;
            }
        


    }
     

    return 0;
}