#include <iostream>

#define ui unsigned int
#define s  string
#define l  length

using namespace std;

s encode(s p, s k)
{
    return [&p,k]()->s{for(ui i=0;p[i];i++)p[i]=(p[i]+k[i%k.l()]-'@')%'_'+' ';return p;}();
}

s decode(s p, s k)
{
    return [&p,k]()->s{for(ui i=0;p[i];i++)p[i]=(p[i]-k[i%k.l()]+(p[i]>k[i%k.l()]?false:'_'))%'_'+' ';
    return p;}();
}

int main()
{
    string p = "Well hello there little coder ~~~!!!";
    string k = "A_Key";
    string e = encode(p, k);
    cout << e << endl;
    cout << decode(e, k) << endl;
}
