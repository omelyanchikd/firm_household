#pragma once

#include "firm.h"
#include "generator.h"

#include <vector>
#include <string>

using namespace std;

class firm;

class household
{
public:
	household(void);
	household(float _money);

	void fire();

	void decide();

	firm* find_work(map<firm*, float> probabilities);

	firm* buy(map<firm*, float> probabilities);
	firm* buy(float &capacity, float &consumption, float &budget, map<firm*, float> probabilities);


private:
	
	float money;

	firm *employer;
	float salary;

	bool employed;

	float consumption_budget;
	float consumption;
	float consumption_capacity;
};

