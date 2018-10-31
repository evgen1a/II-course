#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PhoneBook {
private:
    class PhoneBookElement {
    private:
        int id;
        string from;
        string to;
        string date;
        string time;
        int duration;
    public:

        PhoneBookElement(int id, string from, string to, string date, string time, int duration){
            this->id = id;
            this->from = from;
            this->to = to;
            this->date = date;
            this->time = time;
            this->duration = duration;
        }
        int getId() {
            return this->id;
        }
        string getFrom(){
            return this->from;
        }
        string getTo(){
            return this->to;
        }
        string getDate(){
            return this->date; }
        string getTime(){ return this->time;
        }
        int getDuration(){
            return this->duration;
        }

    };
    vector<PhoneBookElement> phonebook;
    int numberId = 1;

public:
    void show(){
        cout << "ID\t\tFrom\t\tTo\t\tDate\t\tTime\t\tDuration" << endl;
        for (int i = 0; i < this->phonebook.size(); i++)
            cout << phonebook[i].getId() << "\t\t" << phonebook[i].getFrom() << "\t\t" << phonebook[i].getTo() << "\t\t" << phonebook[i].getDate() << "\t" << phonebook[i].getTime() << "\t\t"
                 << phonebook[i].getDuration() << endl;
        cout << endl;
    }

    void add(string from, string to, string date, string time, int duration){
        PhoneBookElement temp(numberId++,from,to,date,time, duration);
        phonebook.push_back(temp);
    }

    void erase(int searchId){
        for(int i = 0;i < phonebook.size();i++){
            if (phonebook[i].getId() == searchId){
                phonebook.erase(phonebook.begin() + i);
            }
        }
    }

    void sortFrom() {
        for (int i = 0; i < phonebook.size() - 1; i++) {
            for (int j = 0; j < phonebook.size() - 1 - i; j++) {
                if (phonebook[j].getFrom() > phonebook[j + 1].getFrom())
                    swap(phonebook[j], phonebook[j+1]);
            }
        }
    }

    void sortTime() {
        for (int i = 0; i < phonebook.size() - 1; i++) {
            for (int j = 0; j < phonebook.size() - 1; j++) {
                if (phonebook[j].getTime() > phonebook[j + 1].getTime())
                    swap(phonebook[j], phonebook[j + 1]);
            }
        }
    }

    void sortDuration() {
        for (int i = 0; i < phonebook.size() - 1; i++) {
            for (int j = 0; j < phonebook.size() - 1; j++) {
                if (phonebook[j].getDuration() > phonebook[j + 1].getDuration())
                    swap(phonebook[j], phonebook[j + 1]);
            }
        }
    }

    void searchFrom(string from){
        bool flag = false;
        for (int i = 0; i < phonebook.size() ; i++) {
            if (phonebook[i].getFrom() == from){
                cout << "ID\t\tFrom\t\tTo\t\tDate\t\tTime\t\tDuration" << endl;
                cout << phonebook[i].getId() << "\t\t" << phonebook[i].getFrom() << "\t\t" << phonebook[i].getTo() << "\t\t" << phonebook[i].getDate() << "\t" << phonebook[i].getTime() << "\t\t"
                     << phonebook[i].getDuration() << endl;
                cout << endl;
                flag = true;
            }
        }
        if(flag == false)
            cout << "This element does not exist" << endl;
    }

    void searchTo(string to){
        bool flag = false;
        for (int i = 0; i < phonebook.size() ; i++) {
            if (phonebook[i].getTo() == to){
                cout << "ID\t\tFrom\t\tTo\t\tDate\t\tTime\t\tDuration" << endl;
                cout << phonebook[i].getId() << "\t\t" << phonebook[i].getFrom() << "\t\t" << phonebook[i].getTo() << "\t\t" << phonebook[i].getDate() << "\t" << phonebook[i].getTime() << "\t\t"
                     << phonebook[i].getDuration() << endl;
                cout << endl;
                flag = true;
            }
        }
        if(flag == false)
            cout << "This element does not exist" << endl;
    }
};

int main()
{
    PhoneBook book;
    int select,elem1;
    string elem2;
    string efrom;
    string eto;
    string edate;
    string etime;
    int eduration;
    book.add("Petya", "Dima", "11.03.2000", "19:03", 66);
    book.add("Vitya", "Evgenia", "09.07.2017", "21:07", 7);
    book.add("Rita", "Masha", "12.03.2013", "07:17", 9);
    book.add("Taisia", "Lera", "17.04.2005", "14:21", 99);
    while(true) {
        cout << "1. add, 2. delete 3.show 4.sortFrom 5.sortTime 6.sortDur 7.searchFrom 8.searchTo" <<endl;
        cin >> select;
        switch (select){
            case 1: {
                cin >> efrom >> efrom >> eto >> edate >> etime >> eduration;
                book.add(efrom,eto,edate,etime,eduration);
                break;
            }
            case 2: {
                cin >> elem1;
                book.erase(elem1);
                break;
            }
            case 3: {
                book.show();
                break;
            }
            case 4:{
                book.sortFrom();
                break;
            }
            case 5:{
                book.sortTime();
                break;
            }
            case 6:{
                book.sortDuration();
                break;
            };
            case 7:{
                cin >> elem2;
                book.searchFrom(elem2);
                break;
            }
            case 8: {
                cin >> elem2;
                book.searchTo(elem2);
                break;
            }
            default:
                exit(0);
            }

    }
    return 0;
}