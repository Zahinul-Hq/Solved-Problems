#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int N = 1e5 + 9;
pair<int , int> pw1[N] ,pw2[N] ;
int ip1 ,ip2 ;

int bigmod(long long n, long long k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}
void prec() {
  pw1[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw1[i].first = 1LL * pw1[i - 1].first * p1 % mod1;
    pw1[i].second = 1LL * pw1[i - 1].second * p2 % mod2;
  }
  ip1 = bigmod(p1, mod1 - 2, mod1);
  ip2 = bigmod(p2, mod2 - 2, mod2);
  pw2[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw2[i].first = 1LL * pw2[i - 1].first * ip1 % mod1;
    pw2[i].second = 1LL * pw2[i - 1].second * ip2 % mod2;
  }
}
pair<int, int> string_hash(string s) {
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * s[i] * pw1[i].first % mod1;
    hs.first %= mod1;
    hs.second += 1LL * s[i] * pw1[i].second % mod2;
    hs.second %= mod2;
  }
  return hs;
}

pair<int,int>pref[N] ;

void build(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pref[i].first = 1LL * s[i] * pw1[i].first % mod1;
    if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
    pref[i].second = 1LL * s[i] * pw1[i].second % mod2;
    if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
  }
}

pair<int, int> get_hash(int i, int j) {
  assert(i <= j);
  pair<int, int> hs({0, 0});
  hs.first = pref[j].first;
  if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
  hs.first = 1LL * hs.first * pw2[i].first % mod1;
  hs.second = pref[j].second;
  if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
  hs.second = 1LL * hs.second * pw2[i].second % mod2;
  return hs;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;
	prec();
  string a, b; cin >> a >> b;
  build(a);
  int ans = 0, n = a.size(), m = b.size();
  auto hash_b = string_hash(b);
  for (int i = 0; i + m - 1 < n; i++) {
    ans += get_hash(i, i + m - 1) == hash_b;
  }
  cout << ans << '\n';
    
    return 0 ;
}
