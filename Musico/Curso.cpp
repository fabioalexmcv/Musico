#include "Curso.h"

Curso::Curso()
: dataInscricao(){
	this->nomeCurso = "";
	this->duracao = 0;
}

Curso::Curso(const Curso &curso)
: dataInscricao(curso.dataInscricao){
	this->nomeCurso = curso.nomeCurso;
	this->duracao = curso.duracao;
}

Curso::Curso(const string &nomeCurso, int duracao, const Data &data)
: dataInscricao(data){
	this->nomeCurso = nomeCurso;
	if (duracao > 0)
		this->duracao = duracao;
	else
		this->duracao = 0;
}

Curso::~Curso(){
}

void Curso::ensinar(){
}


void Curso::formarMusico(){
}

ostream &operator << (ostream &output, const Curso &curso) {		//sobrecarga de operadores <<
	output << " | Data de inscrição: " << curso.dataInscricao
		   << " | Nome do curso: " << curso.nomeCurso
		   << " | Duracao: " << curso.duracao << " anos.\n";
}

const Curso &Curso::operator = (const Curso &curso) {				//sobrecarga de operadores =
	this->dataInscricao = curso.dataInscricao;
	this->nomeCurso = curso.nomeCurso;
	this->duracao = curso.duracao;

	return *this;
}

bool Curso::operator== (const Curso &curso) const {					//sobrecarga de operadores ==
	if (this->dataInscricao != curso.dataInscricao)
		return false;
	if (this->nomeCurso == curso.nomeCurso)
		return false;
	if (this->duracao == curso.duracao)
		return false;

	return true;
}