#pragma once
#include "Musico.h"
class Saxofonista :	public Musico{

	friend ostream &operator<< (ostream &, const Saxofonista &);		//Operador <<


public:

	Saxofonista();
	Saxofonista(const Saxofonista &);
	Saxofonista(const string &tipoSax, const string &tamSax, const string &melodia, int quantMelodia, const Curso &cursoMusica);
	virtual ~Saxofonista();

	void fazerMelodia();
	void informacoes();
	void tocarSax();
	void soprarSuave();
	void addMelodia(const string &);

	const Saxofonista &operator= (const Saxofonista &);		//Operador =
	bool operator== (const Saxofonista &) const;			//Operador ==
	bool operator!= (const Saxofonista &sax) const			//Operador !=
	{
		return !(*this == sax);
	}

protected:

	string tipoSax = "Tenor";
	string tamSax = "Grande";
	string melodia;
	string *melodiaNome;
	int quantMelodia;
};

