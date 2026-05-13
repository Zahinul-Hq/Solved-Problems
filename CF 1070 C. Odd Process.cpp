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
    	int n;
    	cin >> n;

    	vector<ll>arr(n), ev, odd, ans(n, 0);

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		if(arr[i] % 2 == 0)
    			ev.push_back(arr[i]);
    		else
    			odd.push_back(arr[i]);
    	}

    	if(odd.size() == 0){
    		for(int i = 0; i < n; i++){
    			cout << 0 << " ";
    		}
    		cout << endl;
    		continue;
    	}

    	sort(odd.rbegin(), odd.rend());
    	sort(ev.rbegin(), ev.rend());

    	int j = 0, odd_cnt =(int) odd.size();

    	ans[j] = odd[0];
    	j++;
    	odd_cnt--;

    	for(int i = 0; i <(int)ev.size(); i++){
    		ans[j] = ans[j - 1] + ev[i];
    		j++;
    	}
    	if(j == 1){
    		j++;
    	}
        if(odd_cnt % 2 == 1){
            n--;
        }

    	debug(arr, ev, odd, j, ans);

    	for(int i = j; i < n; i++){
    		ans[i] = ans[i - 2];
                
    	}


    	for(auto val : ans){
    		cout << val << " ";
    	}
    	cout << endl;





    }
    return 0 ;

    runtime();

}
