// А. Tokitsukaze и улучшение
#include <iostream>	
#include <cmath>
using namespace std;

int main()
{
	int hp;
	int category = 4;
	cin >> hp;
	cout << "\n" << endl;

	if (hp % 4 == 1) {
		cout << 0;
		category = 1;
	}
	else {
		if (hp % 4 == 3) {
			// 2 > 0 > 1
			if (hp + 2 < 101) {
				hp += 2;
				cout << 2;
				category = 1;
			}
			else {
				cout << 0;
				category = 2;
			}
		}
		else if (hp % 4 == 2) {
			// 1 > 0 > 2
			if (hp + 1 < 101) {
				hp++;
				cout << 1;
				category = 2;
			}
			else {
				cout << 0;
				category = 3;
			}
		}
		else {
			// 1 > 2 > 0
			if (hp + 1 < 101) {
				hp++;
				cout << 1;
				category = 1;
			}
			else if (hp + 2 < 101) {
				hp += 2;
				cout << 2;
				category = 3;
			}
			else {
				cout << 0;
				category = 4;
			}
		}
	}

	switch (category)
	{
	case 1:
		cout << " A";
		break;
	case 2:
		cout << " B";
		break;
	case 3:
		cout << " C";
		break;
	default:
		cout << " D";
		break;
	}



	return 0;
}