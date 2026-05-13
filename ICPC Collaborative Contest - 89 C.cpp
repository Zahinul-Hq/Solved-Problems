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
bool cmp(pair<int,int> a,pair<int,int> b)
{
    bool e=a.first<=a.second;
    bool f=b.first<=b.second;
    if(e==f)
    {
        if(b.second==a.second)
            return a.first<b.first;
        else
            return a.second>b.second;
    }
    else
        return e>f;
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
    	int n, m;

    	cin >> n >> m;

    	vector<int>a(n), b(n);

    	vector<pair<int,int>>bmax, amax;




    	ll ans = 0;

    	for(int i = 0; i < n; i++){
    		cin >> a[i] >> b[i];

    		if(a[i] > b[i]){
    			amax.push_back({a[i], b[i]});
    		}
    		else
    			bmax.push_back({b[i] , a[i]});
    	}

    	if(m == 1){
    		cout << b[0] << endl;
    		continue;
    	}
    	sort(bmax.begin(), bmax.end(), cmp);
    	sort(amax.begin(), amax.end(), cmp);

    	for(int i = 0; i < (int)amax.size(); i++){
    		ans += amax[i].first;
    	}

    	int rem = m - (int)amax.size(), need = rem - (int)bmax.size(), len = (int)bmax.size();

    	debug(a, b, amax, bmax, rem, need);

    	for(int i = 0; i < need && i < len; i++){
    		ans += bmax[i].first;
    	}
    	for(int  i = need; i < len; i++){
    		ans +=  bmax[i].second;
    	}
    	if((int)amax.size() == 1 && need >= len && len > 0){
    		ans -= amax[0].first;
    		ans -= bmax[len - 1].first;
    		ans += (max((amax[0].first + bmax[len - 1].second), (amax[0].second + bmax[len - 1].first) ));
    		
    	}

    	cout << ans << endl;


    	

    	
    	

    }
    return 0 ;

    runtime();

}
