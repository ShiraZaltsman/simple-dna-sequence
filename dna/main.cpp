#include <iostream>
#include "DnaSequence.h"
#include <gtest/gtest.h>
#include <stdexcept>
//
//TEST(DnaSequenceBasicTests, stringDnaSequence) {
//    DnaSequence seq1("AATTCCGG");
//    ASSERT_TRUE(seq1.get_seq_length() > 3);
//}
//
//TEST(DnaSequenceBasicTests, charsDnaSequence) {
//    char *seq = (char *) "AACAGAC";
//    DnaSequence seq1(seq);
//    ASSERT_TRUE(seq1.get_seq_length() > 3);
//}
//TEST(DnaSequenceBasicTests, InstancDnaSequence) {
//    DnaSequence seq1("AATTCCGG");
//    DnaSequence seq2=seq1;
//    ASSERT_TRUE(seq1==seq2);
//}
//TEST(DnaSequenCopmerTests, eqDnaSequence) {
//    DnaSequence seq1("AATTCCGG");
//    DnaSequence seq2("AATTCCGG");
//    ASSERT_TRUE(seq1 == seq2);
//}
//
//TEST(DnaSequenCopmerTests, notEqDnaSequence) {
//    DnaSequence seq1("AATTCCGG");
//    DnaSequence seq2("AATTGCGG");
//    ASSERT_TRUE(seq1 != seq2);
//}
//TEST(DnaSequenTests, printDnaSequence) {
//    std::ostringstream out;
//    DnaSequence seq("ATATA");
//    out << seq;
//    EXPECT_EQ( "ATATA", out.str() );
//}
//int main(int argc, char *argv[]) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}

int main() {
    try {
        DnaSequence seq1("AATTCCGG");
        DnaSequence seq2 = seq1;

        std::cout << seq1 << seq2;
        std::cout << seq1[2];
        DnaSequence seq3("ATATA");

        std::cout << "\nseq3==seq2: " << (seq3 == seq2) << std::endl;
        std::cout << "\nseq3!=seq2: " << (seq3 != seq2) << std::endl;

        DnaSequence seq4="AGCTCGA";

        std::cout <<seq4<<std::endl;

        DnaSequence seq5="AGCLTCGA";
    }catch (const char * e){
        std::cout<<std::endl<<e<<std::endl;
    }
    return 0;
}