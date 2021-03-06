#include "StdAfx.h"
#include "world.h"


world::world(void)
{
	tax = 0.2;
	firms.clear();
	households.clear();
	for (int i = 0; i < 5; i++)
		firms.push_back(new firm());
	for (int i = 0; i < 100; i++)
		households.push_back(new household());
	labor_market = new labormarket(firms, households);
	good_market = new market("good_market", firms, households);
	ofstream fout;
	fout.open("taxes.txt", ios::out | ios::trunc);	
	fout.close();	
}

world::world(int number_firm, int number_household, float money_household)
{
	tax = 0.2;
	firms.clear();
	households.clear();
	for (int i = 0; i < number_firm; i++)
		firms.push_back(new firm());
	for (int i = 0; i < number_household; i++)
		households.push_back(new household(money_household));
	labor_market = new labormarket(firms, households);	
	good_market = new market("good_market", firms, households);
	ofstream fout;
	fout.open("taxes.txt", ios::out | ios::trunc);	
	fout.close();		
}

void world::init(float money, float labor_productivity, float salary_coefficient)
{
	for (int i = 0; i < firms.size(); i++)
	{
		firms[i]->init(money, labor_productivity, salary_coefficient, salary_coefficient * money);	
	}
	get_money();
}


void world::step()
{
	learn();
	get_money();
	labor_market->activate();
	labor_market->match();	
	good_market->activate();
	good_market->match();
	get_profits();
	write_log();
//	taxation();
}

void world::step(float pl, float pr)
{
	learn(pl, pr);
	labor_market->activate();
	labor_market->match();	
	good_market->activate();
	good_market->match();
	get_profits();
	write_log();
	get_money();
//	taxation();
}

void world::change_tax(float new_tax)
{
	tax = new_tax;
}

void world::taxation()
{
	total_taxes = 0;
	for (int i = 0; i < firms.size(); i++)
		total_taxes += firms[i]->get_tax(tax);
	ofstream fout;
	fout.open("taxes.txt", ios_base::app);
	fout<<total_taxes<<endl;
	fout.close();	
}

void world::get_profits()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->get_profits();
}

void world::get_money()
{
	money = 0;
	for (int i = 0; i < firms.size(); i++)
		money += firms[i]->get("money");
	for (int j = 0; j < households.size(); j++)
		money += households[j]->get("money");
}


void world::write_log()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->write_log();
}

void world::learn()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->learn();
}

void world::learn(float pl, float pr)
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->learn(pl, pr);
}

vector<firm*> world::get_firms()
{
	return firms;
}