#include <string>
using namespace std;

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