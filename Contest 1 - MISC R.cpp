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
    //cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;
    	vector<int>arr(n);


    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}

    	vector<int>v1,v2,v3;
    	for(int i = 0; i < n; i++){
    		if(arr[i] > 0)
    			v2.push_back(arr[i]);
    		else if(arr[i] < 0)
    			v1.push_back(arr[i]);
    	}
    	v3.push_back(0);
    	
    	if(v2.size() == 0){
    		v2.push_back(v1.back());
    		v1.pop_back();
    		v2.push_back(v1.back());
    		v1.pop_back();

    	}
    	if(v1.size() % 2 == 0){
    		v3.push_back(v1.back());
    		v1.pop_back();	
    	}

    	cout << v1.size() << " ";
    	for(int j = 0; j < v1.size(); j++){
    		cout << v1[j] << " ";
    	}
    	cout << endl;
    	cout << v2.size() << " ";
    	for(int j = 0; j < v2.size(); j++){
    		cout << v2[j] << " ";
    	}
    	cout << endl;
    	cout << v3.size() << " ";
    	for(int j = 0; j < v3.size(); j++){
    		cout << v3[j] << " ";
    	}
    	cout << endl;
    }
    return 0 ;

    runtime();

}
