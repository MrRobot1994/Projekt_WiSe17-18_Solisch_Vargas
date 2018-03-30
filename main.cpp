//#include <iostream>     // Standard input/output Bibliothek
#include <fstream>      // Wird gebraucht, um Dateien zu lesen und beschreiben zu können
#include <iostream>


#include "klasseperson.h"
#include "klasseliste.h"

using namespace std;


int main(){

    Liste personList;
    personList.readXML();
    personList.readBIRTH();

    string eingabe;
    cout << "1. Wollen sie die beiden Dateien in eine neue Datei konvertieren?" << endl;
    cout << "2. Wollen sie eine bestimmte Information in den Datein suchen?" << endl;
    cout << endl;
    cout << "Auswahlmoeglichkeiten: '1 = konvertieren' oder '2 = suchen'" << endl;
    cin >> eingabe;


    if(eingabe.compare("1") == 0){          //.compare vergleicht den Inhalt eines Strings, mit den hier definierten Vorgaben (in diesem Fall "1")

        cout << "Geben sie der konvertierten Datei einen Namen:" << endl;
        cin >> eingabe;
        personList.toXML(eingabe);
        cout << "konvertiert";
        cout << endl;
    }
    else if(eingabe.compare("2") == 0){
        cout << "Diese Funktion steht zur Zeit leider nicht zu Verfuegung." << endl;
        cout << endl;

    }
    else if(eingabe.compare("!=1, !=2")){
        cout << "Ihre Eingabe stimmt nicht mit den vorgegebenen Moeglichkeiten ueberein" << endl;
        cout << endl;
    }
}

// Eine while Schleife, um den Inhalt der Attribute zu extrahieren

string getAttributeValue(string attributeName, string &line) {
    size_t index = line.find(attributeName)+attributeName.length(); //size_t statt int benutzt, da ansonsten compiler fehler angezeigt werden
    char currentChar = '\0';
    while(currentChar != '"'){
        currentChar = line.at(index);
        index++;
    }
    currentChar = 0;
    string attributeValue;

    while(currentChar != '"'){
        currentChar = line.at(index);
        if(currentChar != '"'){
            attributeValue += currentChar;
            index++;
        }
    }
    return attributeValue;
}

// Eine while Schleife, um den Inhalt der Tags zu extrahieren

string getTagValue(string tagName, string &line){
    size_t index = line.find("<"+tagName+"")+tagName.length(); //size_t statt int benutzt, da ansonsten compiler fehler angezeigt werden
    char currentChar = 0;
    string tagValue;
    while(currentChar != '>') {
        currentChar = line.at(index);
        index++;
    }
    currentChar = 0;
    while(currentChar != '<') {
        currentChar = line.at(index);
        if(currentChar != '<'){
            tagValue += currentChar;
            index++;
        }
    }

    return tagValue;

}
