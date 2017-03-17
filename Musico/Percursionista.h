#pragma once
#include "Musico.h"
class Percursionista : public Musico{

	friend ostream &operator<< (ostream &, const Percursionista &);		//Operador <<

public:

	Percursionista();
	Percursionista(const Percursionista &);
	Percursionista(const string &tipoInstrumento, int quantTambores, const string &ritmo, int quantRitmo, const Curso &cursoMusica);
	virtual ~Percursionista();

	void fazerMelodia() const;
	void informacoes() const;
	void batucar() const;
	void marcarCompasso() const;
	void addRitmo(const string &);

	const Percursionista &operator= (const Percursionista &);		//Operador =
	bool operator== (const Percursionista &) const;					//Operador ==
	bool operator!= (const Percursionista &perc) const				//Operador !=
	{
		return !(*this == perc);
	}

	static int numeroPerc;

private:

	string tipoInstrumento;
	int quantTambores;
	string ritmo;
	string *ritmoNome;
	int quantRitmo;
	static const int quantMaxPerc;
};

