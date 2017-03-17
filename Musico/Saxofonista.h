#pragma once
#include "Musico.h"
class Saxofonista :	public Musico{

	friend ostream &operator<< (ostream &, const Saxofonista &);		//Operador <<


public:

	Saxofonista();
	Saxofonista(const Saxofonista &);
	Saxofonista(const string &tipoSax, const string &tamSax, const string &melodia, int quantMelodia, const Curso &cursoMusica);
	virtual ~Saxofonista();

	void fazerMelodia() const;
	void informacoes() const;
	void tocarSax() const;
	void soprarSuave() const;
	void addMelodia(const string &);

	const Saxofonista &operator= (const Saxofonista &);		//Operador =
	bool operator== (const Saxofonista &) const;			//Operador ==
	bool operator!= (const Saxofonista &sax) const			//Operador !=
	{
		return !(*this == sax);
	}

	static int numeroSax;

private:

	string tipoSax;
	string tamSax;
	string melodia;
	string *melodiaNome;
	int quantMelodia;
	static const int quantMaxSax;
};

