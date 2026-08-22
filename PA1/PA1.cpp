/*
 *Course: CS218-00x
 *Project: Lab5 (As the first part of Project1)
 *Purpose: As part of the Project 1,
 *         to test if the definition of Gradebook class is correct.
 *         it provides FOUR "hard-coded" testing cases of expected average
 *            to curve the scores based on each expected average.
 *         each student's score is at the range [0,100]
 *         the expected average is at the range (original average, 100]
 *
 *****PLEASE DO NOT CHANG THIS FILE***** 
 *
 */

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <string>
#include <cmath>        // std::abs
#include "Gradebook.h"

using namespace std;

int main()
{

    Gradebook CS218gradebook_original;
    string scores;
    double score;
    // Max score is 100, minimum score is 0.


    while (true) {
	cout << "Please enter a score for CS218 (type 'Q' or 'q' to quit): " << endl;
	getline(cin, scores);
	if (scores == "Q" || scores == "q") {
	    break;
	}
	try {
		size_t idx;
		score = stod(scores, &idx);
		if (idx == 0) {
			cout << "Invalid input, please try again..." << endl;
			continue;
		}
		if (score < MIN_SCORE || score > MAX_SCORE) {
			cout << "The score is not in the correct range, please try again..." << endl;
			continue;
		}

	}
        catch(...) {
		cout << "Invalid input, please try again..." << endl;
		continue;
        }
    FinalGrade stu_Grade(score);
    CS218gradebook_original.insert(stu_Grade);
    }
	

    if (CS218gradebook_original.getSize() == 0) {
	cout << "The gradebook is Empty!" << endl;
	cout << "Thank you for using CS218 Grade Calculator." << endl;
	return 0;
    }
   
    // Implement a Grade Curve Calculator:
    // Based on each expected average (there are THREE testing cases)
    // Display the original gradebook and the original average score
    // Then based on each expected average, decide
    //         if adjustment is needed (expected average is close enough to the original average or not);
    //         if adjustment is needed (may not in the valid range)
    //            Display the curved gradebook, the number of scores in the 
    //            gradebook, the maximum score and its letter grade, the 
    //            minimum score and its letter grade and the actual average
    // Note that Since any score cannot be larger than MAX_SCORE, 
    // the "Actual Average" can be less than or equal to "Expected Average"
    cout << fixed << setprecision(SIGDIGITS);
    cout << endl << endl;
    while(true) {

	double avgOG = CS218gradebook_original.getAverage();
	cout << "The original average score is:\t" << avgOG << endl;
        cout << "Please enter your expected average score to curve (type 'Q' to 'q' to quit); " << endl;
	string expectedString;
	double expectedAverage;
	getline(cin, expectedString);
	if (expectedString == "q" || expectedString == "Q") {
		break;
	}
	try {
		size_t idx;
		expectedAverage = stod(expectedString, &idx);
		if (idx == 0) {
			cout << "Invalid input, please try again..." << endl;
			continue;
		}
	}
	catch(...) {
                cout << "Invalid input, please try again..." << endl;
		continue;
	}
	double diff = expectedAverage - avgOG;
	const double EPSILON = 1.0e-2;
	if (abs(diff) < EPSILON) {
		cout << "The scores are perfect, no need for the grading curve!" << endl;
	}
	else {
		if (diff < MIN_SCORE || expectedAverage > MAX_SCORE) {
			cout << "The expected average is not in the correct range, please try again...\n\n" << endl;
		}
		else {

			cout << "The original gradebook for CS218: " << endl;
			CS218gradebook_original.print();
			cout << "The number of scores is:\t" << CS218gradebook_original.getSize() << endl;
			cout << "The maximum score is:\t";
			CS218gradebook_original.getMax().print();
			cout << "The minimum score is :\t";
			CS218gradebook_original.getMin().print();
			cout << "The original average score is :\t" << CS218gradebook_original.getAverage() << endl;
			cout << endl << endl;
			Gradebook CS218gradebook_curved = CS218gradebook_original;
			CS218gradebook_curved.incrementScore(diff);
			cout << "The curved gradebook for CS218: " << endl;
			CS218gradebook_curved.print();
			cout << "The number of scores is:\t" << CS218gradebook_curved.getSize() << endl;
			cout << "The maximum score is :\t";
			CS218gradebook_curved.getMax().print();
			cout << "The minimum score is:\t";
			CS218gradebook_curved.getMin().print();
			cout << "The actual average score is:\t" << CS218gradebook_curved.getAverage() << endl;
			cout << endl << endl;
		}
	}

}
    cout << "Thank you for using CS218 Grade Curve Calculator!" << endl;
    return 0;
}

