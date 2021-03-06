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

ll eval(ll n)
{
    ll s,ret = 1,till = 1;
	s=sqrt(n);
	stack<ll>primes;
  	while (n%2 == 0)
    {
             n /=2;
             primes.push(2);
    }

    for (int i=3;i <= s;i = i+2)
    {
        while (n%i ==0)
            {
                n /=i;
                primes.push(i);
            }
    }

    if (n > 2)
    {
        primes.push(n);
    }
    
    while(!primes.empty())
    {
        till = till*primes.top();
        ret += till;
        primes.pop();
    }
    return ret;
}
int main()
{
    int n;
    n = rll;
    ll ans=0;
    while(n--)
    {
        ll num; cin>>num;
            
        ans+=eval(num);
    }
            cout<<ans<<endl;
    return 0;
}
