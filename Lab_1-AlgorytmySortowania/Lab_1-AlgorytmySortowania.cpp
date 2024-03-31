/**
*Autor:		Jakub Brzozowski 235_IC A1 
*Data:						31.03.2024
**/
#include <iostream>
#include <String>
/// <summary>
/// Funkcja wypełniająca tablicę podanymi wartościami przez użytkownika
/// </summary>
/// <param name="table">Tablica do wypełnienia</param>
/// <param name="size">Rozmiar tablicy</param>
/// <returns>Wypełniona tablica</returns>
int* arrFiller(int table[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "Podaj " + std::to_string(i + 1) + " wartosc: ";
		std::cin >> table[i];
	}
	return table;
}
/// <summary>
/// Fynkcja generująca kopię oryginalnej tablicy
/// </summary>
/// <param name="arr">Tablica do skopiowania</param>
/// <param name="size">Rozmiar tablicy</param>
/// <returns>Nowa dynamiczna tablica</returns>
int* generateTempArr(int* arr,int size) {
	int* tempArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		tempArray[i] = *(arr + i);
	}
	return tempArray;
}
/// <summary>
/// Funkcja drukująca tablię
/// </summary>
/// <param name="arr">Tablica do wydrukowania</param>
/// <param name="size">Rozmiar tablicy</param>
void printArray(int arr[], int size) {

	std::cout << "\nTablica: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}
/// <summary>
/// Funkcja sortująca metądą bąbelkową
/// </summary>
/// <param name="arr">Tablica do posortowania</param>
/// <param name="size">Rozmiar tablicy</param>
void bubbleSort(int arr[], int size) {
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			std::cout << "\nCzy: arr["<<j<<"] = " << arr[j] << " > arr["<<j+1<<"] = "<< arr[j + 1] << "?";
			if (arr[j] > arr[j+1])
			{
				std::cout << " Tak ";
				std::cout << "Zamien "<<arr[j]<<" z " << arr[j + 1];
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				printArray(arr, size);
				std::cout << "\n";
			}
			else
			{
				std::cout << " Nie";
			}
		}
	}
	std::cout << "\nTablica posortowana: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;
}
/// <summary>
/// Funkcja sortująca metodą przez wybieranie
/// </summary>
/// <param name="arr">Tablica do posortowania</param>
/// <param name="size">Rozmiar tablicy</param>
void selectSort(int arr[], int size) 
{
	int minIndex;
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		minIndex = i;
		for (int j = i+1; j < size; j++)
		{
			std::cout << "\nCzy: arr[" << minIndex << "] = " << arr[minIndex] << " > arr[" << j << "] = " << arr[j] << "?";
			if (arr[minIndex] > arr[j]) 
			{
				std::cout << " Tak";
				minIndex = j;
				std::cout << "\nIndeks z minimalna wartascia "<< minIndex;
				std::cout << "\n";
			}
			else 
			{
				std::cout << " Nie";
			}
		}
		
		printArray(arr, size);
		std::cout << "<-Przed zmiana \n";
		
		std::cout << "Zamien " << arr[minIndex] << " z " << arr[i];
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;

		printArray(arr, size);
		std::cout << "<-Po zmianie \n";
	}

	std::cout << "\nTablica po: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;
}
/// <summary>
/// Funkcja sortująca metodą przez wstawianie
/// </summary>
/// <param name="arr">Tablica do posortowania</param>
/// <param name="size">Rozmiar tablicy</param>
void insertSort(int arr[], int size)
{
	int temp,j;
	for (int i = size - 2; i >= 0; i--)
	{
		
		temp = arr[i];
		j = i + 1;

		std::cout << "\nCzy " << j << " < " << size << " oraz " << temp << " > " << arr[j];
		if (((j < size) && (temp > arr[j])))
		{
			std::cout << " Tak";
			std::cout << "\nDopoki j = " << j << " < " << size << " oraz " << temp << " > " << arr[j];
			while (((j < size) && (temp > arr[j])))
			{
				std::cout << "\nPrzypisz arr["<<j<<"] = " << arr[j] << " do arr[" <<j-1<<"] = "<< arr[j-1];
				arr[j - 1] = arr[j];
				j++;
				std::cout << "\nj++ = "<<j;
			}
		}
		else {
			std::cout << " Nie";
		}
		
		arr[j - 1] = temp;
		printArray(arr, size);
		std::cout << "<-Po zmianie";
		std::cout << "\n";
	}

	std::cout << "\nTablica posortowana: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;
}
/// <summary>
/// Funkcja sortująca metodą przez scalanie
/// </summary>
/// <param name="arr">Tablica unikatowa</param>
/// <param name="tmpArr">Tablica pomocnicza</param>
/// <param name="start">Poczatek tablicy</param>
/// <param name="end">Koniec tablicy</param>
void mergeSort(int arr[], int tmpArr[], int start, int end)
{
	bool t = false;
	int mid = (start + end + 1) / 2;
	std::cout << "\nAktualna tablica: ";
	for (int i = 0; i <= end; i++)
	{
		std::cout << arr[i] << " ";
	}
	//*arr = arr[0];
	std::cout << "\nPoczatek: "<< start;
	std::cout << "\nSrodek: " << mid;
	std::cout << "\nKoniec: " << end;
	if (mid - start > 1) 
	{
		std::cout << "\nTablica wymaga podzielenia \n";
		mergeSort(arr, tmpArr, start, mid - 1);	
		t = true;
	}
	if (end - mid > 0) 
	{	
		mergeSort(arr, tmpArr, mid, end);
		t = true;
	}
	if (!t)
	{
		std::cout << "\nTablica NIE wymaga podzielenia \n";
		std::cout << "////////////////////////";
	}
	t = false;
	int i1 = start;
	int i2 = mid;
	std::cout << "\nPoczatek ->i1 " << i1;
	std::cout << "\nSrodek ->i2 " << i2;
	std::cout << "\nKoniec  " << end;

	for (int i = start; i <= end; i++) 
	{
		
		if (i1 == mid || ((i2 <= end) && (arr[i1] > arr[i2]))) 
		{
			
			std::cout << "\nCzy element arr[" << i << "] = " << arr[i] << " ma nastepce?"; 
			std::cout << " TAK";
			std::cout << "\nCzy Sa posortowane?";
			std::cout << " NIE";
			std::cout << "\ntmpArr[" << i << "] = arr[" << i2 << "] = "<<arr[i2];

			tmpArr[i] = arr[i2];
			i2++;

			std::cout << "\ntmpArr[" << i << "] = " << tmpArr[i];
			std::cout << "\ni2++ = " << i2;
			std::cout << "\n";
		}
		else 
		{
			std::cout << "\nCzy element arr[" << i1 << "] = " << arr[i1] << " ma nastepce?";
			std::cout << " TAK";

			std::cout << "\nCzy Sa posortowane?";
			std::cout << " TAK";
			std::cout << "\ntmpArr[" << i << "] = arr[" << i1 << "] = " << arr[i1];

			tmpArr[i] = arr[i1];
			i1++;

			std::cout << "\ntmpArr[" << i << "] = " << tmpArr[i];
			std::cout << "\ni1++ = "<<i1;
			std::cout << "\n";
		}
	}
	std::cout << "----------------------";
	for (int i = start; i <= end; i++) 
	{
		arr[i] = tmpArr[i];
	}
}

