#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H


#include <cstdlib>
#include <vector>
#include <string>
#include "Room.h"
#include "Trigger.h"
#include "Creature.h"
#include "Item.h"
#include "Container.h"

bool game_done = false;

struct Player
{
    Room * current_room;
    vector<string> inventory;
};

Player p1;
std::vector<Room*> room;
std::vector<Container*> container;
std::vector<Item*> item;
std::vector<Creature*> creature;


void perform_action(string a);

// bool game_done = false;

string type_of(string obj)
{
    for(int i = 0 ; i < room.size(); i++)
    {
        if(!room[i]->name.compare(obj))
        {
            string r = "Room";
            return r;
        }
    }
    for(int i = 0 ; i < item.size(); i++)
    {
        if(!item[i]->name.compare(obj))
        {
            string i = "Item";
            return i;
        }
    }
    for(int i = 0 ; i < container.size(); i++)
    {
        if(!container[i]->name.compare(obj))
        {
            string c = "Container";
            return c;
        }
    }
    for(int i = 0 ; i < creature.size(); i++)
    {
        if(!creature[i]->name.compare(obj))
        {
            string cr = "Creature";
            return cr;
        }
    }
    return "\0";
}

void Add(string action)
{
    std::size_t index = action.find(" to ");
    string obj = action.substr(0, index);
    string location = action.substr(index+4);

    string type_obj = type_of(obj);
    // string type_location = type_of(location);
    if(!(type_obj.compare( "Container")))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!(room[i]->name.compare(location)))
            {
                room[i]->containers.push_back(obj);
                return;
            }
        }
    }
    if(!type_obj.compare("Item"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!room[i]->name.compare(location))
            {
                room[i]->items.push_back(obj);
                return;
            }
        }
        for(int i = 0; i < container.size(); i++)
        {
            if(!container[i]->name.compare(location))
            {
                container[i]->items.push_back(obj);
                return;
            }
        }
    }
    if(!type_obj.compare( "Creature"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!room[i]->name.compare(location))
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

    if(!type_obj.compare("Room"))
    {
        for(int i = 0; i < p1.current_room->border_rooms.size(); i++)
        {
            if(p1.current_room->border_rooms[i]->Name == action)
            {
                p1.current_room->border_rooms.erase(p1.current_room->border_rooms.begin()+i);
                return;
            }
        }
    }
    else if(!type_obj.compare("Item"))
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
    else if(!type_obj.compare( "Container"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            for(int j = 0; j < room[i]->containers.size(); j++)
            {
                if(room[i]->containers[j] == action)
                {
                    room[i]->containers.erase(room[i]->containers.begin()+j);
                    return;
                }
            }
        }
    }
    else if(!(type_obj.compare( "Creature")))
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

    if(!type_obj.compare("Room"))
    {
        for(int i  = 0; i < room.size(); i++)
        {
            if(!(room[i]->name.compare(obj)))
            {
                room[i]->status = status;
                return;
            }
        }
    }
    if(!type_obj.compare("Item"))
    {
        for(int i  = 0; i < item.size(); i++)
        {
            if(!item[i]->name.compare(obj))
            {
                item[i]->status = status;
                return;
            }
        }
    }
    if(!type_obj.compare("Creature"))
    {
        for(int i  = 0; i < creature.size(); i++)
        {
            if(!creature[i]->name.compare(obj))
            {
                creature[i]->status = status;
                return;
            }
        }
    }
    if(!type_obj.compare("Container"))
    {
        for(int i  = 0; i < container.size(); i++)
        {
            if(!container[i]->name.compare(obj))
            {
                container[i]->status = status;
                return;
            }
        }
    }

}
void Game_over()
{
    std::cout  << "Game Over" << std::endl;
    std::cout << "Victory!" << std::endl;
    game_done = true;
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
            std::cout << p1.inventory[i] << ", ";
        }
        std::cout << p1.inventory[p1.inventory.size() - 1] << std::endl;
    }
}
void open_container(string con)
{
    int i;
    // std::cout << con << std::endl;
    // std::cout << p1.current_room->containers.size() << std::endl;
    for(i = 0; i < p1.current_room->containers.size(); i++)
    {
        if(!p1.current_room->containers[i].compare(con))
        {

            for(int j = 0; j < container.size(); j++)
            {
                if(!container[j]->name.compare(con))
                {

                    // std::cout << container[j]->name << " ";
                    // std::cout <<  container[j]->items.size() << std::endl;
                    if(container[j]->items.size() == 0)
                    {
                        std::cout << con << " is empty." << std::endl;
                        return;
                    }
                    else
                    {
                        std::cout <<  con << " contains ";
                        if(container[j]->items.size() == 1)
                        {
                            std::cout << container[j]->items[0] << std::endl;
                            p1.current_room->items.push_back(container[j]->items[0]);
                            return;
                        }
                        for(int k = 0; k < container[j]->items.size() - 1 ; k++)
                        {
                            std::cout << container[j]->items[k] << ", " << std::endl;
                            p1.current_room->items.push_back(container[j]->items[k]);
                        }
                        std::cout << container[j]->items[container[j]->items.size()-1]<< std::endl;
                        p1.current_room->items.push_back(container[j]->items[container[j]->items.size()-1]);
                        return;
                    }
                }
            }
        }
    }
    if(i == p1.current_room->containers.size())
    {
        std::cout << "No " << con << " in this room" << std::endl;
        return;
    }
}
void room_check(string input)
{
    int border_index;
    int count = 0;

    if(!input.compare("n"))
    {
        input = "north";
    }
    else if (!input.compare("s"))
    {
        input = "south";
    }
    else if (!input.compare("e"))
    {
        input = "east";
    }
    else if(!input.compare("w"))
    {
        input = "west";
    }
    for(border_index = 0; border_index < p1.current_room->border_rooms.size(); border_index++)
    {
        if(!p1.current_room->border_rooms[border_index]->Direction.compare(input))
        {
            for(int i = 0; i < room.size(); i++)
            {
                if(!room[i]->name.compare(p1.current_room->border_rooms[border_index]->Name))
                {
                    p1.current_room = room[i];
                    std::cout << p1.current_room->description << std::endl;
                    return;
                }
            }
        }
        count += 1;
    }
    if(count == border_index)
    {
        std::cout << "Can't go that way" << std::endl;
        return;
    }
    else
    {
        std::cout << p1.current_room->description << std::endl;
        return;
    }
}
void take(string Item)
{
    int i;
    // std::cout << Item << std::endl;
    for(i = 0; i  < p1.current_room->items.size(); i++)
    {
        if(!(p1.current_room->items[i].compare(Item)))
        {
            std::cout << "Item " << Item << " added to inventory" << std::endl;
            p1.inventory.push_back(p1.current_room->items[i]);
            return;
        }
    }
    if(i == p1.current_room->items.size())
    {
        std::cout << Item << " not in room." << std::endl;
        return;
    }
}
void turn_on(string Item)
{
    int i;
    for(i = 0; i < p1.inventory.size(); i++)
    {
        if(!p1.inventory[i].compare(Item))
        {
            for(int j = 0; j < item.size(); j++)
            {
                if(!Item.compare(item[j]->name))
                {
                    cout << "You activate the " << Item << std::endl;
                    for(int k = 0; k < item[j]->turnOn.toDoActions.size(); k++)
                    {
                        perform_action(item[j]->turnOn.toDoActions[k]);
                    }
                }
            }
        }
    }
    if(i == p1.inventory.size())
    {
        std::cout << Item << " not in inventory." << std::endl;
        return;
    }
}

