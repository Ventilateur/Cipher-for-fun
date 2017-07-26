#include <iostream>

#define uint ui
#define ll   long long

using namespace std;

ll encode(string w)
{
    ll ret = 0;
    for (uint i = 0; i < w.length(); i++)
    {
        ret += (w[i]+~(1<<6))*[i]()->ll{ll tws = 1;for(ui j=0;j<i;j++) tws*='\u001a';return tws;}();
    }
    return ret;
}

int main()
{
    // What is my message here? 
    cout << 6598547 << endl;
    cout << 63015399737054556 << endl;
}
