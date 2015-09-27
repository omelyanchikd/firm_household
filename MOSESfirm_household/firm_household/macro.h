#pragma once
class macro
{
public:

	float salary;
	float price;
	float sales;
	float profits;
	float sold;

	int workers;

	macro()
	{
		salary = 0; price = 0; sales = 0; profits = 0; sold = 0;
	}

	macro(float s, float p, float sold, float prof, float sl, int w)
	{
		salary = s; price = p; sales = sold; profits = prof; sold = sl; workers = w;
	}

	void targeting(macro *m, double r, double e)
	{
		salary = (r * salary + (1 - r) * m->salary)* (1 + e);
		price = (r * price + (1 - r) * m->price)* (1 + e);
		sales = (r * sales + (1 - r) * m->sales)* (1 + e);
		sold = (r * sold + (1 - r) * m->sold)* (1 + e);
		profits = (r * profits + (1 - r) * m->profits)* (1 + e);
	}
};

