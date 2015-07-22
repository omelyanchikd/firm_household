#pragma once

#include "household.h"
#include "generator.h"

#include <vector>
#include <map>

#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class household;


class firm
{
public:
	
	firm(void);

	void init(float _money, float _labor_productivity, float _salary_coefficient, float _salary_budget);

	void activate(string market_type);

	bool check(string market_type);
	float get_value(string market_type);

	void fire();
	void hire(household* worker);
	void quit(household* worker);

	void set_vacancies();

	float pricing();
	float get_tax(float tax);

	void produce();
	
	void sell(float quantity);

	void get_profits();

	void write_log();

	void learn();
	void learn(float pl, float pr);

	float get(string parameter);

	float get_salary();
	float get_needed_workers();
	float get_price();
	float get_storage();


private:

	float money;
	float salary;
	float price;
	float plan;
	
	float salary_budget;

	float labor_capacity;

	float labor_productivity;

	float elasticity;

	float production;
	float storage;

	float time;
	vector<float> history;

	float price_coefficient;

	float salary_coefficient;

	float plan_coefficient;

	vector<household*> workers;
	float sold;

	float prev_sold;
	float prev_plan;
	float prev_price;

	float sales;
	float profit;

	string parse(float a, float b);	
};

