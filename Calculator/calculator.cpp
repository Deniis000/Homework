#include <iostream>

enum kind {
	operations,
	numbers
};

struct tokenexam {
	kind type;
	int value;
	char oper;
};

long long factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    if (op == '!') return 4;
    if (op == '(') return -1;
    if (op == ')') return 0;
    return 0;
}

bool cfn (char num) {
	return(num >= '0' && num <= '9'); //condition of numbers
}

int applyOperation(int a, int b, char oper) {
    switch (oper) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // Assume valid division
        case '^': {
            int result = 1;
            for (int i = 0; i < b; i++) {
                result *= a;
            }
            return result;
        }
        case '!': return factorial(a);
        default: return 0;
    }
}

class SimpleStack {
private:
    int stack[150];
    int top;

public:
    SimpleStack() : top(-1) {}

    void push(int value) {
        if (top < 149) {
            stack[++top] = value;
        }
    }

    int pop() {
        if (top >= 0) {
            return stack[top--];
        }
        return -1; // Return an invalid value if the stack is empty
    }

    int peek() {
        if (top >= 0) {
            return stack[top];
        }
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
	while(1) {
	char n[255];
	std::cout << "Enter your problem: ";
	std::cin >> n;
	//1 6 * 4
	//16(num)*op 4(num)
	
tokenexam tokens[150], rpn[150];
int t = 0, r = 0;

for (int i = 0; n[i]!='\0'; i++) {
	if (cfn (n[i])) {
	int value = 0;
	while (cfn (n[i])) {
	value = value *10 + (n[i] - '0');
		i++;
		}
	i--;
tokens[t++] = {numbers, value, '\0'};
std::cout << "Number: " << value << std::endl;
	}

//5 6 * 9
else if (n[i]=='+' || n[i]=='-' || n[i]=='*' || n[i]=='/' || n[i]=='^' || n[i]=='!' || n[i]=='(' || n[i]==')') {
	    tokens[t++] = {operations, '\0', n[i]};
	    std::cout << "Operator: " << n[i] << std::endl;
			}
		}
		tokenexam save[150];
		int j = 0;
		for (int i = 0; i < t; i++) {
			if (tokens[i].type == numbers) {
				rpn[r++] = tokens[i];
		}
			else if (tokens[i].type == operations) {
                if (tokens[i].oper == '(') {
                    save[j++] = tokens[i];
                }
                else if (tokens[i].oper == ')') {
                    while (j > 0 && save[j - 1].oper != '(') {
                        rpn[r++] = save[--j];
                    }
                    j--; //Pop the '('
		}
	else {
		while (j > 0 && priority(save[j - 1].oper)>= priority(tokens[i].oper)) { //3 + 8 * 4 - 2
		rpn[r++] = save[--j];
			}
		save[j++] = tokens[i];
			}
		}
        }

        // Pop remaining operators from the stack
        while (j > 0) {
            rpn[r++] = save[--j];
        }

        // Evaluate the RPN expression
        SimpleStack calcStack;
        for (int i = 0; i < r; i++) {
            if (rpn[i].type == numbers) {
                calcStack.push(rpn[i].value);
            }
            else if (rpn[i].type == operations) {
                int b = calcStack.pop();
                int a = calcStack.pop();
                int result = applyOperation(a, b, rpn[i].oper);
                calcStack.push(result);
            }
        }

        // Final result
        if (!calcStack.isEmpty()) {
            std::cout << "Result: " << calcStack.peek() << std::endl;
        }
    }

    return 0;
}
