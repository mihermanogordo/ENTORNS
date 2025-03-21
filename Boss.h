#pragma once
#include "Character.h"
class Boss :
	public Character
{
private:
	int spDamage;

public:
	Boss();
	Boss(string name, int hp, int damage, int spDamage);

	int getSpDamage();
	void setSpDamage(int SpDamage);
	string getStatus();
	void specialAttack(Character c);
};

