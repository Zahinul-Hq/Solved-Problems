#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define pb emplace_back
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
const int M =1e9+7;
const int INF = 1e18;
const int N = 1e5+5;
const pii pd= {-1,-1};
int parent[N]; //map<int,int> parent;
int siz[N];    //map<int,int> siz;
map<pair<int,int>, int>tme;
void make_set(int v) {
    parent[v]=v; siz[v]=1;
}
int find_set(int v) {
    return (v==parent[v])?v:parent[v]=find_set(parent[v]);
}
void union_sets(int a, int b, int it) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if(siz[a]<siz[b]) swap(a,b);
    parent[b] = a;
    tme[{min(a, b), max(a, b)}]=it;
    siz[a]+=siz[b]; 
    siz[b]=0; //siz.erase(b);
}
int get_size(int v){
    return siz[find_set(v)];
}
void sol()
{
    int n,q,x,y,t;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        make_set(i);
    for(int i=1;i<=q;i++)
    {
        cin>>t>>x>>y;
        if(t&1)
        {   
            union_sets(x,y,i);
        }
        else
        {
            int u=find_set(x);
            int v=find_set(y);
            if(u==v)
                cout<<tme[{min(x, y), max(x, y)}]<<'\n';
            else
                cout<<"-1\n";
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        sol();
        tme.clear();
        cout<<'\n';
    }
    return 0;
}
/*
1
5 6
1 1 2
1 2 3
1 3 4
1 5 2
2 2 5
2 1 2
*/