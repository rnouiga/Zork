#ifndef OWNERT_H
#define OWNERT_H

#include <iostream>
#include <string>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
using namespace std;
using namespace rapidxml;

// typedef struct _Owner{
//     string object;
//     string has;
//     string owner;
// }Owner;
//
// typedef struct _TurnOn{
//   vector <string> toDoActions;
//   string print;
// }TurnOn;
//
// typedef struct _Status{
//     string object;
//     string status;
// }Status;


class OwnerT {
public:
   string object;
   string has;
   string owner;
   virtual ~OwnerT();
   OwnerT(xml_node<>* node);

private:
  void declareItem(xml_node<>* node);
};


#endif /* OWNERT_H */
