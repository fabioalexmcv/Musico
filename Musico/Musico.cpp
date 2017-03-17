#include "Musico.h"

Musico::Musico()
: cursoMusica(){																//Construtor default
	this->nomeArtistico = "";
	this->instrumento = "";
}

Musico::Musico(const Musico &musico)
: cursoMusica(musico.cursoMusica){												//Construtor de c�pia
	this->nomeArtistico = musico.nomeArtistico;
	this->instrumento = musico.instrumento;
}

Musico::Musico(const string &nomeArtistico, const string &instrumento, const Curso &curso)	//Construtor
: cursoMusica(curso), Pessoa(nome, idade){
	this->nomeArtistico = nomeArtistico;
	this->instrumento = instrumento;
}

Musico::~Musico(){																//Destrutor
}


void Musico::fazerBarulho(){
	fazerMelodia();
}


void Musico::cantar(){
	cantarAfinado();
}


void Musico::silenciar(){
	cout << "	| -------------------------------------------" << '\n';
}

void Musico::cantarAfinado(){
	cout << "Cantar m�sica tema do filme 'Toy Store'..\n\n"

		<< "'Amigo estou aqui\n"
		<< "Amigo estou aqui\n"
		<< "Se a fase � ruim\n"
		<< "E s�o tantos problemas que n�o tem fim\n"
		<< "N�o se esque�a que ouviu de mim\n"
		<< "Amigo estou aqui\n"
		<< "Amigo estou aqui'" << '\n';
}

void Musico::fazerMelodia(){}

void Musico::informacoes() {
	cout << "Nome: " << nome << '\n'
		<< "Nome Arst�stico: " << nomeArtistico << '\n'
		<< "Idade: " << idade << " anos.\n"
		<< "Instrumento: " << instrumento << '\n';
}

ostream &operator << (ostream &output, const Musico &musico) {		//sobrecarga de operadores <<
	output << " | Nome: " << musico.nomeArtistico
		   << " | instrumento: " << musico.instrumento << '\n';
}

const Musico &Musico::operator = (const Musico &musico) {			//sobrecarga de operadores =
	this->nomeArtistico = musico.nomeArtistico;
	this->instrumento = musico.instrumento;

	return *this;
}

bool Musico::operator== (const Musico &musico) const {				//sobrecarga de operadores ==
	if (this->nomeArtistico == musico.nomeArtistico)
		return false;
	if (this->instrumento == musico.instrumento)
		return false;

	return true;
}