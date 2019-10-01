//
// Created by shira on 9/26/19.
//

#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H

#include <iostream>
#include "Nucleotide.h"




class DnaSequence {
public:
    DnaSequence(const char *seq);
    DnaSequence();
    ~DnaSequence();
    //cpy ctor
    DnaSequence(const DnaSequence &dnaSequence);

    //assigment operator
    DnaSequence &operator=(const DnaSequence& seq);
    //DnaSequence& operator=(const std::string *seq);
    //DnaSequence& operator=(const char *seq);
    //DnaSequence &operator=(std::string seq);

    char operator[](size_t index);

    size_t get_seq_length() const;

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &dnaSequence);

    Nucleotide * get_seq() const;


private:
    Nucleotide *m_seq;
    size_t m_len;
};

size_t mystrlen(const char *str);

inline DnaSequence::DnaSequence(const char *seq) {
    try {
        this->m_len = mystrlen(seq);
        this->m_seq = new Nucleotide[this->m_len];
        for (size_t i = 0; i < this->m_len; ++i) {
            this->m_seq[i].set_value(seq[i]);
        }
    }catch (const char* e){
        delete[] this->m_seq;
        throw e;
    }
}

inline std::ostream &operator<<(std::ostream &os, const DnaSequence &dnaSequence) {
    for (size_t i = 0; i < dnaSequence.get_seq_length() ; ++i) {
        os << dnaSequence.m_seq[i].get_value();
    }
    return os;
}

bool operator==(DnaSequence &seq1, DnaSequence &seq2);

bool operator!=(DnaSequence &seq1,  DnaSequence &seq2);

inline char DnaSequence::operator[](size_t index) {
    if(index<this->m_len)
        return m_seq[index].get_value();
    else
        throw "index out of range";

}

inline size_t DnaSequence::get_seq_length() const {
    return this->m_len;
}

inline DnaSequence &DnaSequence::operator=(const DnaSequence &seq) {
    if (this != &seq) {
        delete[] this->m_seq;
        m_len = seq.m_len;
        m_seq = new Nucleotide[m_len];
        for (size_t i = 0; i < m_len; ++i) {
            m_seq[i].set_value(seq.get_seq()[i].get_value());
        }

        return (*this);
    }
    return (*this);
}

inline Nucleotide *DnaSequence::get_seq()const {
        return this->m_seq;
}

inline DnaSequence::DnaSequence(const DnaSequence &seq) {
        this->m_len = seq.m_len;
        this->m_seq = new Nucleotide[m_len];
        for (size_t i = 0; i < m_len; ++i) {
            m_seq[i].set_value(seq.get_seq()[i].get_value());
        }
}

inline DnaSequence::~DnaSequence() {
    delete[] this->m_seq;
}


#endif //DNA_DNASEQUENCE_H