int main()
{
	int size;			//Rozmiar tablicy podany przez użytkownika
	int* arr;			//Wskaźnik alokujący dynamicznie tablice	
	int number;			//"Wartość" podana przez użytkownika		

	std::cout << "Podaj wielkosc tablicy: ";
	std::cin >> size;
	std::cout << "\n";

	arr = new int[size];
	arrFiller(arr,size);

	std::cout << "\n*****SORTOWANIE BAMBELKOWE*****";

	printArray(generateTempArr(arr,size), size);
	bubbleSort(generateTempArr(arr, size), size);
	
	std::cout << "\n*****SORTOWANIE PRZEZ SELEKCJE*****";
	printArray(generateTempArr(arr, size), size);
	selectSort(generateTempArr(arr, size), size);

	std::cout << "\n*****SORTOWANIE PRZEZ WSTAWIANIE*****";
	printArray(generateTempArr(arr, size), size);
	insertSort(generateTempArr(arr, size), size);

	std::cout << "\n*****SORTOWANIE PRZEZ SACLANIE*****";
	int* mArr = generateTempArr(arr, size);
	printArray(mArr, size);
	mergeSort(generateTempArr(arr, size),mArr,0,size-1); 
	std::cout << "\nTablica posortowana: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << mArr[i] << " ";
	}
}
