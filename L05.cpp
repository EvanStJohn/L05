#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Age
{
private:
    vector<string> people;
    vector<int> age;
    int sum = 0;
    int average = 0;
public:
    void catchAge();
    void readFile();
    void reckonAge();
    void output();
};

void Age::readFile()
{
    string line; //this will contain the data read from the file
    ifstream myfile ("input_age.txt"); //opening the file.

    if (myfile.is_open()) //if the file is open
    {
        while (!myfile.eof()) //while the end of file is NOT reached
        {
            getline(myfile, line); //get one line from the file
            people.push_back(line);
        }

        myfile.close(); //closing the file
    }
}

void Age::catchAge()
{
    string line;

    for (int i = 0; i < people.size()-1; i++)
    {
        int pos = 0;
        line = people.at(i);
        pos = line.find_last_of(" ");
        line = line.substr(pos+1, 3);
        age.push_back(std::stoi(line));
    }
}

void Age::reckonAge()
{
    for (int i = 0; i < age.size(); i++)
    {
        sum += age.at(i);
    }

    average = sum / age.size();
}

void Age::output()
{
    ofstream out_stream;
    out_stream.open("output.txt");

    for (int i = 0; i < age.size()-1; i++)
    {
        out_stream << "Age " << i+1 << " is " << age.at(i) << endl;
        cout << "Age " << i+1 << " is " << age.at(i)<< endl;
    }
    out_stream << "The sum of ages is : " << sum <<  endl;
    cout << "The sum of ages is : " << sum <<  endl;
    out_stream << "The average of ages is : " << average  << endl;
    cout << "The average of ages is : " << average  << endl;

    if (average <= 50)
    {
        out_stream << "This is a young group" << endl;
        cout << "This is a young group" << endl;
    }
    else if (average > 50 && average < 100)
    {
        out_stream << "This is a good age group" << endl;
        cout << "This is a good age group" << endl;
    }
    else
    {
        out_stream << "Tell me your secret, my grandma is sick" << endl;
        cout << "Tell me your secret, my grandma is sick" << endl;
    }

    out_stream.close();
}

int main() {
    Age age;
    age.readFile();
    age.catchAge();
    age.reckonAge();
    age.output();

    return 0;
}