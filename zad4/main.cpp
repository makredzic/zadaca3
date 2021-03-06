#include <iostream>
#include <list>
#include <vector>
#include <limits>

#include "structs.hpp" 
#include "functions.hpp"

std::list<Predmet> sviPredmeti;
std::list<Student> sviStudenti;

int mainProgram() {

  mainMenu();
  unsigned short x = 100; //inicijaliziran sa 100 kako bih  na pocetku programa program ispisao "Izaberi opciju: "

  //Gets the valid number input
  do {
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ovo numeric_limits sve je neka genericka funkcija i kad je proslijedjena kao prvi argument u cin.ignore(), ignorisat ce sve charactere kojinisu valid
      std::cout << "\nInvalidan unos.";
    }
    std::cout<< "\nIzaberi jednu od opcija iznad(broj): ";
    std::cin >> x;
  } while(std::cin.fail() || (x != 1 && x != 2 && x != 3 && x !=4 && x != 5)); 

  if (x == 1) {
    try {
      studentUnos(sviPredmeti, sviStudenti);
    } catch (std::string e) {
      std::cout << e << std::endl;
    } catch (...) {
      std::cout << "NEPOZNAT ERROR!" << std::endl;
    }
  } else
    
  if (x == 2) {
    try {
      predmetUnos(sviPredmeti);
    } catch(std::string e) { 
      std::cout << e << std::endl;
    } catch(...) { //ovaj catch hvata sve druge errore koji eksplicitno  nisu uhvaceni catch-evima iznad
      std::cout << "NEPOZNAT ERROR!" << std::endl;
    }
  } else

  if (x == 3) {
    studentUpdate(); 
  } else
    
  if (x == 4) {
    ispisAll(sviPredmeti, sviStudenti);
  } else return 0;

  return 1;
};

int main() {

  int toLoop;
  do {
    toLoop = mainProgram();
  } while (toLoop);
  std::cout << "Shutting down.\n";
return 0;
}
