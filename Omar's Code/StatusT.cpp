#include "StatusT.h"

StatusT::StatusT(xml_node<>* node) {
	declareItem(node);
}

StatusT::~StatusT() {}

void StatusT::declareItem(xml_node<>* node){
  string myName;
  string myValue;
  string indexObj = "object";
  string indexStat = "status";
	for (xml_node<> * index = node->first_node(); index; index = index->next_sibling()){
    myName = index->name();
    myValue = index->value();
		if (!myName.compare(indexObj)){
			object = myValue;
		}
    else if (!myName.compare(indexStat)){
			status = myValue;
		}
	}
}
