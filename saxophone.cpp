#include <bits/stdc++.h>
using namespace std;
//done and accepted
int main(){
    vector<bool>fingers[128];
    fingers['c'] = {false,true,true,true,false,false,true,true,true,true};
    fingers['d'] = {false,true,true,true,false,false,true,true,true,false};
    fingers['e'] = {false,true,true,true,false,false,true,true,false,false};
    fingers['f'] = {false,true,true,true,false,false,true,false,false,false};
    fingers['g'] = {false,true,true,true,false,false,false,false,false,false};
    fingers['a'] = {false,true,true,false,false,false,false,false,false,false};
    fingers['b'] = {false,true,false,false,false,false,false,false,false,false};
    fingers['C'] = {false,false,true,false,false,false,false,false,false,false};
    fingers['D'] = {true,true,true,true,false,false,true,true,true,false};
    fingers['E'] = {true,true,true,true,false,false,true,true,false,false};
    fingers['F'] = {true,true,true,true,false,false,true,false,false,false};
    fingers['G'] = {true,true,true,true,false,false,false,false,false,false};
    fingers['A'] = {true,true,true,false,false,false,false,false,false,false};
    fingers['B'] = {true,true,false,false,false,false,false,false,false,false};
    int setnum;
    string input;
    cin >> setnum;
    cin.ignore(1,'\n');
    while (setnum--){
        int totalpress[10] = {0};
        vector<bool>button(10, false);
        getline(cin, input);
        for(auto it : input){
            if (input == "")
                break;
            for (int i = 0; i < 10; i++){
                if (!button[i] && fingers[it][i]){
                    totalpress[i]++;
                } 
            }
            button = fingers[it];
        }
        for (int i = 0; i < 10; i++){
            if (i == 9)
                cout << totalpress[i];
            else
                cout << totalpress[i] << " ";
        }
        cout << endl;
    }
    return 0;
}