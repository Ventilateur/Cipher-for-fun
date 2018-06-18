#include <iostream>

#define ui unsigned int
#define s  string
#define l  length()

using namespace std;

s encode(s p, s k, ui i=0)
{
    if(!p[i])return p;
    p[i]=(p[i]+k[i%k.l]-'@')%'_'+' ';
    return encode(p,k,-~i);
}

s decode(s p, s k, ui i=0)
{
    if(!p[i])return p;
    p[i]=(p[i]-k[i%k.l]+(p[i]>k[i%k.l]?false:'_'))%'_'+' ';
    return decode(p,k,-~i);
}

int main()
{
    string p = "Well hello there little coder ~~~!!!";
    string k = "A_Key";
    string e = encode(p, k);
    
    cout << e << endl;
    cout << decode(e, k) << endl;
}
