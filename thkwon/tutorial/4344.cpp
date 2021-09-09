#include <stdio.h>
#include <string.h>

int ParseNumbers(char* parseText, int* arrayNumbers)
{
	int n = strlen(parseText);
	int currentNumber = 0;
	int numberCount = 0;
	for (int i = 0; i < n; i++)
	{
		char character = parseText[i];
		if (character == ' ')
		{
			arrayNumbers[numberCount] = currentNumber;
			numberCount++;
			currentNumber = 0;
		}
		else
		{
			currentNumber *= 10;
			currentNumber += character - '0';
		}
	}

	if (currentNumber != 0)
		arrayNumbers[numberCount++] = currentNumber;

	return numberCount;
}

int main()
{
	int count = 0;
	scanf("%d", &count);
	double answer;

	for (int i = 0; i < count; i++)
	{
		char arrayString[100000];
		int arrayNumbers[1000];
		int arrayCount = 0;
		scanf("%d", &arrayCount);

		//scanf("%d %[^\n]%*c", &arrayCount, arrayString);
		//if (arrayCount != ParseNumbers(arrayString, arrayNumbers))
		//	printf("Count Error! %d != %d\n", arrayCount, ParseNumbers(arrayString, arrayNumbers));

		// 평균 구하기
		long totalPoint = 0;
		for (int j = 0; j < arrayCount; j++)
		{
			scanf("%d", &arrayNumbers[j]);
			totalPoint += arrayNumbers[j];
		}
		double averagePoint = (double)totalPoint / (double)arrayCount;

		// 평균넘는 인원 구하기
		int overAverageCount = 0;
		for (int j = 0; j < arrayCount; j++)
			if (arrayNumbers[j] > averagePoint) overAverageCount++;

		answer = (double)overAverageCount * 100 / (double)arrayCount;
		printf("%.3lf%%\n", answer);
	}

	return 0;
}