#pragma once
#include "Car.h"
#include <vector>

class CarsStorage
{
public:
	static vector<Car*>& Instance();
	CarsStorage() {};
};

