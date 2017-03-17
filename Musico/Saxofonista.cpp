#include "Saxofonista.h"

int numeroSax = 0;
const int quantMaxSax = 4;

Saxofonista::Saxofonista(){
	this->tipoSax = "";
	this->tamSax = "";
	this->melodia = "";
	this->quantMelodia = 0;

	numeroSax++;
}

Saxofonista::Saxofonista(const Saxofonista &sax)
: Musico(static_cast< Musico >(sax)) {
	this->tipoSax = sax.tipoSax;
	this->tamSax = sax.tamSax;
	this->melodia = sax.melodia;
	this->quantMelodia = sax.quantMelodia;

	numeroSax++;
}

Saxofonista::Saxofonista(const string &tipoSax, const string &tamSax, const string &melodia, int quantMelodia, const Curso &cursoMusica)
: Musico(nomeArtistico, instrumento, cursoMusica) {
	this->tipoSax = tipoSax;
	this->tamSax = tamSax;
	this->melodia = melodia;
	this->quantMelodia = quantMelodia;

	numeroSax++;
}

Saxofonista::~Saxofonista(){
	delete [] melodiaNome;

	numeroSax--;
}

void Saxofonista::fazerMelodia() const{
	tocarSax();
}

void Saxofonista::informacoes() const {
	cout << "Tipo do saxofone: " << tipoSax << '\n'
		<< "Tamanho do saxofone: " << tamSax << '\n';
}

void Saxofonista::tocarSax() const {
	cout << "Música tema Os Simpsons..\n\n"

		<< "DO MI FA# LA SOL MI DO la\n"
		<< "fa# fa# fa# sol\n"
		<< "fa fa fa sol sib\n"
		<< "sol DO RE FA# FA DO si\n"
		<< "mi re# re# re# mi\n"
		<< "re# re# re# mi\n\n"

		<< "DO MI FA# LA SOL MI DO la\n"
		<< "fa# fa# fa# sol\n"
		<< "fa fa fa sol sib\n"
		<< "sol DO RE FA# FA DO si\n"
		<< "mi re# re# re# mi\n"
		<< "re# re# re# mi\n";
}

void Saxofonista::soprarSuave() const {
	cout << "Tocando a cifra soprando o sax suavemente..\n";
	tocarSax();
}

void Saxofonista::addMelodia(const string &melodia){
	string *aux = new string[quantMelodia];

	for (int i = 0; i < quantMelodia; i++)
		aux[i] = melodiaNome[i];

	delete[] melodiaNome;

	melodiaNome = new string[++quantMelodia];

	for (int i = 0; i < quantMelodia - 1; i++)
		melodiaNome[quantMelodia - 1] = melodia;

	delete[] aux;
}

ostream &operator << (ostream &output, const Saxofonista &sax) {		//sobrecarga de operadores <<
	output << static_cast< Musico > (sax)
		<< " | Tipo de saxofone: " << sax.tipoSax
		<< " | Tamanho do saxofone: " << sax.tamSax
		<< " | Melodia: " << sax.melodia
		<< " | Quantidade de melodias: " << sax.quantMelodia << '\n';
}

const Saxofonista &Saxofonista::operator = (const Saxofonista &sax) {			//sobrecarga de operadores =
	this->tipoSax = sax.tipoSax;
	this->tamSax = sax.tamSax;
	this->melodia = sax.melodia;
	this->quantMelodia = sax.quantMelodia;
	static_cast< Musico >(*this) = static_cast< Musico > (sax);

	return *this;
}

bool Saxofonista::operator== (const Saxofonista &sax) const {				//sobrecarga de operadores ==
	if (this->tipoSax == sax.tipoSax)
		return false;
	if (this->tamSax == sax.tamSax)
		return false;
	if (this->melodia == sax.melodia)
		return false;
	if (this->quantMelodia == sax.quantMelodia)
		return false;
	if (static_cast< Musico >(*this) != static_cast< Musico > (sax))
		return false;
	return true;
}