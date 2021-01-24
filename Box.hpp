#ifndef BOX_HPP
# define BOX_HPP

# include "Object.hpp"
# include "Wrap.hpp"
# include "Toy.hpp"

class Box : public Wrap {
public:
  Box(std::string const& name = BOX_NAME);
  ~Box();

  void closeMe();
  virtual bool wrapMeThat(Object*);

  virtual bool isOpen() const;
};

#endif
