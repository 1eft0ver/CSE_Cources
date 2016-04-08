class toPost
{
private:
    string infix;
    string postfix;
    char temp[100];
    int top;
public:

    toPost()
    {
        postfix = "";
        top = 0;
    }

    void Change(string input)
    {
        infix = input;
        for(int i=0;i<(int)infix.size();i++)
        {
            switch(infix[i])
            {
                case '(':
                       temp[++top] = infix[i];
                       break;
                case '+':
                case '-':
                case '*':
                case '/':
                        while(Pr(temp[top]) >= Pr(infix[i]))
                        {
                            postfix+=temp[top--];
                        }
                        temp[++top] = infix[i];
                        break;
                case ')':
                    while(temp[top] != '(')
                    {
                        postfix+=temp[top--];
                    }
                    top--;
                    break;
                default:
                       postfix+=infix[i];
            }
        }
        while(top>0)
        {
            postfix+=temp[top--];
        }
    }

    int Pr(char op)	//Àu¥ý§Ç
    {
        switch(op)
        {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            default:
                return 0;
        }
    }

    string getPost()
    {
        return postfix;
    }

};