//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_CURSO_H
#define TRABALHO_PROG3_CURSO_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace prog3 {

    //Forward declaration
    class Discente;
    class Disciplina;
    class OrientaGrad;

    class Curso {
    private:
        int codigo;
        string nome;
        bool grad;
        vector<Discente*> discentes;
        vector<Disciplina*> disciplinas;
        vector<OrientaGrad*> orientacoesGrad;
    public:
        Curso(string = "", int = 0, bool = false);
        ~Curso();
        int getCodigo();
        void adicionaDiscente(Discente &d);
        void adicionaDisciplina(Disciplina& d);
        void adicionaOrientaGrad(OrientaGrad& o);
    };

}
#endif //TRABALHO_PROG3_CURSO_H