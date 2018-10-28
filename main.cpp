#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

vector<string> inventory;


using namespace rapidxml;

struct Player
{
//  Player();
//  virtual ~Player();
    Room * current_room = NULL;
    vector<String> inventory;
};

Player p1;
std::vector<Room*> room;
std::vector<Container*> container;
std::vector<Item*> item;
std::vector<Creatures*> creature;

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        std::cout << "Zork: ./zork \"file.xml\""  << std::endl;
        return 0;
    }
    file <>xmlFile(argv[1]);
    xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    // std::cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
    // rapidxml::print(std::ostream, xmlFile);
    // cout << x;
    // rapidxml::print(std::cout, doc, 0);
    std::vector<xml_node<> *> rooms;
    std::vector<xml_node<> *> items;
    std::vector<xml_node<> *> containers;
    std::vector<xml_node<> *> creatures;


    xml_node<> *node = doc.first_node();
    xml_node<> *temp_node = node->first_node();
    while(temp_node)
    {
        std::cout << temp_node->value() << std::endl;
        if(temp_node->name() == "room")
        {
            rooms.push_back(temp_node);
        }
        else if(temp_node->name() == "item")
        {
            items.push_back(temp_node);
        }
        else if(temp_node->name() == "container")
        {
            containers.push_back(temp_node);
        }
        else if(temp_node->name() == "creature")
        {
            creatures.push_back(temp_node);
        }
        temp_node = temp_node->next_sibling();
    }
    for(int i = 0; i < rooms.size(); i++)
    {
        Room * temp_room = new Room(rooms[i]);
        room.push_back(temp_room)
    }
    for(int i = 0; i < items.size(); i++)
    {
        Item * temp_item = new Item(items[i]);
        item.push_back(temp_item);
    }
    for(int i = 0; i < containers.size(); i++)
    {
        Container * temp_container = new Container(containers[i]);
        container.push_back(temp_container);
    }
    for(int i = 0; i <creatures.size(); i++
    {
        Creature * temp_creature = new Creature(creatures[i]);
        creature.push_back(temp_creature);
    }

    p1.current_room = room[0];
    string input_string;
    bool game_done = false;
    while(game_done == false)
    {
        std::getline(cin, input_string);
        parse_input(input_string);


    }

    return 0;
}