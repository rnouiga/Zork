#ifndef TRIGGER_H
#define TRIGGER_H

#include <iostream>
#include <string>
#include <vector>
#include "StatusT.h"
#include "OwnerT.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
using namespace std;
using namespace rapidxml;

typedef struct _Owner{
    string object;
    string has;
    string owner;
}Owner;

typedef struct _TurnOn{
  vector <string> toDoActions;
  string print;
}TurnOn;

typedef struct _Status{
    string object;
    string status;
}Status;


class Trigger {
public:
   string command;
   string type;
   string print;
   vector <string> toDoActions;
   int actionIdx;
   int commandIdx;
   int printIdx;
   StatusT* stat;
   OwnerT* own;
   virtual ~Trigger();
   Trigger(xml_node<>* node);

private:
  void declareItem(xml_node<>* node);
  int counter(xml_node<> * node);
};


#endif /* TRIGGER_H */
