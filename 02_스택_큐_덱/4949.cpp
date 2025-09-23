#include <iostream>
#include <string>
#include <stack>

//완료

using namespace std;

string balanced(string str){
    stack<char> st;

    for(int i=0; i<str.length(); i++){
        if(str[i]=='('||str[i]=='['){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            if(st.empty() || st.top() != '('){ 
            //스택이 비어있을 때 st.top() 등을 호출하면 오류가 남 -> st.top() 호출 전에 st.empty()로 스택이 비어있는지 확인
                return "no";
            }
            st.pop();
        }    
            
        else if(str[i]==']'){
            if(st.empty() || st.top() != '['){
                return "no";
            }
            st.pop();

        }
        
    }

    if (st.empty()) {
        return "yes";
    } else {
        return "no";
    }
}



int main(){
    string str;

    while(true){
        getline(cin,str); // cin>>str;은 공백을 만나면 입력을 끊으므로, 공백을 포함한 한 줄 전체를 읽으려면 getline(cin,str)을 사용해야 함
        if(str=="."){
            break;
        }

        cout<<balanced(str)<<endl;

    }
    return 0;
}