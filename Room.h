#ifndef _ROOM_H
#define _ROOM_H

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<vector>
#include<string>
#include "Trigger.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
// #include "main_helper.h"

using namespace rapidxml;

struct border
{
    std::string Name;
    std::string Direction;
};

class Room
{
public:
    std::string name;
    std::string status;
    std::string type;
    std::string description;
    std::vector<border*> border_rooms;
    std::vector<std::string> items;
    std::vector<std::string> creatures;
    std::vector<Trigger *> triggers;
    std::vector<std::string> containers;
    Room(xml_node<>* node);
    virtual ~Room();
};
#endif /*ROOM_H*/
