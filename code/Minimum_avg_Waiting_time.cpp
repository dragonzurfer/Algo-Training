#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
typedef long long ll;
using namespace std;

struct Customer{
    ll AT,CT;
}customers[100005];

int N;

struct cmp {
  bool operator ()(Customer a, Customer b)
  {
      if(a.CT == b.CT)
          return a.AT>b.AT;
      return a.CT>b.CT;
  }
};

bool operator < (Customer a, Customer b)
{
    return a.AT < b.AT;
}

ll CT = 0, TT = 0;
priority_queue<Customer, vector<Customer>, cmp> heap;
void add_order(Customer A)
{
    if(heap.empty())
        CT = max(A.AT,CT);
    heap.push(A);
}

ll serve_order()
{
    auto order = heap.top();
    heap.pop();
    CT += (order.CT );
    
    return CT - order.AT;
}

void solve()
{
    FOR(i,0,N-1)
    {
        if( i == 0 || customers[i].AT <= CT )
        {
            add_order(customers[i]);
        } else if(!heap.empty()) {
            while(!heap.empty()&&customers[i].AT>CT)
                TT += serve_order();
            add_order(customers[i]);
        }
    }
    while(!heap.empty())
        TT += serve_order();
    cout<<TT/N;
}

int main()
{
    cin>>N;
    FOR(i,0,N-1)
        cin>>customers[i].AT>>customers[i].CT;
    sort(customers,customers+N);
    solve();
    return 0;
}
