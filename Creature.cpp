#include "Creature.h"
using namespace as std;

Creature::Creature(xml_node<>* node)
{
	makeCreature(node);
}

void Creature::makeCreature(xml_node<>* node)
{
	xml_node<>* child =
	while(child)
	{
		if(!strcmp(child -> name(), "name"))
		{
			name = child -> ;
		}
		if(!strcmp(child -> name(), "status"))
		{
			status = child -> ;
		}
		if(!strcmp(child -> name(), "description"))
		{
			description = child -> ;
		}
		if(!strcmp(child -> name(), "attack"))
		{
			attack = new Attack(child);
		}
		if(!strcmp(child -> name(), "vulnerablility"))
		{
			vulnerability.push_back();
		}
		if(!strcmp(child -> name(), "trigger"))
		{
			Trigger* newTrigger = new Trigger(child);
			trigger.push_back(newTrigger);
		}
		child = child -> next;
	}
}
