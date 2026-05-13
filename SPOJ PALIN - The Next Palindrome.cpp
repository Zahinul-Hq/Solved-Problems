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
void palindrome(vector<int> &val){
	int n = val.size();
	int mid = n / 2;
	int i = mid - 1;
	int j = (n % 2) ? mid + 1 : mid;
	bool leftsmall = false;

	while( i >= 0 && val[i] == val[j])
		i--,j++;

	if(i < 0 || val[i] < val[j])
		leftsmall = true;

	while(i >= 0)
		val[j++] = val[i--];

	if(leftsmall){

		int carry = 1;
		i = mid - 1;
		if(n % 2){

			val[mid] += carry;
			carry = val[mid] / 10;
			val[mid] = val[mid] % 10;
			j = mid + 1;

		}
		else
			j = mid;

		while(i >= 0 ){

			val[i] += carry;
			carry = val[i] / 10;
			val[i] %= 10;
			val[j++] = val[i--];
		}

		
	}

	for(auto i : val){
			cout << i;
	}
	cout << endl;

	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        string s;

        cin >> s;

        vector<int>val;

        bool all9 = true;
        bool all0 = true;

        for(int i = 0; i < s.size(); i++){
        	val.push_back(s[i] - '0');
        	if(val[i] != 9)
        		all9 = false;
        	if(val[i] != 0)
        		all0 = false;
        }

        if(all9){

        	cout << 1;
        	for(int i = 1; i < s.size() ;i++){
        		cout << 0;
        	}
        	cout << 1 << endl;

        }else if(all0){

        	cout << 1;
        	for(int i = 1; i < s.size() - 1 ;i++){
        		cout << 0;
        	}
        	cout << 1 << endl;
        	
        }else{
        	palindrome(val);
        }
    }
    return 0 ;
}
