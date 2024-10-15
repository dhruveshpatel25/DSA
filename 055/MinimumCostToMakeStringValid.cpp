#include<iostream>
#include<stack>
using namespace std;

int MinimumCost(string str){
    if(str.length()%2==1){
        return -1;
    }

    stack<char> stk;
    for(int i=0;i<str.length();i++){
        char ch=str[i];

        if(ch=='{'){
            stk.push(ch);
        }else{
            if(!stk.empty() && stk.top()=='{'){
                stk.pop();
            }else{
                stk.push(ch);
            }
        }
    }

    int close=0;
    int open=0;
    while(!stk.empty()){
        if(stk.top()=='{'){
            open++;
        }else{
            close++;
        }
        stk.pop();
    }
    int ans=(open+1)/2 + (close+1)/2;
    return ans;
}

int main() {
    string str = "{{{{{{{";
    cout << "Minimum Cost: " << MinimumCost(str) << endl;
    return 0;
}