#include 'Container.h'

using namespace std;

Container::Container(xml_node<>* node)
{
	makeContainer(node);
}

void Container::makeContainer(node)
{
	child = node -> 
	if(!strcmp(child -> name(), "name"))
		{
			name = child ->;
		}
		if(!strcmp(child -> name(), "status"))
		{
			status = child -> ;
		}
		if(!strcmp(child -> name(), "description"))
		{
			description = child -> ;
		}
		if(!strcmp(child -> name(), "accept"))
		{
			accept.push_back();
		}
		if(!strcmp(child -> name(), "item"))
		{
			item.push_back();
		}
		if(!strcmp(child -> name(), "trigger"))
		{
			Trigger* newTrigger = new Trigger(child);
			tigger.push_back(newTrigger);
		}
		child = child -> next;
}
