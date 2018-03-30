//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>

using namespace std;

string getAttributeValue (string attributeName, string& line);
string getTagValue(string tagName, string& line);

class Person{
public:
    string id{};
    string name{};
    string label{};
    string artist{};
    string writer{};
    string year{};
    string series{};
    string vol{};
    string issue{};
    string merchandise{};
    string clothes{};
    string toys{};
    string movies{};
    string games{};
    string comics{};
    explicit Person(string personXML[18]); //explicit sollte angegeben werden, da es vom compiler verlangt wird
    vector<string> toXML();
    void ausgeben();
};

Person::Person (string *personXML) {
    id = getAttributeValue("xml:id", personXML[1]); //an welcher arraystelle der wert zu holen ist
    name =getTagValue("name", personXML[1]); //name und id befinden sich in der gleichen tagzeile->[1]
    label = getTagValue("label", personXML[2]);
    artist = getTagValue("artist", personXML[4]);
    writer = getTagValue("writer", personXML[5]);
    year = getTagValue("year", personXML[8]);
    series = getTagValue("series", personXML[9]);
    vol = getTagValue("vol", personXML[11]);
    issue = getTagValue("issue", personXML[12]);

}

// Da bisher nur die Infotmationen zwischen den Tags ausgelesen wurden, werden hier die Start- und Endtags wieder hinzugefügt,
// damit die neu konvertierte Datei so aussieht, wie es in der Vorgabe verlangt wurde.

vector<string> Person::toXML() {
    vector<string> lines;
    /* lines.push_back("<person xml:id= "+id+">");
     lines.push_back("<persName>");
     lines.push_back("<forename>" + vorname + "</forename>");
     lines.push_back("<surname>" + nachname + "</surname>");
     lines.push_back("</persName>");
     lines.push_back("<birth when= " + geburtsdatum + "</birth>");
     lines.push_back("</person>");
     */

    lines.push_back("<name hero_id= "+id+">");
    lines.push_back("<label>"+ label + "</label>");
    lines.push_back("<artist>"+ artist + "</artist>");
    lines.push_back("<writer>" + writer + "</writer>");
    lines.push_back("<year>" + year + "</year>");
    lines.push_back("<series>" + series + "</series>");
    lines.push_back("<vol>" + vol + "</vol>");
    lines.push_back("<issue>" + issue + "</issue>");
    return lines;
}

void Person::ausgeben(){
    cout << "ID:" << id;
    cout << " - label: " << label;
    cout << " - artist: " << artist;
    cout << " - writer " << writer;
    cout << " - year " << year;
    cout << " - series" << series;
    cout << " - vol" << vol;
    cout << " - issue" << issue;
    cout << " - merchandise" << merchandise;
    cout << " - clothes" << clothes;
    cout << " - toys" << toys;
    cout << " - movies" << movies;
    cout << " - games" << games;
    cout << " - comics" << comics << endl;
}