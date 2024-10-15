#include<iostream>
#include<vector>
using namespace std;

void solve(string str,string output,int index,vector<string>& ans){
    if(index>=str.length()){
        ans.push_back(output);
        return;
    }

    solve(str,output,index+1,ans);

    output.push_back(str[index]);
    solve(str,output,index+1,ans);
}

vector<string> subsequence(string str){
    vector<string> ans;
    string output="";
    int index=0;
    solve(str,output,index,ans);
    return ans;
}

int main() {
    string str = "abc"; 
    vector<string> result = subsequence(str);
    for (const auto& subset : result) {
        cout << "[ ";
        for (const auto& ch : subset) {
            cout << ch << " ";
        }
        cout << "]" ;
    }
    return 0;
}