
#include <iostream>

#define l (sizeof(e)/sizeof(*e))
#define s string

using namespace std;

string r0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string r1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
string r2 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
string r3 = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

string rC = "FVPJIAOYEDRZXWGCTKUQSBNMHL";

string e[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
              "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
              "AJDKSIRUXBLHWTMCQGZNPYFVOE",
              "BDFHJLCPRTXVZNYEIWGAKMUSQO",
              "FVPJIAOYEDRZXWGCTKUQSBNMHL"};

char p1 = 'B', p2 = 'X', p3 = 'K';
char n1 = 'C', n2 = 'J', n3 = 'F';

char n[] = {'C', 'J', 'F'};


void setPos(string &r, char p)
{
    r = r.substr(r.find(p)).append(r.substr(0, r.find(p)));
}

void roll(int i=1)
{
    if (i != 3 && e[i][0] == n[i-1]) roll(-~i);
    e[i] = e[i].substr(1) + e[i][0];
}



string encode(string p, int j=0)
{
    if (j == p.length()) return p;
    roll();
    return encode([&p,j]()->string{for(int i=0;i<(l<<1)-3;i++)p[j]=(i<~-l?e[-~i]:e[0])[(i<~-l?e[0]:e[l-i+2]).find(p[j])];return p;}(),-~j);
}

int main()
{
    string a = "THISISMYLAND";

    setPos(e[1], 'B');
    setPos(e[2], 'X');
    setPos(e[3], 'K');
    string b = encode(a);
    cout << b << endl;

    setPos(e[1], 'B');
    setPos(e[2], 'X');
    setPos(e[3], 'K');
    cout << encode(b) << endl;
}
