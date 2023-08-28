#include <iostream>
#include <string>

//Desc: implement a linked list to store cities and their data

// 1. Add city record at the tail.
// 2. Add city record at the head.
// 3. Display the city with largest population.
// 4. Display all the city records.
// 5. Exit
using namespace std;

class LinkedList{
    private:
    class City{
        public:
        string name;
        int population;
        int income;

        //constructor
        City(){
            name = "";
            population = 0;
            income = 0;
        }
        City(string n, int p, int i){
        name = n;
        population = p;
        income = i; 
        }
        //toString to display info
        void toString(){
            cout << "Name: " << name << endl;
            cout << "Population: " << population << endl;
            cout << "Income: " << income << "\n" << endl;
        }
    };

    class Node{
        public:
        City city; //includes all the data about the city..
        Node *next; //pointer to next node
            //constructor
            Node(City c){
                city = c;
                next = nullptr;
            }    
    };

    public:
    Node *first;
    int size;

    LinkedList(){ //default constructor
        first = nullptr;
        size = 0;
    }

    void addAtTail(string n, int p, int i){
        City c = City(n, p, i);
        Node *node = new Node(c);
        if(first == nullptr){
            first = node;
        }//new node is first if list is empty
        else{
            Node *pointer = first;
            while(pointer->next != nullptr){
                pointer = pointer->next;
            }
            pointer->next = node;
        }//iterate through list until last node is found. assign new node to that one's next
        size ++;
    }

    void addAtHead(string n, int p, int i){
        City c = City(n, p, i);
        Node *node = new Node(c);
        if(first == nullptr){
            first = node;
        }//new node is first if list is empty
        else{
            node->next = first;
            first = node;
        }//shift the first node to be after the new node
        size++;
    }

    void displayLargest(){
        if(first == nullptr){
            cout << "No city records." << endl;
        }//if list is empty
        else{
            int max = 0;
            Node *largest = nullptr;
            Node *pointer = first;
            for(int i = 0; i < size; i ++){
                if(pointer->city.population > max){
                    max = pointer->city.population;
                    largest = pointer;
                }
                pointer = pointer->next;
            }//iterate through linkedlist and assign max population 
            largest->city.toString();//display node with largest population
        }
    }

    void displayAll(){
        if(first == nullptr){
            cout << "No city records." << endl;
        }//if list is empty
        else{
            Node *pointer = first;
            for (int i = 0; i < size; i++){
                pointer->city.toString();
                pointer = pointer->next;
            }//iterate through list and call toString on every node
        }
    }
}; //end of class LinkedList

//declare functions
void displayMenu(LinkedList *myList); //handles user inputted options
void printMenu(); //helper method to print menu after every option

int main(){
    LinkedList *myList = new LinkedList();
    displayMenu(myList);
    return 0;
}

void displayMenu(LinkedList *myList){
        string name;
        int population;
        int income;
        int option = 0;

        printMenu();

        while(option != 5){

            cin >> option;
            
            switch(option){
                case 1:
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter population: ";
                    cin >> population;
                    cout << "Enter income: ";
                    cin >> income; 
                    myList->addAtTail(name, population, income);
                    printMenu();
                    break;
                case 2: 
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter population: ";
                    cin >> population;
                    cout << "Enter income: ";
                    cin >> income;  
                    myList->addAtHead(name, population, income);
                    printMenu();
                    break;
                case 3:
                    myList->displayLargest();
                    printMenu();
                    break;
                case 4:
                    myList->displayAll();
                    printMenu();
                    break;
            }
        }
        return;
    }

void printMenu(){
        cout << "1. Add city record at the tail." << endl;
        cout << "2. Add city record at the head." << endl;
        cout << "3. Display the city with largest population." << endl;
        cout << "4. Display all the city records."<< endl;
        cout << "5. Exit\n" << endl;
}