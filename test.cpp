#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second
#define tc int tc;cin >> tc; while(tc--) 

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{    
    #ifndef ONLINE_JUDGE
        freopen("input.txt" ,"r" , stdin);
        freopen("output.txt" , "w" ,stdout);
        cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
    #endif
}
 

 
const int N = 2e5 + 5;
int n, m, a[N], b[N];
map <char, int> mp;
map <int, char> mpp;
string v;

int main() {
    inout();
 ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
tc { 
 cin >> n;
 for (int i = 0; i < n; i++)
  cin >> a[i];
 cin >> m;
 for (int i = 0; i < m; i++) {
  cin >> v;
  if (v.size() != n) {
   cout << "NO\n";
   continue;
  }
  bool ff = 1;
  mp.clear();
  mpp.clear();
  for (int i = 0; i < n; i++) {
   if (mp.count(v[i]))
    if (mp[v[i]] != a[i])
     ff = 0;
   if (mpp.count(a[i]))
    if (mpp[a[i]] != v[i])
     ff = 0;
   mp[v[i]] = a[i];
   mpp[a[i]] = v[i];
  }
  if (ff)
   cout << "YES\n";
  else
   cout << "NO\n";
 }
}}
