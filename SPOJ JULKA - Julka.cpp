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

vector<int>convert(string s){

	vector<int>intgr;


	for(auto i: s){
		intgr.push_back(i - '0');
	}

	return intgr;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    string n, m;

    while (cin >> n)
    {
    	cin >> m;

        while(n.size() > m.size()){
        	m = '0' + m;
        }

        vector<int>val =  convert(n);
        vector<int>less =  convert(m);
        vector<int>ls = less;

        vector<int>ans;

        for(int i = less.size() - 1; i >= 0; i--){

        	if(less[i] > val[i]){
        		ans.push_back((10 + val[i]) - less[i]);
        		int j = i - 1;

        		while(less[j] == 9){
        			less[j] = 0;
        			j--;
        		}
        		less[j]++;
        	}else{
        		ans.push_back(val[i] - less[i]);
        	}

        }
        reverse(ans.begin(), ans.end());


        vector<int>div = ans;
        ans.clear();

        for(int i = 0; i < div.size(); i++){

        	if(div[i] % 2 != 0){

        		ans.push_back(div[i] / 2);
        		div[i + 1] += 10;

        	}else{
        		ans.push_back(div[i] / 2);
        	}
        }

        vector<int>ans1 = ans;
        ans.clear();

        vector<int>less1;

        while(less1.size() + ls.size() != ans1.size()){
        	less1.push_back(0);
        }

        for(int i = 0 ; i < ls.size() ; i++)
        	less1.push_back(ls[i]);


        for(int i = less1.size() - 1; i >= 0; i--){

        	if(less1[i] + ans1[i] > 9){
        		ans.push_back((less1[i] + ans1[i]) % 10);
        		int j = i - 1;

        		while(less1[j] == 9){
        			less1[j] = 0;
        			j--;
        		}
        		less1[j]++;
        	}else{
        		ans.push_back(ans1[i] + less1[i]);
        	}

        }
        reverse(ans.begin(), ans.end());

        bool f= 0;

        for(auto i : ans){

            if(i != 0)
                f = 1;
            if(f)
                cout << i ;
        }

        cout << endl;

        f = 0;

        for(auto i : ans1){

            if(i != 0)
                f = 1;
            if(f)
                cout << i ;
        }

        cout << endl;
        
    }
    return 0 ;
}
