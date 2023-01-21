#include <iostream>
#include <string>
#include <stack>

#define LENGTH 100

using namespace std;

 double calcOpz(string opz, stack<float> Buff) {
    int length = opz.length();

    for (int i = 0; i < length; i++) {
        if (opz[i] >= '0' && opz[i] <= '9') Buff.push(opz[i] - '0');
        else {
            float num1 = Buff.top();
            Buff.pop();
            float num2 = Buff.top();
            Buff.pop();

            if (opz[i] == '+') Buff.push(num1 + num2);
            else if (opz[i] == '-') Buff.push(num2 - num1);
            else if (opz[i] == '*') Buff.push(num1 * num2);
            else Buff.push(num2 / num1);
        }
    }

    return Buff.top();
}

string infToOpz(string inf, stack<char> op) {
    int length = inf.length();
    string post = "";

    for (int i = 0; i < length; i++) {
        if (inf[i] >= '0' && inf[i] <= '9') post += inf[i];
        else if (op.empty()) op.push(inf[i]);
        else if (inf[i] == '(') op.push(inf[i]);
        else if (inf[i] == ')') {
            while (op.top() != '(') {
                post += op.top();
                op.pop();
            }
            op.pop();
        }
        else if ((inf[i] == '+' || inf[i] == '-') && op.top() != '*' && op.top() != '/')
            op.push(inf[i]);
        else if (inf[i] == '*' || inf[i] == '/') op.push(inf[i]);
        else {
            while (!op.empty()) {
                if (op.top() == '*' || op.top() == '/') {
                    post += op.top();
                    op.pop();
                }
                else if (op.top() == '-' || op.top() == '+' || op.top() == '(') break;
            }
            op.push(inf[i]);
        }
    }


    int SIZE = op.size();
    for (int i = 0; i < SIZE; i++) {
        post += op.top();
        op.pop();
    }

    return post;
}

int main()
{
    string infix;
    cout << "Enter your expression: ";
    cin >> infix;
    string postfix;
    //char* operators = new char[LENGTH];
    stack<char> operators;

    postfix = infToOpz(infix, operators);
    cout << "Result: " << postfix << endl;

    stack<float> tmp;
    double calcPost = calcOpz(postfix, tmp);
    cout << "Calc: " << calcPost << endl;
}