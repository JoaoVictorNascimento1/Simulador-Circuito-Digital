#include <fstream>
#include "circuito.h"

///
/// CLASSE CIRCUITO
///

/// *********
/// Inicializacao e finalizacao
/// *********

// Construtor por copia
Circuito::Circuito(const Circuito& C)
    : Nin_circ(C.Nin_circ),
    ports(C.ports.size(), nullptr),
    out_circ(C.out_circ),
    id_in(C.id_in),
    id_out(C.id_out)
{
    // Copia cada porta
    for (size_t i = 0; i < C.ports.size(); ++i) {
        if (C.ports[i] != nullptr) {
            ports[i] = C.ports[i]->clone();  // Cria uma nova instância da porta
        }
    }
}

// Construtor por movimento
Circuito::Circuito(Circuito&& C) noexcept
    : Nin_circ(C.Nin_circ),
    ports(std::move(C.ports)),
    out_circ(std::move(C.out_circ)),
    id_in(std::move(C.id_in)),
    id_out(std::move(C.id_out))
{
    // Deixa o objeto movido em um estado válido
    C.Nin_circ = 0;
    C.ports.clear();
    C.out_circ.clear();
    C.id_in.clear();
    C.id_out.clear();
}

// Limpa todo o conteudo do circuito.
void Circuito::clear() noexcept {
    for (auto& port : ports) {
        delete port;  // Desaloca as portas dinâmicas
        port = nullptr;
    }
    ports.clear();
    out_circ.clear();
    id_in.clear();
    id_out.clear();
    Nin_circ = 0;
}

// Operador de atribuicao por copia
Circuito& Circuito::operator=(const Circuito& C) {
    if (this == &C) return *this;  // Proteção contra autoatribuição

    clear();  // Limpa o estado atual do circuito

    // Copia atributos
    Nin_circ = C.Nin_circ;
    out_circ = C.out_circ;
    id_in = C.id_in;
    id_out = C.id_out;

    // Copia as portas
    ports.resize(C.ports.size(), nullptr);
    for (size_t i = 0; i < C.ports.size(); ++i) {
        if (C.ports[i] != nullptr) {
            ports[i] = C.ports[i]->clone();  // Cria uma cópia da porta
        }
    }

    return *this;
}

// Operador de atribuicao por movimento
Circuito& Circuito::operator=(Circuito&& C) noexcept {
    if (this == &C) return *this;  // Proteção contra autoatribuição

    clear();  // Limpa o estado atual do circuito

    // Transfere atributos
    Nin_circ = C.Nin_circ;
    ports = std::move(C.ports);
    out_circ = std::move(C.out_circ);
    id_in = std::move(C.id_in);
    id_out = std::move(C.id_out);

    // Deixa o objeto fonte em estado válido
    C.Nin_circ = 0;
    C.ports.clear();
    C.out_circ.clear();
    C.id_in.clear();
    C.id_out.clear();

    return *this;
}

// Redimensiona o circuito
void Circuito::resize(int NI, int NO, int NP) {
    if (NI <= 0 || NO <= 0 || NP <= 0) return;
    clear();  // Limpa o circuito atual
    Nin_circ = NI;
    ports.resize(NP, nullptr);
    out_circ.resize(NO, bool3S::UNDEF);
    id_in.resize(NP);
    for (int i = 0; i < NP; ++i) {
        id_in[i].clear();
    }
    id_out.resize(NO, 0);
}

/// *********
/// Funcoes de testagem
/// *********

// Testa igualdade entre circuitos
bool Circuito::operator==(const Circuito& C) const
{
    // Testa a igualdade do numero de entradas, saidas e portas
    if (getNumInputs() != C.getNumInputs() ||
        getNumOutputs() != C.getNumOutputs() ||
        getNumPorts() != C.getNumPorts()) return false;

    int id;
    // Testa a igualdade das portas
    for (id=1; id<=getNumPorts(); ++id)
    {
        if (definedPort(id))
        {
            if (!C.definedPort(id)) return false;
            if (getNamePort(id) != C.getNamePort(id)) return false;
            if (getNumInputsPort(id) != C.getNumInputsPort(id)) return false;
            for (int j=0; j<getNumInputsPort(id); ++j)
            {
                if (getIdInPort(id,j) != C.getIdInPort(id,j)) return false;
            }
        }
        else if (C.definedPort(id)) return false;
    }
    // Testa a igualdade das saidas
    for (id=1; id<=getNumOutputs(); ++id)
    {
        if (getIdOutputCirc(id) != C.getIdOutputCirc(id)) return false;
    }
    // Tudo igual!
    return true;
}

