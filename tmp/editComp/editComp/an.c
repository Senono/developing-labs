#include "setjmp.h"
#include "math.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

//type of symbols
//ИЗМЕНИЛА
#define DELIMETR 111  //разделитель, операторы и скобки
#define VARIABLE 222
#define NUMBER 333
#define COMMAND 444
#define STRING 555 //временно используется в get_token, пока идет разбор лексемы
#define QUOTE 666

//commands
#define PRINT 1
#define INPUT 2
#define IF 3
#define THEN 4
#define FOR 5
#define NEXT 6
#define TO 7
#define GOTO 8
#define EOL 9   //конец строки программы
#define FINISHED 10
#define GOSUB 11
#define RETURN 12
#define END 13


char token[80];
char* prog_now;  //указатель на анализируемое выражение
int tok_inner, token_type;    //внутреннее представление лексемы, тип лексемы
jmp_buf e_buf; //буфер среды функции longjmp()

//int variables[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int amount = 0;
char *variables;

struct commands {
    char command[20];
    char tok;
} table[] = { "print", PRINT,
             "input", INPUT,
             "if", IF,
             "then", THEN,
             "goto", GOTO,
             "for", FOR,
             "next", NEXT,
             "to", TO,
             "gosub", GOSUB,
             "return", RETURN,
             "end", END,
             "", END }; //end of table


void sum2(int* result), mult3(int* result), deg4(int* result), unar5(int* result), expInPar6(int* result);
void primitive(int* result); //определение значения переменной по ее имени
void arith(char oper, int* res, int* hol), unary(char op, int* res), putBack(void);
int findVar(char* s);

int lookUp(char* s);   //поиск лексемы в таблице команд
int isDelim(char ch);   //проверка на разделитель
int isWhite(char ch);   //проверка на пробел
int getToken(void);
void getExp(int* result);
void serror(int er);


void getExp(int* result) {
    getToken();
    if (!*token) {
        serror(2);
        return;
    }
    sum2(result);
    putBack();
}

void putBack() {
    char* t;
    t = token;
    for (; *t; t++) prog_now--;
}

void sum2(int* result) {
    register char op;
    int hold;

    mult3(result);
    while ((op = *token) == '+' || op == '-') {
        getToken();
        mult3(&hold);
        arith(op, result, &hold);
    }
}

void mult3(int* result) {
    register char op;
    int hold;

    deg4(result);

    //ИСПРАВЛЕНИЕ
    //в книге вместо * стоит +
    while ((op = *token) == '*' || op == '/' || op == '%') {
        getToken();
        deg4(&hold);
        arith(op, result, &hold);
    }
}

void deg4(int* result) {
    int hold;

    unar5(result);
    if (*token == '^') {
        getToken();
        //ИСПРАВЛЕНИЕ
        //в книге функция lvl4
        unar5(&hold);
        //deg4(&hold);
        arith('^', result, &hold);
    }
}

void unar5(int* result) {
    register char op;

    op = 0;
    if ((token_type == DELIMETR) && (*token == '+' || *token == '-')) {
        op = *token;
        getToken();
    }
    expInPar6(result);
    if (op) unary(op, result);
}

void expInPar6(int* result) {
    if ((*token == '(') && (token_type == DELIMETR)) {
        getToken();
        sum2(result);
        if (*token != ')') serror(1);
        getToken();
    }
    else primitive(result);
}

void primitive(int* result) {
    switch (token_type) {
    case VARIABLE:
        *result = findVar(token);
        getToken();
        return;
    case NUMBER:
        *result = atoi(token);
        getToken();
        return;
    default:
        serror(0);

    }
}

void unary(char op, int* res) {
    if (op == '-') *res = -(*res);
}

void arith(char oper, int* res, int* hol) {
    register int tmp, exp;

    switch (oper) {
    case '-':
        *res = *res - *hol;
        break;
    case '+':
        *res = *res + *hol;
        break;
    case '*':
        *res = *res * *hol;
        break;
    case '/':
        *res = (*res) / (*hol);
        break;
    case '%':
        tmp = (*res) / (*hol);
        *res = *res - (tmp * (*hol));
        break;
    case '^':
        exp = *res;
        if (*hol == 0) {
            *res = 1;
            break;
        }
        for (tmp = *hol - 1; tmp > 0; --tmp)
            *res = (*res) * exp;
        break;
    }
}

