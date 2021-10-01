//////////////////////////////////////////////////////////////////////
//																	//
// main.cpp															//
//																	//
// Генерация 50 случайных прямоугольников и сортировка по			//
// отношению их площади к периметру									//
//																	//
//////////////////////////////////////////////////////////////////////



#include "Rand num module/FibRand.h"
#include <windows.h>
#include <vector>
#include <iostream>
#include "conio.h"


using namespace std;



// количество прямоугольников
#define RECT_COUNT 50
// нижняя гарница значений стороны a прямоугольника
#define RECT_A_LOW 0
// верхняя гарница значений стороны a прямоугольника
#define RECT_A_UP 100
// нижняя гарница значений стороны b прямоугольника
#define RECT_B_LOW 0
// верхняя гарница значений стороны b прямоугольника
#define RECT_B_UP 100


// структура прямоугольника и его характеристики
struct RECTplus {
	RECT rect;
	double charect;
};



int main() {

	// инициализация генератора случайных чисел
	FibRand RandGen(10, 2, 5, 5u, RECT_B_UP + RECT_A_UP);
	srand(GetTickCount64());
	RandGen.seed(5, rand(), rand(), rand(), rand(), rand());

	// массив с прямоугольниками и их характеристикой
	vector<RECTplus> rectVec;


	cout << "Generation start\n";
	UINT starttime = GetTickCount64();

	// генерация 50 случайных прямоугольников и заполнение массива
	for (auto i = 0u; i < RECT_COUNT; i++) {

		LONG a = RandGen.getValue() % (RECT_A_UP - RECT_A_LOW) + RECT_A_LOW;
		LONG b = RandGen.getValue() % (RECT_A_UP - a) + a;
		LONG c = RandGen.getValue() % (RECT_B_UP - RECT_B_LOW) + RECT_B_LOW;
		LONG d = RandGen.getValue() % (RECT_B_UP - c) + c;

		rectVec.push_back({
			{ c, b, d, a },
			((DOUBLE(b) - a) * (d - c)) / (b - a + d - c)
		});

	}

	cout << "Generation Done (" << (GetTickCount64() - starttime) << " ms)\n";


	cout << "Sort start\n";
	starttime = GetTickCount64();

	// конец массива
	auto vec_end = rectVec.end();

	// сортировка по отношению (по убыванию)
	for (auto i = rectVec.begin(); i < vec_end; i++) {
		for (auto k = i; k < vec_end; k++)

			if (i->charect < k->charect) {
				auto tmp = *i;
				*i = *k;
				*k = tmp;
			}

	}

	cout << "Sort Done (" << (GetTickCount64() - starttime) << " ms)\n";


	cout << "\n\
Sorted rectangles\n\
a\tb\tcharectiristic\n";
	
	// вывод результата
	for (auto el : rectVec) {
		cout << el.rect.top - el.rect.bottom << '\t' << el.rect.right - el.rect.left << '\t' << fixed << el.charect << endl;
	}




	cout << "\n\npress any button to exit...";
	_getch();

	return 0;

}
