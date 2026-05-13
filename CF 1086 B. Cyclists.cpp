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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n, k, p, m;

    	cin>>n>>k>>p>>m;
		F(i,1,n) cin>>a[i];
		multiset<int> opt;
		F(i,1,k-1) opt.insert (a[i]);
		F(i,k,p-1) {
			opt.insert (a[i]);
			m-=*opt.begin ();
			opt.erase (opt.begin ());
		}
		m-=a[p];
		if (m<0) {
		    cout<<0<<"\n";
		    return;
		}
		ll sum=a[p];
		opt.clear ();
		F(i,1,n) {
			if (i!=p) opt.insert (a[i]);
		}
		F(i,1,n-k) {
			sum+=*opt.begin ();
			opt.erase (opt.begin ());
		}
		cout<<1+m/sum<<"\n";




    	

    	cout << (m / (sum2)) + 1 << endl;

    }
    return 0 ;

    runtime();

}
