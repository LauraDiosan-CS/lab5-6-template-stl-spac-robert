#include "Service.h"
#include <cstring>

void Service::insert_service(char* name, char* date, bool price) {

	Carte shop(name, date, price);
	repo.insert(shop);

}

std::deque<Carte> Service::get_all() {

	return this->repo.get_all();
}

int Service::get_len() {

	return this->repo.get_len();
}

int Service::find_pozition_by_title(char* titlu) {

	for (int i = 0; i < this->get_len(); i++) {

		if (strcmp(this->get_all()[i].get_titlu(), titlu) == 0) {

			return i;
		}
	}
	return -1;
}

void Service::update_carte(char* titlu, char* autor, bool status) {

	Carte carte(titlu, autor, status);

	int i= this->find_pozition_by_title(titlu);
	this->repo.update_book_by_poz(i, carte);
}

void Service::delete_book(char* titlu) {

	int i = find_pozition_by_title(titlu);
	this->repo.delete_book_by_poz(i);
}

void Service::load_from_file(const char* file_name) {

	this->repo.load_from_file(file_name);
}

std::deque<Carte> Service::find_all_objects_by_author_array(char* titlu) {

	std::deque<Carte> array_by_title;
	std::deque<Carte> books = this->repo.get_all();
	for (int i = 0; i < this->repo.get_len(); i++) {

		if (strcmp(titlu, books[i].get_autor()) == 0) {
			array_by_title.push_back(books[i]);
		}
	}
	return array_by_title;
}

std::deque<Carte> Service::carte_imprumutata(char* titlu,int &contor) {

	int index = this->find_pozition_by_title(titlu);
	std::deque<Carte> array;
	if (index !=-1) {
		array = this->get_all();
		if (array[index].get_status() == 0) {

			array[index].set_status(1);
			contor = 1;
			return array;
			
		}
		else
		{
			
			if (find_all_objects_by_author_array(array[index].get_autor()).size()){

				contor = 0;
				return find_all_objects_by_author_array(array[index].get_autor());
			}
			else
				contor = 2;
		}
	}
	if (index == -1) {
		contor = 4;
		return array;
	}
}