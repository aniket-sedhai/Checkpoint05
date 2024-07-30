#include <iomanip>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>

// ----------------------------------------------------------------1
// NAME     - HiMyNameIs
// INPUT    - None
// OUTPUT   - (string) Your real name somewhere contained in a string
// BEHAVIOR - Return your name as a string
// NOTE     - All the cool kids are centering their strings these days
// -----------------------------------------------------------------
std::string HiMyNameIs(void)
{
    return "         Aniket";
}

// ----------------------------------------------------------------2
// NAME     - GetSizeOfTheStack
// INPUT    - A stack of integers
// OUTPUT   - (int) Size of the stack
// BEHAVIOR - Simply return the size of the stack
// -----------------------------------------------------------------
int GetSizeOfTheStack(std::stack<int>& input_stack)
{
    return static_cast<int>(input_stack.size());
}

// ----------------------------------------------------------------3
// NAME     - GetTopValueOfTheStack
// INPUT    - A stack of integers
// OUTPUT   - (int) Top value of the stack
// BEHAVIOR - Simply return the top value of the stack
// NOTE     - If the stack is empty then return the smallest int
//            https://en.cppreference.com/w/cpp/types/numeric_limits
// NOTE     - You can manipulate the stack, but it must be put back
//            to its original condition before the function returns
// -----------------------------------------------------------------
int GetTopValueOfTheStack(std::stack<int>& input_stack)
{
    if (input_stack.empty() == false)
    {
        return input_stack.top();
    }
    
    return std::numeric_limits<int>::min();
}

// ----------------------------------------------------------------4
// NAME     - GetSecondTopValueOfTheStack
// INPUT    - A stack of integers
// OUTPUT   - (int) SECOND Top value of the stack
// BEHAVIOR - Simply return the SECOND top value of the stack
// NOTE     - If the stack is empty or size 1 then return the smallest int
//            https://en.cppreference.com/w/cpp/types/numeric_limits
// NOTE     - You can manipulate the stack, but it must be put back
//            to its original condition before the function returns
// -----------------------------------------------------------------
int GetSecondTopValueOfTheStack(std::stack<int>& input_stack)
{
    if (input_stack.size() > 1)
    {
        std::stack<int> my_stack = input_stack;
        
        my_stack.pop();
        
        return my_stack.top();
    }
    
    return std::numeric_limits<int>::min();
}

// ----------------------------------------------------------------5
// NAME     - PushValueOntoTheStack
// INPUT    - A stack of integers
// INPUT    - The value to push onto the stack
// OUTPUT   - None
// BEHAVIOR - Simply push the value onto the stack
// -----------------------------------------------------------------
void PushValueOntoTheStack(std::stack<int>& input_stack, int value)
{
    input_stack.push(value);
}

// ----------------------------------------------------------------6
// NAME     - PopValueFromTheStack
// INPUT    - A stack of integers
// OUTPUT   - None
// BEHAVIOR - Simply pop the top value off the stack
// NOTE     - If the stack is empty, do absolutely nothing at all
// -----------------------------------------------------------------
void PopValueFromTheStack(std::stack<int>& input_stack)
{
    if (input_stack.empty() == false)
        input_stack.pop();
}

// ----------------------------------------------------------------7
// NAME     - GetNthTopValueOfTheStack
// INPUT    - A stack of integers
// INPUT    - The N value
// OUTPUT   - (int) Nth Top value of the stack
// BEHAVIOR - Simply return the Nth top value of the stack
// NOTE     - If the stack size is less than n then return the smallest int
//            https://en.cppreference.com/w/cpp/types/numeric_limits
// NOTE     - You can manipulate the stack, but it must be put back
//            to its original condition before the function returns
// -----------------------------------------------------------------
int GetNthTopValueOfTheStack(std::stack<int>& input_stack, int nth_value)
{
    if (input_stack.size() >= nth_value)
    {
        std::stack<int> my_stack = input_stack;
        
        for (int i = 0; i < nth_value - 1; ++i)
            my_stack.pop();
        
        return my_stack.top();
    }
    
    return std::numeric_limits<int>::min();
}

// ------------------------------------------------------------------
// TEST CASES BELOW - PLEASE DON'T MODIFY ANYTHING UNDER THIS MESSAGE
// ------------------------------------------------------------------

void IsThereAnErrorInYourCode(bool correct, int testNo, const std::string& s)
{
    std::cout << "TEST CASE" << std::setw(3) << testNo << " - ";
    if (correct == true)
        std::cout << "PASS" << std::endl;
    else
        std::cout << "ERROR - " << s << std::endl;
}

