//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 3, Project 3
//  1/13/2016
//  bag class overloading operator functions

#include <iostream>
#include <cstdlib>
#include "bag.h"
using namespace std;
using namespace main_savitch_3;

void get_ages(bag& ages);
void check_ages(bag& ages);


//--------------- Mycode for overloading - and -= ---------
void bag::operator -=(const bag& addend)
{
    for (int i=0; i < addend.used; i++){
        for (int j=0; j < addend.used; j++){
            if(addend.data[i] == data[j]){
                data[j] = data[used - 1];
                data[used - 1] = 0;
                used --;
            }
        }
    }
}

bag operator -(const bag& b1, const bag& b2)
{
    bag answer;
    answer -= b1;
    answer -= b2;
    return answer;
}

int main( )
{
    bag ages;
    ages.insert(10);
    ages.insert(20);
    ages.insert(20);
    ages.insert(30);

    bag ages1;
    ages1.insert(15);
    ages1.insert(25);
    ages1.insert(25);
    ages1.insert(35);


    ages1 += ages;
    ages1 -= ages;



    //get_ages(ages);
    //check_ages(ages);
    //cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;
}


void get_ages(bag& ages)
{
    int user_input;

    cout << "Type the ages in your family." << endl;
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
        if (ages.size( ) < ages.CAPACITY)
            ages.insert(user_input);
        else
            cout << "I have run out of room and can’t add that age." << endl;
        cin >> user_input;
    }
}

void check_ages(bag& ages)
{
    int user_input;

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've got that age and will remove it." << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}
