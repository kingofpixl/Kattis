#include <bits/stdc++.h>
using namespace std;
//passed and accepted
int indx;
bool slump(string s){
    if(s[indx] != 'D' && s[indx] != 'E')//checks first character of a slump
        return false;
    indx++;
    if(s[indx] != 'F')//checks to see if F is next
        return false;
    while(s[indx] == 'F'){//goes through each F and sees if a G is next
        indx++;
        if(s[indx] == 'G'){
            indx++;
            return true;
        }
    }
    return slump(s);//the following is a slump so we recall the function
}

bool slimp(string s){
    if(s[indx] != 'A')//checks if the first character is an A
        return false;
    indx++;
    if(s[indx] == 'H'){//sees if its a 2 character slimp
        indx++;
        return true;
    }
    if(s[indx] == 'B'){//checks if the next character is a B and if so we call slimp again and also check after that if the next character is a C
        indx++;
        return slimp(s) && s[indx++] == 'C';
    }
    return slump(s) && s[indx++] == 'C';//if there is no B we check if its a slump followed by a C
}

int main(){
int T;
string s;
cin >> T;
cout << "SLURPYS OUTPUT" << endl;
while(T--){
    cin >> s;
    indx = 0;
    if(slimp(s) && slump(s) && indx == s.size())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    }
cout << "END OF OUTPUT" << endl;
return 0;
}