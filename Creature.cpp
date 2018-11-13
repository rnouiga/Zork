#include "Creature.h"

using namespace std;
using namespace rapidxml;

Creature::Creature(xml_node<>* node)
{
	attackF = false;
	aprint = false;
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
			xml_node<>* temp = child->first_node();
			while(temp)
			{
				if(!strcmp(temp->name(),"print"))
				{
					aprint = true;
					print = temp->value();
				}
				else if(!strcmp(temp->name(), "action"))
				{
					toDoActions.push_back(temp->value());
				}
				temp = temp->next_sibling();
			}
			attackF = true;
		}
		if(!strcmp(child -> name(), "vulnerability"))
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
