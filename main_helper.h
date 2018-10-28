#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

#include <vector>
#include <string>
#include "Room.h"
#include "Trigger.h"
#include "Creature.h"
#include "Item.h"
#include "Container.h"

void Game_over()
{
    std::cout  << "Game Over" << std::endl;
    std::cout << "Victory!" << std::endl;
    game_done = true;
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
void room_check(string input)
{
    int border_index;
    for(border_index = 0; border_index < p1.current_room->border_rooms.size(); border_index++)
    {
        if(p1.current_room->border_rooms[border_index]->direction == input)
        {

        }
    }
    if()
}
void parse_input(string input)
{
    if(input == "n" || input == "s" || input == "e" || input == "w")
    {
        room_check(input);
    }
    else if(strcmp(input, "take") == 0)
    else if(strcmp(input, "open") == 0)
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
    else if(strcmp(input, "n") == 0)

}





#endif
