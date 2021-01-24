#ifndef CONVEYORBELTPEPENOEL_HPP
# define CONVEYORBELTPEPENOEL_HPP

# include "Object.hpp"
# include "IConveyorBelt.hpp"

# define ICB_ERR_NEMPTY "Conveyor Belt queue overflow ! It's not empty !"
# define ICB_ERR_EMPTY "Lazy little elf T_PAAMAYIM_NEKUDOTAYIM Conveyor Belt is empty !"

class ConveyorBeltPePeNoel : public IConveyorBelt {
protected:
  Object *_content;
  std::string _name;

public:
  ConveyorBeltPePeNoel();
  ~ConveyorBeltPePeNoel();

  Object *Take();
  bool Put(Object *);
  bool IN();
  bool OUT();
  std::string const Look() const;
};

IConveyorBelt *createConveyorBelt();

#endif
