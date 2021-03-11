#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string.h>
#include <string>
#include <map>

#include "h/being.h"
#include "h/creature.h"
#include "h/eldritchHorror.h"
#include "h/investigator.h"
#include "h/person.h"

using namespace std;

void createRoleSpecies(map<string, Being*> roles)
{
    std::ofstream filestream;
    filestream.open("roaster.txt", std::ios_base::app);
    string name;
    string type;
    int life;         //change to string to allow "5-7"?
    int strength;     //change to string to allow "5-7"?v
    int intelligence; //change to string to allow "5-7"?
    bool natural;
    int disquiet;
    int traumatism;
    string gender;
    int fear;
    int terror;

    cout << "Name: ";
    cin >> name;
    cout << "Type: ";
    cin >> type;
    cout << "Life: ";
    cin >> life;
    cout << "Strength: ";
    cin >> strength;
    cout << "Intelligence: ";
    cin >> intelligence;
    
    filestream << "\n\n"
               << "Name:" << name << "\n"
               << "Type:" << type << "\n"
               << "Life:" << life << "\n"
               << "Strength:" << strength << "\n"
               << "Intelligence:" << intelligence << "\n";

    if (type == "Creature"){
        cout << "Natural: ";
        cin >> natural;
        cout << "Disquiet: ";
        cin >> disquiet;
        filestream << "Natural: " << natural << "\n";
        filestream << "Disquite: " << disquiet;

        roles[name] = new Creature(name, life, strength, intelligence, natural, disquiet);
        
        for(auto it = roles.cbegin(); it != roles.cend(); ++it)
        {
            cout << it->first 
                << " " << it->second->life 
                << " " << it->second->strength 
                << " " << it->second->intelligence << "\n";
        }
    }

    else if (type == "Eldritch horror"){
        natural = 0;
        disquiet = 10;
        cout << "Traumatism: ";
        cin >> traumatism;
        filestream << "Natural: " << natural << "\n";
        filestream << "Disquite: " << disquiet << "\n";
        filestream << "Traumatism: " << traumatism;
    }
    
    else if (type == "Person" || type == "Investigator"){
        cout << "Gender: ";
        cin >> gender;
        cout << "Fear: ";
        cin >> fear;
        filestream << "Gender:" << gender << "\n"
                   << "Fear:" << fear << "\n";
        if (type == "Investigator"){
            cout << "Terror: ";
            cin >> terror;
            filestream << "Terror:" << terror;
        }
        
    }
}

void getListRoleSpecies(map<string, Being*> roles)
{
    map<string, Being*>::iterator it;
    for (it = roles.begin(); it != roles.end(); ++it){
        cout << it->first;
    }
}

void removeRoleSpecies(map<string, Being*> roles)
{
    map<string, Being*>::iterator it;
    cout << "Which role or species do you want to erase?" << endl;
    
    for (it = roles.begin(); it != roles.end(); ++it){
        for (int i = 0; i < roles.size(); i++){
            cout << i << ":\n" << it->second;
        }
    }
}

int main()
{   string lineString;
    string fileString;
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    int chosenNumber;
    map<string, Being*> roles;

    ifstream fin;
    fin.open("roaster.txt");

    string kind;
    string name;
    string type;
    int life;
    int strength;
    int intelligence;
    bool natural = 0;
    int disquiet;
    string gender;
    int fear;
    int terror;

    while(!fin.eof()){
        fin >> lineString;
        if (lineString != "\n") {
            kind = lineString.substr(0, lineString.find(":"));
            if (kind == "Name") {
                name = lineString.substr(lineString.find(":"), lineString.length());
            }
            else if (kind == "Type") {
                type = lineString.substr(lineString.find(":"), lineString.length());
            }
            else if (type == "Creature") {
                if (kind == "Life") {
                    life = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
                else if (kind == "Strength") {
                    strength = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
                else if (kind == "Intelligence") {
                    intelligence = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
                else if (kind == "Natural") {
                    string true_false = lineString.substr(lineString.find(":"), lineString.length());
                    if (true_false == "True") {
                        natural = 1;
                    }
                }
                else if (kind == "Disquiet") {
                    disquiet = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
            }
            else if (type == "Person") {
                if (kind == "Life") {
                    life = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
                else if (kind == "Strength") {
                    strength = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
                else if (kind == "Intelligence") {
                    intelligence = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
                else if (kind == "Gender") {
                    gender = lineString.substr(lineString.find(":"), lineString.length());
                }
                else if (kind == "Fear") {
                    fear = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
                else if (kind == "Terror") {
                    terror = stoi(lineString.substr(lineString.find(":"), lineString.length()));
                }
            }
        }
        else {
            if (type == "Creature") {
                roles[name] = new Creature(name, life, strength, intelligence, natural, disquiet);
            }
            
        } 
    }

    fin.close();
    for (auto it = roles.cbegin(); it != roles.cend(); ++it) {
        cout << "FOR INN";
        cout << it->first 
            << " " << it->second->life 
            << " " << it->second->strength 
            << " " << it->second->intelligence << "\n";
    }

    /* cout << "1. Create new role/species\n2. Get list of all roles/species\n3. Remove role/species\nYour choice: ";
    cin >> chosenNumber;

    cout << chosenNumber << endl;
    switch (chosenNumber)
    {
    case 1:
        createRoleSpecies(roles);
        break;
    case 2:
        getListRoleSpecies(roles);
    case 3:
        removeRoleSpecies(roles);
    default:
        cout << "Please try again" << endl;
    } */
}
