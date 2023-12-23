#include <iostream>
#include <iomanip> genMatrix
#include <Windows.h>

using namespace std;

const int N1 = 6, N2 = 8, N3 = 10;

void Matrix(int* arr, int N)
{
	int* end = arr + N * N - 1;
	for (int* i = arr; i <= end; i++) {
		*i = 0;
	}
}

void printMatrix(int* arr, int N)
{
	int* end = arr + N * N - 1;
	for (int* i = arr; i <= end; i++) {
		cout << setw(4) << *i;
		if ((i - arr + 1) % N == 0) {
			cout << '\n';
		}
	}
}

void genMatrix(int* arr, int N)
{
	int* end = arr + N * N - 1;
	for (int* i = arr; i <= end; i++) {
		*i = rand() % (N * N) + 1;
	}
}

void SpiralMatrix(int* arr, int N)
{
	Matrix(arr, N);
	printMatrix(arr, N);
	for (int i = 0; i < N / 2; i++) {
		int* p1 = arr + i * (N + 1);
		int* p2 = arr +  (i + 1) * (N - 1);
		int* p3= arr + (N * N - 1) - i * (N + 1);
		int* p4 = arr + (N * N - N) - i * (N - 1);
		for (int* j = p1; j < p2; j++) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(arr, N);
			Sleep(52);
		}
		for (int* j = p2; j < p3; j += N) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(arr, N);
			Sleep(52);
		}
		for (int* j = p3; j > p4; j--) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(arr, N);
			Sleep(52);
		}
		for (int* j = p4; j > p1; j -= N) {
			*j = rand() % (N * N) + 1;
			system("cls");
			printMatrix(arr, N);
			Sleep(52);
		}
	}
}

void SnakeMatrix(int* arr, int N)
{
	Matrix(arr, N);
	printMatrix(arr, N);
	Sleep(52);
	for (int i = 0; i < N / 2; i++)
	{
		int* p1 = arr + i * 2;
		int* p2 = arr + N * (N - 1) + i * 2;
		for (int* i = p1; i <= p2; i += N)
		{
			*i = rand() % (N * N) + 1;
			system("cls");
			printMatrix(arr, N);
			Sleep(52);
		}
		for (int* i = p2 + 1; i >= p1 + 1; i -= N)
		{
			*i = rand() % (N * N) + 1;
			system("cls");
			printMatrix(arr, N);
			Sleep(52);
		}
	}
}

void createBlocks(int* arr, int N)
{
	int* end = arr + N * N - 1;
	int* start = arr + N / 2 - 1;
	int* mid = arr + (N * N / 2) - 1;
	cout << "\n\n";
	for (int* i = arr; i <= end; i++) {
		cout << setw(4) << *i;
		if (((i - arr + 1) % (N / 2) == 0) && ((i - arr + 1) % N != 0)) {
			cout << "  ";
		}
		if (((i - arr + 1) % ((N * N) / 2) == 0) && ((i - arr + 1) % (N * N) != 0)) {
			cout << '\n' << " ";
		}
		if ((i - arr + 1) % N == 0) {
			cout << '\n';
		}
	}
}

void swapCross(int* arr, int N)
{
	for (int i = 0; i < (N * N / 4); i++) {
		int* p1 = arr + (i / (N / 2)) * N + (i % (N / 2));
		int* p2 = p1 + (N / 2);
		int* p4 = p2 + (N / 2) * N;
		int* p3 = p4 - (N / 2);

		int temp = *p2;
		*p2 = *p1;
		int temp1 = *p4;
		*p4 = temp;
		temp = *p3;
		*p3 = temp1;
		*p1 = temp;
	}
	createBlocks(arr, N);
}

void swapDiagonally(int* arr, int N)
{
	for (int i = 0; i < (N * N / 4); i++) {
		int* p1 = arr + (i / (N / 2)) * N + (i % (N / 2));
		int* p2 = p1 + (N / 2);
		int* p3 = p2 + (N / 2) * N;
		int* p4 = p3 - (N / 2);
		swap(*p1, *p3);
		swap(*p2, *p4);
	}
	createBlocks(arr, N);
}

void swapVerticall(int* arr, int N)
{
	for (int i = 0; i < (N * N / 4); i++) {
		int* p1 = arr + (i / (N / 2)) * N + (i % (N / 2));
		int* p2 = p1 + (N / 2);
		int* p4 = p2 + (N / 2) * N;
		int* p3 = p4 - (N / 2);
		swap(*p1, *p3);
		swap(*p2, *p4);
	}
	createBlocks(arr, N);
}

void swapHorizontall(int* arr, int N)
{
	for (int i = 0; i < (N * N / 4); i++) {
		int* p1 = arr + (i / (N / 2)) * N + (i % (N / 2));
		int* p2 = p1 + (N / 2);
		int* p4 = p2 + (N / 2) * N;
		int* p3 = p4 - (N / 2);
		swap(*p1, *p2);
		swap(*p3, *p4);
	}
	createBlocks(arr, N);
}

