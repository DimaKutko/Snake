#include "Best.hpp"
#include <stdio.h>


Best::Best(){
    FILE* rFile = fopen("MyRecord.txt", "rb");
    
    if (rFile == NULL)
    {
        record = 0;
        return;
    }
    
    fread(&record, sizeof(int), 1, rFile);
    
    fclose(rFile);
}

Best::~Best(){
    FILE* wFile = fopen("MyRecord.txt", "wb");
    
    if (wFile == NULL)return;
    
    fwrite(&record, sizeof(int), 1, wFile);
    
    fclose(wFile);
}

void Best::setBest(int points){
    if(points > record) record = points;
}

int Best::getBest(){
    return record;
}
