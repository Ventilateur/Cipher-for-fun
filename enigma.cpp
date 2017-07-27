
#include <iostream>

#define l (sizeof(sys)/sizeof(*sys))

using namespace std;

string r0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string r1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
string r2 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
string r3 = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

string rC = "FVPJIAOYEDRZXWGCTKUQSBNMHL";

//string sys[] = {r0, r1, r2, r3, rC};

string sys[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
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

void roll(int i=0)
{
    if (i != 2 && sys[i+1][0] == n[i]) roll(i+1);
    sys[i+1] = sys[i+1].substr(1) + sys[i+1][0];
}

char encodeChar(char c)
{

//    if (sys[1][0] == n[0])
//    {
//        if (r2[0] == n[1])
//            sys[3] = sys[3].substr(1) + sys[3][0];
//        sys[2] = sys[2].substr(1) + sys[2][0];
//    }
//    sys[1] = sys[1].substr(1) + sys[1][0];

    roll();

    char e = c;
    for (int i = 0; i < 2 * l - 3; i++)
    {
        e = (i < l - 1 ? sys[i + 1] : sys[0])[(i < l - 1 ? sys[0] : sys[l + 2 - i]).find(e)];
    }
    /*
    e = r1[r0.find(e)]; // i = 0
    e = r2[r0.find(e)]; // i = 1
    e = r3[r0.find(e)]; // i = 2
    e = rC[r0.find(e)]; // i = 3

    e = r0[r3.find(e)]; // i = 4
    e = r0[r2.find(e)]; // i = 5
    e = r0[r1.find(e)]; // i = 6
    */
    return e;
}

string encode(string &p, int j=0)
{
    if (j == p.length()) return p;
    roll();
    for (int i=0;i<(l<<1)-3;i++) p[j]=(i<~-l?sys[-~i]:sys[0])[(i<~-l?sys[0]:sys[l-i+2]).find(p[j])];
    return encode(p, j+1);
}

int main()
{
    string a = "THISISMYLAND";
    string e;
    string f;
    //a = a.substr(1).append(a.substr(0, 1));
    setPos(sys[1], 'B');
    setPos(sys[2], 'X');
    setPos(sys[3], 'K');
    for (int i = 0; i < a.length(); i++)
    {
        e += encodeChar(a[i]);
    }
    cout << e << endl;

    setPos(sys[1], 'B');
    setPos(sys[2], 'X');
    setPos(sys[3], 'K');
    for (int i = 0; i < a.length(); i++)
    {
        f += encodeChar(e[i]);
    }
    cout << f << endl;

    setPos(sys[1], 'B');
    setPos(sys[2], 'X');
    setPos(sys[3], 'K');
    cout << encode(a) << endl;
    cout << ~-5 << endl;
}
