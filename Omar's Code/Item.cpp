#include "Item.h"


Item::Item(xml_node<>* node){
	declareItem(node);
}

Item::~Item(){}

void Item::declareItem(xml_node<>* node){
  turnOnStatus = 0;
  string myName;
  string myValue;
  string currName;
  string currValue;
  string indexName = "name";
  string indexStat = "status";
  string indexDescrip = "description";
  string indexWrite = "writing";
  string indexTrig = "trigger"
  string indexTurnOn = "turnon";
  string indexPrint = "print";
  string indexAction = "action";

  for (xml_node<> * index = node->first_node(); index; index = index->next_sibling()){
    myName = index->name();
    myValue = index->value();
    if (string(myName) == indexName){
			name = myValue;
		}
		else if (!myName.compare(indexDescrip)){
			description = myValue;
		}
    else if (!strcmp(myName, indexStat)){
			status = myValue;
		}
		else if (string(myName) == indexTrig){
			Trigger* trig = new Trigger(index);
			trigger.push_back(trig);
		}
    else if (!myName.compare(indexWrite)){
      writing = myValue;
    }
    else if (!strcmp(myName, indexTurnOn)){
      turnOnStatus = 1;
      for (xml_node<> *head = index->first_node(); head; head = head->next_sibling()){
        currName = head->name();
        currValue = head->value();
        if(string(currName) == indexPrint){
          TurnOn.print = currValue;
        }
        else if(!strcmp(currName, indexAction){
          TurnOn.toDoActions.push_back(currValue);
        }
      }
    }
  }
  return;
}
