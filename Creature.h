#include<string>
#include 'Attack'
#include 'Trigger'

class Creature
{
	public:
		std::string name;
		std::string status;
		std::string description;
		Attack* attack;
		std::vector<string> vulnerability;
		std::vector<Trigger*> trigger;
		
		Creature();
		Creature(node);
		~Creature();
	
	private:
		void makeCreature(node);
}