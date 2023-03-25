#include <bits/stdc++.h>
using namespace std;
//done and accepted
int main(){
    int denom[5] = {50, 25, 10, 5, 1};
    int memo[7490] = {0};
    int testCases;
    memo[0] = 1;
        for (int i = 0; i < 5; i++){
            for(int T = 1; T < 7490; T++){
                if(denom[i] <= T){
                    memo[T] += memo[T-denom[i]];
                }
            }
        }
    while (cin >> testCases){
            cout << memo[testCases] << endl;
    }
    return 0;
}