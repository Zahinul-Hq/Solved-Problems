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
vector<ll> make_evils(ll prime, ll n)
{
	vector<ll> ret(n);
	for (ll i = 0; i < n; i++)
		ret[i] = (i + 1) * prime;
	return ret;
}
unordered_set<ll> st;
void test_evils(const vector<ll>& evils)
{
	st = unordered_set<ll>();

	clock_t start = clock();

	for (ll x : evils)
		st.insert(x);

	clock_t end = clock();

	cout << fixed;
	cout.precision(3);
	cout << "Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	cout << 10 << endl;
    for (ll i = 0; i < 10; i++)
    {
        vector<ll> evils = make_evils(26267, 26266);

        cout << evils.size() << endl;

        for(auto i : evils){
        	cout << i << " ";
        }
        cout << endl;
        for(auto i : evils){
        	cout << i << " ";
        }
        cout << endl;
        //test_evils(evils);
    }
    return 0 ;

    runtime();

}
