#include "Jogo.h"
#include <iostream>
#include <locale>
#include <conio.h>
using namespace std;
int main() {
	Jogo Exec;
	bool flag = false;
	while (!Exec.jogoAcabou(flag)) {
	      Exec.desenharTab();
	      while(!Exec.movimento(tolower(_getch())));
	      Exec.geraPos();
	}
	Exec.desenharTab();
	if (flag)
		cout << "Voce Ganhou! Parabens!" << std::endl;
	else 
		cout << "Fim de Jogo, Voce Perdeu" << endl;
	std::cin.get();
}
