#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	int index;
	struct stack *pPrev;
}stack;

stack *push(stack *pStack, int n)
{
	stack *pNew = malloc(sizeof(*pNew));
	pNew->index = n;
	pNew->pPrev = pStack;
	return pNew; 
}

stack *pop(stack *pStack)
{
	stack *pDel = pStack;
	pStack = pStack->pPrev;
	free(pDel);
	return pStack;
}


int main(void)
{
	stack *loop;
	char machine[30000], word[100001], desc[100001];
	int i, instNumber, indexMach, indexWord, indexDesc;
	
	scanf("%d", &instNumber);
	for (i = 1; i <= instNumber; i++)
	{
		printf("Instancia %d\n", i);
		indexMach = indexWord = indexDesc = 0;
		memset(machine, 0, sizeof(machine));
		scanf("%s%s", word, desc);
		while (desc[indexDesc] != '\0')
		{
			switch (desc[indexDesc])
			{
				case '>': indexMach++;
				break;
				case '<': indexMach--;
				break;
				case '+': machine[indexMach]++;
				break;
				case '-': machine[indexMach]--;
				break;
				case '.': printf("%c", machine[indexMach]);
				break;
				case ',':
				{
					if (word[indexWord] != '\0')
					{
						machine[indexMach] = word[indexWord];
						indexWord++;
					}
					else machine[indexMach] = 0;
				}
				break;
				case '[':
				{
					if (machine[indexMach] != 0 ) loop = push(loop, indexDesc);
					else
					{
						int loops = 0;
						do
						{
						    if(desc[indexDesc] == '[') loops++;
						    else if (desc[indexDesc] == ']') loops--;
						    indexDesc++;
						}while (loops);
						continue;
					}
				} 
				break;
				case ']':
				{
					if (machine[indexMach] != 0 ) indexDesc = loop->index;
					else loop = pop(loop);
				}	
				break;
				case '#': printf("%.10s", machine);
				break;
			}
			indexDesc++;
		}
		printf("\n\n");
	}
	return 0;
}