#include <iostream>
#include <stack>
#include <string>
#include <cmath> 
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char c : exp) {

        if (c >= '0' && c <= '9') {
            st.push(c - '0'); 
        }
        
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
                default: 
                    cout << "Invalid operator: " << c << endl;
                    return -1;
            }
        }
    }
    return st.top(); 
}

int main() {
    string postfix;
    cout << "Enter postfix expression (use digits only): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
