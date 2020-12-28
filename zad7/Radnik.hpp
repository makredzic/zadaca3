#pragma once
#include <iostream>
#include <string>

class Radnik {
//private: //private zakomentarisano jer ako nije specificirano, class po defaltu stavlja private dok struct po defaultu stavlja public
    std::string ime_;
    std::string prezime_;
    int starost_;
    int plata_;
  public:
    std::string getIme() const;
    int getStarost() const;
    int getPlata() const;
    void setPlata(const int&);
    Radnik();
    Radnik(const std::string&, const std::string&, const int&, const int&);
    Radnik(std::istream&);
};
