#include <iostream>
#include <string>
#include <cmath>

//완료

using namespace std;

void case1(int D, int W0, int I0, int I, int A){
    W0 += (I -(A+I0))*D;

    if(W0<=0){
        cout<<"Danger Diet"<<endl;
    }
    else{
        cout<<W0<<" "<<I0<<endl;
    }
}

void case2(int D, int W0, int I0, int T, int I, int A){
    string status = "NO";
    int Icur = I0;
    bool isDead = false;

    while(D--){
        int dW = I -(A+Icur);
        W0 += dW;

        if (W0 <= 0){
            isDead = true;
            break;
        }

        if(abs(dW) > T){
            Icur+=floor((double)dW/2);
        }

        if(Icur<=0){

            isDead = true;
            break;
        }
    }

    if(isDead == true){
        cout<<"Danger Diet"<<endl;
    }
    else{
        if(I0 > Icur){
            status = "YOYO";
        }
        cout << W0 << " " << Icur << " " << status << endl;
    }
}

int main(){
    int W0, I0, T;
    int D, I, A;
    

    cin>>W0>>I0>>T;
    cin>>D>>I>>A;

    

    case1(D,W0,I0,I,A);
    case2(D,W0,I0,T,I,A);

    return 0;
}


// 다이어트 전: 체중 W0, 일일 에너지 섭취량 I0, 일일 기초대사량 I0, 일일 활동 대사량 0
// 다이어트 기간(D): 일일 에너지 섭취량 I, 일일 활동 대사량 A -> 체중과 일일 기초 대사량 1일 1회 변화
// 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량 -> 기초 대사량 변화 역치 T 초과이면 체중변화 이후 일일 기초 대사량 증가 ((일일 에너지 섭취량 - 일일 에너지 소비량)/2)
// 체중이 0g 이하이거나 일일 기초 대사량이 0kcal 이하면 사망 
