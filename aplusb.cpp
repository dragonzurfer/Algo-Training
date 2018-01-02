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
#define RFOR(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#define gc getchar
#define pc putchar


typedef long long ll;
constexpr long double PI = 3.1415926535897932384626433;

template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

 typedef complex < double > base ;
 
void fft(vector<base>&a, bool invert) {
    ll n = (ll) a.size();
    if (n == 1)  return;
 
    vector<base> a0(n/2), a1(n/2);
    for (ll i = 0, j = 0; i < n; i += 2, ++j){
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft ( a0, invert ) ;
    fft ( a1, invert ) ;
 
    double ang = 2 * PI/n * ( invert ? - 1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for(ll i = 0; i < n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert)
            a [i] /= 2,  a [i + n/2] /= 2;
        w *= wn;
    }
} 

void multiply (const vector <ll> &a, const vector <ll> &b, vector<ll> &res) {
    vector <base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    size_t n = 1;
    while(n < max(a.size(), b.size())) n <<= 1;
    n <<= 1 ;
    fa.resize(n), fb.resize(n);
 
    fft(fa, false), fft(fb, false);
    for(size_t i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);
 
    res.resize(n);
    for (size_t i = 0; i < n; ++i)
        res[i] = ll(fa [i].real() + 0.5);
} 

vector<ll> pow(vector<ll> &v, ll k)
{
    vector<ll> res;

    if(k==1)
        return v;

    res = pow(v,k/2);
    multiply(res,res,res);

    if(k%2)
    {
        multiply(res,v,res);
    }
    return res;
}

int checker(vll a)
{
    int n = a.size();
    int ans = 0;
    map<int,int> cnt;
    FOR(i,0,n-1)
    {
        FOR(j,0,n-1)
        {
            if(i!=j)
            FOR(k,0,n-1)
            {
                if(k!=i&&k!=j)
                {
                    if(a[i]+a[j] == a[k])
                    {
                            ans++;
                            cnt[a[k]]++;
                    }
                }
            }
        }
    }
    for(auto x:cnt)
        cout<<x.S<<"("<<x.F<<") ";
    cout<<endl;
    return ans;
}

int main()
{
    ll n;cin>>n;
    ll temp,maxi=50000,mini=-50000;

    vector<ll>v,t;
    unordered_map<ll,ll>m;
    bool zero = false;
    FOR(i,1,n)
    {
        cin>>temp;
        if(!zero&&temp==0)zero = true;
        t.pb(temp);
        m[temp]++;
    }

    ll start = -2*50000; 
    FOR(i,mini,maxi)
    {
        if(i==0){v.pb(0);continue;}

        if(m[i]>0)
        { 
            v.pb(m[i]);
        }
        else v.pb(0);
    }


    vll res;
    ll ans = 0;

    multiply(v,v,res);

    n = res.size();
    for(int i = 0, j = start; i < n; i++,j++)
    {
        if(m[j]>0)
        {
            if(j%2==0)
            {
                if(j==0)continue;
                    ans += (res[i]-m[j/2])*(m[j]);
            }
            else
                ans += res[i]*m[j];
        }
    }

    ll zerocnt=0;
    if(zero)
    {
        zerocnt = (m[0]-1)*(m[0]-2)*m[0];
        FOR(i,1,50000)
        {
            zerocnt += 2*m[0]*(m[i]*(m[i]-1));
            zerocnt += 2*m[0]*(m[-i]*(m[-i]-1));
            zerocnt += 2*m[0]*(m[-i]*m[i]);
        }
    }

    ans += zerocnt;
    cout<<ans<<endl;
    
    return 0;
}