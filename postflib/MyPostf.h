#pragma once
#include "MyPostf.h"
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
class MyPostf {
private:
    string infix;
    string postfix;
    vector<string> lexems;
    map<string, int> priority;
    vector<string> operands;

public:
    MyPostf(string infix);
    string GetInfix();
    string GetPostfix();
    void Parse();
    void ToPostfix();
    vector<string> GetOperands();
    double Calculate(const map<string, double>& values);
};

MyPostf::MyPostf(string infix) : infix(infix), priority({ {"(", 1}, {")", 1}, {"+", 2}, {"-", 2}, {"*", 3}, {"/", 3}}) {
    Parse();
    ToPostfix();
}

string MyPostf::GetInfix() {
    return infix;
}

string MyPostf::GetPostfix() {
    return postfix;
}

void MyPostf::Parse() {
    istringstream iss(infix);
    string token;
    while (iss >> token) {
        lexems.push_back(token);
    }
}

void MyPostf::ToPostfix() {
    stack<string> st;
    string stackItem;
    for (string item : lexems) {
        if (item == "(")
            st.push(item);
        else if (item == ")") {
            stackItem = st.top();
            st.pop();
            while (stackItem != "(") {
                postfix += stackItem + ' ';
                stackItem = st.top();
                st.pop();
            }
        }
        else if (item == "+" || item == "-" || item == "*" || item == "/") {
            while (!st.empty()) {
                stackItem = st.top();
                st.pop();
                if (priority[item] <= priority[stackItem])
                    postfix += stackItem + ' ';
                else {
                    st.push(stackItem);
                    break;
                }
            }
            st.push(item);
        }
        else{
            operands.push_back(item);
            postfix += item + ' ';
        } 
    } 
    while (!st.empty()) {
        stackItem = st.top();
        st.pop();
        postfix += stackItem + ' ';
    }
}

vector<string> MyPostf::GetOperands() {
    return operands;
}

double MyPostf::Calculate(const map<string, double>& values) {
    stack<double> st;
    istringstream iss(postfix);
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            st.push(stod(token));
        }
        else if (token.size() == 1 && priority.find(token) != priority.end()) {
            double rightOperand = st.top();
            st.pop();
            double leftOperand = st.top();
            st.pop();
            switch (token[0]) {
            case '+': st.push(leftOperand + rightOperand); break;
            case '-': st.push(leftOperand - rightOperand); break;
            case '*': st.push(leftOperand * rightOperand); break;
            case '/': st.push(leftOperand / rightOperand); break;
            }
        }
        else {
            st.push(values.at(token));
        }
    }
    return st.empty() ? 0 : st.top();
}

