#pragma once
#include <iostream>
#include <ostream>

class Carte {

private:

	char* titlu;
	char* autor;
	bool status;

public:

	Carte();//constructor implicit
	Carte(char*, char*, bool);//constructor de initializare
	Carte(const Carte&);//constructor de copiere
	~Carte();//destructor

	//Getters

	char* get_titlu();
	char* get_autor();
	bool get_status();

	//Setters

	void set_titlu(char*);
	void set_autor(char*);
	void set_status(bool);

	//Overwrite operators '=' , "==" and "<<"

	Carte& operator =(const Carte&);
	bool operator==(const Carte&);
	friend std::ostream& operator << (std::ostream&, const Carte&);
};