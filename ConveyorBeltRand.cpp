#include <cstdlib>
#include "ConveyorBeltRand.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

ConveyorBeltRand::ConveyorBeltRand() : ConveyorBeltPePeNoel() {}

ConveyorBeltRand::~ConveyorBeltRand() {}

bool ConveyorBeltRand::IN() {
  if (_content) {
    std::cerr << ICB_ERR_NEMPTY << std::endl;
    return false;
  }
  if (random() % 2)
    _content = new Box;
  else
    _content = new GiftPaper;
  _name = _content->getName();
  return true;
}

void ConveyorBeltRand::Serialize()
{
  if (_content)
    std::cout << _content->XML();
}
