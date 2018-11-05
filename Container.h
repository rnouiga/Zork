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
		vector<String> item;
		vector<Trigger *> trigger;

		Container();
		Container(node);
		~Container();

	private:
		void makeContainer(node);
}
