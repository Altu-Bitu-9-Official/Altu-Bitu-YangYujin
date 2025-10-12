// 날짜 계산 https://www.acmicpc.net/problem/1476

#include <iostream>
#include <cmath>
#include <algorithm>

//완료

using namespace std;


int main(){

    int e,s,m;
    int year=1;

    cin>>e>>s>>m;

    int e_cur = 1;
    int s_cur = 1;
    int m_cur = 1;

    while(true){
        if((e_cur==e)&&(s_cur==s)&&(m_cur==m)){
            cout<<year<<endl;
            break;
        }

        year++;

        e_cur++;
        s_cur++;
        m_cur++;

        if (e_cur > 15) {
            e_cur = 1;
        }
        if (s_cur > 28) {
            s_cur = 1;
        }
        if (m_cur > 19) {
            m_cur = 1;
        }
    }
    return 0;
}