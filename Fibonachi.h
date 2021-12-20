#pragma once

#include "Algorithm.h"

#include <vector>

enum FibonachiType {
    DYNAMIC, RECURSION, TAIL
};

struct FibonachiArg {
    int n;
    FibonachiType type;
};

class Fibonachi: public Algorithm<FibonachiArg> {
private:
    class Type {
    protected:
        int it = 0;
    public:
        virtual const char *type() = 0;
        virtual int run(int n) = 0;
        int iter() const {
            return it;
        }
    };

    class Dinamic : public Type {
    private:
        std::vector<int> v;

        int dyn(int n) {
            if (n < 2) {
                return 1;
            }
            if (v[n] != -1) {
                return v[n];
            }
            ++it;
            return (v[n] = dyn(n - 1) + dyn(n - 2));
        }
    public:
        const char *type() override {
            return "динамическое программирование";
        }
        int run(int n) override {
            v = std::vector<int>(n + 1, -1);
            return dyn(n);
        }
    };

    class Recursion : public Type {
    public:
        const char *type() override {
            return "классическая рекурсия";
        }
        int run(int n) override {
            if (n < 2) {
                return 1;
            }
            ++it;
            return run(n - 1) + run(n - 2);
        }
    };

    class Tail : public Type {
    public:
        const char *type() override {
            return "хвостовая рекурсия";
        }
        int run(int n) override {
            int r = 1, l = 1, t;
            for(int i = 2; i <= n; ++i) {
                ++it;
                t = r;
                r += l;
                l = t;
            }
            return r;
        }
    };

    Type *type(FibonachiType t) {
        switch(t) {
            case FibonachiType::DYNAMIC: return new Dinamic;
            case FibonachiType::RECURSION: return new Recursion;
            case FibonachiType::TAIL: return new Tail;
            default: return nullptr;
        }
    }

protected:
    const char *name() override {
        return "Fibonachi";
    }

    void run(FibonachiArg *arg) override {
        Type *f = type(arg->type);
        int r = f->run(arg->n);
        printf("Число Фибоначи под номером %d: %d (%s, %d итераций)", arg->n, r, f->type(), f->iter());
        delete f;
    }
};
