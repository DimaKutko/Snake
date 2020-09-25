#pragma once

class Best{
public:
    Best();
    ~Best();
    
    void setBest(int points);
    int  getBest();
    
private:
    int record;
};
