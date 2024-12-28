/*Valid Parentheses
You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .
Return true if the given string 'S' is balanced, else return false.

For example:
'S' = "{}()".
There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
So the 'S' is Balanced.
https://www.naukri.com/code360/problems/valid-parenthesis_795104*/
#include<iostream>
#include<stack>
using namespace std;

bool isValidParanthesis(string expression){
    stack<char> s;
    for(int i=0;i<expression.size();i++){
        char ch=expression[i];

        //check the element if it is opening paranthesis or not
        if(ch=='(' || ch=='{' || ch=='[' ){

            //if yes push it
            s.push(ch);
        }

        //if not
        else{

            //check if it empty or not
            if(!s.empty()){

                //if not take the top element
                char top=s.top();

                //if it is matchinf with its opening paranthesis
                if((ch==')' && top=='(') || (ch=='}'&& top=='{') || (ch==']' && top=='[')){

                    //just remove the top element
                    s.pop();
                }

                //if not matching
                else{

                    //invalid
                    return false;
                }
            }

            //if empty
            else{

                //return invalid
                return false;
            }
        }
    }

    //check if after iteration stack is empty for not
    if(s.empty()){

        //if empty return valis
        return true;
    }else{

        //if not return invalid
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