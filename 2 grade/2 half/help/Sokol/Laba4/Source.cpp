#include <iostream>
#include <fstream>

#define STACK_BUFFER 2

using namespace std;

int StrToInt(char* s)
{
	int temp = 0; // int
	int i = 0;
	int sign = 0; // sign of int
	if (s[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (s[i] >= 0x30 && s[i] <= 0x39 && s[i] != '\0')
	{
		temp = temp + (s[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	if (sign == 1)
		temp = -temp;
	return(temp);
}

class Stack
{
private:

	char* String = nullptr;
	int* Array = nullptr;
	int Length = 0;

public:

	Stack(char* Str)
	{
		String = Str;
		Array = new int[STACK_BUFFER];
	}

	~Stack()
	{
		delete[] String;
		delete[] Array;
	}

	int GetLength()
	{
		return Length;
	}

	void AddElement(int NewElem)
	{
		if (Length != STACK_BUFFER)
		{
			Array[Length] = NewElem;
			Length++;
		}
		else
			cout << "Error: Out of stack buffer" << endl;
	}

	void RemoveLastElement()
	{
		Length--;
	}

	int GetLastElement()
	{
		return Array[Length - 1];
	}

	bool CalculateString()
	{
		char* CurrentStr = new char[11];
		int CalcState = 0;
		int S = 0;

		int StrLen = strlen(String);
		for (int i = 0; i < StrLen; i++)
		{
			if (String[i] == ' ' || i == StrLen - 1)
			{
				S = 0;
				switch (CalcState)
				{
				case 0:
					AddElement(StrToInt(CurrentStr));
					CalcState++;
					for (int j = 0; j < 11; j++)
						CurrentStr[j] = '\0';
					break;
				case 1:
					AddElement(StrToInt(CurrentStr));
					CalcState++;
					for (int j = 0; j < 11; j++)
						CurrentStr[j] = '\0';
					break;
				case 2:
					CalcState--;
					if (CurrentStr[0] == '+')
					{
						int Result = GetLastElement();
						RemoveLastElement();
						Result += GetLastElement();
						RemoveLastElement();
						AddElement(Result);
						for (int j = 0; j < 11; j++)
							CurrentStr[j] = '\0';
					}
					else if (CurrentStr[0] == '-')
					{
						int Result = GetLastElement();
						RemoveLastElement();
						Result = GetLastElement() - Result;
						RemoveLastElement();
						AddElement(Result);
						for (int j = 0; j < 11; j++)
							CurrentStr[j] = '\0';
					}
					else if (CurrentStr[0] == '*')
					{
						int Result = GetLastElement();
						RemoveLastElement();
						Result *= GetLastElement();
						RemoveLastElement();
						AddElement(Result);
						for (int j = 0; j < 11; j++)
							CurrentStr[j] = '\0';
					}
					else if (CurrentStr[0] == '/')
					{
						int Result = GetLastElement();
						RemoveLastElement();
						Result = GetLastElement() / Result;
						RemoveLastElement();
						AddElement(Result);
						for (int j = 0; j < 11; j++)
							CurrentStr[j] = '\0';
					}
					else
					{
						cout << "Error: String couldn't be calculated" << endl;
						return false;
					}
				}
			}
			else
			{
				CurrentStr[S] = String[i];
				S++;
			}
		}
		delete[] CurrentStr;
		return true;
	}
};

int main()
{
	char* String = new char[64];
	ifstream File;
	File.open("File.txt", ifstream::in);
	if (!File.is_open())
		return false;
	if (!File.getline(String, 64))
	{
		File.close();
		cout << "Error: Couldn't read file" << endl;
		return 0;
	}
	else
		File.close();


	cout << "Your string: " << String << endl;
	Stack Obj(String);
	if (Obj.CalculateString())
		cout << "Result: " << Obj.GetLastElement() << endl;
	return 0;
}