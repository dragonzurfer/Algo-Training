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
const int N = 1001, M = 1001;
int marking[N][M],g[N][M];
int n,m;

int check(int x, int y, int val)
{
    if(x<1||y<1||x>n||y>m)return 0;

    if(g[x][y]==val)return 1;

    return 0;
}
int marker=1;
void bfs(pair<int,int>start)
{
    queue<pair<int,int> > q;
    q.push(start);

    while(!q.empty())
    {
        auto f = q.front(); q.pop();
        if(marking[f.F][f.S]!=0)continue;
        marking[f.F][f.S]=marker;
        int x = f.F, y = f.S;
        int val = g[x][y];

        if(check(x-1,y,val))
            q.push(mp(x-1,y));

        if(check(x+1,y,val))
            q.push(mp(x+1,y));

        if(check(x,y-1,val))
            q.push(mp(x,y-1));

        if(check(x,y+1,val))
            q.push(mp(x,y+1));


    }
    marker++;
}

int main()
{
    clr(marking);
	cin>>n>>m;
    char c;
    FOR(i,1,n)
    FOR(j,1,m)
    {
        cin>>c;
        g[i][j] = c - '0';
    }
    FOR(i,1,n)
    FOR(j,1,m){
        if(marking[i][j]==0)
            bfs(mp(i,j));
    }

    int q;cin>>q;
    //FOR(i,1,n){
    //    FOR(j,1,m)
    //        cout<<marking[i][j];
    //    cout<<endl;
    //}

    while(q--)
    {
        int r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        if(marking[r1][c1]!=marking[r2][c2])
            cout<<"neither";
        else{
            if(g[r1][c1])
                cout<<"decimal";
            else cout<<"binary";
        }
        cout<<endl;
    }
	return 0;
}
