#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
 
char s[1000][10];
int next[1000];
int n,m;


bool eqc(int e1,int e2){
    for(int i=0;i<n;++i){
        if(s[i][e1] != s[i][e2]) 
		return false;
    }
    return true;
}
 
bool eqr(int e1,int e2){
    for(int i=0;i<m;++i){
        if(s[e1][i] != s[e2][i]) 
		return false;
    }
    return true;
}
 
int get1(){
    next[0] = -1;
    int k = -1;
    for(int i=1;i<m;++i){
        while(k>-1 && !eqc(k+1,i)){
        k = next[k];	
		} 
        if(eqc(k+1,i)) {
        	++k;
		}
        next[i] = k;
    }
    return m-next[m-1]-1;
}
 
int get2(){
    next[0] = -1;
    int k = -1;
    for(int i=1;i<n;++i){
        while(k > -1 && !eqr(k+1,i)) {
        k = next[k];	
		}
        if(eqr(k+1,i)){
         ++k;	
		}
        next[i] = k;
    }
    return n-(next[n-1]+1);
}
 
int main(){
    while(scanf("%d%d",&n,&m)){
        for(int i=0;i<n;++i){
        	scanf("%s",s[i]);
		} 
        int ans = get1(); 
        ans =ans*get2(); 
        printf("%d\n",ans);
    }
    return 0;
}

