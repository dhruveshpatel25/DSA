/*Minimum Cost To Make String Valid
Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced. Formally for each opening bracket, there must be a closing bracket right to it.

For Example:
“{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.
Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.

For Example:
Minimum operations to make ‘STR’ =  “{{“ valid is 1.
In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’. The ‘STR’ now becomes "{}" which is a valid string.

Note:
Return -1 if it is impossible to make ‘STR’ valid.
https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770*/
#include<iostream>
#include<stack>
using namespace std;

int MinimumCost(string str){

    //if odd length than it is impossible to make valid
    if(str.length()%2==1){
        return -1;
    }

    stack<char> stk;
    for(int i=0;i<str.length();i++){
        char ch=str[i];

        //check whether the paranthesis are open or closed
        if(ch=='{'){

            //if open push
            stk.push(ch);
        }
        
        //if close
        else{

            //if stack is not empty and top element is open paranthesis
            if(!stk.empty() && stk.top()=='{'){

                //remove the top
                stk.pop();
            }
            
            //if empty or top is close paranthesis
            else{

                //push close paranthesis
                stk.push(ch);
            }
        }
    }

    //counter
    int close=0;
    int open=0;
    while(!stk.empty()){

        //if open paranthesis
        if(stk.top()=='{'){
            open++;
        }
        
        //if close paranthesis
        else{
            close++;
        }
        stk.pop();
    }


    int ans=(open+1)/2 + (close+1)/2;
    return ans;
}

int main() {
    string str = "{{{{{{{}";
    cout << "Minimum Cost: " << MinimumCost(str) << endl;
    return 0;
}