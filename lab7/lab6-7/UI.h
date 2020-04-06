#pragma once
#include "Service.h"
#include <string>

class UI {

private:

	Service service;

	void add();
	void print();
	void update();
	bool title_exist(char*);
	bool status_exist(std::string);
	void delete_book_by_title();
	void carte_imprumutata();
public:

	void run();
};