#include <string>
#include <iostream>
#include <fstream>
#include "Object.hpp"

bool checkErrorOnContent(std::string content, int level)
{
  //If error, return and fail
  if (level == 0)
    {
      if (content == PAPER_NAME)
        std::cout << "whistles while working" << std::endl;
      else
        {
          std::cout << "Error : Expected '" << PAPER_NAME << "', was '" << content << "'" << std::endl;
          return false;
        }
    }
  else if (level == 1)
    {
      if (content == BOX_NAME)
        std::cout << "whistles while working" << std::endl;
      else
        {
          std::cout << "Error : Expected '" << PAPER_NAME << "', was '" << content << "'" << std::endl;
          return false;
        }
    }
  else if (level == 2)
    {
      if (content == PONY_NAME)
        std::cout << "yo man" << std::endl;
      else if (content == TEDDY_NAME)
        std::cout << "gra hu" << std::endl;
      else
        {
          std::cout << "Error : Expected a TOY, was '" << content << "'" << std::endl;
          return false;
        }
    }
  else if (level > 2 && content != "")
    {
      std::cout << "Error : Unexpected level !" << std::endl;
      return false;
    }
  return true;
}

bool checkList(std::string list, int level)
{
  std::string bloc; // sub bloc to handle recursivly
  std::string content; // the content of the valise
  std::string obj_next = list; // next bloc
  std::string balise; // temporary variable

  while (obj_next.find(">"))
    {
      //std::cout << "________________________________" << std::endl;
      //std::cout << "BLOC |" << obj_next << std::endl;
      std::string content = obj_next.substr(0, obj_next.find(">")); // keep <NAME
      content = content.erase(0, 1); // keep NAME

      //std::cout << "CONTENT |" << content << std::endl;
      if (content == "") return true;
      if (!checkErrorOnContent(content, level)) return false;

      bloc = obj_next.erase(0, content.size() + 2); // get 1|...|</TYPE>2|...|
      balise = std::string("</") + content + ">"; // </NAME>

      bloc = bloc.substr(0, bloc.find(balise)); // KEEP ONLY 1|...| TO HANDLE
      //std::cout << "SUB-BLOC |" << bloc << std::endl;
      //std::cout << "BALISE   |" << balise << std::endl;
      if (bloc == "") return true;

      if (!checkList(bloc, level + 1)) return false;
      obj_next = obj_next.erase(0, bloc.size() + balise.size());
    }
  return (true);
}

int main(int ac, char **av)
{
  std::string filename;
  std::ifstream f;
  std::string line;
  std::string content;

  for (int i=1; i < ac; i++)
    {
      f.open(av[i]);
      if (!f.good())
        std::cerr << "File " << av[i] << " is unreadable" << std::endl;
      else
        {
          content = "";
          while (!f.eof())
            {
              getline(f, line);
              content += line;
            }
          f.close();
          if (!checkList(content, 0))
            std::cout << "The list '" << av[i] << "' has been broken." << std::endl;
        }
    }
  return 0;
}
