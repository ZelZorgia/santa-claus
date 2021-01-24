#ifndef TEDDY_HPP
# define TEDDY_HPP

# include <iostream>
# include "Toy.hpp"

class Teddy : public Toy {
public:
  Teddy(std::string const& name = TEDDY_NAME);
  ~Teddy();

  virtual void isTaken();
};

#endif
