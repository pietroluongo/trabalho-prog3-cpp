//
// Created by gabriel on 02/07/18.
//

#include "ClassInconsistencyException.h"
/**
    *****************************************************************************************
    *  @brief      Construtor da classe
    *
    *  @param      const string& codigo      Codigo inconsistente
    *  @param      const string& nome        Nome do curso inconsistente
    *
    ****************************************************************************************/
ClassInconsistencyException::ClassInconsistencyException(const string& codigo, const string& nome) {
    this->msg_ = "Inconsistência ao definir o nível do curso: " + codigo + " - " + nome + ".";
}