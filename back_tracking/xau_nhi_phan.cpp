#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100];

void print_arr(){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void back_tracking(int i){
    for(int j=0; j<=1; j++){
        arr[i] = j;
        if(i==n-1){
            print_arr();
        }else{
            back_tracking(i+1);
        }
    }
}

int main(){
    cin >> n;
    back_tracking(0);
    return 0;
}