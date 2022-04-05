#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

template <typename T>
void addItem(vector<T> v, T t) {
    v.push_back(t);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->textEdit_2->setTextColor(QColor("red"));
    ui->textEdit_3->setTextColor(QColor("red"));

    ui->textEdit->append(QString::fromStdString(zork->printWelcome() + "\n"));
    printCharacterStats();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_upButton_clicked() { // 1
    goRoom("north");
}
void MainWindow::on_rightButton_clicked() { // 5
    goRoom("east");
}
void MainWindow::on_downButton_clicked() { // 3
    goRoom("south");
}
void MainWindow::on_leftButton_clicked() { // 4
    goRoom("west");
}

void MainWindow::on_aButton_clicked() { // 6
    putInInventory = true;
    vector<Item> items = zork->getCurrentRoom().viewItems();
    listItems(items, "room");
}
void MainWindow::on_bButton_clicked() { // 2
    ui->textEdit->setText("Pressed B");
}
void MainWindow::on_xButton_clicked() { // 9
    putInInventory = false;
    //vector<Item> items = character.itemsInCharacter;
    vector<Item> items = character.viewItems();
    listItems(items, "character");
}
void MainWindow::on_yButton_clicked() { // 10
    ui->textEdit->setText("Pressed Y");
}

void MainWindow::on_startButton_clicked() { // 8
    ui->textEdit->setText("Pressed Start");

}
void MainWindow::on_selectButton_clicked() { // 7
    ui->textEdit->setText("Pressed Select");
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem*item) {
    string description = item->text().toStdString();
    Item i = *new Item(description);
    ui->listWidget->takeItem(ui->listWidget->row(item));
    //delete item;

    if (putInInventory) {
        Room r = zork->getCurrentRoom();
        Item m = r.findItem(i);
        //character.itemsInCharacter.push_back(m);
        addItem(character.itemsInCharacter, m);
        character.addItem(&m);
        r.removeItem(m);
        ui->textEdit->append(QString::fromStdString(description + " has been added to your inventory.\n"));
        overencumberedTest();
    }
    else {
        Item m = character.findItem(i);
        Room r = zork->getCurrentRoom();
        addItem(r.itemsInRoom, m);
        character.removeItem(m);
        ui->textEdit->append(QString::fromStdString(description + " has been removed from yuor inventory.\n"));
    }
}

void MainWindow::addItemsToListWidget(vector<Item> items) {
    ui->listWidget->clear();

    if (putInInventory) {
        if (!zork->getCurrentRoom().allItemsCollected()) {
            for (unsigned int i = 0; (unsigned int)i < (unsigned int)zork->getCurrentRoom().numberOfItems(); i++) {
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }
        else {
            ui->textEdit->append(QString::fromStdString("There are no items in the room."));
        }
    }
    else {
        if (!character.itemsInCharacter.empty()) {
            for (unsigned int i = 0; i < character.itemsInCharacter.size(); i++) {
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }
        else {
            ui->textEdit->append(QString::fromStdString("There are no items in " + character.shortDescription() + "'s inventory.\n"));
        }
    }
}

void MainWindow::endGameState(string message1, string message2){
    ui->upButton->setEnabled(false);
    ui->rightButton->setEnabled(false);
    ui->downButton->setEnabled(false);
    ui->leftButton->setEnabled(false);
    ui->aButton->setEnabled(false);
    ui->bButton->setEnabled(false);
    ui->xButton->setEnabled(false);
    ui->yButton->setEnabled(false);
    ui->selectButton->setEnabled(false);
    ui->startButton->setEnabled(false);

    ui->listWidget->setEnabled(false);

    ui->textEdit->setText(QString::fromStdString(character.description + " has " + message1 + ". You have " + message2 + " the game.\n"));

    character.stamina = 0;
    character.health = 0;
    ui->textEdit_2->setText(QString::fromStdString(displayHealth()));
    ui->textEdit_3->setText(QString::fromStdString(displayStamina()));
}

void MainWindow::overencumberedTest() {
    if (character.isOverencumbered(4.0)) {
        endGameState("been overencumberd", "lost");
    }
}

void MainWindow::goRoom(string direction) {
    if (character.health != 0 && character.stamina >= 0) {
        character.decrementStamina();
        printCharacterStats();

        if (direction == "teleport") {
            ui->textEdit->append(QString::fromStdString(zork->teleport() + "\n"));
        }
        else {
            ui->textEdit->append(QString::fromStdString(zork->go(direction) + "\n"));

            if (zork->getCurrentRoom().description == "j") {
                endGameState("entered the winning Room", "won");
            }
        }
    }
    else {
        endGameState("ran out of health", "lost");
    }
}

void MainWindow::listItems(vector<Item> items, QString description) {
    if (!items.empty()) {
        addItemsToListWidget(items);
    }
    else {
        ui->textEdit->append("No " + description + " items could be found.\n");
    }
}

string MainWindow::displayStamina() {
    string output = "Stamina:\n";

    for (int i = 0; i < character.stamina; i++) {
        output += "[] ";
    }

    return output;
}

string MainWindow::displayHealth() {
    string output = "Health:\n";

    for (int i = 0; i < character.getHealth(); i++) {
        output += "+ ";
    }

    return output;
}

void MainWindow::printCharacterStats() {
    if (!(character.health > 0)) {
        endGameState("run out of health", "lost");
    }
    else {
        ui->textEdit_2->setText(QString::fromStdString(displayHealth()));
        ui->textEdit_3->setText(QString::fromStdString(displayStamina()));
    }
}

