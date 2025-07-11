#include <iostream>
using namespace std;

// Declaracao da classe No
class No
{
    //propriedades privadas
    private:
        int valor;
        No *proximo;

    public:
        // Metodos publicos (Construtor e demais)
        No(int valor)
        {
            this -> valor = valor;
            this -> proximo = NULL;
        }

        No *obterProx() { return proximo; }
        int obterValor() { return valor; }
        void setProx(No *elemento) { proximo = elemento; }
};

// Declaracao da classe Lista
class Lista
{
    private:
        // primeiro elemento
        No *primeiro;
        // ultimo elemento
        No *ultimo;

    public:
        // Construtores da classe
        Lista()
        {
            primeiro = NULL;
            ultimo = NULL;
        }

        Lista(int valor)
        {
            // se passar elemento, entao cria novo No
            primeiro = new No(valor);
            ultimo = primeiro;
        }

        // Destrutor (utiliza o ~ na frente sempre)
        virtual ~Lista()
        {
            delete primeiro;
        }

        //
        // Demais funcionalidades
        //
        // Tamanho da lista
        int tamanho()
        {
            if (listVazia()) // se for vazia, entao retorna 0
                return 0;

            No *atual = primeiro;
            int tamanho = 0;

            // percorre a lista
            do
            {
                atual = atual -> obterProx();
                tamanho++;

            } while (atual);

            return tamanho;
        }

        // verifica se um elemento existe na lista
        bool existeNo(int valor)
        {
            No *atual = primeiro;

            while (atual)
            {
                if (atual -> obterValor() == valor)
                    return true;

                atual = atual->obterProx();
            }

            return false;
        }

        void mostrarLista()
        {
            cout << "\nImprimindo todos os elementos...\n";
            No *atual = primeiro;

            if (listVazia())
                cout << "A lista NAO possui elementos!!\n";
            else
            {
                while (atual) // percorre a lista
                {
                    cout << atual -> obterValor() << endl;
                    atual = atual -> obterProx();
                }

                cout << endl;

            }
        }

        bool listVazia() // verifica se a lista esta vazia
        {
            return (primeiro == NULL);
        }

        // insere no inicio (semelhante a push_front da list)
        void inserir_inicio(int valor)
        {
            No *novo_no = new No(valor);

            if (listVazia())
            {
                primeiro = novo_no;
                ultimo = novo_no;

            }
            else
            {
                novo_no->setProx(primeiro);
                primeiro = novo_no;

            }
        }

        // insere no final (semelhante a push_back da list)
        void inserir_final(int valor)
        {
            No *novo_no = new No(valor);

            if (listVazia())
            {
                primeiro = novo_no;
                ultimo = novo_no;

            }
            else
            {
                ultimo->setProx(novo_no);
                ultimo = novo_no;

            }
        }


        // remove da lista, remocao do final (semelhante a pop_back da list)
        void removerNo()
        {
            if (!listVazia())
            {
                // se houver so 1 elemento
                if (primeiro->obterProx() == NULL)
                    primeiro = NULL;

                else if (primeiro -> obterProx() -> obterProx() == NULL) // 2 elementos
                    primeiro->setProx(NULL);

                else // > 2 elementos
                {
                    No *ant_ant = primeiro;
                    No *ant = primeiro -> obterProx();
                    No *corrente = primeiro -> obterProx() -> obterProx();

                    while (corrente)
                    {
                        No *aux = ant;
                        ant = corrente;
                        ant_ant = aux;
                        corrente = corrente->obterProx();
                    }

                    // Excluir o elemento
                    delete ant_ant->obterProx();

                     // seta o prox como NULL
                    ant_ant->setProx(NULL);
                         // atualiza a ultimo
                    ultimo = ant_ant;

                }

            }

        }

};

int main(int argc, char *argv[])
{
    Lista lista;

    if (lista.listVazia())
        cout << "Lista vazia...\n";
    else
        cout << "Lista populada...\n";

    //Imprimir a lista atual
    lista.mostrarLista();

    if (lista.existeNo(100))
        cout << "\nO elemento 100 existe na lista...\n";
    else
        cout << "\nO elemento 100 inexiste na lista...\n";

    //Inserir nas posicoes correspondentes
    lista.inserir_final(100);
    lista.inserir_final(200);

    //Valor Insirido no inicio
    lista.inserir_inicio(350);

    lista.inserir_final(300);
    lista.inserir_final(400);
    lista.inserir_final(500);
    lista.inserir_final(600); // ....

    //Imprimir a lista atual
    lista.mostrarLista();

    //Avaliar se a lista esta vazia
    if (lista.listVazia())
        cout << "Lista vazia...\n";
    else
        cout << "Lista populada...\n";

    //Validar se o elemento existe na lista
    if (lista.existeNo(100))
        cout << "\nElemento 100 existe na lista...\n";
    else
        cout << "\nElemento 100 inexiste na lista...\n";

    //Remover o ultimo elemento da lista
    lista.removerNo();

    //Imprimir a lista atual
    lista.mostrarLista();

    //Printar o tamanho atual da lista
    cout << "Tamanho da lista: " << lista.tamanho() << endl;

    return 0;
}
