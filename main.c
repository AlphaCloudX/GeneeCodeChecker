#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/**
 * THESE ARE REQUIRED VARIABLES FOR THE ASSIGNMENT
 * NAMES MUST MATCH, IF THEY DON'T, YOU DON'T GET MARKS
 *
 */

#define SIZE 100
#define NUMPROTEINS 64

/**
 * THESE ARE REQUIRED PROTOTYPES FOR THE ASSIGNMENT
 * NAMES MUST MATCH, IF THEY DON'T, YOU DON'T GET MARKS
 *
 */
bool isBasePair(char neu1, char neu2);

bool isItaDnaSequence(char strand1[SIZE], char strand2[SIZE]);

void reverse(char sStrand[SIZE]);

void complementIt(char aStrand[SIZE]);

bool isItPalindrome(char aStrand[SIZE]);

bool isStrandDnaPalindrome(char aStrand[SIZE]);

int howMany(char aStrand[SIZE], char neu);

void dnaToMrna(char aSeq[SIZE], char mRNA[SIZE]);

void translateDnaToMrnaProteins(char aSeq[SIZE]);


/**
 * ALL TESTING OCCURS HERE
 */
int main() {

#ifdef _WIN32
    system("color");
    system("cls");
#else
    system("clear");
#endif

    //Printing welcome msg, just aesthetics
    printf("\n"
           "   __ _  ___ ___                                                                              \n"
           "  / _` |/ __/ __|                                                                             \n"
           " | (_| | (_| (__                                                                              \n"
           "  \\__, |\\___\\___|                                                                          \n"
           "   __/ |                                                                                      \n"
           "  |___/_                         _____          _         _____ _               _             \n"
           "  / ____|                       / ____|        | |       / ____| |             | |            \n"
           " | |  __  ___ _ __   ___  ___  | |     ___   __| | ___  | |    | |__   ___  ___| | _____ _ __ \n"
           " | | |_ |/ _ \\ '_ \\ / _ \\/ _ \\ | |    / _ \\ / _` |/ _ \\ | |    | '_ \\ / _ \\/ __| |/ / _ \\ '__|\n"
           " | |__| |  __/ | | |  __/  __/ | |___| (_) | (_| |  __/ | |____| | | |  __/ (__|   <  __/ |   \n"
           "  \\_____|\\___|_| |_|\\___|\\___|  \\_____\\___/ \\__,_|\\___|  \\_____|_| |_|\\___|\\___|_|\\_\\___|_|   \n"
           "                                                                                              \n"
           "1000+ Test Cases                                                                                           \n");


    //TEST CASES FOR PROTOTYPE 1
    //Check Cases for isBasePair method
    //EVERY SINGLE POSSIBLE COMBINATION FROM AA-ZZ
    char testcase_CaseIsBasePair[676][2] = {"AA", "AB", "AC", "AD", "AE", "AF", "AG", "AH", "AI", "AJ", "AK", "AL",
                                            "AM", "AN", "AO", "AP", "AQ", "AR", "AS", "AT", "AU", "AV", "AW", "AX",
                                            "AY", "AZ", "BA", "BB", "BC", "BD", "BE", "BF", "BG", "BH", "BI", "BJ",
                                            "BK", "BL", "BM", "BN", "BO", "BP", "BQ", "BR", "BS", "BT", "BU", "BV",
                                            "BW", "BX", "BY", "BZ", "CA", "CB", "CC", "CD", "CE", "CF", "CG", "CH",
                                            "CI", "CJ", "CK", "CL", "CM", "CN", "CO", "CP", "CQ", "CR", "CS", "CT",
                                            "CU", "CV", "CW", "CX", "CY", "CZ", "DA", "DB", "DC", "DD", "DE", "DF",
                                            "DG", "DH", "DI", "DJ", "DK", "DL", "DM", "DN", "DO", "DP", "DQ", "DR",
                                            "DS", "DT", "DU", "DV", "DW", "DX", "DY", "DZ", "EA", "EB", "EC", "ED",
                                            "EE", "EF", "EG", "EH", "EI", "EJ", "EK", "EL", "EM", "EN", "EO", "EP",
                                            "EQ", "ER", "ES", "ET", "EU", "EV", "EW", "EX", "EY", "EZ", "FA", "FB",
                                            "FC", "FD", "FE", "FF", "FG", "FH", "FI", "FJ", "FK", "FL", "FM", "FN",
                                            "FO", "FP", "FQ", "FR", "FS", "FT", "FU", "FV", "FW", "FX", "FY", "FZ",
                                            "GA", "GB", "GC", "GD", "GE", "GF", "GG", "GH", "GI", "GJ", "GK", "GL",
                                            "GM", "GN", "GO", "GP", "GQ", "GR", "GS", "GT", "GU", "GV", "GW", "GX",
                                            "GY", "GZ", "HA", "HB", "HC", "HD", "HE", "HF", "HG", "HH", "HI", "HJ",
                                            "HK", "HL", "HM", "HN", "HO", "HP", "HQ", "HR", "HS", "HT", "HU", "HV",
                                            "HW", "HX", "HY", "HZ", "IA", "IB", "IC", "ID", "IE", "IF", "IG", "IH",
                                            "II", "IJ", "IK", "IL", "IM", "IN", "IO", "IP", "IQ", "IR", "IS", "IT",
                                            "IU", "IV", "IW", "IX", "IY", "IZ", "JA", "JB", "JC", "JD", "JE", "JF",
                                            "JG", "JH", "JI", "JJ", "JK", "JL", "JM", "JN", "JO", "JP", "JQ", "JR",
                                            "JS", "JT", "JU", "JV", "JW", "JX", "JY", "JZ", "KA", "KB", "KC", "KD",
                                            "KE", "KF", "KG", "KH", "KI", "KJ", "KK", "KL", "KM", "KN", "KO", "KP",
                                            "KQ", "KR", "KS", "KT", "KU", "KV", "KW", "KX", "KY", "KZ", "LA", "LB",
                                            "LC", "LD", "LE", "LF", "LG", "LH", "LI", "LJ", "LK", "LL", "LM", "LN",
                                            "LO", "LP", "LQ", "LR", "LS", "LT", "LU", "LV", "LW", "LX", "LY", "LZ",
                                            "MA", "MB", "MC", "MD", "ME", "MF", "MG", "MH", "MI", "MJ", "MK", "ML",
                                            "MM", "MN", "MO", "MP", "MQ", "MR", "MS", "MT", "MU", "MV", "MW", "MX",
                                            "MY", "MZ", "NA", "NB", "NC", "ND", "NE", "NF", "NG", "NH", "NI", "NJ",
                                            "NK", "NL", "NM", "NN", "NO", "NP", "NQ", "NR", "NS", "NT", "NU", "NV",
                                            "NW", "NX", "NY", "NZ", "OA", "OB", "OC", "OD", "OE", "OF", "OG", "OH",
                                            "OI", "OJ", "OK", "OL", "OM", "ON", "OO", "OP", "OQ", "OR", "OS", "OT",
                                            "OU", "OV", "OW", "OX", "OY", "OZ", "PA", "PB", "PC", "PD", "PE", "PF",
                                            "PG", "PH", "PI", "PJ", "PK", "PL", "PM", "PN", "PO", "PP", "PQ", "PR",
                                            "PS", "PT", "PU", "PV", "PW", "PX", "PY", "PZ", "QA", "QB", "QC", "QD",
                                            "QE", "QF", "QG", "QH", "QI", "QJ", "QK", "QL", "QM", "QN", "QO", "QP",
                                            "QQ", "QR", "QS", "QT", "QU", "QV", "QW", "QX", "QY", "QZ", "RA", "RB",
                                            "RC", "RD", "RE", "RF", "RG", "RH", "RI", "RJ", "RK", "RL", "RM", "RN",
                                            "RO", "RP", "RQ", "RR", "RS", "RT", "RU", "RV", "RW", "RX", "RY", "RZ",
                                            "SA", "SB", "SC", "SD", "SE", "SF", "SG", "SH", "SI", "SJ", "SK", "SL",
                                            "SM", "SN", "SO", "SP", "SQ", "SR", "SS", "ST", "SU", "SV", "SW", "SX",
                                            "SY", "SZ", "TA", "TB", "TC", "TD", "TE", "TF", "TG", "TH", "TI", "TJ",
                                            "TK", "TL", "TM", "TN", "TO", "TP", "TQ", "TR", "TS", "TT", "TU", "TV",
                                            "TW", "TX", "TY", "TZ", "UA", "UB", "UC", "UD", "UE", "UF", "UG", "UH",
                                            "UI", "UJ", "UK", "UL", "UM", "UN", "UO", "UP", "UQ", "UR", "US", "UT",
                                            "UU", "UV", "UW", "UX", "UY", "UZ", "VA", "VB", "VC", "VD", "VE", "VF",
                                            "VG", "VH", "VI", "VJ", "VK", "VL", "VM", "VN", "VO", "VP", "VQ", "VR",
                                            "VS", "VT", "VU", "VV", "VW", "VX", "VY", "VZ", "WA", "WB", "WC", "WD",
                                            "WE", "WF", "WG", "WH", "WI", "WJ", "WK", "WL", "WM", "WN", "WO", "WP",
                                            "WQ", "WR", "WS", "WT", "WU", "WV", "WW", "WX", "WY", "WZ", "XA", "XB",
                                            "XC", "XD", "XE", "XF", "XG", "XH", "XI", "XJ", "XK", "XL", "XM", "XN",
                                            "XO", "XP", "XQ", "XR", "XS", "XT", "XU", "XV", "XW", "XX", "XY", "XZ",
                                            "YA", "YB", "YC", "YD", "YE", "YF", "YG", "YH", "YI", "YJ", "YK", "YL",
                                            "YM", "YN", "YO", "YP", "YQ", "YR", "YS", "YT", "YU", "YV", "YW", "YX",
                                            "YY", "YZ", "ZA", "ZB", "ZC", "ZD", "ZE", "ZF", "ZG", "ZH", "ZI", "ZJ",
                                            "ZK", "ZL", "ZM", "ZN", "ZO", "ZP", "ZQ", "ZR", "ZS", "ZT", "ZU", "ZV",
                                            "ZW", "ZX", "ZY", "ZZ"};

    //ANSWERS FOR EACH CASE
    //0--> false expected
    //1--> true expected
    int answerSet_IsBasePair[676] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //What method we are testing
    printf("\nChecking Method 1 | bool isBasePair (char neu1, char neu2);");
    printf("\n--------------------------\n");

    //We have 0 errors
    int error = 0;

    //Output from method
    int boolOut;

    //Loop for each test case
    for (int i = 0; i < 676; i++) {

        //Output from method
        boolOut = isBasePair(testcase_CaseIsBasePair[i][0], testcase_CaseIsBasePair[i][1]);

        //Print test
        printf("[CHECKING] | %c%c | [EXPECTED: %d | GOT: %d] | ", testcase_CaseIsBasePair[i][0],
               testcase_CaseIsBasePair[i][1], answerSet_IsBasePair[i], boolOut);


        //Print if it passed or failed
        if (boolOut != answerSet_IsBasePair[i]) {
            error++;
            printf("\033[31m[FAILED])\033[0m\n");

        } else {
            printf("\033[32m[PASSED]\033[0m\n");

        }


    }
    //Output any errors
    if (error > 0) {
        printf("--------------------------------\n");
        printf("\033[31m[!FAILED!] | %d ERROR(S)\033[0m\n", error);
        printf("--------------------------------\n");
    } else {
        printf("--------------------------------\n");
        printf("\033[32m[PASSED NO ERRORS FOUND]\033[0m\n");
        printf("--------------------------------\n");
    }

    //reset error count
    error = 0;

    //Clear the array, don't need it in memory anymore:
    memset(testcase_CaseIsBasePair, 0, sizeof(testcase_CaseIsBasePair));
    memset(answerSet_IsBasePair, 0, sizeof(answerSet_IsBasePair));

    //From: https://stackoverflow.com/a/1406432
    printf("Press enter to continue\n");
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    //Test cases for checking if something is a dna sequence
    //Left string is seq1, Right string is seq2
    //So AT, CG...
    char testcase_isItaDnaSequence[121][2][SIZE] = {
            {"A",          "T"},
            {"C",          "G"},
            {"A",          "G"},
            {"AAA",        "TTT"},
            {"AAC",        "GTT"},
            {"TAA",        "ATT"},
            {"CCA",        "GGT"},
            {"GGC",        "CCG"},
            {"AGT",        "TCA"},
            {"TCG",        "CGA"},
            {"CGA",        "TGC"},
            {"ACT",        "TGA"},
            {"TGC",        "CGA"},
            {"CGT",        "GCG"},
            {"TAC",        "ATG"},
            {"AGC",        "TCG"},
            {"CTA",        "TAG"},
            {"GAC",        "CTG"},
            {"ATG",        "CAT"},
            {"CTG",        "GAC"},
            {"TGC",        "CGA"},
            {"GTC",        "CAG"},
            {"GCT",        "AGC"},
            {"GAA",        "TTC"},
            {"GAG",        "CTC"},
            {"ACC",        "GGT"},
            {"TTG",        "CAA"},
            {"AGT",        "TCA"},
            {"CTT",        "AAG"},
            {"TCC",        "GGA"},
            {"AAC",        "GTT"},
            {"CTA",        "TAG"},
            {"GTG",        "CAC"},
            {"GCG",        "CGC"},
            {"CAT",        "ATG"},
            {"TGA",        "ACT"},
            {"GTG",        "CAC"},
            {"TCC",        "GGA"},
            {"GAA",        "TTC"},
            {"GAG",        "CTC"},
            {"ACC",        "GGT"},
            {"TTG",        "CAA"},
            {"GCT",        "AGC"},
            {"TGT",        "ACA"},
            {"TTT",        "AAA"},
            {"CCA",        "GGT"},
            {"AGG",        "CCT"},
            {"TTA",        "TAA"},
            {"TGG",        "CCA"},
            {"ATA",        "TAT"},
            {"CGC",        "GCG"},
            {"CCG",        "GGC"},
            {"AGC",        "TCG"},
            {"GAA",        "TTC"},
            {"ACT",        "TGA"},
            {"GCT",        "AGC"},
            {"GGA",        "CCT"},
            {"TCA",        "AGT"},
            {"AAG",        "CTT"},
            {"TCG",        "CGA"},
            {"CAG",        "GTC"},
            {"TAC",        "ATG"},
            {"AAC",        "GTT"},
            {"AGT",        "TCA"},
            {"GTC",        "CAG"},
            {"ATG",        "CAT"},
            {"ACC",        "GGT"},
            {"TGC",        "CGA"},
            {"CGT",        "GCG"},
            {"CTA",        "TAG"},
            {"GAC",        "CTG"},
            {"CTG",        "GAC"},
            {"TGC",        "CGA"},
            {"GTC",        "CAG"},
            {"GCT",        "AGC"},
            {"GAA",        "TTC"},
            {"GAG",        "CTC"},
            {"ACC",        "GGT"},
            {"TTG",        "CAA"},
            {"AGT",        "TCA"},
            {"CTT",        "AAG"},
            {"TCC",        "GGA"},
            {"AAC",        "GTT"},
            {"CTA",        "TAG"},
            {"GTG",        "CAC"},
            {"GCG",        "CGC"},
            {"CAT",        "ATG"},
            {"TGA",        "ACT"},
            {"GTG",        "CAC"},
            {"TCC",        "GGA"},
            {"GAA",        "TTC"},
            {"GAG",        "CTC"},
            {"ACC",        "GGT"},
            {"TTG",        "CAA"},
            {"GCT",        "AGC"},
            {"TGT",        "ACA"},
            {"TTT",        "AAA"},
            {"CCA",        "GGT"},
            {"AGG",        "CCT"},
            {"TTA",        "TAA"},
            {"TGG",        "CCA"},
            {"ATA",        "TAT"},
            {"CGC",        "GCG"},
            {"CCG",        "GGC"},
            {"AGC",        "TCG"},
            {"GAA",        "TTC"},
            {"ACT",        "TGA"},
            {"GCT",        "AGC"},
            {"GGA",        "CCT"},
            {"TCA",        "AGT"},
            {"AAG",        "CTT"},
            {"TCG",        "CGA"},
            {"CAG",        "GTC"},
            {"TAC",        "ATG"},
            {"CGTA",       "TACG"},
            {"ATGCAGTACG", "TACGTCACTG"},
            {"AGTCAGTCACTGACTCGTACGTACGTGCTAGCTACGTCGCTAGTAGTAGTCGTAGTCTAGTAGTCGTAGTCTAGTCACTGACTAGTCACTAGTCACTAG",
                           "TCAGTCAGTGACTGACTGCATGCATGCATCGATGCACTAGCTATCATCATCGACTCATCAGACTCATCAGACTCATGACTGACTCATGACTCATGACTC"},
            {"AAGTCTAGTCGTCAGTCACTGACTGACTGCATGCTAGTCAGTCACTGACTGACTGCATGCTAGTCAGTCACTGACTGACTGCATGCTAGTCAGTCACTG",
                           "TTCAGATCAGCAGGTCAGTGACTGCATCGACTAGTCAGATCAGCAGGTCAGTGACTGCATCGACTAGTCAGATCAGCAGGTCAGTGACTGCATCGACTA"},
            {"ATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
                           "TATTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT"},
            {"TTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTA",
                           "AATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGAT"},
            {"TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT",
                           "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"},
    };

    //Answer set for the above array
    //0 --> false
    //1 --> true
    //each index is for each index above
    int answerSet_isItaDnaSequence[] = {1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0,
                                        1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0,
                                        1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0,
                                        0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0,
                                        1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1};


    //Checking prototype 2
    printf("\nChecking Method 2 | bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]);");
    printf("\n--------------------------\n");

    //Looping for each test case
    for (int i = 0; i < 121; i++) {

        //Outputting input
        printf("[STRAND 1]:%s\n", testcase_isItaDnaSequence[i][0]);
        printf("[STRAND 2]:%s\n", testcase_isItaDnaSequence[i][1]);

        //Output from isItDnaSequence
        boolOut = isItaDnaSequence(testcase_isItaDnaSequence[i][0], testcase_isItaDnaSequence[i][1]);

        //Print test
        printf("[EXPECTED: %d | GOT: %d] | ", answerSet_isItaDnaSequence[i], boolOut);

        //Check if the bool output is the same as from the answer set
        if (boolOut != answerSet_isItaDnaSequence[i]) {
            error++;
            printf("\033[31m[FAILED])\033[0m\n\n");

        } else {
            printf("\033[32m[PASSED]\033[0m\n\n");

        }
    }

    //Output any errors
    if (error > 0) {
        printf("--------------------------------\n");
        printf("\033[31m[!FAILED!] | %d ERROR(S)\033[0m\n", error);
        printf("--------------------------------\n");
    } else {
        printf("--------------------------------\n");
        printf("\033[32m[PASSED NO ERRORS FOUND]\033[0m\n");
        printf("--------------------------------\n");
    }


    error = 0;

    //Clear the array:
    memset(testcase_isItaDnaSequence, 0, sizeof(testcase_isItaDnaSequence));
    memset(answerSet_isItaDnaSequence, 0, sizeof(answerSet_isItaDnaSequence));

    //From: https://stackoverflow.com/a/1406432
    printf("Press enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    //Reverse method test cases
    //Left is what needs to be reversed, right side is the correct output
    char testcase_reverse[14][2][SIZE] = {{"A",        "A"},
                                          {"GT",       "TG"},
                                          {"ACT",      "TCA"},
                                          {"GCTA",     "ATCG"},
                                          {"$ACGT",    "TGCA$"},
                                          {"12345",    "54321"},
                                          {"!@#$%^&*", "*&^%$#@!"},
                                          {"AGCTAGC",  "CGATCGA"},
                                          {"GATCGATC", "CTAGCTAG"},
                                          {"GTCAGTCACTGACTCGTACGTACGTGCTAGCTACGTCGCTAGTAGTAGTCGTAGTCTAGTAGTCGTAGTCTAGTCACTGACTAGTCACTAGTCACTAGT",
                                                       "TGATCACTGATCACTGATCAGTCACTGATCTGATGCTGATGATCTGATGCTGATGATGATCGCTGCATCGATCGTGCATGCATGCTCAGTCACTGACTG"},
                                          {"AGTCTAGTCGTCAGTCACTGACTGACTGCATGCTAGTCAGTCACTGACTGACTGCATGCTAGTCAGTCACTGACTGACTGCATGCTAGTCAGTCACTGA",
                                                       "AGTCACTGACTGATCGTACGTCAGTCAGTCACTGACTGATCGTACGTCAGTCAGTCACTGACTGATCGTACGTCAGTCAGTCACTGACTGCTGATCTGA"},
                                          {"ACGTCGCTGACTGCAGTGCTGACTGCTAGCTGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTA",
                                                       "ATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGTCGATCGTCAGTCGTGACGTCAGTCGCTGCA"},
                                          {"ACTCGTCACGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTCGACTC",
                                                       "CTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCTCAGCACTGCTCA"},
                                          {"GTTGCACTGACTGCATGCACTGCACTGACTGCATGCACTGCACTGACTICATGCACTGCACTGACTGCATGCACTGCACTGACTGCATGCACTGCACTG",
                                                       "GTCACGTCACGTACGTCAGTCACGTCACGTACGTCAGTCACGTCACGTACITCAGTCACGTCACGTACGTCAGTCACGTCACGTACGTCAGTCACGTTG"}};

    //Testing method 3
    printf("\nChecking Method 3 | void reverse (char aStrand [SIZE]);");
    printf("\n--------------------------\n");

    //Loop for each test case
    for (int i = 0; i < 14; i++) {

        //Outputting input
        printf("[CHECKING INPUT   ]:%s\n", testcase_reverse[i][0]);

        //Reversing
        reverse(testcase_reverse[i][0]);
        //Outputting the reversed
        printf("[CHECKING Reverse ]:%s\n", testcase_reverse[i][0]);
        //Outputting the expected
        printf("[CHECKING EXPECTED]:%s\n", testcase_reverse[i][1]);


        //Compare the outputs
        if (strcmp(testcase_reverse[i][0], testcase_reverse[i][1]) != 0) {
            error++;
            printf("\033[31m[FAILED])\033[0m\n\n");

        } else {
            printf("\033[32m[PASSED]\033[0m\n\n");

        }


    }

    //Output any errors
    if (error > 0) {
        printf("--------------------------------\n");
        printf("\033[31m[!FAILED!] | %d ERROR(S)\033[0m\n", error);
        printf("--------------------------------\n");
    } else {
        printf("--------------------------------\n");
        printf("\033[32m[PASSED NO ERRORS FOUND]\033[0m\n");
        printf("--------------------------------\n");
    }

    error = 0;

    //Clear the array:
    memset(testcase_reverse, 0, sizeof(testcase_reverse));

    //From: https://stackoverflow.com/a/1406432
    printf("Press enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    //Checking prototype 4
    printf("\nChecking Method 4 | void complementIt (char aStrand [SIZE]);");
    printf("\n--------------------------\n");

    //Test cases
    //left is the input, right is the expected complement
    char testcase_complementIt[23][2][SIZE] = {{"A",                                                                                                   "T"},
                                               {"AT",                                                                                                  "TA"},
                                               {"GAT",                                                                                                 "CTA"},
                                               {"GCTA",                                                                                                "CGAT"},
                                               {"AGCTA",                                                                                               "TCGAT"},
                                               {"AGCTAG",                                                                                              "TCGATC"},
                                               {"AGCTAGC",                                                                                             "TCGATCG"},
                                               {"GGCTAGCT",                                                                                            "CCGATCGA"},
                                               {"AAGCTAGCTA",                                                                                          "TTCGATCGAT"},
                                               {"CTAGCTAGCTAGC",                                                                                       "GATCGATCGATCG"},
                                               {"GGCTAGCTAGCTAGC",                                                                                     "CCGATCGATCGATCG"},
                                               {"AAGCTAGCTAGCTAGC",                                                                                    "TTCGATCGATCGATCG"},
                                               {"GCTAGCTAGCTAGCTAGC",                                                                                  "CGATCGATCGATCGATCG"},
                                               {"GGCTAGCTAGCTAGCTAGCTA",                                                                               "CCGATCGATCGATCGATCGAT"},
                                               {"AAGCTAGCTAGCTAGCTAGCTAGC",                                                                            "TTCGATCGATCGATCGATCGATCG"},
                                               {"GGCTAGCTAGCTAGCTAGCTAGCTAGCT",                                                                        "CCGATCGATCGATCGATCGATCGATCGA"},
                                               {"AAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC",                                                                    "TTCGATCGATCGATCGATCGATCGATCGATCG"},
                                               {"GGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTA",                                                                   "CCGATCGATCGATCGATCGATCGATCGATCGAT"},
                                               {"AAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC",                                                                "TTCGATCGATCGATCGATCGATCGATCGATCGATCG"},
                                               {"GGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC",                                                             "CCGATCGATCGATCGATCGATCGATCGATCGATCGATCG"},
                                               {"AAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC",                                                            "TTCGATCGATCGATCGATCGATCGATCGATCGATCGATCG"},
                                               {"GGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC",                                                         "CCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCG"},
                                               {"ATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATA", "TATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATATAT"},};

    //Loop for each test case
    for (int i = 0; i < 23; i++) {

        //Outputting input
        printf("[CHECKING INPUT   ]:%s\n", testcase_complementIt[i][0]);

        //Complementing
        complementIt(testcase_complementIt[i][0]);

        //Outputting the reversed
        printf("[CHECKING Reverse ]:%s\n", testcase_complementIt[i][0]);
        //Outputting the expected
        printf("[CHECKING EXPECTED]:%s\n", testcase_complementIt[i][1]);


        //Check if the complement is same as expected complement
        if (strcmp(testcase_complementIt[i][0], testcase_complementIt[i][1]) != 0) {
            error++;
            printf("\033[31m[FAILED])\033[0m\n\n");

        } else {
            printf("\033[32m[PASSED]\033[0m\n\n");

        }

    }

    //Output any errors
    if (error > 0) {
        printf("--------------------------------\n");
        printf("\033[31m[!FAILED!] | %d ERROR(S)\033[0m\n", error);
        printf("--------------------------------\n");
    } else {
        printf("--------------------------------\n");
        printf("\033[32m[PASSED NO ERRORS FOUND]\033[0m\n");
        printf("--------------------------------\n");
    }

    error = 0;

    //Clear the array:
    memset(testcase_complementIt, 0, sizeof(testcase_complementIt));

    //From: https://stackoverflow.com/a/1406432
    printf("Press enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    //Method 5 test cases
    printf("\nChecking Method 5 | bool isItPalindrome (char aStrand [SIZE]);");
    printf("\n--------------------------\n");

    //Test cases for isItPalindrome
    char testcase_isItPalindrome[25][SIZE] = {
            "",
            "radar",
            "level",
            "civic",
            "deed",
            "kayak",
            "racecar",
            "rotor",
            "madam",
            "refer",
            "reviver",
            "noon",
            "tenet",
            "malayalam",
            "minim",
            "radar",
            "civic",
            "kayak",
            "racecar",
            "rotor",
            "madam",
            "$$%",
            "A",
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB"

    };

    // 0 --> false
    // 1--> true
    int answerSet_isItPalindrome[25] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0};

    for (int i = 0; i < 25; i++) {

        //Outputting input
        printf("[CHECKING INPUT]:%s\n", testcase_isItPalindrome[i]);

        boolOut = ((int) isItPalindrome(testcase_isItPalindrome[i]));

        //Print test
        printf("[EXPECTED: %d | GOT: %d] | ", answerSet_isItPalindrome[i], boolOut);


        //Check if it matches answer key
        if (boolOut != answerSet_isItPalindrome[i]) {
            error++;
            printf("\033[31m[FAILED])\033[0m\n\n");

        } else {
            printf("\033[32m[PASSED]\033[0m\n\n");

        }
    }

    //Output any errors
    if (error > 0) {
        printf("--------------------------------\n");
        printf("\033[31m[!FAILED!] | %d ERROR(S)\033[0m\n", error);
        printf("--------------------------------\n");
    } else {
        printf("--------------------------------\n");
        printf("\033[32m[PASSED NO ERRORS FOUND]\033[0m\n");
        printf("--------------------------------\n");
    }

    error = 0;


    //Clear the array:
    memset(testcase_isItPalindrome, 0, sizeof(testcase_isItPalindrome));
    memset(answerSet_isItPalindrome, 0, sizeof(answerSet_isItPalindrome));

    //From: https://stackoverflow.com/a/1406432
    printf("Press enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    //Prototype 6 test
    printf("\nChecking Method 6 | bool isStrandDnaPalindrome (char aStrand [SIZE]);");
    printf("\n--------------------------\n");

    //Test cases for is it dna palindrome
    char testcase_isStrandDnaPalindrome[24][SIZE] = {
            "ATCGT",
            "GCTAGC",
            "TCGGCT",
            "ATTTA",
            "GCATCG",
            "TCCGAACGGAAGCCT",
            "AGCTAGCTAGCT",
            "GATCGATCGATC",
            "TATCGGCGTAT",
            "CCTTTAGTCC",
            "ATCGATC",
            "GCCTACGGTCCAGGTCG",
            "TATGCATCGCTA",
            "CGAGAGAGC",
            "TCGTAATGCTACGAACGT",
            "AGGCGGACGGAGGCGG",
            "TGAGAGGTGATCTC",
            "CCAGTGAGTAGGCCTG",
            "GGGGG",
            "AAAAA",
            "T",
            "AAAAAAAAAATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
            "AT",

    };

    //0 --> false
    //1 --> true
    int answerSet_isStrandDnaPalindrome[24] = {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    //Loop for each test case
    for (int i = 0; i < 24; i++) {

        //Store output into boolout
        boolOut = ((int) isStrandDnaPalindrome(testcase_isStrandDnaPalindrome[i]));

        //Print test
        printf("[CHECKING] | %s\n[EXPECTED: %d | GOT: %d] | ", testcase_isStrandDnaPalindrome[i],
               answerSet_isStrandDnaPalindrome[i], boolOut);

        if (boolOut != answerSet_isStrandDnaPalindrome[i]) {
            error++;
            printf("\033[31m[FAILED])\033[0m\n\n");

        } else {
            printf("\033[32m[PASSED]\033[0m\n\n");

        }
    }

    //Output any errors
    if (error > 0) {
        printf("--------------------------------\n");
        printf("\033[31m[!FAILED!] | %d ERROR(S)\033[0m\n", error);
        printf("--------------------------------\n");
    } else {
        printf("--------------------------------\n");
        printf("\033[32m[PASSED NO ERRORS FOUND]\033[0m\n");
        printf("--------------------------------\n");
    }


    error = 0;

    //Clear the array:
    memset(testcase_isItPalindrome, 0, sizeof(testcase_isItPalindrome));
    memset(answerSet_isItPalindrome, 0, sizeof(answerSet_isItPalindrome));

    //From: https://stackoverflow.com/a/1406432
    printf("Press enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    //Method 7 test
    printf("\nChecking Method 7 | int howMany (char aStrand [SIZE], char neu);");
    printf("\n--------------------------\n");

    char testcase_howMany[6][SIZE] = {"G", "GGG", "GGCCGG", "T",
                                      "AAAAAAAAAATAAAAAAAAAGGGGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAALAAAAAA_WHY_AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG",
                                      "$DKJHB*#&GR&#^G&D^B@BD(BD#&*B(D$#B)*&YB)*D@B*)@DB&*)&B*@)D"};

    int answers_howMany[6] = {1, 3, 4, 0, 5, 2};

    for (int i = 0; i < 6; i++) {

        //Store output into boolout
        boolOut = ((int) howMany(testcase_howMany[i], 'G'));

        //Print test
        printf("[CHECKING | \"G\"] | %s\n[EXPECTED: %d | GOT: %d] | ", testcase_howMany[i],
               answers_howMany[i], boolOut);

        if (boolOut != answers_howMany[i]) {
            error++;
            printf("\033[31m[FAILED])\033[0m\n\n");

        } else {
            printf("\033[32m[PASSED]\033[0m\n\n");

        }
    }

    //Output any errors
    if (error > 0) {
        printf("--------------------------------\n");
        printf("\033[31m[!FAILED!] | %d ERROR(S)\033[0m\n", error);
        printf("--------------------------------\n");
    } else {
        printf("--------------------------------\n");
        printf("\033[32m[PASSED NO ERRORS FOUND]\033[0m\n");
        printf("--------------------------------\n");
    }

    //Clear the array:
    memset(testcase_howMany, 0, sizeof(testcase_howMany));
    memset(answers_howMany, 0, sizeof(answers_howMany));

    error = 0;

    //From: https://stackoverflow.com/a/1406432
    printf("Press enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    //Method 8 test
    printf("\nChecking Method 8 | void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]);");
    printf("\n--------------------------\n");

    //Test cases
    //left is the strand1, right is the strand2
    char testcase_dnaToMrna[40][SIZE] = {"A", "T",
                                         "AT", "TA",
                                         "GAT", "CTA",
                                         "GCTA", "CGAT",
                                         "AGCTA", "TCGAT",
                                         "AGCTAG", "TCGATC",
                                         "AGCTAGC", "TCGATCG",
                                         "GGCTAGCT", "CCGATCGA",
                                         "AAGCTAGCTA", "TTCGATCGAT",
                                         "CTAGCTAGCTAGC", "GATCGATCGATCG",
                                         "GGCTAGCTAGCTAGC", "CCGATCGATCGATCG",
                                         "AAGCTAGCTAGCTAGC", "TTCGATCGATCGATCG",
                                         "GCTAGCTAGCTAGCTAGC", "CGATCGATCGATCGATCG",
                                         "GGCTAGCTAGCTAGCTAGCTA", "CCGATCGATCGATCGATCGAT",
                                         "AAGCTAGCTAGCTAGCTAGCTAGC", "TTCGATCGATCGATCGATCGATCG",
                                         "GGCTAGCTAGCTAGCTAGCTAGCTAGCT", "CCGATCGATCGATCGATCGATCGATCGA",
                                         "AAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC", "TTCGATCGATCGATCGATCGATCGATCGATCG",
                                         "GGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTA", "CCGATCGATCGATCGATCGATCGATCGATCGAT",
                                         "AAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC",
                                         "TTCGATCGATCGATCGATCGATCGATCGATCGATCG",
                                         "AAAAAAAAAATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
                                         "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",};

    char answers_dnaToMrna[40][SIZE] = {"U", "A", "UA", "AU", "CUA", "GAU", "CGAU", "GCUA", "UCGAU", "AGCUA", "UCGAUC",
                                        "AGCUAG", "UCGAUCG", "AGCUAGC", "CCGAUCGA", "GGCUAGCU", "UUCGAUCGAU",
                                        "AAGCUAGCUA", "GAUCGAUCGAUCG", "CUAGCUAGCUAGC", "CCGAUCGAUCGAUCG",
                                        "GGCUAGCUAGCUAGC", "UUCGAUCGAUCGAUCG", "AAGCUAGCUAGCUAGC", "CGAUCGAUCGAUCGAUCG",
                                        "GCUAGCUAGCUAGCUAGC", "CCGAUCGAUCGAUCGAUCGAU", "GGCUAGCUAGCUAGCUAGCUA",
                                        "UUCGAUCGAUCGAUCGAUCGAUCG", "AAGCUAGCUAGCUAGCUAGCUAGC",
                                        "CCGAUCGAUCGAUCGAUCGAUCGAUCGA", "GGCUAGCUAGCUAGCUAGCUAGCUAGCU",
                                        "UUCGAUCGAUCGAUCGAUCGAUCGAUCGAUCG", "AAGCUAGCUAGCUAGCUAGCUAGCUAGCUAGC",
                                        "CCGAUCGAUCGAUCGAUCGAUCGAUCGAUCGAU", "GGCUAGCUAGCUAGCUAGCUAGCUAGCUAGCUA",
                                        "UUCGAUCGAUCGAUCGAUCGAUCGAUCGAUCGAUCG", "AAGCUAGCUAGCUAGCUAGCUAGCUAGCUAGCUAGC",
                                        "UUUUUUUUUUAUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
                                        "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU"};

    char mRNAHolding[SIZE];

    for (int i = 0; i < 40; i++) {

        //Print test
        //Outputting input
        printf("[CHECKING INPUT   ]:%s\n", testcase_dnaToMrna[i]);

        //DNa --> MRNA
        //NOT SURE IF mRNAHolding FROM TA'S TEST CASES IS CLEARED OR IF WE NEED TO CLEAR...
        dnaToMrna(testcase_dnaToMrna[i], mRNAHolding);

        //Outputting the reversed
        printf("[CHECKING Sequence]:%s\n", mRNAHolding);
        //Outputting the expected
        printf("[CHECKING EXPECTED]:%s\n", answers_dnaToMrna[i]);

        if (strcmp(mRNAHolding, answers_dnaToMrna[i]) != 0) {
            error++;
            printf("\033[31m[FAILED])\033[0m\n\n");

        } else {
            printf("\033[32m[PASSED]\033[0m\n\n");

        }

        //Clear the mRNAHolding String to prevent issues of left over strings staying
        memset(mRNAHolding, 0, sizeof(mRNAHolding));

    }

    //Output any errors
    if (error > 0) {
        printf("--------------------------------\n");
        printf("\033[31m[!FAILED!] | %d ERROR(S)\033[0m\n", error);
        printf("--------------------------------\n");
    } else {
        printf("--------------------------------\n");
        printf("\033[32m[PASSED NO ERRORS FOUND]\033[0m\n");
        printf("--------------------------------\n");
    }

    //Clear the array:
    memset(testcase_dnaToMrna, 0, sizeof(testcase_dnaToMrna));
    memset(answers_dnaToMrna, 0, sizeof(answers_dnaToMrna));

    error = 0;

    //From: https://stackoverflow.com/a/1406432
    printf("Press enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    //Method 9 test

    //Stream the output to a text file and then compare based on expected output

    printf("\nChecking Method 9 | void translateDnaToMrnaProteins (char aSeq [SIZE]);");
    printf("\n--------------------------\n"
           "No confirmation on proper format or how to read printf statements so requires visual inspection\n");
    printf("\n--------------------------\n");

    char testcase_translateDnaToMrnaProteins[40][SIZE] = {"A", "T",
                                                          "AT", "TA",
                                                          "GAT", "CTA",
                                                          "GCTA", "CGAT",
                                                          "AGCTA", "TCGAT",
                                                          "AGCTAG", "TCGATC",
                                                          "AGCTAGC", "TCGATCG",
                                                          "GGCTAGCT", "CCGATCGA",
                                                          "AAGCTAGCTA", "CGTAGGCAT",
                                                          "CTAGCTAGCTAGC", "GATCGATCGATCG",
                                                          "GGCTAGCTAGCTAGC", "CCGATCGATCGATCG",
                                                          "AAGCTAGCTAGCTAGC", "TTCGATCGATCGATCG",
                                                          "GCTAGCTAGCTAGCTAGC", "CGATCGATCGATCGATCG",
                                                          "GGCTAGCTAGCTAGCTAGCTA", "CCGATCGATCGATCGATCGAT",
                                                          "AAGCTAGCTAGCTAGCTAGCTAGC", "TTCGATCGATCGATCGATCGATCG",
                                                          "GGCTAGCTAGCTAGCTAGCTAGCTAGCT",
                                                          "CCGATCGATCGATCGATCGATCGATCGA",
                                                          "AAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC",
                                                          "TTCGATCGATCGATCGATCGATCGATCGATCG",
                                                          "GGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTA",
                                                          "CCGATCGATCGATCGATCGATCGATCGATCGAT",
                                                          "AAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGC",
                                                          "TTCGATCGATCGATCGATCGATCGATCGATCGATCG",
                                                          "AAAAAAAAAATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
                                                          "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",};

    //Loop for each test case and test
    //Not sure on the format and reading from the console to use visual inspection for now
    for (int i = 0; i < 40; ++i) {
        translateDnaToMrnaProteins(testcase_translateDnaToMrnaProteins[i]);
        printf("\n\nnewline from tester, not your method, dont worry :)\n\n");
    }

    return 0;
}

