#pragma once
#include "Data.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;

class Curso{

	friend ostream &operator<< (ostream &, const Curso &); //Operador <<

public:

	Curso();
	Curso(const Curso &);
	Curso(const string &nomeCurso, int duracao, const Data &dataInscricao);
	virtual ~Curso();

	void ensinar();
	void formarMusico();
	void licoes();

	const Curso &operator= (const Curso &);			//Operador =
	bool operator== (const Curso &) const;			//Operador ==
	bool operator!= (const Curso &curso) const		//Operador !=
	{
		return !(*this == curso);
	}

private:

	string nomeCurso;
	int duracao;
	Data dataInscricao;
};

