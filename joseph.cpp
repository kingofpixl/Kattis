#include <bits/stdc++.h>
using namespace std;

int joseph(int);

int main(){
    int k;
    int ans[14] = {0};
    while (cin >> k){
        if(k == 0)
            break;
        if(ans[k] != 0)
            cout << ans[k] << endl;
        else{
            ans[k] = joseph(k);
            cout << ans[k] << endl;
        }
    }
    for (int i = 0; i < 14; i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}

int joseph(int k){
    int length = 2*k, index, m;
    bool found = true;
    for (m = k + 1; found; m++)
    {
        index = 0;
        for (int i = 0; i < k; i++)
        {
            index = (index + m - 1) % (length - i);
            if(index < k)
                break;
        }
        if(index < k)
            continue;
        else
            found = false;
    }
    m--;
    return m;
}