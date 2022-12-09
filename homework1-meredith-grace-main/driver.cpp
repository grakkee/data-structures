//Grace Meredith
//CS 302: Homework 1 "Lists"
//17 Feb 2021

#include <iostream>
#include<string>
using namespace std;

#include "linkedList.h"

int getmenuchoice();
void addItem(LinkedList<string>& myList);
void removeItem(LinkedList<string>& myList);
void countItems(LinkedList<string>& myList);
void displayItems(LinkedList<string>& myList);

int main(){
    LinkedList<string> myList; //create object
    int menuChoice;

    do{
        cout << endl;
        menuChoice = getmenuchoice();

        if(menuChoice == 1){ //add item
        addItem(myList);

        }

        else if(menuChoice == 2){ //remove item
        removeItem(myList);

        }

        else if(menuChoice == 3){ //item count
        countItems(myList);

        }

        else if(menuChoice == 4){ //display items 
        displayItems(myList);

        }

        else if(menuChoice != 0){
            cout << "Not a valid option, please try again" << endl;
        }
    }
    while(menuChoice != 0);
    
    return 0;
}

int getmenuchoice(){
    int choice;
    cout << "Welcome! What would you like to do?" << endl;
    cout << "1) add an item to a list" << endl;
    cout << "2) delete an item from a list" << endl;
    cout << "3) check number of items in your list" << endl;
    cout << "4) display the items in your list" << endl;
    cout << "0) exit" << endl;

    cin >> choice; 
    return choice; 
}

void addItem(LinkedList<string>& myList){
    string newItem; 
    int newPosition; 
    bool successful; 
    
    bool empty = myList.isEmpty(); //test for all cases
    if(empty){
        newPosition = 1; 
        cout << endl << "Your list is currently empty, let's add the very first item!" << endl << "Please enter the name of your item" << endl; 
        cin >> newItem; 
        successful = myList.insert(newPosition, newItem);

        if(successful){
            cout << endl << "Item was add successfully!" << endl;
        }
        else{
            cout << endl << "Item failed to be added :(" << endl;
        }

    }
    else{
        displayItems(myList);
        int itemCount = myList.getLength();

        if(itemCount == 1){
            cout << endl << "There is currently " << itemCount << " item in your list." << endl << "Where in your list would you like to add your new item? Please enter the position number" << endl; 
        }
        else{
        cout << endl << "There are currently " << itemCount << " items in your list." << endl << "Where in your list would you like your new item to be added? Please enter the position number." << endl;

        }
        cin >> newPosition; 
        cout << endl << "Perfect! Now, please enter the name of your new item. " << endl;
        cin >> newItem; 
        successful = myList.insert(newPosition, newItem);

        if(successful){
            cout << endl << "Item was add successfully!" << endl;
        }
        else{
            cout << endl << "Item failed to be added :(" << endl;
        }

    }
}

void removeItem(LinkedList<string>& myList){
    bool empty = myList.isEmpty();
    int position;

    if(empty){
        cout << endl << "Your list is currently empty. There is no items that can be deleted." << endl;
    }
    else{
        displayItems(myList);
        cout << endl << "Please select the position number of the item you would like to delete." << endl;
        cin >> position; 
        bool successful = myList.remove(position);

        if(successful){
            cout << endl << "Item was deleted successfully!" << endl;
        }
        else{
            cout << endl << "failed to delete item. :(" << endl;
        }

    }
}

void countItems(LinkedList<string>& myList){
    int itemCount;
    bool empty = myList.isEmpty();

    if(empty){
        cout << endl <<"Your list is empty. Try adding an item!" << endl;
    }
    else{
        itemCount = myList.getLength();

        if(itemCount == 1){
            cout << endl << "There is currently " << itemCount << " item in your list" << endl;
        }
        else{
        cout << endl << "There are currently " << itemCount << " items in your list" << endl; 

        }
    }
}

void displayItems(LinkedList<string>& myList){
    bool empty = myList.isEmpty();
    if(empty){
        cout << endl << "Your list is currently empty, and there is nothing to display. Try adding an item!" << endl;
    }
    else{
        int itemCount = myList.getLength();
        for(int position = 1; position <= itemCount; position++){
            string curItem = myList.getEntry(position);
            cout << endl << position << "). " << curItem; 
        }
        cout << endl;
    }

}
