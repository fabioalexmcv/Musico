#pragma once
#include "Musico.h"
class Violinista : public Musico{

public:

	Violinista();
	Violinista(const Violinista &);
	Violinista(const string &tipoArco, const string &tamViolino);
	virtual ~Violinista();

	void fazerMelodia();
	void tocarViolino();
	void dedilhar();
	void addDedilhado();
	
private:

	string tipoArco;
	string tamViolino;

};

