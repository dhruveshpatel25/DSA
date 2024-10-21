#include<iostream>
#include<vector>
using namespace std;

vector<string> subsequence(string& str){
    int size=str.size();
    int subsequencecount=(1<<size);
    vector<string> ans;
    for(int mask=0;mask<subsequencecount;mask++){
        string subsequence="";
        for(int i=0;i<size;i++){
            if((mask&(1<<i))!=0){
                subsequence=subsequence+str[i];
            }
        }
        ans.push_back(subsequence);
    }
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