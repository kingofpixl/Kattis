#include <bits/stdc++.h>
using namespace std;
//done and accepted

int main(){
    int n;
    cin >> n;
    while (n != 0)
    {
        int k, bet;
        long long int answer = 0;
        std::multiset<int> bets;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> bet;
                bets.insert(bet);
            }
            answer += *bets.rbegin() - *bets.begin();
            bets.erase(bets.begin());
            bets.erase(--bets.end());
        }
        cout << answer << endl;
        cin >> n;
    }
    return 0;
}