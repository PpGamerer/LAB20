#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream file(filename);
    string textline;
    string format = "%[^:]: %d %d %d";
    int x,y,z;
    char name[100];
    int i = 0;
    while(getline(file,textline))
    {
    sscanf(textline.c_str(),format.c_str(),name,&x,&y,&z);
    names.push_back(name);
    scores.push_back(x+y+z);
    grades.push_back(score2grade(scores[i]));
    i++;
    }
}

void getCommand(string &command, string &key){
    cout << "Please input your command: ";
    cin >> command;
    if(toUpperStr(command) == "GRADE" || toUpperStr(command) == "NAME") {
    cin.ignore();
    getline(cin,key);}
}

void searchName(vector<string> &names,vector<int> &scores,vector<char> &grades,const string &key){
    int check = 0;
    for(size_t i = 0; i < names.size(); i++) {
    if(toUpperStr(names[i]) == key) {
        cout << "---------------------------------" << endl;
        cout << names[i] << "'s score = " << scores[i] << endl;
        cout << names[i] << "'s grade = " << grades[i] << endl;
        cout << "---------------------------------" << endl;
        check = 1;
    }else if(check == 0 && i==names.size()-1) {
        cout << "---------------------------------" << endl;
        cout << "Cannot found." << endl;
        cout << "---------------------------------" << endl;
}}
}

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades,const string key){
    int check = 0;
    for(size_t i = 0; i < grades.size(); i++) {
    if(grades[i] == key[0]) {
        cout << "---------------------------------" << endl;
        for(size_t j = 0; j < grades.size(); j++) {
            if(grades[j] == key[0]){
            cout << names[j] << " (" << scores[j] << ")" << endl;}
            }cout << "---------------------------------" << endl;
        check = 1;
        break;
    }else if(check == 0 && i==names.size()-1) {
        cout << "---------------------------------" << endl;
        cout << "Cannot found." << endl;
        cout << "---------------------------------" << endl;
}}
}

int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
