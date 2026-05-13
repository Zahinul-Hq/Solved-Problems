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

    int x;
    vector<int>arr;
    while(cin >> x){
    	arr.push_back(x);
    }
    int n = arr.size(), max_len = 1, lastIndex = n - 1;
    vector<int> dp(n , 1), lis;
    map<int,int>prev, ID;
    for(int i = 1; i < n; i++){
    	for(int j = 0; j < i; j++){
    		if(arr[j] < arr[i] && dp[i] <= dp[j] + 1){
    			dp[i] = dp[j] + 1;
    			prev[i] = j;
    		}
    	}
    	if(dp[i] >= max_len){
		    lastIndex = i;
		   	max_len = dp[i];
		}
    }

    while(lastIndex != -1){
    	lis.push_back(arr[lastIndex]);
    	lastIndex = prev[lastIndex];
    }

    cout << lis.size() << endl << "-" << endl;

    for(int i = lis.size() -1; i >= 0; i--){
    	cout << lis[i] << endl;
    }

    vector<int>temp;
    

    for(int i = 0; i < n; i++){
        int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
        ID[arr[i]] = i;

        if(pos >= temp.size() - 1)
            lastIndex = i;

        if(pos == temp.size()){
            temp.push_back(arr[i]);
            
        }else{
            temp[pos] = arr[i];
        }
        
        prev[i] = pos ? ID[temp[pos - 1]] : -1;

    }

    while(lastIndex != -1){
        lis.push_back(arr[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    cout << lis.size() << endl << "-" << endl;

    for(int i = lis.size() -1; i >= 0; i--){
        cout << lis[i] << endl;
    }
    return 0 ;

    runtime();

}
