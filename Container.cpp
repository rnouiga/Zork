#include 'Container.h'

using namespace std;

Container::Container(xml_node<>* node)
{
	makeContainer(node);
}

void Container::makeContainer(node)
{
	child = node -> node -> frist_node();
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
			item.push_back(child -> value());
		}
		if(!strcmp(child -> name(), "trigger"))
		{
			Trigger* newTrigger = new Trigger(child);
			tigger.push_back(newTrigger);
		}
		child = child -> next();
	}
}
