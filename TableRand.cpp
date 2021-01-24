#include <cstdlib>
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "TableRand.hpp"

TableRand::TableRand() : TablePePeNoel() {
  for (int i = 0; i < 9; ++i)
    switch (random() % 4) {
    case 0:
      _content[i] = new Teddy;
      break ;
    case 1:
      _content[i] = new LittlePony;
      break ;
    case 2:
      _content[i] = new Box;
      break ;
    case 3:
      _content[i] = new GiftPaper;
      break ;
    }
}

TableRand::~TableRand() {
  for (int i = 0; i < 9; ++i)
    if (_content[i])
      delete _content[i];
}
