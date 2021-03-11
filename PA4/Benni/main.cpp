#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string.h>
#include <string>
#include <map>
#include <queue>

#include "h/being.h"
#include "h/creature.h"
#include "h/investigator.h"
#include "h/person.h"

using namespace std;

void createRoleSpecies(map<string, Being*> roles) {
    string name;
    string type;
    int life;
    int strength;
    int intelligence; 
    bool natural;
    string naturalstring;
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

    if (type == "Creature"){
        cout << "Natural (y/n): ";
        cin >> naturalstring;
        if (naturalstring == "y"){
            natural = true;
            naturalstring = "True";
        }
        else{
            natural = false;
            naturalstring = "False";
        }
        cout << "Disquiet: ";
        cin >> disquiet;

        roles[name] = new Creature(name, type, life, strength, intelligence, natural, disquiet, -1);
    }

    if (type == "Eldritch horror"){
        natural = 0;
        disquiet = 10;
        cout << "Traumatism: ";
        cin >> traumatism;

        roles[name] = new Creature(name, type, life, strength, intelligence, false, 10, traumatism);
    }

    if (type == "Person" || type == "Investigator") {
        cout << "Gender: ";
        cout << "Fear: ";
        cin >> fear;
        if (type == "Investigator") {
            cout << "Terror: ";
            cin >> terror;
            roles[name] = new Investigator(name, type, life, strength, intelligence, gender, fear, terror);
        }
        else {
            roles[name] = new Person(name, type, life, strength, intelligence, gender, fear);
        }
    }
}

void removeRoleSpecies(map<string, Being*> roles) {
     map<string, Being*>::iterator it;
    int counter = 1;
    int chosenNumber;
    for (it = roles.begin(); it != roles.end(); ++it) {
        cout << counter << ". " << it->second->name << endl;
        counter++;
    }
    cout << counter << ". " << "Back to main menu." << endl;
    cout << "Choose a role/species you want to delete by entering it's number: ";
    cin >> chosenNumber;

    if (chosenNumber != counter) {
        int newCounter = 1;
        for (it = roles.begin(); it != roles.end(); ++it) {
            if (newCounter == chosenNumber) {
                cout << it->second << endl;
                break;
            }
            newCounter ++;
        }
    }
    cout << "#######################################" << endl;
}

map<string, Being*> createRoleMap(queue<string> stats) {
    map <string, Being*> roles;
    map <string, Being*>::iterator it;
    string name;
    string type;
    string gender;
    string naturalstring;
    int life;
    int strength;
    int intelligence;
    int disquiet;
    int traumatism;
    int fear;
    int terror;
    bool natural;
    pair< queue<string>, string> statpair;
    
    while(stats.size() > 1) {
        name = stats.front();
        stats.pop();
        type = stats.front();
        stats.pop();
        life = stoi(stats.front());
        stats.pop();
        strength = stoi(stats.front());
        stats.pop();
        intelligence = stoi(stats.front());
        stats.pop();

        if (type == "Creature") {
            naturalstring = stats.front();
            stats.pop();
            if (naturalstring == "true") {
                natural = true;
            }
            else {
                natural = false;
            }

            disquiet = stoi(stats.front());
            stats.pop();
            roles[name] = new Creature(name, type, life, strength, intelligence, natural, disquiet, -1);
        }
        else if (type == "Eldritch horror") {
            traumatism = stoi(stats.front());
            stats.pop();
            roles[name] = new Creature(name, type, life, strength, intelligence, false, 10, traumatism);
        }
        else if ((type == "Person") || (type == "Investigator")) {
            gender = stats.front();
            stats.pop();

            fear = stoi(stats.front());
            stats.pop();

            roles[name] = new Person(name, type, life, strength, intelligence, gender, fear);
            
            if (type == "Investigator") {
                terror = stoi(stats.front());
                stats.pop();
                
                roles[name] = new Investigator(name, type, life, strength, intelligence, gender, fear, terror);
            }
        }
    }
    return roles;
}

map<string, Being*> readRolesFromFile() {
    queue<string> stats;
    map<string, Being*> roles;
    string value;
    ifstream fin;

    fin.open("roster.txt");
    while (!fin.eof()){
        string line;
        fin >> line;

        value = line.substr(line.find(":") + 1, line.length());
        stats.push(value);
    }
    fin.close();

    roles = createRoleMap(stats);
    return roles;
}

map<string, Being*> displayRemoveRoles(map<string, Being*> roles, int switchNumber) {
    map<string, Being*>::iterator it;
    int counter = 1;
    int chosenNumber;
    for (it = roles.begin(); it != roles.end(); ++it){
        cout << counter << ". " << it->second->name << endl;
        counter++;
    }
    cout << counter << ". " << "Back to main menu." << endl;
    if (switchNumber == 2) {
        cout << "Choose a role/species by entering it's number: ";
    } else {
        cout << "Choose a role/species to delete by entering it's number: ";
    }
    cin >> chosenNumber;

    if (chosenNumber != counter) {
        int newCounter = 1;
        for (it = roles.begin(); it != roles.end(); ++it) {
            if (newCounter == chosenNumber) {
                if (switchNumber == 2) { // Display roles/species
                    cout << it->second << endl;
                } else { // Remove role/species
                    roles.erase(it);
                }
                break;
            }
            newCounter ++;
        }
    }
    string answer;
    cout << "Choose 'b' to return to main menu: ";
    cin >> answer;
    if (answer != "b") {
        cout << "Ehmmmmm that also works........." << endl;
    }
    cout << "#######################################" << endl;
    return roles;
}

int main() {
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    int chosenNumber;
    map<string, Being*> roles;
    roles = readRolesFromFile();
    // for (auto it = roles.cbegin(); it != roles.cend(); ++it) {
    //     //cout << it->first;
    //     cout << "Name: " << it->first << "\nType: " << it->second->name << "\nLife: " << it->second->life << "\nStrength: " << it->second->strength << "\nIntelligence: " << it->second->intelligence << endl;
    // }

    while (true) {
        cout << "#######################################" << endl;
        cout << "1. Create new role/species\n2. Get list of all roles/species\n3. Remove role/species\n4. Save\n5. Save and Quit\nChoose what you want to do by selecting a number: ";
        cin >> chosenNumber;
        cout << "#######################################" << endl;
        
        switch (chosenNumber) {
        case 1:
            // createRoleSpecies(roles);
            break;
        case 2:
            roles = displayRemoveRoles(roles, chosenNumber);
            break;
        case 3:
            roles = displayRemoveRoles(roles, chosenNumber);
            break;
        case 4:
            //skrifa i txt file.
        case 5:
            //skrifa i txt file.
            exit(0);
        default:
            cout << "Please try again" << endl;
            cout << "#######################################" << endl;
        }
    }
}
