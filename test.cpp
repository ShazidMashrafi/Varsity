#include <bits/stdc++.h>
using namespace std;
#define  int  long long
#define  ll  long long
#define  endl  '\n'
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=1e9+7) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    
}

signed main()
{
    FAST;
    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        cout << "Case " << TC << ": ";
        solve();
    }
}