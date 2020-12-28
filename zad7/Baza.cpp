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
  double prosjek;
  for (const auto& radnik : sviRadnici) {
    //jos malo pa sace 
  }
};