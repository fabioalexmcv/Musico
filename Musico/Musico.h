#pragma once
#include "Pessoa.h"
#include "Curso.h"
#include <iostream>
using std::cout;
class Musico : public Pessoa{

	friend ostream &operator<< (ostream &, const Musico &); //Operador <<

public:

	Musico();
	Musico(const Musico &);
	Musico(const string &nomeArtistico, const string &instrumento);
	virtual ~Musico();

	void fazerBarulho();
	void cantar();
	void silenciar();

	virtual void fazerMelodia() = 0;
	void cantarAfinado();

	const Musico &operator= (const Musico &);		//Operador =
	bool operator== (const Musico &) const;			//Operador ==
	bool operator!= (const Musico &musico) const	//Operador !=
	{
		return !(*this == musico);
	}

private:

	string nomeArtistico;
	string instrumento;
	const Curso curso;

};

