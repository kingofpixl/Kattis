#include <bits/stdc++.h>
using namespace std;
//done and accepted
int vacation[101][101];
string s1, s2;
int solve(int i, int j){
    if(i == s1.size() || j == s2.size())
        return 0;
    if(vacation[i][j] != -1)//if theres a value weve calculated return it
        return vacation[i][j];
    if(s1[i] == s2[j]){
        return vacation[i][j] = solve(i+1,j+1) + 1;
    }
    else{
        vacation[i][j] = max(solve(i+1,j),solve(i,j+1));//find the largest value of the solutions
        return vacation[i][j];
    }
    
}

int main(){
    int cases = 1;
    while(getline(cin, s1)){
        if(s1[0] == '#')
            break;
        getline(cin, s2);
        for(int i = 0; i < 101; i++)//setting all of the vacation spots to -1 so we know whats been solved
            for(int j = 0; j < 101; j++)
                vacation[i][j] = -1;
        
        cout << "Case #" << cases++ << ": you can visit at most " << solve(0,0) << " cities." << endl;
    }
    return 0;
}