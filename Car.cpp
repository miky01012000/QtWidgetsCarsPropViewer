#include "Car.h"

int Car::GetID()
{
	return id;
}

void Car::SetID(int in_id)
{
	id = in_id;
}

string Car::GetMARK()
{
	return mark;
}

void Car::SetMARK(string in_mark)
{
	mark = in_mark;
}

string Car::GetMODEL()
{
	return model;
}

void Car::SetMODEL(string in_model)
{
	model = in_model;
}

int Car::GetYEAR()
{
	return year;
}

void Car::SetYEAR(int in_year)
{
	year = in_year;
}

t_color Car::GetCOLOR()
{
	return color;
}

void Car::SetCOLOR(t_color in_color)
{
	color = in_color;
}

double Car::GetPRICE()
{
	return price;
}

void Car::SetPRICE(double in_price)
{
	price = in_price;
}

string Car::GetREGNUM()
{
	return RegNum;
}

void Car::SetREGNUM(string in_regnum)
{
	RegNum = in_regnum;
}
