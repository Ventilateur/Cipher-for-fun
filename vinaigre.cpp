#include <iostream>

#define ui unsigned int

using namespace std;

string encode(string plain, string key)
{
    string cipher = "";
    for (ui i = 0; i < plain.length(); i++)
    {
        cipher += (plain[i]+key[i%key.length()]+0x13E)%'_'+~-(1<<5);
    }
    return cipher;
}

int main()
{
    cout << "0xAbCd" << endl;                   // This the key
    cout << "do5T7O%_BQ4Zy_5J:I|_5dEf" << endl; // Now find the plain text of this
}
