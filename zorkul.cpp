#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#include "zorkul.h"

ZorkUL::ZorkUL() {
    createRooms();
    srand(time(0));
}

void ZorkUL::createRooms() {

    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("Hallway");
        a->addItem(new Item("Jacket", 1, 11));
    b = new Room("Bedroom");
        b->addItem(new Item("Pillow", 1, 11));
        b->addItem(new Item("Plushie", 2, 22));
    c = new Room("Front Pathway");
        c->addItem(new Item("Plant", 3, 33));
    d = new Room("Porch");
        d->addItem(new Item("Shoes", 4, 44));
    e = new Room("Study");
        e->addItem(new Item("Glasses", 4, 44));
    f = new Room("Utility");
        f->addItem(new Item("Vacuum", 4, 44));
        c->addItem(new Item("Brush", 4, 44));
    g = new Room("Bathroom");
        g->addItem(new Item("Soap", 4, 44));
        g->addItem(new Item("Towel", 4, 44));
        g->addItem(new Item("Roll of toilet paper", 4, 44));
    h = new Room("Kitchen");
        h->addItem(new Item("Knife", 4, 44));
        h->addItem(new Item("Spatula", 4, 44));
    i = new Room("Dining Room");
        i->addItem(new Item("Bowl", 4, 44));
        i->addItem(new Item("Bread", 4, 44));
        i->addItem(new Item("Spoon", 4, 44));
    j = new Room("Garden");
        j->addItem(new Item("Ball"));
        j->addItem(new Item("Shovel"));

//             (N,    E,    S,    W)
    a->setExits(f,    b,    d,    NULL);
    b->setExits(g,    NULL, NULL, a   );
    c->setExits(d,    NULL, NULL, NULL);
    d->setExits(a,    e,    c,    i   );
    e->setExits(NULL, NULL, NULL, d   );
    f->setExits(j,    NULL, a,    h   );
    g->setExits(NULL, NULL, b,    NULL);
    h->setExits(NULL, f,    i,    NULL);
    i->setExits(h,    d,    NULL, NULL);
    j->setExits(NULL, NULL, f,    NULL);

    rooms.push_back(*a);
    rooms.push_back(*b);
    rooms.push_back(*c);
    rooms.push_back(*d);
    rooms.push_back(*e);
    rooms.push_back(*f);
    rooms.push_back(*g);
    rooms.push_back(*h);
    rooms.push_back(*i);
    rooms.push_back(*j);

    currentRoom = c;
}

// COMMANDS
// Given a command, process (that is: execute) the command.
// If this command ends the ZorkUL game, true is returned, otherwise false is returned.

string ZorkUL::printWelcome() {
    return "Welcome to the game. \nPress info for help\n You find yourself on a worn path in front of a wooden door.\n" + currentRoom->longDescription();
}

string ZorkUL::printEnd() {
    return "end";
}

string ZorkUL::printHelp() {
    return "Press the directional buttons to travel, A button to pick up items, B button to ";
}

string ZorkUL::teleport() {
    currentRoom = &rooms.at((int) rand() % rooms.size());

    if (currentRoom == nullptr) {
        return "error teleporting";
    }
    else {
        return currentRoom->longDescription();
    }
}

string ZorkUL::map() {
    string output;
    output += "             [Garden]            ";
    output += "                |                ";
    output += "                |                ";
    output += "[Kitchen] - [Utility]  [Bathroom]";
    output += "    |           |           |    ";
    output += "    |           |           |    ";
    output += "[      ]    [Hallway] - [Bedroom]";
    output += "[Dining]        |                ";
    output += "[ Room ]        |                ";
    output += "[      ] --- [Porch] --- [Study] ";
    output += "                |                ";
    output += "                |                ";
    output += "         [Front Pathway]         ";
    return output;
    /*
               [j]
                |
                |
       [h] --- [f]     [g]
        |       |       |
        |       |       |
       [i]     [a] --- [b]
       [i]      |
       [i]      |
       [i] --- [d] --- [e]
                |
                |
               [c]
    */
}

string ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL) {
        return "There is no way foward in that direction.";
    } else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
string ZorkUL::viewItems() {
    return currentRoom->displayItems();
}
Room ZorkUL::getCurrentRoom() {
    return *currentRoom;
}



