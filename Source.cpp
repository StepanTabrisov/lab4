#include "stdio.h"
#include "time.h"
#include "windows.h"
#include "conio.h"
#pragma warning (disable : 4996)

void DFS(int v, int* mass, int size, int** arr) {

	printf("Посещенная вершина - %d\n", v + 1);
	mass[v] = 1;
	for (int i = 0; i <= size; i++) {
		if ((arr[v][i] == 1) && (mass[i] == 0)) {
			DFS(i, mass, size, arr);
		}
	}
}
void main()
{
	int begin;
	int n;
	int** arr1;
	int* num;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	printf("Введите порядок массива - ");
	scanf("%d", &n);

	num = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		num[i] = 0;
	}
	arr1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) arr1[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				arr1[i][j] = rand() % 2;
				arr1[j][i] = arr1[i][j];
			}
			else if (i == j) arr1[i][j] = 0;
		}
	}
	printf(" ");
	for (int k = 1; k <= n; k++) printf(" %d", k);
	printf("\n   -----------\n");
	for (int i = 0; i < n; i++) {
		printf("%d |", i + 1);
		for (int j = 0; j < n; j++) {
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("Введите вершину с которой хотите начать обход: ");
	scanf("%d", &begin);
	DFS(begin - 1, num, n, arr1);
	free(arr1);
	system("pause");
}
