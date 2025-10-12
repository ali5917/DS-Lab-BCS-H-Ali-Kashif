#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
using namespace std;

#define MAX 1000

template <typename T> // using template class, for char in conversion and int in evaluation
class Stack {
    private:
        int top;
        T arr[MAX];
        
    public:
        Stack (int t = -1) : top(t) {}

        bool push (T x) {
            if (top >= MAX - 1) return false;
            arr[++top] = x;
            return true;
        }

        T pop () {
            if (top < 0) return T();
            T x = arr[top--]; 
            return x;
        }

        T peek () {
            if (top < 0) return T();
            return arr[top];
        }

        bool isEmpty () {return (top < 0);}

        void display() {
            if (top < 0) return;
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int precedence (char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

bool isOperator (char op) {
    if (op == '^' || op == '*' || op == '/' || op == '+' || op == '-') return true;
    return false;
}

string infixToPostfix (string infix) {
    string postfix = "";
    Stack<char> s;

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        } else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop(); 
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) postfix += s.pop();

    return postfix;
}

int calculate(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return -1;
    }
}

int evaluatePostfix (string postfix) {
    Stack<int> s;

    for (char ch : postfix) {
        if (isOperator(ch)) {
            int b = s.pop();
            int a = s.pop();
            int res = calculate(a, b, ch);
            s.push(res);
        } else {
            s.push(ch - '0');
        }   
    }

    return s.pop();
}

int main() {
    string infix = "3+(7*4)-5";
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "Evaluation: " << result << endl;
}
