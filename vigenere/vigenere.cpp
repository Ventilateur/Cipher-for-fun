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
    cout << "0xVHPhan" << endl;                               // This the key
    cout << "TiF1DKWe}[L3AXcojiMI5\\DS|_<I?cbS!^=J" << endl;  // Now find the plain text of this
}
