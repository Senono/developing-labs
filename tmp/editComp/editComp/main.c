//gcc main.c -o result
//./result

#include "an.c"

#define PROG_SIZE 10000
#define NUM_LAB 100
#define LAB_LEN 10
#define FOR_NEST 25 //������������ ����������� ����� FOR
#define SUB_NEST 25

struct label {
    char name[LAB_LEN];
    char* p;
};
struct label label_table[NUM_LAB];

void scanLabels(void);
void labelInit(void); //������������� �������� �����
void findEol(void); //����� ������ ��������� ������
int getNextLabel(char* s);
char* findLabel(char* s);

struct for_stack {
    int var; // ������� �����
    int target; //�������� ��������
    char* loc;
} fstack[FOR_NEST];
int ftos; //������ ������ ����� FOR

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

    //��������� ������ ��� ���������
    if (!(p_buf = (char*)malloc(PROG_SIZE))) {
        printf("������ ��� ��������� ������");
        exit(1);
    }

    //�������� ��������� ��� ����������
    if (!loadProgram(p_buf, fname)) exit(1);
    if (setjmp(e_buf)) exit(1); //������������� ������ ����������� ���������
    prog_now = p_buf;
    scanLabels();
    ftos = 0;
    gtos = 0;

    do {
        token_type = getToken();

        //�������� �� ������������ ��������� �����
        if (token_type == VARIABLE) {
            putBack();
            assignment(); //������ ���� �������� ������������
        }
        else
            switch (tok_inner) {
            case PRINT:
                print();
                break;
            case GOTO:
                exec_goto();
                break;
                //�� ����
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

//�������
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
        else {   //���������
            putBack();
            getExp(&answer);
            getToken();
            len += printf("%d", answer);
        }
        last_delim = *token;
        if (*token == ';') {  //���������� ����� �������� ��� �������� � ��������� ���������
            spaces = 8 - (len % 8);
            len += spaces;
            while (spaces) {
                printf(" ");
                spaces--;
            }
        }
        else if (*token == ',') /* ������ �� ������ */;
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
    getToken();     //����� �������� (����� ������)

    //����� �������������� ����� � ���������
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
        //�������� ������������ �� ���� ������� => ����������� ������� if
    }
    else findEol();
}

void exec_for() {
    struct for_stack i;
    int value;
    int tg;

    //������ ����������� ����������
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

    //���� ���� ����������� ��������� ���, ��������� ���������� � ����
    if (value >= variables[i.var]) {
        i.loc = prog_now;
        fpush(i);
    }
    else {   //���������� ���� �������
        while (tok_inner != NEXT) { getToken(); }
    }
}

void next() {
    struct for_stack i;

    i = fpop(); //������ ���������� � ����

    variables[i.var]++;//���������� ���������� �����
    if (variables[i.var] > i.target) { /*printf("end for\n");*/ return; }//�����
    fpush(i);//� ��������� ������ ��������� ����������
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
        gpush(prog_now); //���������� �����, ���� ����� ����� ���������
        prog_now = loc; //�����, ���� ���������
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
        //������ ���� ������ return;
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
        if (tok_inner != EOL) findEol(); //���� ������ �� ��������, ������� � ���������
    } while (tok_inner != FINISHED);
    prog_now = temp; // ����������� ������������ ��������
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
        if (!strcmp(label_table[t].name, s)) return -2;  //������������ ���� �����
    }
    return -1; //������ ����� ����������
}

char* findLabel(char* s) {
    register int t;

    for (t = 0; t < NUM_LAB; ++t)
        if (!strcmp(label_table[t].name, s)) return label_table[t].p;
    return 0;
}
