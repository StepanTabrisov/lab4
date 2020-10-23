#include "stdio.h"
#include "time.h"
#include "windows.h"
#include "conio.h"
#pragma warning (disable : 4996)


int* num;
int** arr;

void DFS(int v) {

	int t;

	printf("Посещенная вершина - %d\n", v + 1);
	num[v] = 1;


	for (t = 0; t <= 6; t++) {
		if (arr[v][t] == 1 && num[t] == 0) {

			DFS(t);
		}

	}


}


void main()

{

	int begin;
	int n;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	printf("Введите порядок массива - ");
	scanf("%d", &n);

	num = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		num[i] = 0;
	}
	arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) arr[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				arr[i][j] = rand() % 2;
				arr[j][i] = arr[i][j];
			}
			else if (i == j) arr[i][j] = 0;
		}
	}

	printf(" ");

	for (int k = 1; k <= n; k++) printf(" %d", k);

	printf("\n   -----------\n");

	for (int i = 0; i < n; i++) {

		printf("%d |", i + 1);

		for (int j = 0; j < n; j++) {

			printf("%d ", arr[i][j]);

		}

		printf("\n");

	}

	
	printf("Введите вершину с которой хотите начать обход ");
	scanf("%d", &begin);
	DFS(begin - 1);
	system("pause");
}