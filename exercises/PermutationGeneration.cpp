#include<bits/stdc++.h>
using namespace std;

int n;
int Bool[100] = {0};
int arr[100];

void print_arr(){
	for(int i=1;i<=n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}


void back_tracking(int i){
	for(int j=1; j<=n; j++){
		if(!Bool[j]){
			arr[i] = j;
			Bool[j] = 1;
			if(i == n)
				print_arr();
			else
				back_tracking(i+1);
				Bool[j ] = 0;	
		}
	}
}

int main(){
	cin >> n;
	back_tracking(1);
	return 0;
}
