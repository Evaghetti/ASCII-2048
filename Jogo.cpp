#include "Jogo.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
void Jogo::unset() {
	out = false;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			Tab[i][j].comeu = false;
			Tab[i][j].passou = false;
		}
	}
}
Jogo::Jogo() : pontos(0), out(false) {
	for (int i = 0; i < 2; i++)
		geraPos();
}
void Jogo::desenharTab() {
	system("cls");
	std::cout << "Pontuacao: " << pontos << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "+----+----+----+----+" << std::endl << "|";
		for (int j = 0; j < 4; j++) {
			if (!Tab[i][j].bloco)
				std::cout << std::setw(4) << ' ';
			else
				std::cout << std::setw(4) << Tab[i][j].val;
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "+----+----+----+----+" << std::endl << std::endl;
}
void Jogo::geraPos() {
	srand(time(NULL));
	int ich, jch, ch;
	auto sai = true;
	do {
		ich = rand() % 4;
		jch = rand() % 4;
		ch = rand() % 100;
		Tab[ich][jch].passou = true;
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if (Tab[i][j].passou == false)
					sai = false;
			}
		}
	} while (Tab[ich][jch].bloco && !sai);
	if (!Tab[ich][jch].bloco) {
		if (ch < 90)
			Tab[ich][jch] = 2;
		else
			Tab[ich][jch] = 4;
	}
}
bool Jogo::movVert(const int i, const int j, const int dir) {
	if (!Tab[i + dir][j].bloco) {
		Tab[i + dir][j] = Tab[i][j];
		Tab[i][j] = 0;
		return false;
	}
	else if (!Tab[i + dir][j].comeu && !Tab[i][j].comeu) {
		Tab[i + dir][j] *= 2;
		Tab[i][j] = 0;
		pontos += Tab[i + dir][j].val;
		return true;
	}
}
bool Jogo::movHori(const int i, const int j, const int dir) {
	if (!Tab[i][j + dir].bloco) {
		Tab[i][j + dir] = Tab[i][j];
		Tab[i][j] = 0;
		return false;
	}
	else if (!Tab[i][j + dir].comeu && !Tab[i][j].comeu) {
		Tab[i][j + dir] *= 2;
		Tab[i][j] = 0;
		pontos += Tab[i][j + dir].val;
		return true;
	}
}
bool Jogo::movimento(char dir) {
	unset();
	switch (dir) {
	case 'w':
		for (int i = 1; i<4; i++) {
			for (int j = 0; j<4; j++) {
				int posi = i, posj = j;
				while (valMov(dir, posi, posj) && posi>0) {
					out = true;
					if (movVert(posi, posj, -1))
						break;
					posi--;
				}
			}
		}
		return out;
		break;
	case 's':
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j<4; j++) {
				int posi = i, posj = j;
				while (valMov(dir, posi, posj) && posi<3) {
					out = true;
					if (movVert(posi, posj, 1))
						break;
					posi++;
				}
			}
		}
		return out;
		break;
	case 'a':
		for (int i = 0; i<4; i++) {
			for (int j = 1; j<4; j++) {
				int posi = i, posj = j;
				while (valMov(dir, posi, posj) && posj>0) {
					out = true;
					if (movHori(posi, posj, -1))
						break;
					posj--;
				}
			}
		}
		return out;
		break;
	case 'd':
		for (int i = 0; i<4; i++) {
			for (int j = 2; j >= 0; j--) {
				int posi = i, posj = j;
				while (valMov(dir, posi, posj) && posj<3) {
					out = true;
					if (movHori(posi, posj, 1))
						break;
					posj++;
				}
			}
		}
		return out;
		break;
	default:
		return false;
	}
}
bool Jogo::valMov(char dir, const int i, const int j) {
	if (Tab[i][j].val != 0) {
		switch (dir) {
		case 'w':
			if (Tab[i - 1][j].bloco == false) { return true; }
			else if (Tab[i][j].val == Tab[i - 1][j].val) { return true; }
			else return false;
			break;
		case 's':
			if (Tab[i + 1][j].bloco == false) { return true; }
			else if (Tab[i][j].val == Tab[i + 1][j].val) { return true; }
			else return false;
			break;
		case 'd':
			if (Tab[i][j + 1].bloco == false) { return true; }
			else if (Tab[i][j].val == Tab[i][j + 1].val) { return true; }
			else return false;
			break;
		case 'a':
			if (Tab[i][j - 1].bloco == false) { return true; }
			else if (Tab[i][j].val == Tab[i][j - 1].val) { return true; }
			else return false;
			break;
		default:
			return false;
		}
	}
	return false;
}
bool Jogo::jogoAcabou(bool &flag) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (Tab[i + 1][j] == 2048 && i<3) { flag = true; return true; }
			if (Tab[i - 1][j] == 2048 && i>0) { flag = true; return true; }
			if (Tab[i][j + 1] == 2048 && j<3) { flag = true; return true; }
			if (Tab[i][j - 1] == 2048 && j>0) { flag = true; return true; }
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (Tab[i][j] == 0) { return false; }
			if (Tab[i][j] == Tab[i + 1][j] && i<3) { return false; }
			if (Tab[i][j] == Tab[i - 1][j] && i>0) { return false; }
			if (Tab[i][j] == Tab[i][j + 1] && j<3) { return false; }
			if (Tab[i][j] == Tab[i][j - 1] && j>0) { return false; }
		}
	}
	return true;
}
