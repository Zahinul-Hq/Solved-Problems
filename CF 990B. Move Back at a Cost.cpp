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

    	vector<int>arr(n), trr, ans1;
    	map<int,int>mp;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		mp[arr[i]]++;
    	}

    	for(auto i : mp)trr.push_back(i.first);

    	multiset<int>ans2;


    	int j = 0;
    	for(int i = 0; i < n; i++){

    		if(trr[j] == arr[i] && (*ans2.begin() >= trr[j] || ans2.empty())){
    			ans1.push_back(trr[j]);
    			mp[trr[j]]--;
    			if(mp[trr[j]] == 0)
    				while(mp[trr[j]] == 0 && j < (int) trr.size())j++;

    		}else{
    			mp[arr[i]]--;
    			ans2.insert(arr[i] + 1);
    		}

    	}



    	for(auto i : ans1)cout << i << " ";

    	for(auto i : ans2)cout << i << " ";

    	cout << endl;
    }	
    return 0 ;

    runtime();

}
