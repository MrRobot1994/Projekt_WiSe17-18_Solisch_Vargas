#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Liste {
private:
    vector<Person> personenListe;
public:
    enum searchCategories{id=0, name=1, label=2, artist=3, writer=4, year=5, series=6, vol=7, issue=8, merchandise=9, clothes=10,
        toys=11, movies=12, games=13, comics=14};
    void add(Person person); //momentan nicht benutzt
    void print(); //momentan nicht benutzt
    void readXML();
    void readBIRTH();
    Person * search(searchCategories category, string searchValue);
    void toXML(const string outputFileName);

};
void Liste::add(Person person) { //siehe oben
    personenListe.push_back(person);
}
void Liste::print() { //siehe oben
    for(size_t i = 0; i < personenListe.size(); i++) {
        Person tempPerson = personenListe.at(i);
        tempPerson.ausgeben();

    }
}

// Einlesen der .xml-Datei zum Auslesen der Superhelden
void Liste::readXML(){
    ifstream file("//users//gabrielvargas-cardenas//Desktop//C++//VargasSolischHausarbeit//superhelden.xml");
    vector<string> lineStrings;
    for(string line; getline(file,line);){
        lineStrings.push_back(line);
    }
    lineStrings.erase(lineStrings.begin());     //.erase löscht den Inhalt des Objektes
    lineStrings.pop_back();                     //.pop_back löscht den letzten Char eines Strings

    // Wir gehen davon aus, dass die Informationen zu den einzelnen Personen in der XML-Datei aus genau 6 Elementen besteht,
    // Bsp: 1. <person xml:id="123"> 2. <persName> 3. <forename>Paul</forename> 4. <surname>Biegler</surname> 5. </persName> 6. </person>
    // Sollte dies nicht der Fall sein, funktioniert der Code nicht

    for(size_t i = 0; i< lineStrings.size(); i += 18) {
        string personXMLlines[6];
        for (int j = 0; j < 18; ++j) {
            personXMLlines[j] = lineStrings.at(i+j);
        }
        Person person(personXMLlines);
        personenListe.push_back(person);        //.push_back erweitert das Objekt um ein weiteres Element
    }
}

//Einlesen der .txt-Datei zum Auslesen der Geburtstage

void Liste::readBIRTH() {
    ifstream file("//users//gabrielvargas-cardenas//Desktop//C++//VargasSolischHausarbeit//liste.txt");

    for(string line; getline(file, line);) {
        string personID = line.substr(0,line.find(' '));
        search(id,personID)->merchandise = line.substr(line.find(' ') +1);
    }
}

//switch-case (da wir wissen, wie viele Mögliche Fälle es gibt) um die 4 Kategorien ID, Vorname, Nachname und Geburtstag zusammen zu fassen

Person * Liste::search(searchCategories category, string searchValue) {
    for(size_t i = 0; i < personenListe.size(); i++) {
        Person tempPerson = personenListe.at(i);
        switch(category) {
            case id:
                if (tempPerson.id.compare(searchValue) == 0) {

                    return &personenListe.at(i);
                }
                break;
            case name:
                if (tempPerson.name.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case label:
                if (tempPerson.label.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case artist:
                if (tempPerson.artist.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case writer:
                if (tempPerson.writer.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case year:
                if (tempPerson.year.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case series:
                if (tempPerson.series.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case vol:
                if (tempPerson.vol.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case issue:
                if (tempPerson.issue.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case merchandise:
                if (tempPerson.merchandise.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case clothes:
                if (tempPerson.clothes.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case toys:
                if (tempPerson.toys.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case movies:
                if (tempPerson.movies.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case games:
                if (tempPerson.games.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;
            case comics:
                if (tempPerson.comics.compare(searchValue) == 0) {
                    return &personenListe.at(i);
                }
                break;


        }

    }
    return NULL;
}


void Liste::toXML (const string outputFileName)  {

    ofstream xmlFile;
    xmlFile.open(outputFileName);
    xmlFile << "<listPerson> \n";
    for(size_t i = 0; i < personenListe.size(); ++i) {
        vector<string> tempPersonStrings = personenListe.at(i).toXML();

        for(size_t j = 0; j < tempPersonStrings.size(); ++j) {
            xmlFile << tempPersonStrings.at(j) << "\n";
        }
    }
    xmlFile << "<\\listPerson> \n";
    xmlFile.close();

}
