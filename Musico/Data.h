#ifndef DATA_H
#define DATA_H
#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Data{
	
	friend ostream &operator<<(ostream &, const Data &);

public:

	const Data &operator=(const Data &);
	bool operator== (const Data &) const;
	bool operator!= (const Data &data) const
	{
		return !(*this == data);
	}

    Data(int=1, int=1, int=1900);
	Data(const Data &);
    ~Data();

    void print() const;
	int checarDia(int) const;

private:
	    
    int dia;
    int mes;
    int ano;

};

#endif // DATA_H
