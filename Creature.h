#include <string>
#include <vector>
#include "Attack.h"
#include "Trigger.h"

class Creature
{
	public:
		std::string name;
		std::string status;
		std::string description;
		Trigger * t;
		std::vector<string> vulnerability;
		std::vector<Trigger*> trigger;
		// std::string print;
		// std::vector<string> actions;


		Creature();
		Creature(node);
		~Creature();

	private:
		void makeCreature(node);
}
