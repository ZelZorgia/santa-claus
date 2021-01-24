#include "Elf.hpp"

Elf::Elf(std::string const& name) :
    _name(name)
{
  _table = createTable();
  _cb = createConveyorBelt();
}

Elf::~Elf()
{
  std::cout << _name << " est liiiiiiiiiibre !!!" << std::endl;
  //delete _table;
  //delete _cb;
}

bool Elf::CheckIfBoxAvailable() const
{
  if (_cb->Look() == BOX_NAME)
    return true;
  std::string *s = _table->Look(); // list of objects
  for (int i=0; !s[i].empty(); i++)
    if (s[i] == BOX_NAME)
      return true;
  return false;
}

bool Elf::CheckIfPaperAvailable() const
{
  if (_cb->Look() == PAPER_NAME)
    return true;
  std::string *s = _table->Look(); // list of objects
  for (int i=0; !s[i].empty(); i++)
    if (s[i] == PAPER_NAME)
      return true;
  return false;
}

bool Elf::CheckIfToyAvailable() const
{
  std::string *s = _table->Look(); // list of objects
  for (int i=0; !s[i].empty(); i++)
    if (s[i] == TEDDY_NAME || s[i] == PONY_NAME)
      return true;
  return false;
}

bool Elf::CheckIfGiftAvailable() const
{
  return CheckIfBoxAvailable() && CheckIfPaperAvailable() && CheckIfToyAvailable();
}

bool Elf::TableHasPlace() const
{
  int i;
  std::string *s = _table->Look();
  for (i=0; !s[i].empty(); i++);
  return i != 10;
}

void Elf::EnumTable() const
{
  std::string *s = _table->Look();
  std::cout << _name << " go to check the table..." << std::endl;
  for (int i = 0; !s[i].empty(); i++)
    std::cout << "There is a " << s[i] << " on the table" << std::endl;
}

Object *Elf::TakeFirstToy()
{
  std::string *s = _table->Look(); // list of objects
  for (int i; !s[i].empty(); i++)
    if (s[i] == TEDDY_NAME || s[i] == PONY_NAME)
      return _table->Take(i);
  return NULL;
}

Object *Elf::TakeFirstBox()
{
  std::string *s = _table->Look(); // list of objects
  for (int i; !s[i].empty(); i++)
    if (s[i] == BOX_NAME)
      return _table->Take(i);
  return _cb->Take();
}

Object *Elf::TakeFirstPaper()
{
  std::string *s = _table->Look(); // list of objects
  for (int i; !s[i].empty(); i++)
    if (s[i] == PAPER_NAME)
      return _table->Take(i);
  return _cb->Take();
}

void Elf::MakeAGift()
{
  Object *toy = TakeFirstToy();
  Object *box = TakeFirstBox();
  Object *paper = TakeFirstPaper();
  box->openMe();
  box->wrapMeThat(toy);
  box->closeMe();
  paper->wrapMeThat(box);
  _gift = paper;
}

bool Elf::TakeAWrap()
{
  _cb->IN();
  if (!_table->Put(_cb->Take()))
    return false;
  return true;
}

bool Elf::StartWork()
{
  // if a gift is dispo or if a toy AND place for a wrap
  while (CheckIfGiftAvailable() || (CheckIfToyAvailable() && TableHasPlace()))
    {
      EnumTable();
      if (CheckIfGiftAvailable())
        {
          MakeAGift(); // set the _gift
          _cb->Put(_gift);
          _cb->OUT();
          _gift = NULL;
        }
      else
        {
          if (!TakeAWrap())
            return false;
        }
    }
  std::cout << "pepe ya un schmolle dans le bignou" << std::endl;
  std::cout << CheckIfGiftAvailable() << CheckIfToyAvailable() << TableHasPlace();
  return true;
}

std::string const& Elf::getName() const {
  return _name;
}
