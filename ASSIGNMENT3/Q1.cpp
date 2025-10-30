#include <iostream>
#include <stack>      
#include <string>    

using namespace std;

void display(stack<int> s) {
    if (s.empty()) {
        cout << "The stack is empty." << endl;
        return;
    }
    cout << "Elements in the stack (TOP to BOTTOM):" << endl;
    cout << "TOP" << endl;
    while (!s.empty()) {
        cout << "| " << s.top() << " |" << endl; 
        s.pop(); 
    }
}


int main() {
   
    stack<int> myStack;
    int choice;



        cout << "1. Push an element  (push)" << endl;
        cout << "2. Pop an element   (pop)" << endl;
        cout << "3. Check if Empty (empty)" << endl;
        cout << "4. Display the stack" << endl;
        cout << "5. Peek at top      (top)" << endl;
        cout << "6. Get Size         (size)" << endl;
    
        cout << "Enter your choice (1-7): ";

        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Enter the element to push: ";
                cin >> element;
                if(cin.fail()){
                    cout << "Invalid input. Please enter an integer." << endl;
                    cin.clear(); 
                    cin.ignore(1024, '\n');
                } else {
                    myStack.push(element);
                    cout << "Element " << element << " pushed to the stack." << endl;
                }
                break;
            }
            case 2: { 
                if (myStack.empty()) {
                    cout << "Stack Underflow! The stack is empty." << endl;
                } else {
                    cout << "Popped element: " << myStack.top() << endl;
                    myStack.pop(); 
                }
                break;
            }
            case 3: { 
                if (myStack.empty()) {
                    cout << "Result: The stack is EMPTY." << endl;
                } else {
                    cout << "Result: The stack is NOT EMPTY." << endl;
                }
                break;
            }
            case 4: { 
                display(myStack);
                break;
            }
            case 5: { 
                if (myStack.empty()) {
                    cout << "The stack is empty. No element to peek." << endl;
                } else {
                    cout << "The top element (peek): " << myStack.top() << endl;
                }
                break;
            }
            case 6: {
                cout << "The current size of the stack is: " << myStack.size() << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                break;
            }
        }

    return 0; 
}