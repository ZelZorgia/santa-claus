#ifndef GIFTPAPER_HPP
# define GIFTPAPER_HPP

# include "Object.hpp"
# include "Wrap.hpp"

class GiftPaper : public Wrap {
public:
  GiftPaper(std::string const& name = PAPER_NAME);
  ~GiftPaper();
};

#endif
