#include <bits/stdc++.h>
using namespace std;
//done and accepted
int table[11][110];
int summation[11][110];
int path[11][110];
int r, c;

int pathfinder(int row, int col){
    if(col >= c)
        return 0;
    if(summation[row][col] != INT_MAX) //base case
        return summation[row][col];
    int nextRows[3] = {row - 1, row, row + 1};
    if(row == 0)
        nextRows[0] = r - 1;
    if(row == r - 1)
        nextRows[2] = 0;
    
    for(int i = 0; i < 3; i++){
        int value = table[row][col] + pathfinder(nextRows[i], col + 1);//recursive
        if(summation[row][col] > value || (summation[row][col] == value && path[row][col] > nextRows[i])){
            summation[row][col] = value;
            path[row][col] = nextRows[i];
        }
    }
    return summation[row][col];
}

int main(){
    while(cin >> r >> c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> table[i][j];
            summation[i][j] = INT_MAX;//set the path values to a max int
        }
    }
    int minimumPath = INT_MAX;
    int pathNumber = 0;
    for(int i = 0; i < r; i++){
        pathfinder(i, 0);
        if(summation[i][0] < minimumPath){//find the smallest sollution from the beggining row
            minimumPath = summation[i][0];
            pathNumber = i;
        }
    }
    for(int j = 0; j < c; j++){
        if(j == 0){
            cout << pathNumber + 1;
        }
        else
            cout << " " << pathNumber + 1;
        pathNumber = path[pathNumber][j];
    }
    cout << endl;
    cout << minimumPath << endl;
    }
    return 0;
}