#include <iostream>
#include "control.h"

#include "files_stream_dna.h"


int main() {
    try {
        Control control;

        std::cout<<"Enter your command:"<<std::endl;
        std::string cmd,details;
        std::cin>>cmd;
        while(cmd!="quit"){

            std::getline(std::cin,details);

            if(cmd=="new"){
               control.addNewSeq(details);
            }
            else if(cmd=="load"){
                control.loadSeq(details);
            }
            else if(cmd=="save"){
                control.save(details);
            }
            else {
                std::cout<<"no sush command";
            }
            std::cout<<"Enter your command:"<<std::endl;
            std::cin>>cmd;
        }

        std::cout<<"goodbye!"<<std::endl;


        //control.addNewSeq(cmd);

//      DNAReader reader;
//      DnaSequence a= reader.readSequenceFile("/home/shira/Desktop/simple-dna-sequence-ShiraZaltsman/dna/gen123.txt");
//      std::cout<<a;

        }catch (const char * e){
        std::cout<<std::endl<<e<<std::endl;
    }
    return 0;
}