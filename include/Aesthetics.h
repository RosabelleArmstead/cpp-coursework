/* Aesthetics.h */
#ifndef AESTHETICS_H
#define AESTHETICS_H
#include <string>

/*
* Defines the properties of the Aesthetics class.
*/
class Aesthetics {
public: 
  Aesthetics(std::string colour, std::string earType, std::string height, std::string tailColour);
  std::string getColour();
  std::string getEarType();
  std::string getHeight();
  std::string getTailColour();
private:
  std::string colour;
  std::string earType;
  std::string height;
  std::string tailColour;
};

#endif /* AESTHETICS_H */