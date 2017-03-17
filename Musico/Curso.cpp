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
	cout << "Estudar a li��o 1.\n"
		<< "| D� | R� | Mi | F� | Sol | L� | Si |...\n";

	cout << "Estudar a li��o 2.\n"
		 << "Antes de cantar deve-se fazer o aquecimento vocal, juntamente com exerc�cios de respira��o...\n";

	cout << "Estudar a li��o 3.\n"
		<< "Para se profissionalizar, voc� deve escolher o instrumento com o qual tem mais intimidade e treinar todos os dias...\n";
}

void Curso::formarMusico(){
	cout << "Parab�ns! Voc� completou o curso de " << nomeCurso << ", pegue o seu diploma na diretoria.\n";
}

void Curso::licoes(){
	vector <Curso*> licoes(3);

	Curso licao1 ("Musicaliza��o", 1, 01/01/12);
	Curso licao2 ("Vocaliza��o", 1, 01/01/13);
	Curso licao3 ("Profissionaliza��o", 3, 01/01/14);
}

ostream &operator << (ostream &output, const Curso &curso) {		//sobrecarga de operadores <<
	output << " | Data de inscri��o: " << curso.dataInscricao
		   << " | Nome do curso: " << curso.nomeCurso
		   << " | Duracao: " << curso.duracao;
	if (curso.duracao >= 2)
		cout << " anos.\n";
	else
		cout << " ano.\n";
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