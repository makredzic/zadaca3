#include "Radnik.hpp"
#include "Baza.hpp"
#include <iostream>

int main() {
  BazaRadnika b1;
  
  //Nema logike da ispisuje prosjecnu platu i godine
  //kad se program zatvori automatski cim uneses jednog radnika
  //kako bi se unijelo vise radnika, program se mora vrtit
  //odnosno vratit na ponovni unos novog radnika svaki put
  //tako da je kod koji je dat u ovom main.cpp samo ovako
  //'umotan' u while(true) koja ce prestat tek kad zatvoris program sa Ctrl + C
  
  while(true) {
    std::cout << "Unesite ime, prezime, starost i platu radnika: " << std::endl;
    //ovaj dio koda iznad ne dodje u ovom mainu vec sam ja dodao kako bih znao sta unosim za kojeg radnika
    
    b1.ucitaj(std::cin);
    
    if(b1.izbrisi_radnika("Alen")) {
      std::cout << "Alen izbrisan" << std::endl;
    } else {
      std::cout << "Brisanje nije moguce!" << std::endl;
    }

    std::cout << "U bazi su: " << std::endl;
    b1.ispis(std::cout);
    std::cout << "Prosjek plata je: " << b1.prosjek_plata() << std::endl;
    std::cout << "Prosjek godina je: " << b1.prosjek_godina() << std::endl;
  };

  return 0;
}
