//
// Created by shira on 10/28/19.
//

#ifndef DNA_DNACOLLLECTION_H
#define DNA_DNACOLLLECTION_H

#include "DnaSequence.h"

class DnaColllection {
public:
    void addRecord(DnaSequenceRecord);
    DnaSequenceRecord findByName(std::string name);
    DnaSequenceRecord findByID(std::string name);
private:
    std::vector<DnaSequenceRecord> m_collcetion;
};

inline void DnaColllection::addRecord(DnaSequenceRecord record) {
     m_collcetion.push_back(record);

}

inline DnaSequenceRecord DnaColllection::findByName(std::string name) {
    return DnaSequenceRecord(DnaSequence(),"");
}

#endif //DNA_DNACOLLLECTION_H
