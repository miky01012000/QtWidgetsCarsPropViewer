#pragma once

#include <iostream>

using namespace std;

typedef
enum class t_color   { white, red, orange, yellow, green, lightblue, blue, violet };

class Car
{
private:
	int		id;
	string	mark;
	string	model;
	int		year;
	t_color	color;
	double	price;
	string	RegNum;

public:
	Car() { id = 0; year = 1990; color = t_color::white; };
	~Car() {};

	int GetID();
	void SetID(int in_id);

	string GetMARK();
	void SetMARK(string in_mark);

	string GetMODEL();
	void SetMODEL(string in_model);

	int GetYEAR();
	void SetYEAR(int in_year);

	t_color GetCOLOR();
	void SetCOLOR(t_color in_color);

	double GetPRICE();
	void SetPRICE(double in_price);

	string GetREGNUM();
	void SetREGNUM(string in_regnum);
};

