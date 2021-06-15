#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//class
class Beta{
    public:
        string Name;
        string Word;
        string Number;

        Beta(string Name, string Word, string Number){
           Beta::Name = Name;
           Beta::Word = Word;
           Beta::Number = Number;
        }

        string stringify(){
            return "\n" + Name + " " + Word + " " + Number;
        }
};

class DBase{
    public:
        ifstream in;
        ofstream out;
        string fileName;

        DBase(const char* fileName){
            DBase::fileName = fileName;
        }

        void save(Beta data){
        cout << data.Name << endl;
        cout << data.Word << endl;
        cout << data.Number << endl;

        DBase::out.open(DBase::fileName,ios::app);
        DBase::out << data.stringify();
        DBase::out.close();
        }

        void showAll(){
            DBase::in.open(DBase::fileName,ios::in);
            string Name, Word , Number;
            int index = 1;

            while(!DBase::in.eof()){
                DBase::in >> Name;
                DBase::in >> Word;
                DBase::in >> Number;
                cout << index++ << "\t";
                cout << Name << "\t";
                cout << Word << "\t";
                cout << Number << endl;
            }
            DBase::in.close();
        }
};

int main(int argc, char const *argv[])
{
    //creating required data
    DBase database = DBase("userdata.txt");
    database.showAll();

    //user input
    string Name, Word, Number;
    cout << "Enter Your Data" << endl;
    cout << "Name : ";
    cin >> Name;
    cout << "type a random Word : ";
    cin >> Word;
    cout << "type a random number  : ";
    cin >> Number;

    Beta dataBeta = Beta(Name, Word, Number);

    //save to database
    database.save(dataBeta);
    

    database.showAll();
    return 0;
}



// additional notes for windows:
// dont forget to create txt file first
// file name for example if >> CBase database = CBase("example.txt"); >> file name is example.txt
