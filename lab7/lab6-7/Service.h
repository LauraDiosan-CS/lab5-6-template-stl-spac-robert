#pragma once
#include "Repo.h"
#include "Repo_file.h"

class Service {

private:

	Repo_file<Carte> repo;

public:
	Service() {

	}
	~Service() {

	}
	void insert_service(char*, char*,bool);
	int get_len();
	void update_carte(char*, char*, bool);
	int find_pozition_by_title(char*);
	void delete_book(char*);
	void load_from_file(const char*);
	std::deque<Carte> carte_imprumutata(char*,int &);
	std::deque<Carte> find_all_objects_by_author_array(char*);
	std::deque<Carte> get_all();
};