#pragma once
#include "Carte.h"
#include <deque>
#include <fstream>
#include <iostream>

template <typename T>
class Repo {

protected:
	std::deque <T> array;

public:

	Repo();
	~Repo();

	void insert(T);
	int get_len();
	/*void load_from_file(const char*);
	void save_to_file(const char*);*/
	void update_book_by_poz(int,T);
	void delete_book_by_poz(int);
	std::deque<T> get_all();
};

template <typename T>
Repo<T>::Repo() {


}

template <typename T>
Repo<T>::~Repo() {

}

template <typename T>
void Repo<T>::insert(T expence) {
	this->array.push_back(expence);
}

template <typename T>
int Repo<T>::get_len() {
	return this->array.size();
}

template <typename T>
std::deque<T> Repo<T>::get_all() {
	return this->array;
}

template <typename T>
void Repo<T>::update_book_by_poz(int poz,T carte) {

	this->array[poz] = carte;
}

template <typename T>
void Repo<T>::delete_book_by_poz(int poz) {
	
	if(poz>-1)
		this->array.erase(this->array.begin() + poz);
}

//template <typename T>
//void Repo<T>::load_from_file(const char* file_name) {
//
//	std::fstream file;
//	std::string file_titlu, file_autor;
//	char* titlu = new char[0], * autor = new char[0];
//	bool status;
//
//	file.open(file_name, std::ios::out | std::ios::in | std::ios::app);
//	if (file.is_open()) {
//		while (!file.eof()) {
//
//			file >> file_titlu >> file_autor >> status;
//
//			titlu = new char[file_titlu.size() + 1];
//			strcpy_s(titlu, 1 + file_titlu.size(), file_titlu.c_str());
//			autor = new char[file_autor.size() + 1];
//			strcpy_s(autor, 1 + file_autor.size(), file_autor.c_str());
//
//			Carte carte(titlu, autor, status);
//			this->array.push_back(carte);
//		}
//	}
//	else
//		std::cout << "Something is wrong! ";
//	file.close();
//}
//
//template <typename T>
//void Repo<T>::save_to_file(const char* file_name) {
//
//	std::fstream file;
//	file.open(file_name, std::ios::out | std::ios::in | std::ios::app);
//	if (file.is_open()) {
//		for (int i = 0; i<int(this->get_len()); i++) {
//
//			file << this->array[i];
//		}
//	}
//	file.close();
//}