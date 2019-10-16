//SMIT DETROJA
//201601113
//DA-IICT, Gandhinagar, India

#include <bits/stdc++.h>

using namespace std;

/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// s.order_of_key(x);           // gives order of x in the set
//find_by_order(x)

*/

#define INF 999999999999999999
#define nax 1000010
#define pi acos(-1)
#define bp __builtin_popcount
#define sp " "
#define mod 1000000007
#define mod1 998244353
#define ll long long
#define ull unsigned long long
#define ld double

#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()

#define For(i,a,b) for(ll i=a;i<b;i++)

#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define deb4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define deb5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define deb6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

ll gcd(ll a, ll b)
{
    if (!a)
        return b;

    return gcd(b%a,a);
}

ll mpower(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1){
            res = (res*x) % p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x;

        y = y>>1;
        x = x*x;
    }
    return res;
}

void precal()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
    cout<<setprecision(9);
    srand(time(NULL));

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
/*
    fact[0]=1;

    ll fact[100005];
    ll ifact[100005];

    For(i,1,100005)
    {
        fact[i] = (fact[i-1]*i) % mod1;
    }


    For(i,0,100005)
    {
        ifact[i] = mpower(fact[i],mod1-2,mod1);
    }4
*/
}

int main()
{
    precal();

    ll n;
    cin>>n;

    ll a[n];

    For(i,0,n)
    {
        cin>>a[i];
    }

    ll dp[n+1];

    memset(dp,0,sizeof dp);

    dp[1] = a[0];

    for(ll i = 2; i <= n ; i++)
    {
        dp[i] = max(dp[i-1],dp[i - 2] + a[i - 1]);
    }

    cout<<dp[n]<<endl;
    
}