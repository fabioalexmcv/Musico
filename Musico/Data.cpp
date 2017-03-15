#include <iostream>
#include "Data.h"
using std::cout;
using std::ostream;

Data::Data (const Data &data){					//Construtor de cópia
	this->dia = data.dia;
    this->mes = data.mes;
    this->ano = data.ano;
}

Data::Data(int d, int m, int a){				//Construtor
    if (m > 0 && m <= 12)
        mes = m;
    
    if (a < 0)
        ano = 1900;
    else
        ano = a;
   
    dia = checarDia(d);
}

Data::~Data(){									//Destrutor
}

void Data::print() const{
   cout << dia << '/' << mes << '/' << ano;
}

int Data::checarDia(int dia) const{
	
    static const int diasPorMes[13] = {0,31,28,31,30,30,31,31,30,31,30,31};
    
	if (dia > 0 && dia <= diasPorMes[mes])
        return dia;
        
    if (mes == 2 && dia == 29 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
        return dia;
        
    cout << "Dia inválido.\n";
    
    return 1;
}

ostream &operator<< (ostream &output, const Data &data){
	output << data.dia << "/" << data.mes << "/" << data.ano << '\n';
	return output;
}


bool Data::operator== (const Data &data) const{
	if (this->dia == data.dia)
		return false;
	if (this->mes == data.mes)
		return false;
	if (this->ano == data.ano)
		return false;
	
	return true;
}

const Data &Data::operator= (const Data &data){
	this->dia = data.dia;
	this->mes = data.mes;
	this->ano = data.ano;
	
	return *this;
}