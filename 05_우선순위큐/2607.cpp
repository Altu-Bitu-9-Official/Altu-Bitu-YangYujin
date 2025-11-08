// 비슷한 단어(구현) https://www.acmicpc.net/problem/2607

#include <iostream>
#include <vector>
#include <string>

//ing

/**
 * 두 단어가 같은 구성을 갖는 경우
 * 한 단어에서 한 문자를 더하거나 빼거나 다른 문자로 바꾸어 같은 구성을 갖게 되는 경우 
 **/

using namespace std; 

int isSimilarWord(vector<char> v1, vector<char> v2){

}

int main(){
    int n;
    int is_similar=0;
    string tmpstr;

    cin>>n;
    vector<vector<char>> vchar(n);

    for(int i = 0; i < n; i++){
        cin >> tmpstr;
        vchar[i].insert(vchar[i].begin(), tmpstr.begin(), tmpstr.end());
    }

    for(int i=1; i<n; i++){
        is_similar+=isSimilarWord(vchar[0], vchar[i]);
    }
    cout<<is_similar;


    return 0;
}