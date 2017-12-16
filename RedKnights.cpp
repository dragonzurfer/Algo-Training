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


typedef int ll;

template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}


int sr,sc,dr,dc;
int n,visited[222][222];
int mindist = INT_MAX;
string minpath = "";
string bfs()
{
    queue<pair<pll,pair<int,string> > > q;
    q.push(mp(mp(sr,sc),mp(0,"")));

    while(!q.empty())
    {
        auto f = q.front(); q.pop();
        int x = f.F.F, y = f.F.S;
        int dist = f.S.F;
        string path = f.S.S;
        if(x<0||y<0||x>n-1||y>n-1)continue;
        if(visited[x][y])continue;
        if(x==dr&&y==dc){if(dist<mindist)minpath = path,mindist=dist;}
        else
        visited[x][y] = dist;
        if(dist>0)path+=" ";
        //UL
        q.push(mp(mp(x-2,y-1),mp(dist+1,path+"UL")));
        //UR
        q.push(mp(mp(x-2,y+1),mp(dist+1,path+"UR")));
        //R
        q.push(mp(mp(x,y+2),mp(dist+1,path+"R")));
        //LR
        q.push(mp(mp(x+2,y+1),mp(dist+1,path+"LR")));
        //LL
        q.push(mp(mp(x+2,y-1),mp(dist+1,path+"LL")));
        //L
        q.push(mp(mp(x,y-2),mp(dist+1,path+"L")));
    }
visited[dr][dc] = mindist;
return minpath;
}

int main()
{
    cin>>n;
    cin>>sr>>sc>>dr>>dc;
    int rdiff = abs(dr - sr);
    clr(visited);

    string ans = bfs();
    if(ans=="")
    {
        cout<<"Impossible";
        exit(0);
    }
    cout<<visited[dr][dc]<<endl;
    cout<<minpath;
	return 0;
}
