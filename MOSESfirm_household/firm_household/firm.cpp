#include "StdAfx.h"
#include "firm.h"



firm::firm(void)
{
	ofstream fout;
	fout.open("log.csv", ios::out | ios::trunc);
	fout<<"pointer"<<", "<<"money"<<", "<<"price"<<", "<<"salary"<<", "<<"sales"<<", "<<"production"<<", "<<"storage"<<", "<<"workers"<<", "<<"labor_capacity"<<", "<<"plan"<<", "<<"profit"<<", "<<"time"<<endl; 
	fout.close();	
	sales = 0;
	sold = 0;
	storage = 0;
	price = 0;
	production = 0;
	workers.clear();
	time = 0;
	money = 10000;
	elasticity = -1.5;
	prev_sold = 0;
	plan_coefficient = 1;
	labor_productivity = 10;
	salary_budget = 50;
	plan = 50;
	price_coefficient = 1;
	prev_price = 0;
}

firm::firm(string t)
{
	sales = 0;
	sold = 0;
	storage = 0;
	salary = 0;
	price = 0;
	production = 0;
	workers.clear();
	time = 0;
	money = 0;
	profit = 0;
	type = t;

}

void firm::init(float _money, float _labor_productivity, float _salary_coefficient, float _salary_budget)
{
//	world = new macro;
	state = new macro;
	margin = 0.15;
	sales = 0;
	expected = 200;
	money = 100;
	salary = 10;
	labor_capacity = 20;
	sold = 0;
	storage = 0;
	price = 0;
	production = 0;
	workers.clear();
	time = 0;
	labor_productivity = _labor_productivity;	

}

void firm::activate(string market_type)
{
	if (market_type == "labor_market")
	{
		set_vacancies();
	}
	else
	{	
		if (type == "foreign")
		{
			storage = std::numeric_limits<float>::max();
		}
		else
		{
			produce();
			storage += production;
			price = pricing();
		}
	}
}

bool firm::check(string market_type)
{
	if (market_type != "labor_market")
		return (storage >= 0.001);
	return (labor_capacity - workers.size() > 0.001);
}

float firm::get_value(string market_type)
{
	if (market_type != "labor_market")
		return price;
	else
		return salary;
}

void firm::fire()
{
	while (workers.size() > labor_capacity && workers.size())
	{
		int index = rand()/RAND_MAX * (workers.size() - 1);
		workers[index]->fire();
		workers.erase(workers.begin() + index);
	}
}

void firm::hire(household* worker)
{
	workers.push_back(worker);	
}

void firm::quit(household* worker)
{
	int index = -1;
	for (int i = 0; i < workers.size(); i++)
	{
		if (workers[i] == worker)
		{
			index = i;
			break;
		}
	}
	if (index > -1)
		workers.erase(workers.begin() + index);
}

void firm::set_vacancies()
{
	if (labor_capacity < workers.size())
		fire();
}

void firm::sell(float quantity)
{
	storage -= quantity;
	sales += quantity * price;
	sold += quantity;	
}

void firm::produce()
{
	production = labor_productivity * workers.size();
}

float firm::pricing()
{
	return (storage > 0.001? expected/storage : price);
}

void firm::get_profits()
{
	profit = sales - workers.size() * salary;
}

float firm::get_tax(float tax)
{
	if (profit > 0)
	{
		sales -= tax * sales;
		return tax * sales;
	}
	return 0;
}

void firm::write_log()
{
	ofstream fout;
	fout.open("log.csv", ios_base::app);
	fout<<this<<", "<<money<<", "<<price<<", "<<salary<<", "<<sales<<", "<<production<<", "<<storage<<", "<<workers.size()<<", "<<labor_capacity<<", "<<plan<<", "<<profit<<", "<<time<<endl; 
	fout.close();
}

