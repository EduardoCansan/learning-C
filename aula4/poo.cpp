// ---------------------------------------------------------------------------------------
//   Existem problemas nessa classe - Encontre e resolva-os
//
//   Exemplo de Classe - Em C++
//
//   Códigos que estiverem comentados são os que estavam errados antes
//
//   Para compilar use a linha de código g++ poo.cpp -o poo.exe
//
// ---------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdio.h>

class Empregado {
  private:
    // Atributos privados
    std::string nome;
    std::string email;
    int idade;
    double salario;

  public:
    //Metodos getters e setters
    void setNome(std::string _nome) { nome = _nome; }
    std::string getNome() { return nome; }

    void setEmail(std::string _email) { email = _email; }
    std::string getEmail() { return email; }

    void setIdade(int _idade) { idade = _idade; }
    int getIdade() { return idade; }

    void setSalario(double _salario) { salario = _salario; }
    double getSalario() { return salario; }
    // int getSalario() { return salario; }(ERRRADO)

    //Metodo construtor da classe
    Empregado(std::string _nome, std::string _email, int _idade, double _salario)
    {
	    //Inicializar os atributos
        nome = _nome;
        email =_email;
        idade = _idade;
        salario = _salario;
    }

    //Demais metodos
    double CalcularAcrescimoSalario(double _percentual)
    {
	    return salario * ( 1 + (_percentual / 100));
    }
};

int main()
{
  //Inicializar dois empregados
  Empregado _empregado1("Antonio de Jesus", "antonioj@unisinos.br", 19, 3000.0);
  Empregado _empregado2("Pedro da Silva", "pedros@unisinos.br", 20, 5000.0);

  printf("\nSalario Atual do Empregado 1: %lf", _empregado1.getSalario());
  double _novoSalarioEmp1 = _empregado1.CalcularAcrescimoSalario(18.52);
  printf("\nSalario Atualizado Empregado 1: %lf", _novoSalarioEmp1);
  // printf("\nSalario Atualizado Empregado 1: %lf", _empregado1.getSalario()); (ERRADO)

  printf("\nSalario Atual do Empregado 1: %lf", _empregado2.getSalario());
  double _novoSalarioEmp2 = _empregado2.CalcularAcrescimoSalario(22.35);
  printf("\nSalario Atualizado Empregado 1: %lf", _novoSalarioEmp2);
  // printf("\nSalario Atualizado Empregado 1: %lf", _empregado1.getSalario()); (ERRADO)


  return 0;
}
