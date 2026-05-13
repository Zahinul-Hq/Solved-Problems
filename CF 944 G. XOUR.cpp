#include<bits/stdc++.h>
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

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n ;

        cin >> n;

        vector<int> arr(n,0);

        map<int,priority_queue<int>>mp;
        map<int,int>mp_pos;

        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        	mp[arr[i]].push(i);
        	mp_pos[arr[i]]++;
        }

        /*for(auto i : mp){
        	for(auto j : i.S){
        		cout << j << " ";
        	}

        	cout << endl;
        }*/

        for(int i = 0; i < n; i++){

        	ll s_val = inf; int pos = -1;
        	for(int j = 1; j <= 3; j++){

        		int val = arr[i] ^ j;

        		if(mp_pos[val] <= 0)
        			continue;

        		/*cout << arr[i] << " " << val << " " << mp_pos[val] <<  "   ";

        		for(int l = 0; l < temp.size(); l++){
        			cout << temp[l] << " ";
        		}*/

        		

        		if(mp[val].size() > 0  && arr[i] > val){
        			if(val < s_val && mp[val].top() > i){
                        pos = mp[val].top();
                        
                        //cout << pos ;
        				s_val = val;
        			}
        		}

                //cout << endl;
        		
        	}

        	if( pos > i ){
        		mp[s_val].pop();
                mp[arr[i]].push(pos);
        		swap(arr[i], arr[pos]);



        		//cout << arr[i] << " " << arr[pos] << endl;
        	}
        }


       	for(auto i : arr){
        	cout << i << " ";
        }

        cout << endl;
    }
    return 0 ;
}
