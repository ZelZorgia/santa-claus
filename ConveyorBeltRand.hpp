#ifndef CONVEYORBELTRAND_HPP
# define CONVEYORBELTRAND_HPP

# include "ConveyorBeltPePeNoel.hpp"

class ConveyorBeltRand : public ConveyorBeltPePeNoel {
public:
  ConveyorBeltRand();
  ~ConveyorBeltRand();
  bool IN();
  std::string Serialize();
};

#endif
