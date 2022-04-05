#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Pick(char* item, int n, int picked[], int m, int toPick) {

	int i, lastIndex, smallest;

	if (toPick == 0) 
	{
		int pickedIndex;
		for (i = 0;i < n;i++) 
		{
			pickedIndex = picked[i];
			printf("%c ", item[pickedIndex]);
		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else smallest = picked[lastIndex] + 1;

	for (i = smallest;i < n;i++)
	{
		picked[lastIndex + 1] = i;
		Pick(item, n, picked, m, toPick - 1);
	}
}

int main(void) {

	char items[] = "ABCDEFG";
	int item_size = 7;
	int picked[3];

	Pick(items, item_size, picked, 3, 3);

	return 0;
}