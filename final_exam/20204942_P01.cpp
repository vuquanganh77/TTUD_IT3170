#include<bits/stdc++.h>
using namespace std;

map<string,int> qty_customer, total_trip_code ;



int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    int total_qty=0;

    string date;
    string trip_code,customer_code, datee, time;
    string query;
    int qty;
    do{
        cin >> date;
        if(date == "***"){
            break;
        }
    }while(date != "*");

    do{
        cin >> trip_code;
        if(trip_code == "***"){
            break;
        }
        cin >> customer_code >> datee >> time >> qty;
        total_qty += qty;
        qty_customer[customer_code] += qty;
        total_trip_code[trip_code] = 1;
    
        //travel_time_trip[trip_code] += count_time()
    }while(1);

    do{
        cin >> query;
        if(query == "***"){
            break;
        }
        if(query == "TOTAL_QTY"){
            cout << total_qty << endl;
        }

        if(query == "QTY_CUSTOMER"){
            string cmc;
            cin >> cmc;
            cout << qty_customer[cmc] << endl;
        }

        if(query == "QTY_MAX_PERIOD"){

        }

        if(query == "TOTALS_TRIPS"){
            cout << total_trip_code.size() << endl;
        }

        if(query == "TRAVEL_TIME_TRIP"){

        }

        if(query == "MAX_CONFLICT_TRIP"){

        }
        
    }while(1);
    return 0;
}