#ifndef WRAP_HPP
# define WRAP_HPP

#include <iostream>
#include "Object.hpp"

class Wrap : public Object {
protected:
  Object* _content;
  bool _isOpen;

public:
  Wrap(std::string const&, std::string const&);
  virtual ~Wrap();

  Object* getContent() const;
  virtual void isTaken();
  virtual void openMe();
  bool isOpen() const;
  virtual bool wrapMeThat(Object*);
  void setContent(Object* o);
};

#endif
