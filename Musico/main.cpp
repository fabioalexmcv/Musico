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
	
	Curso musica("Curso de violino", 5, (01, 01, 2012));
	Curso musica2("Curso de saxofone", 5, (01, 01, 2011));
	Curso musica3("Curso de percussão", 5, (01, 06, 2014));

    vector <Musico *> musicos(3);
	
	Violinista violin1("Redondo", "1/4", "Padrão", 1, musica);
    Saxofonista sax1("Tenor", "Grande", "The Simpsons", 2, musica2);
    Percursionista perc1("Acústico", 6, "merengue", 3, musica3);
	
	violin1.fazerMelodia;
	violin1.informacoes;
	
	sax1.fazerMelodia;
	sax1.soprarSuave;
	
	perc1.batucar;
	perc1.marcarCompasso;
	
	for (size_t i = 0; i < musicos.size(); i++){
		
		Percursionista *derivedPtr = dynamic_cast<Percursionista*> (musicos[i]);
        if (derivedPtr != 0){
			int quantTambores = derivedPtr->mostrarQuantTambor();
			cout << quantTambores << '\n';
			derivedPtr->addTambor(quantTambores + 1);
			cout << "Quantidade de tambores: " << derivedPtr->mostrarQuantTambor() << '\n';         
		} 
	}
	
	for (size_t j = 0; j < musicos.size(); j++){
		cout << "Deletando objetos... " << typeid(*musicos[j]).name() << '\n';
		delete musicos[j];
    }
	
 	return 0;
}
