#include "Percursionista.h"

Percursionista::Percursionista(){
}


Percursionista::~Percursionista(){
}

ostream &operator << (ostream &output, const Violinista &violin) {		//sobrecarga de operadores <<
	output << static_cast< Musico > (violin)
		<< " | Tipo de arco: " << violin.tipoArco
		<< " | Tamanho do violino: " << violin.tamViolino
		<< " | Dedilhado usado: " << violin.dedilhado
		<< " | Quantidade de dedilhados: " << violin.quantDedilhado << '\n';
}

const Violinista &Violinista::operator = (const Violinista &violin) {			//sobrecarga de operadores =
	this->tipoArco = violin.tipoArco;
	this->tamViolino = violin.tamViolino;
	this->dedilhado = violin.dedilhado;
	this->quantDedilhado = violin.quantDedilhado;
	static_cast< Musico >(*this) = static_cast< Musico > (violin);

	return *this;
}

bool Violinista::operator== (const Violinista &violin) const {				//sobrecarga de operadores ==
	if (this->tipoArco == violin.tipoArco)
		return false;
	if (this->tamViolino == violin.tamViolino)
		return false;
	if (this->dedilhado == violin.dedilhado)
		return false;
	if (this->quantDedilhado == violin.quantDedilhado)
		return false;
	if (static_cast< Musico >(*this) != static_cast< Musico > (violin))
		return false;
	return true;
}