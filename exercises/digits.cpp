#include<bits/stdc++.h>
using namespace std;

int Check[10] = {0};
int arr[8];
int N;
int Q=0;
// I,C,T,H,U,S,K

// void if_valid(){
//     if((arr[1]*100 + arr[2]*10 + arr[3]) - (arr[7]*100 + 62) + (arr[4]*1000 + arr[5]*100 + arr[6]*10 + arr[3]) == N){
//         Q += 1;
//     }
// }

void back_tracking(int i){
    for(int j=1; j<=9; j++){
        if(Check[j] == 0){
            arr[i] = j;
            Check[j] = 1;
            if(i==7 && (arr[1]*100 + arr[2]*10 + arr[3]) - (arr[7]*100 + 62) + (arr[4]*1000 + arr[5]*100 + arr[6]*10 + arr[3]) == N){
                // if_valid();
                Q += 1;
            }else{
                back_tracking(i+1);
                Check[j] = 0;
            }
        }
    }
}

int main(){
    scanf("%d",&N);
    back_tracking(1);
    printf("%d",Q);
    return 0;
}