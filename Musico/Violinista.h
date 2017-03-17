#pragma once
#include "Musico.h"
class Violinista : public Musico{

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
	
private:

	string tipoArco = "redondo";
	string tamViolino = "1/4";
	string dedilhado = "padrão";
	string *dedilhadoNome;
	int quantDedilhado;
};

