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
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second <= b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    int n;
    while (cin >> n)
    {
    	
    	int x, y;
    	vector<int>temp, arr(n), lisdp(n), ldsdp(n);
    	
    	for(int i = 0; i < n; i++){
    	   	cin >> arr[i];
    	}

        for(int i = 0; i < n; i++){
    	    int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
    
    	        if(pos == temp.size() ){
    	            temp.push_back(arr[i]);
    	            
    	        }else{
    	        	temp[pos] = arr[i];
    	        }
                lisdp[i] = temp.size();
    	}  
        temp.clear();
        for(int i = n - 1; i >= 0 ; i--){
            int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
    
            if(pos == temp.size() ){
                temp.push_back(arr[i]);   
            }else{
                temp[pos] = arr[i];
            }
            ldsdp[i] = temp.size();
        }
        int ans = 0;    
        for(int i = 0; i  < n; i++){
            ans = max(ans, min(ldsdp[i], lisdp[i]) * 2 - 1);
        }
        cout << ans << endl; 
    }

    return 0 ;

    runtime();

}
