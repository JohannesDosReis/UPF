/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.upf.poo.appimc;

/**
 *
 * @author 166375
 */
public class Imc {

    private String nome;
    private float altura;
    private float peso;
        
    public Imc(String nome, float peso, float altura) {
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
    }

    public String getNome() {
        return nome;
    }

    public float getAltura() {
        return altura;
    }

    public float getPeso() {
        return peso;
    }

    public float getIndiceImc() {
        return peso / (altura * altura);
    }

    public String getInterpretacao() {
        float imc = getIndiceImc();
        String msg = null;
        if (imc < 16.00) {
            msg = "Magreza grave";
        } else if (imc >= 16.00 && imc < 17.00) {
            msg = "Magreza moderada";
        } else if (imc >= 17.00 && imc < 18.50) {
            msg = "Magreza leve";
        } else if (imc >= 18.50 && imc < 25.00) {
            msg = "Saudável";
        } else if (imc >= 25 && imc < 30) {
            msg = "Sobrepeso";
        } else if (imc >= 30 && imc < 35) {
            msg = "Obesidade Grau I";
        } else if (imc >= 35 && imc < 40) {
            msg = "Obesidade Grau II (severa)";
        } else {
            msg = "Obesidade Grau III (mórbida)";
        }
        return (msg);
    }

}
