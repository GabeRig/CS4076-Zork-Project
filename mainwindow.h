#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "zorkul.h"
#include "character.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    friend class Character;
    friend class Room;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void overencumberedTest();
    void allRoomItemsCollectedTest();
    void disableAllButtons();
    void addItemsToListWidget(vector<Item> item);
    string displayStamina();
    string displayHealth();
    void printCharacterStats();
    void endGameState(string message1, string message2);

private:
    Ui::MainWindow *ui;
    ZorkUL *zork = new ZorkUL();
    Character character = *new Character("Durgrax");
    bool putInInventory;
    void goRoom(string direction);
    void listItems(vector<Item> items, QString description);

private slots:
    void on_upButton_clicked();
    void on_rightButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_aButton_clicked();
    void on_bButton_clicked();
    void on_xButton_clicked();
    void on_yButton_clicked();
    void on_selectButton_clicked();
    void on_startButton_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
};

#endif // MAINWINDOW_H_
