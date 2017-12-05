#include <string>

class Aesthetics {
public: 
  Aesthetics{std::colour, std::earType, std::height, std::tailColour}
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
