#include "porta.h"

/// Implementação das portas lógicas

/// Porta NOT
bool PortaNOT::simular(const std::vector<bool3S>& in_port) {
    if (in_port.size() != 1) {
        out_port = bool3S::UNDEF;
        return false;
    }

    out_port = ~in_port[0];
    return true;
}

/// Porta AND
bool PortaAND::simular(const std::vector<bool3S>& in_port) {
    if (in_port.size() != getNumInputs()) {
        out_port = bool3S::UNDEF;
        return false;
    }

    if(in_port.size()==0){
        return false;
    }

    bool3S resultado = in_port[0];
    for (size_t i = 1; i < in_port.size(); ++i) {
        resultado &= in_port[i];
    }
    out_port = resultado;
    return true;
}

/// Porta NAND
bool PortaNAND::simular(const std::vector<bool3S>& in_port) {
    if (in_port.size() != getNumInputs()) {
        out_port = bool3S::UNDEF;
        return false;
    }

    if(in_port.size()==0){
        return false;
    }

    PortaAND andGate(getNumInputs());
    if (!andGate.simular(in_port)) {
        out_port = bool3S::UNDEF;
        return false;
    }
    out_port = ~andGate.getOutput();
    return true;

}

/// Porta OR
bool PortaOR::simular(const std::vector<bool3S>& in_port) {
    if (in_port.size() != getNumInputs()) {
        out_port = bool3S::UNDEF;
        return false;
    }

    if(in_port.size()==0){
        return false;
    }

    bool3S resultado = in_port[0];
    for (size_t i = 1; i < in_port.size(); ++i) {
        resultado |= in_port[i];
    }
    out_port = resultado;
    return true;

}

/// Porta NOR
bool PortaNOR::simular(const std::vector<bool3S>& in_port) {
    if (in_port.size() != getNumInputs()) {
        out_port = bool3S::UNDEF;
        return false;
    }

    if(in_port.size()==0){
        return false;
    }
    PortaOR orGate(getNumInputs());
    if (!orGate.simular(in_port)) {
        out_port = bool3S::UNDEF;
        return false;
    }
    out_port = ~orGate.getOutput();
    return true;

}

/// Porta XOR
bool PortaXOR::simular(const std::vector<bool3S>& in_port) {
    if (in_port.size() != getNumInputs()) {
        out_port = bool3S::UNDEF;
        return false;
    }


    if(in_port.size()==0){
        return false;
    }

    bool3S resultado = in_port[0];
    for (size_t i = 1; i < in_port.size(); ++i) {
        resultado ^= in_port[i];
    }
    out_port = resultado;
    return true;
}

/// Porta NXOR
bool PortaNXOR::simular(const std::vector<bool3S>& in_port) {
    if (in_port.size() != getNumInputs()) {
        out_port = bool3S::UNDEF;
        return false;
    }

    if(in_port.size()==0){
        return false;
    }

    PortaXOR xorGate(getNumInputs());
    if (!xorGate.simular(in_port)) {
        out_port = bool3S::UNDEF;
        return false;
    }
    out_port = ~xorGate.getOutput();
    return true;

}
