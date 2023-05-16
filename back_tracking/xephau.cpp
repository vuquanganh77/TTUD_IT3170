#include<bits/stdc++.h>
using namespace std;

int arr[8];

bool ok(int i, int j){
    for(int k=1; k<=i; k++){
        if(arr[k] == j || abs(arr[k] - j) == abs(k-i)){
            return false;
        }
    }
    return true;
}

void print_arr(){
    for(int i=1; i<=8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void xep_hau(int i){
    for(int j=1; j<=8; j++){
        if(ok(i,j)){
            arr[i] = j;
            if(i==8){
                print_arr();
            }else{
                xep_hau(i+1);
            }
        }
    }
}


int main(){
    xep_hau(1);
    return 0;
}