template<typename... Rest>
class MultiDigit
{
private:

    //segment digits
    const char zero[5][3] = {{' ','-',' '}, {'|',' ','|'}, {' ',' ',' '}, {'|',' ','|'}, {' ','-',' '}};
    const char one[5][3] = {{' ',' ',' '}, {' ',' ','|'}, {' ',' ',' '}, {' ',' ','|'}, {' ',' ',' '}};
    const char two[5][3] = {{' ','-',' '}, {' ',' ','|'}, {' ','-',' '}, {'|',' ',' '}, {' ','-',' '}};
    const char three[5][3] = {{' ','-',' '}, {' ',' ','|'}, {' ','-',' '}, {' ',' ','|'}, {' ','-',' '}};
    const char four[5][3] = {{' ',' ',' '}, {'|',' ','|'}, {' ','-',' '}, {' ',' ','|'}, {' ',' ',' '}};
    const char five[5][3] = {{' ','-',' '}, {'|',' ',' '}, {' ','-',' '}, {' ',' ','|'}, {' ','-',' '}};
    const char six[5][3] = {{' ','-',' '}, {'|',' ',' '}, {' ','-',' '}, {'|',' ','|'}, {' ','-',' '}};
    const char seven[5][3] = {{' ','-',' '}, {' ',' ','|'}, {' ',' ',' '}, {' ',' ','|'}, {' ',' ',' '}};
    const char eight[5][3] = {{' ','-',' '}, {'|',' ','|'}, {' ','-',' '}, {'|',' ','|'}, {' ','-',' '}};
    const char nine[5][3] = {{' ','-',' '}, {'|',' ','|'}, {' ','-',' '}, {' ',' ','|'}, {' ','-',' '}};
    const char err[5][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ','-',' '}, {' ',' ',' '}, {' ',' ',' '}};
    
    //Größe Des Arrays berechnet sich wie folgt:
    //Anzahl Digits * 5 Zeilen * 3 Zeichen
    //+ 5 * Anzahl Leerzeichen zwischen Digits
    //+ 5 "\n"
    //+ 1 "\0"
    char digitString[(((sizeof...(Rest))*5*3)+(5*((sizeof...(Rest))-1))+5+1)];
    int digits[sizeof...(Rest)];

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
                    switch(num)
                    {
                       case 0:
                            digitString[writeCounter] = zero[i][j];
                            break;
                        case 1:
                            digitString[writeCounter] = one[i][j];
                            break;
                        case 2:
                            digitString[writeCounter] = two[i][j];
                            break;
                        case 3:
                            digitString[writeCounter] = three[i][j];
                            break;
                        case 4:
                            digitString[writeCounter] = four[i][j];
                            break;
                        case 5:
                            digitString[writeCounter] = five[i][j];
                            break;
                        case 6:
                            digitString[writeCounter] = six[i][j];
                            break;
                        case 7:
                            digitString[writeCounter] = seven[i][j];
                            break;
                        case 8:
                            digitString[writeCounter] = eight[i][j];
                            break;
                        case 9:
                            digitString[writeCounter] = nine[i][j];
                            break;
                        default:
                            digitString[writeCounter] = err[i][j];
                    }
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