int main()
{
    std::cout << "------------------------" << std::endl;
    std::cout << ((HiMyNameIs() == "") ? "      Slim Shady?" : HiMyNameIs());
    std::cout << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "      CHECKPOINT 5      " << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "     60 TOTAL POINTS    " << std::endl;
    std::cout << "------------------------" << std::endl;

    std::stack<int> s;
    
    s = {};
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 0, 1,
        "STACK SHOULD BE EMPTY");
        
    s = {};
    IsThereAnErrorInYourCode(GetTopValueOfTheStack(s) == std::numeric_limits<int>::min(), 2,
        "SINCE STACK IS EMPTY, IT SHOULD RETURN SMALLEST int VALUE");
    
    s = {};
    IsThereAnErrorInYourCode(GetSecondTopValueOfTheStack(s) == std::numeric_limits<int>::min(), 3,
        "SINCE STACK IS EMPTY, IT SHOULD RETURN SMALLEST int VALUE");
    
    s = {};
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 1) == std::numeric_limits<int>::min(), 4,
        "SINCE STACK IS EMPTY, IT SHOULD RETURN SMALLEST int VALUE");
    
    s = {};
    PushValueOntoTheStack(s, 12);
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 1, 5,
        "STACK SHOULD BE SIZE 1");
    
    s = {};
    PushValueOntoTheStack(s, 12);
    IsThereAnErrorInYourCode(GetTopValueOfTheStack(s) == 12, 6,
        "TOP VALUE ON STACK SHOULD 12");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 1, 7,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");

    s = {};
    PushValueOntoTheStack(s, 12);
    IsThereAnErrorInYourCode(GetSecondTopValueOfTheStack(s) == std::numeric_limits<int>::min(), 8,
        "SINCE STACK IS SIZE 1, IT SHOULD RETURN SMALLEST int VALUE");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 1, 9,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");

    s = {};
    PushValueOntoTheStack(s, 12);
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 1) == 12, 10,
        "SINCE STACK IS SIZE 1, IT SHOULD RETURN 12");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 1, 11,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 2) == std::numeric_limits<int>::min(), 12,
        "SINCE STACK IS SIZE 1 AND THERE IS NO SECOND ELEMENT, IT SHOULD RETURN SMALLEST int VALUE");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 1, 13,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");

    s = {};
    PushValueOntoTheStack(s, 12);
    PushValueOntoTheStack(s, 19);
    PushValueOntoTheStack(s, 14);
    PushValueOntoTheStack(s, 13);
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 4, 14,
        "STACK SHOULD BE SIZE 4 HERE");
    
    s = {};
    PushValueOntoTheStack(s, 12);
    PushValueOntoTheStack(s, 19);
    PushValueOntoTheStack(s, 14);
    PushValueOntoTheStack(s, 13);
    IsThereAnErrorInYourCode(GetTopValueOfTheStack(s) == 13, 15,
        "TOP VALUE ON STACK SHOULD BE 13");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 4, 16,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");

    s = {};
    PushValueOntoTheStack(s, 12);
    PushValueOntoTheStack(s, 19);
    PushValueOntoTheStack(s, 14);
    PushValueOntoTheStack(s, 13);
    IsThereAnErrorInYourCode(GetSecondTopValueOfTheStack(s) == 14, 17,
        "SECOND TOP VALUE ON STACK SHOULD BE 14");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 4, 18,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");

    s = {};
    PushValueOntoTheStack(s, 12);
    PushValueOntoTheStack(s, 19);
    PushValueOntoTheStack(s, 14);
    PushValueOntoTheStack(s, 13);
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 1) == 13, 19,
        "TOP VALUE ON STACK SHOULD BE 13");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 2) == 14, 20,
        "SECOND TOP VALUE ON STACK SHOULD BE 14");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 3) == 19, 21,
        "THIRD TOP VALUE ON STACK SHOULD BE 19");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 4) == 12, 22,
        "FOURTH TOP VALUE ON STACK SHOULD BE 12");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 4, 23,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");

    s = {};
    PushValueOntoTheStack(s, 12);
    PushValueOntoTheStack(s, 19);
    PushValueOntoTheStack(s, 14);
    PushValueOntoTheStack(s, 13);
    PopValueFromTheStack(s);
    PopValueFromTheStack(s);
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 2, 24,
        "STACK SHOULD BE SIZE 2");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 1) == 19, 25,
        "TOP VALUE ON STACK SHOULD BE 19");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 2) == 12, 26,
        "SECOND TOP VALUE ON STACK SHOULD 12");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 2, 27,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");

    s = {};
    PushValueOntoTheStack(s, 12);
    PushValueOntoTheStack(s, 19);
    PushValueOntoTheStack(s, 14);
    PushValueOntoTheStack(s, 13);
    PopValueFromTheStack(s);
    PopValueFromTheStack(s);
    PushValueOntoTheStack(s, 10);
    PushValueOntoTheStack(s, 9);
    PushValueOntoTheStack(s, 8);
    PushValueOntoTheStack(s, 7);
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 6, 28,
        "STACK SHOULD BE SIZE 6");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 1) == 7, 29,
        "TOP VALUE ON STACK SHOULD 7");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 2) == 8, 30,
        "SECOND TOP VALUE ON STACK SHOULD 8");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 3) == 9, 31,
        "THIRD TOP VALUE ON STACK SHOULD 9");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 4) == 10, 32,
        "FOURTH TOP VALUE ON STACK SHOULD 10");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 5) == 19, 33,
        "FIFTH TOP VALUE ON STACK SHOULD 19");
    IsThereAnErrorInYourCode(GetNthTopValueOfTheStack(s, 6) == 12, 34,
        "SIXTH TOP VALUE ON STACK SHOULD 12");
    IsThereAnErrorInYourCode(GetSizeOfTheStack(s) == 6, 35,
        "STACK MUST NOT BE MODIFIED TO GET VALUE FROM THE STACK");

    std::cout << "------------------------" << std::endl;
    std::cout << "IF THERE ARE NO ERROR MESSAGES ABOVE, ";
    std::cout << "THEN YOUR CODE APPEARS TO WORK AS EXPECTED!" << std::endl;
    std::cout << "------------------------" << std::endl;
    
    return 0;
}
