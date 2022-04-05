#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#include "zorkul.h"
#include "room.h"

ZorkUL::ZorkUL() {
    createRooms();
    srand(time(0));
}

void ZorkUL::createRooms() {

    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;


    a = new Room("Hallway");
        a->addItem(new Item("Jacket"));
    b = new Room("Bedroom");
        b->addItem(new Item("Pillow"));
    c = new Room("Front Pathway");
        c->addItem(new Item("Shovel"));
    d = new Room("Porch");
        d->addItem(new Item("Hat"));
    e = new Room("Study");
        e->addItem(new Item("Book"));
    f = new Room("Utility Room");
        f->addItem(new Item("Brush"));
    g = new Room("Bathroom");
        g->addItem(new Item("Soap"));
    h = new Room("Kitchen");
        h->addItem(new Item("Knife"));
    i = new Room("Dining Room");
        i->addItem(new Item("Bowl"));
    j = new Room("Garden");
        j->addItem(new Item("Ball"));

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
    string output;
    output += "Welcome to Zork.\n\n";
    output += "Press - for help \n\n";
    output += "You find yourself on a worn path in front of a wooden door.\n";
    output += currentRoom->longDescription();
    return output;
}

string ZorkUL::printEnd() {
    return "end";
}

string ZorkUL::printHelp() {
    string output;
    output += "Dpad  Movement\n";
    output += "---------------------------\n";
    output += "A   Grab Item\n";
    output += "B   Drop Item\n";
    output += "X   Character\n";
    output += "Y   Map\n";
    output += "---------------------------\n";
    output += "+  Pause\n";
    output += "-    Help";
    return output;
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
    output += "          [ ]\n";
    output += "           |\n";
    output += "[ ] --- [ ] --- [ ]\n";
    output += " |        |        |\n";
    output += " |       [ ] --- [ ]\n";
    output += " |        |\n";
    output += "[ ] --- [ ] --- [ ]\n";
    output += "          |\n";
    output += "         [ ]";
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

                 [Garden]
                    |
                    |
    [Kitchen] - [Utility]  [Bathroom]
        |           |           |
        |           |           |
    [      ]    [Hallway] - [Bedroom]
    [Dining]        |
    [ Room ]        |
    [      ] --- [Porch] --- [Study]
                    |
                    |
             [Front Pathway]
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
