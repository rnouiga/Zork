#include "Container.h"
#include "main_helper.h"

// using namespace std;

Container::Container(xml_node<>* node)
{
	makeContainer(node);
}

void Container::makeContainer(xml_node<>* node)
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
		if(!strcmp(child -> name(), "accept"))
		{
			accept.push_back(child -> value());
		}
		if(!strcmp(child -> name(), "item"))
		{
			items.push_back(child -> value());
		}
		if(!strcmp(child -> name(), "trigger"))
		{
			Trigger* newTrigger = new Trigger(child);
			trigger.push_back(newTrigger);
		}
		child = child -> next_sibling();
	}
}
