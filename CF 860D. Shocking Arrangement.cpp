#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n, zero = 0;
    	cin >> n;
    	vector<int>arr(n, 0), ans;
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	multiset<int> pos, neg;
    	for(int i = 0; i < n; i++){
    		if(arr[i] > 0)
    			pos.insert(arr[i]);
    		else if(arr[i] < 0)
    			neg.insert(arr[i]);
    		else
    			zero++;
    	}
    	if(pos.size() == 0 && neg.size() == 0){
    		cout << "No" << endl;
    		continue;
    	}
    	for(int i = 0; i < zero; i++){
    		ans.push_back(0);
    	}

    	ll mx = *pos.rbegin() - *neg.begin();
    	ll sum = 0;
    	//cout  << mx << endl;

    	while(!pos.empty() || !neg.empty()){
    		if(!neg.empty() && abs(sum + *neg.begin()) < mx){

    			sum += *neg.begin();
    			ans.push_back(*neg.begin());
    			neg.erase(neg.begin());
    		}else{
    			sum += *pos.begin();
    			ans.push_back(*pos.begin());
    			pos.erase(pos.begin());
    		}
    	}

    	cout << "Yes" << endl;
    	for(auto i : ans){
    		cout << i << " ";
    	}
    	cout << endl;
        
    }
    return 0 ;
}
