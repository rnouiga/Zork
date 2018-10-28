#include "OwnerT.h"

OwnerT::OwnerT(xml_node<>* node) {
	declareItem(node);
}

OwnerT::~OwnerT() {}

void OwnerT::declareItem(xml_node<>* node){
  string myName;
  string myValue;
  string indexObj = "object";
  string indexHas = "has";
  string indexOwner = "owner";
	for (xml_node<> * index = node->first_node(); index; index = index->next_sibling()){
    myName = index->name();
    myValue = index->value();
		if (!myName.compare(indexObj)){
			object = myValue;
		}
    else if (!myName.compare(indexHas)){
			has = myValue;
		}
    else if (!myName.compare(indexOwner)){
			owner = myValue;
		}
	}
}
