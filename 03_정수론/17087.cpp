#include <iostream>
#include <vector>
#include <cmath>

//완료

using namespace std;

int gcd(int a, int b){
    int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    vector<int> v;

    while(n--){
        int a;
        cin>>a;
        v.push_back(abs(s-a));
    }


    int final_gcd = v[0]; 

    for(int i=1; i<v.size(); i++){
    
        final_gcd = gcd(final_gcd, v[i]); 
    }

    cout<<final_gcd<<endl;
    
    return 0;
}