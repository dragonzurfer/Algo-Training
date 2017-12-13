#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define vll vector<ll>
#define G vector<vll >
#define F first
#define S second
#define pll pair<ll,ll>
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#define gc getchar
#define pc putchar


typedef long long ll;

template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

ll mod = 1e9+7;

ll power(ll x,  ll y)
{
	ll res = 1;      
	x = x % mod;  
	                  
	while (y > 0)
	{
	  if (y & 1)
	  res = (res*x) % mod;
	                   
	   y = y>>1; 
	   x = (x*x) % mod;  
	}
	return res;
}

int main()
{
    string s;
    cin>>s;
    vector<int>normal;
    ll qmarkn=0,n=s.length(),zerostillnow=0,onestillnow=0;
    vector<int>zeroscnt(n),onescnt(n);

    FOR(i,0,n-1)
    {
        if(s[i]=='1')onestillnow++;
        if(s[i] == '1' || s[i] == '0')
            normal.pb((s[i]-'0'));
        else qmarkn++;
        onescnt[i] = onestillnow;
    }

    RFOR(i,n-1,0)
    {
        zeroscnt[i] = zerostillnow;
        if(s[i]=='0')
            zerostillnow++;
    }

    ll cnt=0,sec=0,fir=0;
    RFOR(i,qmarkn-1,1)
    {
        ll temp1 = power(2,i-1);
        ll temp2 = power(2,cnt);
        sec = (sec%mod + ((i%mod*(temp1%mod*temp2%mod)%mod)%mod)%mod  )%mod;
        cnt++;
    }

    ll thir = 0;
    RFOR(i,n-1,0)
    {
        if(s[i] == '?')
        {
            ll temp = power(2,qmarkn-1);
            thir = ( thir%mod + ( (onescnt[i]%mod*temp%mod)%mod )%mod + ( (zeroscnt[i]%mod*temp%mod)%mod )%mod )%mod;
        }
    }
 
    zerostillnow=0;
    n = normal.size();
    RFOR(i,n-1,0)
    {
        if(normal[i] == 0)
            zerostillnow++;
        else fir = (fir%mod + zerostillnow%mod)%mod;
    }
    fir = ((fir%mod*power(2,qmarkn)%mod)%mod);

    ll ans = (sec%mod + fir%mod + thir%mod)%mod;
    cout<<ans<<endl;
    return 0;
}
