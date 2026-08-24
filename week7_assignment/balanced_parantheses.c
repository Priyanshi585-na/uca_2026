#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isBalanced(char expression[])
{
    char stack[31];
    int top = -1;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            stack[++top] = ch;
        }

        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (top == -1)
                return false;

            char open = stack[top--];

            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{'))
            {
                return false;
            }
        }
    }

    return top == -1;
}

int main()
{
    char expression[31];

    scanf("%30s", expression);

    if (isBalanced(expression))
        printf("true");
    else
        printf("false");

    return 0;
}
