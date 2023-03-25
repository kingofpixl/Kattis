#include <bits/stdc++.h>
using namespace std;
//done and accepted
string board[15];
int n;
void find(int [],  bool [], bool [], bool [], const int r);

long long int Count = 0;
int main(){
    int cc = 0;
    cin >> n;
    while (n != 0){
        bool col[15], diag1[30], diag2[30]; //max values they can be
        int rowpos[15];
        for (int i = 0; i < n; i++){//fill the board and columns
            cin >> board[i];
            col[i] = true;
        }
        for (int i = 0; i < (2*n); i++){//fill the diagonals
            diag1[i] = true;
            diag2[i] = true;
        }
        
        if(n < 4){//if its a 3x3
            cc++;
            cout << "Case " << cc << ": 0" << endl;
        }
        else{//otherwise calculate
        int r = 0;
        cc++;
        find(rowpos, col, diag1, diag2, r);
        cout << "Case " << cc << ": " << Count << endl;
        }
        Count = 0;
        cin >> n;
    }
    return 0;
}

void find(int rowspos[],  bool col[], bool diag1[], bool diag2[], const int r){
    if (r == n){
        Count++;
        return;
    }
    for(int c = 0; c < n; c++){
        rowspos[r] = c;
        if (board[r][c] == '*'){
            continue;
        }
        //if bad [r][c] continue
        if (col[c] == false || diag1[r + c] == false || diag2[(r - c) + n] == false){
            continue;
        }
        //if same col/diag1/daig2 continue
        col[c] = false;
        diag1[r + c] = false;
        diag2[(r - c) + n] = false;
        //mark col, diag1, diag2
        find(rowspos, col, diag1, diag2, r+1);
        col[c] = true;
        diag1[r + c] = true;
        diag2[(r - c) + n] = true;
        //unmark col, diag1, diag2
    } 
}