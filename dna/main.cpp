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
        DnaSequence seq1("AATTCCGGCCATCCATGCC");
        DnaSequence seq2 = seq1;
        DnaSequence seq6;
        seq6=seq2;
        std::cout << seq1 << seq2;
        std::cout << seq1[2];
        DnaSequence seq3("ATATA");

        std::cout << "\nseq3==seq2: " << (seq3 == seq2) << std::endl;
        std::cout << "\nseq3!=seq2: " << (seq3 != seq2) << std::endl;

        DnaSequence seq4= "AGCTCGA";

        DnaSequence subseq=seq4.get_sub_seq(0,4);

//        std::cout <<seq4<<std::endl;
//        std::cout <<"subseq:"<<subseq<<std::endl;
//        DnaSequence paird=seq1.get_complementary_seq();
//        std::cout <<seq1<<" complemantry seq: "<<paird<<std::endl;
////        DnaSequence fromFile=readSequenceFile("/home/shira/Desktop/simple-dna-sequence-ShiraZaltsman/dna/gen123.txt");
////        std::cout <<fromFile<<std::endl;
////        writeSequenceFile("/home/shira/Desktop/simple-dna-sequence-ShiraZaltsman/dna/outseq.txt",fromFile);
//
//        std::cout<<"find CC in seq1: "<<seq1.find("CC")<<std::endl;
//        std::cout<<"find CCC in seq1: "<<seq1.find("CCC")<<std::endl;

        std::cout<<"count CC in seq1: "<<seq1.Count("CC")<<std::endl;
        int* indexs=seq1.FindAll("CC");
        for (int i = 0; i < seq1.Count("CC"); ++i) {
            std::cout<<indexs[i]<<std::endl;
        }
        delete indexs;
    }catch (const char * e){
        std::cout<<std::endl<<e<<std::endl;
    }
    return 0;
}