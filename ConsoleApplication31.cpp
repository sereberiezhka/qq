#include <iostream>
#include <time.h>
using namespace std;

class Array {
private:
	int max, index;
	int* arr;
public:
	void add(int& a);
	void search(int& a);
	void replace(int& ind, int& val);
	void del(int& ind);
	void show();
	Array(int& i);
	Array();
	~Array();
};

Array::Array(int& i) {
	max = i - 1;
	index = 0;
	arr = new int[max];
	time_t t;
	srand((unsigned)time(&t));
	for (int j = 0; j <= max; j++) arr[j] = rand() % 100 + 1;
}

Array::Array() {
	max = 10;
	index = 0;
	arr = new int[max];
	time_t t;
	srand((unsigned)time(&t));
	for (int j = 0; j <= max; j++) arr[j] = rand() % 100 + 1;
}

Array::~Array() {

	delete[] arr;

	delete[] arr;
	delete[] & max;
	delete[] & index;
}

void Array::search(int& a) {
	int seek = a;
	int count = 0;
	for (int j = 0; j <= max; j++) {
		if (seek == arr[j]) {
			cout << endl << "Значение" << seek << " is at " << j;
			count++;
		}
	}
	if (count == 0)
		cout << endl << "В массиве нет этого элемента" << endl;
}

void Array::add(int& a) {
	arr[max + 1] = a;
	max++;
}

void Array::replace(int& ind, int& val) {
	if (ind <= max) {
		arr[ind] = val;
	}
}

void Array::del(int& ind) {
	if (ind <= max) {
		for (int i = 0; i < (max - ind); i++) {
			arr[ind + i] = arr[ind + i + 1];
		}
		arr[max] = 0;
		max--;
	}
}

void Array::show() {
	for (int i = 0; i <= max; i++) {
		cout << i << " - " << arr[i] << endl;
	}
}

int main() {
	int choice;
	int temp0;
	int temp2;

	setlocale(LC_ALL, "Russian");

	cout << "Введите размер массива: ";
	cin >> temp0;
	cout << "\n";

	Array test(temp0);

	cout << endl << "Массив создан" << endl;
	cout << endl << "Выбрать: \n";

	cout << "1. Добавить элемент" << endl;
	cout << "2. Поиск значения" << endl;
	cout << "3. Заменить элемент" << endl;
	cout << "4. Удалить элемент" << endl;
	cout << "5. Показать массив" << endl;
	cout << "0. Выйти \n" << endl;

	cin >> choice;
	cout << endl;
	while (choice != 0) {
		switch (choice)
		{
		case 1: cout << "Введите значение: ";
			cin >> temp0; test.add(temp0); temp0 = 0;
			cout << "\n"; cin >> choice;
			cout << "\n"; break;
		case 2: cout << "\nВведите значение: ";
			cin >> temp0; test.search(temp0); temp0 = 0;
			cout << "\n"; cin >> choice;
			cout << "\n"; break;
		case 3: cout << "\nВведите индекс: ";
			cin >> temp0;
			cout << "\nВведите значение: ";
			cin >> temp2; test.replace(temp0, temp2);
			temp0 = 0; temp2 = 0;
			cout << "\n"; cin >> choice; cout << "\n"; break;
		case 4: cout << "\nВведите индекс: ";
			cin >> temp0; test.del(temp0); temp0 = 0;
			cout << "\n"; cin >> choice; cout << "\n"; break;
		case 5: test.show();
			cout << "\n"; cin >> choice; cout << "\n"; break;
		default: cout << "Нажмите от 1 до 5\n ";
			cin >> choice; cout << "\n"; break;
		}
	}
	return 0;
}