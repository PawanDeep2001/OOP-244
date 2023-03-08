/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :01/22/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include <iostream>
#include "cStrTools.h"
using namespace std;
namespace sdds {
    void phoneDir(const char* programTitle, const char* fileName)
    {
        char ans[50];
        int i=0, j;
        char lowdataname[50];
        char lowans[50];
        const char* got[100];
        FILE* fp;
        numDatabase data[100];
        fp = fopen(fileName, "r");
        if (fp != NULL) {
            while (!feof(fp)) {
                fscanf(fp, "%[^\t]\t%s\t%s\t%s\n", data[i].name, data[i].area, data[i].prefix, data[i].number);
                i++;
            }
            cout << programTitle << " phone direcotry search" << endl <<
                "-------------------------------------------------------" << endl;
            do
            {
                printf("Enter a partial name to search (no spaces) or enter '!' to exit\n> ");
                
                scanf("%20s", ans);
                
                if (ans[0] != '!')
                {
                    for ( j = 0; j < i; j++)
                    {
                        
                        toLowerCaseAndCopy(lowdataname, data[j].name);
                        toLowerCaseAndCopy(lowans, ans);
                        trim(ans);
                        
                        got[50] = strStr(lowdataname, lowans);
                        
                        
                        if (got[50]!= NULL)
                        {
                            printf("%s: (%s) %s-%s\n", data[j].name, data[j].area, data[j].prefix, data[j].number);
                        }
                        
                    }
                    
                }
                else
                {
                    printf("Thank you for using Star Wars directory.\n");
                }
		
            } while (ans[0]!='!');
	    fclose(fp);
        }
        else
        {
            cout << programTitle << " phone direcotry search" << endl <<
                "-------------------------------------------------------" << endl;
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
        }
    }
}