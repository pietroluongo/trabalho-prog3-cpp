#include "Docente.h"
#include "Producao.h"

namespace prog3 {

    Docente::Docente(int c, string n, string d) {
        this->codigo = c;
        this->nome = n;
        this->departamento = d;
        this->horasAulaSemanais = 0;
        this->horasAulaSemestrais = 0;
    }

    Docente::~Docente() {

    }

    void Docente::print() {
        cout << "Nome: " << this->nome << "\nCodigo: " << this->codigo << "\nDepartamento: " << this->departamento;
    }

    string Docente::to_string() {
        string ret = "";
        ret.append("Nome: ");
        ret.append(this->nome);
        ret.append("\nCodigo: ");
        ret.append(std::to_string(this->codigo));
        ret.append("\nDepartamento: ");
        ret.append(this->departamento);
        return ret;
    }

    string Docente::getNome() {
        return this->nome;
    }

    void Docente::adicionaProducao(Producao& p) {
        this->producoes.push_back(&p);
    }

    void Docente::adicionaAtividade(Atividade& a) {
        this->atividades.push_back(&a);
    }

    void Docente::adicionaHorasAulaSemanais(int val) {
        this->horasAulaSemanais += val;
    }

    void Docente::adicionaHorasAulaSemestrais(int val) {
        this->horasAulaSemestrais += val;
    }

    void Docente::adicionaHorasOrientacao(int val) {
        this->horasOrientacaoSemanais += val;
    }


    vector<string> Docente::getCSVData() {
        unsigned long prodQual = 0;
        unsigned long prodUnqual = 0;
        for(Producao* p : this->producoes) {
            if(p->isQualificada()) {
                prodQual++;
            }
        }
        prodUnqual = this->producoes.size() - prodQual;

        vector<string> vec = {
                this->nome,
                this->departamento,
                std::to_string(this->horasAulaSemanais),
                std::to_string(this->horasAulaSemestrais),
                std::to_string(this->horasOrientacaoSemanais),
                std::to_string(prodQual),
                std::to_string(prodUnqual)
                };
        return vec;
    }

    ostream &operator<<(ostream &os, const Docente &doc) {
        os << "Nome: " << doc.nome << "\nCodigo: " << doc.codigo << "\nDepartamento: " << doc.departamento;
        return os;
    }

    ostream &operator<<(ostream &os, const Docente* doc) {
        os << "Nome: " << doc->nome << "\nCodigo: " << doc->codigo << "\nDepartamento: " << doc->departamento;
        return os;
    }

    bool operator<(Docente const& a, Docente const& b) {
        return cpp_util::stringCompare(a.nome, b.nome);
    }

}

