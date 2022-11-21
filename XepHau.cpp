#include<bits/stdc++.h>
using namespace std;

int arr[20];

bool ok(int i, int j){
	for(int t=1;t<i;t++){
		if(arr[t]==j || abs(i-t)==abs(j-arr[t])){
			return false;
		}
	}
	return true;
}

void print_arr(int n){
	for(int i=1;i<=n;i++){
		cout << arr[i];
	}
	cout << endl;
}

void xep_hau(int i, int n){
	for(int j=1;j<=n;j++){
		if(ok(i,j)){
			arr[i] = j;
			
			if(i==n){
				print_arr(n);
			}
			xep_hau(i+1,n);
		}
	}
}

int main(){
	int n=8;
	xep_hau(1,n);
	return 0;
}
