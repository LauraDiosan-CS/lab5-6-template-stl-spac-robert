#pragma once
#include "Repo.h"
#include <fstream>
#include <string>
#include <deque>

template<typename T>

class Repo_file :public Repo<Carte> {


public:

	int find_pozition_by_title(char* titlu) {

		for (int i = 0; i < this->get_len(); i++) {

			if (strcmp(this->get_all()[i].get_titlu(), titlu) == 0) {

				return i;
			}
		}
		return -1;
	}

	void load_from_file(const char* file_name){

		std::fstream file;
		std::string file_titlu, file_autor;
		char* titlu = new char[0], * autor = new char[0];
		bool status;

		file.open(file_name, std::ios::out | std::ios::in | std::ios::app);
		if (file.is_open()) {
			while (!file.eof()) {

				file >> file_titlu >> file_autor >> status;

				titlu = new char[file_titlu.size() + 1];
				strcpy_s(titlu, 1 + file_titlu.size(), file_titlu.c_str());
				autor = new char[file_autor.size() + 1];
				strcpy_s(autor, 1 + file_autor.size(), file_autor.c_str());
				if (find_pozition_by_title(titlu) == -1) {

					Carte carte(titlu, autor, status);
					this->array.push_back(carte);
				}
			}
		}
		else
			std::cout << "Something is wrong! ";
		file.close();
	}
};