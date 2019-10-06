//
// Created by shira on 9/26/19.
//

#include "DnaSequence.h"
#include <fstream>
size_t mystrlen(const char *str) {
    const char *p = str;
    while (*p++);
    return (p - str - 1);
}

bool operator==(const DnaSequence &seq1, const DnaSequence &seq2) {
    if (seq1.get_seq_length() != seq2.get_seq_length()) {
        return false;
    } else {
        for (size_t i = 0; i < seq1.get_seq_length(); ++i) {
            if (seq1[i]!= seq2[i])
                return false;
        }
        return true;
    }
}

bool operator!=(const DnaSequence &seq1, const DnaSequence &seq2) {
    return !(seq1 == seq2);
}



char ComplementaryBase(char value) {
    char baseComp;
    switch (value) {
        case 'A':
            baseComp = 'T';
            break;
        case 'T':
            baseComp = 'A';
            break;
        case 'C':
            baseComp = 'G';
            break;
        case 'G':
            baseComp = 'C';
            break;
    }
    return baseComp;
}

DnaSequence readSequenceFile(std::string fileName){
    std::string str;
    std::ifstream file(fileName.c_str());
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            str+=line;
        }
        file.close();
    }
    else {
        throw "Unable to open file";
    }
    const char *s=str.c_str();
    DnaSequence sequence(s);
    return sequence;
}

void writeSequenceFile(const std::string& fileName, DnaSequence seq) {
    std::string str;
    std::ofstream file(fileName.c_str());
    if (file.is_open()) {
        for (size_t i = 0; i < seq.get_seq_length() ; ++i) {
            file<<seq[i];
        }
        file.close();
    }
    else {
        throw "Unable to open file";
    }
}
