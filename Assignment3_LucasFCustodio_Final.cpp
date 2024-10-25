/*
Lucas Custodio
COP3014: Assignment 3
2/22/24
*/

/**
 * Citations/References:
 * Lectures 6,8,10
 * Worked together with Gedeon Alfred
 * Worked together with Joseph Xiao
 * Google
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

int r_TestScore(int high, int low);

void calculations_output(ifstream &in_file, ofstream &out_file);

// void randnum(int test_taken, ofstream&, First_Last_Names& FLN);

int main(){

    srand(time(0)); // allows for random number generation every time the code is compiled

    ofstream out_file;
    ifstream in_file;
    ofstream output;

    out_file.open("student_grades.txt"); // Opens/creates a self-generating input file & fail-check launch
    if (out_file.fail()) 
    {
        cout << "File failed to open." << endl;
        exit(1);
    }

    /*
        Asks user for 5 different student's first and last names
        generates 10 random test scores
        scores and names are all pasted onto the input file 
    */
    for (int i = 0; i < 5; ++i) { 
        string first_name, last_name;
        cout << "Enter the student's first name " << i + 1 << ": ";
        cin >> first_name;
        cout << "Enter the student's last name " << i + 1 << ": ";
        cin >> last_name;

        out_file << last_name << ", " << first_name;
        for (int i = 0; i < 10; i++) {
            int test_scores = r_TestScore(20, 0);
            out_file << " " << test_scores;
        }
        out_file << endl;
    }

    out_file.close(); // Closes the input file

    cout << "Attempting to open input file" << endl;

    in_file.open("student_grades.txt"); // Opens the input file
    if (in_file.fail()) { //Checks to see if the input file failed
        cout << "file opening failed." << endl;
        exit(1);
    }

    output.open("student_grades_avg.txt"); // Opens the output file
    if (output.fail()) {  //checks to see if the output file failed
        cout << "unable to open student_grades_avg.txt" << endl;
        exit(1);
    }

    calculations_output(in_file, output);

    in_file.close(); // Ends the reading of the input file
    output.close(); // Ends the storing of text on the output file

    return 0;
}

/*
    Function: Creates a random number between
    the range of 1-20
*/
int r_TestScore(int high, int low) {
    return 1 + rand() % (high-low+1);
}

/*
    Function: outloads the self generated input file's information
    into an output file with additional calculations of each
    line's average test scores
*/ 
void calculations_output(ifstream &in_file, ofstream &out_file) {

    string first_name, last_name;
    int test_score = 0;
    double avg = 0.0;

    out_file << "This file displays the students' quiz scores along with the average score for each student.\n" << endl;

    while (in_file >> last_name >> first_name) {
        out_file << last_name << " " << first_name;
        for (int i = 0; i < 10; ++i) {
            in_file >> test_score;
            out_file << " " << test_score;
            avg += test_score;
        }
    avg /= 10.0;
    out_file << fixed << setprecision(2) << ": " << avg << endl;
    }
}