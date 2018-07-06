
#include <iostream>

#define UNCHANGED 1
#define ll long long

using namespace std;

//
// This function calculate ((b^e) mod m) in an efficient (not the best, cuz it's kinda short) way, also works with big value of e
//

ll expMod(ll x, ll b, ll e, ll m)
{
    return !e?x:expMod(e&1?(x*b)%m:x,(b*b)%m,e>>1,m);
}

int main() 
{
    cout << expMod(UNCHANGED, 5, 498, 7) << endl;    
}
