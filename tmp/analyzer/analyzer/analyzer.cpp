#include <iostream>
#include <string>
#include <regex>

using namespace std;

#define LENGTH 100

int main()
{
	string str;
	string nums[LENGTH];
	int j = 0;

	cout << "Enter the string: ";
	getline(cin, str);
	cout << "Your string: " << str << endl;
	int length = str.length();

	for (int i = 0; i < length; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
				nums[j] += str[i];
		}
		else if (str[i] == '.' ) {
			if (regex_search(nums[j], regex(R"(\.)"))) {
				j++;
				nums[j] += str[i];
			}
			else nums[j] += str[i];
		}
		else if (regex_match(nums[j], regex(R"((\d)*\.(\d)+)"))) {
			j++;
		}
		else {
			nums[j] = "";
		}
	}

	for (int i = 0; i <= j; i++) {
		cout << stod(nums[i]) << endl;
	}
}