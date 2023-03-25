#include <bits/stdc++.h>
using namespace std;
//done and accepted
struct Job{
    int time;
    int charge;
    int id;
};

bool compare(const Job& J1, const Job& J2){
    if((J2.charge * J1.time) < (J1.charge * J2.time))
        return true;
    else if((J2.charge * J1.time) > (J1.charge * J2.time))
        return false;
    else
        return J1.id < J2.id;
}

int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<Job> job(n);//a vector of Jobs called job, im very original
        for(int i = 0; i < n; i++){
            cin >> job[i].time >> job[i].charge;
            job[i].id = i + 1;
        }
        sort(job.begin(), job.end(), compare);
        for(int i = 0; i < n; i++){
            if(i == n-1){
                cout << job[i].id;
                break;
            }
            cout << job[i].id << " ";
        }
        cout << endl;
        if(T != 0)
            cout << endl;
    }
    return 0;
}