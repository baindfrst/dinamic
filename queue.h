#ifndef __LISTS_H__
#define __LISTS_H__
typedef char type_of_elem; // для того, что бы изменить тип элементов очереди, замените char на тот тип, который вам необходим (изначально тип для элементов очереди является char)
typedef struct node // для создания очереди в программе надо написать "node* <имя вашей очереди>" 
{
    type_of_elem elem;
    struct node *next;
} node;

type_of_elem popQ(node**A); // извлекает из очереди элемент и возвращает его как значение функции
int lenQ(node*); // возвращает длинну очереди
void pushQ (type_of_elem c, node **A); // добавляет в очередь новый элемент
void printQ (node * p); // печатает все значения из очереди начиная с первого элемента
void freeQ(node ** p); // очищает память от очереди
int peakQ (node*p, type_of_elem c); // возвращает первое вхождение элемента в очередь
void copyQ(node**, node*); // копирует в 1 очередь 2 очередь
int emptyQ(node*); // проверяет, пуста ли очередь
int check_copyQ(node* , node* ); // проверяет, является 1 очередь копией очереди
node* firstQ(node *); // возвращает ссылку на начало очереди
node* lastQ(node*); // возвращает ссылку на конец очереди
void sortQ(node*); // сортирует очередь по неубыванию элементов

#endif

