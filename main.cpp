/**********************************************************
* Author: Joseph Song-Kim
* Assignment: A6
* Due Date: 2/9/2025
* Purpose: Demonstrate the use of a struct.
**********************************************************/

#include "playerType.h"

#include <string>
#include <iostream>
#include <iomanip>
// Library needed for file processing.
#include <fstream>

using namespace std;

void readFile(playerType []);

int lookUpPlayer(playerType [], string);

void editPlayer(playerType[], string);

void printPlayer(playerType);

void printTeam(playerType[]);

void writeFile(playerType []);

int main(){
        playerType array[10];

        readFile(array);

        char choice = '1';
        string namein;

        do{
        system("clear");

        cout << "**********************************************\n";
        cout << "* Assignment: A6 Structs                     *\n";
        cout << "*                                            *\n";
        cout << "* <1> Look up a player                       *\n";
        cout << "* <2> Edit a player                          *\n";
        cout << "* <3> Print team roster                      *\n";
        cout << "* <4> To quit                                *\n";
        cout << "**********************************************\n";
        cout << "* Choice (1-4):";
        cin >> choice;
        cout << "\n";

        if (choice != '1' && choice != '2' && choice != '3' && choice != '4'){
                do{
                        cout << "Please enter a valid choice (1-4):";
                        cin >> choice;
                        cout << "\n";
                        cin.ignore();
                } while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
        }

        switch (choice) {
                case '1':
                        {cout << "Search: ";
                        cin.ignore();
                        getline(cin, namein);

                        int index = lookUpPlayer(array, namein);
                        cout << left << setw(20) << "\nName ";
                        cout << left << setw(4) << "Pos ";
                        cout << left << setw(5) << "TDs ";
                        cout << left << setw(10) << "Catches ";
                        cout << left << setw(10) << "Pass Yds";
                        cout << left << setw(10) << "Recv Yds";
                        cout << left << setw(10) << "Rush Yds " << endl;

                        printPlayer(array[index]);

                        cout << "\nPress ENTER to continue..." << endl;
                        cin.get();}
                        break;
                case '2':
                        {cout << "Search: ";
                        cin.ignore();
                        getline(cin, namein);

                        editPlayer(array, namein);

                        cout << "Press ENTER to continue..." << endl;
                        cin.get();}
                        break;
                case '3':
                        {
                        printTeam(array);
                        cout << "Press ENTER to continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;}
        }

        } while (choice != '4');

        writeFile(array);

        return 0;
}

void readFile(playerType list[]){
        ifstream inData;
        inData.open("input.txt");
        int index = 0;

        while (index < 10 && getline(inData, list[index].name)){
                getline(inData, list[index].position);

                inData >> list[index].td;
                inData >> list[index].catches;
                inData >> list[index].pyds;
                inData >> list[index].ryds;
                inData >> list[index].rusyds;

                inData.ignore(5, '\n');;
                inData.clear();
                index++;
        }

        inData.close();
        return;
}

int lookUpPlayer(playerType list[], string namein){
        for (int i = 0; i < 10; i++){
                if (list[i].name.find(namein) != string::npos){
                        cout << "The player has been found. \n";
                        return i;
                }
        }
        cout << "The player has not been found. \n";
        return -1;
}

void editPlayer(playerType array[], string namein){
        int index2 = lookUpPlayer(array, namein);
        char choice2 = '1';

        if (index2 != -1){
        do{
        system("clear");
        cout << "**********************************************\n";
        cout << "* Edit Player                                *\n";
        cout << "*                                            *  " << "CURRENT VALUES \n";
        cout << "* <1> Edit Name                              *  " << array[index2].name << "\n";
        cout << "* <2> Edit Position                          *  " << array[index2].position << "\n";
        cout << "* <3> Edit Number of Touch Downs             *  " << array[index2].td << "\n";
        cout << "* <4> Edit Number of Catches                 *  " << array[index2].catches << "\n";
        cout << "* <5> Edit Number of Passing Yards           *  " << array[index2].pyds << "\n";
        cout << "* <6> Edit Number of Receiving Yards         *  " << array[index2].ryds << "\n";
        cout << "* <7> Edit Number of Rushing Yards           *  " << array[index2].rusyds << "\n";
        cout << "* <8> Return to Main Menu                    *\n";
        cout << "**********************************************\n";
        cout << "* Choice (1-8):";
        cin >> choice2;
        cout << "\n";

        if (choice2 != '1' && choice2 != '2' && choice2 != '3' && choice2 != '4' &&  choice2 != '5' && choice2 != '6' && choice2 != '7' && choice2 != '8'){
                do{
                        cout << "Please enter a valid choice (1-8):";
                        cin >> choice2;
                        cout << "\n";
                        cin.ignore();
                } while (choice2 != '1' && choice2 != '2' && choice2 != '3' && choice2 != '4' &&  choice2 != '5' && choice2 != '6' && choice2 != '7' && choice2 != '8');
        }


        switch (choice2){
                case '1':
                        cout << "New Name: ";
                        cin.ignore();
                        getline(cin, array[index2].name);
         break;
      case '2':
         cout << "New Position: ";
                        cin.ignore();
                        getline(cin, array[index2].position);
         break;
      case '3':
         cout << "New Number of Touchdowns: ";
                        cin.ignore();
                        cin >> array[index2].td;
                        if (std::cin.fail() == true){
                        do{
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Please enter a valid input:";
                        std::cin >> array[index2].td;
                        } while (std::cin.fail() == true);
                        }
         break;
      case '4':
         cout << "New Number of Catches: ";
                        cin.ignore();
                        cin >> array[index2].catches;
                        if (std::cin.fail() == true){
                        do{
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Please enter a valid input:";
                        std::cin >> array[index2].catches;
                        } while (std::cin.fail() == true);
                        }
         break;
      case '5':
         cout << "New Number of Passing Yards: ";
                        cin.ignore();
                        cin >> array[index2].pyds;
                        if (std::cin.fail() == true){
                        do{
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Please enter a valid input:";
                        std::cin >> array[index2].pyds;
                        } while (std::cin.fail() == true);
                        }
         break;
                case '6':
         cout << "New Number of Receiving Yards: ";
                        cin.ignore();
                        cin >> array[index2].ryds;
                        if (std::cin.fail() == true){
                        do{
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Please enter a valid input:";
                        std::cin >> array[index2].ryds;
                        } while (std::cin.fail() == true);
                        }
         break;
                case '7':
         cout << "New Number of Rushing Yards: ";
                        cin.ignore();
                        cin >> array[index2].rusyds;
                        if (std::cin.fail() == true){
                        do{
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Please enter a valid input:";
                        std::cin >> array[index2].rusyds;
                        } while (std::cin.fail() == true);
                        }
         break;
      default:
         cout << "\n" << setw(60) << "Please enter a number in the range 1-8." << "\n" << endl;
      }
        } while (choice2 != '8');
        }
}

void printPlayer(playerType player){
        cout << left << setw(20) << player.name;
        cout << left << setw(4) << player.position;
        cout << left << setw(5) << player.td;
        cout << left << setw(10) << player.catches;
        cout << left << setw(10) << player.pyds;
        cout << left << setw(10) << player.ryds;
        cout << left << setw(10) << player.rusyds << endl;
        return;
}

void printTeam(playerType list[]){
        cout << "Team consists of the following players:" << endl;
        cout << left << setw(20) << "Name ";
        cout << left << setw(4) << "Pos ";
        cout << left << setw(5) << "TDs ";
        cout << left << setw(10) << "Catches ";
        cout << left << setw(10) << "Pass Yds";
        cout << left << setw(10) << "Recv Yds";
        cout << left << setw(10) << "Rush Yds " << endl;
        for (int i = 0; i < 10; i++){
                printPlayer(list[i]);
        }
        cout << endl;
}

void writeFile(playerType list[]){
        ofstream file("output.txt");
        for (int i = 0; i < 10; i++){
                file << list[i].name << "\n";
                file << list[i].position << "\n";
                file << list[i].td << "\n";
                file << list[i].catches << "\n";
                file << list[i].pyds << "\n";
                file << list[i].ryds << "\n";
                file << list[i].rusyds << "\n";
        }
        file.close();
}
