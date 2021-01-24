#ifndef OBJECT_HH
# define OBJECT_HH

# define PONY_NAME "Little Pony"
# define BOX_NAME "Box"
# define TEDDY_NAME "Teddy"
# define PAPER_NAME "GiftPaper"

#include <iostream>
#include <string>

class Object {
private:
  std::string const _name;
  std::string const _type;

protected:
  bool _inUse;

public:
  Object(std::string const &, std::string const &);
  virtual ~Object();

  virtual void isTaken() = 0;
  std::string const & getName() const;

  virtual void openMe();
  virtual bool isOpen() const;
  virtual bool wrapMeThat(Object *);
  virtual void closeMe();
  virtual Object* getContent() const;
  virtual void setContent(Object* o);
  virtual std::string const& getType() const;

  virtual std::string XML() const;
};

std::ostream& operator<<(std::ostream &, Object const &);
Object *MyUnitTests(Object **);

#endif
