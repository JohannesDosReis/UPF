/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.upf.poo.imc.dominio;

/**
 *
 * @author Johannes Dos Reis
 */
public class Imc {

    // Atributos
    private final String nome;
    private final float peso;
    private final float altura;

    public Imc(String nome, float altura, float peso) {
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
    }

    /**
     * @return the Index IMC
     */
    public float getIndiceImc() {
        return this.peso / ((this.altura) * (this.altura));
    }

    /**
     * @return the nome
     */
    public String getNome() {
        return nome;
    }

    /**
     * @return the altura
     */
    public float getAltura() {
        return altura;
    }

    /**
     * @return the peso
     */
    public float getPeso() {
        return peso;
    }

    /**
     * @return the Interpretation IMC
     */
    public String getInterpretacao() {
        float index = this.getIndiceImc();
        if (index < 16) {
            return "Magreza grave";
        } else if (index < 17) {
            return "Magreza moderada";
        } else if (index < 18.5) {
            return "Magreza leve";
        } else if (index < 25) {
            return "Saudável";
        } else if (index < 30) {
            return "Sobrepeso";
        } else if (index < 35) {
            return "Obesidade Grau I";
        } else if (index < 40) {
            return "Obesidade Grau II(severa)";
        } else {
            return "Obesidade Grau III(móbida)";
        }

    }

}
