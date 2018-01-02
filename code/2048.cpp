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

int b[5][5];

void left()
{
    FOR(i,1,4)
    {
        queue<int>st;
        vector<int>extracted;

        FOR(j,1,4)
            if(b[i][j])
                extracted.pb(b[i][j]);

        int n = extracted.size();

        FOR(j,0,n-1)
        {
           if(j<n-1&&extracted[j]==extracted[j+1]) 
            st.push(2*extracted[j]),j=j+1;
           else st.push(extracted[j]);
        }

        FOR(j,1,4)
        {
            if(!st.empty())
            {
                b[i][j] = st.front();
                st.pop();
            }
            else b[i][j] = 0;
        }
    }
}

int lr()
{
    int c[5][5];
    int cnst = 4;

    FOR(i,1,4)
    {
        FOR(j,1,4)
        c[i][j] = b[j][cnst];
        cnst--;
    }

    FOR(i,1,4)
    FOR(j,1,4)
    b[i][j]=c[i][j];
    
}

int rr()
{
    int c[5][5];
    int cnst = 1;

    FOR(i,1,4)
    {
        FOR(j,1,4)
            c[i][j] = b[4-j+1][cnst];
        cnst++;
    }

    FOR(i,1,4)
    FOR(j,1,4)
    b[i][j]=c[i][j];
}

void up()
{
    lr(); 
    left();
    rr();
}

void right()
{
    rr();rr();
    left();      
    rr();rr();
}

void down()
{
    rr();
    left();
    lr();
}

int main()
{
    clr(b);

    FOR(i,1,4)
    FOR(j,1,4)
    cin>>b[i][j];

    int dir;
    
    cin>>dir;
    switch(dir)
    {
        case 0: left();
                break;

        case 1: up();
                break;

        case 2: right();
                break;

        case 3: down();
                break;
    }

    FOR(i,1,4)
    {
        FOR(j,1,4)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }

	return 0;
}