void drop(string input)
{
    int i;
    // int count = 0;
    for(i = 0; i < p1.inventory.size(); i++)
    {
        if(!p1.inventory[i].compare(input))
        {
            break;
        }
        // count += 1;
    }
    if(p1.inventory.size() == i)
    {
        std::cout << input << " not in inventory." << std::endl;
        return;
    }
    p1.current_room->items.push_back(p1.inventory[i]);
    p1.inventory.erase(p1.inventory.begin()+i);
    std::cout << input << " dropped." << std::endl;
    return;
}
void put(string input)
{
    std::size_t index = input.find(" in ");
    string item = input.substr(0, index);
    string loc = input.substr(index+4);
    int a;
    for(a = 0; a < p1.inventory.size(); a++)
    {
        if(!item.compare(p1.inventory[a]))
        {
            break;
        }
    }
    if(a == p1.inventory.size())
    {
        std::cout << "Item not in inventory" << std::endl;
        return;
    }

    for(int i = 0; i < p1.current_room->containers.size(); i++)
    {
        if(!p1.current_room->containers[i].compare(loc))
        {
            for(int j = 0;  j < container.size(); j++)
            {
                if(!container[j]->name.compare(loc))
                {
                    for(int k = 0; k < p1.inventory.size(); k++)
                    {
                        if(container[j]->accept.size() > 0)
                        {
                            for(int b = 0;  b < container[j]->accept.size(); b++)
                            {
                                if(!container[j]->accept[b].compare(item))
                                {
                                    container[j]->items.push_back(p1.inventory[k]);
                                    // p1.inventory.erase(p1.inventory.begin()+k);
                                    p1.inventory.erase(p1.inventory.begin() + k);
                                }
                            }
                        }
                        else if(!p1.inventory[k].compare(item))
                        {
                            std::cout << "Item " << p1.inventory[k] << " added to " << container[j]->name << std::endl;
                            container[j]->items.push_back(p1.inventory[k]);
                            // p1.inventory.erase(p1.inventory.begin()+k);
                            p1.inventory.erase(p1.inventory.begin() + k);
                        }
                    }
                }
            }
        }
    }

}
void read_item(string Item)
{
    int i = 0;
    for(i = 0;  i < p1.inventory.size(); i++)
    {
        if(!p1.inventory[i].compare(Item))
        {
            for(int j = 0; j < item.size(); j++)
            {
                if(!Item.compare(item[j]->name))
                {
                    if(item[j]->Ywrite)
                    {
                        std::cout << item[j]->writing << std::endl;
                        return;
                    }
                    else
                    {
                        std::cout << "Nothing written" << std::endl;
                        return;
                    }
                }
            }
        }
    }
    if(i == p1.inventory.size())
    {
        std::cout << "Item not in inventory"  << std::endl;
        return;
    }
}
bool check_status(Trigger * info)
{
    string status = info->stat->status;
    string object = info->stat->object;

    string o_type = type_of(object);

    // std::cout << o_type << std::endl;
    if(!o_type.compare("Room"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!room[i]->name.compare(object))
            {
                if(!room[i]->status.compare(status))
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
    else if (!o_type.compare("Item"))
    {
        for(int i = 0; i < item.size(); i++)
        {
            if(!item[i]->name.compare(object))
            {
                if(!item[i]->status.compare(status))
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
    else if(!o_type.compare("Container"))
    {
        for(int i = 0;  i < container.size(); i++)
        {
            if(!container[i]->name.compare(object))
            {
                if(!container[i]->status.compare(status))
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
    else if(!o_type.compare("Creature"))
    {
        for(int i = 0; i < creature.size(); i++)
        {
            if(!creature[i]->name.compare(object))
            {
                if(!creature[i]->status.compare(status))
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
void attack(string input)
{
    std::size_t index = input.find(" with ");
    string c = input.substr(0, index);
    string weapon = input.substr(index+6);
    // std::cout << c << std::endl;
    // std::cout << weapon << std::endl;
    int a;
    for(a = 0;  a < p1.inventory.size(); a++)
    {
        if(!weapon.compare(p1.inventory[a]))
        {
            break;
        }
    }
    if(a == p1.inventory.size())
    {
        std::cout <<"Error: Item not in inventory" << std::endl;
        return;
    }
    int i;
    // std::cout << p1.current_room->creatures.size() << std::endl;
    for(i = 0;  i < p1.current_room->creatures.size(); i++)
    {
        // std::cout << p1.current_room->creatures[i] << std::endl;
        if(!p1.current_room->creatures[i].compare(c))
        {
            for(int j = 0; j < creature.size(); j++)
            {
                if(!creature[j]->name.compare(c))
                {
                    std::cout << "You assault " << c << " with the " << weapon << std::endl;
                    int k;

                    for(k = 0; k < creature[j]->vulnerability.size(); k++)
                    {
                        if(!creature[j]->vulnerability[k].compare(weapon))
                        {
                            if(creature[j]->attackF)
                            {
                                if(creature[j]->aprint)
                                {
                                    std::cout << creature[j]->print << std::endl;
                                }
                                for(int g = 0; g < creature[j]->toDoActions.size(); g++)
                                {
                                    perform_action(creature[j]->toDoActions[g]);
                                }
                                return;
                            }
                        }
                    }
                    // if(k == creature[j]->vulnerability.size())
                    // {
                    //     std::cout << "Item not effective." << std::endl;
                    //     return;
                    // }
                }
            }
        }
    }
    // if(i == p1.current_room->creatures.size())
    // {
    //     std::cout << "No such creature in Room" << std::endl;
    //     return;
    // }
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
            // std::cout << input << std::endl;
            take(input.erase(0,5));
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
            input.erase(0,5);
            read_item(input);
        }
    }
    else if(input.compare("open exit") == 0)
    {
        if(p1.current_room->type == "exit")
        {
            Game_over();
        }
        else
        {
            std::cout << "Room not exit" << std::endl;
            return;
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
            open_container(input.erase(0,5));
        }
    }
    else if(input.compare("i") == 0)
    {
        print_inventory();
    }
    else if(input.find("put") != string::npos)
    {
        if(input.size() > 3)
        {
            put(input.erase(0, 4));
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }
    else if(input.find("drop") != string::npos)
    {
        drop(input.erase(0, 5));
    }
    else if(input.find("turn on") != string::npos)
    {
        turn_on(input.erase(0,9));
    }
    else if(input.find("attack") != string::npos)
    {
        // input÷.erase(0, 7)
        attack(input.erase(0, 7));
    }
}
void perform_action(string a)
{
    if(a.find("Game Over") != string::npos)
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
    parse_input(a);
}
bool check_for_ownership(Trigger * info)
{
    string owner = info->own->owner;
    string has = info->own->has;
    string object = info->own->object;
    int count  = 0;
    if(!owner.compare("inventory"))
    {
        for(int i = 0; i < p1.inventory.size(); i++)
        {
            if(!p1.inventory[i].compare(object))
            {
                if(!has.compare("yes"))
                {
                    if(info->printIdx)
                    {
                        std::cout << info->print << std::endl;
                        // info->printIdx = false;
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
            if(!has.compare("no"))
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
    if(!value.compare("Room"))
    {
        for(int i = 0; i < room.size(); i++)
        {
            if(!room[i]->name.compare(owner))
            {
                if(!obj.compare("Item"))
                {
                    count = 0;
                    for (int j = 0;  j < room[i]->items.size(); j++)
                    {
                        if(!room[i]->items[j].compare(object))
                        {
                            if(!has.compare("yes"))
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
                        if(!has.compare( "no"))
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
                else if(!obj.compare("Container"))
                {
                    count = 0;
                    for (int j = 0;  j < room[i]->containers.size(); j++)
                    {
                        if(!room[i]->containers[j].compare(object))
                        {
                            if(!has.compare("yes"))
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
                        if(!has.compare("no"))
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
                else if(!obj.compare("Creature"))
                {
                    count = 0;
                    for (int j = 0;  j < room[i]->creatures.size(); j++)
                    {
                        if(!room[i]->creatures[j].compare(object))
                        {
                            if(!has.compare("yes"))
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
                        if(!has.compare("no"))
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
    else if (!value.compare("Container"))
    {
        for(int i  = 0; i < container.size(); i++)
        {
            if(!container[i]->name.compare(owner))
            {
                count = 0;
                for(int j = 0; j < container[i]->items.size(); j++)
                {
                    if(!container[i]->items[j].compare(object))
                    {
                        if(!has.compare( "yes"))
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
                    if(!has.compare("no"))
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
    return false;
}
bool trigger_command(string input)
{
    bool temp1 = false;
    for(int i = 0; i < p1.current_room->triggers.size(); i++)
    {
        Trigger * trig = p1.current_room->triggers[i];
        if(trig->commandIdx && (!trig->command.compare(input)))
        {
            if(!trig->type.compare("permanent") || (!trig->type.compare("single") && trig->single == false))
            {
                if(trig->condition_count == 3)
                {
                    temp1 = check_for_ownership(trig);
                }
                else if(trig->condition_count == 2)
                {
                    temp1 = check_status(trig);
                }
                else if(temp1 == true)
                {
                    trig->single = true;
                }
            }
        }
    }
    bool temp2 = false;
    for(int i = 0 ; i < p1.current_room->containers.size(); i++)
    {
        for(int j = 0; j < container.size(); j++)
        {
            if(!p1.current_room->containers[i].compare(container[j]->name))
            {

                for (int trig_num = 0;  trig_num < container[j]->trigger.size(); trig_num++) // loope for each potential triggers
                {
                    Trigger * trig = container[j]->trigger[trig_num];
                    if(trig->commandIdx && !input.compare(trig->command))
                    {
                        if(!trig->type.compare("permanent") || (!trig->type.compare("single") && trig->single == false))
                        {

                            if(trig->condition_count == 2)
                            {
                                temp2 = check_status(trig);
                            }
                            else if(trig->condition_count == 3)
                            {
                                temp2 = check_for_ownership(trig);
                            }
                            else if(temp2 == true)
                            {
                                trig->single = true;
                            }
                        }
                    }
                }
            }
        }
    }
    bool temp3 = false;
    for(int i = 0 ; i < p1.current_room->creatures.size(); i++)
    {
        for(int j = 0; j < creature.size(); j++)
        {
            if(!p1.current_room->creatures[i].compare(creature[j]->name))
            {

                for (int trig_num = 0;  trig_num < creature[j]->trigger.size(); trig_num++) // loope for each potential triggers
                {
                    Trigger * trig = creature[j]->trigger[trig_num];
                    if(trig->commandIdx && !input.compare(trig->command))
                    {
                        if(!trig->type.compare("permanent") || (!trig->type.compare("single") && trig->single == false))
                        {
                            if(trig->condition_count == 2)
                            {
                                temp3 = check_status(trig);
                            }
                            else if(trig->condition_count == 3)
                            {
                                temp3 = check_for_ownership(trig);
                            }
                            else if(temp3 == true)
                            {
                                trig->single = true;
                            }
                        }
                    }
                }
            }
        }
    }
    bool temp4 = false;
    for(int i = 0 ; i < p1.inventory.size(); i++)
    {
        for(int j = 0; j < item.size(); j++)
        {
            if(!p1.inventory[i].compare(item[j]->name)){

                for (int trig_num = 0;  trig_num < item[j]->trigger.size(); trig_num++) // loope for each potential triggers
                {
                    Trigger * trig = item[j]->trigger[trig_num];
                    if(trig->commandIdx && !input.compare(trig->command))
                    {
                        if(!trig->type.compare("permanent") || (!trig->type.compare("single") && trig->single == false))
                        {
                            if(trig->condition_count == 3)
                            {
                                temp4 = check_for_ownership(trig);
                            }
                            else if(trig->condition_count == 2)
                            {
                                temp4 = check_status(trig);
                            }
                            else if(temp4 == true)
                            {
                                trig->single = true;
                            }
                        }
                    }
                }
            }
        }
    }
    bool fo = temp1 || temp2 || temp3 || temp4;
    return fo;
}
bool check_non_command_triggers()
{
    bool CM_trigRoom = false;
    for(int i = 0; i < p1.current_room->triggers.size(); i++)
    {
        Trigger * trig = p1.current_room->triggers[i];
        if(trig->commandIdx == 0)
        {
            if(!trig->type.compare("permanent") || (!trig->type.compare("single") && trig->single == false))
            {
                if(trig->condition_count == 3)
                {
                    CM_trigRoom = check_for_ownership(trig);
                }
                else if(trig->condition_count == 2)
                {
                    CM_trigRoom = check_status(trig);
                }
                if(CM_trigRoom == true)
                {
                    trig->single = true;
                }
            }
        }
    }
    bool CM_trigItem = false;

    for(int i = 0 ; i < p1.current_room->items.size(); i++)
    {
        for(int j = 0; j < item.size(); j++)
        {
            if(!p1.current_room->items[i].compare(item[j]->name))
            {
                for(int a = 0; a < item[j]->trigger.size(); a++)
                {
                    Trigger * trig = item[j]->trigger[a];
                    if(trig->commandIdx == 0)
                    {
                        if(!trig->type.compare("permanent") || (!trig->type.compare("single") && trig->single == false))
                        {
                            if(trig->condition_count == 3)
                            {
                                CM_trigItem = check_for_ownership(trig);
                            }
                            else if(trig->condition_count == 2)
                            {
                                CM_trigItem = check_status(trig);
                            }
                            if(CM_trigItem == true)
                            {
                                trig->single = true;
                            }
                        }
                    }
                }
            }
        }
    }
    bool CM_trigcreature = false;

    for(int i = 0 ; i < p1.current_room->creatures.size(); i++)
    {
        for(int j = 0; j < creature.size(); j++)
        {

            if(!p1.current_room->creatures[i].compare(creature[j]->name))
            {
                for(int a = 0; a < creature[j]->trigger.size(); a++)
                {
                    Trigger * trig = creature[j]->trigger[a];
                    if(trig->commandIdx == 0)
                    {
                        if(!trig->type.compare("permanent") || (!trig->type.compare("single") && trig->single == false))
                        {
                            if(trig->condition_count == 3)
                            {
                                CM_trigcreature = check_for_ownership(trig);
                            }
                            else if(trig->condition_count == 2)
                            {
                                CM_trigcreature = check_status(trig);
                            }
                            if(CM_trigcreature== true)
                            {
                                trig->single = true;
                            }
                        }
                    }
                }
            }
        }
    }
    bool CM_trigcontainer = false;
    for(int i = 0 ; i < p1.current_room->containers.size(); i++)
    {
        for(int j = 0; j < container.size(); j++)
        {
            if(!p1.current_room->containers[i].compare(container[j]->name))
            {
                for(int a = 0; a < container[j]->trigger.size(); a++)
                {
                    Trigger * trig = container[j]->trigger[a];
                    if(trig->commandIdx == 0)
                    {
                        if(!trig->type.compare("permanent") || (!trig->type.compare("single") && trig->single == false))
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
                                trig->single = true;
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


#endif
