#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>
#include "Trigger.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

class Container
{
	public:
		string name;
		string status;
		string description;
		vector<string> accept;
		vector<string> items;
		vector<Trigger *> trigger;

		// Container();
		Container(xml_node <>* node);
		virtual ~Container();

	private:
		void makeContainer(xml_node <>* node);
};

#endif
