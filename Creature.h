#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include "Trigger.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
// #include "main_helper.h"

class Creature
{
public:
	std::string name;
	std::string status;
	std::string description;
	// Trigger * t;
	std::string print;
	std::vector<string> toDoActions;
	bool attackF;
	bool aprint;
	std::vector<string> vulnerability;
	std::vector<Trigger*> trigger;
	Creature(xml_node<>* node);
	virtual ~Creature();
private:
	void makeCreature(xml_node<>* node);
};

#endif
