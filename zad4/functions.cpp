#include <iostream>
#include <string>
#include <list>
#include <limits>
#include <algorithm>

#include "functions.hpp"

void mainMenu() {
  std::cout << " --- Student Database --- \n";
 std::cout << "1. Dodaj Studenta\n2. Dodaj Predmet\n3. Promijeni podatak Studenta\n4. Ispisi sve studente\n5. Zatvori program\n";
};

void studentUnos(const std::list<Predmet> &sviPredmeti, std::list<Student> &sviStudenti) {

  std::string brIndex, ime, prezime, grad, predmet;
  int ocjena;

  std::cout << "\n --- Unosenje Studenta ---\nIspod unesite sljedece podatke\n";

//Unosenje indeksa
  std::cout << "Broj indeksa: ";
  std::cin >> brIndex;
 
  bool found = false;
  for (std::list<Student>::iterator it = sviStudenti.begin(); it != sviStudenti.end(); it++) {
    if (it->brojIndeksa == brIndex) found = true;
  }
  if (found) throw std::string{"Student sa tim brojem indeksa vec postoji."};

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  //std::cin >> ce uzeti prvu rijec, ukoliko korisnik unese vise rijei, prvu rijec uzima a ostale ostaju u bufferu i odmah se kupe za ime i ostale cin-ove ispod,
  //tako da u slucaju da neko unese vise od jedne rijeci (a zadatak trazi samo jednu rijec za indeks)
  //program NECE uzeti te rijeci za ime, prezime i ostalo
  //std::numeric_limits<std::streamsize>::max se koristi da cin.ignore izignorise sve rijeci, koliko god ih bilo ili do '\n' karaktera
  
  
  std::cout << "Ime: ";
  std::getline(std::cin, ime);

  std::cout << "Prezime: ";
  std::getline(std::cin, prezime);

  std::cout << "Grad: ";
  std::getline(std::cin, grad);
 
  std::cout << "Unos ocjena za studenta: " << brIndex << std::endl;
  
  //Ispod je loop koji ce unosit predmet i ocjenu za datog studenta onoliko koliko postoji predmeta u bazi
  int i = 0;
  std::vector<OcjenaIzPredmeta> sveOcjene;
  while(i < sviPredmeti.size()) {
    if(i != 0) std::cout <<"Unesite sljedecu ocjenu.\n"; //jedina svrha ove linije je da ispise ovo svaki put OSIM za prvu ocjenu, znaci ova linija je bukv beskorisna isto ko ovaj komentar sto sad citas
    std::cout << "Naziv predmeta: ";
    std::getline(std::cin, predmet);

  //Provjera postojanja predmeta
    std::list<Predmet>::const_iterator predmetIt;
    bool found = false;

    for (std::list<Predmet>::const_iterator it = sviPredmeti.cbegin(); it != sviPredmeti.end(); it++) {
      if(it->naziv == predmet) {
        predmetIt = it;
        found = true;
      }
    }
    if (!found) throw std::string{"Predmet ne postoji u bazi podataka."}; 


    bool loop;
    do {
      loop = false;
      std::cout << "Ocjena: ";
      std::cin >> ocjena;
      if (ocjena < 5 || ocjena > 10) {
        std::cout << "Ocjena moze biti samo broj izmedju 5-10.\n";
        loop = true;
      }
    } while (loop);


    sveOcjene.push_back(OcjenaIzPredmeta{ocjena, predmetIt});
    i++;
  }

  sviStudenti.push_back(Student{brIndex, ime, prezime, grad, sveOcjene}); 

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
  std::cout << "Ocjena uspjesno unesena.\n";
};

void studentUpdate() {
  std::cout << "\nNe radi trenutno.\n"; 
};

void ispisAll() {
  std::cout << "\nNe radi trenutno.\n"; 
};
