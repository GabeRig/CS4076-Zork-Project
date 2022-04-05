#include "character.h"
#include <string>

Character::Character(string description) {
    itemsInCharacter.empty();
    this->description = description;
    stamina = 5;
    health = 5;
}

void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    carriedWeight += item->getWeight();
}

void Character::addItem(Item &item) {
    itemsInCharacter.push_back(item);
    carriedWeight += item.getWeight();
}

vector<Item> Character::viewItems() {
    return itemsInCharacter;
}

string Character::shortDescription() {
    return this->description;
}

string Character::longDescription() {
    string output;

    output += this->description;
    output += "\n\n   o";
    output += "\n   T";
    output += "\n   ^\n";

    if (itemsInCharacter.empty()) {
        output += "\nYou are carrying no items.";
    }
    else {
        output += "\nItem List:\n";

        for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++) {
            output += "\t" + (*i).getLongDescription() + "\n";
        }
    }

    return output;
}

Item Character::findItem(Item item) {
    for (unsigned int i = 0; i < (unsigned int)itemsInCharacter.size(); i++) {
        if (itemsInCharacter[i] == item) {
            return itemsInCharacter[i];
        }
    }
}

int Character::findItemPos(Item item) {
    for (unsigned int i = 0; i < (unsigned int)itemsInCharacter.size(); i++) {
        if (itemsInCharacter[i] == item) {
            return i;
        }
    }
}

string Character::viewCharacterInfo() {
    string output = "";
    output += longDescription();
    output += "\nCarried Weight: " + to_string(carriedWeight) + "g.";
    return output;
}

void Character::removeItem(Item item) {
    itemsInCharacter.erase(itemsInCharacter.begin() + findItemPos(item));
}

bool Character::isOverencumbered(float maxWeight) {
    if (carriedWeight > maxWeight) {
        return true;
    }
    else {
        return false;
    }
}

int Character::getStamina() {
    return stamina;
}

void Character::setStamina(int stamina) {
    this->stamina = stamina;
}

void Character::decrementStamina() {
    stamina--;

    if (stamina < 0 && health > 1) {
        setStamina(5);
        decrementHealth();
    }
}

int Character::getHealth() {
    return health;
}

void Character::setHealth(int health) {
    this->health = health;
}

void Character::decrementHealth() {
    health--;
}
