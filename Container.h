#include <string>
#include <vector>

#include "Trigger.h"

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
