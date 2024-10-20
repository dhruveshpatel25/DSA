#include<iostream>
#include<vector>
using namespace std;

void solve(string& str, int index, string& output, vector<string>& ans,string map[]){
    if(index>=str.length()){
        ans.push_back(output);
        return;
    }
    int number = str[index]-'0';
    string value=map[number];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(str,index+1,output,ans,map);
        output.pop_back();
    }
}

vector<string> keypad(string& str){
    vector<string> ans;
    if(str.length()==0){
        return ans;
    }
    string output="";
    int index=0;
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(str,index,output,ans,map);
    return ans;
}

int main() {
    string str;
    cin>>str;
    vector<string> result = keypad(str);
    cout<<"[";
    for (const auto& combination : result) {
        cout << combination <<" ";
    }
    cout<<"]";
}
