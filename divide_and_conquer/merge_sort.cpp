#include<bits/stdc++.h>
using namespace std;

int arr[100];
int n;

void input(){
    cout << "Nhap so luong phan tu cua mang: " << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}

void print_arr(){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int i, int mid, int j){
    int n1 = mid - i + 1;
    int n2 = j - mid;
    int temp1[n1], temp2[n2];
    for(int k=0; k<n1; k++){
        temp1[k] = arr[i+k];
    }
    for(int k=0; k<n2; k++){
        temp2[k] = arr[mid+1+k];
    }

    int t1=0,t2=0,merge_index=i;

    while(t1<n1 && t2<n2){
        if(temp1[t1] <= temp2[t2]){
            arr[merge_index] = temp1[t1];
            t1++;
            merge_index++;
        }
        if(temp1[t1] > temp2[t2]){
            arr[merge_index] = temp2[t2];
            t2++;
            merge_index++;
        }
    }

    while(t1<n1){
        arr[merge_index] = temp1[t1];
        t1++;
        merge_index++;
    }

    while(t2<n2){
        arr[merge_index] = temp2[t2];
        t2++;
        merge_index++;
    }

}

void merge_sort(int i, int j){
    int mid = (i+j)/2;
    if(i<j){
        merge_sort(i,mid);
        merge_sort(mid+1,j);
    }
    merge(i,mid,j);
}

int main(){
    input();
    cout << "Mang truoc khi sap xep: ";
    print_arr();
    merge_sort(0,n-1);
    cout << "Mang sau khi sap xep: ";
    print_arr();
    return 0;
}