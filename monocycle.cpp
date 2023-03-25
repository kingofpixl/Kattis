#include <bits/stdc++.h>
using namespace std;
//done and accepted
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

struct node {
    int row;
    int col;
    int direction;
    int colour;
};

node makeNode(int row, int col, int direction, int colour){
    node m;
    m.row = row;
    m.col = col;
    m.direction = direction;
    m.colour = colour;
    return m;
}

int BFS(int l, int w, char board[27][27], node start, node goal){
    queue<node> q;
    bool visited[27][27][4][5] = {false};
    int distance[27][27][4][5] = {0};//tracks the distance at each step
    int finishtime = 0;
    q.push(start);
    while(!q.empty()){
        node current = q.front();
        q.pop();
        int currRow = current.row, currCol = current.col, currDirection = current.direction, currColour = current.colour;
        visited[currRow][currCol][currDirection][currColour] = true;
        if(currRow == goal.row && currCol == goal.col && currColour == 0){
            finishtime = distance[currRow][currCol][currDirection][currColour];
            return finishtime;//distance
        }
        node nextNode;
        int nextRow = currRow + dr[currDirection];
        int nextCol = currCol + dc[currDirection];
        int nextColour = (currColour+1)%5;
        if(board[nextRow][nextCol] != '#'){//forward checker
            nextNode = makeNode(nextRow, nextCol, currDirection, (currColour+1)%5);
            if(!visited[nextRow][nextCol][currDirection][nextColour]){
                distance[nextRow][nextCol][currDirection][nextColour] = ((distance[currRow][currCol][currDirection][currColour]) + 1);
                q.push(nextNode);
            }
        }
        int moveRight = (currDirection+1)%4;
        int moveLeft = (currDirection+3)%4;
        node rotatingRight;
        node rotatingLeft;
        rotatingRight = makeNode(currRow, currCol, moveRight, currColour);
        rotatingLeft = makeNode(currRow, currCol, moveLeft, currColour);
        if(!visited[currRow][currCol][moveRight][currColour]){//rotate right
            distance[currRow][currCol][moveRight][currColour] = ((distance[currRow][currCol][currDirection][currColour]) + 1);
            q.push(rotatingRight);
        }

        if(!visited[currRow][currCol][moveLeft][currColour]){//rotate left
            distance[currRow][currCol][moveLeft][currColour] = ((distance[currRow][currCol][currDirection][currColour]) + 1);
            q.push(rotatingLeft);
        }
    }
    return -1;
}

int main(){
    int m,n;
    int cases = 1;
    while(cin >> m >> n){
        if(m == 0 && n == 0)
            break;
        node start, goal;
        char board[27][27]; //base board with boundaries to stop the cycle from going off the edge
        for(int i = 0; i < 27; i++)
            for(int j = 0; j < 27; j++)
                board[i][j] = '#';
        
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j++){
                char input;
                cin >> input;
                board[i][j] = input;
                if(input == 'S')
                    start = makeNode(i,j,0,0);
                if(input == 'T')
                    goal = makeNode(i,j,0,0);
            }

        }
        int timer;
        if(cases > 1)
            cout << endl;
        cout << "Case #" << cases++ << endl;
        timer = BFS(m,n,board,start,goal);
        if(timer == -1)
            cout << "destination not reachable" << endl;
        else
            cout << "minimum time = " << timer << " sec" << endl;
    }
    return 0;
}