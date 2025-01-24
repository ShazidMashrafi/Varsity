#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define  int  long long
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  ins  insert
#define  pb  push_back
#define  ppb  pop_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  rep(i,a,b)  for(int i=a; i<b; ++i)
#define  rrep(i,a,b) for(int i=a; i>=b; --i)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll pow(ll x,ll y,ll m=1e9+7) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    // int a, b, c, d;
    // cin >> a >> b >> c >> d;
    // if((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
    //     cout <<"YES" << endl;
    // else
    //     cout << "NO" << endl;
    
    // int sides[4];
    // for(int i = 0; i < 4; ++i)
    //     cin >> sides[i];
    // sort(sides, sides + 4);
    // if(sides[0] == sides[1] && sides[2] == sides[3])
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a ^ b ^ c ^ d)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

signed main()
{
    FAST;
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}