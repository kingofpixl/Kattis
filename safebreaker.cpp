#include <bits/stdc++.h>
using namespace std;
//done and accepted

struct guess
{
    string givenGuess;
    int correct;
    int badplacement;
};
vector<guess> posibGuesses;

bool posibilityCheck(string);
bool guessPosibility(string, guess);

int main(){
    vector<string> posibilities;
    string posib, ans;
    int counter = 0, T;
    for (int i = 0; i < 100000; i++){
        posib = to_string(i);
        if (i < 1001)
            posibilities.push_back(posib.insert(0, 4 - posib.size(), '0'));
        else
            posibilities.push_back(posib = to_string(i));
    }
    cin >> T;
    while (T--){
    int g;
    cin >> g;
    posibGuesses.resize(g);
    char c;
    for (int i = 0; i < g; i++){
        cin >> posibGuesses[i].givenGuess >> posibGuesses[i].correct >> c >> posibGuesses[i].badplacement;

    }
    for (int i = 0; i < 10000; i++)
    {
        if(posibilityCheck(posibilities[i])){
            ans = posibilities[i];
            counter++;
        }
    }
    if (counter == 0)
        cout << "impossible" << endl;
    else if(counter == 1)
        cout << ans << endl;
    else
        cout << "indeterminate" << endl;
    counter = 0;
    }
    return 0;
}

bool posibilityCheck(string s){
    for (int i = 0; i < posibGuesses.size(); i++){
        if(!guessPosibility(s, posibGuesses[i]))
            return false;
    }
    return true;
}

bool guessPosibility(string str, guess guess){
    vector<bool> A(4, false);
    vector<bool> G(4, false);
    int right = 0, misplaced = 0;
    for(int i = 0; i < 4; i++){
        if(str[i] == guess.givenGuess[i]){
            right++;
            A[i] = true;
            G[i] = true;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(str[i] == guess.givenGuess[j] && A[i] == false && G[j] != true){
                misplaced++;
                A[i] = true;
                G[j] = true;
            }
        }
    }

    if ((right != guess.correct) || (misplaced != guess.badplacement))
        return false;
    else
        return true;
}