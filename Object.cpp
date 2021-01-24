#include "Object.hpp"

Object::Object(std::string const& name, std::string const& type) :
    _name(name),
    _type(type)
{
  _inUse = false;
}

Object::~Object() {}

std::string const & Object::getName() const
{
  return _name;
}

void Object::openMe() {
  std::cerr << "Function member in openMe does not exist" << std::endl;
}

void Object::closeMe() {
  std::cerr << "Function member in closeMe does not exist" << std::endl;
}

bool Object::isOpen() const {
  std::cerr << "Function member in isOpen does not exist" << std::endl;
  return false;
}

Object* Object::getContent() const {
  std::cerr << "Function member in getContent does not exist" << std::endl;
  return NULL;
}

void Object::setContent(Object*) {
  std::cerr << "Function member in getContent does not exist" << std::endl;
}

std::string const& Object::getType() const {
  return _type;
}

bool Object::wrapMeThat(Object * o) {
  std::cerr << "Function member in wrapMeThat does not exist" << std::endl;
  (void) o;
  return false;
}

# define STRBOOL(x) (x ? "\"1\"" : "\"0\"")
# define ATTRNAME() ("<name>" + getName() + "</name>")
# define ATTROPEN() ("<isOpen>" + STRBOOL(isOpen()) + "</isOpen>")
std::string Object::XML() const
{
  if (_type == PAPER_NAME)
    return std::string("<" + _type + ">" + (getContent() ? getContent()->XML() : "") + "</" + _type + ">");
  if (_type == BOX_NAME)
    return std::string("<" + _type + ">" + (getContent() ? getContent()->XML() : "") + "</" + _type + ">");
  return std::string("<" + _type + ">" + "</" + _type + ">");
}

std::ostream& operator<<(std::ostream &s, Object const &o)
{
  s << o.getName();
  return s;
}
