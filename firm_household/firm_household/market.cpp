#include "StdAfx.h"
#include "market.h"


market::market(void)
{
}


market::market(string market_type, vector<firm*> _sellers, vector<household*> _buyers)
{
	type = market_type;
	sellers = _sellers;
	buyers = _buyers;
	probabilities.clear();
}

void market::activate()
{
	probabilities.clear();
	for (int i = 0; i < sellers.size(); i++)
	{
		sellers[i]->activate(type);
		if (sellers[i]->check(type))
				probabilities[sellers[i]] = sellers[i]->get_value(type);
	}
	probabilities = allocate<firm*>(invert<firm*>(probabilities));
}

void market::match()
{
	for (int i = 0; i < buyers.size(); i++)
	{
		buyers[i]->decide();
		while (!empty())
		{
			firm *seller = buyers[i]->buy(probabilities);
			if (seller == NULL)
				break;
			update(seller);
		}		
	}
}

void market::update(firm *seller)
{
	if (!(seller->check(type)))
	{
		probabilities.erase(seller);
		probabilities = allocate<firm*>(probabilities);
	}
}


bool market::empty()
{
	return (probabilities.empty());
}

string market::get_type()
{
	return type;
}

