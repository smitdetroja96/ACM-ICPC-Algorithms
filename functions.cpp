-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//GCD

ll gcd(ll a, ll b)
{
    if (!a)
        return b;

    return gcd(b%a,a);
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//POWER IN LOGN

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

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//MODULO POWER IF MOD IS A PRIME NUMBER

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

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//MODULO POWER IF MOD IS NOT A PRIME NUMBER

void EE(ll a,ll b,ll &co1,ll &co2)
{
    if(a%b==0)
    {
        co1=0;
        co2=1;
        return;
    }
    EE(b,a%b,co1,co2);
    ll temp=co1;
    co1=co2;
    co2=temp-co2*(a/b);
}

ll inverse(ll a , ll m)
{
    ll x,y;
    EE(a,m,x,y);
    if(x<0) x+=m;
        return x;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//PRIME SEIVE

bool isprime[1000005];

vector<ll> prime;

For(i,0,1000005)
{
    isprime[i] = true;
}

isprime[0] = false;
isprime[1] = false;

for(ll i = 2 ; i < 1000005; i++)
{
    if(isprime[i])
    {
        for(ll j = i; i * j < 1000005; j++)
        {
            isprime[i * j] = false;
        }
    }
}

For(i,0,1000005)
{
    if(isprime[i])
    {
        prime.pb(i);
    }
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FACTORS

vector<ll> factor(ll x)
{
    vector<ll> v;

    for(ll i = 1 ; i * i <= x ; i++)
    {
        if(x % i == 0)
        {
            v.pb(i);

            if(x / i != i)
            {
                v.pb(x/i);
            }
        }
    }

    return v;

}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//N C K

long long choose(ll n,ll k)
{
    if(k==0)  return 1;
    return (n* choose(n-1,k-1))/k;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//N C K with DP -->>>>

ll ans[1005][1005];

for(ll i = 0 ; i < 1005; i++)
{
    for(ll j = 0; j < i ; j++)
    {
        if(j == 0 || j == 1)
    }
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

fact[0] = 1;
    ifact[0] = 1;

    For(i,1,2005)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ifact[2004] = mpower(fact[2004], mod - 2, mod);

    for (ll i = 2003; i > 0; i--)
    {
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
    }

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




