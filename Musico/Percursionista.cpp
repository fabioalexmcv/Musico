#include "Percursionista.h"

int numeroPerc = 0;
const int quantMaxPerc = 2;

Percursionista::Percursionista(){
	this->tipoInstrumento = "";
	this->quantTambores = 0;
	this->ritmo = "";
	this->quantRitmo = 0;

	numeroPerc++;
}

Percursionista::Percursionista(const Percursionista &perc)
: Musico(static_cast< Musico >(perc)) {
	this->tipoInstrumento = perc.tipoInstrumento;
	this->quantTambores = perc.quantTambores;
	this->ritmo = perc.ritmo;
	this->quantRitmo = perc.quantRitmo;

	numeroPerc++;
}

Percursionista::Percursionista(const string &tipoInstrumento, int quantTambores, const string &ritmo, int quantRitmo, const Curso &cursoMusica)
: Musico(nomeArtistico, instrumento, cursoMusica) {
	this->tipoInstrumento = tipoInstrumento;
	this->quantTambores = quantTambores;
	this->ritmo = ritmo;
	if (quantRitmo >= 0)
		this->quantRitmo = quantRitmo;
	else
		this->quantRitmo = 0;

	numeroPerc++;
}

Percursionista::~Percursionista() {
	delete [] ritmoNome;

	numeroPerc--;
}

void Percursionista::fazerMelodia() const {
	batucar();
}

void Percursionista::informacoes() const {
	cout << "Tipo do instrumento: " << tipoInstrumento << '\n'
		<< "Quantidade de tambores: " << quantTambores << '\n';
}

void Percursionista::batucar() const {
	cout << "Introdução da música Faz chover - Fernandinho..\n\n"

		<< "   | ------------14x----------- |\n"
		<< "Ch | x-x-x-x-x-x-x-x-x-x-x-x-x- |\n"
		<< "Cx | --------o---------------o- |\n"
		<< "Su | -------------------------- |\n"
		<< "BB | o-----o-------o-o-----o--- |\n\n"

		<< "   |------------11x------------ |\n"
		<< "Ch | x-x-x-x-x-x-x-x-x-x-x-x-x- |\n"
		<< "Cx | --------o---------------o- |\n"
		<< "Su | -------------------------- |\n"
		<< "BB | o-----o-------o-o-----o--- |\n";
}

void Percursionista::marcarCompasso() const{
	cout << "Tocar apenas a marcação do tempo no chimbau.. tss! tss! tss! tss!\n";
}

void Percursionista::addRitmo(const string &ritmo){
	string *aux = new string[quantRitmo];

	for (int i = 0; i < quantRitmo; i++)
		aux[i] = ritmoNome[i];

	delete[] ritmoNome;

	ritmoNome = new string[++quantRitmo];

	for (int i = 0; i < quantRitmo - 1; i++)
		ritmoNome[quantRitmo - 1] = ritmo;

	delete[] aux;
}

ostream &operator << (ostream &output, const Percursionista &perc) {		//sobrecarga de operadores <<
	output << static_cast< Musico > (perc)
		<< " | Tipo de arco: " << perc.tipoInstrumento
		<< " | Tamanho do perco: " << perc.quantTambores
		<< " | ritmo usado: " << perc.ritmo
		<< " | Quantidade de ritmos: " << perc.quantRitmo << '\n';
}

const Percursionista &Percursionista::operator = (const Percursionista &perc) {			//sobrecarga de operadores =
	this->tipoInstrumento = perc.tipoInstrumento;
	this->quantTambores = perc.quantTambores;
	this->ritmo = perc.ritmo;
	this->quantRitmo = perc.quantRitmo;
	static_cast< Musico >(*this) = static_cast< Musico > (perc);

	return *this;
}

bool Percursionista::operator== (const Percursionista &perc) const {				//sobrecarga de operadores ==
	if (this->tipoInstrumento == perc.tipoInstrumento)
		return false;
	if (this->quantTambores == perc.quantTambores)
		return false;
	if (this->ritmo == perc.ritmo)
		return false;
	if (this->quantRitmo == perc.quantRitmo)
		return false;
	if (static_cast< Musico >(*this) != static_cast< Musico > (perc))
		return false;
	return true;
}