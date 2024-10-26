#include<iostream>
#include<stack>
using namespace std;

bool redundantbracket(string &mystack){
    stack<char> stack;
    for(int i=0;i<mystack.length();i++){
        char ch=mystack[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            stack.push(ch);
        }else{
            if(ch==')'){
                bool isredundant=true;
                while(stack.top()!='('){
                    char top=stack.top();
                    if( top=='+' || top=='-' || top=='*' || top=='/'){
                        isredundant=false;
                    }
                    stack.pop();
                }
                if(isredundant==true){
                    return true;
                }
                stack.pop();
            }
        }
    }
    return false;
}

int main() {
    string expression;
    cout << "Enter a string containing parentheses: ";
    cin >> expression;

    if (redundantbracket(expression)) {
        cout << "The expression is redundant." << endl;
    } else {
        cout << "The expression is not redundant." << endl;
    }

    return 0;
}