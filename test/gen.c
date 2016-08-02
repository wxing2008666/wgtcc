typedef union {
    char a;
    struct {
        int h;
        long double b;
    };
    char c;
    int d;
} foo0_t;

typedef struct {
    char a;
    short b;
    char c;
} foo1_t;

typedef struct {
    char a;
    union {
        int h;
        long double b;
    };
    char c;
    int d;
} foo2_t;

typedef struct {
    short a;
    struct {
        double b;
        float c;
    };
    char d;
} foo3_t;

typedef union {
    short a;
    union {
        double b;
        float c;
    };
    char d;
} foo3_t;


typedef int Type;
typedef int SourceLoc;
typedef int Vector;
typedef struct Node {
    int kind;
    Type *ty;
    SourceLoc *sourceLoc;
    union {
        // Char, int, or long
        long ival;
        // Float or double
        struct {
            double fval;
            char *flabel;
        };
        // String
        struct {
            char *sval;
            char *slabel;
        };
        // Local/global variable
        struct {
            char *varname;
            // local
            int loff;
            Vector *lvarinit;
            // global
            char *glabel;
        };
        // Binary operator
        struct {
            struct Node *left;
            struct Node *right;
        };
        // Unary operator
        struct {
            struct Node *operand;
        };
        // Function call or function declaration
        struct {
            char *fname;
            // Function call
            Vector *args;
            struct Type *ftype;
            // Function pointer or function designator
            struct Node *fptr;
            // Function declaration
            Vector *params;
            Vector *localvars;
            struct Node *body;
        };
        // Declaration
        struct {
            struct Node *declvar;
            Vector *declinit;
        };
        // Initializer
        struct {
            struct Node *initval;
            int initoff;
            Type *totype;
        };
        // If statement or ternary operator
        struct {
            struct Node *cond;
            struct Node *then;
            struct Node *els;
        };
        // Goto and label
        struct {
            char *label;
            char *newlabel;
        };
        // Return statement
        struct Node *retval;
        // Compound statement
        Vector *stmts;
        // Struct reference
        struct {
            struct Node *struc;
            char *field;
            Type *fieldtype;
        };
    };
} Node;


void test_foo0(foo0_t foo)
{
}

int world(void)
{
    foo0_t foo;
    test_foo0(foo);

    //test_flt(1, 2, 3, 4);
    return 0;
}
