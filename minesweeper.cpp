#include <bits/stdc++.h>
using namespace std;
//done and checked
int main(){
    int col,row, num = 0, setnum = 0;
    const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    char input;
    while (cin >> row >> col)
    {
        if (row == 0 && col == 0)
            break;
        
        vector<vector<char>> board(row+2, vector<char>(col+2)); //initialize entire board with '0's
        for (int i = 0; i <= row+1; i++)
        {
            for (int j = 0; j <= col+1; j++)
            {
                board[i][j] = '0';
            } 
        }
        for (int i = 1; i <= row; i++) // put the mines in
        {
            for (int j = 1; j <= col; j++)
            {
                cin >> input;
                if (input == '*')
                    board[i][j] = input;
            } 
        }
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (board[i][j] == '*')
                        break;
                    if (board[i + dr[k]][j + dc[k]] == '*')//check each surrounding area for mines
                    {
                        num++;
                    }   
                }
                if (board[i][j] != '*') //change the number
                    board[i][j] = num + '0';
                num = 0;
            }
        }
        if (setnum != 0)
            cout << endl;
        setnum++;
        cout << "Field #" << setnum << ":" << endl;
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                    cout << board[i][j];
            } 
            cout << endl;
        }
    }
    return 0;
}