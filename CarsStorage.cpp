#include "CarsStorage.h"

vector<Car*>& CarsStorage::Instance()
{
    static vector<Car*> vector_cars;
    return vector_cars;
}