void firm::learn(float pl, float pr)
{
	plan = pl;
	price = pr;
	salary_budget = (sales > 0)? salary_coefficient * sales : salary_budget;
	time++;
	money += profit;
	sold = 0;
	sales = 0;

	if (plan - storage > 0)
	{
		plan -= storage;
	}
	else
	{
		plan = 0;
	}//*/
}

void firm::learn(macro *world)
{
	if (type == "foreign")
	{
		price = 5 * world->price;
		sold = 0;
		sales = 0;
	}
	else
	{
		money += profit;
	/*	if (profit/(price * sold) > margin) 
			salary *= 1.01;
		/*if (profit > 0)
			price *= 1.01;//*/
		margin = (0.6 * profit/(price * sold) + 0.4 * margin) * 1.01 >= 0? (0.6 * profit/(price * sold) + 0.4 * margin) * 1.01: 0.01;
		share = (0.6 * sold/world->sold + 0.4 * share);
		expected = world->sales * share; 
		plan = expected/price - storage;
		if (plan > 0)
		{
			if (plan <= labor_capacity * labor_productivity)
			{
				if (trial(expected, salary, labor_capacity) >= margin)
				{
					while (trial(expected, 1.01 * salary, labor_capacity) >= margin)
						salary *= 1.01;
				}
				else
				{
					while (labor_capacity - 1 >= 0 && plan <= (labor_capacity - 1) * labor_productivity)
					{
						labor_capacity--;
						if (trial(expected, salary, labor_capacity) >= margin)
							break;
					}
					while (trial(expected, 0.99 * salary, labor_capacity) < margin)
						salary *= 0.99;
				}
			}
			else
			{
				while (plan > (labor_capacity + 1)* labor_productivity)
				{
					labor_capacity++;
					if (trial(expected, 0.99* salary, labor_capacity) < margin)
						salary *= 0.99;
				}
			}
		}
		else
		{
			labor_capacity = 1;
		}
		/*
		if (trial(expected, salary, labor_capacity) > 2 * margin)
		{
			while (true)
			{
				if (trial(expected, salary, labor_capacity+1) <= 2* margin)
				{
					labor_capacity++;
					break;
				}
				else
					labor_capacity++;
			}
		}
		else
			if (trial(expected, salary, labor_capacity) < margin)
			{
				while (true)
				{
					if (trial(expected, salary, labor_capacity - 1) >= margin && labor_capacity - 1 > 0)
					{
						labor_capacity--;
						break;
					}
					else
						if (labor_capacity - 1 > 0)
							labor_capacity--;
						else
							break;
				}
			}
			else
			{
				while (true)
				{
					if (trial(expected, salary, labor_capacity+1) < 2 * margin &&trial(expected, salary, labor_capacity+1) >= margin)
						labor_capacity++;
					else
						break;
				}
			}//*/
	}
	time++;
	sold = 0;
	sales = 0;
}

double firm::trial(double expected, double wage, int capacity)
{
	return (1 - wage * capacity/expected);
}
string firm::parse(float a, float b)
{
	ostringstream buffer;
	buffer << a;
	buffer << " ";
	buffer << b;
	return buffer.str();
}

float firm::get(string parameter)
{
	if (parameter == "price")
		return price;
	if (parameter == "salary")
		return salary;
	if (parameter == "workers")
		return workers.size();
	if (parameter == "sales")
		return sales;
	if (parameter == "profit")
		return profit;
	if (parameter == "labor_capacity")
		return labor_capacity;
	if (parameter == "sold")
		return sold;
	if (parameter == "production")
		return production;
	if (parameter == "plan")
		return plan;
	if (parameter == "money")
		return money;
	if (parameter == "storage")
		return storage;
	if (parameter == "margin")
		return margin;
	if (parameter == "share")
		return share;
}

float firm::get_salary()
{
	return salary;
}

float firm::get_needed_workers()
{
	return (labor_capacity - workers.size());
}

float firm::get_price()
{
	return price;
}

float firm::get_storage()
{
	return storage;
}

void firm::set(string param, float value)
{
	if (param == "price")
		price = value;
	if (param == "share")
		share = value;
}