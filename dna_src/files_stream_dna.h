//
// Created by shira on 10/28/19.
//

#ifndef DNA_FILES_STREAM_DNA_H
#define DNA_FILES_STREAM_DNA_H

#include "DnaSequence.h"
#include <fstream>

class DNAReader {
public:

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
};

class DNAWriter {

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
};


#endif //DNA_FILES_STREAM_DNA_H
