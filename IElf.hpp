#ifndef IELF_HPP
# define IELF_HPP

# include <string>
# include "ConveyorBeltPePeNoel.hpp"
# include "TablePePeNoel.hpp"

class IElf
{
protected:
  virtual ~IElf() {}
  virtual bool CheckIfBoxAvailable() const = 0;
  virtual bool CheckIfPaperAvailable() const = 0;
  virtual bool CheckIfToyAvailable() const = 0;
  virtual bool CheckIfGiftAvailable() const = 0;
  virtual bool TableHasPlace() const = 0;
  virtual void EnumTable() const = 0;
  virtual Object *TakeFirstToy() = 0;
  virtual Object *TakeFirstBox() = 0;
  virtual Object *TakeFirstPaper() = 0;
  virtual void MakeAGift() = 0;
  virtual bool TakeAWrap() = 0;
public:
  virtual bool StartWork() = 0;
  virtual std::string const& getName() const = 0;
};

#endif
