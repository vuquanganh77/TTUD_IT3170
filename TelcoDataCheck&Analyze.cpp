#include<bits/stdc++.h>

using namespace std;
//while(strcpm(getline(std::cin,line),"#")!=0){
//		char line1 = " ";
//		char *rq = strtok(line," ");
//		char *from_num = strtok(NULL," ");
//		char *to_num = strtok(NULL," ");
//		char *date = strtok(NULL," ");
//		char *from_time = strtok(NULL," ");
//		char *end_time = strtok(NULL," ");

bool check_phone_number(string s){
	
		
		
	//check valid phone number
	if(s.length() != 10) return false;
	for(int i=0; i<s.length();i++){
		if(!(s[i]>='0' && s[i]<='9'))
			return false;
	}
	return true;
}
	

//int number_calls_from(string s){
//	
//	int count = 0;
//	
//	
//	return count;
//}

//int number_total_calls(char str[256]){
//	char line[256];
//	int count = 0;
//	
//	return count;
//}

int count_time_call_from(string ftime, string etime){
	int start_time = 3600*((ftime[0]-'0')*10 + ftime[1]-'0') + 60*((ftime[3]-'0')*10 + ftime[4]-'0') + ((ftime[6]-'0')*10 + ftime[7]-'0');
	
	int end_time = 3600*((etime[0]-'0')*10 + etime[1] - '0') + 60*((etime[3]-'0')*10 + etime[4] -'0') + ((etime[6]-'0')*10 + etime[7]-'0');
	
	return end_time - start_time;
	
}
	
map<string,int> numberCalls, timeCall;
int main(){
	
	ios_base :: sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string type;
	int totalCalls = 0;
	int incorrectPhone = 0;
	do{
		cin>>type;
		if(type == "#") continue;
		++totalCalls;
		string fnum,tnum,date,ftime,etime;
		
		cin >> fnum >> tnum >> date >> ftime >> etime;
		if(!check_phone_number(fnum) || !check_phone_number(tnum))
			++incorrectPhone;
		numberCalls[fnum] ++;
		timeCall[fnum] += count_time_call_from(ftime,etime);
	}while(type!="#");
	
	do{
		cin>>type;
		if(type == "#") continue;
		
		//	task 1
		if(type == "?check_phone_number"){
			if(incorrectPhone == 0) 
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		
		
		//task 2
		if(type =="?number_calls_from"){
			string phone;
			cin >> phone;
			cout << numberCalls[phone] << endl;
		}
		
		//task 3
		if(type =="?number_total_calls"){
			cout<<totalCalls <<endl;
		}
		
		//task 4
		if(type =="?count_time_calls_from"){
			string phone;
			cin >> phone;
			cout << timeCall[phone] << endl;
		}
	}while(type!="#");
//	char line[256];
	
//	while(strcpm(getline(std::cin,line)){
//		char line1 = " ";
//		char *left = strtok(line," ");
//		char *right = strtok(NULL," ");
//		
//		//task 1
//		if(strcmp(left,"?check_phone_number")==0){
//			int result = check_phone_number();
//			printf("%d",result);
//		}
//		
//		
//		//task 2
//		if(strcmp(left,"?number_calls_from")==0){
//			number_calls_from(right);
//		}
//		
//		//task 3
//		if(strcmp(left,"?number_total_calls")==0){
//			number_total_calls();
//		}
//		
//		//task 4
//		if(strcmp(left,"?count_time_calls_from")==0){
//			count_time_calls_from(right);
//		}
//		
//	}
	
	return 0;
}
