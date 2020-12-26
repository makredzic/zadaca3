#pragma once
#include <iostream>
#include <list>
#include "structs.hpp"

void mainMenu();
void studentUnos(const std::list<Predmet> &, std::list<Student> &);
void predmetUnos(std::list<Predmet> &);
void studentUpdate();
void ispisAll(const std::list<Predmet> &, const std::list<Student> &);
