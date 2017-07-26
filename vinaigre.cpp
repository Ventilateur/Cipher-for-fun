#include <iostream>

#define ui unsigned int
#define s  string
#define l  length

using namespace std;

s encode(s p, s k)
{
    return [&p,k]()->s{for(ui i=0;i<p.l();i++)p[i]=(p[i]+k[i%k.l()]+0x13E)%'_'+~-(1<<5);return p;}();
}

int main()
{
    cout << "0xAbCd" << endl;                   // This the key
    cout << "do5T7O%_BQ4Zy_5J:I|_5dEf" << endl; // Now find the plain text of this
}
