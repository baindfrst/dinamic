#include <stdio.h>
#include "queue.h"

int main(){
	printf("*Выбор седьмого дозвонившегося слушателя*\n");
	int i;
	node* Call = NULL;
	char a = 'a';
	for (i = 0; i < 3; i++){
		pushQ(a, &Call);
		a++;
	}
	printf("Первые дозвонившиеся:\n");
	printQ(Call);
	printf("\nДобавление людей в очередь:");
	while (lenQ(Call) < 7){
		pushQ(a, &Call);
		printf("\nДозвонился ");
		printf("%c", lastQ(Call)->elem);
		a++;
	}
	printf("\nОчередь: ");
	printQ(Call);
	printf("\nУдаление из очереди всех, кроме седьмого:\n");
	do{
		printf("Отключается ");
		printf("%c", popQ(&Call));
		printf("\n");
	} while (Call != lastQ(Call));	
	printf("Седьмой дозвонившийся слушатель: ");
	printQ(Call);
	popQ(&Call);
	if (emptyQ(Call)) printf("\nОчередь очищена\n");
	freeQ(&Call);
	return 0;
}

