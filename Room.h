#ifndef _ROOM_H
#define _ROOM_H

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

class Room
{
public:
    string name;
    string status;
    string type;
    string description;
    std::vector<border*> border_rooms;
    std::vector<string> items;
    std::vector<string> creatures;
    std::vector<Trigger *> triggers;
    std::vector<string> containers;
    Room(xml_node<>* node);
    virtual ~Room();
}
#endif /*ROOM_H*/
