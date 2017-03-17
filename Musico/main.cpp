#include <stdio.h>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Pessoa.h"
#include "Musico.h"
#include "Data.h"
#include "Curso.h"
#include "Violinista.h"
#include "Saxofonista.h"
#include "Percursionista.h"
using std::cout;
using std::iostream;
using std::ostream;
using std::string;
using std::vector;


int main(int argc, char **argv){
	
    vector <Musico *> musicos(3);
	
	//musicos.push_back(new Violinista("Redondo", "1/4", "Padrão", 1, "Curso de violinho"));
	Violinista violin1("Redondo", "1/4", "Padrão", 1, "Curso de violinho");
    Saxofonista sax1("Tenor", "Grande", "The Simpsons", 2, "Curso de saxofone");
    Percursionista perc1("Acústico", 6, "merengue", 3, "Curso de bateria");
	
	violin1.fazerMelodia;
	violin1.informacoes;
	
	sax1.fazerMelodia;
	sax1.soprarSuave;
	
	perc1.batucar;
	perc1.marcarCompasso;
	
	for (size_t i = 0; i < musicos.size(); i++){
		
	/*	Moto *derivedPtr = dynamic_cast<Moto*> (musicos[i]);
        if (derivedPtr != 0){
			int rotacaoMotor = derivedPtr->mostrarRotacaoMotor();
			cout << rotacaoMotor << '\n';
			derivedPtr->aumentarGiro(10 * rotacaoMotor);
			cout << "Rotacao: " << derivedPtr->mostrarRotacaoMotor() << '\n';                     
		} 
	}*/
	
	for (size_t j = 0; j < musicos.size(); j++){
		cout << "Deletando objetos... " << typeid(*musicos[j]).name() << '\n';
		delete musicos[j];
    }
	
 	return 0;
}
