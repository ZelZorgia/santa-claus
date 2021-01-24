#ifndef TABLEPEPENOEL_HPP_
# define TABLEPEPENOEL_HPP_

# include "ITable.hpp"

class TablePePeNoel : public ITable {
protected:
  Object* _content[9];
  std::string *_strings;

  void generateStrings();
public:
  TablePePeNoel();
  ~TablePePeNoel();
  Object *Take();
  Object *Take(int i);
  bool Put(Object*);
  std::string* Look() const;
};

ITable *createTable();

#endif
