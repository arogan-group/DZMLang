// (c) ZaKlaus 2016; Apache 2 Licensed, see LICENSE;;

static inline OBJECT *
make_lambda(OBJECT *Parameters, OBJECT *Body)
{
    OBJECT *r = MAKE1(PAIR, Parameters, Body);
    return(MAKE1(PAIR, LambdaSymbol,
                     r));
}

static inline b32
is_lambda(OBJECT *Exp)
{
    return(is_tagged_list(Exp, LambdaSymbol));
}

static inline OBJECT *
lambda_parameters(OBJECT *Exp)
{
    return(pair_get_a(pair_get_b(Exp)));
}

static inline OBJECT *
lambda_body(OBJECT *Exp)
{
    return(pair_get_b(pair_get_b(Exp)));
}