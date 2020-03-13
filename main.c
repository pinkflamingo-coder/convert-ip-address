#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned uFirstOktett, uSecondOktett, uThirdOktett, ufourthOktett;

int isNotValidIp(char *cIp);
int toBinary(int iNumber);
int toOctal(int iNumber);
char *toHexa(int iNumber);

int main () {
    char cIp[124];
    printf("enter a cIp address: ");
    scanf( "%s" , cIp );

    if (!isNotValidIp(cIp)) {
        printf("Binary: %i.%i.%i.%i\n", toBinary(uFirstOktett), toBinary(uSecondOktett), toBinary(uThirdOktett), toBinary(ufourthOktett));
        printf("Octal: %i.%i.%i.%i\n", toOctal(uFirstOktett), toOctal(uSecondOktett), toOctal(uThirdOktett), toOctal(ufourthOktett));
        printf("Hexadecimal: %s.%s.%s.%s\n", toHexa(uFirstOktett), toHexa(uSecondOktett), toHexa(uThirdOktett), toHexa(ufourthOktett));
    }
}

int isNotValidIp(char *cIp)
{

    int iLength, iSplitIp;
    unsigned char ucOverflow;

    iLength = strlen(cIp);

    if (iLength < 7 || iLength > 15) {
        printf("input is incorrect\n");
        return 1;
    }

    iSplitIp = sscanf(cIp, "%3u.%3u.%3u.%3u%c", &uFirstOktett, &uSecondOktett, &uThirdOktett, &ufourthOktett, &ucOverflow);

    if(iSplitIp != 4) {
        printf("input has invalid octets\n");
        return 1;
    }

    if ((uFirstOktett | uSecondOktett | ufourthOktett | ufourthOktett) > 255){
        printf("the octets are invalid\n");
        return 1;
    }
    return 0;
}

int toBinary(iNumber){

    int iLeftover, iResult =  0;
    int iFaktor = 1;

    while (iNumber) {
        iLeftover = iNumber % 2;
        iNumber /= 2;
        iFaktor *= 10;
        if(!iResult) {
            iResult = iLeftover * iFaktor;
        } else {
            iResult += iLeftover * iFaktor;
        }
    }

    return iResult;
}

int toOctal(int iNumber)
{

    int iOctalNumber = 0, iFaktor = 1;
    while (iNumber != 0)
    {
        iOctalNumber += (iNumber % 8) * iFaktor;
        iNumber /= 8;
        iFaktor *= 10;
    }
    return iOctalNumber;
}

char *toHexa(int iNumber){

    char *cHexadecimal = malloc(65 * sizeof(int));
    cHexadecimal = "0";
    char cValues[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int iIndex = 0;
    int iResidual;

   while (iNumber != 0){
		iResidual = iNumber % 16;
		iNumber = iNumber / 16;
		cHexadecimal[iIndex] = cValues[iResidual];
		iIndex++;
	}

    int iLength = strlen(cHexadecimal);

	char cTmp, i, cIndexOfHex;

	for(i=0, cIndexOfHex=iLength-1; i < cIndexOfHex; i++,cIndexOfHex--){
		cTmp = cHexadecimal[i];
		cHexadecimal[i] = cHexadecimal[cIndexOfHex];
		cHexadecimal[cIndexOfHex] = cTmp;
	}

	return cHexadecimal;
}
