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
    	int n, m, x;

    	cin >> n >> m;
    	vector<int>arr(n), brr(m + n + 2, 0), freq(n + m + 2, -1);

    	set<int>st;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		st.insert(arr[i]);
    	}
    	for(int i = 0; i < m; i++){
    		cin >> x;
    		brr[x]++;
    		freq[x] = 0;
    	}
    	int alice = 0, bob = 0, both = 0;

    	for(auto i : st){
    		for(int j = i; j < (m + n + 2); j += i){
    			if(brr[j]){
    				freq[j]++;
    			}
    		}
    	}

    	debug(freq);

    	for(int i = 1; i < (n + m + 2); i++){
    		if(freq[i] == st.size()){
    			alice += brr[i];
    		}
    		if(freq[i] == 0){
    			bob += brr[i] ;
    		}
    		if(freq[i] > 0 && freq[i] < st.size()){
    			both += brr[i];
    		}
    	}

    	debug(alice, bob, both);

    	alice += ((both + 1) / 2);
    	bob += (both / 2);

    	if(alice > bob){
    		cout << "Alice" << endl;
    	}else{
    		cout << "Bob" << endl;
    	}


    }
    return 0 ;

    runtime();

}
