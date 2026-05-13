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

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
struct node
{
	ll total_size,prev_total_size, range_size, p;
};
string flip(string s){
	for(int i = 0; i < s.size(); i++){
		s[i] = s[i] == '0' ? '1' : '0';
	}
	return s;
}
string rev(string s){
	reverse(s.begin(), s.end());
	return s;
}
node sizeCanBe(ll sz, ll lim){
	int i = 1;
	ll total_size = sz;
    while(total_size < lim){
        sz *= 3;
        total_size += sz;
        i++;
    }
    return {total_size, total_size - sz, sz, i};
}
vector<int> prefix_sum(string s){
	vector<int> pre_sum(s.size() + 1, 0);
	for(int i = 1; i <= s.size(); i++){
		pre_sum[i] = pre_sum[i - 1] + (s[i - 1] == '1');
	}
	return pre_sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases , cs = 1;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        string s;
        cin >> s;
        ll q, l, r; cin >> q;
        string fr = rev(flip(s));
        string rv = rev(s);
        string f = flip(s);
        int n = s.size();

      

        ll cnt1 = count(s.begin(), s.end(), '1');
        ll cnt0 = count(s.begin(), s.end(), '0');

        vector<int>s_pref = prefix_sum(s), fr_pref = prefix_sum(fr), rv_pref = prefix_sum(rv), f_pref = prefix_sum(f);

        cout << "Case " << cs++ << ": " << endl;

       	while(q--){

       		cin >> l >> r;
       		node left = sizeCanBe(n, l);
       		node right = sizeCanBe(n, r);
       		ll x = (left.total_size - l + n) / n;
       		ll y = (r - right.prev_total_size + n - 1) / n;
       		int l_mod = (l % n == 0) ? n : (l % n);
       		int r_mod = (r % n == 0) ? n : (r % n);
       		ll tot = 0;

       		//cout << x << endl;

       		//cout << left.p << " " << right.p << " " << x << " " << y << endl;


       		if(left.p % 2 == 0){
       			if(x % 2 == 1){
       				tot += (rv_pref[n] - rv_pref[l_mod - 1]);
       			}else{
       				tot += (f_pref[n] - f_pref[l_mod - 1]);
       			}
       		}else{
       			if(x % 2 == 1){
       				tot += (s_pref[n] - s_pref[l_mod - 1]);
       			}else{
       				tot += (fr_pref[n] - fr_pref[l_mod - 1]);
       			}
       		}
       		//cout << tot << endl;
       		if(right.p % 2 == 0){
       			if(y % 2 == 1){
       				tot += (rv_pref[r_mod]);
       			}else{
       				tot += (f_pref[r_mod]);
       			}
       		}else{
       			if(y % 2 == 1){
       				tot += (s_pref[r_mod] );
       			}else{
       				tot += (fr_pref[r_mod]);
       			}
       		}
       		x--, y--;

       		if(left.p == right.p){

       			if(r - l + 1 <= n && l_mod <= r_mod){
       				if(left.p % 2 == 0){

		       			if((x + 1) % 2 == 1){
		       				tot = (rv_pref[r_mod] - rv_pref[l_mod - 1]);
		       			}else{
		       				tot = (f_pref[r_mod] - f_pref[l_mod - 1]);
		       			}
		       		}else{
		       			if((x + 1) % 2 == 1){
		       				tot = (s_pref[r_mod] - s_pref[l_mod - 1]);
		       			}else{
		       				tot = (fr_pref[r_mod] - fr_pref[l_mod - 1]);
		       			}
		       		}
       			}else{
       				ll block = left.range_size / n;
	       			block = block - x;
	       			y = y - block;

	       			if( (x + 1) % 2 == 1){
	       				tot += (((y / 2) * cnt1) + (((y + 1) / 2) * cnt0));
	       			}else{
	       				tot += (((y / 2) * cnt0) + (((y + 1) / 2) * cnt1));
	       			}
       			}
       			
       		}else{
       			tot += (((x / 2) * cnt0) + (((x + 1) / 2) * cnt1));
	       		tot += (((y / 2) * cnt0) + (((y + 1) / 2) * cnt1));

	       		ll l_size = left.range_size * 3 , r_size = right.range_size;

	       		while(l_size < r_size){
	       			tot += ((l_size / (n * 2)) * cnt0) + (((l_size + (2 *n - 1 )) / (2 * n)) * cnt1);
	       			l_size *= 3;
	       		}

       		}
       		
       		cout << tot << endl;
       	
       	}
    }
    return 0 ;
}
