
#include <iostream>

#define UNCHANGED 1

using namespace std;

//
// This function calculate ((b^e) mod m) in an efficient (not the best, cuz it's kinda short) way, also works with big value of e
//

int expMod(int x, int b, int e, int m)
{
    return (!e)?x:expMod((e&1)?(x*b)%m:x,(b*b)%m,e>>1,m);
}

int main() 
{
    cout << expMod(UNCHANGED, 5, 498, 7) << endl;    
}
