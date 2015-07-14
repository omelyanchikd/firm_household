#include "StdAfx.h"
#include "household.h"


household::household(void)
{
	money = 1000;
	employed = false;
	employer = NULL;
	salary = 0;
}

household::household(float _money)
{
	money = _money;
	employed = false;
	employer = NULL;
	salary = 0;

}

void household::fire()
{
	employed = false;
	employer = NULL;
	salary = 0;
}

void household::decide()
{
/*	if (money > 0.6 * salary)
		consumption_budget = money - 0.8 * (money - 0.6 * salary);
	else
		consumption_budget = money;//*/
	consumption_budget = salary;
	//consumption_budget = 20;
	consumption = 0;
	consumption_capacity = 5;
}

firm* household::find_work(map<firm*, float> probabilities)
{
	if (employer != NULL)
		salary = employer->get_salary();
	firm* offer = get_random<firm*>(probabilities);
	if (offer->get_salary() > salary && offer->get_needed_workers() > 0)
	{
		if (employer != NULL)
		{
			employer->quit(this);
		}
		employer = offer;
		salary = offer->get_salary();
		offer->hire(this);
	}
	return employer;
}

firm* household::buy(map<firm*, float> probabilities)
{
	return buy(consumption_capacity, consumption, consumption_budget, probabilities);
}

firm* household::buy(float &capacity, float &consumption, float &budget, map<firm*, float> probabilities)
{
	if (consumption == capacity || budget == 0)
	//if (consumption == need)
	//if (budget == 0)
		return NULL;
	firm* seller = get_random<firm*>(probabilities);
	float quantity = seller->get_storage();
	float price = seller->get_price();
	float need = capacity - consumption;
	if (need <= quantity && budget >= need * price)
	{
		budget -= need * price;
		seller->sell(need);
		consumption += need - consumption;
	}
	else
		if (need > quantity && budget >= quantity * price)
		{
			budget -= quantity * price;
			seller->sell(quantity);
			consumption += quantity;
		}
		else
		{
			consumption += budget/price;
			seller->sell(budget/price);
			budget = 0;
		}
/*	if (budget >= quantity * price)
	{
		seller->sell(quantity);
		budget -= quantity * price;
	}
	else
	{
		seller->sell(budget/price);
		budget = 0;
	}//*/
	return seller;
}
