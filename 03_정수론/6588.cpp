#include <iostream>
#include <vector>
#include <cmath>

//완료

using namespace std;

void goldbach(int n, vector<bool>& is_prime){
    bool is_wrong = true;
    for(int i=3; i<=n/2; i+=2){
        if(is_prime[i]&&is_prime[n-i]){
            cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
            is_wrong=false;
            break;
        }
    }
    if(is_wrong){
        cout<<"Goldbach's conjecture is wrong."<<"\n";
    }
    

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    const int MAX_N = 1000000;
    
    vector<bool> is_prime(MAX_N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;


    for (int i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }


    while(true){
        cin>>n;
        if(n==0){
            break;
        }
        goldbach(n, is_prime);

    }
    
    
    return 0;
}