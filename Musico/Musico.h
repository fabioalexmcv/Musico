#pragma once
#include "Pessoa.h"
#include "Curso.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;

class Musico : public Pessoa{

	friend ostream &operator<< (ostream &, const Musico &); //Operador <<

public:

	Musico();
	Musico(const Musico &);
	Musico(const string &nomeArtistico, const string &instrumento, const Curso &cursoMusica);
	virtual ~Musico();

	void fazerBarulho();
	void cantar();
	void silenciar();

	void cantarAfinado();
	virtual void fazerMelodia();
	virtual void informacoes();
	
	const Musico &operator= (const Musico &);		//Operador =
	bool operator== (const Musico &) const;			//Operador ==
	bool operator!= (const Musico &musico) const	//Operador !=
	{
		return !(*this == musico);
	}

protected:

	string nomeArtistico;
	string instrumento;
	const Curso cursoMusica;
};

