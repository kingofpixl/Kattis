#include <bits/stdc++.h>
using namespace std;

int main(){
    int K, E, counter = 0, setnum = 1, tempcounter = 0;
    vector <string> keywords;
    vector <string> exc;
    string temp, keyword, excuse;
    while (cin >> K >> E)
    {
        keywords.clear();
        exc.clear();
        for (int i = 0; i < K; i++)//take in keywords
        {
            cin >> keyword;
            keyword = " " + keyword + " ";
            keywords.push_back(keyword);
        }
        cin.ignore(1, '\n');
        for (int j = 0; j < E; j++)//take in excuses
        {
            getline(cin,excuse);
            temp = excuse;
            temp = " " + temp + " ";
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            for (int l = 0; l < temp.size(); l++)//replace punctuation and digits with spaces
            {
                if (ispunct(temp[l]) || isdigit(temp[l]))
                {
                    temp.replace(l,1," ");
                }
            }
            for (int k = 0; k < keywords.size(); k++)//search the excuse with the keywords given
            {
                for (auto pos = temp.find(keywords[k]); pos != string::npos; counter++)
                {
                    pos = temp.find(keywords[k], pos + keywords[k].length() - 2);//changes the position to check for more keywords, the -2 is to account for the spaces initially added
                }
            }
            if (tempcounter < counter && !exc.empty())//if the vector isnt empty and we find a greater amount of keywords, erase the old stuff
                {
                    exc.clear();
                    exc.push_back(excuse);
                }
                else if(tempcounter == counter)//if we find an equal amount of keywords add it to the vector
                    exc.push_back(excuse);
                else if(tempcounter < counter && exc.empty())//get the first excuse
                    exc.push_back(excuse);
                if(tempcounter < counter)//keeps the highest counted amount of keywords
                    tempcounter = counter;
                counter = 0;
        }
        cout << "Excuse Set #" << setnum << endl;
        for (int i = 0; i < exc.size(); i++)
        {
            cout << exc[i] << endl;
        }
        cout << endl;
        tempcounter = 0;
        setnum++;
    }
    return 0;
}