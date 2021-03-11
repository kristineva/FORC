#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string.h>
#include <string>
#include <map>
#include <sstream>

using namespace std;
#include "h/being.h"
#include "h/creature.h"
#include "h/eldritchHorror.h"
#include "h/investigator.h"
#include "h/person.h"



int main() {
    map<string, Being*> roles;
    map<string, string> bla;
    fstream file("roaster.txt");

    string name;
    string type;
    int life;
    int strength;
    int intelligence;
    string natural;
    int disquiet;
    int traumatism;
    string gender;
    int fear;
    int terror;

    string key;
    string value;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty()) {
                break;
            }
            key = line.substr(0, line.find(":"));
            value = line.substr(line.find(":") + 1, line.length());
            bla.insert(pair<string, string>(key, value));
            }
    }
    map<string, string>::iterator it;

    it = bla.find("Name");
    cout <<  it->second;
    name = it->second;

    it = bla.find("Type");
    type = it->second;

    it = bla.find("Life");
    life = stoi(it->second);

    it = bla.find("Strength");
    strength = stoi(it->second);

    it = bla.find("Intelligence");
    intelligence = stoi(it->second);


    if (type == "Creature") {
        it = bla.find("Natural");
        natural = it->second;

        it = bla.find("Disquiet");
        disquiet = stoi(it->second);

        roles[name] = new Creature(name, life, strength, intelligence, natural, disquiet);
        for(auto it = roles.cbegin(); it != roles.cend(); ++it)
        {
            cout << it->first << " " << it->second->life << " " << it->second->strength << " " << it->second->intelligence << "\n";
        }
    }

    else if (type == "Eldritch horror"){
        natural = "Unnatural";
        disquiet = 10;
        cout << "Traumatism: ";
        cin >> traumatism;
    }
    
    else if (type == "Person" || type == "Investigator"){
        cout << "Gender: ";
        cin >> gender;
        cout << "Fear: ";
        cin >> fear;

        if (type == "Investigator"){
            cout << "Terror: ";
            cin >> terror;

        }
    }
}


