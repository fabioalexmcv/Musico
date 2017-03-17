#pragma once
#include <string>
#include <ostream>
#include "Data.h"
using std::string;
using std::ostream;

class Pessoa{

	friend ostream &operator<< (ostream &, const Pessoa &); //Operador <<

public:

	Pessoa();									//Construtor default
	Pessoa(const Pessoa &);						//Construtor de cópia
	Pessoa(const string &nome, int idade);		//Construtor
	virtual ~Pessoa();							//Destrutor

	virtual void fazerBarulho() = 0;
	virtual void cantar() = 0;
	virtual void silenciar() = 0;

	const Pessoa &operator= (const Pessoa &);		//Operador =
	bool operator== (const Pessoa &) const;			//Operador ==
	bool operator!= (const Pessoa &pessoa) const	//Operador !=
	{
		return !(*this == pessoa);
	}
	
protected:

	string nome;
	int idade;
};

