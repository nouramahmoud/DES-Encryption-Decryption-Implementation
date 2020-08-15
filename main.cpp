#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string shiftleft(string k, int shifts)
{
    string s = "";
    for (int i = 0; i < shifts; i++)
    {
        for (int j = 1; j < 28; j++)
        {
            s += k[j];
        }
        s += k[0];
        k = s;
        s = "";
    }
    return k;
}
string permutations(string k, int* arr,int n)
{
    string per = "";
    for (int i = 0; i < n; i++)
    {
        per += k[arr[i] - 1];
    }
    return per;
}
string XOR(string number1, string number2)
{
    string result = "";
    for (int i = 0; i < number1.size(); i++)
    {
        if (number1[i] == number2[i])
        {
            result += "0";
        }
        else
        {
            result += "1";
        }
    }
    return result;
}

int main()
{
    string permutedkey="";
    string leftc0,rightd0,leftIP,rightIP;
    string newc[16],newd[16];
    string keyn[16],newkeyn[16];
    string plaintext ="0000000100100011010001010110011110001001101010111100110111101111";
    string originalkey="0001001100110100010101110111100110011011101111001101111111110001";
    int pc1[56] = {57, 49, 41, 33, 25, 17, 9,
                   1, 58, 50, 42, 34, 26, 18,
                   10, 2, 59, 51, 43, 35, 27,
                   19, 11, 3, 60, 52, 44, 36,
                   63, 55, 47, 39, 31, 23, 15,
                   7, 62, 54, 46, 38, 30, 22,
                   14, 6, 61, 53, 45, 37, 29,
                   21, 13, 5, 28, 20, 12, 4
                  };


    permutedkey=permutations(originalkey,pc1,56);

    cout<<"permuted key : "<<permutedkey<<endl;
    for(int i=0; i<28; i++)
    {
        leftc0+=permutedkey[i];
        rightd0+=permutedkey[i+28];
    }
    cout<<"left part : "<<leftc0<<endl;
    cout<<"right part: "<<rightd0<<endl;
    int shiftschedule[16]= { 1, 1, 2, 2,
                             2, 2, 2, 2,
                             1, 2, 2, 2,
                             2, 2, 2, 1
                           };
    newc[0]=shiftleft(leftc0, shiftschedule[1]);
    newd[0]=shiftleft(rightd0, shiftschedule[1]);

    for(int i=1; i<16; i++)
    {
        newc[i]=shiftleft(newc[i-1], shiftschedule[i]);
        newd[i]=shiftleft(newd[i-1],shiftschedule[i]);
    }

//    for(int i=0; i<16; i++)
//    {
//        cout<<"c"<<i<<" is "<<newc[i]<<endl;
//        cout<<"d"<<i<<" is "<<newd[i]<<endl;
//    }
    for(int i=0; i<16; i++)
    {
        keyn[i]=newc[i]+newd[i];
        // cout<<i<<"key is "<<keyn[i]<<endl;
    }
    int pc2[48] = { 14, 17, 11, 24, 1, 5,
                    3, 28, 15, 6, 21, 10,
                    23, 19, 12, 4, 26, 8,
                    16, 7, 27, 20, 13, 2,
                    41, 52, 31, 37, 47, 55,
                    30, 40, 51, 45, 33, 48,
                    44, 49, 39, 56, 34, 53,
                    46, 42, 50, 36, 29, 32
                  };
    for(int i=0; i<16; i++)
    {
        newkeyn[i]=permutations(keyn[i],pc2,48);
        //  cout<<"new key"<<i<<" is "<<newkeyn[i]<<endl;
    }
    int permutationIP[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                              60, 52, 44, 36, 28, 20, 12, 4,
                              62, 54, 46, 38, 30, 22, 14, 6,
                              64, 56, 48, 40, 32, 24, 16, 8,
                              57, 49, 41, 33, 25, 17, 9, 1,
                              59, 51, 43, 35, 27, 19, 11, 3,
                              61, 53, 45, 37, 29, 21, 13, 5,
                              63, 55, 47, 39, 31, 23, 15, 7
                            };

    string textIP = permutations(plaintext,permutationIP,64);
    cout<<"the initial permutation result : "<<textIP<<endl;
    for(int i=0; i<32; i++)
    {
        leftIP+=textIP[i];
        rightIP+=textIP[i+32];
    }
    cout<<"left half "<<leftIP<<endl;
    cout<<"right half "<<rightIP<<endl;

    int EbitSELECTION[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
                              6, 7, 8, 9, 8, 9, 10, 11,
                              12, 13, 12, 13, 14, 15, 16, 17,
                              16, 17, 18, 19, 20, 21, 20, 21,
                              22, 23, 24, 25, 24, 25, 26, 27,
                              28, 29, 28, 29, 30, 31, 32, 1
                            };

    int stable[8][4][16] = { {
            14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
            0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
            4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
            15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
        },

        {
            15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
            3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
            0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
            13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
        },

        {
            10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
            13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
            13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
            1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
        },

        {
            7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
            13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
            10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
            3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
        },

        {
            2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
            14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
            4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
            11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
        },

        {
            12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
            10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
            9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
            4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
        },

        {
            4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
            13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
            1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
            6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
        },

        {
            13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
            1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
            7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
            2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
        }
    };
    int spermutaion[32] = { 16, 7, 20, 21,
                            29, 12, 28, 17,
                            1, 15, 23, 26,
                            5, 18, 31, 10,
                            2, 8, 24, 14,
                            32, 27, 3, 9,
                            19, 13, 30, 6,
                            22, 11, 4, 25
                          };
    int finalpermutation[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
                           39, 7, 47, 15, 55, 23, 63, 31,
                           38, 6, 46, 14, 54, 22, 62, 30,
                           37, 5, 45, 13, 53, 21, 61, 29,
                           36, 4, 44, 12, 52, 20, 60, 28,
                           35, 3, 43, 11, 51, 19, 59, 27,
                           34, 2, 42, 10, 50, 18, 58, 26,
                           33, 1, 41, 9, 49, 17, 57, 25 };

    for(int i=0; i<16; i++)
    {

        string expandedright=permutations(rightIP,EbitSELECTION,48);
        string xoresult=XOR(expandedright,newkeyn[i]);
        //cout<<"expanded right: "<<expandedright<<endl;
        //cout<<"xor result: "<<xoresult<<endl;
        string sbox_result = "";
        for (int i = 0; i < 8; i++) {
            int row = 2 * int(xoresult[i * 6] - '0') + int(xoresult[i * 6 + 5] - '0');
            int col = 8 * int(xoresult[i * 6 + 1] - '0') + 4 * int(xoresult[i * 6 + 2] - '0') + 2 * int(xoresult[i * 6 + 3] - '0') + int(xoresult[i * 6 + 4] - '0');
            int val = stable[i][row][col];
            sbox_result += char(val / 8 + '0');
            val = val % 8;
            sbox_result += char(val / 4 + '0');
            val = val % 4;
            sbox_result += char(val / 2 + '0');
            val = val % 2;
            sbox_result += char(val + '0');
        }
        sbox_result = permutations(sbox_result, spermutaion, 32);
        //cout<<"result of s-box permutation : "<<sbox_result<<endl;

        xoresult = XOR(sbox_result, leftIP);
        leftIP=xoresult;
        if (i != 15) {
            swap(leftIP, rightIP);
        }
    }
    string fulltext = leftIP+rightIP;
    string finalone = permutations(fulltext,finalpermutation,64);
    cout<<"final permutation for text : "<<finalone<<endl;
    //decryption
    string decrypted ="";
      for(int i=0; i<16; i++)
    {
       reverse(newkeyn[i].begin(), newkeyn[i].end());

    }
    string decryptedtext = permutations(finalone,permutationIP,64);
    string left = decryptedtext.substr(0, 32);
    string right = decryptedtext.substr(32, 32);
    for(int i=0; i<16; i++)
    {
        string expanddright=permutations(right,EbitSELECTION,48);
        string xoresult=XOR(expanddright,newkeyn[i]);
        //cout<<"expanded right: "<<expandedright<<endl;
        //cout<<"xor result: "<<xoresult<<endl;
        string sbox_result = "";
        for (int i = 0; i < 8; i++) {
            int row = 2 * int(xoresult[i * 6] - '0') + int(xoresult[i * 6 + 5] - '0');
            int col = 8 * int(xoresult[i * 6 + 1] - '0') + 4 * int(xoresult[i * 6 + 2] - '0') + 2 * int(xoresult[i * 6 + 3] - '0') + int(xoresult[i * 6 + 4] - '0');
            int val = stable[i][row][col];
            sbox_result += char(val / 8 + '0');
            val = val % 8;
            sbox_result += char(val / 4 + '0');
            val = val % 4;
            sbox_result += char(val / 2 + '0');
            val = val % 2;
            sbox_result += char(val + '0');
        }
        sbox_result = permutations(sbox_result, spermutaion, 32);
        //cout<<"result of s-box permutation : "<<sbox_result<<endl;

        xoresult = XOR(sbox_result, leftIP);
        left=xoresult;
        if (i != 15) {
            swap(left, right);
        }
    }
    string text = left+right;
    string finalonel = permutations(text,finalpermutation,64);
    cout<<"the result of decryption : "<<finalonel<<endl;

    return 0;
}
