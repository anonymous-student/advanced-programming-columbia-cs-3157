/*
 * duper_upper.h
 */

#ifndef __DUPER_UPPER_H__
#define __DUPER_UPPER_H__

class DuperUpper {
    public:
        DuperUpper(int argc, char **argv);
        ~DuperUpper();

        char *arg_normal()  { return normal[idx]; } 
        char *arg_upper()   { return upper[idx];  }

        int top_of_list()   { return (idx == 1);   }
        int end_of_list()   { return (idx == end); }

        void go_prev()      { idx--; }
        void go_next()      { idx++; }

        // tell the compiler not to generate copy constructor & assignment
        DuperUpper(const DuperUpper& du) = delete;
        DuperUpper& operator=(const DuperUpper& du) = delete;

    private:
        char **normal;
        char **upper;
        int idx;
        int end;
};

#endif
