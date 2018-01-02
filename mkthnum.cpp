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

const int N = 1e5+5;
int n,q;
struct node
{
	int val;
	node*left,*right;
};

node*cnode(int value)
{
	node*newnode = new node;
	newnode->val = value;
	newnode->left = newnode->right = NULL;
	return newnode;
}

int op(node*l,node*r)
{
	int ret = 0;
	if(l!=NULL)
		ret += l->val;
	if(r!=NULL)
		ret += r->val;
	return ret;
}

node*newparent(node*l, node*r)
{
	node*newnode = cnode(op(l,r));
	newnode->left = l;
	newnode->right = r;
	return newnode;
}

node* init(int l = 0, int r = n)
{
	if(l == r)
		return cnode(0);
	node*root = cnode(0);
	int m = (l+r)/2;
	root->left = init(l,m);
	root->right = init(m+1,r);
	return root;
}

node*pointUpdate(node*root,int pos, int value, int l = 0, int r = n)
{
	if(r<l) return NULL;
	if(l==r)
		return cnode(value);
	int m = (l+r)/2;
	if(pos<=m)
		return newparent(pointUpdate(root->left,pos,value,l,m),root->right);
	else return newparent(root->left,pointUpdate(root->right,pos,value,m+1,r));
}
bool found;
int rangeQuery(node*rootl,node*rootr,int k,int l = 0,int r = n)
{
	int value = rootr->val - rootl->val;
	// cout<<l<< " "<<r<< " :"<<value<<" k:"<<k<<endl;
	if(k>value)
		return k-value;
	if(l==r)
	{
		found = true;
		return l;
	}
	int m = (l+r)/2;
	if(k<=value)
		k = rangeQuery(rootl->left,rootr->left,k,l,m);
	if(!found)
		k = rangeQuery(rootl->right,rootr->right,k,m+1,r);
	return k;
}

int main()
{
	cin>>n>>q;
	vector<ll>A(n);
	map<ll,int>m;
	unordered_map<int,ll>rem;
	FOR(i,0,n-1)
	{
		A[i] = rll
		m[A[i]] = 1;
	}

	int cnt = 1;
	for(auto &k: m)
	{
		if(k.second == 1)
			k.second = cnt++;
		// cout<<k.first<<" = "<<k.second<<endl;
		rem[k.second] = k.first;
	}

	node*root[n+1];
	root[0] = init();

	FOR(i,0,n-1)
	{
		root[i+1] = pointUpdate(root[i], m[A[i]], 1);
		// cout<<root[i+1]->val<< " ";
	}

	while(q--)
	{
		int l,r,x;
		l = rll
		r = rll
		x = rll
		found = false;
		int ans = rangeQuery(root[l-1],root[r],x);
		// cout<<ans<<" : "<<rem[ans]<<endl;
		cout<<rem[ans]<<endl;
	}

	return 0;
}