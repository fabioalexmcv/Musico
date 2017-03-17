#include "Violinista.h"

Violinista::Violinista(){
	this->tipoArco = "";
	this->tamViolino = "";
	this->dedilhado = "";
	this->quantDedilhado = 0;
}

Violinista::Violinista(const Violinista &violin)
: Musico(static_cast< Musico >(violin)) {
	this->tipoArco = violin.tipoArco;
	this->tamViolino = violin.tamViolino;
	this->dedilhado = violin.dedilhado;
	this->quantDedilhado = violin.quantDedilhado;
}

Violinista::Violinista(const string &tipoArco, const string &tamViolino, const string &dedilhado, int quatDedilhado, const Curso &cursoMusica)
: Musico(nomeArtistico, instrumento, cursoMusica){
	this->tipoArco = tipoArco;
	this->tamViolino = tamViolino;
	this->dedilhado = dedilhado;
	if (quantDedilhado >= 0)
		this->quantDedilhado = quantDedilhado;
	else
		this->quantDedilhado = 0;
}

Violinista::~Violinista(){
	delete [] dedilhadoNome;
}

void Violinista::fazerMelodia() const{
	tocarViolino();
}

void Violinista::informacoes() const{
	cout
		<< "Tipo do Arco: " << tipoArco << '\n'
		<< "Tamanho do violino: " << tamViolino << '\n'
		<< "Dedilhado usado: " << dedilhado << '\n';

}

void Violinista::tocarViolino() const{
	cout << "4/4 - 9� Sinfonia de Beethoven..\n\n"

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

void Violinista::dedilhar() const{
	cout << "Tocando a trablatura dedilhando, sem utilizar o arco.." << '\n';
	tocarViolino();
}


void Violinista::addDedilhado(const string &dedilhado){
	string *aux = new string[quantDedilhado];

	for (int i = 0; i < quantDedilhado; i++)
		aux[i] = dedilhadoNome[i];

	delete [] dedilhadoNome;

	dedilhadoNome = new string[++quantDedilhado];

	for (int i = 0; i < quantDedilhado - 1; i++)
		dedilhadoNome[quantDedilhado - 1] = dedilhado;

	delete [] aux;
}
