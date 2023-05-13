#include<bits/stdc++.h>
using namespace std;

int x[100];

int n;

void print_arr(int x[]){
	for(int i = 0; i<n; i++){
		cout<<x[i];
	}
	cout<<endl;
}

void back_tracking(int i){
	for(int j =0; j<=1; j++){
		x[i] = j;
		if(i==n-1){
			print_arr(x);
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
