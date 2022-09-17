#pragma once

#include <string>
#include <fstream>

class CsvWriter
{
public:
    CsvWriter(const std::string &csvPath);
    virtual ~CsvWriter();
    void nextLine();
    void addEntry(const std::string &entry);

private:
    std::ofstream   _ofs;
    bool            _isFirstEntry;

};


