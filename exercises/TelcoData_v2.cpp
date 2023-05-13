#include<bits/stdc++.h>

using namespace std;
map<string,int> numberCalls, totalTime;

bool check(string num){
	if(num.length() != 10)	return false;
	for(int i; i< num.length(); i++){
		if(!(num[i]>='0' && num[i]<='9'))
			return false;
	}
	return true;
}

int count_time(string stime, string etime){
	int time1 = 3600*(10*(stime[0] - '0') + (stime[1] - '0')) + 60*(10*(stime[3] - '0') + (stime[4] - '0')) + (10*(stime[6] - '0') + (stime[7] - '0'));
	int time2 = 3600*(10*(etime[0] - '0') + (etime[1] - '0')) + 60*(10*(etime[3] - '0') + (etime[4] - '0')) + (10*(etime[6] - '0') + (etime[7] - '0'));
	return time2 - time1;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string type;
	int incorrect_num=0, total_calls=0;
	
	do{
		cin >> type;
		if(type == "#")	continue;
		string fnum, tnum, date, stime, etime;
		cin >> fnum >> tnum >> date >> stime >> etime;
		if(!check(fnum) || !check(tnum)){
			incorrect_num += 1;
		}
		total_calls+=1;
		numberCalls[fnum] += 1;
		totalTime[fnum] += count_time(stime,etime);
		
	}while(type != "#");
	
	do{
		cin >> type;
		if(type == "?check_phone_number"){
			if(incorrect_num == 0) cout << 1 << endl;
			else	cout << 0 << endl;
		}
		
		if(type == "?number_calls_from"){
			string num;
			cin >> num;
			cout << numberCalls[num]<<endl;
		}
		
		if(type == "?number_total_calls"){
			cout << total_calls << endl;
		}
		
		if(type == "?count_time_calls_from"){
			string num;
			cin >> num;
			cout << totalTime[num] << endl;
		}
	}while(type != "#");
	
	
	return 0;
}
