#include<bits/stdc++.h>
using namespace std;

map<string,int> num_call_from, count_time_from;

bool check_num(string s){
    if(s.length()!=10){
        return false;
    }
    for(int i=0; i<10; i++){
        if(!(s[i]>='0' && s[i]<='9')){
            return false;
        }
    }
    return true;
}

// 02:23:23  ||  04:35:25
int count_time(string s1, string s2){
    int x = ((s1[0]-'0')*10+(s1[1]-'0'))*3600 + ((s1[3]-'0')*10+(s1[4]-'0'))*60 + ((s1[6]-'0')*10+(s1[7]-'0'));
    int y = ((s2[0]-'0')*10+(s2[1]-'0'))*3600 + ((s2[3]-'0')*10+(s2[4]-'0'))*60 + ((s2[6]-'0')*10+(s2[7]-'0'));
    return y-x;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    string type;
    int check = 0;
    int total_calls = 0;

    do{
        cin >> type;
        if(type == "#"){
            continue;
        }
        string fnum, tnum, date, ftime, ttime;
        cin >> fnum >> tnum >> date >> ftime >> ttime;
        if(!check_num(fnum) || !check_num(tnum)){
            check++;
        }
        total_calls ++;
        num_call_from[fnum]++;
        count_time_from[fnum] += count_time(ftime,ttime);
    }while(type!="#");

    do{
        cin >> type;
        if(type == "?check_phone_number"){
            if(check==0){
                cout << 1 << endl;
            }else{
                cout << check << endl;
            }
        }

        if(type == "?number_calls_from"){
            string num;
            cin >> num;
            int result = num_call_from[num];
            cout << result << endl;
        }

        if(type == "?number_total_calls"){
            cout << total_calls << endl;
        }

        if(type == "?count_time_calls_from"){
            string num;
            cin >> num;
            cout << count_time_from[num] << endl;
        }
    }while(type!="#");
    return 0;
}