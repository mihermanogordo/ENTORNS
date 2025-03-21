#include "Character.h"
#include <iostream>
#include <string>
using namespace std;
Character::Character()
{
	name = "";//si pones esto te saldra por default en el constructor sin parantesis
	hp = 0;
	damage = (rand() % 55) + 5; //constructor sin parametros
	Curacion = (rand() % 55) + 5;
	//Curacion = (rand() % 100) + 5;
}

Character::Character(string name, int pHp, int damage, int Curacion)
{
	//constructor con parametros
	this->name = name; //para diferenciar el parametro con el atributo se pone la flecha.
	hp = pHp; //aqui no hay confusion entonces puedes ponerlo normal el this se usa cuando el nombre del atri no se diferencia del param
	this->damage = damage;
	this->Curacion = Curacion;
}
string Character::getName()
{
	return name;
}

void Character::setName(string Name)
{
	this->name = Name;
}

int Character::getHp()
{
	return hp;
}

void Character::setHp(int Hp)
{
	this->hp = hp; //lo que le llega del parametro se lo pasa al atributo
}

void Character::setDamage(int damage)
{
	this->damage = damage;

}
int Character::getDamage()
{
	return damage;
}
void Character::setCuracion(int curacion) {
	this->Curacion = curacion;
}
int Character::getCuracion() {
	return Curacion;
}
string Character::getStatus()
{
	return string("\nName: " + name + "\nHP: " + to_string(hp) + "\ndamage: " + to_string(damage) + "\nhealing: " + to_string(Curacion));
	//el to_string es una libreria que pasa hp a string para concatenarlo sin que se queje
}

void Character::attack(Character c)
{
	//el character que le llega llama al metido sethp que le reste el damage a su vida
	c.setHp(c.getHp() - damage);
	int characterHP = c.getHp() - damage; //el personaje te pasa la vida y te la guardas en el gethp que le resta el da o
	//la vida que le queda se le asignas en el set y le pasas la vida nueva
	c.setHp(characterHP);

}
