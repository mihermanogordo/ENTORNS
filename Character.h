#pragma once
#include <iostream>
using namespace std;

class Character
{
	//ATRIBUTOS
private:
	string name;
	int hp;
	int damage;
	int Curacion;

	//PROTOTIPOS
public:
	//CONSTRUCTORES && BUILDERS
	Character();
	Character(string name,int hp, int damage, int curacion);//esto es del malo porque se cura
	//Character(string name, int hp, int damage);esto bueno porque no se cura random
	//Character(string name, int damage, int curacion);
	//Character(string name, int damage);


	//GETTERSETTER

	string getName();
	void setName(string Name);

	int getHp();
	void setHp(int Hp);

	int getDamage();
	void setDamage(int damage);

	int getCuracion();
	void setCuracion(int Curacion);


	//SIMILAR TOSTRING
	string getStatus();

	//METODOS PROPIOS
	void attack(Character c);

	
};



