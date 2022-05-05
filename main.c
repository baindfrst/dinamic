#include <stdio.h>
#include "queue.h"

int main(){
	printf("работа очереди в телефенной линии, вместо номеров - символы\n");
	printf("команды для работы:\n");
	printf("i - добавление в очередь\n");
	printf("o - извличение из очереди\n");
	printf("c - для проверки, входит ли номер в очередь и определения его индекса в очереди (индексация идет с начиная с 0, -1 - при отсутствии)\n");
	printf("b - для создания бекапа (автоматически происходит каждые 4 действия без сохранения)\n");
	printf("l - для вывода бекапа очереди\n");
	printf("k - для окончания работы\n");
	printf("q - для проверки нынешней очереди\n");
	int backup = 0;
	node* Call = NULL;
	node* Back = NULL;
	int a;
	printf("\nПервые дозвонившийся: ");
	scanf("%s", &a);
	pushQ((char)a, &Call);
	printQ(Call);
	printf("\nвыберите действие\n");
	scanf("%s", &a);
	while ((char)a != 'k')
	{
		if ((char)a == 'i')
		{
			printf("введите символ, который войдет в очередь: ");
			scanf("%s", &a);
			pushQ((char)a, &Call);
			printf("ввели %c\n", a);
		}
		else
		{
			if ((char)a == 'o')
			{
				printf("закончил работу: %c\n", popQ(&Call));
			}
			else
			{
				if ((char)a == 'c')
				{
					printf("введите символ, для проверки его присутствия: ");
					scanf("%s", &a);
					printf("//%d//", peakQ(Call, (char)a));
					if (peakQ(Call, (char)a) != -1)
					{
						printf("%c в очереди\n", a);
					}
					else
					{
						printf("%c не в очереди\n", a);
					}
				}
				else
				{
					if ((char)a == 'l')
					{
						printf("последний бекап очереди: ");
						printQ(Back);
						printf("\n");
					}
					else
					{
						if ((char)a == 'b')
						{
							freeQ(&Back);
							copyQ(&Back, Call);
							printf("сохранение прошло успешно\n");
							backup = -1;
						}
						else
						{
							if((char)a == 'q')
							{
								printf("нынешняя очередь: ");
								printQ(Call);
								printf("\n");
							}
							else
							{
								printf("неизвестный ввод");
							}
						}
					}
				}
			}
		}

		backup++;
		if (backup == 4)
		{
			freeQ(&Back);
			copyQ(&Back, Call);
			printf("сохранение прошло успешно автоматически\n");
			backup = 0;
		}
		printf("выбирите действие\n");
		scanf("%s", &a);
	}
	printf("остались в очереди: ");
	printQ(Call);
	if (emptyQ(Call)) printf("\nОчередь очищена\n");
	freeQ(&Call);
	return 0;
}

