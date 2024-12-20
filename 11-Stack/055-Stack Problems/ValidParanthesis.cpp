#include<iostream>
#include<stack>
using namespace std;

bool isValidParanthesis(string expression){
    stack<char> s;
    for(int i=0;i<expression.size();i++){
        char ch=expression[i];

        if(ch=='(' || ch=='{' || ch=='[' ){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.top();
                if((ch==')' && top=='(') || (ch=='}'&& top=='{') || (ch==']' && top=='[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }else{
        return false;
    }
}

int main() {
    string expression;
    cout << "Enter a string containing parentheses: ";
    cin >> expression;

    if (isValidParanthesis(expression)) {
        cout << "The parentheses in the expression are balanced." << endl;
    } else {
        cout << "The parentheses in the expression are not balanced." << endl;
    }

    return 0;
}