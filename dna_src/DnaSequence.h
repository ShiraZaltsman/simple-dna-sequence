//
// Created by shira on 9/26/19.
//

#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H

#include <iostream>
#include <vector>

class DnaSequence {

    class Nucleotide {
    public:
        Nucleotide();
        Nucleotide(char val);
        void set_value(char val);
        char get_value()const;
        Nucleotide &operator=(const Nucleotide &nuc);
    private:
        char value;
    };

public:
    DnaSequence(const char *seq);

    DnaSequence();

    ~DnaSequence();

    //cpy ctor
    DnaSequence(const DnaSequence &dnaSequence);

    //assigment operator
    DnaSequence &operator=(const DnaSequence &seq);

    void operator+=(const char nuc);

    const char operator[](size_t index) const;

    char &operator[](size_t index);

    size_t get_seq_length() const;

    DnaSequence get_sub_seq(size_t startindex, size_t EndIndex);

    DnaSequence get_complementary_seq();

    int find(const DnaSequence seq, size_t start = 0);

    int Count(const DnaSequence seq);

    int *FindAll(const DnaSequence seq);

    std::vector<DnaSequence> get_all_consensus();

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &dnaSequence);

    Nucleotide *const get_seq() const;


private:
    Nucleotide *m_seq;
    size_t m_len;
};

static int countRecord=0;
class DnaSequenceRecord {
public:
    DnaSequenceRecord(DnaSequence seq, std::string name);
    void id_genarate(){
        countRecord++;
        m_ID=countRecord;
    }

    int getId() const;

    const std::string &getName() const;

    void setName(const std::string &mName);

    const DnaSequence &getSeq() const;

    void setSeq(const DnaSequence &mSeq);

    void printRecord();

private:
    int m_ID;
    std::string m_name;
    DnaSequence m_seq;

};

inline int DnaSequenceRecord::getId() const {
    return m_ID;
}

inline const std::string &DnaSequenceRecord::getName() const {
    return m_name;
}

inline void DnaSequenceRecord::setName(const std::string &mName) {
    m_name = mName;
}

inline const DnaSequence &DnaSequenceRecord::getSeq() const {
    return m_seq;
}

inline void DnaSequenceRecord::setSeq(const DnaSequence &mSeq) {
    m_seq = mSeq;
}

inline DnaSequenceRecord::DnaSequenceRecord(DnaSequence seq, std::string name) {
    m_seq=seq;
    m_name=name;
    id_genarate();
}

inline void DnaSequenceRecord::printRecord() {
    std::cout<<"["<<m_ID<<"]"<<" "<<m_name<<": ";
    if(m_seq.get_seq_length()>40){
        std::cout<<m_seq.get_sub_seq(0,32)
        <<"..."<<m_seq.get_sub_seq(m_seq.get_seq_length()-3,m_seq.get_seq_length())<<std::endl;
    }
    else{
        std::cout<<m_seq<<std::endl;
    }
}


inline DnaSequence::Nucleotide::Nucleotide() {

}

inline DnaSequence::Nucleotide::Nucleotide(char val) {
    if(val=='A' || val=='G' || val=='C'|| val=='T' ){
        this->value=val;
    } else{
        throw "nucleotide value is not valid!";
    }
}

inline void DnaSequence::Nucleotide::set_value(char val) {
    if(val=='A' || val=='G' || val=='C'|| val=='T' ){
        this->value=val;
    } else{
        throw "nucleotide value is not valid!";
    }
}

inline char DnaSequence::Nucleotide::get_value() const {
    return value;
}

inline DnaSequence::Nucleotide &DnaSequence::Nucleotide::operator=(const Nucleotide &nuc) {
    value=nuc.get_value();
    return (*this);
}


size_t mystrlen(const char *str);

bool operator==(const DnaSequence &seq1, const DnaSequence &seq2);

bool operator!=(const DnaSequence &seq1, const DnaSequence &seq2);

// phase_2:
char ComplementaryBase(char value);

DnaSequence readSequenceFile(std::string fileName);

void writeSequenceFile(const std::string &fileName, DnaSequence seq);

inline DnaSequence::DnaSequence() {
    m_len = 0;
    m_seq = NULL;
}

inline DnaSequence::DnaSequence(const char *seq) {
    try {

        m_len = mystrlen(seq);
        m_seq = new Nucleotide[m_len];
        for (size_t i = 0; i < m_len; ++i) {
            m_seq[i].set_value(seq[i]);
        }
    } catch (const char *e) {
        delete[] m_seq;
        throw e;
    }
}

