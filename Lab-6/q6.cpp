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

string infixToPrefix (string infix) {
    string prefix = "";
    Stack<char> s;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char ch = infix[i];
        if (isdigit(ch)) {
            prefix = ch + prefix;
        } else if (ch == ')') {
            s.push(ch);
        } else if (ch == '(') {
            while (!s.isEmpty() && s.peek() != ')') {
                prefix = s.pop() + prefix;
            }
            s.pop(); 
        } else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) > precedence(ch)) {
                prefix = s.pop() + prefix; 
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) prefix = s.pop() + prefix;

    return prefix;
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

int evaluatePrefix (string prefix) {
    Stack<int> s;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isOperator(ch)) {
            int a = s.pop();
            int b = s.pop();
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
    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    int result = evaluatePrefix(prefix);
    cout << "Evaluation: " << result << endl;
}