#include <bits/stdc++.h>
using namespace std;
//done and accepted

int main(){
    int T;
    cin >> T;
    while (T--){
    int M, N, A, U, output = 0, increment = 0;
    vector<int> inputA;
    priority_queue<int> less;
    priority_queue<int, vector<int>, greater<int>> higher;
        cin >> M >> N;
        for (int i = 0; i < M; i++)
        {
            cin >> A;
            inputA.push_back(A);
        }
        for (int i = 0; i < N; i++){
            cin >> U;
            if (i == 0){
                for (; increment != U; increment++){ //checks until we need to do the first case of GET
                    higher.push(inputA.front());
                    inputA.erase(inputA.begin());
                }
                output = higher.top();
                higher.pop();
            }
            else{
                for (; increment != U; increment++){ // checks each GET after the first instance
                    if (inputA.front() < output){
                        less.push(inputA.front());
                        inputA.erase(inputA.begin());
                        higher.push(output);
                        output = less.top();
                        less.pop();
                    }
                    else{
                        higher.push(inputA.front());
                        inputA.erase(inputA.begin());
                    }
                }
                less.push(output);
                output = higher.top();
                higher.pop();
            }
            cout << output << endl;
        }
        cin.ignore(1,'\n');
        if(T!= 0)
            cout << endl;
    }
    return 0;
}