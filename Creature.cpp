#include "Creature.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace as std;
using namespace rapidxml;

Creature::Creature(xml_node<>* node)
{
	makeCreature(node);
}

void Creature::makeCreature(xml_node<>* node)
{
	xml_node<>* child = node -> first_node();
	while(child)
	{
		if(!strcmp(child -> name(), "name"))
		{
			name = child -> value();
		}
		if(!strcmp(child -> name(), "status"))
		{
			status = child -> value();
		}
		if(!strcmp(child -> name(), "description"))
		{
			description = child -> value();
		}
		if(!strcmp(child -> name(), "attack"))
		{
			t = new Trigger(child->first_node);
			t->type = "permanent";
		}
		if(!strcmp(child -> name(), "vulnerablility"))
		{
			vulnerability.push_back(child -> value());
		}
		if(!strcmp(child -> name(), "trigger"))
		{
			Trigger* newTrigger = new Trigger(child);
			trigger.push_back(newTrigger);
		}
		child = child -> next_sibling();
	}
}
