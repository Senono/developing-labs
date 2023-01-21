#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <regex>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iomanip>

#define LENGTH 100
#define PATH "C:\developing\opz.txt"

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

int countAfterComma(double num) {
    stringstream s;
    s << num;
    int pos = s.str().find('.');
    if (pos != string::npos) return s.str().size() - 1 - pos;
    return 0;
}

int countBeforeComma(double num) {
    string str = to_string(num);
    int count = 0;
    while (str[count] != '.') count++;
    return count;
}

double calcOpz(string opz, stack <double> Buff);
string infToOpz(string inf, stack<string> op) {
    int length = inf.length();
    string post = "";
    string lexems[LENGTH];
    stack<string> tmpOp;
    stack<double> tmpBuff;
    cout << "Inf opz: " << inf << endl;

    int j = 0;
    for (int i = 0; i < length; i++) {
        if ((inf[i] >= '0' && inf[i] <= '9')
            || inf[i] == '.'
            || (inf[i] == '-' && j == 0 && lexems[j] == "")
            || (inf[i] == '-' && j != 0 && regex_match(lexems[j - 1], regex(R"([+\-*/(\)])")) && lexems[j] == "")) {
            lexems[j] += inf[i];
        }
        else if (inf[i] >= 'a' && inf[i] <= 'z') {
            int cntTmp = 0;
            while (i < length) {
                lexems[j] += inf[i];
                if (inf[i] == '(') cntTmp++;
                if (inf[i] == ')') cntTmp--;
                if (i < length && inf[i] == ')' && inf[i + 1] != ')' && cntTmp == 0) break;
                i++;
            }
            j++;
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
        else if (regex_search(lexems[i], regex(R"(\w)"))) {
            //post += ' '; // cos(0+0+0)
            //string tmp = lexems[i].substr(lexems[i].find("(") + 1, lexems[i].length() - lexems[i].find("(") - 2);;
            //cout << lexems[i].substr(lexems[i].find("(") + 1, lexems[i].length() - lexems[i].find("(") - 2);
            ////post += to_string(calcOpz(infToOpz(tmp, tmpOp), tmpBuff));
            //post += ' ';
            //post += lexems[i].erase(lexems[i].find("("));
            post += ' ';
            post += infToOpz(lexems[i].substr(lexems[i].find("(") + 1, lexems[i].length() - lexems[i].find("(") - 2), tmpOp);
            post += ' ';
            post += lexems[i].erase(lexems[i].find("("));

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
        else if (lexems[i] == "^") { // 2^2 2 2 ^     2^(4-3) 2 4 3 - ^      2^(4*3)    2 4 3 * ^ 
            op.push(lexems[i]);
        }
        else if (op.top() == "^") {
            post += ' ';
            post += op.top();
            op.pop();
            i--;
        }
        else if ((lexems[i] == "+" || lexems[i] == "-") && op.top() != "*" && op.top() != "/") {
            op.push(lexems[i]);
        }
        else if (lexems[i] == "*" || lexems[i] == "/") {
            if (op.top() == "*" || op.top() == "/" || op.top() == "^") {
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
    cout << "post opz: " << post << endl;
    return post;
}

double calcOpz(string opz, stack <double> Buff) {
    int length = opz.length();

    string lexems[LENGTH];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (opz[i] != ' ')
            lexems[j] += opz[i];
        else j++;
    }

    for (int i = 0; i < j + 1; i++) {
        if (is_number(lexems[i])) Buff.push(stod(lexems[i]));
        else if (regex_search(lexems[i], regex(R"(\w)"))) {
            /*int pos = lexems[i].find("(");
            string tmp = lexems[i].substr(0, pos);
            string exp = lexems[i].substr(pos + 1, lexems[i].length() - pos - 2);
            stack<string> tmpOp;
            stack<double> tmpBuff;
            if (tmp == "cos") Buff.push(cos(calcOpz(infToOpz(exp, tmpOp), tmpBuff)));
            if (tmp == "abs") Buff.push(abs(calcOpz(infToOpz(exp, tmpOp), tmpBuff)));
            if (tmp == "sqrt") Buff.push(sqrt(calcOpz(infToOpz(exp, tmpOp), tmpBuff)));*/
            double num = Buff.top();
            Buff.pop();
            if (lexems[i] == "abs") Buff.push(abs(num));
            else if (lexems[i] == "cos") Buff.push(cos(num));
            else if (lexems[i] == "sqrt") Buff.push(sqrt(num));
        }
        else {
            double num1 = Buff.top();
            Buff.pop();
            double num2 = Buff.top();
            Buff.pop();
            if (lexems[i] == "+") Buff.push(num1 + num2);
            else if (lexems[i] == "-") Buff.push(num2 - num1);
            else if (lexems[i] == "*") Buff.push(num1 * num2);
            else if (lexems[i] == "^") {
                if (floor(num1) != num1 && num2 < 0) throw invalid_argument("Your base num less than zero");
                Buff.push(pow(num2, num1));
            }
            else Buff.push(num2 / num1);
        }
    }

    return Buff.top();
}

string toStringStream(double num) {
    ostringstream ostr;
    ostr << num;
    return ostr.str();
}

int main()
{
    int numOfVariables;

    vector<string> variables;
    vector<string> expression;

    stack<string> operators;
    stack<double> buff;
    int flag = 0;
    int count = 0;

    /*try {
        string inf;
        getline(cin, inf);
        string opzz = infToOpz(inf, operators);
        cout << opzz << endl;
        cout << calcOpz(opzz, buff);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }*/
    

    /*cout << "Enter the numbers of variables: ";
    cin >> numOfVariables;
    cin.ignore();*/

    /*cout << "Enter the variables:" << endl;
    for (int i = 0; i < numOfVariables; i++) {
        string tmp;
        getline(cin, tmp);
        variables.push_back(tmp);
        expression.push_back(variables[i].substr(2));
    }*/
    
    /*cout << setw(30) << pow(10.000000000000000, 30.0000000000);
    cout << calcOpz("10.0000000 30.000000 ^", buff);*/
    string line;
    ifstream f("opz.txt");
    if (f){
        int i = 0;
        while (getline(f, line)) {
            variables.push_back(line);
            expression.push_back(variables[i].substr(2));
            i++;
        }
        numOfVariables = i;
    }
    f.close();

    for (int i = 0; i < numOfVariables; i++)
        cout << "vector " << i << " " << expression[i] << endl;

    try {
        while (count != numOfVariables) {
            count = 0;
            for (int i = 0; i < numOfVariables; i++) {
                if (regex_match(expression[i], regex(R"((\-)?(\d)+(\.)?(\d)*)"))) count++;
                else if ((!regex_search(expression[i], regex("[A-Za-z]")) && regex_search(expression[i], regex(R"([+\-/*(\)\^])"))) 
                    || (regex_search(expression[i], regex(R"(([a-z]){2,})")) && !regex_search(expression[i], regex(R"([^A-Za-z][A-Za-z][^A-Za-z])")))) {
                    count++;
                    string tmp = infToOpz(expression[i], operators);
                    double tmpCalc = calcOpz(tmp, buff);
                    expression[i].erase(0);
                    expression[i].insert(0, toStringStream(tmpCalc));
                    variables[i].erase(2);
                    variables[i].insert(2, toStringStream(tmpCalc));
                }
                else {
                    for (int j = 0; j < numOfVariables; j++) {
                        int pos = expression[i].find(variables[j][0]);
                        if (pos != string::npos && regex_match(variables[j], regex(R"(\w=(\-)?(\d)+(\.)?(\d)*)"))) {
                            expression[i].erase(pos, 1);
                            expression[i].insert(pos, variables[j].substr(2));
                            if (regex_match(expression[i], regex(R"((\-)?(\d)+(\.)?(\d)*)"))) {
                                variables[i].erase(2);
                                variables[i].insert(2, expression[i]);
                            }
                        }
                    }
                }
            }
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    for (int i = 0; i < numOfVariables; i++) cout << variables[i] << endl;
}