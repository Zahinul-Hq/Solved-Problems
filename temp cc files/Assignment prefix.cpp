#include<bits/stdc++.h>
using namespace std ;

int precedence(char ch ){

    if(ch=='^')
        return 5 ;
    else if(ch=='*'|| ch=='/')
        return 4 ;
    else if(ch=='+'||ch=='-')
        return 3;
    else
        return -1 ;

}
string rev(string ss){

    reverse(ss.begin(), ss.end());

    for (int i = 0; i < ss.size(); i++) {

        if (ss[i] == '(')
                ss[i] = ')';

        else if (ss[i] == ')')
                ss[i] = '(';

    }

    return ss;
}

int main(){

    string inp , postfix="" ;
    stack<char>st;
    cin>>inp ;

    string input=rev(inp);




    for(int i=0 ; i<input.size() ; i++){

        char symbol = input[i] ;
        if(symbol>='A' && symbol<='Z'){
            postfix+=symbol;
        }
        else if(symbol=='('){
            st.push(symbol);
        }
        else if(symbol==')'){
            while(st.top()!='(' && !st.empty()){
                postfix+=st.top() ;
                st.pop() ;
            }
            if(!st.empty())
                st.pop() ;
        }
        else if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^'){
            while(!st.empty()&& precedence(symbol)<=precedence(st.top())){
                postfix=postfix+st.top() ;
                st.pop();
            }
            st.push(symbol);
        }
    }

    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }

    reverse(postfix.begin() , postfix.end()) ;

    cout<<postfix<<endl;


}
