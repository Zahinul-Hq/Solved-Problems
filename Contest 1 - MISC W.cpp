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


    int test_cases = 1 ;
    // cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;
    	vector<int>arr(n), v1, v2;
    	map<int,int>mp;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		mp[arr[i]]++;
    	}

    	for(auto i : mp){
    		if(i.S >= 2)
    			v2.push_back(i.F);

    		v1.push_back(i.F);
    	}

    	if(v2.size() > 0 && v2[v2.size() - 1] == v1[v1.size() - 1]){
    		v1.pop_back();
    	}


    	cout << v1.size() + v2.size() << endl;

    	if(v2.size() == 0){
    		reverse(v1.begin(), v1.end());

    		for(int i = 0; i < v1.size(); i++){
    			cout << v1[i] << " ";
    		}
    		cout << endl;
    	}else{
    		reverse(v2.begin(), v2.end());
    		for(int i = 0; i < v1.size(); i++){
    			cout << v1[i] << " ";
    		}
    		for(int i = 0; i < v2.size(); i++){
    			cout << v2[i] << " ";
    		}
    		cout << endl;
    		


    	}


    }
    return 0 ;

    runtime();

}
