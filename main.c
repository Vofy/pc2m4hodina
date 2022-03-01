#include <stdio.h>
#include <stdlib.h>

int main()
{
    char obrazovka[30][120]= {0};
    int center[2]= {15,60}, ctverec=20,obdelnik=5,trojuhelnik=6,rowcounter=0;
    char prepinac;

    for(;;)
    {
        fflush(stdin);
        scanf("%c", &prepinac);

        switch(prepinac)
        {
        case 'c':
            // Provede se pro kazdy radek
            for (int i=(center[0]-ctverec/2); i<(center[0]+ctverec/2+ctverec%2); i++)
            {
                // Pokud je rowcounter 0 nebo velikost odpovídá velikosti ètverce
                if (!rowcounter || rowcounter==ctverec-1)
                {
                    // Prvni a posledni radek
                    for (int j=(center[1]-ctverec/2); j<(center[1]+ctverec/2+ctverec%2); j++)
                        obrazovka[i][j]='*';
                }
                else
                {
                    // Meziradky
                    obrazovka[i][(center[1]-ctverec/2)]='*';
                    obrazovka[i][(center[1]+ctverec/2+ctverec%2)-1]='*';

                }

                // Pricte radek
                rowcounter++;
            }
            break;

        case 'o':
            for (int i=(center[0]-obdelnik/2); i<(center[0]+obdelnik/2+obdelnik%2); i++)
            {
                if (!rowcounter || rowcounter==obdelnik-1)
                {
                    for (int j=(center[1]-ctverec/2); j<(center[1]+ctverec/2+ctverec%2); j++)
                        obrazovka[i][j]='*';
                }
                else
                {
                    obrazovka[i][(center[1]-ctverec/2)]='*';
                    obrazovka[i][(center[1]+ctverec/2+ctverec%2)-1]='*';

                }

                rowcounter++;
            }
            break;

        case 't':
            for (int i=(center[0]-ctverec/2); i<(center[0]+ctverec/2+ctverec%2); i++)
            {
                if (rowcounter==ctverec-1)
                {
                    for (int j=(center[1]-ctverec/2); j<(center[1]+ctverec/2+ctverec%2); j++)
                        obrazovka[i][j]='*';
                }
                else
                {
                    obrazovka[i][(center[1]-ctverec/2)]='*';
                    obrazovka[i][(center[1]-ctverec/2+rowcounter)]='*';

                }

                rowcounter++;
            }

            break;
        case 'e':
            return 0;
        }

        for (int i =0; i<30; i++)
            for (int j=0; j<120; j++)
                printf("%c",obrazovka[i][j]);

        memset(obrazovka, 0, 30*120);
        rowcounter = 0;
    }

    return 0;
}
