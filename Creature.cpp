#include "Creature.h"

using namespace std;
using namespace rapidxml;

Creature::Creature(xml_node<>* node)
{
	makeCreature(node);
}
Creature::~Creature() {}

void Creature::makeCreature(xml_node<>* node)
{
	xml_node<>* child = node->first_node();
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
			t = new Trigger(child);
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
