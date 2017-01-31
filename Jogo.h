#pragma once
#include "Tabuleiro.h"
class Jogo{
	private:
		Tabuleiro Tab[4][4];
		Tabuleiro Temp[4][4];
		int pontos;
		bool out;
		void unset();
		bool movVert(const int i,const int j, const int dir);
		bool movHori(const int i,const int j, const int dir);
		bool valMov(char dir, const int i, const int j);
	public:
		Jogo();
		void desenharTab();
		void geraPos();
		bool movimento(char dir);
		bool jogoAcabou(bool &flag);
};