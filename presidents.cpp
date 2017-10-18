#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

const string INPUT_FILE_NAME = "presidents.in";

string format_string(string,int);

int main()
{
    ifstream input;
    input.open("presidents.in",ios::in);  // open file for reading
    if (input.fail()) // this method gives boolean output ( 0 / 1)
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    cout << "First name  Middle name Last name   Born Died  Age  Start End  Party" << endl;  //Display header for the table
    cout << "----------  ----------- ---------   ---- ----  ---  ----- ---- -----" << endl;
    string name[5],first_name,middle_name,last_name,party,temp;
    int age,born,counter=0,died,End,flag=0,start;
    float average=0;
    while(!input.eof())                        // Check if it is end of file or not
    {
        int lengthOfName=0;
        if(flag)
        {
            lengthOfName=1;                    // for empty field
        }
        flag=0;
        while(1)
        {
            input >> name[lengthOfName];       // read string
            if(name[lengthOfName]==".")        // check whether it's the end of file (in the term of .)
            {
                goto END;                      // goto label END and calculate average
            }
            if(name[lengthOfName]=="(")
            {
                break;  // skip the braces
            }
            lengthOfName++;                    // increment counter for next string
        }
        first_name = format_string(name[0],12); // call function for first name field format
        cout << first_name;                     // print the first name string
        middle_name = "";                       // initially middle name is empty
        for(int i=1; i<lengthOfName-1; i++)
        {
            middle_name = middle_name + " " + name[i]; // appending the middle name
        }
        middle_name = format_string(middle_name,12);
        cout << middle_name;                    // print middle name
        last_name = format_string(name[lengthOfName-1],12); // call function for formating
        cout << last_name;                      // print last name
        input >> born;
        cout << born << " ";                    // print born year
        input >> temp;
        if(temp == "-")                         // check if there is death year given or not
        {
            input >> died;
            cout << died << "  ";
            age=died-born;                      // calculate the age
            average=average+age;                // sum up the age of all presidents
            counter++;                          // increment the counter for calculate total death presidents
            cout << " " << age << " ";
            input >> temp;
        }
        else
        {
            cout << "          ";               // if death year is not given just add whitespace
        }
        input >> party;
        input >> start;
        input >> temp;
        if(temp!="-")                           // read the string upto " - " symbol
        {
            name[0]=temp;
            flag=1;
            cout << "  " << start;
            cout << " " << start << " ";
            cout << party.c_str() << endl;
            continue;
        }
        input >> End;
        cout << "  " << start << " ";
        cout << End << " ";
        cout << party.c_str() << endl;
    }
    END:
    cout << "" << endl;                          // add one blank line
    average/=counter;                            // divide average value with total death presidents for final average value
    average=(floor(average*10+0.5)/10);          // round off average value to it's nearest 10th value
    cout << "Average age at death = " << average << endl;
    return 0;
}

string format_string(string str,int required_len)
 {
    int strlen=str.size();   // save string's length
    for(int i=strlen; i<required_len; i++)
    {
        str = str + " ";    // padding whitespace after the string
    }
    return str;
}



