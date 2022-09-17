#include "CsvWriter.h" 
 
CsvWriter::CsvWriter(const std::string &csvPath):_isFirstEntry(true)
{
    _ofs.open(csvPath.c_str());
}

CsvWriter::~CsvWriter()
{
    _ofs.flush();
    _ofs.close();
}
    
void CsvWriter::nextLine()
{   
    _ofs << std::endl;
}

void CsvWriter::addEntry(const std::string &entry)
{
    _ofs << (_isFirstEntry ? "" : ",") <<  entry;
    _isFirstEntry = false;
}
