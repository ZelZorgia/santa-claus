#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "Elf.hpp"

Object* MyUnitTests(Object**);
Object** MyUnitTests();

int		main(void)
{
  std::cout << "----- TEST UNITAIRE 1 -----" << std::endl;
  Object **objTab = MyUnitTests();
  
  std::cout << objTab[0]->getName() << std::endl;
  std::cout << objTab[1]->getName() << std::endl;

  std::cout << std::endl <<std::endl;
  std::cout << "----- TEST UNITAIRE 2 -----" << std::endl;

  Object *Tibers = new Teddy("Tibers");
  Object *BBox = new Box("Byougues Box");
  Object *Paper = new GiftPaper("Kitty Paper");
  Object *tab[3];
  tab[0] = Tibers;
  tab[1] = BBox;
  tab[2] = Paper;
  Object *unit = MyUnitTests(tab);

  std::cout << std::endl;
  std::cout << "Oh this a " << unit->getName() << " !" << std::endl;
  std::cout << "OHHH a " << unit->getContent()->getName() << " So Fiber so Optical !" << std::endl;
  std::cout << "AAAAAAAAAAAH !! How can this be ?! *" << unit->getContent()->getContent()->getName() << " GROWLS ! *" 
  	    << std::endl;
  std::cout << std::endl << std::endl;

  std::cout << "-------- TEST UNITAIRE - ELF --------" << std::endl;

  IElf *elf = new Elf;
  std::cout << elf->getName() << std::endl;
  elf->StartWork();

  std::cout << "-------- TEST XML --------" << std::endl;
  
  std::cout << Tibers->XML() << std::endl;
  std::cout << BBox->XML() << std::endl << std::endl;
  std::cout << unit->XML() << std::endl;

  std::cout << "-------- TEST ELF --------" << std::endl;

  delete Tibers;
  delete BBox;
  delete Paper;
  return 0;
}
