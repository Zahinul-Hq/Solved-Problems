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
    	int n, m;
    	cin >> n >> m;

    	vector<pair<int,int>>arr(n);
    	for(int i = 0; i < n; i++){
    		cin >> arr[i].first;
    		arr[i].second = i;
    	}

    	if(n / 2 < m){
    		cout <<  -1 << endl;
    		continue;
    	}



    	sort(arr.begin(), arr.end());

    	debug(arr);

    	if(m == 0){
    		ll sum = 0, indx = 0;
    		for(int i = n - 2; i >= 0; i--){

    			sum += arr[i].first;
    			if(sum >= arr[n - 1].first){
    				indx = i - 1;
    				break;	
    			}
    		}
    		if(sum < arr[n - 1].first){
    			cout << -1 << endl;
    			continue;
    		}
    		int l = indx + 1, r = n - 1;

	    	vector<pair<int,int>>ans;

	    	for(int i = 0; i <= indx; i++){
	    		ans.push_back({arr[i].second, arr[i + 1].second});
	    		
	    	}

	    	while(l < r){
	    		ans.push_back({arr[l++].second, arr[r].second});
	    	}


	    	cout << ans.size() << endl;

	    	for(auto i : ans){
	    		cout << i.first + 1 << " " << i.second + 1 << endl;
	    	}

	    	continue;
    		
    	}

    	int l = 0, r = n - 1;

    	vector<pair<int,int>>ans;

    	for(int i = 0; i < n - (2 * m); i++){
    		ans.push_back({arr[i].second, arr[i + 1].second});
    		l++;
    	}

    	while(l < r){
    		ans.push_back({arr[r--].second, arr[l++].second});
    	}


    	cout << ans.size() << endl;

    	for(auto i : ans){
    		cout << i.first + 1 << " " << i.second + 1<< endl;
    	}




    }
    return 0 ;

    runtime();

}
