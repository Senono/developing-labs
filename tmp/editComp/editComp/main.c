//gcc main.c -o result
//./result

#include "an.c"

#define PROG_SIZE 10000
#define NUM_LAB 100
#define LAB_LEN 10
#define FOR_NEST 25 //максимальная вложенность цикла FOR
#define SUB_NEST 25

struct label {
    char name[LAB_LEN];
    char* p;
};
struct label label_table[NUM_LAB];

void scanLabels(void);
void labelInit(void); //инициализация массивов меток
void findEol(void); //поиск начала следующей строки
int getNextLabel(char* s);
char* findLabel(char* s);

struct for_stack {
    int var; // счетчик цикла
    int target; //конечное значение
    char* loc;
} fstack[FOR_NEST];
int ftos; //индекс начала стека FOR

void fpush(i)
struct for_stack i;
{
    if (ftos > FOR_NEST)
        serror(10);
    fstack[ftos] = i;
    ftos++;
}

struct for_stack fpop(void) {
    ftos--;
    if (ftos < 0) serror(11);
    return(fstack[ftos]);
}

char* gstack[SUB_NEST];
int gtos;
void greturn(void);
void gpush(char* s);
char* gpop(void);

int loadProgram(char* p, char* fname);
void assignment(void);
void print(void);
void input(void);
void exec_goto(void);
void exec_if(void);
void exec_for(void);
void next(void);
void gosub(void);

int main(int argc, char* argv[]) {
    char in[80];
    int answer;
    char* p_buf;
    char* t;
    char* fname = "proga1.txt";

    //выделение памяти для программы
    if (!(p_buf = (char*)malloc(PROG_SIZE))) {
        printf("Ошибка при выделении памяти");
        exit(1);
    }

    //загрузка программы для выполнения
    if (!loadProgram(p_buf, fname)) exit(1);
    if (setjmp(e_buf)) exit(1); //инициализация буфера нелокальных переходов
    prog_now = p_buf;
    scanLabels();
    ftos = 0;
    gtos = 0;

    do {
        token_type = getToken();

        //проверка на соответствие оператору языка
        if (token_type == VARIABLE) {
            putBack();
            assignment(); //должен быть оператор присваивания
        }
        else
            switch (tok_inner) {
            case PRINT:
                print();
                break;
            case GOTO:
                exec_goto();
                break;
                //не было
            case IF:
                exec_if();
                break;
            case FOR:
                exec_for();
                break;
            case NEXT:
                next();
                break;
            case INPUT:
                input();
                break;
            case GOSUB:
                gosub();
                break;
            case RETURN:
                greturn();
                break;
            case END:
                exit(0);
            }
    } while (tok_inner != FINISHED);
}

int loadProgram(char* p, char* fname) {
    FILE* fp;
    int i = 0;
    if (!(fp = fopen(fname, "rb"))) return 0;

    i = 0;
    do {
        *p = getc(fp);
        p++; i++;
    } while (!feof(fp) && i < PROG_SIZE);
    *(p - 2) = 0;// \0
    fclose(fp);
    return 1;
}

void assignment() {
    int var, value;

    getToken();
    if (!isalpha(*token)) {
        serror(4);
        return;
    }

    var = toupper(*token) - 'A';

    getToken();
    if (*token != '=') {
        serror(3);
        return;
    }

    getExp(&value);
    variables[var] = value;
}

//команды
void print(void) {
    int answer;
    int len = 0, spaces;
    char last_delim = 0;// \0

    do {
        getToken();
        if (tok_inner == EOL || tok_inner == FINISHED) break;
        if (token_type == QUOTE) {
            printf("%s", token);
            len += strlen(token);
            getToken();
        }
        else {   //выражение
            putBack();
            getExp(&answer);
            getToken();
            len += printf("%d", answer);
        }
        last_delim = *token;
        if (*token == ';') {  //вычисление числа пробелов при переходе к следующей табуляции
            spaces = 8 - (len % 8);
            len += spaces;
            while (spaces) {
                printf(" ");
                spaces--;
            }
        }
        else if (*token == ',') /* ничего не делать */;
        else if (tok_inner != EOL && tok_inner != FINISHED) serror(0);
    } while (*token == ';' || *token == ',');

    if (tok_inner == EOL || tok_inner == FINISHED) {
        if (last_delim != ';' && last_delim != ',')
            printf("\n");
        else serror(0);
    }
}

