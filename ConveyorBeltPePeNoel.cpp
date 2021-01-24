#include <iostream>
#include "ConveyorBeltPePeNoel.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel() {
  _content = NULL;
  _name = "";
}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel() {
  delete _content;
}

Object *ConveyorBeltPePeNoel::Take() {
  if (!_content) {
    std::cerr << ICB_ERR_EMPTY << std::endl;
    return NULL;
  }
  _content->isTaken();
  Object *tmp = _content;
  _content = NULL;
  _name = "";
  return tmp;
}

bool ConveyorBeltPePeNoel::Put(Object *tmp) {
  if (_content) {
    std::cerr << ICB_ERR_NEMPTY << std::endl;
    return false;
  }
  _content = tmp;
  _name = tmp->getName();
  return true;
}

bool ConveyorBeltPePeNoel::IN() {
  static int i = 0;

  if (_content) {
    std::cerr << ICB_ERR_NEMPTY << std::endl;
    return false;
  }
  if (++i % 2)
    _content = new Box;
  else
    _content = new GiftPaper;
  _name = _content->getName();
  return true;
}

bool ConveyorBeltPePeNoel::OUT() {
  if (!_content) {
    std::cerr << ICB_ERR_EMPTY << std::endl;
    return false;
  }
  delete _content;
  _content = NULL;
  return true;
}

std::string const ConveyorBeltPePeNoel::Look() const {
  return _name;
}

IConveyorBelt *createConveyorBelt()
{
  return new ConveyorBeltPePeNoel;
}
