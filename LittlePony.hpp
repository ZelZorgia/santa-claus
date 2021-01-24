#ifndef LITTLEPONY_HPP
# define LITTLEPONY_HPP

# include <iostream>
# include "Object.hpp"
# include "Toy.hpp"

class LittlePony : public Toy {
public:
  LittlePony(std::string const& name = PONY_NAME);
  ~LittlePony();

  virtual void isTaken();
};

#endif
