#include "Tabuleiro.h"
Tabuleiro Tabuleiro::operator = (int num) {
	this->val = num;
	this->bloco = bool(num);
	this->comeu = bool(num);
	return *this;
}
Tabuleiro Tabuleiro::operator = (Tabuleiro temp) {
	this->bloco = temp.bloco;
	this->val = temp.val;
	return *this;
}
Tabuleiro Tabuleiro::operator *= (int temp) {
	this->val *= 2;
	this->comeu = true;
	this->bloco = true;
	return *this;
}
bool Tabuleiro::operator == (Tabuleiro temp) {
	return this->val == temp.val;
}
bool Tabuleiro::operator == (int num) {
	return this->val == num;
}