#include <bits/stdc++.h>
using namespace std;
//done with presentation errors
int main(){
    int T;
    cin >> T;
    int n = T;
    while (T != 0){
        vector<int> maxsum;
        int nonZero;
        for(int i = 0; i < n; i++){
            cin >> nonZero;
            if(nonZero > 0){//push back with non 0's
                maxsum.push_back(nonZero);
            }
            T--;
        }
        if(maxsum.empty()){//if empty put a 0
            maxsum.push_back(0);
        }
        for (int j = 0; j < maxsum.size(); j++){
            if(j == maxsum.size()){
                cout << maxsum[j];
            }
            else
                cout << maxsum[j] << ' ';
        }
        cout << endl;
        if(T == 0){
            cin >> n;
            if(n == 0){//checks to see if its the end
                cout << endl;
                break;
            }
            else{
                T = n;
                maxsum.clear();
            }
        }
    }
    
    return 0;
}