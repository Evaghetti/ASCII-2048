#pragma once
class Tabuleiro{
	public:
		Tabuleiro() : val(0), bloco(false) , comeu(false), passou(false){};
		bool bloco;
		bool comeu;
		bool passou;
		int val;
		Tabuleiro operator = (Tabuleiro temp);
		Tabuleiro operator = (int num);
		Tabuleiro operator *= (int num);
		bool operator == (Tabuleiro temp);
		bool operator == (int num);
};