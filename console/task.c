#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

extern char _binary_students_txt_start[];
extern char _binary_students_txt_end;

#define ARRSZ(a) (sizeof (a) / sizeof (a)[0])

static const char *tasks[] = {"tail", "head", "wc", "echo", "cat", "cp", "mv", "ar", "sort", "date", "du", "ls",};

static int find(char *s, char *end)
{
    char *pos = strstr(_binary_students_txt_start, s);

    int num = -1;
    for (char *newline = _binary_students_txt_start; newline != NULL && newline <= pos; newline = strchr(newline + 1, '\n'))
    {
        num++;
        volatile int r = rand();
    }
    return num;
}

static int strrev(char *s, char *end)
{
    char c;
    while (s < end - 1)
    {
        --end;

        c = *s;
        *s = *end;
        *end = c;

        ++s;
    }
}

static void flip_name(char *name, char *surname, char *end)
{
    strrev(name, surname - 1);
    strrev(surname, end);
    strrev(name, end);
}

static void ye_to_yo(char *s)
{
    do
    {
        *s += *s == (char)0xb8 || *s == (char)0xa8 ? 0xe5 - 0xb8 : 0;
    } while (*s++);
}

void utf8_to_cp1251(char*);


int main()
{
    _binary_students_txt_end = 0;

    ye_to_yo(_binary_students_txt_start);

    srand(13372018);

    char wname[100], name[100];
    char fmt[] = "%99s";

    puts("Введите имя и фамилию");
    scanf(fmt, name);

    int sz = strlen(name);
    fmt[1] -= sz / 10;
    fmt[2] -= sz % 10;

    name[sz] = ' ';

    scanf(fmt, name + sz + 1);

    int name_sz = sz;

    sz = strlen(name + sz + 1);
    
    strcpy(wname, name);

    utf8_to_cp1251(name);
    

    char *wend = wname + name_sz + 1 + sz + 1;
    char *end  = name + name_sz / 2 + sz / 2 + 2;

    int pos = find(name, end);
    if (pos == -1)
    {
        flip_name(name, name + name_sz / 2 + 1, end - 1);
        flip_name(wname, wname + name_sz + 1, wend - 1);

        pos = find(name, end);
        name_sz = sz;
    }

    if (pos == -1)
    {
        puts("U kidin mi!");
        return 0;
    }
    
    int task_no = rand() % ARRSZ(tasks);

    printf("%s, Ваше задание -- реализовать консольную утилиту %s "
               "(см. https://www.opennet.ru/man.shtml?topic=%s&category=1)\n"
               "В качестве альтернативы также возможно выполнить задание по ссылке: http://imcs.dvfu.ru/works/task_view?id=51758\n",
           wname + name_sz + 1,
           tasks[task_no],
           tasks[task_no]);


    return 0;
}
