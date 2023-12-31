﻿#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], const int length, int left, int rigth) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (rigth - left) + left;
}
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}


template <typename T>
void arr_app(T*& arr, int length, int num) {

	// шаг 0. Защита от лишних действий
	if (num <= 0)
		return;
	
	//Шаг 1. Выделение памяти под новый массив нужного рамера
	T* tmp = new T[length + num]{};

	//шаг 2. Копирование значений старого массива в новый 
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];

	//Шаг 3. Освобождение памяти, выделенной под старый массив
	delete[] arr;

	//Шаг 4. Перенаправление указателя на новый массив.
	arr = tmp; 

}

template <typename T>
void arr_del(T*& arr, int length, int num) {
	if (num <= 0)
		return;
	if (num >= length) {
		delete[] arr;
		arr = nullptr;
		return;
	}

	T* tmp = new T[length - num];
	for (int i = 0; i < length - num; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}








int main() {
	setlocale(0, "");
	int n;





	//Выделение динамической памяти 
	
	int* pointer = new int; // Выдиление участка динамической памяти размером в тип int (4 byte)

	*pointer = 7;
	std::cout << "*pointer = " << *pointer << std::endl;
	std::cout << "pointer = " << pointer << std::endl;

	delete pointer; // Освобождение памяти, выделенной динамически.
	pointer = nullptr;

	if(pointer == nullptr)
		pointer = new int;

	*pointer = 15;
	std::cout << "*pointer = " << *pointer << std::endl;
	std::cout << "pointer = " << pointer << std::endl;

	delete pointer;
	pointer = nullptr;
	

	//Одномерные динамические массивы 
	
	std::cout << "Введите длинну массива -> ";
	int dsize;
	std::cin >> dsize;
	int* darr = new int[dsize];
	fill_arr(darr, dsize, 1, 10);

	std::cout << "Массив:\n";
	print_arr(darr, dsize);

	delete[] darr;
	

	// Двумерные динамические массивы
	
	int rows = 5, cols = 4;
	//int* mx = new int[rows][cols]; // НЕ РАБОТАЕТ
	
	int** mx = new int*[rows];
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];


	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[] mx;
	


	//Задача 1. Увеличение размера массива. 
	
	std::cout << "Введите размер массива -> ";
	int size1;
	std::cin >> size1;

	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr1, size1);

	std::cout << "Введите кол-во новых элементов -> ";
	std::cin >> n;
	arr_app(arr1, size1, n);
	if (n > 0)
		size1 += n;

	std::cout << "Итоговый массив:\n";
	print_arr(arr1, size1);
	

	delete[] arr1;
	

	//Задача 2. Уменьшение размера массива

	std::cout << "Задача 2.\n\n";
	std::cout << "Введите размер массива -> ";
	int size2;
	std::cin >> size2;

	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr2, size2);

	std::cout << "Введите кол-во элементов для удаления -> ";
	std::cin >> n;
	arr_del(arr2, size2, n);
	if (n > size2)
		size2 = 0;
	else
		if (n > 0)
			size2 -= n;

	std::cout << "Итоговый массив:\n";
	print_arr(arr2, size2);


	delete[] arr2;



	return 0;
}


//Утечка памяти - явление, когда в связи с небрежным применнение указателей, в памяти остаются значения, не связанные с каким-либо указателями. 
// Данные значения "Блокируют" ячейки памяти и не дают другим программам с ними взайимодействовать.


//Области применения динамических массивов :
//1. Размер массива не известе на этапер кода
//2. Размер массива должен иметь возможность изменится.
//3. Реализация сложных структур данных.
