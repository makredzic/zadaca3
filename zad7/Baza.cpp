#include "Baza.hpp"
#include <algorithm>

std::istream& BazaRadnika::ucitaj(std::istream& nekiUlaz) {
  Radnik x{nekiUlaz};
  sviRadnici.push_back(x);
  return nekiUlaz;
};

bool BazaRadnika::izbrisi_radnika(const std::string &ime) {
  std::vector<Radnik>::iterator it = std::find(sviRadnici.begin(), sviRadnici.end(), ime);
  if (it != sviRadnici.end()) {
    sviRadnici.erase(it);
    return true;
  } else return false;
};

double BazaRadnika::prosjek_plata() {
  int plata = 0, i = 0;
  for (const auto& radnik : sviRadnici) {
    plata += radnik.getPlata(); 
    i++;
  }
  return plata/i;
};

double BazaRadnika::prosjek_godina() {
  int starost = 0, i = 0;
  for (const auto& radnik : sviRadnici) {
    starost += radnik.getStarost();
    i++;
  }
  return starost/i;
};

void BazaRadnika::ispis(std::ostream& izlaz) {
  for (const auto& radnik : sviRadnici) {
    izlaz << "Ime: " << radnik.getIme() << std::endl;
    izlaz << "Plata: " << radnik.getPlata() << std::endl;
    izlaz << "Godine: " << radnik.getStarost() << std::endl;
    izlaz << "- - - - - " << std::endl;
  }
};
