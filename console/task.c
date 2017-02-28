#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

extern char _binary_students_txt_start[];
extern char _binary_students_txt_end;

#define ARRSZ(a) (sizeof (a) / sizeof (a)[0])

const char *tasks[] = {"tail", "head", "wc", "echo", "cat", "cp", "mv", "ar", "sort", "date", "du", "ls",};

int find(char *s, char *end)
{
    char *pos = strstr(_binary_students_txt_start, s);

    int num = -1;
    for(char *newline = _binary_students_txt_start; newline != NULL && newline < pos; newline = strchr(newline + 1, '\n'))
    {
        num++;
        volatile int r = rand();
    }
    return num;
}

int strrev(char *s, char *end)
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

void flip_name(char *name, char *surname, char *end)
{
    strrev(name, surname - 1);
    strrev(surname, end);
    strrev(name, end);
}

int main()
{
    _binary_students_txt_end = 0;

    srand(81771);

    char name[100];
    char fmt[] = "%99s";

    scanf(fmt, name);

    int sz = strlen(name);
    fmt[1] -= sz / 10;
    fmt[2] -= sz % 10;

    name[sz] = ' ';

    int name_sz = sz;

    scanf(fmt, name + sz + 1);
    
    sz = strlen(name + sz + 1);

    char *end = name + name_sz + 1 + sz + 1;

    int pos = find(name, end);
    if (pos == -1)
    {
        flip_name(name, name + name_sz + 1, end);
        pos = find(name, end);
        name_sz = sz;
    }

    if (pos == -1)
    {
        puts("U kidin mi!");
    }
    printf("pos %d\n", pos);
    int task_no = rand() % ARRSZ(tasks);
    printf("%d\n", task_no);
    printf("%s, Ваше задание -- реализовать консольную утилиту %s "
               "(см. https://www.opennet.ru/man.shtml?topic=%s&category=1 )\n",
           name + name_sz + 1,
           tasks[task_no],
           tasks[task_no]);


    return 0;
}
