#include <iostream>
#include "DnaSequence.h"
int main() {
    try {
        std::cout << "Hello, World!" << std::endl;
        DnaSequence seq1("AATTCCGG");
        DnaSequence seq2 = seq1;

        std::cout << seq1 << seq2;
        std::cout << seq1[2];
        DnaSequence seq3("ATATA");

        std::cout << "\nseq3==seq2: " << (seq3 == seq2) << std::endl;
        std::cout << "\nseq3!=seq2: " << (seq3 != seq2) << std::endl;
    }catch (const char * e){
        std::cout<<std::endl<<e<<std::endl;
    }
    return 0;
}