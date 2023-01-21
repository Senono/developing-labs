#include <iostream>
#include <string>
#include <sstream>
#include <stack>

#define LENGTH 10

using namespace std;

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
        else {
            double num1 = Buff.top();
            Buff.pop();
            double num2 = Buff.top();
            Buff.pop();
            if (lexems[i] == "+") Buff.push(num1 + num2);
            else if (lexems[i] == "-") Buff.push(num2 - num1);
            else if (lexems[i] == "*") Buff.push(num1 * num2);
            else if (lexems[i] == "^") {
                if (floor(num1) != num1) {
                    if (num2 < 0) throw exception("Your base num less than zero");
                    //int test = countBeforeComma(num1);
                    int _comma = countAfterComma(num1);
                    int numerator = num1 * pow(10, _comma);
                    int denominator = pow(10, _comma + countBeforeComma(num1));
                    Buff.push(pow(pow(num2, 1.0 / denominator), numerator));
                }
                else {
                    Buff.push(pow(num2, num1));
                }
            }
            else Buff.push(num2 / num1);
        }
    }

    return Buff.top();
}

int main()
{
    stack<double> buff;
    try {
        cout << calcOpz("-2 1.5 ^", buff);
    }
    catch (exception& e) {
        cout << e.what();
    }
}