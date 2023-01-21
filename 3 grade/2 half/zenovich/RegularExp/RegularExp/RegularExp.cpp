// /(abc+)* | (ab)+

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define LENGTH 100

int main()
{
    string str;
    cout << "Enter your string: ";
    cin >> str;
    int length = str.length();

    //string *buff = new string[LENGTH];
    vector<string> buff;
    string tmpBuff;

    int pos1 = 0, pos2 = 2;
    int flag = 1;

    if (str == "") {
        cout << "String is empty" << endl;
    }
    else {
        for (int i = 0; i < length; i++) {
            if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c' && (tmpBuff.length() == 0 || tmpBuff.find('c') != string::npos)) {
                pos1 = i;
                pos2 = i + 2;
                if (flag) tmpBuff.clear();
                flag = 1;
                tmpBuff.append("abc");

                for (int j = pos2 + 1; j < length; j++) {
                    if (str[j] == 'c') {
                        tmpBuff.append("c");
                        pos2++;
                        i = pos2;
                    }
                    else {
                        i = pos2;
                        break;
                    }
                }
                if (str[i + 1] == 'a' && str[i + 2] == 'b' && str[i + 3] == 'c') {
                    flag = 0;
                }
                else {
                    buff.push_back(tmpBuff);
                    tmpBuff.clear();
                }
            }
            else if (str[i] == 'a' && str[i + 1] == 'b') {
                if (flag) tmpBuff.clear();
                flag = 1;
                tmpBuff.append("ab");
                i++;
                if (str[i + 1] == 'a' && str[i + 2] == 'b') {
                    flag = 0;
                }
                else {
                    buff.push_back(tmpBuff);
                    tmpBuff.clear();
                }
            }
        }
    }
    
    int vector_size = buff.size();
    for (int i = 0; i < vector_size; i++)
        cout << buff[i] << endl;
}