/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :01/31/2022

*/
#define _CRT_SECURE_NO_WARNINGS
#include "cStrTools.h"
#include <stdio.h>
#include "DNA.h"
#include <iostream>
using namespace std;
namespace sdds {
    FILE* fptr;
    struct DNA* dna;
    int counter;

    bool beginSearch(const char* filename)
    {
        bool ans = false;
        cout << "DNA search program" << endl;
        fptr= fopen(filename, "r");
        if (fptr!=NULL)
        {
            ans = true;
        }
        return ans;
    }
    bool read(const char* subDNA)
    {
        counter = 0;
        bool ans = false;
        int tempid,i=0;
        char tempdna[1000];
        
        while (fscanf(fptr, "%d, %s", &tempid, tempdna) != EOF)
        {
            if (strStr(tempdna, subDNA)!=NULL)
            {
                counter++;
            }
        }
        rewind(fptr);
        if (counter>0)
        {
            dna = new DNA[counter];
            while (fscanf(fptr, "%d, %s", &tempid, tempdna) != EOF)
            {
                if (strStr(tempdna, subDNA)!=NULL)
                {
                    ans = true;
                    dna[i].numdna = new char[strLen(tempdna) + 1];
                    dna[i].id = tempid;
                    strCpy(dna[i].numdna, tempdna);
                    i++;
                }
            }
            rewind(fptr);
        }
        
        return ans;
    }
    void sort() {
        int i, d;
        
        DNA temp;
        for ( i = 0; i < counter-1; i++)
        {
            for (d = 0; d < counter - i - 1; d++)
            {
                if (dna[d].id > dna[d + 1].id)
                {
                    temp = dna[d];
                    dna[d] = dna[d + 1];
                    dna[d + 1] = temp;
                    
                }
            }
            
        }
    }
    void displayMatches() {
        int i;
        cout << counter << " matches found:" << endl;
        for ( i = 0; i < counter; i++)
        {
            cout  << i + 1 << ") " << dna[i].id << ":" << endl << dna[i].numdna << endl << "======================================================================" << endl;
          
                
        }
    }
    void deallocate() {
        int i;
        for ( i = 0; i < counter; i++)
        {
            delete[] dna[i].numdna;
            dna[i].numdna = nullptr;
        }
        delete[] dna;
        dna = nullptr;
    }

    void endSearch() {
        fclose(fptr);
        cout << "DNA Search Program Closed."<< endl;
    }
}