#ifndef _7SEGMENT_H_

#define _7SEGMENT_H_

template<typename... Rest>
class MultiDigit
{
private:

    //segment digits
    static const char digitcode[10][5][3] = {{{' ','-',' '}, {'|',' ','|'}, {' ',' ',' '}, {'|',' ','|'}, {' ','-',' '}},
                                    {{' ',' ',' '}, {' ',' ','|'}, {' ',' ',' '}, {' ',' ','|'}, {' ',' ',' '}},
                                    {{' ','-',' '}, {' ',' ','|'}, {' ','-',' '}, {'|',' ',' '}, {' ','-',' '}},
                                    {{' ','-',' '}, {' ',' ','|'}, {' ','-',' '}, {' ',' ','|'}, {' ','-',' '}},
                                    {{' ',' ',' '}, {'|',' ','|'}, {' ','-',' '}, {' ',' ','|'}, {' ',' ',' '}},
                                    {{' ','-',' '}, {'|',' ',' '}, {' ','-',' '}, {' ',' ','|'}, {' ','-',' '}},
                                    {{' ','-',' '}, {'|',' ',' '}, {' ','-',' '}, {'|',' ','|'}, {' ','-',' '}},
                                    {{' ','-',' '}, {' ',' ','|'}, {' ',' ',' '}, {' ',' ','|'}, {' ',' ',' '}},
                                    {{' ','-',' '}, {'|',' ','|'}, {' ','-',' '}, {'|',' ','|'}, {' ','-',' '}},
                                    {{' ','-',' '}, {'|',' ','|'}, {' ','-',' '}, {' ',' ','|'}, {' ','-',' '}}};
    
    //Größe Des Arrays berechnet sich wie folgt:
    //Anzahl Digits * 5 Zeilen * 3 Zeichen
    //+ 5 * Anzahl Leerzeichen zwischen Digits
    //+ 5 "\n"
    //+ 1 "\0"
    //char digitString[(((sizeof...(Rest))*5*3)+(5*((sizeof...(Rest))-1))+5+1)];
    char digitString[(sizeof...(Rest) * 20)+1];
    const int digits[sizeof...(Rest)];

public:
    constexpr MultiDigit(Rest... rest):
    digitString{},
    digits{rest...}
    {
        if constexpr ((sizeof...(Rest))>0)
        {

        int writeCounter = 0;
        for(int i = 0; i<5; i++)
        {
            for(long unsigned int k = 0; k<(sizeof...(Rest)); k++)
            {
                int num = digits[k];
                for(int j = 0; j<3; j++)
                {
                    digitString[writeCounter] = digitcode[num][i][j];
                    writeCounter++;                
                }
                if(k<((sizeof...(Rest)-1)))
                {
                    digitString[writeCounter] = ' ';
                    writeCounter++;                   
                }
            }
            digitString[writeCounter] = '\n';
            writeCounter++;
        }
        digitString[writeCounter] = '\0';
        }
        else
        {
        }
    }

    operator const char*() const{
        
        return this->digitString;
    }

};

#endif