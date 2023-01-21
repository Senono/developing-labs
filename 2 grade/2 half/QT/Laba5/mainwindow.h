#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define STACK_BUFFER 2

class Stack
{
private:

    int* Array;
    int Length = 0;

public:

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

    Stack()
    {
        Array = new int[STACK_BUFFER];
    }

    ~Stack()
    {
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
    }

    void RemoveLastElement()
    {
        Length--;
    }

    int GetLastElement()
    {
        return Array[Length - 1];
    }

    bool CalculateString(char* String)
    {
        Length = 0;
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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool GetStringFromFile();

    Stack* StackObj;

private slots:
    void on_FileButton_clicked();

    void on_CalculateButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
