#include <bits/stdc++.h>
using namespace std;

bool checkPhone(string s) {
    // 10 ky tu
    if (s.length() != 10) return false;

    for (int i = 0; i < s.length(); i++){
        if (!(s[i] >= '0' && s[i] <= '9')) return false;
    }

    return true;
}

// Tinh thoi gian cuoc goi
int countTime(string ftime, string etime) {
    // Chuyen thoi gian "HH:MM:SS" sang giay
    int startTime = 3600 * ((ftime[0] - '0') * 10 + ftime[1] - '0') + 
                    60 * ((ftime[3] - '0') * 10 + ftime[4] - '0') +
                    ((ftime[6] - '0') * 10 + ftime[7] - '0');

    int endTime = 3600 * ((etime[0] - '0') * 10 + etime[1] - '0') + 
                  60 * ((etime[3] - '0') * 10 + etime[4] - '0') +
                  ((etime[6] - '0') * 10 + etime[7] - '0');

    return endTime - startTime;
}

map<string, int> numberCalls;  
map<string, int> timeCall;    

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;
    int totalCalls = 0;       
    int incorrectPhone = 0;   

    // Read data cuoc goi
    do {
        cin >> type;
        if (type == "#") continue; 
        
        ++totalCalls; // Tang tong so cuoc goi len 1
        
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;

        if (!checkPhone(fnum) || !checkPhone(tnum)) ++incorrectPhone;

        numberCalls[fnum]++;
        timeCall[fnum] += countTime(ftime, etime);

    } while (type != "#"); 


    do {
        cin >> type;
        if (type == "#") continue; 

        if (type == "?check_phone_number") {
            if (incorrectPhone == 0) 
                cout << 1 << endl;
            else 
                cout << 0 << endl;

        } else if (type == "?number_calls_from") {
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;

        } else if (type == "?number_total_calls") {
            cout << totalCalls << endl;

        } else if (type == "?count_time_calls_from") {
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
        }

    } while (type != "#"); 

    return 0;
}
