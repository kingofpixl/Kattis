#include <bits/stdc++.h>
using namespace std;
//tested and passed
int ed[210][210];
int visited[210];
int colours[210];

int cases;
bool bfs(int edge){
    queue<int> q;
    q.push(edge);
    colours[edge] = 1;
    visited[edge] = 1;

    while (!q.empty()){
        int f = q.front();
        q.pop();
        for(int i = 0; i < cases; i++){
            if(ed[f][i]){
                if(!visited[i]){
                    colours[i] = !colours[f];
                    visited[i] = 1;
                    q.push(i);
                }
                else if(colours[i] == colours[f]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    while(cin >> cases){
        if(cases == 0)
            break;
        int edges;
        cin >> edges;
        memset(ed,0,sizeof(ed));
        memset(visited,0,sizeof(visited));
        int a,b;
        for(int i = 0; i < edges; i++){
            cin >> a >> b;
            ed[a][b] = 1;
            ed[b][a] = 1;
        }
        if(bfs(0))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}