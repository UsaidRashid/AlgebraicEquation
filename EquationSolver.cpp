#include<bits/stdc++.h>
using namespace std;
//#define int long long


signed main()
{
    cout<<"ENTER THE EQUATION"<<endl;
    string s;
    cin>>s;
    vector<int>LHS(10);
    vector<int>LHSx(10);
    vector<int>RHS(10);
    vector<int>RHSx(10);
    int sign=0;
    int i=0;
    if(s[i]=='-'){
        sign=1;
        i++;
    } 
    int n=0,x=0,t=0;
    while(s[i]!='='){
        if(s[i]=='x'){
            if(sign==0){
                if(n==0) LHSx[t]=1;
                else LHSx[t]=n;
            } 
            else{
                if(n==0) LHSx[t]=-1;
                else LHSx[t]=-n;
            } 
            cout<<LHSx[t]<<endl;
            t++;
            n=0;
            if(s[i+1]=='+'){
                sign=0;
                i++;
            } 
            else if(s[i+1]=='-'){
                sign=1;
                i++;
            } 
        }
        else if(s[i]=='+' || s[i]=='-'){
            if(sign==0) LHS[x]=n;
            else LHS[x]=-n;
            cout<<LHS[x]<<endl;
            n=0;
            x++;
            if(s[i]=='+') sign=0;
            else if(s[i]=='-') sign=1;
        }
        else n=n*10+int(s[i])-48;
        i++;
    }
    if(sign==0) LHS[x]=n;
    else LHS[x]=-n;
    cout<<LHS[x]<<endl;
    x=0;
    t=0;
    n=0;
    i++;
    if(s[i]=='-') sign=1;
    else sign=0;
    while(i<s.length()){
        if(s[i]=='x'){
            if(sign==0){
                if(n==0) RHSx[t]=1;
                else RHSx[t]=n; 
            } 
            else{
                if(n==0) RHSx[t]=-1;
                else RHSx[t]=-n;
            } 
            cout<<RHSx[t]<<endl;
            t++;
            n=0;
            if(s[i+1]=='+'){
                sign=0;
                i++;
            } 
            else if(s[i+1]=='-'){
                sign=1;
                i++;
            } 
        }
        else if(s[i]=='+' || s[i]=='-'){
            if(sign==0) RHS[x]=n;
            else RHS[x]=-n;
            cout<<RHS[x]<<endl;
            n=0;
            x++;
            if(s[i]=='+') sign=0;
            else if(s[i]=='-') sign=1;
        }
        else n=n*10+int(s[i])-48;
        i++;
    }
    if(sign==0) RHS[x]=n;
    else RHS[x]=-n;
    cout<<RHS[x]<<endl;
    for(int k=0;k<LHS.size();k++) cout<<LHS[k]<<" ";
    cout<<endl;
    for(int k=0;k<LHSx.size();k++) cout<<LHSx[k]<<" ";
    cout<<endl;
    for(int k=0;k<RHS.size();k++) cout<<RHS[k]<<" ";
    cout<<endl;
    for(int k=0;k<RHSx.size();k++) cout<<RHSx[k]<<" ";
    cout<<endl;
    int s1=accumulate(LHS.begin(),LHS.end(),0);
    int s2=accumulate(RHS.begin(),RHS.end(),0);
    int s3=accumulate(LHSx.begin(),LHSx.end(),0);
    int s4=accumulate(RHSx.begin(),RHSx.end(),0);
    double X=s3-s4;
    double C=s2-s1;
    double result=C/X;
    cout<<"The value of x is: "<<result<<endl;
    return 0;
}