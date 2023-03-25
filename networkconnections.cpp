#include <bits/stdc++.h>
using namespace std;
//accepted and done

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind


class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n + 1;
	 uf = new UF[howMany];
	 for (int i = 1; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use
      
      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }
      
   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

int main(){
   char q;
    int T, i, j, right = 0, wrong = 0, setnum = 0, pcs, parse;
    string input, identifier = " ";
    cin >> T;
    while (T--)
    {
        cin >> pcs;
        UnionFind Ufind(pcs);
        cin.ignore(1, '\n');
        getline(cin,input);
        while (input != ""){
           q = input[0];
           input = input.substr(2);
           parse = input.find(" ");
           i = stoi(input.substr(0,parse)); //parse the string
           j = stoi(input.substr(parse+1));
           if(q == 'c'){
              Ufind.merge(i,j);
           }
           else {
            if (Ufind.find(i) == Ufind.find(j)) //check if they are equal if so its good
              right++;
           else
               wrong++;
           }
            getline(cin,input);
        }
        if (setnum != 0){
            cout << endl;
        }
         cout << right << "," << wrong << endl;
         right = 0;
         wrong = 0;
         setnum++;
    }
    
    return 0;
}