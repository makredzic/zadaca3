#pragma once
#include <iostream>
#include <vector>
#include "Radnik.hpp"

class BazaRadnika {
  std::vector<Radnik> sviRadnici; 
  public:
    std::istream& ucitaj(std::istream&);
    void ispis(const std::ostream&);
    bool izbrisi_radnika(const std::string&); 
    double prosjek_plata();
    double prosjek_godina();
};
