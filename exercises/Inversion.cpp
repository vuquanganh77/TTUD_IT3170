#include<bits/stdc++.h>
using namespace std;

#define max 1000000
int n;
int result=0;
int arr[max];


void input(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void inversion(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    //Khoi tao 2 mang temp luu gia tri cua 2 mang can merge
    int T1[n1];
    int T2[n2];

    for(int i=0;i<n1;i++){
        T1[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        T2[i] = arr[m+1+i];
    }

    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(T1[i] > T2[j]){
            result += m-i+1;
            arr[k] = T2[j];
            k++;
            j++;
        }else{
            arr[k] = T1[i];
            k++;
            i++;
        }

    }

    while(i<n1){
        arr[k] = T1[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = T2[j];
        j++;
        k++;
    }
}

void divide(int arr[], int l, int r){
    int m = (l+r)/2;
    if(l<r){
        divide(arr,l,m);
        divide(arr,m+1,r);
    }
    inversion(arr,l,m,r);

}

int main(){
    input();
    divide(arr,0,n-1);
    printf("%d",result);
    return 0;
}