#include "Gradebook.h"
#include <iostream>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

// Default constructor
Gradebook::Gradebook() {
    // The vector 'scores' is automatically initialized.
}

// Returns the number of grades currently in the gradebook.
int Gradebook::getSize() const {
    return scores.size();
}

// Inserts a new FinalGrade object into the gradebook.
void Gradebook::insert(FinalGrade newFG) {
    scores.push_back(newFG);
}

// Finds and returns the FinalGrade object with the maximum score.
// Returns a default FinalGrade object if the gradebook is empty.
FinalGrade Gradebook::getMax() const {
    if (scores.empty()) {
        return FinalGrade(); // Return a default-constructed object
    }

    FinalGrade maxGrade = scores[0];
    for (size_t i = 1; i < scores.size(); ++i) {
        if (scores[i].getScore() > maxGrade.getScore()) {
            maxGrade = scores[i];
        }
    }
    return maxGrade;
}

// Finds and returns the FinalGrade object with the minimum score.
// Returns a default FinalGrade object if the gradebook is empty.
FinalGrade Gradebook::getMin() const {
    if (scores.empty()) {
        return FinalGrade(); // Return a default-constructed object
    }

    FinalGrade minGrade = scores[0];
    for (size_t i = 1; i < scores.size(); ++i) {
        if (scores[i].getScore() < minGrade.getScore()) {
            minGrade = scores[i];
        }
    }
    return minGrade;
}

// Calculates and returns the average of all scores.
// Returns 0.0 if the gradebook is empty to avoid division by zero.
double Gradebook::getAverage() const {
    if (scores.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (size_t i = 0; i < scores.size(); ++i) {
        sum += scores[i].getScore();
    }
    return sum / scores.size();
}

// Adds the given value to each score in the gradebook.
// If a score would exceed MAX_SCORE (100.0), it is capped at MAX_SCORE.
void Gradebook::incrementScore(double value) {
    const double MAX_SCORE = 100.0;
    for (size_t i = 0; i < scores.size(); ++i) {
        double currentScore = scores[i].getScore();
        double newScore = currentScore + value;

        if (newScore > MAX_SCORE) {
            scores[i].setScore(MAX_SCORE);
        } else {
            scores[i].setScore(newScore);
        }
    }
}

// Prints all the scores and their corresponding letter grades.
void Gradebook::print() const {
    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < scores.size(); ++i) {
        std::cout << "Score: " << std::setw(8) << scores[i].getScore()
                  << "    Letter Grade: " << scores[i].decideLetterGrade()
                  << std::endl;
    }
}


