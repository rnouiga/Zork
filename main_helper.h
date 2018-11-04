#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

#include <vector>
#include <string>
#include "Room.h"
#include "Trigger.h"
#include "Creature.h"
#include "Item.h"
#include "Container.h"

bool game_done = false;

void Add(string action)
{
    std::size_t index = action.find(" to ");
    string obj = action.substr(0, index);
    string location = action.substr(index+4);

    string type_obj = type_of(obj);
    // string type_location = type_of(location);
    if(!strcmp(type_obj, "Container"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!strcmp(room[i]->name, location))
            {
                room[i]->containers.push_back(obj);
                return;
            }
        }
    }
    if(!strcmp(type_obj, "Item"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!strcmp(room[i]->name, location))
            {
                room[i]->items.push_back(obj);
                return;
            }
        }
        for(int i = 0; i < container.size(); i++)
        {
            if(!strcmp(container[i]->name, location))
            {
                container[i]->items.push_back(obj);
                return;
            }
        }
    }
    if(!strcmp(type_obj, "Creature"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!strcmp(room[i]->name, location))
            {
                room[i]->creatures.push_back(obj);
                return;
            }
        }
    }
}
void Delete(string action)
{
    string type_obj = type_of(action);

    if(!strcmp(type_obj, "Room"))
    {
        for(int i = 0; i < p1.current_room->border.size(); i++)
        {
            if(p1.current_room->border[i]->name == action)
            {
                p1.current_room->border.erase(p1.current_room->border.begin()+i);
                return;
            }
        }
    }
    else if(!strcmp(type_obj, "Item"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            for(int j = 0; j < room[i]->items.size(); j++)
            {
                if(room[i]->items[j] == action)
                {
                    room[i]->items.erase(room[i]->items.begin()+j);
                    return;
                }
            }
        }
    }
    else if(!strcmp(type_obj, "Container"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            for(int j = 0; j < room[i]->containers.size(); j++)
            {
                if(room[i]->containers[j] == action)
                {
                    room[i]->containers.erase(room[i]->container.begin()+j);
                    return;
                }
            }
        }
    }
    else if(!strcmp(type_obj, "Creature"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            for(int j = 0; j < room[i]->creatures.size(); j++)
            {
                if(room[i]->creatures[j] == action)
                {
                    room[i]->creatures.erase(room[i]->creatures.begin()+j);
                    return;
                }
            }
        }
    }
}
void Update(string action)
{
    std::size_t index = action.find(" to ");
    string obj = action.substr(0, index);
    string status = action.substr(index+4);

    string type_obj = type_of(obj);

    if(!strcmp(type_obj, "Room"))
    {
        for(int i  = 0; i < room.size(); i++)
        {
            if(!strcmp(room[i]->name, obj))
            {
                room[i]->status = status;
                return;
            }
        }
    }
    if(!strcmp(type_obj, "Item"))
    {
        for(int i  = 0; i < item.size(); i++)
        {
            if(!strcmp(item[i]->name, obj))
            {
                item[i]->status = status;
                return;
            }
        }
    }
    if(!strcmp(type_obj, "Creature"))
    {
        for(int i  = 0; i < creature.size(); i++)
        {
            if(!strcmp(creature[i]->name, obj))
            {
                creature[i]->status = status;
                return;
            }
        }
    }
    if(!strcmp(type_obj, "Container"))
    {
        for(int i  = 0; i < container.size(); i++)
        {
            if(!strcmp(container[i], obj))
            {
                container[i]->status = status;
                return;
            }
        }
    }

}
void Game_over()
{
    if(p1.current_room->type == "exit")
    {
        std::cout  << "Game Over" << std::endl;
        std::cout << "Victory!" << std::endl;
        game_done = true;
        return;
    }
    std::cout << "Room is not Exit." << std::endl;
    return;
}
void print_inventory()
{
    if(p1.inventory.size() == 0)
    {
        std::cout << "Inventory: empty" << std::endl;
    }
    else
    {
        for(int i = 0; i < p1.inventory.size() - 1; i++)
        {
            std::cout << p1.inventory[i]->name << ", ";
        }
        std::cout << p1.inventory[p1.inventory.size() - 1]->name << std::endl;
    }
}
void open_container(string container)
{
    int i = 0;
    for(i; i < p1.current_room->containers.size(); i++)
    {
        if(p1.current_room->containers[i]->name == container)
        {
            for(int j)
        }
    }
}
void room_check(string input)
{
    int border_index;
    int count = 0;
    for(border_index = 0; border_index < p1.current_room->border_rooms.size(); border_index++)
    {
        if(p1.current_room->border_rooms[border_index]->direction == input)
        {

        }
    }
    if()
}
void take(string Item)
{
    for(int i = 0; i  < p1.current_room->items.size(); i++)
    {
        if(!strcmp(p1.current_room->items[i], Item))
        {
            p1.current_room->inventory.push_back(p1.current_room->items[i]);
        }
    }
}
void read_item(string Item)
{
    int i = 0;
    for(i = 0;  i < p1.inventory.size(); i++)
    {
        if(!strcmp(p1.inventory[i]->name, Item))
        {
            if(p1.inventory[i]->writing != NULL)
            {
                std::cout << p1.inventory[i]->writing << std::endl;
                return;
            }
            else
            {
                std::cout << "Nothing written" << std::endl;
                return;
            }
        }
    }
    if(i == p1.inventory.size())
    {
        std::cout << "Item not in inventory"  << std::endl;
        return;
    }
}
void parse_input(string input)
{
    if(input == "n" || input == "s" || input == "e" || input == "w")
    {
        room_check(input);
    }
    else if(input.find("take") != string::npos)
    {
        if(input.size() == 4)
        {
            std::cout << "Must take an item, so give an item." << std::endl;
            string temp_item;
            getline(cin, temp_item);
            take(temp_item);
        }
        else
        {
            input.erase(0,4);
            take(input);
        }
    }
    else if(input.find("read") != string::npos)
    {
        if(input.size() == 4)
        {
            std::cout << "What item" << std::endl;
            string temp;
            getline(cin, temp);
            read_item(temp);
        }
        else
        {
            input.erase(0,4);
            read_item(input);
        }
    }
    else if(input.find("open") != string::npos)
    {
        if(input.size() == 4)
        {
            std::cout << "which container would you like to open?" << std::endl;
            string temp_container;
            getline(cin, temp_container);
            open_container(temp_container);
        }
        else
        {
            input.erase(0,4);
            open_container(input);
        }
    }
    else if(strcmp(input, "open exit") == 0)
    {
        if(p1.current_room->temp_room.type == "exit")
        {
            Game_over();
        }
    }
    else if(strcmp(input, "i") == 0)
    {
        print_inventory();
    }
}
bool check_non_command_triggers()
{
    bool CM_trigRoom;

    for(int i = 0; i < p1.current_room->triggers.size(); i++)
    {
        Trigger * trig = p1.current_room->triggers[i];
        if(trig->commandIdx == 0)
        {
            if(!strcmp(trig->type, "permanent") || (!strcmp(trig->type, "single") && trig->single == false))
            {
                if(trig->condition_count == 3)
                {
                    CM_trigRoom = check_for_ownership(trig);
                }
                else if(t->condition == 2)
                {
                    CM_trigRoom = check_status(trig);
                }
                if(CM_trigRoom == true)
                {
                    trig->single == true;
                }
            }
        }
    }
    bool CM_trigItem;

    for(int i = 0 ; i < p1.current_room->items.size(); i++)
    {
        for(int j = 0; j < item.size(); j++)
        {
            if(!strcmp(p1.current_room->items[i], item[j]))
            {
                for(int a = 0; a < item[j]->triggers.size(); a++)
                {
                    Trigger * trig = item[j]->triggers[a];
                    if(trig->commandIdx == 0)
                    {
                        if(!strcmp(trig->type, "permanent") || (!strcmp(trig->type, "single") && trig->single == false))
                        {
                            if(trig->condition_count == 3)
                            {
                                CM_trigItem = check_for_ownership(trig);
                            }
                            else if(t->condition == 2)
                            {
                                CM_trigItem = check_status(trig);
                            }
                            if(CM_trigItem== true)
                            {
                                trig->single == true;
                            }
                        }
                    }
                }
            }
        }
    }
    bool CM_trigcreature;

    for(int i = 0 ; i < p1.current_room->creatures.size(); i++)
    {
        for(int j = 0; j < creature.size(); j++)
        {
            if(!strcmp(p1.current_room->creatures[i], creature[j]))
            {
                for(int a = 0; a < creature[j]->triggers.size(); a++)
                {
                    Trigger * trig = creature[j]->triggers[a];
                    if(trig->commandIdx == 0)
                    {
                        if(!strcmp(trig->type, "permanent") || (!strcmp(trig->type, "single") && trig->single == false))
                        {
                            if(trig->condition_count == 3)
                            {
                                CM_trigcreature = check_for_ownership(trig);
                            }
                            else if(t->condition == 2)
                            {
                                CM_trigcreature = check_status(trig);
                            }
                            if(CM_trigcreature== true)
                            {
                                trig->single == true;
                            }
                        }
                    }
                }
            }
        }
    }
    bool CM_trigcontainer;
    for(int i = 0 ; i < p1.current_room->containers.size(); i++)
    {
        for(int j = 0; j < container.size(); j++)
        {
            if(!strcmp(p1.current_room->containers[i], container[j]))
            {
                for(int a = 0; a < container[j]->triggers.size(); a++)
                {
                    Trigger * trig = container[j]->triggers[a];
                    if(trig->commandIdx == 0)
                    {
                        if(!strcmp(trig->type, "permanent") || (!strcmp(trig->type, "single") && trig->single == false))
                        {
                            if(trig->condition_count == 3)
                            {
                                CM_trigcontainer = check_for_ownership(trig);
                            }
                            else if(trig->condition_count == 2)
                            {
                                CM_trigcontainer = check_status(trig);
                            }
                            if(CM_trigcontainer == true)
                            {
                                trig->single == true;
                            }
                        }
                    }
                }
            }
        }
    }
    bool final_value = CM_trigItem || CM_trigRoom || CM_trigcreature || CM_trigcontainer; // see if any trigger had taken place over all
    return final_value;
}
string type_of(string obj)
{
    for(int i = 0 ; i < room.size(); i++)
    {
        if(!room[i]->name.compare(obj))
        {
            return "Room";
        }
    }
    for(int i = 0 ; i < item.size(); i++)
    {
        if(!item[i]->name.compare(obj))
        {
            return "Item";
        }
    }
    for(int i = 0 ; i < container.size(); i++)
    {
        if(!container[i]->name.compare(obj))
        {
            return "Container";
        }
    }
    for(int i = 0 ; i < creature.size(); i++)
    {
        if(!creature[i]->name.compare(obj))
        {
            return "Creature";
        }
    }
}
void perform_action(string a)
{
    if(!strcmp(a, "Game Over") != string::npos)
    {
        Game_over();
        return;
    }
    else if(a.find("Add") != string::npos)
    {
        string temp = a.erase(0,4);
        Add(temp);
        return;
    }
    else if(a.find("Delete") != string::npos)
    {
        string temp = a.erase(0,7);
        Delete(temp);
        return;
    }
    else if(a.find("Update") != string::npos)
    {
        string temp = a.erase(0, 7);
        Update(temp);
        return;
    }
    perform_action(action);
}
bool check_for_ownership(Trigger * info)
{
    String owner = info->own->owner;
    String has = info->own->has;
    String object = info->own->object;
    int count  = 0;
    if(!strcmp(owner, "inventory"))
    {
        for(int i = 0; i < p1.inventory.size(); i++)
        {
            if(!strcmp(p1.inventory[i]->name, object))
            {
                if(!strcmp(has, "yes"))
                {
                    if(info->printIdx)
                    {
                        std::cout << info->print << std::endl;
                    }
                    if(info->actionIdx)
                    {
                        for(int j = 0;  j < info->toDoActions.size(); j++)
                        {
                            perform_action(info->toDoActions[j]);
                        }
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }
            count =  count + 1;
        }
        if(count == p1.inventory.size())
        {
            if(!strcmp(has, "no"))
            {
                if(info->printIdx)
                {
                    std::cout << info->print << std::endl;
                }
                if(info->actionIdx)
                {
                    for(int j = 0;  j < info->toDoActions.size(); j++)
                    {
                        perform_action(info->toDoActions[j]);
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    string value = type_of(owner);
    string obj = type_of(object);
    count = 0;
    if(!strcmp(value, "Room"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!strcmp(room[i]->name, owner))
            {
                if(!strcmp(obj, "Item"))
                {
                    count = 0;
                    for (int j = 0;  j < room[i]->items.size(); j++)
                    {
                        if(!strcmp(room[i]->items[j]->name, object))
                        {
                            if(!strcmp(has, "yes"))
                            {
                                if(info->printIdx)
                                {
                                    std::cout << info->print << std::endl;
                                }
                                if(info->actionIdx)
                                {
                                    for(int k = 0;  k < info->toDoActions.size(); k++)
                                    {
                                        perform_action(info->toDoActions[j]);
                                    }
                                }
                                return true;
                            }
                            else
                            {
                                return false;
                            }

                        }
                        count = count + 1;
                    }
                    if(count == room[i]->items.size())
                    {
                        if(!strcmp(has, "no"))
                        {
                            if(info->printIdx)
                            {
                                std::cout << info->print << std::endl;
                            }
                            if(info->actionIdx)
                            {
                                for(int j = 0;  j < info->toDoActions.size(); j++)
                                {
                                    perform_action(info->toDoActions[j]);
                                }
                            }
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else if(!strcmp(obj, "Container"))
                {
                    count = 0;
                    for (int j = 0;  j < room[i]->containers.size(); j++)
                    {
                        if(!strcmp(room[i]->containers[j]->name, object))
                        {
                            if(!strcmp(has, "yes"))
                            {
                                if(info->printIdx)
                                {
                                    std::cout << info->print << std::endl;
                                }
                                if(info->actionIdx)
                                {
                                    for(int k = 0;  k < info->toDoActions.size(); k++)
                                    {
                                        perform_action(info->toDoActions[j]);
                                    }
                                }
                                return true;
                            }
                            else
                            {
                                return false;
                            }

                        }
                        count = count + 1;
                    }
                    if(count == room[i]->containers.size())
                    {
                        if(!strcmp(has, "no"))
                        {
                            if(info->printIdx)
                            {
                                std::cout << info->print << std::endl;
                            }
                            if(info->actionIdx)
                            {
                                for(int j = 0;  j < info->toDoActions.size(); j++)
                                {
                                    perform_action(info->toDoActions[j]);
                                }
                            }
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else if(!strcmp(obj, "Creature"))
                {
                    count = 0;
                    for (int j = 0;  j < room[i]->creatures.size(); j++)
                    {
                        if(!strcmp(room[i]->creatures[j]->name, object))
                        {
                            if(!strcmp(has, "yes"))
                            {
                                if(info->printIdx)
                                {
                                    std::cout << info->print << std::endl;
                                }
                                if(info->actionIdx)
                                {
                                    for(int k = 0;  k < info->toDoActions.size(); k++)
                                    {
                                        perform_action(info->toDoActions[j]);
                                    }
                                }
                                return true;
                            }
                            else
                            {
                                return false;
                            }

                        }
                        count = count + 1;
                    }
                    if(count == room[i]->creatures.size())
                    {
                        if(!strcmp(has, "no"))
                        {
                            if(info->printIdx)
                            {
                                std::cout << info->print << std::endl;
                            }
                            if(info->actionIdx)
                            {
                                for(int j = 0;  j < info->toDoActions.size(); j++)
                                {
                                    perform_action(info->toDoActions[j]);
                                }
                            }
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    else if (!strcmp(value, "Container"))
    {
        for(int i  = 0; i < container.size(); i++)
        {
            if(!strcmp(container[i]->name, owner))
            {
                count = 0;
                for(int j = 0; j < container[i]->items.size(); j++)
                {
                    if(!strcmp(container[i]->items[j]->name, object))
                    {
                        if(!strcmp(has, "yes"))
                        {
                            if(info->printIdx)
                            {
                                std::cout << info->print << std::endl;
                            }
                            if(info->actionIdx)
                            {
                                for(int k = 0;  k < info->toDoActions.size(); k++)
                                {
                                    perform_action(info->toDoActions[k]);
                                }
                            }
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    count += 1;
                }
                if(count == container[i]->items.size())
                {
                    if(!strcmp(has, "no"))
                    {
                        if(info->printIdx)
                        {
                            std::cout << info->print << std::endl;
                        }
                        if(info->actionIdx)
                        {
                            for(int j = 0;  j < info->toDoActions.size(); j++)
                            {
                                perform_action(info->toDoActions[j]);
                            }
                        }
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
}
void check_status(Trigger * info)
{
    string status = info->stat->status;
    string object = info->stat->object;

    string o_type = type_of(object);

    if(!strcmp(o_type, "Room"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!strcmp(room[i]->name, object))
            {
                if(!strcmp(room[i]->status, status))
                {
                    if(info->printIdx)
                    {
                        std::cout << info->print << std::endl;
                    }
                    if(info->actionIdx)
                    {
                        for(int j = 0;  j < info->toDoActions.size(); j++)
                        {
                            perform_action(info->toDoActions[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    else if (!strcmp(o_type, "Item"))
    {
        for(int i = 0; i < item.size(); i++)
        {
            if(!strcmp(item[i]->name, object))
            {
                if(!strcmp(item[i]->status, status))
                {
                    if(info->printIdx)
                    {
                        std::cout << info->print << std::endl;
                    }
                    if(info->actionIdx)
                    {
                        for(int j = 0;  j < info->toDoActions.size(); j++)
                        {
                            perform_action(info->toDoActions[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    else if(!strcmp(o_type, "Container"))
    {
        for(int i = 0;  i < container.size(); i++)
        {
            if(!strcmp(container[i]->name, object))
            {
                if(!strcmp(container[i]->status, status))
                {
                    if(info->printIdx)
                    {
                        std::cout << info->print << std::endl;
                    }
                    if(info->actionIdx)
                    {
                        for(int j = 0;  j < info->toDoActions.size(); j++)
                        {
                            perform_action(info->toDoActions[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    else if (!strcmp(o_type, "Creature"))
    {
        for(int i = 0; i < creature.size(); i++)
        {
            if(!strcmp(creature[i]->name, object))
            {
                if(!strcmp(creature[i]->status, status))
                {
                    if(info->printIdx)
                    {
                        std::cout << info->print << std::endl;
                    }
                    if(info->actionIdx)
                    {
                        for(int j = 0;  j < info->toDoActions.size(); j++)
                        {
                            perform_action(info->toDoActions[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}
void trigger_command(string input)
{
    bool temp = false;
    for(int i = 0; i < p1.current_room->triggers.size(); i++)
    {
        Trigger * trig = p1.current_room->trigger[i];
        if(trig->commandIdx && (!strcmp(trig->command, input)))
        {
            if(!strcmp(trig->type, "permanent") || (!strcmp(trig->type, "single") && trig->single == false))
            {
                if(trig->condition_count == 3)
                {
                    temp = check_for_ownership(trig);
                }
                else if(trig->condition_count == 2)
                {
                    temp = check_status(trig);
                }
                else if(temp == true)
                {
                    trig->single == true;
                }
            }
        }
    }
    temp = false;
    for(int i = 0 ; i < p1.current_room->container.size(); i++)
    {
        for(int j = 0; j < container.size(); j++)
        {
            if(!strcmp(p1.current_room->container[i]->name, container[j]->name)){

                for (int trig_num = 0;  trig_num < container[j]->triggers.size(); trig_num++) // loope for each potential triggers
                {
                    Trigger * trig = container[j]->triggers[trig_num];
                    if(trig->commandIdx && !strcmp(input, trig->command))
                    {
                        if(!strcmp(trig->type, "permanent") || (!strcmp(trig->type, "single") && trig->single == false))
                        {

                            if(trig->condition_count == 2)
                            {
                                temp = check_status(trig);
                            }
                            else if(trig->condition_count == 3)
                            {
                                temp = check_for_ownership(trig);
                            }
                            else if(temp == true)
                            {
                                trig->single = true;
                            }
                        }
                    }
                }
            }
        }
    }
    temp = false;
    for(int i = 0 ; i < p1.current_room->creatures.size(); i++)
    {
        for(int j = 0; j < creature.size(); j++)
        {
            if(!strcmp(p1.current_room->creatures[i]->name, creature[j]->name)){

                for (int trig_num = 0;  trig_num < creature[j]->triggers.size(); trig_num++) // loope for each potential triggers
                {
                    Trigger * trig = creature[j]->triggers[trig_num];
                    if(trig->commandIdx && !strcmp(input, trig->command))
                    {
                        if(!strcmp(trig->type, "permanent") || (!strcmp(trig->type, "single") && trig->single == false))
                        {
                            if(trig->condition_count == 2)
                            {
                                temp = check_status(trig);
                            }
                            else if(trig->condition_count == 3)
                            {
                                temp = check_for_ownership(trig);
                            }
                            else if(temp == true)
                            {
                                trig->single = true;
                            }
                        }
                    }
                }
            }
        }
    }
    temp = false;
    for(int i = 0 ; i < p1.inventory.size(); i++)
    {
        for(int j = 0; j < item.size(); j++)
        {
            if(!strcmp(p1.inventory[i], item[j]->name)){

                for (int trig_num = 0;  trig_num < item[j]->triggers.size(); trig_num++) // loope for each potential triggers
                {
                    Trigger * trig = item[j]->triggers[trig_num];
                    if(trig->commandIdx && !strcmp(input, trig->command))
                    {
                        if(!strcmp(trig->type, "permanent") || (!strcmp(trig->type, "single") && trig->single == false))
                        {
                            if(trig->condition_count == 3)
                            {
                                temp = check_for_ownership(trig);
                            }
                            else if(trig->condition_count == 2)
                            {
                                temp = check_status(trig);
                            }
                            else if(temp == true)
                            {
                                trig->single = true;
                            }
                        }
                    }
                }
            }
        }
    }
}



#endif
