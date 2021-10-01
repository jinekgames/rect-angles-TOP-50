//////////////////////////////////////////////////////////////////////
//																	//
// FibRand.h														//
//																	//
// Генератора случайных чисел (вариант 10 (на числах Фибоначчи)		//
//																	//
//////////////////////////////////////////////////////////////////////


#pragma once

#include <list>
#include <vector>


class FibRand {

public:
	FibRand() noexcept;
	FibRand(int a, int b, int c, unsigned int k, unsigned int m) noexcept;
	~FibRand() noexcept = default;

public:
	int getValue();
	void seed(std::vector<int> startValues);
	void seed(std::list<int> startValues);
	void seed(int n, ...);

private:
	// коэффициенты
	int A = 1;
	int B = 2;
	int C = 3;
	unsigned int K = 5u;		// также определяет размер буфера (дб целочисленным)
	unsigned int M = 30u;
	// буфер с вычисленными ранее значениями
	std::list<int> buf;

};
