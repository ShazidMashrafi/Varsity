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
    // int n;
    // cin >> n;
    // int mx = -1, smx = -2, ans = -1, ind = -1;
    // for(int i = 0; i < n; ++i)
    // {
    //     int x;
    //     cin >> x;
    //     if(x>mx)
    //     {   
    //         smx = mx; 
    //         mx = x;
    //         ans = ind;
    //         ind = i + 1;
    //     }
    //     else if(x>smx)
    //     {    
    //         smx = x;
    //         ans = i + 1;
    //     }
    // }
    // cout << ans << endl;

    // int n;
    // cin >> n;
    // vector<pair<int, int>> v;
    // for(int i = 0; i < n; ++i)
    // {
    //     int x;
    //     cin >> x;
    //     v.push_back({x,i+1});
    // }
    // sort(all(v));
    // cout << v[v.size()-2].ss << endl;

    // int n;
    // cin >> n;
    // map<int, int> m;
    // for(int i = 0; i < n; ++i)
    // {
    //     int x;
    //     cin >> x;
    //     m[x] = i + 1;
    // }
    // auto it = m.rbegin();
    // cout << (++it)->second << endl;
    // dbg(m);

    // int n;
    // cin >> n;
    // priority_queue<pair<int, int>> pq;
    // for(int i=0; i<n; ++i)
    // {
    //     int x;
    //     cin >> x;
    //     pq.push({x, i+1});
    // }
    // pq.pop();
    // cout << pq.top().second << endl;
}

signed main()
{
    FAST;
    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}