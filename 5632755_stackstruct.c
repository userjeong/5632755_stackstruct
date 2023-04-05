#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_STACK_SIZE 10

typedef int element;
typedef struct {  //������ ����ü�� ����
    element data[MAX_STACK_SIZE];
    int top;

}StackType;

void init_stack(StackType* s);
void push(StackType* s, element item);
int is_full(StackType* s);
element pop(StackType* s);
int is_empty(StackType* s);

int main(void)
{
    StackType s;
    init_stack(&s);

    srand(time(NULL));
    for (int i = 1; i <= 30; i++)
    {
        int rand_num = rand() % 100 + 1;

        if ((rand_num % 2) == 1)
        {
            push(&s, rand_num);
            printf("[ %d ] Push %d\n", i, rand_num);
        }
        else
        {

            printf("[ %d ] Pop %d\n", i, pop(&s));
        }


    }
    system("pause");
}

void init_stack(StackType* s) //���� �ʱ�ȭ �Լ�
{
    s->top = -1;
}

void push(StackType* s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "Stack full!\n");
        return;
    }
    else s->data[++(s->top)] = item; //data[-1]���� [0]���� ������ص� item���� ����
}

int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "Stack Empty!\n");
        return (s->top = -1);
    }
    else return s->data[(s->top)--];
}

int is_empty(StackType* s)
{
    return (s->top == -1);
}
