#include<bits/stdc++.h>
using namespace std;


int priority(char op){
    switch(op){
        case '^':
            return 3;
        case '/':
            return 2;
        case '*':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
    }
    return 100;
}

string in_to_post(string str){
    stack<char>st;
    string postfix;
    for(int i=0;i<str.length();i++){
        if(str[i]>='a' && str[i]<='z'){
            postfix += str[i];
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'){
            while(!st.empty() && priority(str[i])>=priority(st.top())){
                char op = st.top();
                postfix+=op;
                st.pop();
            }
            st.push(str[i]);
        }
        else if(str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            while(st.top()!='('){
                char op = st.top();
                postfix+=op;
                st.pop();
            }
            st.pop();
        }
    }
    while(!st.empty()){
        char op = st.top();
        postfix += op;
        st.pop();
    }
    return postfix;
}

string in_to_pre(string str){
    stack<char>st;
    string prefix;
    reverse(str.begin(),str.end());
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            str[i]=')';
        }
        else if(str[i]==')'){
            str[i]='(';
        }
    }
    
    string reverse_postfix = in_to_post(str);
    
    reverse(reverse_postfix.begin(),reverse_postfix.end());
    prefix = reverse_postfix;
    return prefix;
}

int main(){
    string str = "a+b*(c^d-e)";
    cout<<in_to_pre(str);
    return 0;
}