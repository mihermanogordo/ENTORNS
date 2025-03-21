
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Character.h"
#include <string>
using namespace std;
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "Boss.h"
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
void enunciado() {
	cout << "==========PELEA==========" << endl;
	cout << "" << endl;
	cout << "[==BUENO==] pasea tranquilamente por las colinas de Concha City y sale\n de la parada de bus un hombre con capa y botas..." << endl;
	cout << "" << endl;
	cout << "[==MALO==] con aspecto recio se saca un gorro de mago del bolsillo y le reta a una batalla a muerte...." << endl;
	cout << "" << endl;
	cout << "-------LA PELEA COMIENZA ---------" << endl;
	cout << "" << endl;
}
void enemyInitializations(int& psMalo, int& armaMalo) {// int& curacionMalo) {

	armaMalo = (rand() % 55) + 5;
	//curacionMalo = (rand() % 55) + 5;

	cout << "\nIntroduce los puntos de vida del [==MALO==]: ";
	cin >> psMalo;
	if (psMalo > 500) {
		armaMalo = (rand() % 105) + 95;
		//curacionMalo = (rand() % 95) + 45;
	}

}

void heroInitializations(int& psBueno, int& armaBueno) {
	armaBueno = (rand() % 55) + 5;
	cout << "\nIntroduce los puntos de vida del [==BUENO==]: ";
	cin >> psBueno;
	if (psBueno > 500) {
		armaBueno = (rand() % 105) + 65;

	}

}
void FinalBossInitializations(int& armaExtraReMalo) {
	cout << "\nIntroduce los puntos del super ataque extremo del [==REMALO==]: ";
	cin >> armaExtraReMalo;

}
int heroAttackEnemy(int& psMalo) {
	int armaBueno = (rand() % 55) + 5;
	psMalo -= armaBueno;
	psMalo = max(0, psMalo);

	cout << "" << endl;
	cout << "[==BUENO==] es mi turno!" << endl;
	cout << "" << endl;
	cout << "[==BUENO==] ha hecho: " << armaBueno << "  puntos de ataque inflingidos." << endl;
	cout << "" << endl;
	cout << "[==MALO==] ha recibido un ataque de " << armaBueno << " puntos de ataque inflingidos, sigue con un total de vida de : " << psMalo << " PSs." << endl;
	cout << "" << endl;

	//if (psMalo < 50) {
	//	psMalo += curacionMalo;
	//	psMalo = min(psMalo, 150);
	//	cout << "[==MALO==] se ha curado : " << curacionMalo << " de vida." << endl;
	//	cout << "[==MALO==] tiene de vida :" << psMalo << endl;
	//}
	return psMalo;
}

int enemyAttackHero(int& psBueno, int armaMalo) {
	int damageMalo = (rand() % armaMalo) + 5;
	psBueno -= damageMalo;
	psBueno = max(0, psBueno);

	cout << "[==MALO==] es mi turno!" << endl;
	cout << "" << endl;
	cout << "[==MALO==] ha hecho: " << damageMalo << " puntos de ataque inflingidos." << endl;
	cout << "" << endl;

	if (psBueno > 0) {
		cout << "[==BUENO==] ha recibido un ataque de " << damageMalo << " puntos de ataque inflingidos, tiene un total de vida de:  " << psBueno << " PSs (positivos)." << endl;
		cout << "" << endl;
	}
	return psBueno;
}
void heroeAttackFinalBoss(int& psBueno, int& psReMalo, int& armaExtraReMalo, int& armaBueno, int curacionBueno) {
	heroInitializations(psBueno, armaBueno);

	cout << "El [==BUENO==] ha derrribado al enemigo y se ha encontrado al gerente del enemigo..." << endl;
	do {

		psBueno -= 40;
		cout << "El [==REMAL0==] le ha asertado un ataque de 40 a la vida del [==BUENO==] le queda un total de vida de: " << psBueno << endl;
		cout << "" << endl;
		psReMalo -= armaBueno;
		if (psBueno > 0 || psReMalo > 0) {
			cout << "El [==BUENO==] le da un ataque de " << armaBueno << " puntos a la vida del [==REMALO==] le quedan: " << psReMalo << " de vida." << endl;
			psBueno -= armaExtraReMalo;
			cout << "El [==REMALO==] le ha asertado un ataque especial de " << armaExtraReMalo << " puntos a la vida del [==BUENO==], le quedan un total de: " << psBueno << " vida." << endl;
		}
		if (psBueno > 10) {
			curacionBueno += 10;
			psBueno = min(psBueno + 10, psBueno);
			cout << "La vida del [==BUENO==] se ha curado " << curacionBueno << " le queda un total de: " << psBueno << endl;
		}
	} while (psBueno > 0 && psReMalo > 0);


	if (psBueno <= 0 && psReMalo <= 0) {

		cout << "[==REMALO==] ha ganado exitosamente..." << endl;
		cout << "" << endl;
		cout << "[==BUENO==] ha perdido estrepitosamente... " << endl;
		cout << "" << endl;
		cout << "******************************El [==REMALO==] ha ganado*******************************" << endl;
	}
	else if (psBueno > 0) {
		cout << "[==BUENO==] ha ganado exitosamente.... " << endl;
		cout << "" << endl;
		cout << "[==REMALO==] ha perdido estrepitosamente..." << endl;
		cout << "" << endl;
		cout << "--------------------------------El [==BUENO==] ha ganado.-------------------------------" << endl;
	}
}

