#ifndef STUDENT_H
#define STUDENT_H

class Binops {
    private:
        double opnd1;
        double opnd2;
        char op;
    public:
        Binops() = default;
        Binops(double a, char oper, double b) : opnd1(a), op(oper), opnd2(b) {}

        void set_opnd1(double value) { opnd1 = value; }
        double get_opnd1() const { return opnd1; }

        void set_opnd2(double value) { opnd2 = value; }
        double get_opnd2() const { return opnd2; }

        void set_op(char operatorChar) { op = operatorChar; }
        char get_op() const { return op; }

        double perform_operation() const;
};
#endif // STUDENT_H