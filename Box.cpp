#include "Box.hpp"

Box::Box(std::string const &name) : Wrap(name, BOX_NAME) {
  _isOpen = false;
}

Box::~Box() {}

void Box::closeMe() {
  _isOpen = false;
}

bool Box::isOpen() const {
  return _isOpen;
}

bool Box::wrapMeThat(Object* o) {
  if (!isOpen())
    return false;
  return Wrap::wrapMeThat(o);
}
