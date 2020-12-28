#include "Radnik.hpp"

void Radnik::setPlata(const int& x) {
  plata_ = x;
};

Radnik::Radnik() {
  ime_ = "Anoniman";
  prezime_ = "Nepoznato";
  starost_ = 0;
  plata_ = 0;
};

Radnik::Radnik(const std::string& ime, const std::string& prezime, const int& starost, const int& plata) {
  ime_ = ime;
  prezime_ = prezime;
  starost_ = starost;
  plata_ = plata;
};

Radnik::Radnik(std::istream& ulaz) {
  ulaz >> ime_ >> prezime_ >> starost_ >> plata_;
};

std::string Radnik::getIme() {
  return ime_;
};

int Radnik::getStarost() {
  return starost_;
};

int Radnik::getPlata() {
  return plata_;
};
