/*Redundant Brackets
Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.
Note :
A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.

For Example :
((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
While (a + (b*c)) does not have any pair of redundant brackets. 
https://www.naukri.com/code360/problems/redundant-brackets_975473*/
#include<iostream>
#include<stack>
using namespace std;

bool redundantbracket(string &mystack){
    stack<char> stack;

    //iterate the compelete expression
    for(int i=0;i<mystack.length();i++){
        char ch=mystack[i];

        //check for the expression if it is an operator or opening bracket
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){

            //push in stack
            stack.push(ch);
        }
        
        //if other thing
        else{

            //if closing bracket 
            if(ch==')'){

                //flag as true
                bool isredundant=true;

                //till we get the opening bracket
                while(stack.top()!='('){

                    //get the top element
                    char top=stack.top();

                    //if an operator
                    if( top=='+' || top=='-' || top=='*' || top=='/'){

                        //means it is not redundant
                        isredundant=false;
                    }

                    //remove the element
                    stack.pop();
                }

                //if it remains unchanged
                if(isredundant==true){

                    //return true
                    return true;
                }

                //remove the element
                stack.pop();
            }
        }
    }

    //if after complete iteration there exist no redundant then return false
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