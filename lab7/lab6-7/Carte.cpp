#include "Carte.h"
#include <cstring>

Carte::Carte() {

	this->titlu = NULL;
	this->autor = NULL;
	this->status = false;
}

Carte::Carte(char* name, char* date, bool price) {

	this->titlu = new char[strlen(name) + 1];
	strcpy_s(this->titlu, 1 + strlen(name), name);
	this->autor = new char[strlen(date) + 1];
	strcpy_s(this->autor, 1 + strlen(date), date);
	this->status = price;
}

Carte::Carte(const Carte& expence) {

	this->titlu = new char[strlen(expence.titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(expence.titlu), expence.titlu);
	this->autor = new char[strlen(expence.autor) + 1];
	strcpy_s(this->autor, 1 + strlen(expence.autor), expence.autor);
	this->status = expence.status;
}

Carte::~Carte() {

	if (this->titlu) {

		free(this->titlu);
		this->titlu = NULL;
	}
	if (this->autor)
	{
		free(this->autor);
		this->autor = NULL;
	}
}

//Getters

char* Carte::get_titlu() {

	return this->titlu;
}

char* Carte::get_autor() {
	return this->autor;
}

bool Carte::get_status() {
	return this->status;
}

//Setters

void Carte::set_titlu(char* new_name) {

	if (this->titlu)
	{
		delete[] this->titlu;
		this->titlu = NULL;
	}
	this->titlu = new char[strlen(new_name) + 1];
	strcpy_s(this->titlu, 1 + strlen(new_name), new_name);
}

void Carte::set_autor(char* new_date) {
	if (this->autor)
	{
		delete[] this->autor;
		this->autor = NULL;
	}
	this->autor = new char[strlen(new_date) + 1];
	strcpy_s(this->autor, 1 + strlen(new_date), new_date);
}

void Carte::set_status(bool new_date) {

	this->status = new_date;
}

Carte& Carte:: operator =(const Carte& expence) {
	this->set_titlu(expence.titlu);
	this->set_autor(expence.autor);
	this->set_status(expence.status);
	return *this;
}

bool Carte:: operator==(const Carte& s) {
	return strcmp(this->titlu, s.titlu) == 0 and strcmp(this->autor, s.autor) == 0 and this->status == s.status;
}

std::ostream& operator <<(std::ostream& os, const Carte& expence) {
	os << "Titlu: " << expence.titlu << " Autor: " << expence.autor << " Status: " << expence.status << std::endl;
	return os;
}