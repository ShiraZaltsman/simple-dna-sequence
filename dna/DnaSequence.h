//
// Created by shira on 9/26/19.
//

#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H

#include <iostream>
#include "Nucleotide.h"
#include "mystring.h"

size_t strlen(const char *str);

class DnaSequence {
public:
    DnaSequence(const char *seq);

    //DnaSequence(const std::string seq);

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

inline DnaSequence::DnaSequence(const char *seq) {
    m_len = strlen(seq);
    m_seq=new Nucleotide[m_len];
    for (size_t i = 0; i <m_len ; ++i) {
        m_seq[i].set_value(seq[i]);
    }
}

inline std::ostream &operator<<(std::ostream &os, const DnaSequence &dnaSequence) {
    for (size_t i = 0; i < dnaSequence.get_seq_length() ; ++i) {
        os << dnaSequence.m_seq[i].get_value();
    }
    os<< std::endl;
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


//DnaSequence::DnaSequence(const std::string _seq) {
//    const char * seq=std::string::c_str(_seq);
//    m_len = strlen(_seq);
//    m_seq=new Nucleotide[m_len];
//    for (size_t i = 0; i <m_len ; ++i) {
//        m_seq[i].set_value(seq[i]);
//    }
//}


#endif //DNA_DNASEQUENCE_H
