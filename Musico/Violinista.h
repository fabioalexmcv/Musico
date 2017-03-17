#pragma once
#include "Musico.h"
class Violinista : public Musico{

	friend ostream &operator<< (ostream &, const Violinista &);		//Operador <<

public:

	Violinista();
	Violinista(const Violinista &);
	Violinista(const string &tipoArco, const string &tamViolino, const string &dedilhado, int quatDedilhado , const Curso &cursoMusica);
	virtual ~Violinista();

	void fazerMelodia() const;
	void informacoes() const;
	void tocarViolino() const;
	void dedilhar() const;
	void addDedilhado(const string &);

	const Violinista &operator= (const Violinista &);		//Operador =
	bool operator== (const Violinista &) const;			//Operador ==
	bool operator!= (const Violinista &violin) const	//Operador !=
	{
		return !(*this == violin);
	}
	
private:

	string tipoArco = "Redondo";
	string tamViolino = "1/4";
	string dedilhado;
	string *dedilhadoNome;
	int quantDedilhado;
};

