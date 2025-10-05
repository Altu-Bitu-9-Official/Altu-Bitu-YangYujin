#include <iostream>
#include <vector>
#include <string>

using namespace std;

//완료

string solve_wheel(int n, int k, const vector<int>& s, const vector<char>& ch) {
    vector<char> result(n, '?');
    vector<bool> used_char(26, false); 
    int cur_idx = 0; 

    for (int i = 0; i < k; i++) {
        cur_idx = (cur_idx + s[i]) % n;

        char cur_ch = ch[i];
        int char_idx = cur_ch - 'A';

        if (result[cur_idx] == '?') {
            if (used_char[char_idx]) {
                return "!"; 
            }
            
            result[cur_idx] = cur_ch;
            used_char[char_idx] = true;
            
        } 
        else if (result[cur_idx] != cur_ch) {
            return "!";
        }
    }
    
    string str = "";
    for (int i = 0; i < n; i++) {
        int idx = (cur_idx - i + n) % n;
        str += result[idx];
    }

    return str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<int> s(k);
    vector<char> ch(k);

    for (int i = 0; i < k; i++) {
        if (!(cin >> s[i] >> ch[i])) break;
    }

    cout<<solve_wheel(n, k, s, ch)<<endl;

    return 0;
}