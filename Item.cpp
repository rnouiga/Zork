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
  Ywrite = false;
  string indexName = "name";
  string indexStat = "status";
  string indexDescrip = "description";
  string indexWrite = "writing";
  string indexTrig = "trigger";
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
    else if (!myName.compare(indexStat)){
			status = myValue;
		}
		else if (string(myName) == indexTrig){
			Trigger* trig = new Trigger(index);
			trigger.push_back(trig);
		}
    else if (!myName.compare(indexWrite)){
      writing = myValue;
	  Ywrite = true;
    }
    else if (!myName.compare(indexTurnOn)){
      turnOnStatus = 1;
      for (xml_node<> *head = index->first_node(); head; head = head->next_sibling()){
        currName = head->name();
        currValue = head->value();
        if(string(currName) == indexPrint){
          turnOn.print = currValue;
        }
        else if(!currName.compare(indexAction)){
          turnOn.toDoActions.push_back(currValue);
        }
      }
    }
  }
  return;
}
