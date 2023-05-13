#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    int result=0;
    for(int i=1; i<n-1; i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            result += 1;
        }
    }


    printf("%d",result);
    return 0;
}