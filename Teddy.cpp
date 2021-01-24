#include "Teddy.hpp"

Teddy::Teddy(std::string const& name) : Toy(name, TEDDY_NAME) {
}

Teddy::~Teddy() {

}

void Teddy::isTaken() {
  _inUse = true;
  std::cout << "gra hu" << std::endl;
}
