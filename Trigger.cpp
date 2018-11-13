#include "Trigger.h"
// #include "main_helper.h"

Trigger::Trigger(xml_node<>* node) {
	single = false;
	declareItem(node);
}

Trigger::~Trigger() {}

int Trigger::counter(xml_node<> * node){
	int counter = 0;
	for (xml_node<> * index = node->first_node(); index; index = index->next_sibling()){
		counter++;
	}
	return counter;
}

void Trigger::declareItem(xml_node<>* node){
	string myName;
	string myValue;
	type = "permanent";
	string indexType = "type";
	string indexAction = "action";
	string indexCondition = "condition";
	string indexCommand = "command";
	string indexPrint = "print";
	actionIdx = 0;
	printIdx = 0;
	commandIdx = 0;
	for (xml_node<> * index = node->first_node(); index; index = index->next_sibling()){
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
			condition_count = counter(index);
			if (condition_count == 2){
				stat = new StatusT(index);
			}
	  		else if (condition_count == 3){
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
