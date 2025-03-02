#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main()
{
    srand(time(0));

    cout << "1. EQUATION SOLVER " << endl;
    cout << "2. FIBONACCI ADVENTURE " << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "!WELCOME TO THE EQUATION SOLVER GAME!" << endl;
        cout << "Solve the equation and increase your score.\nYou have 5 seconds to answer every question. Let's Go!" << endl;
        int score = 0;
        int timeTaken = 0;

        for (int i = 1; i <= 10; i++)
        {
            int a = rand() % 15 + 1;
            int b = rand() % 15 + 1;
            char operators[] = {'+', '-', '*', '/'};
            char op = operators[rand() % 4];

            int rightanswer;
            if (op == '+')
            {
                rightanswer = a + b;
            }
            else if (op == '-')
            {
                rightanswer = a - b;
            }
            else if (op == '*')
            {
                rightanswer = a * b;
            }
            else
            {
                while (a % b != 0)
                {
                    a = rand() % 20 + 1;
                    b = rand() % 20 + 1;
                }
                rightanswer = a / b;
            }

            cout << "Question " << i << ": " << a << " " << op << " " << b << " =?" << endl;

            auto start = high_resolution_clock::now();
            int answer;
            cin >> answer;
            auto end = high_resolution_clock::now();

            duration<double> diff = end - start;
            timeTaken += diff.count();

            if (diff.count() > 5)
            {
                cout << "Time's Up! You took too long. Your score has been reduced by 1" << endl;
                score--;
            }
            else
            {
                if (answer == rightanswer)
                {
                    cout << "Correct! You took " << diff.count() << " seconds." << endl;
                    score++;
                }
                else
                {
                    cout << "Wrong! Correct answer was: " << rightanswer << endl;
                }
            }
        }
        cout << "\nGame Over! Your final score: " << score << "/10";
        cout << "\nTotal time taken: " << timeTaken << " seconds." << endl;
        break;
    }

    case 2:
    {
        cout << "!WELCOME TO THE FIBONACCI ADVENTURE!" << endl;
        cout << "Enter the next Fibonacci number in the sequence and increase your score. You have 5 seconds." << endl;
        cout << "Game Ends when you enter an incorrect number. Let's Go" << endl;

        int prev2 = 0, prev1 = 1, next;
        int level = 1;
        int totalTime = 0;
        int sc = 0;

        cout << "Level " << level << ": " << prev2 << "\n";
        cout << "Level " << ++level << ": " << prev1 << "\n";

        while (true)
        {
            next = prev2 + prev1;
            cout << "Level " << ++level << ": ";
            auto start = high_resolution_clock::now();
            int answer;
            cin >> answer;
            auto end = high_resolution_clock::now();

            duration<double> differ = end - start;
            totalTime += differ.count();

            if (differ.count() > 5)
            {
                cout << "Time's Up! You took too long." << endl;
                break;
            }
            else
            {
                if (answer == next)
                {
                    cout << "Correct! You took " << differ.count() << " seconds" << endl;
                    prev2 = prev1;
                    prev1 = next;
                    sc++;
                }
                else
                {
                    cout << "Wrong! The correct answer was " << next << endl;
                    cout << "You reached Level " << level - 1 << endl;
                    cout << "Your final score: " << sc << endl;
                    cout << "Total Time taken: " << totalTime << " seconds." << endl;
                    break;
                }
            }
        }
        break;
    }
    default:
        cout << "Invalid choice! Please enter 1 or 2." << endl;
        break;
    }
}
