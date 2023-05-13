#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int a[MAX];

int MaxLeftMid(int i, int j){
    int maxLM = a[j];
    int s=0;
    for(int k=j; k>=i; k--){
        s+=a[k];
        maxLM = max(maxLM,s);
    }
    return maxLM; 
}

int MaxRightMid(int i, int j){
    int maxRM = a[i];
    int s=0;
    for(int k=i; k<=j; k++){
        s+=a[k];
        maxRM = max(maxRM,s);
    }
    return maxRM;
}

int sub_seq_max(int i, int j){
    if(i==j) return a[i];
    int mid = (i+j)/2;
    int wL = sub_seq_max(i,mid);
    int wR = sub_seq_max(mid+1,j);
    int maxLM = MaxLeftMid(i,mid);
    int maxRM = MaxRightMid(mid+1,j);
    int wM = maxLM + maxRM;
    return max(max(wL,wR),wM);
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int result = sub_seq_max(0,n-1);
    cout << result;
    return 0;
}