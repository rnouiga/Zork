#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Trigger.h"
using namespace std;
using namespace rapidxml;

typedef struct _TurnOn{
  vector <string> toDoActions;
  string print;
}TurnOn;

class Item {
public:
   string name;
   string status;
   string writing;
   string description;
   vector <Trigger*> trigger;
   TurnOn turnOn;
   int turnOnStatus;
   virtual ~Item();
   Item(xml_node<>* node);

private:
  void declareItem(xml_node<>* node);
};


#endif /* ITEM_H */
