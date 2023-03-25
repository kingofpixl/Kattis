#include <bits/stdc++.h>
using namespace std;

int main(){
    map <string, string> dic;
    map <string, string>::iterator it;
    string real,gibberish,input,str;
    while(getline(cin,str) && !str.empty())
    {
        auto between = str.find(' ');
        real = str.substr(0,between);
        gibberish = str.substr(between+1);
        dic.insert(pair<string,string>(gibberish,real));
    }
    
    while (cin >> input)
    {
        it = dic.find(input);
            if (it == dic.end())
            {
                cout << "eh"<< endl;
            }
            else
            cout << it->second << endl;
    }
    return 0;
}