// Testa circuito valido
bool Circuito::valid() const
{
    int id;
    // Testa o numero de entradas, saidas e portas
    if (getNumInputs()<=0 || getNumOutputs()<=0 || getNumPorts()<=0) return false;
    // Testa cada porta
    for (id=1; id<=getNumPorts(); ++id)
    {
        if (!definedPort(id)) return false;
        for (int j=0; j<getNumInputsPort(id); ++j)
        {
            if (!validIdOrig(getIdInPort(id,j))) return false;
        }
    }
    // Testa cada saida
    for (id=1; id<=getNumOutputs(); ++id)
    {
        if (!validIdOrig(getIdOutputCirc(id))) return false;
    }
    // Tudo valido!
    return true;
}

/// *********
/// Funcoes de modificacao
/// *********

// A porta cuja id eh IdPort passa a ser do tipo Tipo (NT, AN, etc.), com Nin entradas.
// Tambem altera o numero de conexoes dessa porta no vetor id_in, para ser igual ao novo
// numero de entradas da porta.
// Caso necessario, converte os caracteres da string Tipo para maiusculas.
// Se der tudo certo, retorna true. Se algum parametro for invalido, retorna false.
bool Circuito::setPort(int IdPort, std::string& Tipo, int Nin)
{
    // Chegagem dos parametros
    if (!validIdPort(IdPort)) return false;
    if (Tipo.size()!=2) return false;
    Tipo.at(0) = toupper(Tipo.at(0));
    Tipo.at(1) = toupper(Tipo.at(1));
    if (Tipo!="NT" &&
        Tipo!="AN" && Tipo!="NA" &&
        Tipo!="OR" && Tipo!="NO" &&
        Tipo!="XO" && Tipo!="NX") return false;
    if (Tipo=="NT" && Nin!=1) return false;
    if (Tipo!="NT" && Nin<2) return false;

    // Altera a porta:
    // - cria a nova porta
    // - redimensiona o vetor de conexoes da porta

    delete ports[IdPort - 1];  // Remove a porta anterior, se existir
    if (Tipo == "NT") ports[IdPort - 1] = new PortaNOT();
    else if (Tipo == "AN") ports[IdPort - 1] = new PortaAND(Nin);
    else if (Tipo == "NA") ports[IdPort - 1] = new PortaNAND(Nin);
    else if (Tipo == "OR") ports[IdPort - 1] = new PortaOR(Nin);
    else if (Tipo == "NO") ports[IdPort - 1] = new PortaNOR(Nin);
    else if (Tipo == "XO") ports[IdPort - 1] = new PortaXOR(Nin);
    else if (Tipo == "NX") ports[IdPort - 1] = new PortaNXOR(Nin);

    id_in[IdPort - 1].resize(Nin, 0);  // Ajusta o número de conexões

    return true;
}

// Altera a origem de uma entrada de uma porta
bool Circuito::setIdInPort(int IdPort, int I, int IdOrig)
{
    // Chegagem dos parametros
    if (!definedPort(IdPort)) return false;
    if (!ports.at(IdPort-1)->validIndex(I)) return false;
    if (!validIdOrig(IdOrig)) return false;
    // Fixa a origem da entrada
    id_in.at(IdPort-1).at(I) = IdOrig;
    return true;
}

// Altera a origem de uma saida
bool Circuito::setIdOutputCirc(int IdOut, int IdOrig)
{
    if (!validIdOutputCirc(IdOut) || !validIdOrig(IdOrig)) return false;
    id_out.at(IdOut-1) = IdOrig;
    return true;
}

/// *********
/// E/S de dados
/// *********

// Entrada dos dados de um circuito via arquivo
bool Circuito::ler(const std::string& arq)
{
    // Novo circuito provisorio a ser lido do arquivo
    Circuito prov;
    // A stream do arquivo a ser lido
    std::ifstream myfile(arq);

    try
    {
        if (!myfile.is_open()) throw 1;

        // Variaveis temporarias para leitura
        std::string pS;
        int NI,NO,NP;
        char c;
        std::string Tipo;
        int Nin_port;
        int id_orig;
        int i,id,I;

        // Lendo as dimensoes do circuito
        myfile >> pS >> NI >> NO >> NP;
        if (!myfile.good() || pS!="CIRCUITO" ||
            NI<=0 || NO<=0 || NP<=0) throw 2;
        // Redimensionando o novo circuito
        prov.resize(NI, NO, NP);

        // Lendo as portas do circuito
        myfile >> pS;
        if (!myfile.good() || pS!="PORTAS") throw 3;
        for (i=0; i<prov.getNumPorts(); ++i)
        {
            // Lendo o tipo e o numero de entradas de uma porta
            myfile >> id >> c >> Tipo >> Nin_port;
            if (!myfile.good() || id != i+1 || c!=')' ||
                !prov.setPort(id,Tipo,Nin_port)) throw 4;
        }

        // Lendo a conectividade das portas
        myfile >> pS;
        if (!myfile.good() || pS!="CONEXOES") throw 5;
        for (i=0; i<prov.getNumPorts(); ++i)
        {
            // Lendo a id da porta
            myfile >> id >> c;
            if (!myfile.good() || id != i+1 || c!=')') throw 6;
            // Lendo as ids das entradas da porta
            for (I=0; I<prov.getNumInputsPort(id); ++I)
            {
                myfile >> id_orig;
                if (!myfile.good() ||
                    !prov.setIdInPort(id, I, id_orig)) throw 7;
            }
        }

        // Lendo as saidas do circuito
        myfile >> pS;
        if (!myfile.good() || pS!="SAIDAS") throw 8;
        for (i=0; i<prov.getNumOutputs(); ++i)
        {
            // Lendo a id de uma saida do circuito
            myfile >> id >> c >> id_orig;
            if (!myfile.good() || id != i+1 || c!=')' ||
                !prov.setIdOutputCirc(id, id_orig)) throw 9;
        }
    }
    catch (int erro)
    {
        return false;
    }

    // Leitura OK
    // Faz o circuito assumir as caracteristicas lidas do arquivo
    *this = std::move(prov);
    return true;
}