//получить лексему
int getToken() {
    register char* temp;

    token_type = 0; tok_inner = 0;
    temp = token;

    if (*prog_now == 0) {// '\0'
        *token = 0;
        tok_inner = FINISHED;

        return(token_type = DELIMETR);
    }

    while (isWhite(*prog_now)) ++prog_now;

    //printf("%c %d\n", *prog_now, *prog_now);
    //"возврат каретки" - конец строки программы ???
    //  /r
    if (*prog_now == 10) {// '\r'
        //printf("FIND\n");
        ++prog_now;
        //++prog_now;
        tok_inner = EOL; *token = 10; // '\r'
        //token[1] = 10;// \n
        //token[2] = 0;

        //мой вариант
        token[1] = 0;

        return(token_type = DELIMETR);
    }

    if (strchr("+-*^/%=;(),><", *prog_now)) {
        *temp = *prog_now;
        prog_now++; temp++;
        *temp = 0;

        return(token_type = DELIMETR);
    }

    if (*prog_now == '"') {
        prog_now++;
        while (*prog_now != '"' && *prog_now != 10) *temp++ = *prog_now++; // 10 -> '\r'
        if (*prog_now == 10) serror(1);// \r
        prog_now++; *temp = 0;

        return(token_type = QUOTE);
    }

    if (isdigit(*prog_now)) {
        while (!isDelim(*prog_now)) *temp++ = *prog_now++;
        *temp = 0;// \0

        return(token_type = NUMBER);
    }

    //ЗАМЕНА МЕТОДА
    if (isalpha(*prog_now)) {
        while (!isDelim(*prog_now)) *temp++ = *prog_now++;
        token_type = STRING;
    }

    *temp = 0;// \0

    if (token_type == STRING) {
        tok_inner = lookUp(token);
        if (!tok_inner) {
            token_type = VARIABLE;
            variables = (char*)realloc(variables, sizeof(char) * (++amount));
            variables[amount - 1] = *token;
        }
        else {
            token_type = COMMAND;
        }
    }

    return token_type;
}

int lookUp(char* s) {
    register int i;
    char* p;

    //в нижний рег
    p = s;
    while (*p) { *p = tolower(*p); p++; }

    for (i = 0; *table[i].command; i++)
        if (!strcmp(table[i].command, s))
            return table[i].tok;
    return 0;
}

int isDelim(char ch)
{
    if (strchr(" !;,+-<>'/*%^=()", ch) || ch == 9 ||
        ch == 10 /* \r */ || ch == 0) return 1;
    return 0;
}

int isWhite(char ch)
{
    if (ch == 32 || ch == 9) return 1;// \t
    else return 0;
}

int findVar(char* s) {
    if (!isalpha(*s)) {
        serror(4);
        return 0;
    }
    int tmp = 0;
    while (tmp < amount) {
        if (!strcmp(variables[tmp], s))
            return tmp;
    }
    serror(14);
    return 0;
}

void serror(error) int error; {
    static char* e[] = {
        "\nСинтаксическая ошибка",
        "\nНепарные круглые скобки",
        "\nЭто не выражение",
        "\nПредполагается символ равенства",
        "\nНе переменная",
        "\nТаблица меток переполнена",
        "\nДублирование меток",
        "\nНеопределенная метка",
        "\nНеобходим оператор THEN",
        "\nНеобходим оператор TO",
        "\nУровень вложенности цикла FOR слишком велик",
        "\nNEXT не соответствует FOR",
        "\nУровень вложенности GOSUB слишком велик",
        "\nRETURN не соответствует GOSUB",
        "\nПеременная не найдена"};
    printf("&4%s\n", e[error]);
    longjmp(e_buf, 1); //возврат в точку сохранения
}