int main()
{

	PlaySound(TEXT("642214__n0iz__horror-scary-human-female-scream-short-01.wav"), NULL, SND_FILENAME | SND_SYNC);
	PlaySound(TEXT("663431__josefpres__8-bit-arpeggio-001-major-120-bpm-pulse1-020-g2.wav"), NULL, SND_FILENAME | SND_SYNC);
	PlaySound(TEXT("642214__n0iz__horror-scary-human-female-scream-short-01.wav"), NULL, SND_FILENAME | SND_SYNC);
	PlaySound(TEXT("663431__josefpres__8-bit-arpeggio-001-major-120-bpm-pulse1-020-g2.wav"), NULL, SND_FILENAME | SND_SYNC);

	srand(time(0));

	enunciado();

	int psBueno, psMalo, armaBueno, armaMalo, armaExtraReMalo;
	int psReMalo = 0;
	int  armaReMalo = 0;
	int curacionBueno = 0;

	heroInitializations(psBueno, armaBueno);
	Character heroe("[==BUENO==]", psBueno, armaBueno, 10);

	enemyInitializations(psMalo, armaMalo);
	Character enemy("[==MALO==]", psMalo, armaMalo, 0);

	FinalBossInitializations(armaExtraReMalo);
	Boss FinalEnemy("[==REMAL0==]", 120, 40, armaExtraReMalo);


	cout << heroe.getStatus() << endl;
	cout << enemy.getStatus() << endl;
	cout << FinalEnemy.getStatus() << endl;

	do {
		psMalo = heroAttackEnemy(psMalo);

		if (psMalo > 0) {

			psBueno = enemyAttackHero(psBueno, armaMalo);

		}


	} while (psBueno > 0 && psMalo > 0);

	/*do {
		heroe.attack(enemy);
		if (enemy.getHp() > 0) {
			enemy.attack(heroe);
	}
	} while (heroe.getHp() > 0 && enemy.getHp() > 0);*/

	cout << "" << endl;
	cout << "El [==BUENO==] ha ganado este pelea pero..." << endl;
	cout << "" << endl;

	if (psBueno > 0 && psMalo <= 0) {

		cout << "[==BUEN0==] ha ganado exitosamente.... " << endl;
		cout << "" << endl;
		cout << "[==MALO==] ha perdido estrepitosamente..." << endl;
		cout << "" << endl;
		cout << "--------------------------------El [==BUENO==] ha ganado.-------------------------------" << endl;
		heroeAttackFinalBoss(psBueno, psReMalo, armaExtraReMalo, armaBueno, curacionBueno);

	}
	else if (psBueno <= 0) {

		cout << "[==MALO==] ha ganado exitosamente.... " << endl;
		cout << "" << endl;
		cout << "[==BUEN0==]  ha perdido estrepitosamente..." << endl;
		cout << "" << endl;
		cout << "--------------------------------El [==MALO==] ha ganado.-------------------------------" << endl;
	}

	cout << "" << endl;
	cout << "Pelea se ha acabado." << endl;
	cout << "" << endl;


}

//ERRORES
//NO SE ACTUALIZA EL ATAQUE EXTRA DEL REMALO?
//PELEA MEDIAS ENTRE MALO Y BUENO 


