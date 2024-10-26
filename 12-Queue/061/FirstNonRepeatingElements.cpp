#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

string NonRepeating(string str){
    map<char,int> m;
    string ans="";
    queue<char> que;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        que.push(ch);
        m[ch]++;

        while(!que.empty()){
            if(m[que.front()]>1){
                que.pop();
            }else{
                ans.push_back(que.front());
                break;
            }
        }
        if(que.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main() {
    string str = "aabbbccddee";
    string result = NonRepeating(str);
    cout << "Original string: " << str << endl;
    cout << "Non-repeating characters: " << result << endl;
    return 0;
}