void shakerSort(int* arr, int N)
{
	int* p1 = arr, * p2 = arr + N - 1;
	while (p1 < p2)
	{
		for (int* i = p1; i < p2; i++)
		{
			if (*i > *(i + 1))
				swap(*i, *(i + 1));
		}
		p2--;
		for (int* i = p2; i > p1; i--)
		{
			if (*(i - 1) > *i)
				swap(*i, *(i - 1));
		}
		p1++;
	}
}


void action(int* arr, int N)
{
	setlocale(0, "");
	int x, a;
	cout << "\nВедите число:\n";
	cin >> a;
	cout << "\nКакое действие необходимо сделать?\n"
		<< "1 - Сложение\n"
		<< "2 - Вычитание\n"
		<< "3 - Умножение\n"
		<< "4 - Деление\n"
		<< "0 - Выход в меню\n\n";
	cin >> x;
	cout << '\n';
	int* p = arr + N * N - 1;
	switch (x)
	{
	case 1:
		for (int* i = arr; i <= p; i++)
			*i += a;
		printMatrix(arr, N);
		break;
	case 2:
		for (int* i = arr; i <= p; i++)
			*i -= a;
		printMatrix(arr, N);
		break;
	case 3:
		for (int* i = arr; i <= p; i++)
			*i *= a;
		printMatrix(arr, N);
		break;
	case 4:
		for (int* i = arr; i <= p; i++)
			*i /= a;
		printMatrix(arr, N);
		break;
	case 0:
		break;
	default:
		cout << "Ошибка!";
		system("Pause");
		action(arr, N);
		break;
	}
}

void idz(int* arr, int N)
{
	cout << "\n\n\n";
	for (int i = 1; i < N * N; i++)
	{
		int* p1 = arr + (i / N * N) + (i % N);
		int* p2 = arr + (i / N) + (i % N * N);
		swap(*p1, *p2);
		if (i % N == (N - 1))
			i += i / N + 1;
		printMatrix(arr, N);
		cout << "\n\n";
		Sleep(50);
	}
}

void menu(int* arr, int N)
{
	setlocale(0, "");
	int x;
	cout << "Какой пункт вы хотите запустить?:\n"
		<< "1 - Заполнить матрицу по спирали\n"
		<< "2 - Заполнить матрицу змейкой\n"
		<< "3 - Поменять местами блоки матрицы по часовой стрелке\n"
		<< "4 - Поменять местами блоки матрицы по диагонали.\n"
		<< "5 - Поменять местами блоки матрицы по вертикали\n"
		<< "6 - Поменять местами блоки матрицы по горизонтали\n"
		<< "7 - Отсортировать матрицу\n"
		<< "8 - Прибавить / вычесть / уможить / разделить матрицу на число\n"
		<< "9 - ИДЗ\n"
		<< "0 - Выход\n\n";
	cin >> x;
	switch (x)
	{
	case 1:
		system("cls");
		SpiralMatrix(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 2:
		system("cls");
		SnakeMatrix(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 3:
		system("cls");
		genMatrix(arr, N);
		createBlocks(arr, N);
		swapCross(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 4:
		system("cls");
		genMatrix(arr, N);
		createBlocks(arr, N);
		swapDiagonally(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 5:
		system("cls");
		genMatrix(arr, N);
		createBlocks(arr, N);
		swapVerticall(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 6:
		system("cls");
		genMatrix(arr, N);
		createBlocks(arr, N);
		swapHorizontall(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 7:
		system("cls");
		genMatrix(arr, N);
		printMatrix(arr, N);
		cout << "\n";
		shakerSort(arr, N*N);
		printMatrix(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 8:
		system("cls");
		genMatrix(arr, N);
		printMatrix(arr, N);
		action(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 9:
		system("cls");
		genMatrix(arr, N);
		printMatrix(arr, N);
		idz(arr, N);
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	case 0:
		exit(1);
	default:
		cout << "Ошибка!";
		system("Pause");
		system("cls");
		menu(arr, N);
		break;
	}
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int x, matrix1[N1][N1], matrix2[N2][N2], matrix3[N3][N3];
	int* m1 = *matrix1, * m2 = *matrix2, * m3 = *matrix3;
	cout << "Введите размер матрицы (6, 8 ,10):\n";
	cin >> x;
	switch (x)
	{
	case 6:
		system("cls");
		menu(m1, N1);
		break;
	case 8:
		system("cls");
		menu(m2, N2);
		break;
	case 10:
		system("cls");
		menu(m3, N3);
		break;
	default:
		cout << "Ошибка!\n";
		system("Pause");
		system("cls");
		main();
		break;
	}
	return 0;
}

