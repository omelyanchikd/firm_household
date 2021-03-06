#include "StdAfx.h"
#include "household.h"


household::household(void)
{
	money = 100;
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
	money += salary;
	if (employer != NULL)
		consumption_budget = 0.8 * salary;
	else
		consumption_budget = money > 0.001? 0.01 * money: 0;
	//consumption_budget = 20;//*/
	consumption = 0;
	consumption_capacity = 5;
}

void household::activate()
{
	if (employer != NULL)
		salary = employer->get_salary();
}


firm* household::find_work(map<firm*, float> probabilities)
{
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
	if (budget == 0)//(consumption == capacity || budget == 0)
	//if (consumption == need)
	//if (budget == 0)
		return NULL;
	firm* seller = get_random<firm*>(probabilities);
	float quantity = seller->get_storage();
	float price = seller->get_price();
/*	float need = capacity - consumption;
	if (need <= quantity && budget >= need * price)
	{
		money -= need* price;
		budget -= need * price;
		seller->sell(need);
		consumption += need - consumption;
	}
	else
		if (need > quantity && budget >= quantity * price)
		{
			money -= quantity * price;
			budget -= quantity * price;
			seller->sell(quantity);
			consumption += quantity;
		}
		else
		{
			money -= budget;
			consumption += budget/price;
			seller->sell(budget/price);
			budget = 0;
		}//*/
	if (budget >= quantity * price)
	{
		seller->sell(quantity);
		budget -= quantity * price;
		money -= quantity * price;
	}
	else
	{
		seller->sell(budget/price);
		money -= budget;
		budget = 0;
	}//*/
	return seller;
}

float household::get(string s)
{
	if (s == "money")
		return money;
}