inline DnaSequence::DnaSequence(const DnaSequence &seq) {
    m_len = seq.m_len;
    m_seq = new Nucleotide[m_len];
    for (size_t i = 0; i < m_len; ++i) {
        m_seq[i].set_value(seq.get_seq()[i].get_value());
    }
}

inline DnaSequence::~DnaSequence() {
    delete[] m_seq;
}

inline DnaSequence &DnaSequence::operator=(const DnaSequence &seq) {
    if (this != &seq) {
        delete[] m_seq;
        m_len = seq.m_len;
        m_seq = new Nucleotide[m_len];
        for (size_t i = 0; i < m_len; ++i) {
            m_seq[i].set_value(seq.get_seq()[i].get_value());
        }

        return (*this);
    }
    return (*this);
}

inline std::ostream &operator<<(std::ostream &os, const DnaSequence &dnaSequence) {
    for (size_t i = 0; i < dnaSequence.get_seq_length(); ++i) {
        os << dnaSequence.m_seq[i].get_value();
    }
    return os;
}

inline const char DnaSequence::operator[](size_t index) const {
    if (index < m_len)
        return m_seq[index].get_value();
    else
        throw "index out of range";

}

inline void DnaSequence::operator+=(const char nuc) {
    Nucleotide n(nuc);
    Nucleotide *temp = new Nucleotide[m_len + 1];
    for (size_t i = 0; i < m_len; ++i) {
        temp[i] = m_seq[i];
    }
    temp[m_len] = n;
    delete[]m_seq;
    m_seq = temp;
    ++m_len;

}

inline DnaSequence::Nucleotide *const DnaSequence::get_seq() const {
    return m_seq;
}

inline size_t DnaSequence::get_seq_length() const {
    return m_len;
}

inline DnaSequence DnaSequence::get_sub_seq(size_t StartIndex, size_t EndIndex) {
    if (StartIndex >= EndIndex) {
        throw "invalid indexes";
    }
    DnaSequence subseq("");
    for (size_t i = StartIndex; i < EndIndex; ++i) {
        subseq += m_seq[i].get_value();
    }

    return subseq;
}

inline DnaSequence DnaSequence::get_complementary_seq() {
    DnaSequence pairdSeq;
    for (size_t i = 1; i <= m_len; ++i) {
        pairdSeq += ComplementaryBase(m_seq[m_len - i].get_value());
    }
    return pairdSeq;
}

inline int DnaSequence::find(const DnaSequence seq, size_t start) {
    for (size_t i = start; i <= m_len - seq.get_seq_length(); i++) {
        size_t j;
        /* For current index i, check for pattern match */
        for (j = 0; j < seq.get_seq_length(); j++)
            if (m_seq[i + j].get_value() != seq[j])
                break;
        if (j == seq.get_seq_length())
            return int(i);
    }
    return -1;
}

inline int DnaSequence::Count(const DnaSequence seq) {
    int count = 0;
    for (size_t i = 0; i < m_len;) {
        int ans = find(seq, i);
        if (ans > 0) {
            i = ans + seq.get_seq_length();
            count++;
        } else {
            break;
        }
    }
    return count;
}

inline int *DnaSequence::FindAll(const DnaSequence seq) {
    int size = this->Count(seq);
    if (size > 0) {
        int *indexs = new int[size];
        indexs[0] = find(seq);
        for (int i = 1; i < size; ++i) {
            indexs[i] = find(seq, indexs[i - 1] + seq.get_seq_length());
        }
        return indexs;
    }
    return NULL;
}

inline std::vector<DnaSequence> DnaSequence::get_all_consensus() {
    std::vector<DnaSequence> consesuslist;
    int *s = this->FindAll("ATG");
    for (int j = 0; j < this->Count("ATG"); ++j) {
        size_t start_index = s[j] + 3;
        while (start_index + 3 <= m_len) {
            DnaSequence nextcodon = this->get_sub_seq(start_index, start_index + 3);
            if (nextcodon == "TAG" || nextcodon == "TAA" || nextcodon == "TGA") {
                consesuslist.push_back(get_sub_seq(s[j], start_index + 3));
            }
            start_index = start_index + 3;
        }
    }
    return consesuslist;
}

//inline char &DnaSequence::operator[](size_t index) {
//    return 'n';
//}

#endif //DNA_DNASEQUENCE_H