// Saida dos dados de um circuito
std::ostream& Circuito::escrever(std::ostream& O) const
{
    // Soh imprime se o circuito for valido
    if (!valid()) return O;

    int id,I;

    O << "CIRCUITO "
      << getNumInputs() << ' '
      << getNumOutputs() << ' '
      << getNumPorts() << std::endl;
    O << "PORTAS\n";
    for (id=1; id<=getNumPorts(); ++id)
    {
        O << id << ") " << getNamePort(id) << ' '
          << getNumInputsPort(id) << std::endl;
    }
    O << "CONEXOES\n";
    for (id=1; id<=getNumPorts(); ++id)
    {
        O << id << ')';
        for (I=0; I<getNumInputsPort(id); ++I)
        {
            O << ' ' << getIdInPort(id,I);
        }
        O << std::endl;
    }
    O << "SAIDAS\n";
    for (id=1; id<=getNumOutputs(); ++id)
    {
        O << id << ") " << getIdOutputCirc(id) << std::endl;
    }
    return O;
}

// Salvar circuito em arquivo
bool Circuito::salvar(const std::string& arq) const
{
    if (!valid()) return false;

    std::ofstream myfile(arq);
    if (!myfile.is_open()) return false;
    escrever(myfile);
    return true;
}

/// *********
/// SIMULACAO (funcao principal do circuito)
/// *********

// Simula o circuito
bool Circuito::simular(const std::vector<bool3S>& in_circ) {
    // Verifica se o circuito e os parâmetros de entrada são válidos
    if (!valid() || int(in_circ.size()) != getNumInputs()) {
        return false;
    }

    // Inicializa as saídas das portas como indefinidas
    for (auto& porta : ports) {
        if (porta) {
            porta->setOutput(bool3S::UNDEF);
        }
    }

    // Variáveis auxiliares
    bool tudo_def = true;       // Indica se todas as saídas estão definidas
    bool alguma_def = false;    // Indica se pelo menos uma saída foi definida

    // Algoritmo iterativo para simulação
    do {
        tudo_def = true;
        alguma_def = false;

        // Itera sobre todas as portas do circuito
        for (int id_port = 1; id_port <= getNumPorts(); ++id_port) {
            if (!definedPort(id_port)) continue;  // Porta não definida

            // Obtém a porta e verifica se a saída já foi calculada
            auto* porta = ports[id_port - 1];
            if (porta->getOutput() != bool3S::UNDEF) {
                continue;  // Saída já calculada
            }

            // Coleta os valores das entradas da porta
            std::vector<bool3S> entradas(porta->getNumInputs());
            for (int i = 0; i < porta->getNumInputs(); ++i) {
                int id_origem = getIdInPort(id_port, i);

                // Determina o valor da entrada com base na origem
                if (id_origem > 0) {  // Sinal vem da saída de outra porta
                    entradas[i] = getOutputPort(id_origem);
                } else if (id_origem < 0) {  // Sinal vem de uma entrada do circuito
                    entradas[i] = in_circ[-id_origem - 1];  // -id_origem ajusta o índice
                } else {
                    entradas[i] = bool3S::UNDEF;  // Entrada indefinida
                }
            }


            porta->simular(entradas);

            // Simula a porta com as entradas coletadas
            if (porta->getOutput()==bool3S::UNDEF) {
                alguma_def = true;
            } else {
                tudo_def = false;
            }
        }
    } while (!tudo_def && alguma_def);

    // Determinação das saídas do circuito
    for (int id_out = 1; id_out <= getNumOutputs(); ++id_out) {
        int id_origem = getIdOutputCirc(id_out);

        // Determina o valor da saída com base na origem
        if (id_origem > 0) {  // Vem da saída de uma porta
            out_circ[id_out - 1] = getOutputPort(id_origem);
        } else if (id_origem < 0) {  // Vem de uma entrada do circuito
            out_circ[id_out - 1] = in_circ[-id_origem - 1];
        } else {
            out_circ[id_out - 1] = bool3S::UNDEF;  // Saída indefinida
        }
    }

    // Retorna sucesso se a simulação foi concluída
    return tudo_def;
}
