#include <iostream>
#include <set>
#include <string>

//완료

using namespace std;

int main(){
    string s;
    set<string> sset;

    cin>>s;

    for(int i=0; i<=s.length(); i++){
        for(int j=0; j<=s.length()-i; j++){
            string tmp = s.substr(i,j);
                if(tmp!=""){
                    sset.insert(tmp);
                }
            
        }
    }
    
    cout<<sset.size();    

    return 0;
}