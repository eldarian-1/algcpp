//
// Created by eldarian on 30.05.2021.
//

#ifndef ALGCPP_FRACTIONOPERATIONS_H
#define ALGCPP_FRACTIONOPERATIONS_H

#include <string>
#include <iostream>
#include <regex>
#include <cstdlib>
#include <algorithm>

#include "Algorithm.h"

struct FractionArg {
    std::string left;
    char operation;
    std::string right;

    FractionArg(const char *left, char operation, const char *right) {
        this->left = left;
        this->operation = operation;
        this->right = right;
    }
};

struct Fraction {
    long long whole;
    long long numerator;
    long long denominator;
};

class FractionOperations : public Algorithm<FractionArg> {
private:
    void buildFraction(std::string from, Fraction *to) {
        std::regex a(R"(-(\d+) (\d+)/(\d+))"), b(R"((\d+) (\d+)/(\d+))"), c(R"((\d*)/(\d*))"), d(R"(\d*)");
        std::smatch m;
        if(std::regex_match(from, a)) {
            std::regex_search(from, m, a);
            to->whole = -std::atoi(m[1].str().c_str());
            to->numerator = std::atoi(m[2].str().c_str());
            to->denominator = std::atoi(m[3].str().c_str());
        } else if(std::regex_match(from, b)) {
            std::regex_search(from, m, b);
            to->whole = std::atoi(m[1].str().c_str());
            to->numerator = std::atoi(m[2].str().c_str());
            to->denominator = std::atoi(m[3].str().c_str());
        } else if(std::regex_match(from, b)) {
            std::regex_search(from, m, a);
            to->whole = 0;
            to->numerator = std::atoi(m[1].str().c_str());
            to->denominator = std::atoi(m[2].str().c_str());
        } else if(std::regex_match(from, c)) {
            std::regex_search(from, m, a);
            to->whole = std::atoi(m[0].str().c_str());
            to->numerator = 0;
            to->denominator = 1;
        }
    }

    Fraction toSimple(const Fraction &from) {
        Fraction result = from;
        if(result.whole > 0)
            result.numerator += result.denominator * result.whole;
        else
            result.numerator = -(result.numerator - result.denominator * result.whole);
        result.whole = 0;
        return result;
    }

    Fraction toFullForm(const Fraction &from) {
        Fraction result = from;
        long long t = gcf(result.numerator, result.denominator);
        result.numerator /= t;
        result.denominator /= t;
        result.whole = result.numerator / result.denominator;
        result.numerator %= result.denominator;
        if(result.denominator < 0 && result.whole == 0) {
            result.denominator *= -1;
            result.numerator *= -1;
        } else if(result.denominator < 0 && result.whole != 0) {
            result.denominator *= -1;
            result.whole *= -1;
        } else if(result.numerator < 0 && result.whole != 0) {
            result.numerator *= -1;
        }
        return result;
    }

    long long gcf(long long a, long long b) {
        return std::__gcd(a, b);
        /*a = abs(a);
        b = abs(b);
        while(a != 0 && b != 0)
            if(a > b)
                a %= b;
            else
                b %= a;
        return a + b;*/
    }

    void calculate(const Fraction &left, const Fraction &right, const char &operation, Fraction *result) {
        Fraction l = toSimple(left);
        Fraction r = toSimple(right);
        switch(operation) {
            case '+':
                l.numerator *= r.denominator;
                r.numerator *= l.denominator;
                l.numerator += r.numerator;
                l.denominator *= r.denominator;
                break;
            case '-':
                l.numerator *= r.denominator;
                r.numerator *= l.denominator;
                l.numerator -= r.numerator;
                l.denominator *= r.denominator;
                break;
            case '*':
                l.numerator *= r.numerator;
                l.denominator *= r.denominator;
                break;
            case '/':
                l.numerator *= r.denominator;
                l.denominator *= r.numerator;
                break;
        }
        *result = toFullForm(l);
    }

    std::string toString(const Fraction &fraction) {
        std::string result = "";
        if(fraction.whole != 0)
            result += std::to_string(fraction.whole);
        if(fraction.numerator)
            result += (result != "" ? " " : "") + std::to_string(fraction.numerator) + "/" + std::to_string(fraction.denominator);
        if(result == "")
            result = "0";
        return result;
    }

    void printExample(const Fraction &left, const Fraction &right, const char &operation, const Fraction &result) {
        std::cout << toString(left) << ' ' << operation << ' ' << toString(right) << " = " << toString(result) << '\n';
    }

protected:
    const char *name() override {
        return "FractionOperations";
    }

    void run(FractionArg *arg) override {
        Fraction left, right, result;
        buildFraction(arg->left, &left);
        buildFraction(arg->right, &right);
        calculate(left, right, arg->operation, &result);
        printExample(left, right, arg->operation, result);
    }
};

#endif //ALGCPP_FRACTIONOPERATIONS_H
