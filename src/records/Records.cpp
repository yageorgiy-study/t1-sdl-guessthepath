#include <string>
#include <fstream>
#include <utility>
#include <algorithm>
#include "Records.h"

Records::Records(std::string dataFilename) {
    this->filename = std::move(dataFilename);
    this->readFromFile();
}

void Records::writeToFile() {
    std::ofstream file;
    file.open (this->filename);
    if(file.is_open()){
        file << username << std::endl;

        for(auto record : values){
            file << record->player << std::endl;
            file << record->score << std::endl;
        }
    }
    file.close();
}

void Records::readFromFile() {
    std::ifstream file;
    file.open (this->filename);
    if(file.is_open()){
        std::getline( file, username );

        std::string playername, score;
        while(std::getline( file, playername ) && std::getline( file, score ))
        {
            this->values.push_back(new Record(playername, std::stoi(score)));
        }

    }
    file.close();
}

bool Records::addValue(Record *rec) {
    auto size = this->values.size();
    if(size < maxValues) {
        this->values.push_back(rec);
        this->sort();
        return true;
    }
    if(rec->score < this->values[size - 1]->score){
        this->values[size - 1] = rec;
        this->sort();
        return true;
    }
    return false;
}

const std::vector<Record *> &Records::getValues() const {
    return values;
}

Records::~Records() {
    for(auto record : values){
        delete record;
    }
}

void Records::sort() {
    struct {
        bool operator()(Record* a, Record* b) const { return a->score < b->score; }
    } customLess;

    std::sort(this->values.begin(), this->values.end(), customLess);
}

void Records::clear() {
    this->values.clear();
}

void Records::printToFile(){
    std::ofstream file;
    file.open("temp_print.txt");
    if(file.is_open()){
        file << "Имя пользователя: " << username << std::endl << std::endl;

        int i = 1;
        for(auto record : values){
            file << "#" << i << ": " << record->player  << ", время: " << (record->score / 1000.) << " сек" << std::endl;
            i++;
        }
    }
    file.close();
}
