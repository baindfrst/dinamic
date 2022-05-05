#include <stdio.h>
#include "queue.h"

int main(){
	printf("*Выбор седьмого дозвонившегося слушателя*\n");
	int i;
	int backup = 0;
	node* Call = NULL;
	node* Back = NULL;
	int a;
	for (i = 0; i < 3; i++){
		pushQ(a, &Call);
		a++;
	}
	printf("Первые дозвонившиеся:\n");
	printQ(Call);
	scanf("%s", a);
	while ((char)a != 'k')
	{
		if ((char)a == 'i')
		{
			pushQ((char)(a % 256), &Call);
			printf("ввели %c\n", (char)(a % 256));
		}
		if ((char)a == 'o')
		{
			popQ(&Call);
			printf("закончил работу: %c\n", (char)(a % 256));
		}
		if ((char)a == 'c')
		{
			if (peakQ(Call, (char)(a % 256)))
			{
				printf("%c в очереди", (char)(a % 256));
			}
			else
			{
				printf("%c не в очереди", (char)(a % 256));
			}
		}
		backup++;
		if (backup == 2)
		{
			copyQ(&Back, Call);
			printf("сохранение произошло\n");
			backup = 0;
		}
	}
	printf("Седьмой дозвонившийся слушатель: ");
	printQ(Call);
	popQ(&Call);
	if (emptyQ(Call)) printf("\nОчередь очищена\n");
	freeQ(&Call);
	return 0;
}

