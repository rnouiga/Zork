#include "Room.h"

Room::Room(xml_node<>* node)
{
    type = "regular";
    xml_node<>* temp_node = node->first_node();
    while(temp_node)
    {
        // std::cout << temp_node->name() << std::endl;
        if(strcmp(temp_node->name(), "name") == 0)
        {
            //change dsome of this shit to transport pointer to corresponding item or container obejcts that are within the rooms
            name = temp_node->value();
        }
        if(strcmp(temp_node->name(), "description") == 0)
        {
            description = temp_node->value();
        }
        if(strcmp(temp_node->name(), "type") == 0)
        {
            type = temp_node->value();
        }
        if(strcmp(temp_node->name(), "status") == 0)
        {
            status = temp_node->value();
        }
        if(strcmp(temp_node->name(), "border") == 0)
        {
            border * temp_border = new border;
            xml_node<>* temp = temp_node->first_node();
            while(temp)
            {
                if(strcmp(temp->name(), "direction") == 0)
                {
                    temp_border->Direction = temp->value();
                }
                else if(strcmp(temp->name(), "name") == 0)
                {
                    temp_border->Name = temp->value();
                }
                temp = temp->next_sibling();
            }
            border_rooms.push_back(temp_border);
        }
        if(strcmp(temp_node->name(), "item") == 0)
        {
            items.push_back(temp_node->value());
        }
        if(strcmp(temp_node->name(), "creature") == 0)
        {
            creatures.push_back(temp_node->value());
        }
        if(strcmp(temp_node->name(), "container") == 0)
        {
            // std::cout << temp_node->value() << std::endl;
            containers.push_back(temp_node->value());
        }
        if(strcmp(temp_node->name(), "trigger") == 0)
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
