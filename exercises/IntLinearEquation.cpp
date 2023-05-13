#include<bits/stdc++.h>
using namespace std;

int n, M;
int t[20], a[20], x[20];
int f=0;
int result=0;

void init_t(){
	t[0] = a[0];
	for(int i=1;i<=n;i++){
		t[i] = t[i-1] + a[i];
	}
}

void solution(){
	if(f==M){
		result += 1;
	}
}

void Try(int k){
	for(int v=1; v<= (M - f - (t[n-1]-t[k]))/a[k]; v++){
		x[k] = v;
		f += x[k]*a[k];
		if(k==n-1){
			solution();
		}else{
			Try(k+1);
		}
		f -= x[k]*a[k];
	}
}

int main(){
	cout << "Nhap n va M: "<< endl;
	scanf("%d %d",&n,&M);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	init_t();
	Try(0);
	// for(int i=0; i<n; i++){
	// 	printf("%d\n",t[i]);
	// }
	printf("%d",result);

	return 0;
}