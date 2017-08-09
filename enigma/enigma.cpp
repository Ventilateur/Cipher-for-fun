#include <iostream>

#define l (sizeof(e)/sizeof(*e)-1)
#define s string

using namespace std;

s e[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ","EKMFLGDQVZNTOWYHXUSPAIBRCJ",
         "AJDKSIRUXBLHWTMCQGZNPYFVOE","BDFHJLCPRTXVZNYEIWGAKMUSQO",
         "FVPJIAOYEDRZXWGCTKUQSBNMHL","CJFBXK"};

void set(int i=1)
{
    if(i%3)set(-~i);e[i]=e[i].substr(e[i].find(e[l][i+2])).append(e[i].substr(0,e[i].find(e[l][i+2])));
}

void roll(int i=1)
{
    if(i%3&&e[i][0]==e[l][~-i])roll(-~i);e[i]=e[i].substr(1)+e[i][0];
}

s encode(s p, int j=0)
{
    if(!j)set();if(j==p.length())return p;roll();
    return encode([&p,j]()->s{for(int i=0;i<(l<<1)-3;i++)p[j]=(i<~-l?e[-~i]:e[0])[(i<~-l?e[0]:e[l-i+2]).find(p[j])];
    return p;}(),-~j);
}

int main()
{
    cout << "NGOZHGZKGRS" << endl;  // Try Kevin! Break my code!
}
