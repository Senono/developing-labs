#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <regex>

#define LENGTH 100

using namespace std;
// 2+3.14     23.14

bool is_number(const std::string& s)
{
    try
    {
        std::stod(s);
    }
    catch (...)
    {
        return false;
    }
    return true;
}

double calcOpz(string opz, stack <double> Buff) {
    int length = opz.length();
    bool isSpace = false;

    string lexems[LENGTH];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (opz[i] != ' ')
            lexems[j] += opz[i];
        else j++;
    }

    for (int i = 0; i < j + 1; i++) {
        if (is_number(lexems[i])) Buff.push(stod(lexems[i]));
        else {

            double num1 = Buff.top();
            Buff.pop();
            double num2 = Buff.top();
            Buff.pop();
            if (lexems[i] == "+") Buff.push(num1 + num2);
            else if (lexems[i] == "-") Buff.push(num2 - num1);
            else if (lexems[i] == "*") Buff.push(num1 * num2);
            else Buff.push(num2 / num1);
        }
    }

    return Buff.top();
}

string infToOpz(string inf, stack<string> op) {
    int length = inf.length();
    string post = "";
    bool isDouble = false;
    string lexems[LENGTH];

    int j = 0;
    for (int i = 0; i < length; i++) {
        if ((inf[i] >= '0' && inf[i] <= '9') || inf[i] == '.') {
            lexems[j] += inf[i];
        }
        else if (inf[i] != ' ') {
            if (is_number(lexems[j])) j++;
            lexems[j] += inf[i];
            j++;
        }
    }

    if (is_number(lexems[j])) j++;
    for (int i = 0; i < j; i++) {
        if (is_number(lexems[i])) {
            post += ' ';
            post += lexems[i];
        }
        else if (op.empty()) op.push(lexems[i]);
        else if (lexems[i] == "(") op.push(lexems[i]);
        else if (lexems[i] == ")") {
            while (op.top() != "(") {
                post += ' ';
                post += op.top();
                op.pop();
            }
            op.pop();
        }
        else if ((lexems[i] == "+" || lexems[i] == "-") && op.top() != "*" && op.top() != "/") {
            op.push(lexems[i]);
        }
        else if (lexems[i] == "*" || lexems[i] == "/") {
            if (op.top() == "*" || op.top() == "/") {
                post += ' ';
                post += op.top();
                op.pop();
            }
            op.push(lexems[i]);
        }
        else {
            while (!op.empty()) {
                if (op.top() == "*" || op.top() == "/") {
                    post += ' ';
                    post += op.top();
                    op.pop();
                }
                else if (op.top() == "-" || op.top() == "+" || op.top() == "(") break;
            }
            op.push(lexems[i]);
        }
    }


    int SIZE = op.size();
    for (int i = 0; i < SIZE; i++) {
        post += ' ';
        post += op.top();
        op.pop();
    }

    post.erase(0, 1);
    return post;
}

int main()
{
    int numOfVariables=1;

    vector<string> variables;
    vector<string> expression;

    stack<string> operators;
    stack<double> buff;
    int flag = 0;
    int count = 0;

    double resultNums[LENGTH];
    //vector<string> resultVar;

    //for (int i = 0; i < LENGTH; i++)
    //    resultNums[i] = '\0'; 

    string inf;
    getline(cin, inf);
    string opzz = infToOpz(inf, operators);
    cout << opzz << endl;
    cout << calcOpz(opzz, buff);

    cout << "Enter the numbers of variables: ";
    cin >> numOfVariables;
    cin.ignore();

    cout << "Enter the variables:" << endl;
    for (int i = 0; i < numOfVariables; i++) {
        string tmp;
        getline(cin, tmp);
        variables.push_back(tmp);
        expression.push_back(variables[i].substr(2));
    }

    /*for (int i = 0; i < numOfVariables; i++)
        cout << "vector " << i << " " << expression[i] << endl;*/

    //a = b*3;
    //b = 2;
    //c = a*b
    //d = e
    //e = c/b;
    // i = 0
    // j = 1
    /*while (count != 5) {
        count = 0;
        for (int i = 0; i < numOfVariables; i++) {
            if (!regex_search(expression[i], regex("[A-Za-z+-/*()]"))) count++;
            else if (!regex_search(expression[i], regex("[A-Za-z]")) && regex_search(expression[i], regex("[+-/*()]"))) {
                count++;
                string tmp = infToOpz(expression[i], operators);
                variables[i].erase(2);
                variables[i].insert(2, to_string(calcOpz(tmp, buff)));
            } 
            else {
                for (int j = 0; j < numOfVariables; j++) {
                    if (int pos = expression[i].find(variables[j][0]) != string::npos && regex_match(variables[j], regex("\w=(\d)+"))) {
                        expression[i].erase(pos, 1);
                        expression[i].insert(pos, variables[j].substr(2));
                    }
                }
            }
        }
    }*/
    
    //for (int i = 0; i < numOfVariables; i++) cout << variables[i];
}