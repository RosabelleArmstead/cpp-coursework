#include <string>
#pragma once

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
