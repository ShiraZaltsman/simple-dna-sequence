//
// Created by shira on 9/26/19.
//

#include "DnaSequence.h"

size_t mystrlen(const char *str) {
    const char *p = str;
    while (*p++);
    return (p - str - 1);
}

bool operator==(DnaSequence &seq1, DnaSequence &seq2) {
    if (seq1.get_seq_length() != seq2.get_seq_length()) {
        return false;
    } else {
        for (size_t i = 0; i < seq1.get_seq_length(); ++i) {
            if (seq1[i] != seq2[i])
                return false;
        }
        return true;
    }
}

bool operator!=(DnaSequence &seq1, DnaSequence &seq2) {
    return !(seq1 == seq2);
}


