#include <iostream>
#include <vector>
#include <string>
#include <map>

struct Question {
    std::string question;
    int type;
    std::string math;
};

int main() {
    std::vector<Question> assessment = {
        {"Am the life of the party.", 1, "+"},
        {"Feel little concern for others.", 2, "-"},
        {"Am always prepared.", 3, "+"},
        {"Get stressed out easily.", 4, "-"},
        {"Have a rich vocabulary.", 5, "+"},
        {"Don't talk a lot.", 1, "-"},
        {"Am interested in people.", 2, "+"},
        {"Leave my belongings around.", 3, "-"},
        {"Am relaxed most of the time.", 4, "+"},
        {"Have difficulty understanding abstract ideas.", 5, "-"},
        {"Feel comfortable around people.", 1, "+"},
        {"Insult people.", 2, "-"},
        {"Pay attention to details.", 3, "+"},
        {"Worry about things.", 4, "-"},
        {"Have a vivid imagination.", 5, "+"},
        {"Keep in the background.", 1, "-"},
        {"Sympathize with others' feelings.", 2, "+"},
        {"Make a mess of things.", 3, "-"},
        {"Seldom feel blue.", 4, "+"},
        {"Am not interested in abstract ideas.", 5, "-"},
        {"Start conversations.", 1, "+"},
        {"Am not interested in other people's problems.", 2, "-"},
        {"Get chores done right away.", 3, "+"},
        {"Am easily disturbed.", 4, "-"},
        {"Have excellent ideas.", 5, "+"},
        {"Have little to say.", 1, "-"},
        {"Have a soft heart.", 2, "+"},
        {"Often forget to put things back in their proper place.", 3, "-"},
        {"Get upset easily.", 4, "-"},
        {"Do not have a good imagination.", 5, "-"},
        {"Talk to a lot of different people at parties.", 1, "+"},
        {"Am not really interested in others.", 2, "-"},
        {"Like order.", 3, "+"},
        {"Change my mood a lot.", 4, "-"},
        {"Am quick to understand things.", 5, "+"},
        {"Don't like to draw attention to myself.", 1, "-"},
        {"Take time out for others.", 2, "+"},
        {"Shirk my duties.", 3, "-"},
        {"Have frequent mood swings.", 4, "-"},
        {"Use difficult words.", 5, "+"},
        {"Don't mind being the center of attention.", 1, "+"},
        {"Feel others' emotions.", 2, "+"},
        {"Follow a schedule.", 3, "+"},
        {"Get irritated easily.", 4, "-"},
        {"Spend time reflecting on things.", 5, "+"},
        {"Am quiet around strangers.", 1, "-"},
        {"Make people feel at ease.", 2, "+"},
        {"Am exacting in my work.", 3, "+"},
        {"Often feel blue.", 4, "-"},
        {"Am full of ideas.", 5, "+"}
    };
    int numQuestions = assessment.size();
    std::string helpText = "Describe yourself as you generally are now, not as you wish to be in the future.\nDescribe yourself as you honestly see yourself, in relation to other people you know of the same sex as you are, and roughly your same age.\nSo that you can describe yourself in an honest manner, your responses will be kept in absolute confidence.\n\nIndicate for each statement which answer best fits as a description of you:\n1. Very Inaccurate\n2. Moderately Inaccurate\n3. Neither Accurate Nor Inaccurate\n4. Moderately Accurate\n5. Very Accurate\n\n";
    std::vector<std::string> answerDescriptions = {
        "Very Inaccurate", "Moderately Inaccurate", "Neither Accurate Nor Inaccurate",
        "Moderately Accurate", "Very Accurate"
    };
    std::vector<int> typeScores(5, 0);
    int questionNum = 0;

    std::cout << "Welcome to the IPIP Big-Five Factor Markers Assessment!" << std::endl;
    std::cout << "Programmed in C++" << std::endl << questionNum << " Total Questions" << std::endl;
    std::cout << std::endl << helpText;
    std::cout << std::endl << std::endl << "For each question, type a number 1-5 to represent your answer. Type 'help' for more info, or press Enter to get started." << std::endl;
    std::cin.ignore();

    for (const auto& questionData : assessment) {
        ++questionNum;
        bool validAnswer = false;
        while (!validAnswer) {
            std::cout << std::endl << "Question #" << questionNum << ":" << std::endl;
            std::string answer;
            std::cout << questionData.question << "" << std::endl;
            std::getline(std::cin, answer);

            if (std::isdigit(answer[0])) {
                int intAnswer = std::stoi(answer);
                if (intAnswer > 5 || intAnswer < 1) {
                    std::cout << "ERROR: Your answer must be a number 1-5" << std::endl;
                } else {
                    int answerMath = (questionData.math == "+") ? intAnswer : 5 - (intAnswer - 1);
                    typeScores[questionData.type - 1] += answerMath;
                    validAnswer = true;
                }
            } else if (answer == "help" || answer == "HELP") {
                std::cout << std::endl << "************HELP************" << std::endl << helpText << std::endl << std::endl << "Please continue..." << std::endl;
            } else {
                std::cout << std::endl << "You must answer the question with a number 1-5. Type 'help' for information!" << std::endl;
            }
        }  
    }

    std::vector<std::string> typeInfo = {"Extraversion", "Agreeableness", "Conscientiousness", "Emotional Stability", "Intellect/Imagination"};
    for (int i = 0; i < typeInfo.size(); ++i) {
        std::cout << std::endl << typeInfo[i] << ": " << typeScores[i] << "" << std::endl;
    }

    std::cout << std::endl << std::endl << "Thank you for taking the IPIP BFFM Assessment! Press any key to exit, but copy and information above to save it." << std::endl;
    std::string exitProgram;
    std::getline(std::cin, exitProgram);
    return 0;
}
