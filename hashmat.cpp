#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int x = 0,y= 0,ans = 0;
    while(cin >> x >> y){
        ans = abs(x - y);
        cout << ans << endl;
    }
    return 0;
}