#include "Boss.h"
#include <string>
Boss::Boss():Character()
{
	this->spDamage = 0;		
}

Boss::Boss(string name, int hp, int damage, int spDamage):Character(name,hp,damage,0)
{
	this->spDamage = spDamage;
}

int Boss::getSpDamage()
{
	return 0;
}

void Boss::setSpDamage(int SpDamage)
{
}

string Boss::getStatus()
{
	return string("\nName: " + getName() + "\nHP: " + to_string(getHp()) + "\nDamage: " + to_string(getDamage()) + "\nSuperDamageAttack: " + to_string(spDamage));

}

void Boss::specialAttack(Character c)
{
	
		c.setHp(c.getHp() - spDamage);

		int characterHP = c.getHp() - spDamage;
		c.setHp(characterHP);


	
}

