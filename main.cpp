#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "main_helper.h"
// vector<string> inventory;


using namespace rapidxml;



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
    // std::cout << temp_node->name() << std::endl;
    //print what the node is
    // if(strcmp(temp_node->name())
    while(temp_node)
    {
        // std::cout << temp_node->value() << std::endl;
        if(!strcmp(temp_node->name(), "room"))
        {
            rooms.push_back(temp_node);
        }
        else if(!strcmp(temp_node->name(), "item"))
        {
            items.push_back(temp_node);
        }
        else if(!strcmp(temp_node->name(), "container"))
        {
            containers.push_back(temp_node);
        }
        else if(!strcmp(temp_node->name(), "creature"))
        {
            creatures.push_back(temp_node);
        }
        temp_node = temp_node->next_sibling();
    }
    for(int i = 0; i < rooms.size(); i++)
    {
        Room * temp_room = new Room(rooms[i]);
        // std::cout <<  << std::endl;
        room.push_back(temp_room);
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
    for(int i = 0; i <creatures.size(); i++)
    {
        Creature * temp_creature = new Creature(creatures[i]);
        creature.push_back(temp_creature);
    }

    p1.current_room = room[0];
    string input_string;
    std::cout << p1.current_room->description << std::endl;

    bool return_value1;
    bool return_value2;
    while(game_done == false)
    {
        return_value1 = check_non_command_triggers();
        if(game_done == true)
        {
            break;
        }
        std::getline(cin, input_string);
        if(input_string == "q")
        {
            break;
        }
        if(game_done == true)
        {
            break;
        }
        return_value2 = trigger_command(input_string);
        if(game_done == true)
        {
            break;
        }
        if(return_value2)
        {
            continue;
        }
        parse_input(input_string);
        if(game_done == true)
        {
            break;
        }
    }
    return 0;
}
