#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

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
	cout.tie(NULL) ;
	inout() ;

    int n, q;

    cin >> n >> q;

    vector<int>arr(q,0);
    vector<ll> pref(q + 1, 0);

    set<int>st;

    for(int i = 0; i < q; i++){
    	cin >> arr[i];
    }

    vector<ll>ans(n + 1, 0);
    vector<int>pos(n + 1 , -1);

    for(int i = 1; i <= q; i++){

    	if(pos[arr[i -  1]] == -1){

    		st.insert(arr[i - 1]);
    		pos[arr[i - 1]] = i - 1;

    	}else{

    		st.erase(arr[i - 1]);
    		ans[arr[i - 1]] += (pref[i - 1] - pref[pos[arr[i - 1]]]);

    		pos[arr[i - 1]] = -1;
    	}

    	pref[i] = pref[i - 1] + st.size();

    }

    for(auto i : st){
    	ans[i] += (pref[q] - pref[pos[i]]);

    }



    for(int i = 1; i <= n ; i++){
    	cout << ans[i] << " ";
    }

    cout << endl;
    


    return 0 ;
}
