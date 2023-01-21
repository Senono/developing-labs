/*
С помощью multiset подсчитать количество вхождений каждой буквы алфавита в
тексте. Текст считывается из файла.
*/

#include <iostream>
#include <set>
#include <fstream>

#define FILE "text.txt"

using namespace std;

int main(int argc, const char* argv[]) {
    int i = 0;
    ifstream file;
    file.open(FILE);
    if (file.is_open()) {
        cout << "File is open" << endl;
    }
    else cout << "File isn't open" << endl;
    char buffer[100];
    file.get(buffer, 100);
    file.close();
   
    multiset <char> mst;

    while (buffer[i]) {
        cout << buffer[i];
        mst.insert(buffer[i]);
        i++;
    }
    cout << endl;
    multiset<char> ::iterator it;
    multiset<char> used;
   
    for (it = mst.begin(); it != mst.end(); it++) {
        if (used.count(*it) == 0 && *it != ' ') {
            cout << *it << "=" << mst.count(*it) << endl;
            used.insert(*it);
        }
    }
    
    return 0;
}