void exec_goto() {
    char* loc;
    getToken();     //метка перехода (номер строки)

    //поиск местоположения метки в программе
    loc = findLabel(token);
    if (loc == 0) serror(7);// \0
    else prog_now = loc;
}

void exec_if() {
    int x, y, cond;
    char op;

    getExp(&x);
    getToken();
    if (!strchr("=<>", *token)) {
        serror(0);
        return;
    }
    op = *token;
    getExp(&y);

    cond = 0;
    switch (op) {
    case '=':
        if (x == y) cond = 1;
        break;
    case '<':
        if (x < y) cond = 1;
        break;
    case '>':
        if (x > y) cond = 1;
        break;
    }

    if (cond) {
        getToken();
        if (tok_inner != THEN) {
            serror(8);
            return;
        }
        //програма продолжается со след строчки => выполняется условие if
    }
    else findEol();
}

void exec_for() {
    struct for_stack i;
    int value;
    int tg;

    //чтение управляющей переменной
    getToken();
    if (!isalpha(*token)) {
        serror(4);
        return;
    }
    //
    i.var = toupper(*token) - 'A';

    getToken();
    if (*token != '=') {
        serror(3);
        return;
    }

    getExp(&value);
    variables[i.var] = value;
    getToken();
    if (tok_inner != TO) serror(9);
    getExp(&tg); //i.target
    i.target = tg;

    //если цикл выполняется последний раз, поместить информацию в стек
    if (value >= variables[i.var]) {
        i.loc = prog_now;
        fpush(i);
    }
    else {   //пропустить цикл целиком
        while (tok_inner != NEXT) { getToken(); }
    }
}

void next() {
    struct for_stack i;

    i = fpop(); //чтение информации о цикл

    variables[i.var]++;//увеличение переменной цикла
    if (variables[i.var] > i.target) { /*printf("end for\n");*/ return; }//конец
    fpush(i);//в противном случае запомнить информацию
    prog_now = i.loc;
}

void input(void) {
    char str[80], var;
    int i;

    getToken();
    if (token_type == QUOTE) {
        printf("%s", token);
        getToken();
        if (*token != ',') serror(1);
        getToken();
    }
    else printf("? ");
    var = toupper(*token) - 'A';
    scanf("%d", &i);
    variables[var] = i;
}

void gosub() {
    char* loc;

    getToken();
    loc = findLabel(token);
    if (loc == 0) serror(7);// \0
    else {
        gpush(prog_now); //запоминаем место, куда нужно будет вернуться
        prog_now = loc; //место, куда переходим
    }
}

void greturn() {
    prog_now = gpop();
}

void gpush(char* s) {
    gtos++;
    if (gtos == SUB_NEST) {
        serror(12);
        return;
    }
    gstack[gtos] = s;
}

char* gpop() {
    if (gtos == 0) {
        serror(13);
        //ДОЛЖЕН БЫТЬ ПРОСТО return;
        return 0;
    }
    return (gstack[gtos--]);
}

void scanLabels() {
    register int loc;
    char* temp;

    labelInit();
    temp = prog_now;
    getToken();
    if (token_type == NUMBER) {
        strcpy(label_table[0].name, token);
        label_table[0].p = prog_now;
    }

    findEol();
    do {
        getToken();
        if (token_type == NUMBER) {
            loc = getNextLabel(token);
            if (loc == -1 || loc == -2) {
                (loc == -1) ? serror(5) : serror(6);
            }
            strcpy(label_table[loc].name, token);
            label_table[loc].p = prog_now;
        }
        if (tok_inner != EOL) findEol(); //если строка не помечена, переход к следующей
    } while (tok_inner != FINISHED);
    prog_now = temp; // восстановка изначального значения
}

void labelInit() {
    register int t;
    for (t = 0; t < NUM_LAB; ++t)
        label_table[t].name[0] = 0;// \0
}

void findEol() {
    while (*prog_now != 10 && *prog_now != 0) ++prog_now; // \n \0
    if (*prog_now) prog_now++;
}

int getNextLabel(char* s) {
    register int t;

    for (t = 0; t < NUM_LAB; ++t) {
        if (label_table[t].name[0] == 0) return t;
        if (!strcmp(label_table[t].name, s)) return -2;  //дублирование имен меток
    }
    return -1; //массив меток переполнен
}

char* findLabel(char* s) {
    register int t;

    for (t = 0; t < NUM_LAB; ++t)
        if (!strcmp(label_table[t].name, s)) return label_table[t].p;
    return 0;
}
