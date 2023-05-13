#include<bits/stdc++.h>
using namespace std;

#define MAX 50
int n;
int arr[MAX];

void print_array(){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void input(){
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    // Khoi tao 2 mang tam thoi luu gia tri cua 2 mang can merge
    int Temp1[n1];
    int Temp2[n2];


    // Luu gia tri cho 2 mang tam thoi
    for(int i=0;i<n1;i++){
        Temp1[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        Temp2[i] = arr[m+1+i];
    }

    int i=0,j=0,k=l;

    // Thuc hien merge
    while(i<n1 && j<n2){
        if(Temp1[i] <= Temp2[j]){
            arr[k] = Temp1[i];
            i++;
        }else{
            arr[k] = Temp2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = Temp1[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = Temp2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r){
    int m = (l+r)/2;

    // Chia nho bai toan ra, moi lan chia mang lam 2 phan bang nhau
    // Den khi moi mang con con 1 phan tu se tien hanh merge lai
    if(l<r){
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
    }
    merge(arr,l,m,r);
}

int main(){
    input();
    printf("Mang truoc khi sap xep la: ");
    print_array();

    merge_sort(arr,0,n-1);
    printf("\nMang sau khi sap xep la: ");
    print_array();

    return 0;
}