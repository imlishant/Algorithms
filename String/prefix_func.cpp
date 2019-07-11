#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int* createprefix(string P)
{
    int* s = new int[P.length()];
    int border = 0;
    s[0] = 0;
    for(int i = 1; i < P.length(); i++)
    {
        while((border > 0) && (P[i] != P[border]))
            border = s[border-1];
        if(P[i] == P[border])
            border++;
        else border = 0;

        s[i] = border ;
    }
    return s;
}

int main()
{
    string P;
    cin >> P;
    int* s = createprefix(P);
    for(int i = 0; i < P.length(); i++){
        cout << s[i] << " " ;
    }
    return 0;
}
