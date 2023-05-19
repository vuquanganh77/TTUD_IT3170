#include<bits/stdc++.h>
using namespace std;

int n,s;
int mark[100], mark_best[101], t[100], t_max[100];
int cnt, cnt_best, sum;

void input(){
    cin >> n >> s;
    for(int i=1; i<=n; i++){
        cin >> t[i];
    }

    cnt_best = n+1;

    t_max[n] = t[n];
    for(int i=n-1; i>=0; i--){
        t_max[i] = max(t_max[i+1], t[i]);
    }
}

void update_solution(){
    if(sum==s && cnt < cnt_best){
        cnt_best = cnt;
        for(int i=1; i<=n; i++){
            mark_best[i] = mark[i];
        }
    }
}

void print_solution(){
    if(cnt_best==n+1){
        cout << -1;
    }else{
        cout << cnt_best << endl;
        for(int i=1; i<=n; i++){
            if(mark_best[i]){
                cout << t[i] << " ";
            }
        }
    }
}

int branch_and_bound(int i){
    // if(cnt + (s-sum)/t_max[i+1] >= cnt_best){
    //     return;
    // }

    for(int j=0; j<=1; j++){
        mark[i] = j;
        sum += t[i]*j;
        cnt += j;

        if(i==n){
            update_solution();
        }
        else if(sum < s){
            branch_and_bound(i+1);
        }   

        sum -= t[i]*j;
        cnt -= j;

    }

    return 0;


}


int main(){
    input();
    branch_and_bound(1);
    print_solution();

    return 0;
}