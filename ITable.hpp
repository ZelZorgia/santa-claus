#ifndef ITABLE_HPP
# define ITABLE_HPP

# include "Object.hpp"

class ITable
{
public:
  virtual ~ITable() {}
  virtual Object *Take() = 0;
  virtual Object *Take(int i) = 0;
  virtual bool Put(Object *) = 0;
  virtual std::string* Look() const = 0;
};

#endif
