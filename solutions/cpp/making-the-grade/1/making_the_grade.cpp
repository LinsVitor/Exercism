#include <array>
#include <cstddef>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> scores{};
    for (size_t i{0}; i < student_scores.size(); i++) {
        scores.push_back(static_cast<int>(student_scores[i]));
    }
    return scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count{0};
    for (size_t i{0}; i < student_scores.size(); i++) {
        if (student_scores[i] <= 40) {
            count++;
        }
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    const int fail_score{40};
    std::array<int, 4> highest_grade{};
    int total_range = highest_score - fail_score;
    float grade_interval = total_range / 4.0;
    for (size_t i{0}; i < highest_grade.size(); i++) {
        highest_grade[i] = (fail_score + 1) + i * grade_interval;
    }
    return highest_grade;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranking{};
    for (size_t i{0}; i < student_scores.size() && i < student_names.size(); i++) {
        std::string position = std::to_string(i + 1);
        std::string score = std::to_string(student_scores[i]);
        ranking.push_back(position + ". " + student_names[i] + ": " + score);
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    for (size_t i{0}; i < student_scores.size() && i < student_names.size(); i++) {
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }
    return "";
}
