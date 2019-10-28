//
// Created by shira on 10/28/19.
//

#ifndef DNA_CONTROL_H
#define DNA_CONTROL_H
#include <sstream>
#include "files_stream_dna.h"
#include <string>
#include "DnaColllection.h"
class Control {
private:
    DnaColllection m_DB;
    int m_countNewSeq;
    DNAReader reader;
    DNAWriter writer;
public:
    Control();
    std::string parse_name(std::string commend);
    std::string parse_seq(std::string commend);
    std::string parse_fileName(std::string commend);
    void addNewSeq(std::string commend);
    void loadSeq(std::string commend);
    void showSeq(DnaSequenceRecord record);


    void save(std::string basicString);
};

inline Control::Control() : m_countNewSeq(0) {}



inline void Control::addNewSeq(std::string commend) {
    std::string name;
    if (commend.find('@') < commend.length()) {
        name=parse_name(commend);
    } else {
        std::string name = "seq";
        std::ostringstream ss;
        ss << ++m_countNewSeq;
        name += ss.str();
    }
    DnaSequenceRecord rec(parse_seq(commend).c_str(),name);//implicitly convert the seq string to DnaSequence
    m_DB.addRecord(rec);
    showSeq(rec);

}



inline void Control::showSeq(DnaSequenceRecord record) {
    record.printRecord();
}

inline void Control::save(std::string commend) {

}
std::string ExtractFileName(const std::string& fullPath)
{
    const size_t lastSlashIndex = fullPath.find_last_of('/');
    return fullPath.substr(lastSlashIndex + 1,fullPath.find_last_of('.')) ;
}
inline void Control::loadSeq(std::string commend) {
    std::string name;
    if (commend.find('@') < commend.length()) {
        name=parse_name(commend);
    } else {
        name = ExtractFileName((parse_fileName(commend)));
    }
    ///implicitly convert the seq string to DnaSequence
    DnaSequenceRecord rec(reader.readSequenceFile(parse_fileName(commend)), name);
    m_DB.addRecord(rec);
    showSeq(rec);
}

inline std::string Control::parse_name(std::string commend) {

    return commend.substr(commend.find("@") + 1, commend.length());
}

inline std::string Control::parse_seq(std::string commend) {
    return commend.substr(1, commend.find("@") - 2);
}

inline std::string Control::parse_fileName(std::string commend) {
    return commend.substr(1, commend.find("@") - 2);
}

#endif //DNA_CONTROL_H
