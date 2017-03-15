#include "Violinista.h"

Violinista::Violinista(){
	this->tipoArco = "";
	this->tamViolino = "";
}

Violinista::Violinista(const Violinista &violin){
	this->tipoArco = violin.tipoArco;
	this->tamViolino = violin.tamViolino;
}

Violinista::Violinista(const string &tipoArco, const string &tamViolino){
	this->tipoArco = tipoArco;
	this->tamViolino = tamViolino;
}


Violinista::~Violinista(){
}

void Violinista::fazerMelodia() {
	tocarViolino();
}

void Violinista::tocarViolino(){
	cout << "4/4 - 9ª Sinfonia de Beethoven..\n\n"

		<< "			 C          G       C        G					 \n"
		<< "	E | -0-0-1-3-3-1-0-----------0-0-------------------------\n"
		<< "	B | ---------------3--1-1-3------3-3---------------------\n\n"

		<< "			 C          G        C       G					 \n"
		<< "	E | -0-0-1-3-3-1-0------------0--------------------------\n"
		<< "	B | ----------------3--1-1-3------3--1-1-----------------\n\n"

		<< "			G                    C							 \n"
		<< "	E | -----0------0--1--0-------0-1-0----------------------\n"
		<< "	B | -3-3---1--3---------1--3--------3--1--3--------------\n"
		<< "	G | ----------------------------------------0------------" << '\n';
}

void Violinista::dedilhar(){
	cout << "Tocando a trablatura dedilhando, sem utilizar o arco.." << '\n';
	tocarViolino();
}


void Violinista::addDedilhado(){

}
