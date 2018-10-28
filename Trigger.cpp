#include "Trigger.h"

Trigger::Trigger(xml_node<>* node) {
	declareItem(node);
}

Trigger::~Trigger() {}

int Trigger::counter(xml_node<> * xnode){
	int counter = 0;
	for (xml_node<> * index = xnode->first_node(); index; index = index->next_sibling()){
		counter++;
	}
	return counter;
}

void Trigger::declareItem(xml_node<>* xnode){
  string myName;
  string myValue;
  string indexType = "type";
  string indexAction = "action";
  string indexCondition = "condition";
  string indexCommand = "command";
  string indexPrint = "print";
  actionIdx = 0;
  printIdx = 0;
  commandIdx = 0;
	for (xml_node<> * index = xnode->first_node(); index; index = index->next_sibling()){
    myName = index->name();
    myValue = index->value();
		if (!myName.compare(indexType)){
			type = myValue;
		}
    else if (!myName.compare(indexAction)){
			toDoActions.push_back(myValue);
      actionIdx = 1;
		}
    else if (!myName.compare(indexCondition)){
			if (counter(index) == 2){
				stat = new StatusT(index);
			}
      else if (counter(index) == 3){
				own = new OwnerT(index);
			}
		}
    else if (!myName.compare(indexCommand)){
			command = myValue;
      commandIdx = 1;
		}
    else if (!myName.compare(indexPrint)){
			print = myValue;
      printIdx = 1;
		}
	}
}
