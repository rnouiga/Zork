#include "Room.h"

struct border
{
    string Name;
    string Direction;
}

Room::Room(xml_node<>* node)
{
    type = "regular";
    xml_node<>* temp_node = node->first_node();
    while(temp_node)
    {
        if(strcmp(temp_node->name(), "name") == 0)
        {
            name = temp_node->value();
        }
        else if(strcmp(temp_node->name(), "description") == 0)
        {
            description = temp_node->value();
        }
        else if(strcmp(temp_node->name(), "type") == 0)
        {
            type = temp_node->value();
        }
        else if(strcmp(temp_node->name(), "status") == 0)
        {
            status = temp_node->value();
        }
        else if(strcmp(temp_node->name(), "border") == 0)
        {
            Border * temp_border = new Border;
            xml_node<>* temp = temp_node->first_node()
            while(temp)
            {
                if(strcmp(temp->name(), "direction") == 0)
                {
                    temp_border->direction = temp->value();
                }
                else if(strcmp(temp->name(), "name") == 0)
                {
                    temp_border->name = temp->value;
                }
                temp = temp->next_sibling();
            }
            border_rooms.push_back(temp_border);
        }
        else if(strcmp(temp_node->name(), "item") == 0)
        {
            items.push_back(temp_node->value());
        }
        else if(strcmp(temp_node->name(), "creature"))
        {
            creatures.push_back(temp_node->value());
        }
        else if(strcmp(temp_node->name(), "container") == 0)
        {
            containers.push_back(temp_node->value);
        }
        else if(strcmp(temp_node->name(), "trigger") == 0)
        {
            Trigger * temp_trigger = new Trigger(temp_node);
            triggers.push_back(temp_trigger);
        }
        temp_node = temp_node->next_sibling();
    }

}
Room::~Room()
{

}
