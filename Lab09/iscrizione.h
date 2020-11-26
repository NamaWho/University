struct elem {
    char nome[30 + 1];
    int pettorale;
    elem *pun;
};

void init(elem *&);

void visualizza(elem *);

bool aggiungi(elem *&, const char *, int);

bool cerca(elem *, const char *);

bool elimina(elem* &, const char *);
