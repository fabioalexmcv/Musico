#include "Pessoa.h"

Pessoa::Pessoa(){											//Construtor default
	this->nome = "";
	this->idade = 0;
}

Pessoa::Pessoa(const Pessoa &pessoa) {						//Construtor de cópia
	this->nome = pessoa.nome;
	this->idade = pessoa.idade;
}

Pessoa::Pessoa(const string &nome, int idade) {				//Construtor
	this->nome = nome;
	if (idade >= 0)
		this->idade = idade;
	else
		this->idade = 0;
}

Pessoa::~Pessoa(){											//Destrutor
}

ostream &operator << (ostream &output, const Pessoa &pessoa) {		//sobrecarga de operadores <<
	output << " | Nome " << pessoa.nome
			<< " | Idade: " << pessoa.idade << '\n';
}

const Pessoa &Pessoa::operator = (const Pessoa &pessoa) {			//sobrecarga de operadores =
	this->nome = pessoa.nome;
	this->idade = pessoa.idade;

	return *this;
}

bool Pessoa::operator== (const Pessoa &pessoa) const {				//sobrecarga de operadores ==
	if (this->nome == pessoa.nome)
		return false;
	if (this->idade == pessoa.idade)
		return false;

	return true;
}