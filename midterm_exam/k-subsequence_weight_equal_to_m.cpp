#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    int  sum[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + a[i];

    }
    for(int i=1; )


    return 0;
}