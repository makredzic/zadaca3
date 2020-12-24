#include <iostream>
#include <string>
#include <list>
#include "functions.hpp"

void mainMenu() {
  std::cout << " --- Student Database --- \n";
 std::cout << "1. Dodaj Studenta\n2. Dodaj Predmet\n3. Promijeni podatak Studenta\n4. Ispisi sve studente\n5. Zatvori program\n";
};

void studentUnos() {

  std::cout << "\n --- Unosenje Studenta ---\n";
  std::cout << "Unesite broj indeksa studenta: ";
  
};

void predmetUnos(std::list<Predmet> &sviPredmeti) {

  std::string ime;
  std::cout << "\nUnesite naziv novog predmeta: ";
  std::cin.ignore(); //nisam siguran zasto se mora ovdje cin.ignore() staviti, ako se ne stavi program se ne zaustavi ovdje da uzme vrijednost za ime iz konzole, na stackoverflow-u sam nasao da se ovo stavi
  std::getline(std::cin, ime); //getline() se koristi jer obicni cin bi uzeo samo prvu rijec unesenu
  std::cout << std::endl;

  std::string odsjek;
  std::cout << "Unesite naziv odsjeka kojem taj predmet pripada: ";
  std::getline(std::cin, odsjek);
  std::cout << std::endl; 

  for (std::list<Predmet>::iterator it = sviPredmeti.begin(); it != sviPredmeti.end(); it++) {
    if ((it -> naziv) == ime) throw std::string{"\nError: Predmet vec postoji.\n"};
  }

  sviPredmeti.push_back(Predmet{ime, odsjek}); 
};

void studentUpdate() {
  std::cout << "\nNe radi trenutno.\n"; 
};

void ispisAll() {
  std::cout << "\nNe radi trenutno.\n"; 
};
