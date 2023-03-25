#include <bits/stdc++.h>
using namespace std;
//done and accepted

vector<int> house;

int checkRange(int D){
    int value = 1;
    double houseRange = house[0] + D;
    for(int i = 0; i < house.size(); i++){
        if(house[i] > houseRange){
            houseRange = house[i] + D;
            ++value;
        }
    }
    return value;
}

int main(){
    int T, m, n;
    cin >> T;
    while (T--){
        int input;
        double D;
        cin >> n >> m;
        house.clear();
        for (int i = 0; i < m; i++){
            cin >> input;
            house.push_back(input);
        }
        sort(house.begin(), house.end());
        double high = house[house.size() - 1], low = 0;
        while (high - low  > 0.01){
            D = (high + low)/2.0;
            if(checkRange(D) > n)
                low = D;
            else
                high = D;
        }
        cout << fixed << setprecision(1) << D/2.0 << endl;
    }
    return 0;
}