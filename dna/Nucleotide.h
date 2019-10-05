//
// Created by shira on 9/26/19.
//

#ifndef DNA_NUCLEOTIDE_H
#define DNA_NUCLEOTIDE_H

static const char valid_nucl[4]={'A', 'T','G', 'C'};
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
inline Nucleotide::Nucleotide() {

}

inline Nucleotide::Nucleotide(char val) {
    if(val=='A' || val=='G' || val=='C'|| val=='T' ){
        this->value=val;
    } else{
        throw "nucleotide value is not valid!";
    }
}

inline void Nucleotide::set_value(char val) {
    if(val=='A' || val=='G' || val=='C'|| val=='T' ){
        this->value=val;
    } else{
        throw "nucleotide value is not valid!";
    }
}

inline char Nucleotide::get_value() const {
    return value;
}

inline Nucleotide &Nucleotide::operator=(const Nucleotide &nuc) {
    value=nuc.get_value();
    return (*this);
}

#endif //DNA_NUCLEOTIDE_H
