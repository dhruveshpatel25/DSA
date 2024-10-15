#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>>& M,int a,int b,int n){
    if(M[a][b]==1){
        return true;
    }else{
        return false;
    }
}

int celebrity(vector<vector<int>>& M,int n){
    stack<int> stk;
    for(int i=0;i<n;i++){
        stk.push(i);
    }
    while(stk.size()>1){
        int a=stk.top();
        stk.pop();

        int b=stk.top();
        stk.pop();

        if(knows(M,a,b,n)){
            stk.push(b);
        }else{
            stk.push(a);
        }
        int ans=stk.top();
        int zerocount=0;
        for(int i=0;i<n;i++){
            if(M[ans][i]==0){
                zerocount++;
            }
        }
        if(zerocount!=n){
            return -1;
        }
        int onecount=0;
        for(int i=0;i<n;i++){
            if(M[i][ans]==1){
                onecount++;
            }
        }
        if(onecount!=n-1){
            return -1;
        }
    }
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    int n = M.size();
    int potential_celebrity = celebrity(M, n);

    if (potential_celebrity != -1) {
        cout << "Potential celebrity found at index: " << potential_celebrity << endl;
    } else {
        cout << "No celebrity found." << endl;
    }

    return 0;
}