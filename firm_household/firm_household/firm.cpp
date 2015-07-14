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
}

void firm::init(float _money, float _labor_productivity, float _salary_coefficient, float _salary_budget)
{
	sales = 0;
	sold = 0;
	storage = 0;
	price = 0;
	production = 0;
	workers.clear();
	time = 0;
	money = _money;
	elasticity = -1.5;
	labor_productivity = _labor_productivity;	
	salary_budget = _salary_budget;	
	plan = 10;
	salary_coefficient = _salary_coefficient;
}

void firm::activate(string market_type)
{
	if (market_type == "labor_market")
	{
		set_vacancies();
	}
	else
	{	
		produce();
		storage += production;
		price = pricing();
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
	labor_capacity = ceil(plan/labor_productivity);
	if (labor_capacity)
		salary = salary_budget/labor_capacity;
	else	
		salary = 0;
	if (salary <= 0.001)
	{
		labor_capacity = 0;
		salary = 0;
	}
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
	if (profit > 0)
		price_coefficient *= 1.1;
	else
		if (profit < 0)
			price_coefficient *= 0.9;
	price_coefficient = (price_coefficient < 1)? 1: price_coefficient;

	return (production > 0)? price_coefficient * salary/labor_productivity: price;
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

void firm::learn()
{	
	if (time)
	{		
		if (sold >= prev_sold && sold >= production && production >= 0.99 * plan)
			plan_coefficient = 1.1;
		else
			if (sold < prev_sold && sold < production)
				plan_coefficient = 0.9;	
			else
				plan_coefficient = 1;
		prev_plan = plan;//*/
		if (sold == prev_sold && sold == production && production < plan)
			plan = sold;
		else
			plan = plan_coefficient* plan;
		salary_budget = salary_coefficient * sales;
	}
	time++;
	money += profit;
	prev_sold = sold;
	sold = 0;
	sales = 0;


/*	if (plan - storage > 0)
	{
		plan -= storage;
	}
	else
	{
		plan = 0;
	}//*/
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